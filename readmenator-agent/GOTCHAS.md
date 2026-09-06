# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `FatFs-R0.16/source/ff.c` (score: 33.20)
- `harness/exploit_disks.c` (score: 5.10)
- `FatFs-R0.16/source/ff.h` (score: 4.40)
- `FatFs-R0.16/source/ffconf.h` (score: 4.20)
- `harness/test_ffconf.h` (score: 4.20)
- `harness/test_harness.c` (score: 4.00)
- `FatFs-R0.16/source/diskio.h` (score: 2.40)
- `fuzzer/fat_image.go` (score: 1.80)
- `esp32-qemu-test/app/main/fatfs_vuln_test.c` (score: 1.60)
- `harness/rce_demo.c` (score: 1.20)

## Hotspots (complexity + centrality)

- `esp32-qemu-test/app/main/fatfs_vuln_test.c` -- complexity: 0.0, centrality: 1.0, combined: 0.6
- `FatFs-R0.16/source/ff.c` -- complexity: 1.0, centrality: 0.3, combined: 0.6
- `harness/exploit_disks.c` -- complexity: 0.2, centrality: 0.6, combined: 0.4
- `harness/rce_demo.c` -- complexity: 0.0, centrality: 0.6, combined: 0.4
- `harness/test_harness.c` -- complexity: 0.1, centrality: 0.5, combined: 0.3
- `FatFs-R0.16/source/ffsystem.c` -- complexity: 0.0, centrality: 0.5, combined: 0.3
- `harness/libfuzzer_harness.c` -- complexity: 0.0, centrality: 0.5, combined: 0.3
- `fuzzer/main.go` -- complexity: 0.0, centrality: 0.4, combined: 0.3
- `FatFs-R0.16/source/ff.h` -- complexity: 0.1, centrality: 0.2, combined: 0.2
- `esp32-qemu-test/scripts/gen_exploit_image.py` -- complexity: 0.0, centrality: 0.3, combined: 0.2
