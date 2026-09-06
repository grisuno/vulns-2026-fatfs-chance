# Subsystem: misc

## esp32-qemu-test/app/main/fatfs_vuln_test.c
- Layer: testing
- Doc: include <stdio.h> include <string.h> include <stdlib.h> include <sys/stat.h> include <errno.h> include <inttypes.h> incl
- Language: c
- Symbols:
  - `ota_update_ctx` (struct, line 29)
  - `ota_exec_region` (struct, line 36)
  - `lfn_overflow_probe` (struct, line 48)
  - `__attribute__` (function, line 54) `__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const struct dirent *entry)`
  - `legitimate_update_callback` (function, line 66) `static void legitimate_update_callback(void)`
  - `run_lfn_copy_probe` (function, line 71) `static bool run_lfn_copy_probe(void)`
  - `get_firmware_size` (function, line 120) `static long get_firmware_size(void)`
  - `read_firmware_image` (function, line 133) `static bool read_firmware_image(int fd, size_t firmware_size)`
  - `run_update_flow` (function, line 151) `static void run_update_flow(long attacker_fsize)`
  - `app_main` (function, line 170) `void app_main(void)`
  - `MOUNT_POINT` (macro, line 22)
  - `FW_HDR_SIZE` (macro, line 24)
  - `OTA_READ_SLAB_SIZE` (macro, line 27)
  - `CANARY_CRC` (macro, line 42)
  - `CANARY_VERSION` (macro, line 44)
  - `LFN_GUARD_VALUE` (macro, line 45)

## esp32-qemu-test/run.sh
- Layer: testing
- Doc: =========================================================================== run.sh — Build and run the ESP32 QEMU FatFs 
- Language: sh
- Symbols:
  - `usage` (function, line 25)
  - `image_exists` (function, line 35)
  - `ensure_image` (function, line 39)
  - `do_build` (function, line 46)
  - `do_run` (function, line 53)
  - `do_shell` (function, line 63)
