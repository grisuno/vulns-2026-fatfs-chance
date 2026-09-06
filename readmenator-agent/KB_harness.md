# Subsystem: harness

## harness/diskio_ramdisk.c
- Layer: infrastructure
- Doc: ---------------------------------------------------------------------------
- Language: c
- Symbols:
  - `ramdisk_reset_stats` (function, line 34) `void ramdisk_reset_stats(void)`
  - `ramdisk_load` (function, line 46) `void ramdisk_load(const BYTE *image, UINT size)`
  - `ramdisk_eject` (function, line 55) `void ramdisk_eject(void)`
  - `disk_status` (function, line 61) `DSTATUS disk_status(BYTE pdrv)`
  - `disk_initialize` (function, line 67) `DSTATUS disk_initialize(BYTE pdrv)`
  - `disk_read` (function, line 74) `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)`
  - `disk_write` (function, line 94) `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)`
  - `disk_ioctl` (function, line 113) `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)`
  - `get_fattime` (function, line 136) `DWORD get_fattime(void)`

## harness/diskio_ramdisk.h
- Layer: infrastructure
- Doc: ---------------------------------------------------------------------------
- Language: h
- Symbols:
  - `DISKIO_RAMDISK_H` (macro, line 6)
  - `RAMDISK_SECTOR_SIZE` (macro, line 12)
  - `RAMDISK_SECTOR_COUNT` (macro, line 14)
  - `RAMDISK_SIZE_BYTES` (macro, line 15)

## harness/exploit_disks.c
- Layer: infrastructure
- Doc: ===========================================================================
- Language: c
- Symbols:
  - `exploit_disks` (function, line 49) `*   make exploit_disks            (see Makefile target)
 *
 * Expected output:
 *   Generating 14...`
  - `st32le` (function, line 99) `static inline void st32le(uint8_t *p, uint32_t v)`
  - `st64le` (function, line 102) `static inline void st64le(uint8_t *p, uint64_t v)`
  - `save_image` (function, line 116) `static int save_image(const char *name, const uint8_t *buf, size_t sz)`
  - `load_ramdisk` (function, line 128) `static void load_ramdisk(const uint8_t *buf, size_t sz)`
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
  - `gen_bug2_exfat` (function, line 455) `static void gen_bug2_exfat(void)`
  - `MicroPython` (function, line 498) `*                            MicroPython (if the port enables FF_LBA64)
 *
 * R0.16 fix:  test_gp...`
  - `chain` (function, line 576) `*   An application writes 64 bytes to the END of cluster chain (fp->sect = X,
 *   FA_DIRTY set),...`
  - `bug4_set_fat16_entry` (function, line 637) `static void bug4_set_fat16_entry(uint8_t *disk, uint16_t cluster, uint16_t value)`
  - `gen_bug4_fragmented` (function, line 647) `static void gen_bug4_fragmented(void)`
  - `Zephyr` (function, line 836) `*                     Zephyr (R0.16), ArduPilot (R0.14b),
 *                     RIOT-OS (R0.15),...`
  - `bug6_verify_overflow` (function, line 892) `static int bug6_verify_overflow(uint8_t *disk, const char *imgname,
                             ...`
  - `gen_bug6_stm32` (function, line 932) `static void gen_bug6_stm32(void)`
  - `gen_bug6_zephyr` (function, line 947) `static void gen_bug6_zephyr(void)`
  - `layout` (function, line 989) `*
 * Directory layout (FAT16):
 *   Entries in order: LFN entries (N × 32 bytes) then 8.3 SFN ent...`
  - `bug7_build` (function, line 1006) `static void bug7_build(uint8_t *disk, int lfn_len, uint16_t dirent_name_size)`
  - `bug7_verify` (function, line 1059) `static int bug7_verify(uint8_t *disk, const char *imgname, int expected_lfn_len)`
  - `gen_bug7_max255` (function, line 1095) `static void gen_bug7_max255(void)`
  - `gen_bug7_zephyr` (function, line 1111) `static void gen_bug7_zephyr(void)`
  - `main` (function, line 1273) `int main(void)`
  - `IMG_DIR` (macro, line 94)
  - `INFO` (macro, line 107)
  - `PASS` (macro, line 109)
  - `FAIL` (macro, line 110)
  - `SKIP` (macro, line 111)
  - `B4_BYTES_PER_SEC` (macro, line 592)
  - `B4_SEC_PER_CLUS` (macro, line 593)
  - `B4_RESERVED_SECS` (macro, line 594)
  - `B4_N_FATS` (macro, line 595)
  - `B4_ROOT_ENTRIES` (macro, line 596)
  - `B4_FAT_SIZE_SECS` (macro, line 597)
  - `B4_TOT_SECS` (macro, line 598)
  - `B4_ROOT_DIR_SECS` (macro, line 599)
  - `B4_SYS_SECS` (macro, line 600)
  - `B4_FAT_OFFSET_SECS` (macro, line 601)
  - `B4_ROOT_OFFSET_SECS` (macro, line 602)
  - `B4_DATA_OFFSET_SECS` (macro, line 603)
  - `B4_CLUS2SEC` (macro, line 604)
  - `B5_SEC_PER_CLUS` (macro, line 738)
  - `B5_CLUS2SEC` (macro, line 739)
  - `B5_SECRET` (macro, line 740)
  - `B5_WRITE_SIZE` (macro, line 741)

## harness/ffunicode_stub.c
- Layer: testing
- Doc: ---------------------------------------------------------------------------
- Language: c
- Symbols:
  - `ff_uni2oem` (function, line 5) `* ff_uni2oem() and ff_wtoupper() which normally come from ffunicode.c.
 * These stubs are suffici...`
  - `ff_uni2oem` (function, line 17) `WCHAR ff_uni2oem(DWORD uni, WORD cp)`
  - `ff_wtoupper` (function, line 25) `DWORD ff_wtoupper(DWORD chr)`

## harness/libfuzzer_harness.c
- Layer: utility
- Doc: ---------------------------------------------------------------------------
- Language: c
- Symbols:
  - `Usage` (function, line 9) `*
 * Usage (libFuzzer):
 *   ./fuzz_fatfs -max_len=2097152 corpus/
 *
 * Usage (AFL++):
 *   afl-...`
  - `main` (function, line 128) `int main(int argc, char **argv)`

## harness/rce_demo.c
- Layer: utility
- Doc: ===========================================================================
- Language: c
- Symbols:
  - `ota_ctx` (struct, line 98)
  - `Build` (function, line 45) `*
 * Build (without sanitisers, without stack protector — lets the overflow
 * reach the function...`
  - `st32le` (function, line 73) `static inline void st32le(uint8_t *p, uint32_t v)`
  - `st64le` (function, line 76) `static inline void st64le(uint8_t *p, uint64_t v)`
  - `safe_update_complete` (function, line 123) `static void safe_update_complete(void)`
  - `__attribute__` (function, line 131) `__attribute__((noinline))
static void rce_win(void)`
  - `vulnerable_ota_check` (function, line 155) `static void vulnerable_ota_check(void)`
  - `build_exploit_image` (function, line 232) `static void build_exploit_image(uint8_t *disk, size_t disk_bytes,
                               ...`
  - `save_image` (function, line 348) `static int save_image(const char *path, const uint8_t *disk, size_t sz)`
  - `load_image` (function, line 363) `static int load_image(const char *path)`
  - `main` (function, line 380) `int main(void)`
  - `FW_HDR_SIZE` (macro, line 95)

## harness/test_ffconf.h
- Layer: testing
- Doc: ---------------------------------------------------------------------------
- Language: h
- Symbols:
  - `TEST_FFCONF_H` (macro, line 22)
  - `FFCONF_DEF` (macro, line 25)
  - `FF_FS_READONLY` (macro, line 28)
  - `FF_FS_MINIMIZE` (macro, line 29)
  - `FF_USE_FIND` (macro, line 30)
  - `FF_USE_MKFS` (macro, line 31)
  - `FF_USE_FASTSEEK` (macro, line 32)
  - `FF_USE_EXPAND` (macro, line 33)
  - `FF_USE_CHMOD` (macro, line 34)
  - `FF_USE_LABEL` (macro, line 35)
  - `FF_USE_FORWARD` (macro, line 36)
  - `FF_USE_STRFUNC` (macro, line 37)
  - `FF_PRINT_LLI` (macro, line 38)
  - `FF_PRINT_FLOAT` (macro, line 39)
  - `FF_STRF_ENCODE` (macro, line 40)
  - `FF_CODE_PAGE` (macro, line 43)
  - `FF_USE_LFN` (macro, line 44)
  - `FF_MAX_LFN` (macro, line 45)
  - `FF_LFN_UNICODE` (macro, line 46)
  - `FF_LFN_BUF` (macro, line 47)
  - `FF_SFN_BUF` (macro, line 48)
  - `FF_FS_RPATH` (macro, line 49)
  - `FF_PATH_DEPTH` (macro, line 50)
  - `FF_VOLUMES` (macro, line 53)
  - `FF_STR_VOLUME_ID` (macro, line 54)
  - `FF_VOLUME_STRS` (macro, line 55)
  - `FF_MULTI_PARTITION` (macro, line 56)
  - `FF_MIN_SS` (macro, line 57)
  - `FF_MAX_SS` (macro, line 58)
  - `FF_LBA64` (macro, line 59)
  - `FF_MIN_GPT` (macro, line 60)
  - `FF_USE_TRIM` (macro, line 61)
  - `FF_FS_TINY` (macro, line 64)
  - `FF_FS_EXFAT` (macro, line 65)
  - `FF_FS_NORTC` (macro, line 66)
  - `FF_NORTC_MON` (macro, line 67)
  - `FF_NORTC_MDAY` (macro, line 68)
  - `FF_NORTC_YEAR` (macro, line 69)
  - `FF_FS_CRTIME` (macro, line 70)
  - `FF_FS_NOFSINFO` (macro, line 71)
  - `FF_FS_LOCK` (macro, line 72)
  - `FF_FS_REENTRANT` (macro, line 73)

## harness/test_harness.c
- Layer: testing
- Doc: ===========================================================================
- Language: c
- Symbols:
  - `buffers` (function, line 36) `*         buffers (e.g. char path[16]) and unchecked string copies
 *         (sprintf, strcat) o...`
  - `st32le` (function, line 65) `static inline void st32le(BYTE *p, uint32_t v)`
  - `st64le` (function, line 70) `static inline void st64le(BYTE *p, uint64_t v)`
  - `rce_proof_of_execution` (function, line 119) `static void rce_proof_of_execution(void)`
  - `build_fat32_bug1` (function, line 120) `static void build_fat32_bug1(BYTE *disk, size_t disk_bytes)`
  - `MCUs` (function, line 261) `*    common on embedded MCUs (STM32, RP2040, ESP32, …).  The resulting call
 *    invokes rce_pro...`
  - `test_bug1_rce_exploit` (function, line 338) `static int test_bug1_rce_exploit(void)`
  - `build_gpt_image` (function, line 459) `static void build_gpt_image(BYTE *disk, size_t disk_bytes, uint32_t n_ent)`
  - `releases` (function, line 509) `*
 * Historical note: older FatFs releases (before test_gpt_header was
 * introduced) had no such...`
  - `test_bug4_stale_cache_skip` (function, line 601) `static int test_bug4_stale_cache_skip(void)`
  - `layout` (function, line 693) `*
 * Disk layout (FAT16, 4 sectors/cluster):
 *   Sectors  0           VBR
 *   Sectors  1-4     ...`
  - `build_fat16_base` (function, line 725) `static void build_fat16_base(BYTE *disk, size_t disk_bytes)`
  - `__attribute__` (function, line 763) `__attribute__((unused))
static void fat16_set_chain(BYTE *disk, uint16_t cluster, uint16_t next)`
  - `test_bug5_infoleak_lseek` (function, line 781) `static int test_bug5_infoleak_lseek(void)`
  - `pass` (function, line 927) `*      or pass (sizeof_label - di) instead of the hard-coded 4.
 *===============================...`
  - `test_bug6_getlabel_exfat_overflow` (function, line 998) `static int test_bug6_getlabel_exfat_overflow(void)`
  - `sfn_checksum_b7` (function, line 1090) `static BYTE sfn_checksum_b7(const BYTE sfn[11])`
  - `build_fat16_with_lfn` (function, line 1104) `static void build_fat16_with_lfn(BYTE *disk, size_t disk_bytes)`
  - `test_bug7_lfn_path_overflow` (function, line 1156) `static int test_bug7_lfn_path_overflow(void)`
  - `main` (function, line 1257) `int main(void)`
  - `RESULT` (macro, line 77)
  - `INFO` (macro, line 83)
  - `F16_BYTES_PER_SEC` (macro, line 703)
  - `F16_SEC_PER_CLUS` (macro, line 704)
  - `F16_RESERVED_SECS` (macro, line 705)
  - `F16_N_FATS` (macro, line 706)
  - `F16_ROOT_ENTRIES` (macro, line 707)
  - `F16_FAT_SIZE_SECS` (macro, line 708)
  - `F16_TOT_SECS` (macro, line 709)
  - `F16_ROOT_DIR_SECS` (macro, line 710)
  - `F16_SYS_SECS` (macro, line 712)
  - `F16_FAT_OFFSET_SECS` (macro, line 714)
  - `F16_ROOT_OFFSET_SECS` (macro, line 715)
  - `F16_DATA_OFFSET_SECS` (macro, line 716)
  - `F16_CLUS2SEC` (macro, line 717)
  - `SECRET_PATTERN` (macro, line 774)
  - `WRITE_SIZE` (macro, line 779)
  - `LSEEK_TARGET` (macro, line 780)
  - `B7_LFN_LEN` (macro, line 1102)
  - `B7_FILE_SIZE` (macro, line 1103)
