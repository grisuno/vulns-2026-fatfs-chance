# orphans

*Community 3 | 11 files | cohesion 0.00*

## Definition

This community groups 11 file(s) rooted at `FatFs-R0.16/documents/res` with dominant language c (cohesion 0.00). Central symbols: `BuildExFATImage`, `BuildExFATWithLargeLabel`, `BuildFAT12Minimal`, `BuildFAT16`, `BuildFAT16WithLFNFile`, `BuildFAT32`, `BuildGPTImage`, `CANARY_CRC`. Core file: `harness/test_ffconf.h` (42 symbols). Documented purpose: — Generate and inject the ESP32 QEMU PoC storage image.  The image is intentionally hybrid so one run can exercise two realistic paths:  1) CVE-2026-6682 setup .

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `FatFs-R0.16/documents/res/app1.c` | c | utility | 2 | yes |
| `FatFs-R0.16/documents/res/app2.c` | c | utility | 1 | yes |
| `FatFs-R0.16/documents/res/app3.c` | c | utility | 2 | yes |
| `FatFs-R0.16/documents/res/app5.c` | c | utility | 1 | yes |
| `esp32-qemu-test/app/main/fatfs_vuln_test.c` | c | testing | 20 | no |
| `esp32-qemu-test/run.sh` | sh | testing | 6 | yes |
| `esp32-qemu-test/scripts/gen_exploit_image.py` | py | testing | 8 | yes |
| `esp32-qemu-test/scripts/run_test.sh` | sh | testing | 0 | yes |
| `fuzzer/fat_image.go` | go | utility | 18 | no |
| `fuzzer/main.go` | go | utility | 7 | yes |
| `harness/test_ffconf.h` | h | testing | 42 | yes |

## Key Symbols

- `open_append` (function, `FatFs-R0.16/documents/res/app1.c:6`) `FRESULT open_append (     FIL* fp,            /* [OUT] File object to create */`
- `main` (function, `FatFs-R0.16/documents/res/app1.c:25`) `int main (void)`
- `delete_node` (function, `FatFs-R0.16/documents/res/app2.c:9`) `FRESULT delete_node (     TCHAR* path,    /* Path name buffer with the sub-direc`
- `allocate_contiguous_clusters` (function, `FatFs-R0.16/documents/res/app3.c:20`) `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:er`
- `main` (function, `FatFs-R0.16/documents/res/app3.c:78`) `int main (void)`
- `test_contiguous_file` (function, `FatFs-R0.16/documents/res/app5.c:5`) `FRESULT test_contiguous_file (     FIL* fp,    /* [IN]  Open file object to be c`
- `MOUNT_POINT` (macro, `esp32-qemu-test/app/main/fatfs_vuln_test.c:23`) `#define MOUNT_POINT`
- `FW_HDR_SIZE` (macro, `esp32-qemu-test/app/main/fatfs_vuln_test.c:26`) `#define FW_HDR_SIZE`
- `OTA_READ_SLAB_SIZE` (macro, `esp32-qemu-test/app/main/fatfs_vuln_test.c:27`) `#define OTA_READ_SLAB_SIZE`
- `fw_header` (type_alias, `esp32-qemu-test/app/main/fatfs_vuln_test.c:28`) `typedef struct ota_update_ctx { uint8_t fw_header[FW_HDR_SIZE];` - define FW_HDR_SIZE 128u define OTA_READ_SLAB_SIZE 512u
- `ota_update_ctx` (struct, `esp32-qemu-test/app/main/fatfs_vuln_test.c:29`)
- `ctx` (type_alias, `esp32-qemu-test/app/main/fatfs_vuln_test.c:35`) `typedef struct ota_exec_region { ota_update_ctx_t ctx;`
- `ota_exec_region` (struct, `esp32-qemu-test/app/main/fatfs_vuln_test.c:36`)
- `CANARY_CRC` (macro, `esp32-qemu-test/app/main/fatfs_vuln_test.c:43`) `#define CANARY_CRC`
- `CANARY_VERSION` (macro, `esp32-qemu-test/app/main/fatfs_vuln_test.c:44`) `#define CANARY_VERSION`
- `LFN_GUARD_VALUE` (macro, `esp32-qemu-test/app/main/fatfs_vuln_test.c:46`) `#define LFN_GUARD_VALUE`
- `name` (type_alias, `esp32-qemu-test/app/main/fatfs_vuln_test.c:47`) `typedef struct lfn_overflow_probe { char name[32];` - define LFN_GUARD_VALUE 0xA5A5C3C3u
- `lfn_overflow_probe` (struct, `esp32-qemu-test/app/main/fatfs_vuln_test.c:48`)
- `__attribute__` (function, `esp32-qemu-test/app/main/fatfs_vuln_test.c:55`) `__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const s`
- `legitimate_update_callback` (function, `esp32-qemu-test/app/main/fatfs_vuln_test.c:67`) `static void legitimate_update_callback(void)`
- `run_lfn_copy_probe` (function, `esp32-qemu-test/app/main/fatfs_vuln_test.c:72`) `static bool run_lfn_copy_probe(void)`
- `readdir` (function, `esp32-qemu-test/app/main/fatfs_vuln_test.c:76`) `* readdir() returns an attacker-controlled long filename, then application * cod`
- `get_firmware_size` (function, `esp32-qemu-test/app/main/fatfs_vuln_test.c:121`) `static long get_firmware_size(void)`
- `read_firmware_image` (function, `esp32-qemu-test/app/main/fatfs_vuln_test.c:134`) `static bool read_firmware_image(int fd, size_t firmware_size)`
- `run_update_flow` (function, `esp32-qemu-test/app/main/fatfs_vuln_test.c:152`) `static void run_update_flow(long attacker_fsize)`
- `app_main` (function, `esp32-qemu-test/app/main/fatfs_vuln_test.c:170`) `void app_main(void)`
- `usage` (function, `esp32-qemu-test/run.sh:25`)
- `image_exists` (function, `esp32-qemu-test/run.sh:35`)
- `ensure_image` (function, `esp32-qemu-test/run.sh:39`)
- `do_build` (function, `esp32-qemu-test/run.sh:46`)

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 0
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 3 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 0 (FatFs-R0.16/source: ff) and community 3 (orphans).
- [INFERRED] shares_context community 1 <-> 3 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 1 (FatFs-R0.16/source: ff) and community 3 (orphans).
- [INFERRED] shares_context community 2 <-> 3 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 2 (harness) and community 3 (orphans).

## Risks

- [taint high] `esp32-qemu-test/scripts/gen_exploit_image.py` -> `esp32-qemu-test/scripts/gen_exploit_image.py` via `subprocess` (0 hops)

## Open Questions

- Why do 2 file(s) lack file-level docs (e.g. `esp32-qemu-test/app/main/fatfs_vuln_test.c`)? What purpose do they serve?
- Is the dangerous import `subprocess` in `esp32-qemu-test/scripts/gen_exploit_image.py` still required, or can it be isolated?
- What would break if the most connected file in orphans changed?
- Should orphans be split, given cohesion 0.00?

## Sources

- `FatFs-R0.16/documents/res/app1.c`
- `FatFs-R0.16/documents/res/app2.c`
- `FatFs-R0.16/documents/res/app3.c`
- `FatFs-R0.16/documents/res/app5.c`
- `esp32-qemu-test/app/main/fatfs_vuln_test.c`
- `esp32-qemu-test/run.sh`
- `esp32-qemu-test/scripts/gen_exploit_image.py`
- `esp32-qemu-test/scripts/run_test.sh`
- `fuzzer/fat_image.go`
- `fuzzer/main.go`
- `harness/test_ffconf.h`
