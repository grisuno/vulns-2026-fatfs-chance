# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `FatFs-R0.16/source/ff.h` (score: 40.00)
- `FatFs-R0.16/source/ff.c` (score: 39.10)
- `FatFs-R0.16/source/diskio.h` (score: 21.10)
- `harness/exploit_disks.c` (score: 14.00)
- `harness/diskio_ramdisk.h` (score: 13.00)
- `harness/test_harness.c` (score: 12.40)
- `harness/rce_demo.c` (score: 8.60)
- `harness/libfuzzer_harness.c` (score: 7.70)
- `harness/diskio_ramdisk.c` (score: 7.10)
- `FatFs-R0.16/source/ffconf.h` (score: 6.20)

## Hotspots (complexity + centrality)

- `FatFs-R0.16/source/ff.h` -- complexity: 0.3, centrality: 1.0, combined: 0.7
- `FatFs-R0.16/source/ff.c` -- complexity: 1.0, centrality: 0.4, combined: 0.6
- `esp32-qemu-test/app/main/fatfs_vuln_test.c` -- complexity: 0.1, centrality: 0.9, combined: 0.6
- `harness/exploit_disks.c` -- complexity: 0.2, centrality: 0.7, combined: 0.5
- `harness/rce_demo.c` -- complexity: 0.1, centrality: 0.7, combined: 0.5
- `harness/test_harness.c` -- complexity: 0.2, centrality: 0.6, combined: 0.4
- `harness/libfuzzer_harness.c` -- complexity: 0.0, centrality: 0.6, combined: 0.4
- `FatFs-R0.16/source/ffsystem.c` -- complexity: 0.1, centrality: 0.6, combined: 0.4
- `FatFs-R0.16/source/diskio.h` -- complexity: 0.1, centrality: 0.5, combined: 0.3
- `harness/diskio_ramdisk.h` -- complexity: 0.0, centrality: 0.4, combined: 0.3
