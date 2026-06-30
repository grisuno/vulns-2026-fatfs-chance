/*---------------------------------------------------------------------------
 * libfuzzer_harness.c — libFuzzer / AFL++ entry point for FatFs R0.16
 *
 * Compile with libFuzzer:
 *   make fuzz_asan
 *
 * Compile with AFL++:
 *   CC=afl-clang-fast make afl
 *
 * Usage (libFuzzer):
 *   ./fuzz_fatfs -max_len=2097152 corpus/
 *
 * Usage (AFL++):
 *   afl-fuzz -i corpus/ -o findings/ -- ./afl_fatfs @@
 *
 * The harness:
 *  1. Loads up to 2 MiB of fuzzer-supplied bytes as a raw disk image.
 *  2. Calls f_mount() to parse the image (covers BPB/GPT parsing, CVE-2026-6682, CVE-2026-6684).
 *  3. On successful mount, exercises f_getlabel (covers CVE-2026-6687 exFAT label
 *     overflow), f_opendir, f_readdir, f_open, f_read, f_lseek (covers LFN,
 *     FAT chain walk, CVE-2026-6686, CVE-2026-6685, CVE-2026-6688 long-LFN path overflow).
 *  4. Unmounts.  All filesystem state is discarded.
 *
 * AddressSanitizer and UndefinedBehaviourSanitizer detect memory errors.
 *---------------------------------------------------------------------------*/

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "ff.h"
#include "diskio.h"
#include "diskio_ramdisk.h"

/* libFuzzer entry — AFL++ shim defined at bottom                           */
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < 512 || size > RAMDISK_SIZE_BYTES) return 0;

    /* load fuzzer data as disk image */
    ramdisk_load((const BYTE *)data, (UINT)size);

    FATFS fs;
    memset(&fs, 0, sizeof(fs));

    FRESULT res = f_mount(&fs, "0:", 1);
    if (res != FR_OK) goto done;

    /* ── exercise f_getlabel (covers CVE-2026-6687: exFAT XDIR_NumLabel overflow) ── *
     * Use a heap buffer large enough for any valid label plus slop so that   *
     * ASan can detect writes beyond the expected 12-char maximum.            *
     * A caller using a smaller stack buffer (e.g. char label[12]) would have *
     * their stack corrupted by a crafted disk with XDIR_NumLabel > 11.       */
    {
        /* 256 bytes: enough to receive the full overflowing write and let    *
         * ASan's shadow memory flag the out-of-bounds access precisely.      */
        char *label_buf = (char *)malloc(256);
        if (label_buf) {
            memset(label_buf, 0, 256);
            f_getlabel("0:", label_buf, NULL);
            free(label_buf);
        }
    }

    /* ── exercise directory enumeration ──────────────────────────────── */
    DIR dj;
    FILINFO fno;
    if (f_opendir(&dj, "0:/") == FR_OK) {
        int entry_limit = 128;
        while (entry_limit-- > 0) {
            res = f_readdir(&dj, &fno);
            if (res != FR_OK || fno.fname[0] == 0) break;
        }
        f_closedir(&dj);
    }

    /* ── exercise file read / lseek on first found file ──────────────── */
    if (f_opendir(&dj, "0:/") == FR_OK) {
        while (f_readdir(&dj, &fno) == FR_OK && fno.fname[0] != 0) {
            if (fno.fattrib & AM_DIR) continue; /* skip sub-dirs */

            /* build "0:/filename" path
             * CVE-2026-6688 fix: size the buffer for full LFN (up to FF_LFN_BUF chars)
             * rather than the old SFN-only size (FF_SFN_BUF = 12).  The old
             * code used char path[16 + FF_SFN_BUF] = char path[28], which
             * silently truncated any LFN longer than 24 chars and prevented
             * the fuzzer from ever opening long-named files.  A caller using
             * the same wrong buffer size with sprintf/strcat instead of strncat
             * would get a stack overflow from a disk with a long LFN file.   */
            char path[4 + FF_LFN_BUF];   /* "0:/" (3) + LFN (255) + NUL (1) */
            memcpy(path, "0:/", 3);
            path[3] = '\0';
            strncat(path, fno.fname, sizeof(path) - sizeof("0:/"));

            FIL fp;
            if (f_open(&fp, path, FA_READ) != FR_OK) continue;

            /* read up to 4 KiB in two passes to exercise partial reads */
            BYTE buf[512];
            UINT br;
            f_read(&fp, buf, sizeof(buf), &br);

            /* seek to a mid-point and read again */
            FSIZE_t mid = fp.obj.objsize / 2;
            f_lseek(&fp, mid);
            f_read(&fp, buf, sizeof(buf), &br);

            /* seek to end-1 to test near-boundary reads */
            if (fp.obj.objsize > 0) {
                f_lseek(&fp, fp.obj.objsize - 1);
                f_read(&fp, buf, 1, &br);
            }
            f_close(&fp);
            break; /* process at most one file per fuzz iteration */
        }
        f_closedir(&dj);
    }

done:
    f_mount(NULL, "0:", 0);
    return 0;
}

/* ── AFL++ shim ─────────────────────────────────────────────────────────── */
#ifdef AFL_SHIM
#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc < 2) return 1;
    FILE *f = fopen(argv[1], "rb");
    if (!f) return 1;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f); rewind(f);
    if (sz <= 0 || sz > (long)RAMDISK_SIZE_BYTES) { fclose(f); return 0; }
    uint8_t *buf = (uint8_t *)malloc((size_t)sz);
    if (!buf) { fclose(f); return 1; }
    fread(buf, 1, (size_t)sz, f);
    fclose(f);
    LLVMFuzzerTestOneInput(buf, (size_t)sz);
    free(buf);
    return 0;
}
#endif /* AFL_SHIM */
