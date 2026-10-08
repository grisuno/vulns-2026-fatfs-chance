# Architecture

## Internal Dependencies

- `FatFs-R0.16/documents/res/app4.c` -> `FatFs-R0.16/source/diskio.h`
- `FatFs-R0.16/documents/res/app4.c` -> `FatFs-R0.16/source/ff.h`
- `FatFs-R0.16/documents/res/app6.c` -> `FatFs-R0.16/source/diskio.h`
- `FatFs-R0.16/documents/res/app6.c` -> `FatFs-R0.16/source/ff.h`
- `FatFs-R0.16/source/diskio.c` -> `FatFs-R0.16/source/diskio.h`
- `FatFs-R0.16/source/diskio.c` -> `FatFs-R0.16/source/ff.h`
- `FatFs-R0.16/source/ff.c` -> `FatFs-R0.16/source/diskio.h`
- `FatFs-R0.16/source/ff.c` -> `FatFs-R0.16/source/ff.h`
- `FatFs-R0.16/source/ff.h` -> `FatFs-R0.16/source/ffconf.h`
- `FatFs-R0.16/source/ffsystem.c` -> `FatFs-R0.16/source/ff.h`
- `FatFs-R0.16/source/ffunicode.c` -> `FatFs-R0.16/source/ff.h`
- `harness/diskio_ramdisk.c` -> `FatFs-R0.16/source/diskio.h`
- `harness/diskio_ramdisk.c` -> `FatFs-R0.16/source/ff.h`
- `harness/diskio_ramdisk.c` -> `harness/diskio_ramdisk.h`
- `harness/diskio_ramdisk.h` -> `FatFs-R0.16/source/ff.h`
- `harness/exploit_disks.c` -> `FatFs-R0.16/source/diskio.h`
- `harness/exploit_disks.c` -> `FatFs-R0.16/source/ff.h`
- `harness/exploit_disks.c` -> `harness/diskio_ramdisk.h`
- `harness/ffunicode_stub.c` -> `FatFs-R0.16/source/ff.h`
- `harness/libfuzzer_harness.c` -> `FatFs-R0.16/source/diskio.h`
- `harness/libfuzzer_harness.c` -> `FatFs-R0.16/source/ff.h`
- `harness/libfuzzer_harness.c` -> `harness/diskio_ramdisk.h`
- `harness/rce_demo.c` -> `FatFs-R0.16/source/diskio.h`
- `harness/rce_demo.c` -> `FatFs-R0.16/source/ff.h`
- `harness/rce_demo.c` -> `harness/diskio_ramdisk.h`
- `harness/test_harness.c` -> `FatFs-R0.16/source/diskio.h`
- `harness/test_harness.c` -> `FatFs-R0.16/source/ff.h`
- `harness/test_harness.c` -> `harness/diskio_ramdisk.h`

## External Imports

- `FatFs-R0.16/documents/res/app4.c` -> stdio.h, string.h
- `FatFs-R0.16/documents/res/app6.c` -> stdio.h, systimer.h
- `FatFs-R0.16/source/diskio.c` -> platform.h, storage.h
- `FatFs-R0.16/source/ff.c` -> math.h, stdarg.h, string.h
- `FatFs-R0.16/source/ff.h` -> float.h, stdint.h, windows.h
- `FatFs-R0.16/source/ffsystem.c` -> FreeRTOS.h, cmsis_os.h, includes.h, itron.h, kernel.h, semphr.h, stdlib.h, windows.h
- `esp32-qemu-test/app/main/fatfs_vuln_test.c` -> dirent.h, errno.h, esp_idf_version.h, esp_log.h, esp_partition.h, esp_system.h, esp_vfs_fat.h, fcntl.h, freertos/FreeRTOS.h, freertos/task.h, inttypes.h, stdbool.h, stdio.h, stdlib.h, string.h, sys/stat.h, unistd.h
- `esp32-qemu-test/scripts/gen_exploit_image.py` -> os, struct, subprocess, sys, tempfile
- `fuzzer/fat_image.go` -> encoding/binary, math/rand
- `fuzzer/main.go` -> encoding/binary, flag, fmt, math/rand, os, path/filepath, testing
- `harness/diskio_ramdisk.c` -> string.h
- `harness/diskio_ramdisk.h` -> stdint.h
- `harness/exploit_disks.c` -> errno.h, stddef.h, stdint.h, stdio.h, stdlib.h, string.h, sys/stat.h
- `harness/libfuzzer_harness.c` -> stddef.h, stdint.h, stdio.h, stdlib.h, string.h
- `harness/rce_demo.c` -> assert.h, inttypes.h, stddef.h, stdint.h, stdio.h, stdlib.h, string.h
- `harness/test_harness.c` -> assert.h, stdint.h, stdio.h, stdlib.h, string.h
