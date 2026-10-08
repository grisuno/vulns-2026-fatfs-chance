# Subsystem: misc

## esp32-qemu-test/app/main/fatfs_vuln_test.c
- Layer: testing
- Language: c
- Symbols:
  - `ota_update_ctx` (struct, line 29)
  - `ota_exec_region` (struct, line 36)
  - `lfn_overflow_probe` (struct, line 48)
  - `fw_header` (type_alias, line 28) `typedef struct ota_update_ctx { uint8_t fw_header[FW_HDR_SIZE];`
  - `ctx` (type_alias, line 35) `typedef struct ota_exec_region { ota_update_ctx_t ctx;`
  - `name` (type_alias, line 47) `typedef struct lfn_overflow_probe { char name[32];`
  - `__attribute__` (function, line 55) `__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const struct dirent *entry)`
  - `legitimate_update_callback` (function, line 67) `static void legitimate_update_callback(void)`
  - `run_lfn_copy_probe` (function, line 72) `static bool run_lfn_copy_probe(void)`
  - `get_firmware_size` (function, line 121) `static long get_firmware_size(void)`
  - `read_firmware_image` (function, line 134) `static bool read_firmware_image(int fd, size_t firmware_size)`
  - `run_update_flow` (function, line 152) `static void run_update_flow(long attacker_fsize)`
  - `app_main` (function, line 170) `void app_main(void)`
  - `readdir` (function, line 76) `* readdir() returns an attacker-controlled long filename, then application * code copies it into a fixed 32-byte stack/global buffer without bounds * checks, matching public ESP32 code patterns. */ DI`
  - `MOUNT_POINT` (macro, line 23) `#define MOUNT_POINT`
  - `FW_HDR_SIZE` (macro, line 26) `#define FW_HDR_SIZE`
  - `OTA_READ_SLAB_SIZE` (macro, line 27) `#define OTA_READ_SLAB_SIZE`
  - `CANARY_CRC` (macro, line 43) `#define CANARY_CRC`
  - `CANARY_VERSION` (macro, line 44) `#define CANARY_VERSION`
  - `LFN_GUARD_VALUE` (macro, line 46) `#define LFN_GUARD_VALUE`

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
