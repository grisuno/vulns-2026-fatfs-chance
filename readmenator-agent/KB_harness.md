# Subsystem: harness

## harness/diskio_ramdisk.c
- Doc: ramdisk_load: Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.
- Layer: utility
- Language: c
- Symbols:
  - `ramdisk_reset_stats` (function, line 35) `void ramdisk_reset_stats(void)`
  - `ramdisk_load` (function, line 46) `void ramdisk_load(const BYTE *image, UINT size)`
  - `ramdisk_eject` (function, line 55) `void ramdisk_eject(void)`
  - `disk_status` (function, line 62) `DSTATUS disk_status(BYTE pdrv)`
  - `disk_initialize` (function, line 68) `DSTATUS disk_initialize(BYTE pdrv)`
  - `disk_read` (function, line 75) `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)`
  - `disk_write` (function, line 95) `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)`
  - `disk_ioctl` (function, line 114) `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)`
  - `get_fattime` (function, line 137) `DWORD get_fattime(void)`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/diskio_ramdisk.h
- Doc: ramdisk_load: /* ── backing store (accessible for direct inspection in tests) ────────────...
- Layer: utility
- Language: h
- Symbols:
  - `ramdisk_reset_stats` (function, line 26) `void ramdisk_reset_stats(void);`
  - `ramdisk_load` (function, line 31) `void ramdisk_load(const BYTE *image, UINT size);`
  - `ramdisk_eject` (function, line 34) `void ramdisk_eject(void);`
  - `ramdisk` (variable, line 19) `extern BYTE ramdisk[RAMDISK_SECTOR_COUNT * RAMDISK_SECTOR_SIZE];`
  - `ramdisk_read_count` (variable, line 23) `extern volatile uint32_t ramdisk_read_count;`
  - `ramdisk_write_count` (variable, line 24) `extern volatile uint32_t ramdisk_write_count;`
  - `DISKIO_RAMDISK_H` (macro, line 6) `#define DISKIO_RAMDISK_H`
  - `RAMDISK_SECTOR_SIZE` (macro, line 13) `#define RAMDISK_SECTOR_SIZE`
  - `RAMDISK_SECTOR_COUNT` (macro, line 14) `#define RAMDISK_SECTOR_COUNT`
  - `RAMDISK_SIZE_BYTES` (macro, line 15) `#define RAMDISK_SIZE_BYTES`
- Depends on: `FatFs-R0.16/source/ff.h`
- Imported by: `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

## harness/exploit_disks.c
- Doc: bug1_write_vbr: clst2sect(2) = 6 → attacker plants root-dir entry at sector 6 clst2sect(4) = 8 →...
- Layer: utility
- Language: c
- Symbols:
  - `exploit_disks` (function, line 49) `*   make exploit_disks            (see Makefile target)
 *
 * Expected output:
 *   Generating 14...`
  - `st32le` (function, line 99) `static inline void st32le(uint8_t *p, uint32_t v)`
  - `st64le` (function, line 102) `static inline void st64le(uint8_t *p, uint64_t v)`
  - `save_image` (function, line 116) `static int save_image(const char *name, const uint8_t *buf, size_t sz)`
  - `load_ramdisk` (function, line 129) `static void load_ramdisk(const uint8_t *buf, size_t sz)`
  - `bug1_write_vbr` (function, line 156) `static void bug1_write_vbr(uint8_t *disk)`
  - `bug1_fill_payload` (function, line 227) `static void bug1_fill_payload(uint8_t *disk,
                               const uint8_t *payloa...`
  - `bug1_build` (function, line 241) `static uint8_t *bug1_build(uint32_t file_size,
                            const uint8_t *payload...`
  - `bug1_verify` (function, line 255) `static int bug1_verify(uint8_t *disk, const char *filename)`
  - `Payload` (function, line 293) `*   Payload (sector 8): placeholder address 0xDEADBEEFCAFEBABE
 *   Simulates: embedded OTA reade...`
  - `gen_bug1_espidf` (function, line 317) `static void gen_bug1_espidf(void)`
  - `gen_bug1_stm32` (function, line 338) `static void gen_bug1_stm32(void)`
  - `gen_bug1_keystone3` (function, line 359) `static void gen_bug1_keystone3(void)`
  - `gen_bug1_ardupilot` (function, line 382) `static void gen_bug1_ardupilot(void)`
  - `gen_bug2_exfat` (function, line 456) `static void gen_bug2_exfat(void)`
  - `MicroPython` (function, line 498) `*                            MicroPython (if the port enables FF_LBA64)
 *
 * R0.16 fix:  test_gp...`
  - `chain` (function, line 576) `*   An application writes 64 bytes to the END of cluster chain (fp->sect = X,
 *   FA_DIRTY set),...`
  - `bug4_set_fat16_entry` (function, line 638) `static void bug4_set_fat16_entry(uint8_t *disk, uint16_t cluster, uint16_t value)`
  - `gen_bug4_fragmented` (function, line 648) `static void gen_bug4_fragmented(void)`
  - `Zephyr` (function, line 836) `*                     Zephyr (R0.16), ArduPilot (R0.14b),
 *                     RIOT-OS (R0.15),...`
  - `bug6_verify_overflow` (function, line 893) `static int bug6_verify_overflow(uint8_t *disk, const char *imgname,
                             ...`
  - `gen_bug6_stm32` (function, line 933) `static void gen_bug6_stm32(void)`
  - `gen_bug6_zephyr` (function, line 948) `static void gen_bug6_zephyr(void)`
  - `layout` (function, line 990) `*
 * Directory layout (FAT16):
 *   Entries in order: LFN entries (N × 32 bytes) then 8.3 SFN ent...`
  - `bug7_build` (function, line 1007) `static void bug7_build(uint8_t *disk, int lfn_len, uint16_t dirent_name_size)`
  - `bug7_verify` (function, line 1060) `static int bug7_verify(uint8_t *disk, const char *imgname, int expected_lfn_len)`
  - `gen_bug7_max255` (function, line 1096) `static void gen_bug7_max255(void)`
  - `gen_bug7_zephyr` (function, line 1112) `static void gen_bug7_zephyr(void)`
  - `main` (function, line 1273) `int main(void)`
  - `code` (function, line 564) `* * Vulnerable code (ff.c non-tiny path, f_read multi-sector branch): * disk_read(pdrv, rbuff, sect, cc);`
  - `cc` (function, line 673) `* if cc (sectors remaining) is also large, 0xFFFFFFFC < cc → TRUE * → memcpy fires at offset 0xFFFFFFFC * 512 (out...`
  - `IMG_DIR` (macro, line 94) `#define IMG_DIR`
  - `INFO` (macro, line 108) `#define INFO(fmt, ...)`
  - `PASS` (macro, line 109) `#define PASS(label)`
  - `FAIL` (macro, line 110) `#define FAIL(label)`
  - `SKIP` (macro, line 111) `#define SKIP(label)`
  - `B4_BYTES_PER_SEC` (macro, line 592) `#define B4_BYTES_PER_SEC`
  - `B4_SEC_PER_CLUS` (macro, line 593) `#define B4_SEC_PER_CLUS`
  - `B4_RESERVED_SECS` (macro, line 594) `#define B4_RESERVED_SECS`
  - `B4_N_FATS` (macro, line 595) `#define B4_N_FATS`
  - `B4_ROOT_ENTRIES` (macro, line 596) `#define B4_ROOT_ENTRIES`
  - `B4_FAT_SIZE_SECS` (macro, line 597) `#define B4_FAT_SIZE_SECS`
  - `B4_TOT_SECS` (macro, line 598) `#define B4_TOT_SECS`
  - `B4_ROOT_DIR_SECS` (macro, line 599) `#define B4_ROOT_DIR_SECS`
  - `B4_SYS_SECS` (macro, line 600) `#define B4_SYS_SECS`
  - `B4_FAT_OFFSET_SECS` (macro, line 601) `#define B4_FAT_OFFSET_SECS(n)`
  - `B4_ROOT_OFFSET_SECS` (macro, line 602) `#define B4_ROOT_OFFSET_SECS`
  - `B4_DATA_OFFSET_SECS` (macro, line 603) `#define B4_DATA_OFFSET_SECS`
  - `B4_CLUS2SEC` (macro, line 604) `#define B4_CLUS2SEC(c)`
  - `B5_SEC_PER_CLUS` (macro, line 738) `#define B5_SEC_PER_CLUS`
  - `B5_CLUS2SEC` (macro, line 739) `#define B5_CLUS2SEC(c)`
  - `B5_SECRET` (macro, line 740) `#define B5_SECRET`
  - `B5_WRITE_SIZE` (macro, line 741) `#define B5_WRITE_SIZE`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/ffunicode_stub.c
- Doc: ff_wtoupper: WCHAR ff_oem2uni(WCHAR oem, WORD cp) { (void)cp; return (oem < 0x80) ? oem : 0; }...
- Layer: testing
- Language: c
- Symbols:
  - `ff_uni2oem` (function, line 5) `* ff_uni2oem() and ff_wtoupper() which normally come from ffunicode.c.
 * These stubs are suffici...`
  - `ff_uni2oem` (function, line 18) `WCHAR ff_uni2oem(DWORD uni, WORD cp)`
  - `ff_wtoupper` (function, line 25) `DWORD ff_wtoupper(DWORD chr)`
- Depends on: `FatFs-R0.16/source/ff.h`

## harness/libfuzzer_harness.c
- Doc: main: f_close(&fp); break; /* process at most one file per fuzz iteration } f_closedir(&dj); }...
- Layer: utility
- Language: c
- Symbols:
  - `Usage` (function, line 10) `*
 * Usage (libFuzzer):
 *   ./fuzz_fatfs -max_len=2097152 corpus/
 *
 * Usage (AFL++):
 *   afl-...`
  - `main` (function, line 128) `int main(int argc, char **argv)`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/rce_demo.c
- Doc: vulnerable_ota_check: This function is the VICTIM.
- Layer: utility
- Language: c
- Symbols:
  - `ota_ctx` (struct, line 98)
  - `fw_header` (type_alias, line 97) `typedef struct ota_ctx { uint8_t fw_header[FW_HDR_SIZE];`
  - `Build` (function, line 46) `*
 * Build (without sanitisers, without stack protector — lets the overflow
 * reach the function...`
  - `st32le` (function, line 73) `static inline void st32le(uint8_t *p, uint32_t v)`
  - `st64le` (function, line 76) `static inline void st64le(uint8_t *p, uint64_t v)`
  - `safe_update_complete` (function, line 123) `static void safe_update_complete(void)`
  - `__attribute__` (function, line 132) `__attribute__((noinline))
static void rce_win(void)`
  - `vulnerable_ota_check` (function, line 155) `static void vulnerable_ota_check(void)`
  - `build_exploit_image` (function, line 232) `static void build_exploit_image(uint8_t *disk, size_t disk_bytes,
                               ...`
  - `save_image` (function, line 348) `static int save_image(const char *path, const uint8_t *disk, size_t sz)`
  - `load_image` (function, line 363) `static int load_image(const char *path)`
  - `main` (function, line 380) `int main(void)`
  - `fasize` (function, line 258) `* fasize (DWORD) = 0x80000001 * 2 = 0x100000002 → truncates to 2 * sysect = 4 + 2 + 0 = 6 → database = sector 6...`
  - `FW_HDR_SIZE` (macro, line 96) `#define FW_HDR_SIZE`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/test_ffconf.h
- Layer: testing
- Language: h
- Symbols:
  - `TEST_FFCONF_H` (macro, line 22) `#define TEST_FFCONF_H`
  - `FFCONF_DEF` (macro, line 25) `#define FFCONF_DEF`
  - `FF_FS_READONLY` (macro, line 28) `#define FF_FS_READONLY`
  - `FF_FS_MINIMIZE` (macro, line 29) `#define FF_FS_MINIMIZE`
  - `FF_USE_FIND` (macro, line 30) `#define FF_USE_FIND`
  - `FF_USE_MKFS` (macro, line 31) `#define FF_USE_MKFS`
  - `FF_USE_FASTSEEK` (macro, line 32) `#define FF_USE_FASTSEEK`
  - `FF_USE_EXPAND` (macro, line 33) `#define FF_USE_EXPAND`
  - `FF_USE_CHMOD` (macro, line 34) `#define FF_USE_CHMOD`
  - `FF_USE_LABEL` (macro, line 35) `#define FF_USE_LABEL`
  - `FF_USE_FORWARD` (macro, line 36) `#define FF_USE_FORWARD`
  - `FF_USE_STRFUNC` (macro, line 37) `#define FF_USE_STRFUNC`
  - `FF_PRINT_LLI` (macro, line 38) `#define FF_PRINT_LLI`
  - `FF_PRINT_FLOAT` (macro, line 39) `#define FF_PRINT_FLOAT`
  - `FF_STRF_ENCODE` (macro, line 40) `#define FF_STRF_ENCODE`
  - `FF_CODE_PAGE` (macro, line 43) `#define FF_CODE_PAGE`
  - `FF_USE_LFN` (macro, line 44) `#define FF_USE_LFN`
  - `FF_MAX_LFN` (macro, line 45) `#define FF_MAX_LFN`
  - `FF_LFN_UNICODE` (macro, line 46) `#define FF_LFN_UNICODE`
  - `FF_LFN_BUF` (macro, line 47) `#define FF_LFN_BUF`
  - `FF_SFN_BUF` (macro, line 48) `#define FF_SFN_BUF`
  - `FF_FS_RPATH` (macro, line 49) `#define FF_FS_RPATH`
  - `FF_PATH_DEPTH` (macro, line 50) `#define FF_PATH_DEPTH`
  - `FF_VOLUMES` (macro, line 53) `#define FF_VOLUMES`
  - `FF_STR_VOLUME_ID` (macro, line 54) `#define FF_STR_VOLUME_ID`
  - `FF_VOLUME_STRS` (macro, line 55) `#define FF_VOLUME_STRS`
  - `FF_MULTI_PARTITION` (macro, line 56) `#define FF_MULTI_PARTITION`
  - `FF_MIN_SS` (macro, line 57) `#define FF_MIN_SS`
  - `FF_MAX_SS` (macro, line 58) `#define FF_MAX_SS`
  - `FF_LBA64` (macro, line 59) `#define FF_LBA64`
  - `FF_MIN_GPT` (macro, line 60) `#define FF_MIN_GPT`
  - `FF_USE_TRIM` (macro, line 61) `#define FF_USE_TRIM`
  - `FF_FS_TINY` (macro, line 64) `#define FF_FS_TINY`
  - `FF_FS_EXFAT` (macro, line 65) `#define FF_FS_EXFAT`
  - `FF_FS_NORTC` (macro, line 66) `#define FF_FS_NORTC`
  - `FF_NORTC_MON` (macro, line 67) `#define FF_NORTC_MON`
  - `FF_NORTC_MDAY` (macro, line 68) `#define FF_NORTC_MDAY`
  - `FF_NORTC_YEAR` (macro, line 69) `#define FF_NORTC_YEAR`
  - `FF_FS_CRTIME` (macro, line 70) `#define FF_FS_CRTIME`
  - `FF_FS_NOFSINFO` (macro, line 71) `#define FF_FS_NOFSINFO`
  - `FF_FS_LOCK` (macro, line 72) `#define FF_FS_LOCK`
  - `FF_FS_REENTRANT` (macro, line 73) `#define FF_FS_REENTRANT`

## harness/test_harness.c
- Doc: build_gpt_image: Minimal protective-MBR + GPT header disk image builder.
- Layer: testing
- Language: c
- Symbols:
  - `buffers` (function, line 36) `*         buffers (e.g. char path[16]) and unchecked string copies
 *         (sprintf, strcat) o...`
  - `st32le` (function, line 65) `static inline void st32le(BYTE *p, uint32_t v)`
  - `st64le` (function, line 70) `static inline void st64le(BYTE *p, uint64_t v)`
  - `rce_proof_of_execution` (function, line 119) `static void rce_proof_of_execution(void)`
  - `build_fat32_bug1` (function, line 121) `static void build_fat32_bug1(BYTE *disk, size_t disk_bytes)`
  - `MCUs` (function, line 261) `*    common on embedded MCUs (STM32, RP2040, ESP32, …).  The resulting call
 *    invokes rce_pro...`
  - `test_bug1_rce_exploit` (function, line 339) `static int test_bug1_rce_exploit(void)`
  - `build_gpt_image` (function, line 459) `static void build_gpt_image(BYTE *disk, size_t disk_bytes, uint32_t n_ent)`
  - `releases` (function, line 510) `*
 * Historical note: older FatFs releases (before test_gpt_header was
 * introduced) had no such...`
  - `test_bug4_stale_cache_skip` (function, line 601) `static int test_bug4_stale_cache_skip(void)`
  - `layout` (function, line 694) `*
 * Disk layout (FAT16, 4 sectors/cluster):
 *   Sectors  0           VBR
 *   Sectors  1-4     ...`
  - `build_fat16_base` (function, line 726) `static void build_fat16_base(BYTE *disk, size_t disk_bytes)`
  - `__attribute__` (function, line 764) `__attribute__((unused))
static void fat16_set_chain(BYTE *disk, uint16_t cluster, uint16_t next)`
  - `test_bug5_infoleak_lseek` (function, line 782) `static int test_bug5_infoleak_lseek(void)`
  - `pass` (function, line 927) `*      or pass (sizeof_label - di) instead of the hard-coded 4.
 *===============================...`
  - `test_bug6_getlabel_exfat_overflow` (function, line 999) `static int test_bug6_getlabel_exfat_overflow(void)`
  - `sfn_checksum_b7` (function, line 1090) `static BYTE sfn_checksum_b7(const BYTE sfn[11])`
  - `build_fat16_with_lfn` (function, line 1105) `static void build_fat16_with_lfn(BYTE *disk, size_t disk_bytes)`
  - `test_bug7_lfn_path_overflow` (function, line 1157) `static int test_bug7_lfn_path_overflow(void)`
  - `main` (function, line 1257) `int main(void)`
  - `code` (function, line 89) `* * Vulnerable code (ff.c ~line 3600): * * fasize = ld_16(fs->win + BPB_FATSz16);`
  - `truncated` (function, line 146) `* truncated (DWORD) → 0x00000002 * * sysect = 4 (reserved) + 2 (fake fasize) + 0 (no root) = 6 * * fs->database =...`
  - `move_window` (function, line 435) `* move_window(fs, pt_lba + i * SZ_GPTE / SS(fs));`
  - `memcpy` (function, line 561) `* memcpy(rbuff + ((fp->sect - sect) * SS(fs)), fp->buf, SS(fs));`
  - `byte` (function, line 1023) `* sentinel byte (0xC3) so that any write beyond offset 24 is visible. * * f_getlabel must receive a pointer to byte...`
  - `sprintf` (function, line 1075) `* sprintf(path, "0:/%s", fno.fname);`
  - `strcpy` (function, line 1078) `* strcpy(fname, fno.fname);`
  - `strcat` (function, line 1213) `* strcat(path, fno.fname);`
  - `RESULT` (macro, line 78) `#define RESULT(label, cond)`
  - `INFO` (macro, line 84) `#define INFO(fmt, ...)`
  - `F16_BYTES_PER_SEC` (macro, line 703) `#define F16_BYTES_PER_SEC`
  - `F16_SEC_PER_CLUS` (macro, line 704) `#define F16_SEC_PER_CLUS`
  - `F16_RESERVED_SECS` (macro, line 705) `#define F16_RESERVED_SECS`
  - `F16_N_FATS` (macro, line 706) `#define F16_N_FATS`
  - `F16_ROOT_ENTRIES` (macro, line 707) `#define F16_ROOT_ENTRIES`
  - `F16_FAT_SIZE_SECS` (macro, line 708) `#define F16_FAT_SIZE_SECS`
  - `F16_TOT_SECS` (macro, line 709) `#define F16_TOT_SECS`
  - `F16_ROOT_DIR_SECS` (macro, line 711) `#define F16_ROOT_DIR_SECS`
  - `F16_SYS_SECS` (macro, line 712) `#define F16_SYS_SECS`
  - `F16_FAT_OFFSET_SECS` (macro, line 714) `#define F16_FAT_OFFSET_SECS(n)`
  - `F16_ROOT_OFFSET_SECS` (macro, line 715) `#define F16_ROOT_OFFSET_SECS`
  - `F16_DATA_OFFSET_SECS` (macro, line 716) `#define F16_DATA_OFFSET_SECS`
  - `F16_CLUS2SEC` (macro, line 717) `#define F16_CLUS2SEC(c)`
  - `SECRET_PATTERN` (macro, line 774) `#define SECRET_PATTERN`
  - `WRITE_SIZE` (macro, line 779) `#define WRITE_SIZE`
  - `LSEEK_TARGET` (macro, line 780) `#define LSEEK_TARGET`
  - `B7_LFN_LEN` (macro, line 1102) `#define B7_LFN_LEN`
  - `B7_FILE_SIZE` (macro, line 1103) `#define B7_FILE_SIZE`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`
