# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `FatFs-R0.16/source/ff.c` (score: 37.40)
- `FatFs-R0.16/source/ff.h` (score: 36.60)
- `FatFs-R0.16/source/diskio.h` (score: 20.60)
- `harness/diskio_ramdisk.h` (score: 13.00)
- `harness/exploit_disks.c` (score: 11.30)
- `harness/test_harness.c` (score: 10.80)
- `harness/rce_demo.c` (score: 7.40)
- `harness/diskio_ramdisk.c` (score: 6.90)
- `FatFs-R0.16/source/ffconf.h` (score: 6.20)
- `harness/libfuzzer_harness.c` (score: 6.20)

## Hotspots (complexity + centrality)

- `FatFs-R0.16/source/ff.h` -- complexity: 0.3, centrality: 1.0, combined: 0.7
- `FatFs-R0.16/source/ff.c` -- complexity: 1.0, centrality: 0.4, combined: 0.6
- `esp32-qemu-test/app/main/fatfs_vuln_test.c` -- complexity: 0.1, centrality: 0.9, combined: 0.6
- `harness/exploit_disks.c` -- complexity: 0.2, centrality: 0.7, combined: 0.5
- `harness/rce_demo.c` -- complexity: 0.0, centrality: 0.7, combined: 0.5
- `harness/test_harness.c` -- complexity: 0.1, centrality: 0.6, combined: 0.4
- `harness/libfuzzer_harness.c` -- complexity: 0.0, centrality: 0.6, combined: 0.4
- `FatFs-R0.16/source/ffsystem.c` -- complexity: 0.0, centrality: 0.6, combined: 0.3
- `FatFs-R0.16/source/diskio.h` -- complexity: 0.1, centrality: 0.5, combined: 0.3
- `harness/diskio_ramdisk.h` -- complexity: 0.0, centrality: 0.4, combined: 0.3

## Dataflow Issues (INFERRED, review each lead)

- `harness/exploit_disks.c:877` `Zephyr` [DEAD_STORE] `lab`: `lab` assigned at line 877 but never read afterwards.
