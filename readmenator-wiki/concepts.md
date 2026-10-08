# Concepts

Second-brain semantic layer: nouns map atomically to file sets (EXTRACTED); verbs aggregate structural edges (INFERRED).

| Concept | Files | Mentions | Top Files |
|---------|-------|----------|-----------|
| `fat` | 21 | 61 | `FatFs-R0.16/documents/res/app1.c`, `FatFs-R0.16/documents/res/app2.c`, `FatFs-R0.16/documents/res/app3.c`, `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app5.c` |
| `size` | 11 | 62 | `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `esp32-qemu-test/scripts/gen_exploit_image.py` |
| `image` | 11 | 56 | `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `esp32-qemu-test/run.sh`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `esp32-qemu-test/scripts/run_test.sh`, `fuzzer/fat_image.go` |
| `read` | 11 | 31 | `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/app/main/fatfs_vuln_test.c` |
| `write` | 11 | 21 | `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/scripts/gen_exploit_image.py` |
| `disk` | 10 | 48 | `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.c`, `esp32-qemu-test/run.sh`, `fuzzer/fat_image.go` |
| `path` | 10 | 45 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffconf.h`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `esp32-qemu-test/scripts/run_test.sh` |
| `file` | 10 | 43 | `FatFs-R0.16/documents/res/app5.c`, `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/scripts/gen_exploit_image.py` |
| `harness` | 10 | 16 | `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c` |
| `lfn` | 9 | 78 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffconf.h`, `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `esp32-qemu-test/scripts/gen_exploit_image.py` |
| `byte` | 9 | 50 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go`, `fuzzer/main.go` |
| `volume` | 9 | 34 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffconf.h`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go` |
| `sector` | 8 | 45 | `FatFs-R0.16/source/diskio.h`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h` |
| `build` | 8 | 37 | `esp32-qemu-test/run.sh`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `esp32-qemu-test/scripts/run_test.sh`, `fuzzer/fat_image.go`, `fuzzer/main.go` |
| `code` | 8 | 37 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffconf.h`, `FatFs-R0.16/source/ffunicode.c`, `harness/exploit_disks.c` |
| `bytes` | 8 | 28 | `FatFs-R0.16/source/ff.c`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h` |
| `data` | 8 | 18 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/diskio_ramdisk.c` |
| `entry` | 8 | 16 | `FatFs-R0.16/source/ff.c`, `esp32-qemu-test/run.sh`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go`, `fuzzer/main.go` |
| `overflow` | 7 | 13 | `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `esp32-qemu-test/scripts/run_test.sh`, `fuzzer/main.go`, `harness/exploit_disks.c` |
| `partition` | 7 | 13 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffconf.h`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `esp32-qemu-test/scripts/run_test.sh` |
| `exfat` | 7 | 10 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffconf.h`, `fuzzer/main.go`, `harness/exploit_disks.c` |
| `not` | 7 | 8 | `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/scripts/run_test.sh`, `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/diskio_ramdisk.c` |
| `source` | 7 | 7 | `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffconf.h` |
| `use` | 6 | 45 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffconf.h`, `esp32-qemu-test/run.sh`, `fuzzer/fat_image.go` |
| `char` | 6 | 37 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/exploit_disks.c` |
| `get` | 6 | 36 | `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `fuzzer/fat_image.go` |
| `label` | 6 | 34 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffconf.h`, `fuzzer/fat_image.go`, `fuzzer/main.go` |
| `fat16` | 6 | 29 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/exploit_disks.c` |
| `fat32` | 6 | 27 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go`, `fuzzer/main.go` |
| `return` | 6 | 24 | `FatFs-R0.16/source/ff.c`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c` |
| `cve` | 6 | 23 | `esp32-qemu-test/scripts/gen_exploit_image.py`, `esp32-qemu-test/scripts/run_test.sh`, `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/exploit_disks.c` |
| `buf` | 6 | 19 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffconf.h`, `fuzzer/main.go`, `harness/exploit_disks.c`, `harness/test_ffconf.h` |
| `name` | 6 | 17 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go` |
| `root` | 6 | 17 | `FatFs-R0.16/source/ff.c`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go`, `harness/exploit_disks.c`, `harness/rce_demo.c` |
| `gpt` | 6 | 16 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffconf.h`, `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/test_ffconf.h` |
| `header` | 6 | 15 | `FatFs-R0.16/source/ff.c`, `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go`, `harness/rce_demo.c` |
| `clus` | 6 | 14 | `FatFs-R0.16/source/ff.c`, `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/exploit_disks.c`, `harness/rce_demo.c` |
| `sfn` | 6 | 14 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffconf.h`, `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/test_ffconf.h` |
| `mount` | 6 | 13 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `harness/exploit_disks.c` |
| `only` | 6 | 11 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/run.sh`, `fuzzer/main.go`, `harness/rce_demo.c` |
| `type` | 6 | 11 | `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `FatFs-R0.16/source/ffsystem.c`, `fuzzer/fat_image.go` |
| `entries` | 6 | 10 | `FatFs-R0.16/source/ff.c`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `fuzzer/fat_image.go`, `fuzzer/main.go`, `harness/exploit_disks.c` |
| `open` | 6 | 8 | `FatFs-R0.16/documents/res/app1.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/run.sh`, `harness/rce_demo.c` |
| `documents` | 6 | 6 | `FatFs-R0.16/documents/res/app1.c`, `FatFs-R0.16/documents/res/app2.c`, `FatFs-R0.16/documents/res/app3.c`, `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app5.c` |
| `res` | 6 | 6 | `FatFs-R0.16/documents/res/app1.c`, `FatFs-R0.16/documents/res/app2.c`, `FatFs-R0.16/documents/res/app3.c`, `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app5.c` |
| `define` | 5 | 56 | `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `harness/rce_demo.c` |
| `must` | 5 | 36 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `esp32-qemu-test/run.sh`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `harness/exploit_disks.c` |
| `dir` | 5 | 34 | `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ff.h`, `harness/exploit_disks.c`, `harness/rce_demo.c`, `harness/test_harness.c` |
| `void` | 5 | 32 | `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/ffunicode_stub.c`, `harness/rce_demo.c` |
| `run` | 5 | 20 | `esp32-qemu-test/app/main/fatfs_vuln_test.c`, `esp32-qemu-test/run.sh`, `esp32-qemu-test/scripts/gen_exploit_image.py`, `esp32-qemu-test/scripts/run_test.sh`, `fuzzer/main.go` |

## Verb Edges

| Source | Verb | Target | Strength |
|--------|------|--------|----------|
| `fat` | `depends_on` | `read` | 1.00 |
| `fat` | `depends_on` | `size` | 1.00 |
| `fat` | `depends_on` | `write` | 1.00 |
| `disk` | `depends_on` | `read` | 0.89 |
| `disk` | `depends_on` | `size` | 0.89 |
| `disk` | `depends_on` | `write` | 0.89 |
| `fat` | `depends_on` | `source` | 0.89 |
| `harness` | `depends_on` | `read` | 0.89 |
| `harness` | `depends_on` | `size` | 0.89 |
| `harness` | `depends_on` | `write` | 0.89 |
| `read` | `depends_on` | `size` | 0.89 |
| `read` | `depends_on` | `write` | 0.89 |
| `write` | `depends_on` | `read` | 0.89 |
| `write` | `depends_on` | `size` | 0.89 |
| `fat` | `depends_on` | `define` | 0.84 |
| `fat` | `depends_on` | `file` | 0.84 |
| `fat` | `depends_on` | `get` | 0.84 |
| `fat` | `depends_on` | `type` | 0.84 |
| `bytes` | `depends_on` | `read` | 0.79 |
| `bytes` | `depends_on` | `size` | 0.79 |
| `bytes` | `depends_on` | `write` | 0.79 |
| `size` | `depends_on` | `read` | 0.79 |
| `size` | `depends_on` | `write` | 0.79 |
| `data` | `depends_on` | `read` | 0.74 |
| `data` | `depends_on` | `size` | 0.74 |
| `data` | `depends_on` | `write` | 0.74 |
| `file` | `depends_on` | `read` | 0.74 |
| `file` | `depends_on` | `size` | 0.74 |
| `file` | `depends_on` | `write` | 0.74 |
| `read` | `depends_on` | `fat` | 0.74 |
| `read` | `depends_on` | `source` | 0.74 |
| `write` | `depends_on` | `fat` | 0.74 |
| `write` | `depends_on` | `source` | 0.74 |
| `disk` | `depends_on` | `define` | 0.68 |
| `disk` | `depends_on` | `fat` | 0.68 |
| `disk` | `depends_on` | `file` | 0.68 |
| `disk` | `depends_on` | `get` | 0.68 |
| `disk` | `depends_on` | `source` | 0.68 |
| `disk` | `depends_on` | `type` | 0.68 |
| `image` | `depends_on` | `read` | 0.68 |
| `image` | `depends_on` | `size` | 0.68 |
| `image` | `depends_on` | `write` | 0.68 |
| `read` | `depends_on` | `define` | 0.68 |
| `read` | `depends_on` | `file` | 0.68 |
| `read` | `depends_on` | `get` | 0.68 |
| `read` | `depends_on` | `type` | 0.68 |
| `sector` | `depends_on` | `read` | 0.68 |
| `sector` | `depends_on` | `size` | 0.68 |
| `sector` | `depends_on` | `write` | 0.68 |
| `write` | `depends_on` | `define` | 0.68 |

## Dialectic Prompts

- Thesis: `buf` centralizes 6 files; Antithesis: `byte` pulls 9 files with 4 shared (Jaccard 0.36); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `buf` centralizes 6 files; Antithesis: `char` pulls 6 files with 4 shared (Jaccard 0.50); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `buf` centralizes 6 files; Antithesis: `clus` pulls 6 files with 4 shared (Jaccard 0.50); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `buf` centralizes 6 files; Antithesis: `code` pulls 8 files with 5 shared (Jaccard 0.56); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `buf` centralizes 6 files; Antithesis: `data` pulls 8 files with 4 shared (Jaccard 0.40); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `buf` centralizes 6 files; Antithesis: `dir` pulls 5 files with 3 shared (Jaccard 0.38); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `buf` centralizes 6 files; Antithesis: `entries` pulls 6 files with 4 shared (Jaccard 0.50); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `buf` centralizes 6 files; Antithesis: `entry` pulls 8 files with 4 shared (Jaccard 0.40); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `buf` centralizes 6 files; Antithesis: `exfat` pulls 7 files with 6 shared (Jaccard 0.86); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `buf` centralizes 6 files; Antithesis: `fat16` pulls 6 files with 4 shared (Jaccard 0.50); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
