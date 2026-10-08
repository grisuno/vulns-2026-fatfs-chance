# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `FatFs-R0.16/source/ff.c` (score: 37.40)
- `FatFs-R0.16/source/ff.h` (score: 36.60, imported by 13 files)
- `FatFs-R0.16/source/diskio.h` (score: 20.60, imported by 9 files)
- `harness/diskio_ramdisk.h` (score: 13.00, imported by 5 files)
- `harness/exploit_disks.c` (score: 11.30)
- `harness/rce_demo.c` (score: 7.40)
- `harness/diskio_ramdisk.c` (score: 6.90)
- `FatFs-R0.16/source/ffconf.h` (score: 6.20, imported by 1 files)
- `harness/libfuzzer_harness.c` (score: 6.20)

## Blast Radius (change impact)

Editing these files can break the listed number of dependents. Run their tests after any change.

- `FatFs-R0.16/source/ffconf.h` -- 1 direct, 14 total dependents
- `FatFs-R0.16/source/ff.h` -- 13 direct, 13 total dependents
- `FatFs-R0.16/source/diskio.h` -- 9 direct, 9 total dependents
- `harness/diskio_ramdisk.h` -- 5 direct, 5 total dependents

## Hotspots (complexity + centrality)

- `FatFs-R0.16/source/ff.h` -- complexity: 0.3, centrality: 1.0, combined: 0.7
- `FatFs-R0.16/source/ff.c` -- complexity: 1.0, centrality: 0.4, combined: 0.6
- `harness/exploit_disks.c` -- complexity: 0.2, centrality: 0.7, combined: 0.5
- `harness/rce_demo.c` -- complexity: 0.0, centrality: 0.7, combined: 0.5
- `harness/libfuzzer_harness.c` -- complexity: 0.0, centrality: 0.6, combined: 0.4
- `FatFs-R0.16/source/ffsystem.c` -- complexity: 0.0, centrality: 0.6, combined: 0.3
- `FatFs-R0.16/source/diskio.h` -- complexity: 0.1, centrality: 0.5, combined: 0.3
- `harness/diskio_ramdisk.h` -- complexity: 0.0, centrality: 0.4, combined: 0.3
- `harness/diskio_ramdisk.c` -- complexity: 0.0, centrality: 0.4, combined: 0.2
- `fuzzer/main.go` -- complexity: 0.0, centrality: 0.4, combined: 0.2

## Dataflow Issues (INFERRED, review each lead)

- `harness/exploit_disks.c:877` `Zephyr` [DEAD_STORE] `lab`: `lab` assigned at line 877 but never read afterwards.
