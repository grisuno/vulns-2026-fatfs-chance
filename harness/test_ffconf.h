/*---------------------------------------------------------------------------
 * test_ffconf.h — FatFs configuration for the security test harness
 *
 * Used by the Makefile via:  gcc -include test_ffconf.h ...
 *
 * When processed before ff.h is parsed, the #if !defined(FFCONF_DEF)
 * guard in ff.h skips the standard ffconf.h so all settings below apply.
 *
 * Feature flags enabled for the extended test build:
 *   FF_USE_LFN    = 1   (static LFN buffer; required by FF_FS_EXFAT)
 *   FF_FS_EXFAT   = 1   (required by FF_LBA64)
 *   FF_LBA64      = 1   (enables GPT parsing path — CVE-2026-6684)
 *
 * Feature flags kept at security-relevant defaults:
 *   FF_FS_READONLY  = 0  (read-write; needed to exercise lseek / write)
 *   FF_FS_NORTC     = 0  (use get_fattime() stub in diskio_ramdisk.c)
 *   FF_FS_LOCK      = 0  (simplify harness — no multi-open concurrency)
 *   FF_FS_REENTRANT = 0  (single-threaded test)
 *---------------------------------------------------------------------------*/

#ifndef TEST_FFCONF_H
#define TEST_FFCONF_H

/* ── revision sentinel (must match FF_DEFINED in ff.h) ─────────────────── */
#define FFCONF_DEF          80386

/* ── function configuration ─────────────────────────────────────────────── */
#define FF_FS_READONLY      0
#define FF_FS_MINIMIZE      0
#define FF_USE_FIND         0
#define FF_USE_MKFS         0
#define FF_USE_FASTSEEK     0
#define FF_USE_EXPAND       0
#define FF_USE_CHMOD        0
#define FF_USE_LABEL        1            /* required for f_getlabel (CVE-2026-6687) */
#define FF_USE_FORWARD      0
#define FF_USE_STRFUNC      0
#define FF_PRINT_LLI        0
#define FF_PRINT_FLOAT      0
#define FF_STRF_ENCODE      0

/* ── locale / namespace ──────────────────────────────────────────────────── */
#define FF_CODE_PAGE        437          /* US-ASCII/CP437 — no DBCS tables  */
#define FF_USE_LFN          1            /* static LFN buffer                */
#define FF_MAX_LFN          255
#define FF_LFN_UNICODE      0            /* ANSI/OEM on API                  */
#define FF_LFN_BUF          255
#define FF_SFN_BUF          12
#define FF_FS_RPATH         0
#define FF_PATH_DEPTH       10

/* ── drive / volume ──────────────────────────────────────────────────────── */
#define FF_VOLUMES          1
#define FF_STR_VOLUME_ID    0
#define FF_VOLUME_STRS      "RAM"
#define FF_MULTI_PARTITION  0
#define FF_MIN_SS           512
#define FF_MAX_SS           512
#define FF_LBA64            1            /* enables GPT parsing → CVE-2026-6684      */
#define FF_MIN_GPT          0x10000000
#define FF_USE_TRIM         0

/* ── system ──────────────────────────────────────────────────────────────── */
#define FF_FS_TINY          0
#define FF_FS_EXFAT         1            /* required by FF_LBA64             */
#define FF_FS_NORTC         0            /* use get_fattime() stub           */
#define FF_NORTC_MON        1
#define FF_NORTC_MDAY       1
#define FF_NORTC_YEAR       2025
#define FF_FS_CRTIME        0
#define FF_FS_NOFSINFO      0
#define FF_FS_LOCK          0
#define FF_FS_REENTRANT     0

#endif /* TEST_FFCONF_H */
