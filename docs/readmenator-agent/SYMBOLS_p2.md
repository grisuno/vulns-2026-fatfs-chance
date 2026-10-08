# Symbols (page 2 of 2)
Previous: [SYMBOLS.md](SYMBOLS.md)

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `FF_STR_VOLUME_ID` | macro | `FatFs-R0.16/source/ffconf.h:185` | `#define FF_STR_VOLUME_ID` |
| `FF_USE_CHMOD` | macro | `FatFs-R0.16/source/ffconf.h:45` | `#define FF_USE_CHMOD` |
| `FF_USE_EXPAND` | macro | `FatFs-R0.16/source/ffconf.h:41` | `#define FF_USE_EXPAND` |
| `FF_USE_FASTSEEK` | macro | `FatFs-R0.16/source/ffconf.h:37` | `#define FF_USE_FASTSEEK` |
| `FF_USE_FIND` | macro | `FatFs-R0.16/source/ffconf.h:28` | `#define FF_USE_FIND` |
| `FF_USE_FORWARD` | macro | `FatFs-R0.16/source/ffconf.h:55` | `#define FF_USE_FORWARD` |
| `FF_USE_LABEL` | macro | `FatFs-R0.16/source/ffconf.h:50` | `#define FF_USE_LABEL` |
| `FF_USE_LFN` | macro | `FatFs-R0.16/source/ffconf.h:116` | `#define FF_USE_LFN` |
| `FF_USE_MKFS` | macro | `FatFs-R0.16/source/ffconf.h:33` | `#define FF_USE_MKFS` |
| `FF_USE_STRFUNC` | macro | `FatFs-R0.16/source/ffconf.h:59` | `#define FF_USE_STRFUNC` |
| `FF_USE_TRIM` | macro | `FatFs-R0.16/source/ffconf.h:228` | `#define FF_USE_TRIM` |
| `FF_VOLUMES` | macro | `FatFs-R0.16/source/ffconf.h:181` | `#define FF_VOLUMES` |
| `FF_VOLUME_STRS` | macro | `FatFs-R0.16/source/ffconf.h:186` | `#define FF_VOLUME_STRS` |
| `OS_TYPE` | macro | `FatFs-R0.16/source/ffsystem.c:42` | `#define OS_TYPE` |
| `ff_memalloc` | function | `FatFs-R0.16/source/ffsystem.c:17` | `void* ff_memalloc (	/* Returns pointer to the allocated memory block (null if not enough core) */...` |
| `ff_memfree` | function | `FatFs-R0.16/source/ffsystem.c:25` | `void ff_memfree ( 	void* mblock	/* Pointer to the memory block to free (no effect if null) */ )` |
| `ff_mutex_create` | function | `FatFs-R0.16/source/ffsystem.c:79` | `int ff_mutex_create (	/* Returns 1:Function succeeded or 0:Could not create the mutex */ 	int vol...` |
| `ff_mutex_delete` | function | `FatFs-R0.16/source/ffsystem.c:120` | `void ff_mutex_delete (	/* Returns 1:Function succeeded or 0:Could not delete due to an error */ 	...` |
| `ff_mutex_give` | function | `FatFs-R0.16/source/ffsystem.c:185` | `void ff_mutex_give ( 	int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (...` |
| `ff_mutex_take` | function | `FatFs-R0.16/source/ffsystem.c:152` | `int ff_mutex_take (	/* Returns 1:Succeeded or 0:Timeout */ 	int vol			/* Mutex ID: Volume mutex (...` |
| `CVTBL` | macro | `FatFs-R0.16/source/ffunicode.c:31` | `#define CVTBL(tbl, cp)` |
| `MERGE2` | macro | `FatFs-R0.16/source/ffunicode.c:30` | `#define MERGE2(a, b)` |
| `ff_oem2uni` | function | `FatFs-R0.16/source/ffunicode.c:15244` | `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */ 	WCHAR	oem,	/* OEM co...` |
| `ff_oem2uni` | function | `FatFs-R0.16/source/ffunicode.c:15311` | `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */ 	WCHAR	oem,	/* OEM co...` |
| `ff_oem2uni` | function | `FatFs-R0.16/source/ffunicode.c:15410` | `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */ 	WCHAR	oem,	/* OEM co...` |
| `ff_uni2oem` | function | `FatFs-R0.16/source/ffunicode.c:15222` | `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */ 	DWORD	uni,	/* UTF-16 encoded ...` |
| `ff_uni2oem` | function | `FatFs-R0.16/source/ffunicode.c:15275` | `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */ 	DWORD	uni,	/* UTF-16 encoded ...` |
| `ff_uni2oem` | function | `FatFs-R0.16/source/ffunicode.c:15358` | `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */ 	DWORD	uni,	/* UTF-16 encoded ...` |
| `ff_wtoupper` | function | `FatFs-R0.16/source/ffunicode.c:15464` | `DWORD ff_wtoupper (	/* Returns up-converted code point */ 	DWORD uni		/* Unicode code point to be...` |
| `CANARY_CRC` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:43` | `#define CANARY_CRC` |
| `CANARY_VERSION` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:44` | `#define CANARY_VERSION` |
| `FW_HDR_SIZE` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:26` | `#define FW_HDR_SIZE` |
| `LFN_GUARD_VALUE` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:46` | `#define LFN_GUARD_VALUE` |
| `MOUNT_POINT` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:23` | `#define MOUNT_POINT` |
| `OTA_READ_SLAB_SIZE` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:27` | `#define OTA_READ_SLAB_SIZE` |
| `__attribute__` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:55` | `__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const struct dirent *entry)` |
| `app_main` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:170` | `void app_main(void)` |
| `ctx` | type_alias | `esp32-qemu-test/app/main/fatfs_vuln_test.c:35` | `typedef struct ota_exec_region { ota_update_ctx_t ctx;` |
| `fw_header` | type_alias | `esp32-qemu-test/app/main/fatfs_vuln_test.c:28` | `typedef struct ota_update_ctx { uint8_t fw_header[FW_HDR_SIZE];` |
| `get_firmware_size` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:121` | `static long get_firmware_size(void)` |
| `legitimate_update_callback` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:67` | `static void legitimate_update_callback(void)` |
| `lfn_overflow_probe` | struct | `esp32-qemu-test/app/main/fatfs_vuln_test.c:48` | `` |
| `name` | type_alias | `esp32-qemu-test/app/main/fatfs_vuln_test.c:47` | `typedef struct lfn_overflow_probe { char name[32];` |
| `ota_exec_region` | struct | `esp32-qemu-test/app/main/fatfs_vuln_test.c:36` | `` |
| `ota_update_ctx` | struct | `esp32-qemu-test/app/main/fatfs_vuln_test.c:29` | `` |
| `read_firmware_image` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:134` | `static bool read_firmware_image(int fd, size_t firmware_size)` |
| `readdir` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:76` | `* readdir() returns an attacker-controlled long filename, then application * code copies it into a fixed 32-byte...` |
| `run_lfn_copy_probe` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:72` | `static bool run_lfn_copy_probe(void)` |
| `run_update_flow` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:152` | `static void run_update_flow(long attacker_fsize)` |
| `do_build` | function | `esp32-qemu-test/run.sh:46` | `` |
| `do_run` | function | `esp32-qemu-test/run.sh:53` | `` |
| `do_shell` | function | `esp32-qemu-test/run.sh:63` | `` |
| `ensure_image` | function | `esp32-qemu-test/run.sh:39` | `` |
| `image_exists` | function | `esp32-qemu-test/run.sh:35` | `` |
| `usage` | function | `esp32-qemu-test/run.sh:25` | `` |
| `build_lfn_entries` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:76` | `def build_lfn_entries(long_name, short_name_11)` |
| `build_payload_sector` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:271` | `def build_payload_sector(shellcode, callback_target_addr)` |
| `build_xtensa_uart_shellcode` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:149` | `def build_xtensa_uart_shellcode()` |
| `generate_bug1_espidf_image` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:282` | `def generate_bug1_espidf_image(shellcode, callback_target_addr)` |
| `inject_into_flash` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:389` | `def inject_into_flash(flash_path, output_path, shellcode, callback_target_addr)` |
| `lfn_checksum` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:67` | `def lfn_checksum(short_name_11)` |
| `main` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:456` | `def main()` |
| `resolve_symbol_address` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:115` | `def resolve_symbol_address(elf_path, symbol_name)` |
| `BuildExFATImage` | function | `fuzzer/fat_image.go:262` | `func BuildExFATImage(` |
| `BuildExFATWithLargeLabel` | function | `fuzzer/fat_image.go:354` | `func BuildExFATWithLargeLabel(` |
| `BuildFAT16` | function | `fuzzer/fat_image.go:65` | `func BuildFAT16(` |
| `BuildFAT16WithLFNFile` | function | `fuzzer/fat_image.go:451` | `func BuildFAT16WithLFNFile(` |
| `BuildFAT32` | function | `fuzzer/fat_image.go:144` | `func BuildFAT32(` |
| `BuildGPTImage` | function | `fuzzer/fat_image.go:214` | `func BuildGPTImage(` |
| `DefaultFAT16Config` | function | `fuzzer/fat_image.go:52` | `func DefaultFAT16Config(` |
| `DefaultFAT32Config` | function | `fuzzer/fat_image.go:131` | `func DefaultFAT32Config(` |
| `FAT16Config` | struct | `fuzzer/fat_image.go:41` | `` |
| `FAT16DataSector` | function | `fuzzer/fat_image.go:107` | `func FAT16DataSector(` |
| `FAT32Config` | struct | `fuzzer/fat_image.go:118` | `` |
| `MutateFAT32BPB` | function | `fuzzer/fat_image.go:303` | `func MutateFAT32BPB(` |
| `RandomMutate` | function | `fuzzer/fat_image.go:324` | `func RandomMutate(` |
| `le16` | function | `fuzzer/fat_image.go:19` | `func le16(` |
| `le32` | function | `fuzzer/fat_image.go:20` | `func le32(` |
| `le64` | function | `fuzzer/fat_image.go:21` | `func le64(` |
| `newDisk` | function | `fuzzer/fat_image.go:29` | `func newDisk(` |
| `sfnChecksum` | function | `fuzzer/fat_image.go:430` | `func sfnChecksum(` |
| `BuildFAT12Minimal` | function | `fuzzer/main.go:290` | `func BuildFAT12Minimal(` |
| `FuzzExFATNumLabel` | function | `fuzzer/main.go:449` | `func FuzzExFATNumLabel(` |
| `FuzzFAT16LFNLength` | function | `fuzzer/main.go:507` | `func FuzzFAT16LFNLength(` |
| `FuzzFAT32BPB` | function | `fuzzer/main.go:343` | `func FuzzFAT32BPB(` |
| `FuzzGPTNEnt` | function | `fuzzer/main.go:398` | `func FuzzGPTNEnt(` |
| `buildAllSeeds` | function | `fuzzer/main.go:76` | `func buildAllSeeds(` |
| `main` | function | `fuzzer/main.go:51` | `func main(` |
| `disk_initialize` | function | `harness/diskio_ramdisk.c:68` | `DSTATUS disk_initialize(BYTE pdrv)` |
| `disk_ioctl` | function | `harness/diskio_ramdisk.c:114` | `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)` |
| `disk_read` | function | `harness/diskio_ramdisk.c:75` | `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)` |
| `disk_status` | function | `harness/diskio_ramdisk.c:62` | `DSTATUS disk_status(BYTE pdrv)` |
| `disk_write` | function | `harness/diskio_ramdisk.c:95` | `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)` |
| `get_fattime` | function | `harness/diskio_ramdisk.c:137` | `DWORD get_fattime(void)` |
| `ramdisk_eject` | function | `harness/diskio_ramdisk.c:55` | `void ramdisk_eject(void)` |
| `ramdisk_load` | function | `harness/diskio_ramdisk.c:46` | `void ramdisk_load(const BYTE *image, UINT size)` |
| `ramdisk_reset_stats` | function | `harness/diskio_ramdisk.c:35` | `void ramdisk_reset_stats(void)` |
| `DISKIO_RAMDISK_H` | macro | `harness/diskio_ramdisk.h:6` | `#define DISKIO_RAMDISK_H` |
| `RAMDISK_SECTOR_COUNT` | macro | `harness/diskio_ramdisk.h:14` | `#define RAMDISK_SECTOR_COUNT` |
| `RAMDISK_SECTOR_SIZE` | macro | `harness/diskio_ramdisk.h:13` | `#define RAMDISK_SECTOR_SIZE` |
| `RAMDISK_SIZE_BYTES` | macro | `harness/diskio_ramdisk.h:15` | `#define RAMDISK_SIZE_BYTES` |
| `ramdisk` | variable | `harness/diskio_ramdisk.h:19` | `extern BYTE ramdisk[RAMDISK_SECTOR_COUNT * RAMDISK_SECTOR_SIZE];` |
| `ramdisk_eject` | function | `harness/diskio_ramdisk.h:34` | `void ramdisk_eject(void);` |
| `ramdisk_load` | function | `harness/diskio_ramdisk.h:31` | `void ramdisk_load(const BYTE *image, UINT size);` |
| `ramdisk_read_count` | variable | `harness/diskio_ramdisk.h:23` | `extern volatile uint32_t ramdisk_read_count;` |
| `ramdisk_reset_stats` | function | `harness/diskio_ramdisk.h:26` | `void ramdisk_reset_stats(void);` |
| `ramdisk_write_count` | variable | `harness/diskio_ramdisk.h:24` | `extern volatile uint32_t ramdisk_write_count;` |
| `B4_BYTES_PER_SEC` | macro | `harness/exploit_disks.c:592` | `#define B4_BYTES_PER_SEC` |
| `B4_CLUS2SEC` | macro | `harness/exploit_disks.c:604` | `#define B4_CLUS2SEC(c)` |
| `B4_DATA_OFFSET_SECS` | macro | `harness/exploit_disks.c:603` | `#define B4_DATA_OFFSET_SECS` |
| `B4_FAT_OFFSET_SECS` | macro | `harness/exploit_disks.c:601` | `#define B4_FAT_OFFSET_SECS(n)` |
| `B4_FAT_SIZE_SECS` | macro | `harness/exploit_disks.c:597` | `#define B4_FAT_SIZE_SECS` |
| `B4_N_FATS` | macro | `harness/exploit_disks.c:595` | `#define B4_N_FATS` |
| `B4_RESERVED_SECS` | macro | `harness/exploit_disks.c:594` | `#define B4_RESERVED_SECS` |
| `B4_ROOT_DIR_SECS` | macro | `harness/exploit_disks.c:599` | `#define B4_ROOT_DIR_SECS` |
| `B4_ROOT_ENTRIES` | macro | `harness/exploit_disks.c:596` | `#define B4_ROOT_ENTRIES` |
| `B4_ROOT_OFFSET_SECS` | macro | `harness/exploit_disks.c:602` | `#define B4_ROOT_OFFSET_SECS` |
| `B4_SEC_PER_CLUS` | macro | `harness/exploit_disks.c:593` | `#define B4_SEC_PER_CLUS` |
| `B4_SYS_SECS` | macro | `harness/exploit_disks.c:600` | `#define B4_SYS_SECS` |
| `B4_TOT_SECS` | macro | `harness/exploit_disks.c:598` | `#define B4_TOT_SECS` |
| `B5_CLUS2SEC` | macro | `harness/exploit_disks.c:739` | `#define B5_CLUS2SEC(c)` |
| `B5_SECRET` | macro | `harness/exploit_disks.c:740` | `#define B5_SECRET` |
| `B5_SEC_PER_CLUS` | macro | `harness/exploit_disks.c:738` | `#define B5_SEC_PER_CLUS` |
| `B5_WRITE_SIZE` | macro | `harness/exploit_disks.c:741` | `#define B5_WRITE_SIZE` |
| `FAIL` | macro | `harness/exploit_disks.c:110` | `#define FAIL(label)` |
| `IMG_DIR` | macro | `harness/exploit_disks.c:94` | `#define IMG_DIR` |
| `INFO` | macro | `harness/exploit_disks.c:108` | `#define INFO(fmt, ...)` |
| `MicroPython` | function | `harness/exploit_disks.c:498` | `*                            MicroPython (if the port enables FF_LBA64)  *  * R0.16 fix:  test_gp...` |
| `PASS` | macro | `harness/exploit_disks.c:109` | `#define PASS(label)` |
| `Payload` | function | `harness/exploit_disks.c:293` | `*   Payload (sector 8): placeholder address 0xDEADBEEFCAFEBABE  *   Simulates: embedded OTA reade...` |
| `SKIP` | macro | `harness/exploit_disks.c:111` | `#define SKIP(label)` |
| `Zephyr` | function | `harness/exploit_disks.c:836` | `*                     Zephyr (R0.16), ArduPilot (R0.14b),  *                     RIOT-OS (R0.15),...` |
| `bug1_build` | function | `harness/exploit_disks.c:241` | `static uint8_t *bug1_build(uint32_t file_size,                             const uint8_t *payload...` |
| `bug1_fill_payload` | function | `harness/exploit_disks.c:227` | `static void bug1_fill_payload(uint8_t *disk,                                const uint8_t *payloa...` |
| `bug1_verify` | function | `harness/exploit_disks.c:255` | `static int bug1_verify(uint8_t *disk, const char *filename)` |
| `bug1_write_vbr` | function | `harness/exploit_disks.c:156` | `static void bug1_write_vbr(uint8_t *disk)` |
| `bug4_set_fat16_entry` | function | `harness/exploit_disks.c:638` | `static void bug4_set_fat16_entry(uint8_t *disk, uint16_t cluster, uint16_t value)` |
| `bug6_verify_overflow` | function | `harness/exploit_disks.c:893` | `static int bug6_verify_overflow(uint8_t *disk, const char *imgname,                              ...` |
| `bug7_build` | function | `harness/exploit_disks.c:1007` | `static void bug7_build(uint8_t *disk, int lfn_len, uint16_t dirent_name_size)` |
| `bug7_verify` | function | `harness/exploit_disks.c:1060` | `static int bug7_verify(uint8_t *disk, const char *imgname, int expected_lfn_len)` |
| `cc` | function | `harness/exploit_disks.c:673` | `* if cc (sectors remaining) is also large, 0xFFFFFFFC < cc → TRUE * → memcpy fires at offset 0xFFFFFFFC * 512 (out...` |
| `chain` | function | `harness/exploit_disks.c:576` | `*   An application writes 64 bytes to the END of cluster chain (fp->sect = X,  *   FA_DIRTY set),...` |
| `code` | function | `harness/exploit_disks.c:564` | `* * Vulnerable code (ff.c non-tiny path, f_read multi-sector branch): * disk_read(pdrv, rbuff, sect, cc);` |
| `exploit_disks` | function | `harness/exploit_disks.c:49` | `*   make exploit_disks            (see Makefile target)  *  * Expected output:  *   Generating 14...` |
| `gen_bug1_ardupilot` | function | `harness/exploit_disks.c:382` | `static void gen_bug1_ardupilot(void)` |
| `gen_bug1_espidf` | function | `harness/exploit_disks.c:317` | `static void gen_bug1_espidf(void)` |
| `gen_bug1_keystone3` | function | `harness/exploit_disks.c:359` | `static void gen_bug1_keystone3(void)` |
| `gen_bug1_stm32` | function | `harness/exploit_disks.c:338` | `static void gen_bug1_stm32(void)` |
| `gen_bug2_exfat` | function | `harness/exploit_disks.c:456` | `static void gen_bug2_exfat(void)` |
| `gen_bug4_fragmented` | function | `harness/exploit_disks.c:648` | `static void gen_bug4_fragmented(void)` |
| `gen_bug6_stm32` | function | `harness/exploit_disks.c:933` | `static void gen_bug6_stm32(void)` |
| `gen_bug6_zephyr` | function | `harness/exploit_disks.c:948` | `static void gen_bug6_zephyr(void)` |
| `gen_bug7_max255` | function | `harness/exploit_disks.c:1096` | `static void gen_bug7_max255(void)` |
| `gen_bug7_zephyr` | function | `harness/exploit_disks.c:1112` | `static void gen_bug7_zephyr(void)` |
| `layout` | function | `harness/exploit_disks.c:990` | `*  * Directory layout (FAT16):  *   Entries in order: LFN entries (N × 32 bytes) then 8.3 SFN ent...` |
| `load_ramdisk` | function | `harness/exploit_disks.c:129` | `static void load_ramdisk(const uint8_t *buf, size_t sz)` |
| `main` | function | `harness/exploit_disks.c:1273` | `int main(void)` |
| `save_image` | function | `harness/exploit_disks.c:116` | `static int save_image(const char *name, const uint8_t *buf, size_t sz)` |
| `st32le` | function | `harness/exploit_disks.c:99` | `static inline void st32le(uint8_t *p, uint32_t v)` |
| `st64le` | function | `harness/exploit_disks.c:102` | `static inline void st64le(uint8_t *p, uint64_t v)` |
| `ff_uni2oem` | function | `harness/ffunicode_stub.c:5` | `* ff_uni2oem() and ff_wtoupper() which normally come from ffunicode.c.  * These stubs are suffici...` |
| `ff_uni2oem` | function | `harness/ffunicode_stub.c:18` | `WCHAR ff_uni2oem(DWORD uni, WORD cp)` |
| `ff_wtoupper` | function | `harness/ffunicode_stub.c:25` | `DWORD ff_wtoupper(DWORD chr)` |
| `Usage` | function | `harness/libfuzzer_harness.c:10` | `*  * Usage (libFuzzer):  *   ./fuzz_fatfs -max_len=2097152 corpus/  *  * Usage (AFL++):  *   afl-...` |
| `main` | function | `harness/libfuzzer_harness.c:128` | `int main(int argc, char **argv)` |
| `Build` | function | `harness/rce_demo.c:46` | `*  * Build (without sanitisers, without stack protector — lets the overflow  * reach the function...` |
| `FW_HDR_SIZE` | macro | `harness/rce_demo.c:96` | `#define FW_HDR_SIZE` |
| `__attribute__` | function | `harness/rce_demo.c:132` | `__attribute__((noinline)) static void rce_win(void)` |
| `build_exploit_image` | function | `harness/rce_demo.c:232` | `static void build_exploit_image(uint8_t *disk, size_t disk_bytes,                                ...` |
| `fasize` | function | `harness/rce_demo.c:258` | `* fasize (DWORD) = 0x80000001 * 2 = 0x100000002 → truncates to 2 * sysect = 4 + 2 + 0 = 6 → database = sector 6...` |
| `fw_header` | type_alias | `harness/rce_demo.c:97` | `typedef struct ota_ctx { uint8_t fw_header[FW_HDR_SIZE];` |
| `load_image` | function | `harness/rce_demo.c:363` | `static int load_image(const char *path)` |
| `main` | function | `harness/rce_demo.c:380` | `int main(void)` |
| `ota_ctx` | struct | `harness/rce_demo.c:98` | `` |
| `safe_update_complete` | function | `harness/rce_demo.c:123` | `static void safe_update_complete(void)` |
| `save_image` | function | `harness/rce_demo.c:348` | `static int save_image(const char *path, const uint8_t *disk, size_t sz)` |
| `st32le` | function | `harness/rce_demo.c:73` | `static inline void st32le(uint8_t *p, uint32_t v)` |
| `st64le` | function | `harness/rce_demo.c:76` | `static inline void st64le(uint8_t *p, uint64_t v)` |
| `vulnerable_ota_check` | function | `harness/rce_demo.c:155` | `static void vulnerable_ota_check(void)` |
| `FFCONF_DEF` | macro | `harness/test_ffconf.h:25` | `#define FFCONF_DEF` |
| `FF_CODE_PAGE` | macro | `harness/test_ffconf.h:43` | `#define FF_CODE_PAGE` |
| `FF_FS_CRTIME` | macro | `harness/test_ffconf.h:70` | `#define FF_FS_CRTIME` |
| `FF_FS_EXFAT` | macro | `harness/test_ffconf.h:65` | `#define FF_FS_EXFAT` |
| `FF_FS_LOCK` | macro | `harness/test_ffconf.h:72` | `#define FF_FS_LOCK` |
| `FF_FS_MINIMIZE` | macro | `harness/test_ffconf.h:29` | `#define FF_FS_MINIMIZE` |
| `FF_FS_NOFSINFO` | macro | `harness/test_ffconf.h:71` | `#define FF_FS_NOFSINFO` |
| `FF_FS_NORTC` | macro | `harness/test_ffconf.h:66` | `#define FF_FS_NORTC` |
| `FF_FS_READONLY` | macro | `harness/test_ffconf.h:28` | `#define FF_FS_READONLY` |
| `FF_FS_REENTRANT` | macro | `harness/test_ffconf.h:73` | `#define FF_FS_REENTRANT` |
| `FF_FS_RPATH` | macro | `harness/test_ffconf.h:49` | `#define FF_FS_RPATH` |
| `FF_FS_TINY` | macro | `harness/test_ffconf.h:64` | `#define FF_FS_TINY` |
| `FF_LBA64` | macro | `harness/test_ffconf.h:59` | `#define FF_LBA64` |
| `FF_LFN_BUF` | macro | `harness/test_ffconf.h:47` | `#define FF_LFN_BUF` |
| `FF_LFN_UNICODE` | macro | `harness/test_ffconf.h:46` | `#define FF_LFN_UNICODE` |
| `FF_MAX_LFN` | macro | `harness/test_ffconf.h:45` | `#define FF_MAX_LFN` |
| `FF_MAX_SS` | macro | `harness/test_ffconf.h:58` | `#define FF_MAX_SS` |
| `FF_MIN_GPT` | macro | `harness/test_ffconf.h:60` | `#define FF_MIN_GPT` |
| `FF_MIN_SS` | macro | `harness/test_ffconf.h:57` | `#define FF_MIN_SS` |
| `FF_MULTI_PARTITION` | macro | `harness/test_ffconf.h:56` | `#define FF_MULTI_PARTITION` |
| `FF_NORTC_MDAY` | macro | `harness/test_ffconf.h:68` | `#define FF_NORTC_MDAY` |
| `FF_NORTC_MON` | macro | `harness/test_ffconf.h:67` | `#define FF_NORTC_MON` |
| `FF_NORTC_YEAR` | macro | `harness/test_ffconf.h:69` | `#define FF_NORTC_YEAR` |
| `FF_PATH_DEPTH` | macro | `harness/test_ffconf.h:50` | `#define FF_PATH_DEPTH` |
| `FF_PRINT_FLOAT` | macro | `harness/test_ffconf.h:39` | `#define FF_PRINT_FLOAT` |
| `FF_PRINT_LLI` | macro | `harness/test_ffconf.h:38` | `#define FF_PRINT_LLI` |
| `FF_SFN_BUF` | macro | `harness/test_ffconf.h:48` | `#define FF_SFN_BUF` |
| `FF_STRF_ENCODE` | macro | `harness/test_ffconf.h:40` | `#define FF_STRF_ENCODE` |
| `FF_STR_VOLUME_ID` | macro | `harness/test_ffconf.h:54` | `#define FF_STR_VOLUME_ID` |
| `FF_USE_CHMOD` | macro | `harness/test_ffconf.h:34` | `#define FF_USE_CHMOD` |
| `FF_USE_EXPAND` | macro | `harness/test_ffconf.h:33` | `#define FF_USE_EXPAND` |
| `FF_USE_FASTSEEK` | macro | `harness/test_ffconf.h:32` | `#define FF_USE_FASTSEEK` |
| `FF_USE_FIND` | macro | `harness/test_ffconf.h:30` | `#define FF_USE_FIND` |
| `FF_USE_FORWARD` | macro | `harness/test_ffconf.h:36` | `#define FF_USE_FORWARD` |
| `FF_USE_LABEL` | macro | `harness/test_ffconf.h:35` | `#define FF_USE_LABEL` |
| `FF_USE_LFN` | macro | `harness/test_ffconf.h:44` | `#define FF_USE_LFN` |
| `FF_USE_MKFS` | macro | `harness/test_ffconf.h:31` | `#define FF_USE_MKFS` |
| `FF_USE_STRFUNC` | macro | `harness/test_ffconf.h:37` | `#define FF_USE_STRFUNC` |
| `FF_USE_TRIM` | macro | `harness/test_ffconf.h:61` | `#define FF_USE_TRIM` |
| `FF_VOLUMES` | macro | `harness/test_ffconf.h:53` | `#define FF_VOLUMES` |
| `FF_VOLUME_STRS` | macro | `harness/test_ffconf.h:55` | `#define FF_VOLUME_STRS` |
| `TEST_FFCONF_H` | macro | `harness/test_ffconf.h:22` | `#define TEST_FFCONF_H` |
| `B7_FILE_SIZE` | macro | `harness/test_harness.c:1103` | `#define B7_FILE_SIZE` |
| `B7_LFN_LEN` | macro | `harness/test_harness.c:1102` | `#define B7_LFN_LEN` |
| `F16_BYTES_PER_SEC` | macro | `harness/test_harness.c:703` | `#define F16_BYTES_PER_SEC` |
| `F16_CLUS2SEC` | macro | `harness/test_harness.c:717` | `#define F16_CLUS2SEC(c)` |
| `F16_DATA_OFFSET_SECS` | macro | `harness/test_harness.c:716` | `#define F16_DATA_OFFSET_SECS` |
| `F16_FAT_OFFSET_SECS` | macro | `harness/test_harness.c:714` | `#define F16_FAT_OFFSET_SECS(n)` |
| `F16_FAT_SIZE_SECS` | macro | `harness/test_harness.c:708` | `#define F16_FAT_SIZE_SECS` |
| `F16_N_FATS` | macro | `harness/test_harness.c:706` | `#define F16_N_FATS` |
| `F16_RESERVED_SECS` | macro | `harness/test_harness.c:705` | `#define F16_RESERVED_SECS` |
| `F16_ROOT_DIR_SECS` | macro | `harness/test_harness.c:711` | `#define F16_ROOT_DIR_SECS` |
| `F16_ROOT_ENTRIES` | macro | `harness/test_harness.c:707` | `#define F16_ROOT_ENTRIES` |
| `F16_ROOT_OFFSET_SECS` | macro | `harness/test_harness.c:715` | `#define F16_ROOT_OFFSET_SECS` |
| `F16_SEC_PER_CLUS` | macro | `harness/test_harness.c:704` | `#define F16_SEC_PER_CLUS` |
| `F16_SYS_SECS` | macro | `harness/test_harness.c:712` | `#define F16_SYS_SECS` |
| `F16_TOT_SECS` | macro | `harness/test_harness.c:709` | `#define F16_TOT_SECS` |
| `INFO` | macro | `harness/test_harness.c:84` | `#define INFO(fmt, ...)` |
| `LSEEK_TARGET` | macro | `harness/test_harness.c:780` | `#define LSEEK_TARGET` |
| `MCUs` | function | `harness/test_harness.c:261` | `*    common on embedded MCUs (STM32, RP2040, ESP32, …).  The resulting call  *    invokes rce_pro...` |
| `RESULT` | macro | `harness/test_harness.c:78` | `#define RESULT(label, cond)` |
| `SECRET_PATTERN` | macro | `harness/test_harness.c:774` | `#define SECRET_PATTERN` |
| `WRITE_SIZE` | macro | `harness/test_harness.c:779` | `#define WRITE_SIZE` |
| `__attribute__` | function | `harness/test_harness.c:764` | `__attribute__((unused)) static void fat16_set_chain(BYTE *disk, uint16_t cluster, uint16_t next)` |
| `buffers` | function | `harness/test_harness.c:36` | `*         buffers (e.g. char path[16]) and unchecked string copies  *         (sprintf, strcat) o...` |
| `build_fat16_base` | function | `harness/test_harness.c:726` | `static void build_fat16_base(BYTE *disk, size_t disk_bytes)` |
| `build_fat16_with_lfn` | function | `harness/test_harness.c:1105` | `static void build_fat16_with_lfn(BYTE *disk, size_t disk_bytes)` |
| `build_fat32_bug1` | function | `harness/test_harness.c:121` | `static void build_fat32_bug1(BYTE *disk, size_t disk_bytes)` |
| `build_gpt_image` | function | `harness/test_harness.c:459` | `static void build_gpt_image(BYTE *disk, size_t disk_bytes, uint32_t n_ent)` |
| `byte` | function | `harness/test_harness.c:1023` | `* sentinel byte (0xC3) so that any write beyond offset 24 is visible. * * f_getlabel must receive a pointer to byte...` |
| `code` | function | `harness/test_harness.c:89` | `* * Vulnerable code (ff.c ~line 3600): * * fasize = ld_16(fs->win + BPB_FATSz16);` |
| `layout` | function | `harness/test_harness.c:694` | `*  * Disk layout (FAT16, 4 sectors/cluster):  *   Sectors  0           VBR  *   Sectors  1-4     ...` |
| `main` | function | `harness/test_harness.c:1257` | `int main(void)` |
| `memcpy` | function | `harness/test_harness.c:561` | `* memcpy(rbuff + ((fp->sect - sect) * SS(fs)), fp->buf, SS(fs));` |
| `move_window` | function | `harness/test_harness.c:435` | `* move_window(fs, pt_lba + i * SZ_GPTE / SS(fs));` |
| `pass` | function | `harness/test_harness.c:927` | `*      or pass (sizeof_label - di) instead of the hard-coded 4.  *===============================...` |
| `rce_proof_of_execution` | function | `harness/test_harness.c:119` | `static void rce_proof_of_execution(void)` |
| `releases` | function | `harness/test_harness.c:510` | `*  * Historical note: older FatFs releases (before test_gpt_header was  * introduced) had no such...` |
| `sfn_checksum_b7` | function | `harness/test_harness.c:1090` | `static BYTE sfn_checksum_b7(const BYTE sfn[11])` |
| `sprintf` | function | `harness/test_harness.c:1075` | `* sprintf(path, "0:/%s", fno.fname);` |
| `st32le` | function | `harness/test_harness.c:65` | `static inline void st32le(BYTE *p, uint32_t v)` |
| `st64le` | function | `harness/test_harness.c:70` | `static inline void st64le(BYTE *p, uint64_t v)` |
| `strcat` | function | `harness/test_harness.c:1213` | `* strcat(path, fno.fname);` |
| `strcpy` | function | `harness/test_harness.c:1078` | `* strcpy(fname, fno.fname);` |
| `test_bug1_rce_exploit` | function | `harness/test_harness.c:339` | `static int test_bug1_rce_exploit(void)` |
| `test_bug4_stale_cache_skip` | function | `harness/test_harness.c:601` | `static int test_bug4_stale_cache_skip(void)` |
| `test_bug5_infoleak_lseek` | function | `harness/test_harness.c:782` | `static int test_bug5_infoleak_lseek(void)` |
| `test_bug6_getlabel_exfat_overflow` | function | `harness/test_harness.c:999` | `static int test_bug6_getlabel_exfat_overflow(void)` |
| `test_bug7_lfn_path_overflow` | function | `harness/test_harness.c:1157` | `static int test_bug7_lfn_path_overflow(void)` |
| `truncated` | function | `harness/test_harness.c:146` | `* truncated (DWORD) → 0x00000002 * * sysect = 4 (reserved) + 2 (fake fasize) + 0 (no root) = 6 * * fs->database =...` |

