# Index

| File | Purpose | Subsystem | Symbols | Used by |
|------|---------|-----------|---------|---------|
| `FatFs-R0.16/documents/res/app1.c` | - | res | 2 | 0 |
| `FatFs-R0.16/documents/res/app2.c` | - | res | 1 | 0 |
| `FatFs-R0.16/documents/res/app3.c` | - | res | 2 | 0 |
| `FatFs-R0.16/documents/res/app4.c` | - | res | 3 | 0 |
| `FatFs-R0.16/documents/res/app5.c` | - | res | 1 | 0 |
| `FatFs-R0.16/documents/res/app6.c` | - | res | 1 | 0 |
| `FatFs-R0.16/source/diskio.c` | - | source | 8 | 0 |
| `FatFs-R0.16/source/diskio.h` | DSTATUS: ifdef __cplusplus | source | 26 | 9 |
| `FatFs-R0.16/source/ff.c` | FILESEM: #if FF_NORTC_YEAR < 1980 \|\| FF_NORTC_YEAR > 2107 \|\| FF_NORTC_MON < 1 \|\| FF_NORTC_MON >... | source | 334 | 0 |
| `FatFs-R0.16/source/ff.h` | PARTITION: #define _TEXT(x) U ## x #elif FF_USE_LFN && (FF_LFN_UNICODE < 0 \|\| FF_LFN_UNICODE >... | source | 86 | 13 |
| `FatFs-R0.16/source/ffconf.h` | - | source | 42 | 1 |
| `FatFs-R0.16/source/ffsystem.c` | - | source | 7 | 0 |
| `FatFs-R0.16/source/ffunicode.c` | ff_uni2oem: if FF_CODE_PAGE != 0 && FF_CODE_PAGE < 900 | source | 9 | 0 |
| `esp32-qemu-test/app/main/fatfs_vuln_test.c` | fw_header: define FW_HDR_SIZE 128u define OTA_READ_SLAB_SIZE 512u | misc | 20 | 0 |
| `esp32-qemu-test/run.sh` | - | misc | 6 | 0 |
| `esp32-qemu-test/scripts/gen_exploit_image.py` | — Generate and inject the ESP32 QEMU PoC storage image. | scripts | 8 | 0 |
| `esp32-qemu-test/scripts/run_test.sh` | - | scripts | 0 | 0 |
| `fuzzer/fat_image.go` | FAT16Config: FAT16Config holds parameters for a minimal FAT16 volume. | fuzzer | 18 | 0 |
| `fuzzer/main.go` | — FatFs corpus generator and native Go fuzzer  Modes of operation ────────────────── 1. | fuzzer | 7 | 0 |
| `harness/diskio_ramdisk.c` | ramdisk_load: Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data. | harness | 9 | 0 |
| `harness/diskio_ramdisk.h` | ramdisk_load: /* ── backing store (accessible for direct inspection in tests) ────────────... | harness | 10 | 5 |
| `harness/exploit_disks.c` | bug1_write_vbr: clst2sect(2) = 6 → attacker plants root-dir entry at sector 6 clst2sect(4) = 8 →... | harness | 53 | 0 |
| `harness/ffunicode_stub.c` | ff_wtoupper: WCHAR ff_oem2uni(WCHAR oem, WORD cp) { (void)cp; return (oem < 0x80) ? oem : 0; }... | harness | 3 | 0 |
| `harness/libfuzzer_harness.c` | main: f_close(&fp); break; /* process at most one file per fuzz iteration } f_closedir(&dj); }... | harness | 2 | 0 |
| `harness/rce_demo.c` | vulnerable_ota_check: This function is the VICTIM. | harness | 14 | 0 |
| `harness/test_ffconf.h` | - | harness | 42 | 0 |
| `harness/test_harness.c` | build_gpt_image: Minimal protective-MBR + GPT header disk image builder. | harness | 48 | 0 |
