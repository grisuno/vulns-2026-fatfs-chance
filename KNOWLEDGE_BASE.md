# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM.
> No LLMs. No tokens. Pure static analysis. See more [here](https://github.com/grisuno/ReadMenator)

**Total Files Parsed:** 27 | **Total Symbols Extracted:** 694 | **Total Imports:** 105

## Structural Knowledge Map
```mermaid
graph TD
    classDef mod fill:#1e1e1e,stroke:#ff6666,stroke-width:2px,color:#fff;
    classDef cls fill:#2d2d2d,stroke:#4ec9b0,stroke-width:2px,color:#fff;
    classDef fn fill:#333,stroke:#dcdcaa,stroke-width:1px,color:#dcdcaa;
    classDef ext fill:#111,stroke:#666,stroke-dasharray:5 5,color:#aaa;
    esp32_qemu_test_app_main_fatfs_vuln_test_c["fatfs_vuln_test.c (c)"]
    class esp32_qemu_test_app_main_fatfs_vuln_test_c mod;
    esp32_qemu_test_app_main_fatfs_vuln_test_c_ota_update_ctx["ota_update_ctx"]
    class esp32_qemu_test_app_main_fatfs_vuln_test_c_ota_update_ctx cls;
    esp32_qemu_test_app_main_fatfs_vuln_test_c --> esp32_qemu_test_app_main_fatfs_vuln_test_c_ota_update_ctx
    esp32_qemu_test_app_main_fatfs_vuln_test_c_ota_exec_region["ota_exec_region"]
    class esp32_qemu_test_app_main_fatfs_vuln_test_c_ota_exec_region cls;
    esp32_qemu_test_app_main_fatfs_vuln_test_c --> esp32_qemu_test_app_main_fatfs_vuln_test_c_ota_exec_region
    esp32_qemu_test_app_main_fatfs_vuln_test_c_lfn_overflow_probe["lfn_overflow_probe"]
    class esp32_qemu_test_app_main_fatfs_vuln_test_c_lfn_overflow_probe cls;
    esp32_qemu_test_app_main_fatfs_vuln_test_c --> esp32_qemu_test_app_main_fatfs_vuln_test_c_lfn_overflow_probe
    esp32_qemu_test_app_main_fatfs_vuln_test_c___attribute__["__attribute__"]
    class esp32_qemu_test_app_main_fatfs_vuln_test_c___attribute__ fn;
    esp32_qemu_test_app_main_fatfs_vuln_test_c --> esp32_qemu_test_app_main_fatfs_vuln_test_c___attribute__
    esp32_qemu_test_app_main_fatfs_vuln_test_c_legitimate_update_callback["legitimate_update_callback"]
    class esp32_qemu_test_app_main_fatfs_vuln_test_c_legitimate_update_callback fn;
    esp32_qemu_test_app_main_fatfs_vuln_test_c --> esp32_qemu_test_app_main_fatfs_vuln_test_c_legitimate_update_callback
    harness_exploit_disks_c["exploit_disks.c (c)"]
    class harness_exploit_disks_c mod;
    harness_exploit_disks_c_exploit_disks["exploit_disks"]
    class harness_exploit_disks_c_exploit_disks fn;
    harness_exploit_disks_c --> harness_exploit_disks_c_exploit_disks
    harness_exploit_disks_c_st32le["st32le"]
    class harness_exploit_disks_c_st32le fn;
    harness_exploit_disks_c --> harness_exploit_disks_c_st32le
    harness_exploit_disks_c_st64le["st64le"]
    class harness_exploit_disks_c_st64le fn;
    harness_exploit_disks_c --> harness_exploit_disks_c_st64le
    harness_exploit_disks_c_save_image["save_image"]
    class harness_exploit_disks_c_save_image fn;
    harness_exploit_disks_c --> harness_exploit_disks_c_save_image
    harness_exploit_disks_c_load_ramdisk["load_ramdisk"]
    class harness_exploit_disks_c_load_ramdisk fn;
    harness_exploit_disks_c --> harness_exploit_disks_c_load_ramdisk
    harness_rce_demo_c["rce_demo.c (c)"]
    class harness_rce_demo_c mod;
    harness_rce_demo_c_ota_ctx["ota_ctx"]
    class harness_rce_demo_c_ota_ctx cls;
    harness_rce_demo_c --> harness_rce_demo_c_ota_ctx
    harness_rce_demo_c_Build["Build"]
    class harness_rce_demo_c_Build fn;
    harness_rce_demo_c --> harness_rce_demo_c_Build
    harness_rce_demo_c_st32le["st32le"]
    class harness_rce_demo_c_st32le fn;
    harness_rce_demo_c --> harness_rce_demo_c_st32le
    harness_rce_demo_c_st64le["st64le"]
    class harness_rce_demo_c_st64le fn;
    harness_rce_demo_c --> harness_rce_demo_c_st64le
    harness_rce_demo_c_safe_update_complete["safe_update_complete"]
    class harness_rce_demo_c_safe_update_complete fn;
    harness_rce_demo_c --> harness_rce_demo_c_safe_update_complete
    FatFs_R0_16_source_ffsystem_c["ffsystem.c (c)"]
    class FatFs_R0_16_source_ffsystem_c mod;
    FatFs_R0_16_source_ffsystem_c_ff_memalloc["ff_memalloc"]
    class FatFs_R0_16_source_ffsystem_c_ff_memalloc fn;
    FatFs_R0_16_source_ffsystem_c --> FatFs_R0_16_source_ffsystem_c_ff_memalloc
    FatFs_R0_16_source_ffsystem_c_ff_memfree["ff_memfree"]
    class FatFs_R0_16_source_ffsystem_c_ff_memfree fn;
    FatFs_R0_16_source_ffsystem_c --> FatFs_R0_16_source_ffsystem_c_ff_memfree
    FatFs_R0_16_source_ffsystem_c_ff_mutex_create["ff_mutex_create"]
    class FatFs_R0_16_source_ffsystem_c_ff_mutex_create fn;
    FatFs_R0_16_source_ffsystem_c --> FatFs_R0_16_source_ffsystem_c_ff_mutex_create
    FatFs_R0_16_source_ffsystem_c_ff_mutex_delete["ff_mutex_delete"]
    class FatFs_R0_16_source_ffsystem_c_ff_mutex_delete fn;
    FatFs_R0_16_source_ffsystem_c --> FatFs_R0_16_source_ffsystem_c_ff_mutex_delete
    FatFs_R0_16_source_ffsystem_c_ff_mutex_take["ff_mutex_take"]
    class FatFs_R0_16_source_ffsystem_c_ff_mutex_take fn;
    FatFs_R0_16_source_ffsystem_c --> FatFs_R0_16_source_ffsystem_c_ff_mutex_take
    harness_test_harness_c["test_harness.c (c)"]
    class harness_test_harness_c mod;
    harness_test_harness_c_buffers["buffers"]
    class harness_test_harness_c_buffers fn;
    harness_test_harness_c --> harness_test_harness_c_buffers
    harness_test_harness_c_st32le["st32le"]
    class harness_test_harness_c_st32le fn;
    harness_test_harness_c --> harness_test_harness_c_st32le
    harness_test_harness_c_st64le["st64le"]
    class harness_test_harness_c_st64le fn;
    harness_test_harness_c --> harness_test_harness_c_st64le
    harness_test_harness_c_rce_proof_of_execution["rce_proof_of_execution"]
    class harness_test_harness_c_rce_proof_of_execution fn;
    harness_test_harness_c --> harness_test_harness_c_rce_proof_of_execution
    harness_test_harness_c_build_fat32_bug1["build_fat32_bug1"]
    class harness_test_harness_c_build_fat32_bug1 fn;
    harness_test_harness_c --> harness_test_harness_c_build_fat32_bug1
    harness_libfuzzer_harness_c["libfuzzer_harness.c (c)"]
    class harness_libfuzzer_harness_c mod;
    harness_libfuzzer_harness_c_Usage["Usage"]
    class harness_libfuzzer_harness_c_Usage fn;
    harness_libfuzzer_harness_c --> harness_libfuzzer_harness_c_Usage
    harness_libfuzzer_harness_c_main["main"]
    class harness_libfuzzer_harness_c_main fn;
    harness_libfuzzer_harness_c --> harness_libfuzzer_harness_c_main
    fuzzer_main_go["main.go (go)"]
    class fuzzer_main_go mod;
    fuzzer_main_go_main["main"]
    class fuzzer_main_go_main fn;
    fuzzer_main_go --> fuzzer_main_go_main
    fuzzer_main_go_buildAllSeeds["buildAllSeeds"]
    class fuzzer_main_go_buildAllSeeds fn;
    fuzzer_main_go --> fuzzer_main_go_buildAllSeeds
    fuzzer_main_go_BuildFAT12Minimal["BuildFAT12Minimal"]
    class fuzzer_main_go_BuildFAT12Minimal fn;
    fuzzer_main_go --> fuzzer_main_go_BuildFAT12Minimal
    fuzzer_main_go_FuzzFAT32BPB["FuzzFAT32BPB"]
    class fuzzer_main_go_FuzzFAT32BPB fn;
    fuzzer_main_go --> fuzzer_main_go_FuzzFAT32BPB
    fuzzer_main_go_FuzzGPTNEnt["FuzzGPTNEnt"]
    class fuzzer_main_go_FuzzGPTNEnt fn;
    fuzzer_main_go --> fuzzer_main_go_FuzzGPTNEnt
    FatFs_R0_16_source_ff_c["ff.c (c)"]
    class FatFs_R0_16_source_ff_c mod;
    FatFs_R0_16_source_ff_c_dbc_1st["dbc_1st"]
    class FatFs_R0_16_source_ff_c_dbc_1st fn;
    FatFs_R0_16_source_ff_c --> FatFs_R0_16_source_ff_c_dbc_1st
    FatFs_R0_16_source_ff_c_dbc_2nd["dbc_2nd"]
    class FatFs_R0_16_source_ff_c_dbc_2nd fn;
    FatFs_R0_16_source_ff_c --> FatFs_R0_16_source_ff_c_dbc_2nd
    FatFs_R0_16_source_ff_c_tchar2uni["tchar2uni"]
    class FatFs_R0_16_source_ff_c_tchar2uni fn;
    FatFs_R0_16_source_ff_c --> FatFs_R0_16_source_ff_c_tchar2uni
    FatFs_R0_16_source_ff_c_put_utf["put_utf"]
    class FatFs_R0_16_source_ff_c_put_utf fn;
    FatFs_R0_16_source_ff_c --> FatFs_R0_16_source_ff_c_put_utf
    FatFs_R0_16_source_ff_c_lock_volume["lock_volume"]
    class FatFs_R0_16_source_ff_c_lock_volume fn;
    FatFs_R0_16_source_ff_c --> FatFs_R0_16_source_ff_c_lock_volume
    esp32_qemu_test_scripts_gen_exploit_image_py["gen_exploit_image.py (py)"]
    class esp32_qemu_test_scripts_gen_exploit_image_py mod;
    esp32_qemu_test_scripts_gen_exploit_image_py_lfn_checksum["lfn_checksum"]
    class esp32_qemu_test_scripts_gen_exploit_image_py_lfn_checksum fn;
    esp32_qemu_test_scripts_gen_exploit_image_py --> esp32_qemu_test_scripts_gen_exploit_image_py_lfn_checksum
    esp32_qemu_test_scripts_gen_exploit_image_py_build_lfn_entries["build_lfn_entries"]
    class esp32_qemu_test_scripts_gen_exploit_image_py_build_lfn_entries fn;
    esp32_qemu_test_scripts_gen_exploit_image_py --> esp32_qemu_test_scripts_gen_exploit_image_py_build_lfn_entries
    esp32_qemu_test_scripts_gen_exploit_image_py_resolve_symbol_address["resolve_symbol_address"]
    class esp32_qemu_test_scripts_gen_exploit_image_py_resolve_symbol_address fn;
    esp32_qemu_test_scripts_gen_exploit_image_py --> esp32_qemu_test_scripts_gen_exploit_image_py_resolve_symbol_address
    esp32_qemu_test_scripts_gen_exploit_image_py_build_xtensa_uart_shellcode["build_xtensa_uart_shellcode"]
    class esp32_qemu_test_scripts_gen_exploit_image_py_build_xtensa_uart_shellcode fn;
    esp32_qemu_test_scripts_gen_exploit_image_py --> esp32_qemu_test_scripts_gen_exploit_image_py_build_xtensa_uart_shellcode
    esp32_qemu_test_scripts_gen_exploit_image_py_build_payload_sector["build_payload_sector"]
    class esp32_qemu_test_scripts_gen_exploit_image_py_build_payload_sector fn;
    esp32_qemu_test_scripts_gen_exploit_image_py --> esp32_qemu_test_scripts_gen_exploit_image_py_build_payload_sector
    FatFs_R0_16_source_ff_h["ff.h (h)"]
    class FatFs_R0_16_source_ff_h mod;
    FatFs_R0_16_source_ff_h_FF_DEFINED["FF_DEFINED"]
    class FatFs_R0_16_source_ff_h_FF_DEFINED fn;
    FatFs_R0_16_source_ff_h --> FatFs_R0_16_source_ff_h_FF_DEFINED
    FatFs_R0_16_source_ff_h_FF_INTDEF["FF_INTDEF"]
    class FatFs_R0_16_source_ff_h_FF_INTDEF fn;
    FatFs_R0_16_source_ff_h --> FatFs_R0_16_source_ff_h_FF_INTDEF
    FatFs_R0_16_source_ff_h_isnan["isnan"]
    class FatFs_R0_16_source_ff_h_isnan fn;
    FatFs_R0_16_source_ff_h --> FatFs_R0_16_source_ff_h_isnan
    FatFs_R0_16_source_ff_h_isinf["isinf"]
    class FatFs_R0_16_source_ff_h_isinf fn;
    FatFs_R0_16_source_ff_h --> FatFs_R0_16_source_ff_h_isinf
    FatFs_R0_16_source_ff_h_FF_INTDEF["FF_INTDEF"]
    class FatFs_R0_16_source_ff_h_FF_INTDEF fn;
    FatFs_R0_16_source_ff_h --> FatFs_R0_16_source_ff_h_FF_INTDEF
    harness_diskio_ramdisk_c["diskio_ramdisk.c (c)"]
    class harness_diskio_ramdisk_c mod;
    harness_diskio_ramdisk_c_ramdisk_reset_stats["ramdisk_reset_stats"]
    class harness_diskio_ramdisk_c_ramdisk_reset_stats fn;
    harness_diskio_ramdisk_c --> harness_diskio_ramdisk_c_ramdisk_reset_stats
    harness_diskio_ramdisk_c_ramdisk_load["ramdisk_load"]
    class harness_diskio_ramdisk_c_ramdisk_load fn;
    harness_diskio_ramdisk_c --> harness_diskio_ramdisk_c_ramdisk_load
    harness_diskio_ramdisk_c_ramdisk_eject["ramdisk_eject"]
    class harness_diskio_ramdisk_c_ramdisk_eject fn;
    harness_diskio_ramdisk_c --> harness_diskio_ramdisk_c_ramdisk_eject
    harness_diskio_ramdisk_c_disk_status["disk_status"]
    class harness_diskio_ramdisk_c_disk_status fn;
    harness_diskio_ramdisk_c --> harness_diskio_ramdisk_c_disk_status
    harness_diskio_ramdisk_c_disk_initialize["disk_initialize"]
    class harness_diskio_ramdisk_c_disk_initialize fn;
    harness_diskio_ramdisk_c --> harness_diskio_ramdisk_c_disk_initialize
    FatFs_R0_16_source_diskio_c["diskio.c (c)"]
    class FatFs_R0_16_source_diskio_c mod;
    FatFs_R0_16_source_diskio_c_disk_status["disk_status"]
    class FatFs_R0_16_source_diskio_c_disk_status fn;
    FatFs_R0_16_source_diskio_c --> FatFs_R0_16_source_diskio_c_disk_status
    FatFs_R0_16_source_diskio_c_disk_initialize["disk_initialize"]
    class FatFs_R0_16_source_diskio_c_disk_initialize fn;
    FatFs_R0_16_source_diskio_c --> FatFs_R0_16_source_diskio_c_disk_initialize
    FatFs_R0_16_source_diskio_c_disk_read["disk_read"]
    class FatFs_R0_16_source_diskio_c_disk_read fn;
    FatFs_R0_16_source_diskio_c --> FatFs_R0_16_source_diskio_c_disk_read
    FatFs_R0_16_source_diskio_c_disk_write["disk_write"]
    class FatFs_R0_16_source_diskio_c_disk_write fn;
    FatFs_R0_16_source_diskio_c --> FatFs_R0_16_source_diskio_c_disk_write
    FatFs_R0_16_source_diskio_c_disk_ioctl["disk_ioctl"]
    class FatFs_R0_16_source_diskio_c_disk_ioctl fn;
    FatFs_R0_16_source_diskio_c --> FatFs_R0_16_source_diskio_c_disk_ioctl
    FatFs_R0_16_documents_res_app4_c["app4.c (c)"]
    class FatFs_R0_16_documents_res_app4_c mod;
    FatFs_R0_16_documents_res_app4_c_pn["pn"]
    class FatFs_R0_16_documents_res_app4_c_pn fn;
    FatFs_R0_16_documents_res_app4_c --> FatFs_R0_16_documents_res_app4_c_pn
    FatFs_R0_16_documents_res_app4_c_test_diskio["test_diskio"]
    class FatFs_R0_16_documents_res_app4_c_test_diskio fn;
    FatFs_R0_16_documents_res_app4_c --> FatFs_R0_16_documents_res_app4_c_test_diskio
    FatFs_R0_16_documents_res_app4_c_main["main"]
    class FatFs_R0_16_documents_res_app4_c_main fn;
    FatFs_R0_16_documents_res_app4_c --> FatFs_R0_16_documents_res_app4_c_main
    FatFs_R0_16_documents_res_app6_c["app6.c (c)"]
    class FatFs_R0_16_documents_res_app6_c mod;
    FatFs_R0_16_documents_res_app6_c_test_raw_speed["test_raw_speed"]
    class FatFs_R0_16_documents_res_app6_c_test_raw_speed fn;
    FatFs_R0_16_documents_res_app6_c --> FatFs_R0_16_documents_res_app6_c_test_raw_speed
    fuzzer_fat_image_go["fat_image.go (go)"]
    class fuzzer_fat_image_go mod;
    fuzzer_fat_image_go_le16["le16"]
    class fuzzer_fat_image_go_le16 fn;
    fuzzer_fat_image_go --> fuzzer_fat_image_go_le16
    fuzzer_fat_image_go_le32["le32"]
    class fuzzer_fat_image_go_le32 fn;
    fuzzer_fat_image_go --> fuzzer_fat_image_go_le32
    fuzzer_fat_image_go_le64["le64"]
    class fuzzer_fat_image_go_le64 fn;
    fuzzer_fat_image_go --> fuzzer_fat_image_go_le64
    fuzzer_fat_image_go_newDisk["newDisk"]
    class fuzzer_fat_image_go_newDisk fn;
    fuzzer_fat_image_go --> fuzzer_fat_image_go_newDisk
    fuzzer_fat_image_go_DefaultFAT16Config["DefaultFAT16Config"]
    class fuzzer_fat_image_go_DefaultFAT16Config fn;
    fuzzer_fat_image_go --> fuzzer_fat_image_go_DefaultFAT16Config
    harness_diskio_ramdisk_h["diskio_ramdisk.h (h)"]
    class harness_diskio_ramdisk_h mod;
    harness_diskio_ramdisk_h_DISKIO_RAMDISK_H["DISKIO_RAMDISK_H"]
    class harness_diskio_ramdisk_h_DISKIO_RAMDISK_H fn;
    harness_diskio_ramdisk_h --> harness_diskio_ramdisk_h_DISKIO_RAMDISK_H
    harness_diskio_ramdisk_h_RAMDISK_SECTOR_SIZE["RAMDISK_SECTOR_SIZE"]
    class harness_diskio_ramdisk_h_RAMDISK_SECTOR_SIZE fn;
    harness_diskio_ramdisk_h --> harness_diskio_ramdisk_h_RAMDISK_SECTOR_SIZE
    harness_diskio_ramdisk_h_RAMDISK_SECTOR_COUNT["RAMDISK_SECTOR_COUNT"]
    class harness_diskio_ramdisk_h_RAMDISK_SECTOR_COUNT fn;
    harness_diskio_ramdisk_h --> harness_diskio_ramdisk_h_RAMDISK_SECTOR_COUNT
    harness_diskio_ramdisk_h_RAMDISK_SIZE_BYTES["RAMDISK_SIZE_BYTES"]
    class harness_diskio_ramdisk_h_RAMDISK_SIZE_BYTES fn;
    harness_diskio_ramdisk_h --> harness_diskio_ramdisk_h_RAMDISK_SIZE_BYTES
    FatFs_R0_16_source_ffunicode_c["ffunicode.c (c)"]
    class FatFs_R0_16_source_ffunicode_c mod;
    FatFs_R0_16_source_ffunicode_c_ff_uni2oem["ff_uni2oem"]
    class FatFs_R0_16_source_ffunicode_c_ff_uni2oem fn;
    FatFs_R0_16_source_ffunicode_c --> FatFs_R0_16_source_ffunicode_c_ff_uni2oem
    FatFs_R0_16_source_ffunicode_c_ff_oem2uni["ff_oem2uni"]
    class FatFs_R0_16_source_ffunicode_c_ff_oem2uni fn;
    FatFs_R0_16_source_ffunicode_c --> FatFs_R0_16_source_ffunicode_c_ff_oem2uni
    FatFs_R0_16_source_ffunicode_c_ff_uni2oem["ff_uni2oem"]
    class FatFs_R0_16_source_ffunicode_c_ff_uni2oem fn;
    FatFs_R0_16_source_ffunicode_c --> FatFs_R0_16_source_ffunicode_c_ff_uni2oem
    FatFs_R0_16_source_ffunicode_c_ff_oem2uni["ff_oem2uni"]
    class FatFs_R0_16_source_ffunicode_c_ff_oem2uni fn;
    FatFs_R0_16_source_ffunicode_c --> FatFs_R0_16_source_ffunicode_c_ff_oem2uni
    FatFs_R0_16_source_ffunicode_c_ff_uni2oem["ff_uni2oem"]
    class FatFs_R0_16_source_ffunicode_c_ff_uni2oem fn;
    FatFs_R0_16_source_ffunicode_c --> FatFs_R0_16_source_ffunicode_c_ff_uni2oem
    harness_ffunicode_stub_c["ffunicode_stub.c (c)"]
    class harness_ffunicode_stub_c mod;
    harness_ffunicode_stub_c_ff_uni2oem["ff_uni2oem"]
    class harness_ffunicode_stub_c_ff_uni2oem fn;
    harness_ffunicode_stub_c --> harness_ffunicode_stub_c_ff_uni2oem
    harness_ffunicode_stub_c_ff_uni2oem["ff_uni2oem"]
    class harness_ffunicode_stub_c_ff_uni2oem fn;
    harness_ffunicode_stub_c --> harness_ffunicode_stub_c_ff_uni2oem
    harness_ffunicode_stub_c_ff_wtoupper["ff_wtoupper"]
    class harness_ffunicode_stub_c_ff_wtoupper fn;
    harness_ffunicode_stub_c --> harness_ffunicode_stub_c_ff_wtoupper
    FatFs_R0_16_source_ffconf_h["ffconf.h (h)"]
    class FatFs_R0_16_source_ffconf_h mod;
    FatFs_R0_16_source_ffconf_h_FFCONF_DEF["FFCONF_DEF"]
    class FatFs_R0_16_source_ffconf_h_FFCONF_DEF fn;
    FatFs_R0_16_source_ffconf_h --> FatFs_R0_16_source_ffconf_h_FFCONF_DEF
    FatFs_R0_16_source_ffconf_h_FF_FS_READONLY["FF_FS_READONLY"]
    class FatFs_R0_16_source_ffconf_h_FF_FS_READONLY fn;
    FatFs_R0_16_source_ffconf_h --> FatFs_R0_16_source_ffconf_h_FF_FS_READONLY
    FatFs_R0_16_source_ffconf_h_FF_FS_MINIMIZE["FF_FS_MINIMIZE"]
    class FatFs_R0_16_source_ffconf_h_FF_FS_MINIMIZE fn;
    FatFs_R0_16_source_ffconf_h --> FatFs_R0_16_source_ffconf_h_FF_FS_MINIMIZE
    FatFs_R0_16_source_ffconf_h_FF_USE_FIND["FF_USE_FIND"]
    class FatFs_R0_16_source_ffconf_h_FF_USE_FIND fn;
    FatFs_R0_16_source_ffconf_h --> FatFs_R0_16_source_ffconf_h_FF_USE_FIND
    FatFs_R0_16_source_ffconf_h_FF_USE_MKFS["FF_USE_MKFS"]
    class FatFs_R0_16_source_ffconf_h_FF_USE_MKFS fn;
    FatFs_R0_16_source_ffconf_h --> FatFs_R0_16_source_ffconf_h_FF_USE_MKFS
    harness_test_ffconf_h["test_ffconf.h (h)"]
    class harness_test_ffconf_h mod;
    harness_test_ffconf_h_TEST_FFCONF_H["TEST_FFCONF_H"]
    class harness_test_ffconf_h_TEST_FFCONF_H fn;
    harness_test_ffconf_h --> harness_test_ffconf_h_TEST_FFCONF_H
    harness_test_ffconf_h_FFCONF_DEF["FFCONF_DEF"]
    class harness_test_ffconf_h_FFCONF_DEF fn;
    harness_test_ffconf_h --> harness_test_ffconf_h_FFCONF_DEF
    harness_test_ffconf_h_FF_FS_READONLY["FF_FS_READONLY"]
    class harness_test_ffconf_h_FF_FS_READONLY fn;
    harness_test_ffconf_h --> harness_test_ffconf_h_FF_FS_READONLY
    harness_test_ffconf_h_FF_FS_MINIMIZE["FF_FS_MINIMIZE"]
    class harness_test_ffconf_h_FF_FS_MINIMIZE fn;
    harness_test_ffconf_h --> harness_test_ffconf_h_FF_FS_MINIMIZE
    harness_test_ffconf_h_FF_USE_FIND["FF_USE_FIND"]
    class harness_test_ffconf_h_FF_USE_FIND fn;
    harness_test_ffconf_h --> harness_test_ffconf_h_FF_USE_FIND
    FatFs_R0_16_source_diskio_h["diskio.h (h)"]
    class FatFs_R0_16_source_diskio_h mod;
    FatFs_R0_16_source_diskio_h__DISKIO_DEFINED["_DISKIO_DEFINED"]
    class FatFs_R0_16_source_diskio_h__DISKIO_DEFINED fn;
    FatFs_R0_16_source_diskio_h --> FatFs_R0_16_source_diskio_h__DISKIO_DEFINED
    FatFs_R0_16_source_diskio_h_STA_NOINIT["STA_NOINIT"]
    class FatFs_R0_16_source_diskio_h_STA_NOINIT fn;
    FatFs_R0_16_source_diskio_h --> FatFs_R0_16_source_diskio_h_STA_NOINIT
    FatFs_R0_16_source_diskio_h_STA_NODISK["STA_NODISK"]
    class FatFs_R0_16_source_diskio_h_STA_NODISK fn;
    FatFs_R0_16_source_diskio_h --> FatFs_R0_16_source_diskio_h_STA_NODISK
    FatFs_R0_16_source_diskio_h_STA_PROTECT["STA_PROTECT"]
    class FatFs_R0_16_source_diskio_h_STA_PROTECT fn;
    FatFs_R0_16_source_diskio_h --> FatFs_R0_16_source_diskio_h_STA_PROTECT
    FatFs_R0_16_source_diskio_h_CTRL_SYNC["CTRL_SYNC"]
    class FatFs_R0_16_source_diskio_h_CTRL_SYNC fn;
    FatFs_R0_16_source_diskio_h --> FatFs_R0_16_source_diskio_h_CTRL_SYNC
    esp32_qemu_test_run_sh["run.sh (sh)"]
    class esp32_qemu_test_run_sh mod;
    esp32_qemu_test_run_sh_usage["usage"]
    class esp32_qemu_test_run_sh_usage fn;
    esp32_qemu_test_run_sh --> esp32_qemu_test_run_sh_usage
    esp32_qemu_test_run_sh_image_exists["image_exists"]
    class esp32_qemu_test_run_sh_image_exists fn;
    esp32_qemu_test_run_sh --> esp32_qemu_test_run_sh_image_exists
    esp32_qemu_test_run_sh_ensure_image["ensure_image"]
    class esp32_qemu_test_run_sh_ensure_image fn;
    esp32_qemu_test_run_sh --> esp32_qemu_test_run_sh_ensure_image
    esp32_qemu_test_run_sh_do_build["do_build"]
    class esp32_qemu_test_run_sh_do_build fn;
    esp32_qemu_test_run_sh --> esp32_qemu_test_run_sh_do_build
    esp32_qemu_test_run_sh_do_run["do_run"]
    class esp32_qemu_test_run_sh_do_run fn;
    esp32_qemu_test_run_sh --> esp32_qemu_test_run_sh_do_run
    FatFs_R0_16_documents_res_app1_c["app1.c (c)"]
    class FatFs_R0_16_documents_res_app1_c mod;
    FatFs_R0_16_documents_res_app1_c_open_append["open_append"]
    class FatFs_R0_16_documents_res_app1_c_open_append fn;
    FatFs_R0_16_documents_res_app1_c --> FatFs_R0_16_documents_res_app1_c_open_append
    FatFs_R0_16_documents_res_app1_c_main["main"]
    class FatFs_R0_16_documents_res_app1_c_main fn;
    FatFs_R0_16_documents_res_app1_c --> FatFs_R0_16_documents_res_app1_c_main
    FatFs_R0_16_documents_res_app3_c["app3.c (c)"]
    class FatFs_R0_16_documents_res_app3_c mod;
    FatFs_R0_16_documents_res_app3_c_allocate_contiguous_clusters["allocate_contiguous_clusters"]
    class FatFs_R0_16_documents_res_app3_c_allocate_contiguous_clusters fn;
    FatFs_R0_16_documents_res_app3_c --> FatFs_R0_16_documents_res_app3_c_allocate_contiguous_clusters
    FatFs_R0_16_documents_res_app3_c_main["main"]
    class FatFs_R0_16_documents_res_app3_c_main fn;
    FatFs_R0_16_documents_res_app3_c --> FatFs_R0_16_documents_res_app3_c_main
    FatFs_R0_16_documents_res_app2_c["app2.c (c)"]
    class FatFs_R0_16_documents_res_app2_c mod;
    FatFs_R0_16_documents_res_app2_c_delete_node["delete_node"]
    class FatFs_R0_16_documents_res_app2_c_delete_node fn;
    FatFs_R0_16_documents_res_app2_c --> FatFs_R0_16_documents_res_app2_c_delete_node
    FatFs_R0_16_documents_res_app5_c["app5.c (c)"]
    class FatFs_R0_16_documents_res_app5_c mod;
    FatFs_R0_16_documents_res_app5_c_test_contiguous_file["test_contiguous_file"]
    class FatFs_R0_16_documents_res_app5_c_test_contiguous_file fn;
    FatFs_R0_16_documents_res_app5_c --> FatFs_R0_16_documents_res_app5_c_test_contiguous_file
    esp32_qemu_test_scripts_run_test_sh["run_test.sh (sh)"]
    class esp32_qemu_test_scripts_run_test_sh mod;
    ext_stdio_h["stdio.h"]
    class ext_stdio_h ext;
    FatFs_R0_16_documents_res_app4_c -.->|imports| ext_stdio_h
    ext_string_h["string.h"]
    class ext_string_h ext;
    FatFs_R0_16_documents_res_app4_c -.->|imports| ext_string_h
    ext_ff_h["ff.h"]
    class ext_ff_h ext;
    FatFs_R0_16_documents_res_app4_c -.->|imports| ext_ff_h
    ext_diskio_h["diskio.h"]
    class ext_diskio_h ext;
    FatFs_R0_16_documents_res_app4_c -.->|imports| ext_diskio_h
    FatFs_R0_16_documents_res_app6_c -.->|imports| ext_stdio_h
    ext_systimer_h["systimer.h"]
    class ext_systimer_h ext;
    FatFs_R0_16_documents_res_app6_c -.->|imports| ext_systimer_h
    FatFs_R0_16_documents_res_app6_c -.->|imports| ext_diskio_h
    FatFs_R0_16_documents_res_app6_c -.->|imports| ext_ff_h
    FatFs_R0_16_source_diskio_c -.->|imports| ext_ff_h
    FatFs_R0_16_source_diskio_c -.->|imports| ext_diskio_h
    ext_platform_h["platform.h"]
    class ext_platform_h ext;
    FatFs_R0_16_source_diskio_c -.->|imports| ext_platform_h
    ext_storage_h["storage.h"]
    class ext_storage_h ext;
    FatFs_R0_16_source_diskio_c -.->|imports| ext_storage_h
    FatFs_R0_16_source_ff_c -.->|imports| ext_string_h
    FatFs_R0_16_source_ff_c -.->|imports| ext_ff_h
    FatFs_R0_16_source_ff_c -.->|imports| ext_diskio_h
    ext_stdarg_h["stdarg.h"]
    class ext_stdarg_h ext;
    FatFs_R0_16_source_ff_c -.->|imports| ext_stdarg_h
    ext_math_h["math.h"]
    class ext_math_h ext;
    FatFs_R0_16_source_ff_c -.->|imports| ext_math_h
    ext_ffconf_h["ffconf.h"]
    class ext_ffconf_h ext;
    FatFs_R0_16_source_ff_h -.->|imports| ext_ffconf_h
    ext_windows_h["windows.h"]
    class ext_windows_h ext;
    FatFs_R0_16_source_ff_h -.->|imports| ext_windows_h
    ext_float_h["float.h"]
    class ext_float_h ext;
    FatFs_R0_16_source_ff_h -.->|imports| ext_float_h
    ext_stdint_h["stdint.h"]
    class ext_stdint_h ext;
    FatFs_R0_16_source_ff_h -.->|imports| ext_stdint_h
    FatFs_R0_16_source_ffsystem_c -.->|imports| ext_ff_h
    ext_stdlib_h["stdlib.h"]
    class ext_stdlib_h ext;
    FatFs_R0_16_source_ffsystem_c -.->|imports| ext_stdlib_h
    FatFs_R0_16_source_ffsystem_c -.->|imports| ext_windows_h
    ext_itron_h["itron.h"]
    class ext_itron_h ext;
    FatFs_R0_16_source_ffsystem_c -.->|imports| ext_itron_h
    ext_kernel_h["kernel.h"]
    class ext_kernel_h ext;
    FatFs_R0_16_source_ffsystem_c -.->|imports| ext_kernel_h
    ext_includes_h["includes.h"]
    class ext_includes_h ext;
    FatFs_R0_16_source_ffsystem_c -.->|imports| ext_includes_h
    ext_FreeRTOS_h["FreeRTOS.h"]
    class ext_FreeRTOS_h ext;
    FatFs_R0_16_source_ffsystem_c -.->|imports| ext_FreeRTOS_h
    ext_semphr_h["semphr.h"]
    class ext_semphr_h ext;
    FatFs_R0_16_source_ffsystem_c -.->|imports| ext_semphr_h
    ext_cmsis_os_h["cmsis_os.h"]
    class ext_cmsis_os_h ext;
    FatFs_R0_16_source_ffsystem_c -.->|imports| ext_cmsis_os_h
    FatFs_R0_16_source_ffunicode_c -.->|imports| ext_ff_h
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_stdio_h
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_string_h
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_stdlib_h
    ext_sys_stat_h["stat.h"]
    class ext_sys_stat_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_sys_stat_h
    ext_errno_h["errno.h"]
    class ext_errno_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_errno_h
    ext_inttypes_h["inttypes.h"]
    class ext_inttypes_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_inttypes_h
    ext_fcntl_h["fcntl.h"]
    class ext_fcntl_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_fcntl_h
    ext_unistd_h["unistd.h"]
    class ext_unistd_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_unistd_h
    ext_dirent_h["dirent.h"]
    class ext_dirent_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_dirent_h
    ext_stdbool_h["stdbool.h"]
    class ext_stdbool_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_stdbool_h
    ext_esp_log_h["esp_log.h"]
    class ext_esp_log_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_esp_log_h
    ext_esp_system_h["esp_system.h"]
    class ext_esp_system_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_esp_system_h
    ext_esp_idf_version_h["esp_idf_version.h"]
    class ext_esp_idf_version_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_esp_idf_version_h
    ext_esp_vfs_fat_h["esp_vfs_fat.h"]
    class ext_esp_vfs_fat_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_esp_vfs_fat_h
    ext_esp_partition_h["esp_partition.h"]
    class ext_esp_partition_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_esp_partition_h
    ext_freertos_FreeRTOS_h["FreeRTOS.h"]
    class ext_freertos_FreeRTOS_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_freertos_FreeRTOS_h
    ext_freertos_task_h["task.h"]
    class ext_freertos_task_h ext;
    esp32_qemu_test_app_main_fatfs_vuln_test_c -.->|imports| ext_freertos_task_h
    ext_struct["struct"]
    class ext_struct ext;
    esp32_qemu_test_scripts_gen_exploit_image_py -.->|imports| ext_struct
    ext_subprocess["subprocess"]
    class ext_subprocess ext;
    esp32_qemu_test_scripts_gen_exploit_image_py -.->|imports| ext_subprocess
    ext_sys["sys"]
    class ext_sys ext;
    esp32_qemu_test_scripts_gen_exploit_image_py -.->|imports| ext_sys
    ext_os["os"]
    class ext_os ext;
    esp32_qemu_test_scripts_gen_exploit_image_py -.->|imports| ext_os
    ext_tempfile["tempfile"]
    class ext_tempfile ext;
    esp32_qemu_test_scripts_gen_exploit_image_py -.->|imports| ext_tempfile
    ext_encoding_binary["binary"]
    class ext_encoding_binary ext;
    fuzzer_fat_image_go -.->|imports| ext_encoding_binary
    ext_math_rand["rand"]
    class ext_math_rand ext;
    fuzzer_fat_image_go -.->|imports| ext_math_rand
    fuzzer_main_go -.->|imports| ext_encoding_binary
    ext_flag["flag"]
    class ext_flag ext;
    fuzzer_main_go -.->|imports| ext_flag
    ext_fmt["fmt"]
    class ext_fmt ext;
    fuzzer_main_go -.->|imports| ext_fmt
    fuzzer_main_go -.->|imports| ext_math_rand
    fuzzer_main_go -.->|imports| ext_os
    ext_path_filepath["filepath"]
    class ext_path_filepath ext;
    fuzzer_main_go -.->|imports| ext_path_filepath
    ext_testing["testing"]
    class ext_testing ext;
    fuzzer_main_go -.->|imports| ext_testing
    harness_diskio_ramdisk_c -.->|imports| ext_ff_h
    harness_diskio_ramdisk_c -.->|imports| ext_diskio_h
    ext_diskio_ramdisk_h["diskio_ramdisk.h"]
    class ext_diskio_ramdisk_h ext;
    harness_diskio_ramdisk_c -.->|imports| ext_diskio_ramdisk_h
    harness_diskio_ramdisk_c -.->|imports| ext_string_h
    harness_diskio_ramdisk_h -.->|imports| ext_ff_h
    harness_diskio_ramdisk_h -.->|imports| ext_stdint_h
    harness_exploit_disks_c -.->|imports| ext_stdio_h
    harness_exploit_disks_c -.->|imports| ext_stdlib_h
    harness_exploit_disks_c -.->|imports| ext_string_h
    harness_exploit_disks_c -.->|imports| ext_stdint_h
    ext_stddef_h["stddef.h"]
    class ext_stddef_h ext;
    harness_exploit_disks_c -.->|imports| ext_stddef_h
    harness_exploit_disks_c -.->|imports| ext_sys_stat_h
    harness_exploit_disks_c -.->|imports| ext_errno_h
    harness_exploit_disks_c -.->|imports| ext_ff_h
    harness_exploit_disks_c -.->|imports| ext_diskio_h
    harness_exploit_disks_c -.->|imports| ext_diskio_ramdisk_h
    harness_ffunicode_stub_c -.->|imports| ext_ff_h
    harness_libfuzzer_harness_c -.->|imports| ext_stdint_h
    harness_libfuzzer_harness_c -.->|imports| ext_stddef_h
    harness_libfuzzer_harness_c -.->|imports| ext_string_h
    harness_libfuzzer_harness_c -.->|imports| ext_stdlib_h
    harness_libfuzzer_harness_c -.->|imports| ext_ff_h
    harness_libfuzzer_harness_c -.->|imports| ext_diskio_h
    harness_libfuzzer_harness_c -.->|imports| ext_diskio_ramdisk_h
    harness_libfuzzer_harness_c -.->|imports| ext_stdio_h
    harness_rce_demo_c -.->|imports| ext_stdio_h
    harness_rce_demo_c -.->|imports| ext_stdlib_h
    harness_rce_demo_c -.->|imports| ext_string_h
    harness_rce_demo_c -.->|imports| ext_stdint_h
    harness_rce_demo_c -.->|imports| ext_stddef_h
    ext_assert_h["assert.h"]
    class ext_assert_h ext;
    harness_rce_demo_c -.->|imports| ext_assert_h
    harness_rce_demo_c -.->|imports| ext_inttypes_h
    harness_rce_demo_c -.->|imports| ext_ff_h
    harness_rce_demo_c -.->|imports| ext_diskio_h
    harness_rce_demo_c -.->|imports| ext_diskio_ramdisk_h
    harness_test_harness_c -.->|imports| ext_stdio_h
    harness_test_harness_c -.->|imports| ext_stdlib_h
    harness_test_harness_c -.->|imports| ext_string_h
    harness_test_harness_c -.->|imports| ext_stdint_h
    harness_test_harness_c -.->|imports| ext_assert_h
    harness_test_harness_c -.->|imports| ext_ff_h
    harness_test_harness_c -.->|imports| ext_diskio_h
    harness_test_harness_c -.->|imports| ext_diskio_ramdisk_h
```

---

## Architecture Reference

### C (17 files)

#### `app1.c`
**Path:** `FatFs-R0.16/documents/res/app1.c`

**Functions:**
- `open_append` (line 5) `FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* p...` - *-----------------------------------------------------------/ Open or create a file in append mode (This function was sperseded by FA_OPEN_APPEND fl...*
- `main` (line 23) `int main (void)`

#### `app2.c`
**Path:** `FatFs-R0.16/documents/res/app2.c`

**Functions:**
- `delete_node` (line 7) `FRESULT delete_node (
    TCHAR* path,    /* Path name buffer with the sub-directory to delete */...` - *-----------------------------------------------------------/ Delete a sub-directory even if it contains any file ----------------------------------...*

#### `app3.c`
**Path:** `FatFs-R0.16/documents/res/app3.c`

**Functions:**
- `allocate_contiguous_clusters` (line 18) `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:error or not contig...`
- `main` (line 76) `int main (void)`

#### `app4.c`
**Path:** `FatFs-R0.16/documents/res/app4.c`

**Functions:**
- `pn` (line 11) `static DWORD pn (       /* Pseudo random number generator */
    DWORD pns   /* 0:Initialize, !0:...` - *---------------------------------------------------------------------/ Low level disk I/O module function checker                            / ----...*
- `test_diskio` (line 34) `int test_diskio (
    BYTE pdrv,      /* Physical drive number to be checked (all data on the dri...`
- `main` (line 296) `int main (int argc, char* argv[])`

#### `app5.c`
**Path:** `FatFs-R0.16/documents/res/app5.c`

**Functions:**
- `test_contiguous_file` (line 4) `FRESULT test_contiguous_file (
    FIL* fp,    /* [IN]  Open file object to be checked */
    int...` - *---------------------------------------------------------------------/ Test if the file is contiguous                                        / /---...*

#### `app6.c`
**Path:** `FatFs-R0.16/documents/res/app6.c`

**Functions:**
- `test_raw_speed` (line 9) `int test_raw_speed (
    BYTE pdrv,      /* Physical drive number */
    DWORD lba,      /* Start...` - *include <stdio.h> include <systimer.h> include "diskio.h" include "ff.h"*

#### `diskio.c`
**Path:** `FatFs-R0.16/source/diskio.c`

**Functions:**
- `disk_status` (line 26) `DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)` - */* Example: Declarations of the platform and disk functions in the project #include "platform.h" #include "storage.h" /* Example: Mapping of physic...*
- `disk_initialize` (line 64) `DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)` - *result = USB_disk_status(); translate the reslut code here return stat; } return STA_NOINIT; } /*--------------------------------------------------...*
- `disk_read` (line 102) `DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		...` - *result = USB_disk_initialize(); translate the reslut code here return stat; } return STA_NOINIT; } /*----------------------------------------------...*
- `disk_write` (line 152) `DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE ...` - *if FF_FS_READONLY == 0*
- `disk_ioctl` (line 201) `DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code *...` - *translate the reslut code here return res; } return RES_PARERR; } #endif /*----------------------------------------------------------------------- ...*

**Macros:**
- `DEV_FLASH` (line 18)
- `DEV_MMC` (line 19)
- `DEV_USB` (line 20)

#### `ff.c`
**Path:** `FatFs-R0.16/source/ff.c`

**Functions:**
- `dbc_1st` (line 693) `static int dbc_1st (BYTE c)` - *ptr++ = (BYTE)val; val >>= 8; ptr++ = (BYTE)val; val >>= 8; ptr++ = (BYTE)val; } #endif #endif	/* !FF_FS_READONLY /*-------------------------------...*
- `dbc_2nd` (line 713) `static int dbc_2nd (BYTE c)` - *} #elif FF_CODE_PAGE >= 900	/* DBCS fixed code page if (c >= DbcTbl[0]) { if (c <= DbcTbl[1]) return 1; if (c >= DbcTbl[2] && c <= DbcTbl[3]) retur...*
- `tchar2uni` (line 737) `static DWORD tchar2uni (	/* Returns a character in UTF-16 encoding (>=0x10000 on surrogate pair, ...` - *if (c <= DbcTbl[5]) return 1; if (c >= DbcTbl[6] && c <= DbcTbl[7]) return 1; if (c >= DbcTbl[8] && c <= DbcTbl[9]) return 1; } #else						/* SBCS ...*
- `put_utf` (line 806) `static UINT put_utf (	/* Returns number of encoding units written (0:buffer overflow or wrong enc...` - *} if (wc != 0) { wc = ff_oem2uni(wc, CODEPAGE);	/* ANSI/OEM ==> Unicode if (wc == 0) return 0xFFFFFFFF;	/* Invalid code? } uc = wc; #endif *str = p...*
- `lock_volume` (line 895) `static int lock_volume (	/* 1:Ok, 0:timeout */
	FATFS* fs,				/* Filesystem object to lock */
	in...` - *return 2; } if (wc == 0 || szb < 1) return 0;	/* Invalid character or buffer overflow? *buf++ = (TCHAR)wc;					/* Store the character return 1; #en...*
- `unlock_volume` (line 920) `static void unlock_volume (
	FATFS* fs,		/* Filesystem object */
	FRESULT res		/* Result code to ...`
- `chk_share` (line 946) `static FRESULT chk_share (	/* Check if the file can be accessed */
	DIR* dp,		/* Directory object...` - *} #endif ff_mutex_give(fs->ldrv);	/* Unlock the volume } } #endif #if FF_FS_LOCK /*----------------------------------------------------------------...*
- `inc_share` (line 981) `static UINT inc_share (	/* Increment object open counter and returns its index (0:Internal error)...`
- `dec_share` (line 1012) `static FRESULT dec_share (	/* Decrement object open counter */
	UINT i			/* Semaphore index (1..)...`
- `clear_share` (line 1036) `static void clear_share (	/* Clear all lock entries of the volume */
	FATFS* fs
)`
- `sync_window` (line 1057) `static FRESULT sync_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs			/* Filesystem object...` - *for (i = 0; i < FF_FS_LOCK; i++) { if (Files[i].fs == fs) Files[i].fs = 0; } } #endif	/* FF_FS_LOCK /*---------------------------------------------...*
- `move_window` (line 1077) `static FRESULT move_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs,		/* Filesystem object...` - *endif*
- `sync_fs` (line 1109) `static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs		/* Filesystem object */
)` - *} fs->winsect = sect; } } return res; } #if !FF_FS_READONLY /*----------------------------------------------------------------------- /* Synchroniz...*
- `clst2sect` (line 1158) `static LBA_t clst2sect (	/* !=0:Sector number, 0:Failed (invalid cluster#) */
	FATFS* fs,		/* Fil...` - */* Make sure that no pending write process in the lower layer if (disk_ioctl(fs->pdrv, CTRL_SYNC, 0) != RES_OK) res = FR_DISK_ERR; } return res; } ...*
- `get_fat` (line 1175) `static DWORD get_fat (		/* 0xFFFFFFFF:Disk error, 1:Internal error, 2..0x7FFFFFFF:Cluster status ...` - *DWORD clst		/* Cluster# to be converted ) { clst -= 2;		/* Cluster number is origin from 2 if (clst >= fs->n_fatent - 2) return 0;		/* Is it invali...*
- `put_fat` (line 1253) `static FRESULT put_fat (	/* FR_OK(0):succeeded, !=0:error */
	FATFS* fs,		/* Corresponding filesy...` - *val = 1;	/* Internal error } } return val; } #if !FF_FS_READONLY /*----------------------------------------------------------------------- /* FAT a...*
- `find_bitmap` (line 1318) `static DWORD find_bitmap (	/* 0:Not found, 2..:Cluster block found, 0xFFFFFFFF:Disk error */
	FAT...` - *#endif /* !FF_FS_READONLY #if FF_FS_EXFAT && !FF_FS_READONLY /*----------------------------------------------------------------------- /* exFAT: Ac...*
- `change_bitmap` (line 1358) `static FRESULT change_bitmap (
	FATFS* fs,	/* Filesystem object */
	DWORD clst,	/* Cluster number...` - *} else { scl = val; ctr = 0;		/* Encountered a cluster in-use, restart to scan } if (val == clst) return 0;	/* All cluster scanned? } while (bm != ...*
- `fill_first_frag` (line 1394) `static FRESULT fill_first_frag (
	FFOBJID* obj	/* Pointer to the corresponding object */
)` - *fs->win[i] ^= bm;	/* Flip the bit fs->wflag = 1; if (--ncl == 0) return FR_OK;	/* All bits processed? } while (bm <<= 1);		/* Next bit bm = 1; } wh...*
- `fill_last_frag` (line 1417) `static FRESULT fill_last_frag (
	FFOBJID* obj,	/* Pointer to the corresponding object */
	DWORD l...` - *if (obj->stat == 3) {	/* Has the object been changed 'fragmented' in this session? for (cl = obj->sclust, n = obj->n_cont; n; cl++, n--) {	/* Creat...*
- `remove_chain` (line 1443) `static FRESULT remove_chain (	/* FR_OK(0):succeeded, !=0:error */
	FFOBJID* obj,		/* Correspondin...` - *if (res != FR_OK) return res; obj->n_frag--; } return FR_OK; } #endif	/* FF_FS_EXFAT && !FF_FS_READONLY #if !FF_FS_READONLY /*---------------------...*
- `create_chain` (line 1538) `static DWORD create_chain (	/* 0:No free cluster, 1:Internal error, 0xFFFFFFFF:Disk error, >=2:Ne...` - *} } } } #endif return FR_OK; } /*----------------------------------------------------------------------- /* FAT handling - Stretch a chain or Creat...*
- `clmt_clust` (line 1643) `static DWORD clmt_clust (	/* <2:Error, >=2:Cluster number */
	FIL* fp,		/* Pointer to the file ob...` - *} return ncl;		/* Return new cluster number or error status } #endif /* !FF_FS_READONLY #if FF_USE_FASTSEEK /*-------------------------------------...*
- `dir_clear` (line 1675) `static FRESULT dir_clear (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS *fs,		/* Filesystem object *...` - *if !FF_FS_READONLY*
- `dir_sdi` (line 1713) `static FRESULT dir_sdi (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,		/* Pointer to directory o...` - *{ ibuf = fs->win; szb = 1;	/* Use window buffer (many single-sector writes may take a time) for (n = 0; n < fs->csize && disk_write(fs->pdrv, ibuf,...*
- `dir_next` (line 1761) `static FRESULT dir_next (	/* FR_OK(0):succeeded, FR_NO_FILE:End of table, FR_DENIED:Could not str...` - *dp->clust = clst;					/* Current cluster# if (dp->sect == 0) return FR_INT_ERR; dp->sect += ofs / SS(fs);			/* Sector# of the directory entry dp->d...*
- `dir_alloc` (line 1822) `static FRESULT dir_alloc (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,				/* Pointer to the dir...` - *} dp->dptr = ofs;						/* Current entry dp->dir = fs->win + ofs % SS(fs);	/* Pointer to the entry in the win[] return FR_OK; } #if !FF_FS_READONLY ...*
- `ld_clust` (line 1864) `static DWORD ld_clust (	/* Returns the top cluster value of the SFN entry */
	FATFS* fs,			/* Poi...` - *} if (res == FR_NO_FILE) res = FR_DENIED;	/* No directory entry to allocate return res; } #endif	/* !FF_FS_READONLY /*-----------------------------...*
- `st_clust` (line 1882) `static void st_clust (
	FATFS* fs,	/* Pointer to the fs object */
	BYTE* dir,	/* Pointer to the k...` - *if !FF_FS_READONLY*
- `cmp_lfn` (line 1901) `static int cmp_lfn (		/* 1:matched, 0:not matched */
	const WCHAR* lfnbuf,	/* Pointer to the LFN ...` - *{ st_16(dir + DIR_FstClusLO, (WORD)cl); if (fs->fs_type == FS_FAT32) { st_16(dir + DIR_FstClusHI, (WORD)(cl >> 16)); } } #endif #if FF_USE_LFN /*--...*
- `pick_lfn` (line 1937) `static int pick_lfn (	/* 1:succeeded, 0:buffer overflow or invalid LFN entry */
	WCHAR* lfnbuf,		...` - *if (chr != 0xFFFF) return 0;	/* Check filler } } if ((dir[LDIR_Ord] & LLEF) && pchr && lfnbuf[ni]) return 0;	/* Last name segment matched but diffe...*
- `put_lfn` (line 1975) `static void put_lfn (
	const WCHAR* lfn,	/* Pointer to the LFN */
	BYTE* dir,			/* Pointer to the...` - *if (dir[LDIR_Ord] & LLEF && pchr != 0) {	/* Put terminator if it is the last LFN part and not terminated if (ni >= FF_MAX_LFN + 1) return 0;		/* Bu...*
- `gen_numname` (line 2012) `static void gen_numname (
	BYTE* dst,			/* Pointer to the buffer to store numbered SFN */
	const ...` - *} while (++di < 13); if (chr == 0xFFFF || !lfn[ni]) ord |= LLEF;	/* Last LFN part is the start of an enrty set dir[LDIR_Ord] = ord;			/* Set order ...*
- `sum_sfn` (line 2069) `static BYTE sum_sfn (
	const BYTE* dir		/* Pointer to the SFN entry */
)` - *} } do {	/* Append the suffix dst[j++] = (i < 8) ? ns[i++] : ' '; } while (j < 8); } #endif	/* FF_USE_LFN && !FF_FS_READONLY #if FF_USE_LFN /*-----...*
- `xdir_sum` (line 2091) `static WORD xdir_sum (	/* Get checksum of the directoly entry block */
	const BYTE* dir		/* Direc...` - *do { sum = (sum >> 1) + (sum << 7) + *dir++; } while (--n); return sum; } #endif	/* FF_USE_LFN #if FF_FS_EXFAT /*----------------------------------...*
- `xname_sum` (line 2110) `static WORD xname_sum (	/* Get check sum (to be used as hash) of the file name */
	const WCHAR* n...`
- `xsum32` (line 2131) `static DWORD xsum32 (	/* Returns 32-bit checksum */
	BYTE  dat,			/* Byte to be calculated (byte-...` - *if !FF_FS_READONLY && FF_USE_MKFS*
- `load_xdir` (line 2146) `static FRESULT load_xdir (	/* FR_INT_ERR: invalid entry block */
	DIR* dp					/* Reading director...` - *BYTE  dat,			/* Byte to be calculated (byte-by-byte processing) DWORD sum			/* Previous sum value ) { sum = ((sum & 1) ? 0x80000000 : 0) + (sum >> ...*
- `init_alloc_info` (line 2198) `static void init_alloc_info (
	FFOBJID* dobj,	/* Object allocation information to be initialized ...` - *} while ((i += SZDIRE) < sz_ent); /* Sanity check (do it for only accessible object) if (i <= MAXDIRB(FF_MAX_LFN)) { if (xdir_sum(dirb) != ld_16(di...*
- `load_obj_xdir` (line 2224) `static FRESULT load_obj_xdir (
	DIR* dp,			/* Blank directory object to be used to access contain...` - *dobj->c_ofs = sdir->blk_ofs; } dobj->sclust = ld_32(fs->dirbuf + XDIR_FstClus);	/* Start cluster dobj->objsize = ld_64(fs->dirbuf + XDIR_FileSize);...*
- `store_xdir` (line 2253) `static FRESULT store_xdir (
	DIR* dp				/* Pointer to the directory object */
)` - *res = dir_sdi(dp, dp->blk_ofs);	/* Goto object's entry block if (res == FR_OK) { res = load_xdir(dp);		/* Load the object's entry block } return re...*
- `create_xdir` (line 2287) `static void create_xdir (
	BYTE* dirb,			/* Pointer to the directory entry block buffer */
	const...` - *dp->obj.fs->wflag = 1; if (--nent == 0) break;	/* All done? dirb += SZDIRE; res = dir_next(dp, 0);	/* Next entry } return (res == FR_OK || res == F...*
- `dir_read` (line 2333) `static FRESULT dir_read (
	DIR* dp,		/* Pointer to the directory object */
	int vol			/* Filtered...` - *define DIR_READ_FILE(dp) dir_read(dp, 0) define DIR_READ_LABEL(dp) dir_read(dp, 1)*
- `dir_find` (line 2411) `static FRESULT dir_find (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp					/* Pointer to the dire...` - *if (res != FR_OK) break; } if (res != FR_OK) dp->sect = 0;		/* Terminate the read operation on error or EOT return res; } #endif	/* FF_FS_MINIMIZE ...*
- `dir_register` (line 2493) `static FRESULT dir_register (	/* FR_OK:succeeded, FR_DENIED:no free entry or too many SFN collisi...` - *#endif res = dir_next(dp, 0);	/* Next entry } while (res == FR_OK); return res; } #if !FF_FS_READONLY /*-------------------------------------------...*
- `dir_remove` (line 2606) `static FRESULT dir_remove (	/* FR_OK:Succeeded, FR_DISK_ERR:A disk error */
	DIR* dp					/* Direc...` - *} } return res; } #endif /* !FF_FS_READONLY #if !FF_FS_READONLY && FF_FS_MINIMIZE == 0 /*----------------------------------------------------------...*
- `get_fileinfo` (line 2652) `static void get_fileinfo (
	DIR* dp,			/* Pointer to the directory object */
	FILINFO* fno		/* Po...` - *} #endif return res; } #endif /* !FF_FS_READONLY && FF_FS_MINIMIZE == 0 #if FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >= 2 /*-----------------------------...*
- `get_achar` (line 2805) `static DWORD get_achar (	/* Get a character and advance ptr */
	const TCHAR** ptr		/* Pointer to ...` - *fno->crdate = ld_16(dp->dir + DIR_CrtTime + 2);	/* Created date #endif } #endif /* FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >= 2 #if FF_USE_FIND && FF_FS...*
- `pattern_match` (line 2836) `static int pattern_match (	/* 0:mismatched, 1:matched */
	const TCHAR* pat,	/* Matching pattern *...`
- `create_name` (line 2891) `static FRESULT create_name (	/* FR_OK: successful, FR_INVALID_NAME: could not create */
	DIR* dp,...` - *} get_achar(&nam);			/* nam++ } while (skip && nchr);		/* Retry until end of name if infinite search is specified return 0; } #endif /* FF_USE_FIND...*
- `follow_path` (line 3100) `static FRESULT follow_path (	/* FR_OK(0): successful, !=0: error code */
	DIR* dp,					/* Directo...` - *if (sfn[0] == DDEM) sfn[0] = RDDEM;	/* If the first character collides with DDEM, replace it with RDDEM sfn[NSFLAG] = (c <= ' ' || p[si] <= ' ') ? ...*
- `get_ldnumber` (line 3219) `static int get_ldnumber (	/* Returns logical drive number (-1:invalid drive number or null pointe...` - *dp->obj.sclust = ld_clust(fs, fs->win + dp->dptr % SS(fs));	/* Open next directory } } } return res; } /*------------------------------------------...*
- `crc32` (line 3296) `static DWORD crc32 (	/* Returns next CRC value */
	DWORD crc,			/* Current CRC value */
	BYTE d		...` - *return 0;				/* Default drive is 0 #endif } /*----------------------------------------------------------------------- /* GPT support functions /*--...*
- `test_gpt_header` (line 3314) `static int test_gpt_header (	/* 0:Invalid, 1:Valid */
	const BYTE* gpth			/* Pointer to the GPT h...` - *) { BYTE b; for (b = 1; b; b <<= 1) { crc ^= (d & b) ? 1 : 0; crc = (crc & 1) ? crc >> 1 ^ 0xEDB88320 : crc >> 1; } return crc; } /* Check validity...*
- `make_rand` (line 3339) `static DWORD make_rand (	/* Returns a seed value for next */
	DWORD seed,				/* Seed value */
	BY...` - *if (hlen < 92 || hlen > FF_MIN_SS) return 0; for (i = 0, bcc = 0xFFFFFFFF; i < hlen; i++) {			/* Check header BCC bcc = crc32(bcc, i - GPTH_Bcc < 4...*
- `check_fs` (line 3366) `static UINT check_fs (	/* 0:FAT/FAT32 VBR, 1:exFAT VBR, 2:Not FAT and valid BS, 3:Not FAT and inv...` - *} while (--n); return seed; } #endif #endif /*----------------------------------------------------------------------- /* Load a sector and check if...*
- `find_volume` (line 3406) `static UINT find_volume (	/* Returns BS status found in the hosting drive */
	FATFS* fs,		/* File...` - *&& ld_16(fs->win + BPB_RsvdSecCnt) != 0		/* Properness of number of reserved sectors (MNBZ) && (UINT)fs->win[BPB_NumFATs] - 1 <= 1		/* Properness o...*
- `mount_volume` (line 3460) `static FRESULT mount_volume (	/* FR_OK(0): successful, !=0: an error occurred */
	const TCHAR** p...` - *} i = part ? part - 1 : 0;		/* Table index to find first do {							/* Find an FAT volume fmt = mbr_pt[i] ? check_fs(fs, mbr_pt[i]) : 3;	/* Check i...*
- `validate` (line 3694) `static FRESULT validate (	/* Returns FR_OK or FR_INVALID_OBJECT */
	FFOBJID* obj,			/* Pointer to...` - *#if FF_FS_LOCK				/* Clear file lock semaphores clear_share(fs); #endif return FR_OK; } /*---------------------------------------------------------...*
- `f_open` (line 3798) `FRESULT f_open (
	FIL* fp,			/* Pointer to the blank file object */
	const TCHAR* path,	/* Pointe...` - *} if (opt == 0) return FR_OK;	/* Do not mount now, it will be mounted in subsequent file functions res = mount_volume(&path, &fs, 0);	/* Force moun...*
- `f_read` (line 3995) `FRESULT f_read (
	FIL* fp, 	/* Open file to be read */
	void* buff,	/* Data buffer to store the r...` - *FREE_NAMEBUFF(); } if (res != FR_OK) fp->obj.fs = 0;	/* Invalidate file object on error LEAVE_FF(fs, res); } /*------------------------------------...*
- `f_write` (line 4096) `FRESULT f_write (
	FIL* fp,			/* Open file to be written */
	const void* buff,	/* Data to be writ...` - *memcpy(rbuff, fp->buf + fp->fptr % SS(fs), rcnt);	/* Extract partial sector #endif } LEAVE_FF(fs, FR_OK); } #if !FF_FS_READONLY /*-----------------...*
- `f_sync` (line 4217) `FRESULT f_sync (
	FIL* fp		/* Open file to be synced */
)` - *#endif } fp->flag |= FA_MODIFIED;				/* Set file change flag LEAVE_FF(fs, FR_OK); } /*-------------------------------------------------------------...*
- `f_close` (line 4298) `FRESULT f_close (
	FIL* fp		/* Open file to be closed */
)` - *} } LEAVE_FF(fs, res); } #endif /* !FF_FS_READONLY /*----------------------------------------------------------------------- /* API: Close File /*-...*
- `f_chdrive` (line 4334) `FRESULT f_chdrive (
	const TCHAR* path		/* Drive number to set */
)` - *unlock_volume(fs, FR_OK);		/* Unlock volume #endif } } return res; } #if FF_FS_RPATH >= 1 /*-------------------------------------------------------...*
- `f_chdir` (line 4356) `FRESULT f_chdir (
	const TCHAR* path	/* Pointer to the directory path */
)` - */* Get logical drive number vol = get_ldnumber(&path); if (vol < 0) return FR_INVALID_DRIVE; CurrVol = (BYTE)vol;	/* Set it as current volume retur...*
- `f_getcwd` (line 4418) `FRESULT f_getcwd (
	TCHAR* buff,	/* Pointer to the buffer to store the current direcotry path */
...` - *} #endif } LEAVE_FF(fs, res); } #if FF_FS_RPATH >= 2 /*----------------------------------------------------------------------- /* API: Get Curent D...*
- `f_lseek` (line 4554) `FRESULT f_lseek (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t ofs		/* File pointer from ...` - *} LEAVE_FF(fs, res); } #endif /* FF_FS_RPATH >= 2 #endif /* FF_FS_RPATH >= 1 #if FF_FS_MINIMIZE <= 2 /*--------------------------------------------...*
- `f_opendir` (line 4718) `FRESULT f_opendir (
	DIR* dp,			/* Pointer to directory object to create */
	const TCHAR* path	/*...` - *#endif fp->sect = nsect; } } LEAVE_FF(fs, res); } #if FF_FS_MINIMIZE <= 1 /*-----------------------------------------------------------------------...*
- `f_closedir` (line 4780) `FRESULT f_closedir (
	DIR *dp		/* Pointer to the directory object to be closed */
)` - *FREE_NAMEBUFF(); if (res == FR_NO_FILE) res = FR_NO_PATH; } if (res != FR_OK) dp->obj.fs = 0;		/* Invalidate the directory object if function faile...*
- `f_readdir` (line 4810) `FRESULT f_readdir (
	DIR* dp,			/* Pointer to the open directory object */
	FILINFO* fno		/* Poin...` - *#endif #if FF_FS_REENTRANT unlock_volume(fs, FR_OK);	/* Unlock volume #endif } return res; } /*----------------------------------------------------...*
- `f_findnext` (line 4849) `FRESULT f_findnext (
	DIR* dp,		/* Pointer to the open directory object */
	FILINFO* fno	/* Point...` - *FREE_NAMEBUFF(); } } if (fno && res != FR_OK) fno->fname[0] = 0;	/* Clear the file information if any error occured LEAVE_FF(fs, res); } #if FF_USE...*
- `f_findfirst` (line 4874) `FRESULT f_findfirst (
	DIR* dp,				/* Pointer to the blank directory object */
	FILINFO* fno,			/...` - *if (res != FR_OK || !fno || !fno->fname[0]) break;	/* Terminate if any error or end of directory if (pattern_match(dp->pat, fno->fname, 0, FIND_REC...*
- `f_stat` (line 4901) `FRESULT f_stat (
	const TCHAR* path,	/* Pointer to the file path */
	FILINFO* fno		/* Pointer to ...` - *if (res == FR_OK) { res = f_findnext(dp, fno);	/* Find the first item } return res; } #endif	/* FF_USE_FIND #if FF_FS_MINIMIZE == 0 /*-------------...*
- `f_getfree` (line 4938) `FRESULT f_getfree (
	const TCHAR* path,	/* Logical drive number */
	DWORD* nclst,		/* Pointer to ...` - *} FREE_NAMEBUFF(); } if (fno && res != FR_OK) fno->fname[0] = 0;	/* Invalidate the file information if an error occured LEAVE_FF(dj.obj.fs, res); }...*
- `f_truncate` (line 5035) `FRESULT f_truncate (
	FIL* fp		/* Pointer to the file object */
)` - *fs->fsi_flag |= 1;		/* FAT32/exfAT : Allocation information is to be updated } } } LEAVE_FF(fs, res); } /*-----------------------------------------...*
- `f_unlink` (line 5086) `FRESULT f_unlink (
	const TCHAR* path		/* Pointer to the file or directory path */
)` - *} #endif if (res != FR_OK) ABORT(fs, res); } LEAVE_FF(fs, res); } /*----------------------------------------------------------------------- /* API:...*
- `f_mkdir` (line 5175) `FRESULT f_mkdir (
	const TCHAR* path		/* Pointer to the directory path */
)` - *if (res == FR_OK) res = sync_fs(fs); } FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } /*------------------------------------------------------------------...*
- `f_rename` (line 5260) `FRESULT f_rename (
	const TCHAR* path_old,	/* Pointer to the object name to be renamed */
	const ...` - *} } FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } /*----------------------------------------------------------------------- /* API: Rename a File/Directo...*
- `f_chmod` (line 5384) `FRESULT f_chmod (
	const TCHAR* path,	/* Pointer to the file path */
	BYTE attr,			/* Attribute b...` - *LEAVE_FF(fs, res); } #endif /* !FF_FS_READONLY #endif /* FF_FS_MINIMIZE == 0 #endif /* FF_FS_MINIMIZE <= 1 #endif /* FF_FS_MINIMIZE <= 2 #if FF_USE...*
- `f_utime` (line 5433) `FRESULT f_utime (
	const TCHAR* path,	/* Pointer to the file/directory name */
	const FILINFO* fn...` - *} } FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } /*----------------------------------------------------------------------- /* API: Change Timestamp /*--...*
- `f_getlabel` (line 5501) `FRESULT f_getlabel (
	const TCHAR* path,	/* Logical drive number */
	TCHAR* label,		/* Buffer to ...` - *FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } #endif	/* FF_USE_CHMOD && !FF_FS_READONLY #if FF_USE_LABEL /*----------------------------------------------...*
- `f_setlabel` (line 5602) `FRESULT f_setlabel (
	const TCHAR* label	/* Volume label to set with heading logical drive number...` - *} *vsn = di ? ld_32(fs->win + di) : 0;	/* Get VSN in the VBR } } LEAVE_FF(fs, res); } #if !FF_FS_READONLY /*---------------------------------------...*
- `f_expand` (line 5725) `FRESULT f_expand (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t fsz,	/* File size to be e...` - *} LEAVE_FF(fs, res); } #endif /* !FF_FS_READONLY #endif /* FF_USE_LABEL #if FF_USE_EXPAND && !FF_FS_READONLY /*------------------------------------...*
- `f_forward` (line 5821) `FRESULT f_forward (
	FIL* fp, 						/* Pointer to the file object */
	UINT (*func)(const BYTE*,UI...` - *} } LEAVE_FF(fs, res); } #endif /* FF_USE_EXPAND && !FF_FS_READONLY #if FF_USE_FORWARD /*----------------------------------------------------------...*
- `create_partition` (line 5899) `static FRESULT create_partition (
	BYTE drv,			/* Physical drive number */
	const LBA_t plst[],	/...` - *#if !FF_FS_READONLY && FF_USE_MKFS /*----------------------------------------------------------------------- /* API: Create FAT/exFAT volume (with ...*
- `f_mkfs` (line 6040) `FRESULT f_mkfs (
	const TCHAR* path,		/* Logical drive number */
	const MKFS_PARM* opt,	/* Format...`
- `f_fdisk` (line 6547) `FRESULT f_fdisk (
	BYTE pdrv,			/* Physical drive number */
	const LBA_t ptbl[],	/* Pointer to th...` - *} if (disk_ioctl(pdrv, CTRL_SYNC, 0) != RES_OK) LEAVE_MKFS(FR_DISK_ERR); LEAVE_MKFS(FR_OK); } #if FF_MULTI_PARTITION /*----------------------------...*
- `f_gets` (line 6587) `TCHAR* f_gets (
	TCHAR* buff,	/* Pointer to the buffer to store read string */
	int len,		/* Size...` - *#endif /* FF_MULTI_PARTITION #endif /* !FF_FS_READONLY && FF_USE_MKFS #if FF_USE_STRFUNC #if FF_USE_LFN && FF_LFN_UNICODE && (FF_STRF_ENCODE < 0 ||...*
- `putc_bfd` (line 6739) `static void putc_bfd (putbuff* pb, TCHAR c)` - *typedef struct { FIL *fp;		/* Pointer to the writing file int idx, nchr;	/* Write index of buf[] (-1:error), number of written encoding units #if F...*
- `putc_flush` (line 6870) `static int putc_flush (putbuff* pb)` - *#else							/* ANSI/OEM input (without re-encoding) pb->buf[i++] = (BYTE)c; #endif if (i >= (int)(sizeof pb->buf) - 4) {	/* Write buffered characte...*
- `putc_init` (line 6885) `static void putc_init (putbuff* pb, FIL* fp)` - *static int putc_flush (putbuff* pb) { UINT nw; if (   pb->idx >= 0	/* Flush buffered characters to the file && f_write(pb->fp, pb->buf, (UINT)pb->i...*
- `f_putc` (line 6891) `int f_putc (
	TCHAR c,	/* A character to be output */
	FIL* fp		/* Pointer to the file object */
)`
- `f_puts` (line 6913) `int f_puts (
	const TCHAR* str,	/* Pointer to the string to be output */
	FIL* fp				/* Pointer t...` - *putbuff pb; putc_init(&pb, fp); putc_bfd(&pb, c);	/* Put the character return putc_flush(&pb); } /*------------------------------------------------...*
- `ftoa` (line 6978) `static void ftoa (
	char* buf,	/* Buffer to output the floating point string */
	double val,	/* V...`
- `f_printf` (line 7054) `int f_printf (
	FIL* fp,			/* Pointer to the file object */
	const TCHAR* fmt,	/* Pointer to the ...` - *buf++ = (char)('0' + exp / 10); buf++ = (char)('0' + exp % 10); } } } if (er) {	/* Error condition if (sign) *buf++ = sign;		/* Add sign if needed ...*
- `f_setcp` (line 7225) `FRESULT f_setcp (
	WORD cp		/* Value to be set as active code page */
)` - *va_end(arp); return putc_flush(&pb); } #endif /* !FF_FS_READONLY #endif /* FF_USE_STRFUNC #if FF_CODE_PAGE == 0 /*---------------------------------...*

**Macros:**
- `MAX_DIR` (line 38)
- `MAX_DIR_EX` (line 39)
- `MAX_FAT12` (line 40)
- `MAX_FAT16` (line 41)
- `MAX_FAT32` (line 42)
- `MAX_EXFAT` (line 43)
- `IsUpper` (line 47)
- `IsLower` (line 48)
- `IsDigit` (line 49)
- `IsSeparator` (line 50)
- `IsTerminator` (line 51)
- `IsSurrogate` (line 52)
- `IsSurrogateH` (line 53)
- `IsSurrogateL` (line 54)
- `FA_SEEKEND` (line 58)
- `FA_MODIFIED` (line 59)
- `FA_DIRTY` (line 60)
- `AM_VOL` (line 64)
- `AM_LFN` (line 65)
- `AM_MASK` (line 66)
- `AM_MASKX` (line 67)
- `NSFLAG` (line 71)
- `NS_LOSS` (line 72)
- `NS_LFN` (line 73)
- `NS_LAST` (line 74)
- `NS_BODY` (line 75)
- `NS_EXT` (line 76)
- `NS_DOT` (line 77)
- `NS_NOLFN` (line 78)
- `NS_NONAME` (line 79)
- `ET_BITMAP` (line 83)
- `ET_UPCASE` (line 84)
- `ET_VLABEL` (line 85)
- `ET_FILEDIR` (line 86)
- `ET_STREAM` (line 87)
- `ET_FILENAME` (line 88)
- `BS_JmpBoot` (line 93)
- `BS_OEMName` (line 95)
- `BPB_BytsPerSec` (line 96)
- `BPB_SecPerClus` (line 97)
- `BPB_RsvdSecCnt` (line 98)
- `BPB_NumFATs` (line 99)
- `BPB_RootEntCnt` (line 100)
- `BPB_TotSec16` (line 101)
- `BPB_Media` (line 102)
- `BPB_FATSz16` (line 103)
- `BPB_SecPerTrk` (line 104)
- `BPB_NumHeads` (line 105)
- `BPB_HiddSec` (line 106)
- `BPB_TotSec32` (line 107)
- `BS_DrvNum` (line 108)
- `BS_NTres` (line 109)
- `BS_BootSig` (line 110)
- `BS_VolID` (line 111)
- `BS_VolLab` (line 112)
- `BS_FilSysType` (line 113)
- `BS_BootCode` (line 114)
- `BS_55AA` (line 115)
- `BPB_FATSz32` (line 116)
- `BPB_ExtFlags32` (line 118)
- `BPB_FSVer32` (line 119)
- `BPB_RootClus32` (line 120)
- `BPB_FSInfo32` (line 121)
- `BPB_BkBootSec32` (line 122)
- `BS_DrvNum32` (line 123)
- `BS_NTres32` (line 124)
- `BS_BootSig32` (line 125)
- `BS_VolID32` (line 126)
- `BS_VolLab32` (line 127)
- `BS_FilSysType32` (line 128)
- `BS_BootCode32` (line 129)
- `BPB_ZeroedEx` (line 130)
- `BPB_VolOfsEx` (line 132)
- `BPB_TotSecEx` (line 133)
- `BPB_FatOfsEx` (line 134)
- `BPB_FatSzEx` (line 135)
- `BPB_DataOfsEx` (line 136)
- `BPB_NumClusEx` (line 137)
- `BPB_RootClusEx` (line 138)
- `BPB_VolIDEx` (line 139)
- `BPB_FSVerEx` (line 140)
- `BPB_VolFlagEx` (line 141)
- `BPB_BytsPerSecEx` (line 142)
- `BPB_SecPerClusEx` (line 143)
- `BPB_NumFATsEx` (line 144)
- `BPB_DrvNumEx` (line 145)
- `BPB_PercInUseEx` (line 146)
- `BPB_RsvdEx` (line 147)
- `BS_BootCodeEx` (line 148)
- `DIR_Name` (line 149)
- `DIR_Attr` (line 151)
- `DIR_NTres` (line 152)
- `DIR_CrtTime10` (line 153)
- `DIR_CrtTime` (line 154)
- `DIR_LstAccDate` (line 155)
- `DIR_FstClusHI` (line 156)
- `DIR_ModTime` (line 157)
- `DIR_FstClusLO` (line 158)
- `DIR_FileSize` (line 159)
- `LDIR_Ord` (line 160)
- `LDIR_Attr` (line 161)
- `LDIR_Type` (line 162)
- `LDIR_Chksum` (line 163)
- `LDIR_FstClusLO` (line 164)
- `XDIR_Type` (line 165)
- `XDIR_NumLabel` (line 166)
- `XDIR_Label` (line 167)
- `XDIR_CaseSum` (line 168)
- `XDIR_NumSec` (line 169)
- `XDIR_SetSum` (line 170)
- `XDIR_Attr` (line 171)
- `XDIR_CrtTime` (line 172)
- `XDIR_ModTime` (line 173)
- `XDIR_AccTime` (line 174)
- `XDIR_CrtTime10` (line 175)
- `XDIR_ModTime10` (line 176)
- `XDIR_CrtTZ` (line 177)
- `XDIR_ModTZ` (line 178)
- `XDIR_AccTZ` (line 179)
- `XDIR_GenFlags` (line 180)
- `XDIR_NumName` (line 181)
- `XDIR_NameHash` (line 182)
- `XDIR_ValidFileSize` (line 183)
- `XDIR_FstClus` (line 184)
- `XDIR_FileSize` (line 185)
- `SZDIRE` (line 186)
- `DDEM` (line 188)
- `RDDEM` (line 189)
- `LLEF` (line 190)
- `FSI_LeadSig` (line 191)
- `FSI_StrucSig` (line 193)
- `FSI_Free_Count` (line 194)
- `FSI_Nxt_Free` (line 195)
- `FSI_TrailSig` (line 196)
- `MBR_Table` (line 197)
- `SZ_PTE` (line 199)
- `PTE_Boot` (line 200)
- `PTE_StHead` (line 201)
- `PTE_StSec` (line 202)
- `PTE_StCyl` (line 203)
- `PTE_System` (line 204)
- `PTE_EdHead` (line 205)
- `PTE_EdSec` (line 206)
- `PTE_EdCyl` (line 207)
- `PTE_StLba` (line 208)
- `PTE_SizLba` (line 209)
- `GPTH_Sign` (line 210)
- `GPTH_Rev` (line 212)
- `GPTH_Size` (line 213)
- `GPTH_Bcc` (line 214)
- `GPTH_CurLba` (line 215)
- `GPTH_BakLba` (line 216)
- `GPTH_FstLba` (line 217)
- `GPTH_LstLba` (line 218)
- `GPTH_DskGuid` (line 219)
- `GPTH_PtOfs` (line 220)
- `GPTH_PtNum` (line 221)
- `GPTH_PteSize` (line 222)
- `GPTH_PtBcc` (line 223)
- `SZ_GPTE` (line 224)
- `GPTE_PtGuid` (line 225)
- `GPTE_UpGuid` (line 226)
- `GPTE_FstLba` (line 227)
- `GPTE_LstLba` (line 228)
- `GPTE_Flags` (line 229)
- `GPTE_Name` (line 230)
- `ABORT` (line 234)
- `LEAVE_FF` (line 242)
- `LEAVE_FF` (line 244)
- `LD2PD` (line 250)
- `LD2PT` (line 251)
- `LD2PD` (line 253)
- `LD2PT` (line 254)
- `SS` (line 263)
- `SS` (line 265)
- `GET_FATTIME` (line 274)
- `GET_FATTIME` (line 276)
- `TBL_CT437` (line 295)
- `TBL_CT720` (line 303)
- `TBL_CT737` (line 311)
- `TBL_CT771` (line 319)
- `TBL_CT775` (line 327)
- `TBL_CT850` (line 335)
- `TBL_CT852` (line 343)
- `TBL_CT855` (line 351)
- `TBL_CT857` (line 359)
- `TBL_CT860` (line 367)
- `TBL_CT861` (line 375)
- `TBL_CT862` (line 383)
- `TBL_CT863` (line 391)
- `TBL_CT864` (line 399)
- `TBL_CT865` (line 407)
- `TBL_CT866` (line 415)
- `TBL_CT869` (line 423)
- `TBL_DC932` (line 435)
- `TBL_DC936` (line 436)
- `TBL_DC949` (line 437)
- `TBL_DC950` (line 438)
- `MERGE_2STR` (line 442)
- `MKCVTBL` (line 443)
- `DEF_NAMEBUFF` (line 502)
- `INIT_NAMEBUFF` (line 503)
- `FREE_NAMEBUFF` (line 504)
- `LEAVE_MKFS` (line 505)
- `MAXDIRB` (line 518)
- `DEF_NAMEBUFF` (line 525)
- `INIT_NAMEBUFF` (line 526)
- `FREE_NAMEBUFF` (line 527)
- `LEAVE_MKFS` (line 528)
- `DEF_NAMEBUFF` (line 532)
- `INIT_NAMEBUFF` (line 533)
- `FREE_NAMEBUFF` (line 534)
- `DEF_NAMEBUFF` (line 536)
- `INIT_NAMEBUFF` (line 537)
- `FREE_NAMEBUFF` (line 538)
- `LEAVE_MKFS` (line 540)
- `DEF_NAMEBUFF` (line 544)
- `INIT_NAMEBUFF` (line 545)
- `FREE_NAMEBUFF` (line 546)
- `DEF_NAMEBUFF` (line 548)
- `INIT_NAMEBUFF` (line 549)
- `FREE_NAMEBUFF` (line 550)
- `LEAVE_MKFS` (line 552)
- `MAX_MALLOC` (line 553)
- `CODEPAGE` (line 568)
- `CODEPAGE` (line 596)
- `CODEPAGE` (line 600)
- `DIR_READ_FILE` (line 2330)
- `DIR_READ_LABEL` (line 2332)
- `FIND_RECURS` (line 2803)
- `N_SEC_TRACK` (line 5892)
- `GPT_ALIGN` (line 5894)
- `GPT_ITEMS` (line 5895)
- `SZ_PUTC_BUF` (line 6716)
- `SZ_NUM_BUF` (line 6717)

#### `ffsystem.c`
**Path:** `FatFs-R0.16/source/ffsystem.c`

**Functions:**
- `ff_memalloc` (line 15) `void* ff_memalloc (	/* Returns pointer to the allocated memory block (null if not enough core) */...` - */*------------------------------------------------------------------------ /* A Sample Code of User Provided OS Dependent Functions for FatFs /*---...*
- `ff_memfree` (line 23) `void ff_memfree (
	void* mblock	/* Pointer to the memory block to free (no effect if null) */
)`
- `ff_mutex_create` (line 78) `int ff_mutex_create (	/* Returns 1:Function succeeded or 0:Could not create the mutex */
	int vol...` - *This function is called in f_mount function to create a new mutex or semaphore for the volume. When a 0 is returned, the f_mount function fails wit...*
- `ff_mutex_delete` (line 119) `void ff_mutex_delete (	/* Returns 1:Function succeeded or 0:Could not delete due to an error */
	...` - *This function is called in f_mount function to delete a mutex or semaphore of the volume created with ff_mutex_create function.*
- `ff_mutex_take` (line 151) `int ff_mutex_take (	/* Returns 1:Succeeded or 0:Timeout */
	int vol			/* Mutex ID: Volume mutex (...` - *This function is called on enter file functions to lock the volume. When a 0 is returned, the file function fails with FR_TIMEOUT.*
- `ff_mutex_give` (line 184) `void ff_mutex_give (
	int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (...` - *This function is called on leave file functions to unlock the volume.*

**Macros:**
- `OS_TYPE` (line 41)

#### `ffunicode.c`
**Path:** `FatFs-R0.16/source/ffunicode.c`

**Functions:**
- `ff_uni2oem` (line 15222) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...` - *if FF_CODE_PAGE != 0 && FF_CODE_PAGE < 900*
- `ff_oem2uni` (line 15243) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- `ff_uni2oem` (line 15275) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...` - *if FF_CODE_PAGE >= 900*
- `ff_oem2uni` (line 15309) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- `ff_uni2oem` (line 15356) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- `ff_oem2uni` (line 15408) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- `ff_wtoupper` (line 15463) `DWORD ff_wtoupper (	/* Returns up-converted code point */
	DWORD uni		/* Unicode code point to be...` - *if (n != 0) c = p[i * 2 + 1]; } } } return c; } #endif /*------------------------------------------------------------------------ /* Unicode Up-cas...*

**Macros:**
- `MERGE2` (line 29)
- `CVTBL` (line 31)

#### `fatfs_vuln_test.c`
**Path:** `esp32-qemu-test/app/main/fatfs_vuln_test.c`

**Functions:**
- `__attribute__` (line 54) `__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const struct dirent *entry)`
- `legitimate_update_callback` (line 66) `static void legitimate_update_callback(void)`
- `run_lfn_copy_probe` (line 71) `static bool run_lfn_copy_probe(void)`
- `get_firmware_size` (line 120) `static long get_firmware_size(void)`
- `read_firmware_image` (line 133) `static bool read_firmware_image(int fd, size_t firmware_size)`
- `run_update_flow` (line 151) `static void run_update_flow(long attacker_fsize)`
- `app_main` (line 170) `void app_main(void)`

**Macros:**
- `MOUNT_POINT` (line 22)
- `FW_HDR_SIZE` (line 24)
- `OTA_READ_SLAB_SIZE` (line 27)
- `CANARY_CRC` (line 42)
- `CANARY_VERSION` (line 44)
- `LFN_GUARD_VALUE` (line 45)

**Structs:**
- `ota_update_ctx` (line 29)
- `ota_exec_region` (line 36)
- `lfn_overflow_probe` (line 48)

#### `diskio_ramdisk.c`
**Path:** `harness/diskio_ramdisk.c`

**Functions:**
- `ramdisk_reset_stats` (line 34) `void ramdisk_reset_stats(void)`
- `ramdisk_load` (line 46) `void ramdisk_load(const BYTE *image, UINT size)` - *Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.  Any sector beyond the image is left zeroed.  Call this before * mountin...*
- `ramdisk_eject` (line 55) `void ramdisk_eject(void)` - *Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.  Any sector beyond the image is left zeroed.  Call this before * mountin...*
- `disk_status` (line 61) `DSTATUS disk_status(BYTE pdrv)` - *{ UINT bytes = (size < sizeof(ramdisk)) ? size : (UINT)sizeof(ramdisk); memset(ramdisk, 0, sizeof(ramdisk)); memcpy(ramdisk, image, bytes); disk_st...*
- `disk_initialize` (line 67) `DSTATUS disk_initialize(BYTE pdrv)`
- `disk_read` (line 74) `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)`
- `disk_write` (line 94) `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)`
- `disk_ioctl` (line 113) `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)`
- `get_fattime` (line 136) `DWORD get_fattime(void)` - *return RES_OK; case GET_SECTOR_SIZE: (WORD *)buff = RAMDISK_SECTOR_SIZE; return RES_OK; case GET_BLOCK_SIZE: (DWORD *)buff = 1; return RES_OK; defa...*

#### `exploit_disks.c`
**Path:** `harness/exploit_disks.c`

**Functions:**
- `exploit_disks` (line 49) `*   make exploit_disks            (see Makefile target)
 *
 * Expected output:
 *   Generating 14...`
- `st32le` (line 99) `static inline void st32le(uint8_t *p, uint32_t v)`
- `st64le` (line 102) `static inline void st64le(uint8_t *p, uint64_t v)`
- `save_image` (line 116) `static int save_image(const char *name, const uint8_t *buf, size_t sz)` - *-------------------------------------------------------------------------- I/O helpers *-----------------------------------------------------------...*
- `load_ramdisk` (line 128) `static void load_ramdisk(const uint8_t *buf, size_t sz)`
- `bug1_write_vbr` (line 156) `static void bug1_write_vbr(uint8_t *disk)` - *clst2sect(2) = 6 → attacker plants root-dir entry at sector 6 clst2sect(4) = 8 → attacker plants file payload at sector 8  The filesystem believes ...*
- `bug1_fill_payload` (line 227) `static void bug1_fill_payload(uint8_t *disk,
                               const uint8_t *payloa...` - *bug1_fill_payload  —  write exploit bytes into sector 8 (cluster 4).  The first payload_sz bytes of sector 8 are filled with payload_buf. If payloa...*
- `bug1_build` (line 241) `static uint8_t *bug1_build(uint32_t file_size,
                            const uint8_t *payload...` - *Allocate and build a complete CVE-2026-6682 image for a given file_size / payload. * Returns pointer to RAMDISK_SIZE_BYTES-sized buffer (caller mus...*
- `bug1_verify` (line 255) `static int bug1_verify(uint8_t *disk, const char *filename)` - *static uint8_t *bug1_build(uint32_t file_size, const uint8_t *payload, uint32_t payload_sz, uint8_t fill, const char *fname8, const char *ext3) { u...*
- `Payload` (line 293) `*   Payload (sector 8): placeholder address 0xDEADBEEFCAFEBABE
 *   Simulates: embedded OTA reade...`
- `gen_bug1_espidf` (line 317) `static void gen_bug1_espidf(void)` - *-------------------------------------------------------------------------- CVE-2026-6682  image 2:  ESP-IDF stat/malloc/read pattern ESP-IDF vfs_fa...*
- `gen_bug1_stm32` (line 338) `static void gen_bug1_stm32(void)` - *-------------------------------------------------------------------------- CVE-2026-6682  image 3:  STM32 CubeMX firmware-update buffer overflow ST...*
- `gen_bug1_keystone3` (line 359) `static void gen_bug1_keystone3(void)` - *-------------------------------------------------------------------------- CVE-2026-6682  image 4:  Keystone3 hardware wallet OTA overflow Keystone...*
- `gen_bug1_ardupilot` (line 382) `static void gen_bug1_ardupilot(void)` - *-------------------------------------------------------------------------- CVE-2026-6682  image 5:  ArduPilot / Mbed OS (R0.14b) log buffer overflo...*
- `gen_bug2_exfat` (line 455) `static void gen_bug2_exfat(void)`
- `MicroPython` (line 498) `*                            MicroPython (if the port enables FF_LBA64)
 *
 * R0.16 fix:  test_gp...`
- `chain` (line 576) `*   An application writes 64 bytes to the END of cluster chain (fp->sect = X,
 *   FA_DIRTY set),...`
- `bug4_set_fat16_entry` (line 637) `static void bug4_set_fat16_entry(uint8_t *disk, uint16_t cluster, uint16_t value)`
- `gen_bug4_fragmented` (line 647) `static void gen_bug4_fragmented(void)`
- `Zephyr` (line 836) `*                     Zephyr (R0.16), ArduPilot (R0.14b),
 *                     RIOT-OS (R0.15),...`
- `bug6_verify_overflow` (line 892) `static int bug6_verify_overflow(uint8_t *disk, const char *imgname,
                             ...`
- `gen_bug6_stm32` (line 932) `static void gen_bug6_stm32(void)`
- `gen_bug6_zephyr` (line 947) `static void gen_bug6_zephyr(void)`
- `layout` (line 989) `*
 * Directory layout (FAT16):
 *   Entries in order: LFN entries (N × 32 bytes) then 8.3 SFN ent...`
- `bug7_build` (line 1006) `static void bug7_build(uint8_t *disk, int lfn_len, uint16_t dirent_name_size)`
- `bug7_verify` (line 1059) `static int bug7_verify(uint8_t *disk, const char *imgname, int expected_lfn_len)`
- `gen_bug7_max255` (line 1095) `static void gen_bug7_max255(void)`
- `gen_bug7_zephyr` (line 1111) `static void gen_bug7_zephyr(void)`
- `main` (line 1273) `int main(void)` - *=========================================================================== main *=================================================================...*

**Macros:**
- `IMG_DIR` (line 94)
- `INFO` (line 107)
- `PASS` (line 109)
- `FAIL` (line 110)
- `SKIP` (line 111)
- `B4_BYTES_PER_SEC` (line 592)
- `B4_SEC_PER_CLUS` (line 593)
- `B4_RESERVED_SECS` (line 594)
- `B4_N_FATS` (line 595)
- `B4_ROOT_ENTRIES` (line 596)
- `B4_FAT_SIZE_SECS` (line 597)
- `B4_TOT_SECS` (line 598)
- `B4_ROOT_DIR_SECS` (line 599)
- `B4_SYS_SECS` (line 600)
- `B4_FAT_OFFSET_SECS` (line 601)
- `B4_ROOT_OFFSET_SECS` (line 602)
- `B4_DATA_OFFSET_SECS` (line 603)
- `B4_CLUS2SEC` (line 604)
- `B5_SEC_PER_CLUS` (line 738)
- `B5_CLUS2SEC` (line 739)
- `B5_SECRET` (line 740)
- `B5_WRITE_SIZE` (line 741)

#### `ffunicode_stub.c`
**Path:** `harness/ffunicode_stub.c`

**Functions:**
- `ff_uni2oem` (line 5) `* ff_uni2oem() and ff_wtoupper() which normally come from ffunicode.c.
 * These stubs are suffici...`
- `ff_uni2oem` (line 17) `WCHAR ff_uni2oem(DWORD uni, WORD cp)`
- `ff_wtoupper` (line 25) `DWORD ff_wtoupper(DWORD chr)` - *WCHAR ff_oem2uni(WCHAR oem, WORD cp) { (void)cp; return (oem < 0x80) ? oem : 0; } WCHAR ff_uni2oem(DWORD uni, WORD cp) { (void)cp; return (uni < 0x...*

#### `libfuzzer_harness.c`
**Path:** `harness/libfuzzer_harness.c`

**Functions:**
- `Usage` (line 9) `*
 * Usage (libFuzzer):
 *   ./fuzz_fatfs -max_len=2097152 corpus/
 *
 * Usage (AFL++):
 *   afl-...`
- `main` (line 128) `int main(int argc, char **argv)` - *f_close(&fp); break; /* process at most one file per fuzz iteration } f_closedir(&dj); } done: f_mount(NULL, "0:", 0); return 0; } /* ── AFL++ shim...*

#### `rce_demo.c`
**Path:** `harness/rce_demo.c`

**Functions:**
- `Build` (line 45) `*
 * Build (without sanitisers, without stack protector — lets the overflow
 * reach the function...`
- `st32le` (line 73) `static inline void st32le(uint8_t *p, uint32_t v)`
- `st64le` (line 76) `static inline void st64le(uint8_t *p, uint64_t v)`
- `safe_update_complete` (line 123) `static void safe_update_complete(void)`
- `__attribute__` (line 131) `__attribute__((noinline))
static void rce_win(void)`
- `vulnerable_ota_check` (line 155) `static void vulnerable_ota_check(void)` - *This function is the VICTIM.  It contains no deliberately insecure code except for one extremely common mistake:  f_read(&fp, ctx.fw_header, finfo....*
- `build_exploit_image` (line 232) `static void build_exploit_image(uint8_t *disk, size_t disk_bytes,
                               ...` - *→ database = sector 6   (inside FAT area [4, ∞)) → clst2sect(2) = 6  (root dir reads from sector 6) → clst2sect(4) = 8  (FIRMWARE.BIN data reads fr...*
- `save_image` (line 348) `static int save_image(const char *path, const uint8_t *disk, size_t sz)` - *printf("             version    [%u..%u)  = 0x00010000\n", FW_HDR_SIZE + 4, FW_HDR_SIZE + 8); printf("             on_apply   [%u..%u)  = %p  (rce_...*
- `load_image` (line 363) `static int load_image(const char *path)` - *{ FILE *f = fopen(path, "wb"); if (!f) { perror(path); return -1; } size_t written = fwrite(disk, 1, sz, f); fclose(f); if (written != sz) { fprint...*
- `main` (line 380) `int main(void)` - *=========================================================================== main *=================================================================...*

**Macros:**
- `FW_HDR_SIZE` (line 95)

**Structs:**
- `ota_ctx` (line 98)

#### `test_harness.c`
**Path:** `harness/test_harness.c`

**Functions:**
- `buffers` (line 36) `*         buffers (e.g. char path[16]) and unchecked string copies
 *         (sprintf, strcat) o...`
- `st32le` (line 65) `static inline void st32le(BYTE *p, uint32_t v)`
- `st64le` (line 70) `static inline void st64le(BYTE *p, uint64_t v)`
- `rce_proof_of_execution` (line 119) `static void rce_proof_of_execution(void)`
- `build_fat32_bug1` (line 120) `static void build_fat32_bug1(BYTE *disk, size_t disk_bytes)`
- `MCUs` (line 261) `*    common on embedded MCUs (STM32, RP2040, ESP32, …).  The resulting call
 *    invokes rce_pro...`
- `test_bug1_rce_exploit` (line 338) `static int test_bug1_rce_exploit(void)`
- `build_gpt_image` (line 459) `static void build_gpt_image(BYTE *disk, size_t disk_bytes, uint32_t n_ent)` - *Minimal protective-MBR + GPT header disk image builder.  Only as much structure as find_volume needs to enter the loop: - MBR: partition 0 type = 0...*
- `releases` (line 509) `*
 * Historical note: older FatFs releases (before test_gpt_header was
 * introduced) had no such...`
- `test_bug4_stale_cache_skip` (line 601) `static int test_bug4_stale_cache_skip(void)` - *through a range that includes X. 4. The bulk disk_read() returns stale (pre-write) data for sector X; the cache copy that would patch it is skipped...*
- `layout` (line 693) `*
 * Disk layout (FAT16, 4 sectors/cluster):
 *   Sectors  0           VBR
 *   Sectors  1-4     ...`
- `build_fat16_base` (line 725) `static void build_fat16_base(BYTE *disk, size_t disk_bytes)`
- `__attribute__` (line 763) `__attribute__((unused))
static void fat16_set_chain(BYTE *disk, uint16_t cluster, uint16_t next)`
- `test_bug5_infoleak_lseek` (line 781) `static int test_bug5_infoleak_lseek(void)` - *Write exactly one full cluster so fp->buf is never used (direct sector writes) and the cluster-2 content is fully under our control (0xBB). Seek ON...*
- `pass` (line 927) `*      or pass (sizeof_label - di) instead of the hard-coded 4.
 *===============================...`
- `test_bug6_getlabel_exfat_overflow` (line 998) `static int test_bug6_getlabel_exfat_overflow(void)`
- `sfn_checksum_b7` (line 1090) `static BYTE sfn_checksum_b7(const BYTE sfn[11])` - *char fname[13];                     // SFN-sized buffer strcpy(fname, fno.fname);           // overflows if LFN > 12 chars  Disk trigger: any FAT12...*
- `build_fat16_with_lfn` (line 1104) `static void build_fat16_with_lfn(BYTE *disk, size_t disk_bytes)` - *static BYTE sfn_checksum_b7(const BYTE sfn[11]) { BYTE sum = 0; for (int i = 0; i < 11; i++) sum = (BYTE)(((sum & 1) ? 0x80 : 0) + (sum >> 1) + sfn...*
- `test_bug7_lfn_path_overflow` (line 1156) `static int test_bug7_lfn_path_overflow(void)`
- `main` (line 1257) `int main(void)` - *=========================================================================== main *=================================================================...*

**Macros:**
- `RESULT` (line 77)
- `INFO` (line 83)
- `F16_BYTES_PER_SEC` (line 703)
- `F16_SEC_PER_CLUS` (line 704)
- `F16_RESERVED_SECS` (line 705)
- `F16_N_FATS` (line 706)
- `F16_ROOT_ENTRIES` (line 707)
- `F16_FAT_SIZE_SECS` (line 708)
- `F16_TOT_SECS` (line 709)
- `F16_ROOT_DIR_SECS` (line 710)
- `F16_SYS_SECS` (line 712)
- `F16_FAT_OFFSET_SECS` (line 714)
- `F16_ROOT_OFFSET_SECS` (line 715)
- `F16_DATA_OFFSET_SECS` (line 716)
- `F16_CLUS2SEC` (line 717)
- `SECRET_PATTERN` (line 774)
- `WRITE_SIZE` (line 779)
- `LSEEK_TARGET` (line 780)
- `B7_LFN_LEN` (line 1102)
- `B7_FILE_SIZE` (line 1103)

### GO (2 files)

#### `fat_image.go`
**Path:** `fuzzer/fat_image.go`

**Functions:**
- `le16` (line 19) `func le16(`
- `le32` (line 20) `func le32(`
- `le64` (line 21) `func le64(`
- `newDisk` (line 29) `func newDisk(` - *newDisk returns a zeroed byte slice of min(totalSectors, maxDiskSectors) * 512 bytes.  Callers should still write the intended TotalSectors value i...*
- `DefaultFAT16Config` (line 52) `func DefaultFAT16Config(` - *DefaultFAT16Config returns a valid, minimal 1 MiB FAT16 configuration.*
- `BuildFAT16` (line 65) `func BuildFAT16(` - *BuildFAT16 constructs a minimal FAT16 disk image from the given config.*
- `FAT16DataSector` (line 107) `func FAT16DataSector(` - *FAT16DataSector returns the first sector of cluster c (c >= 2).*
- `DefaultFAT32Config` (line 131) `func DefaultFAT32Config(` - *DefaultFAT32Config returns a valid FAT32 configuration sized to fit in the test harness RAM disk (4096 sectors = 2 MiB).  BPB_TotSec32 still reflec...*
- `BuildFAT32` (line 144) `func BuildFAT32(` - *BuildFAT32 constructs a minimal FAT32 disk image.*
- `BuildGPTImage` (line 214) `func BuildGPTImage(` - *BuildGPTImage constructs a disk image with a GPT-protective MBR, a GPT header at sector 1 declaring nPartitions entries, and nMSBDP entries whose P...*
- `BuildExFATImage` (line 262) `func BuildExFATImage(` - *BuildExFATImage creates a minimal exFAT VBR. When numClusters == 0, n_fatent becomes 2 in FatFs, which is the divide-by-zero precondition in sync_f...*
- `MutateFAT32BPB` (line 303) `func MutateFAT32BPB(` - *MutateFAT32BPB returns a copy of a FAT32 disk image with the named BPB field set to value.*
- `RandomMutate` (line 324) `func RandomMutate(` - *RandomMutate applies a single random byte-flip to a copy of disk.*
- `BuildExFATWithLargeLabel` (line 354) `func BuildExFATWithLargeLabel(` - *volume-label directory entry has XDIR_NumLabel set to numLabel.  The exFAT spec limits XDIR_NumLabel to 11 characters.  FatFs reads it as a raw BYT...*
- `sfnChecksum` (line 430) `func sfnChecksum(` - *sfnChecksum computes the LFN checksum of an 11-byte FAT SFN (matching sum_sfn() in ff.c).*
- `BuildFAT16WithLFNFile` (line 451) `func BuildFAT16WithLFNFile(` - *BuildFAT16WithLFNFile returns a FAT16 image identical to BuildFAT16(cfg) but with one file in the root directory whose LFN is lfnName.  len(lfnName...*

**Structs:**
- `FAT16Config` (line 41) - *FAT16Config holds parameters for a minimal FAT16 volume.*
- `FAT32Config` (line 118) - *FAT32Config holds parameters for a minimal FAT32 volume.*

#### `main.go`
**Path:** `fuzzer/main.go`

**Functions:**
- `main` (line 51) `func main(`
- `buildAllSeeds` (line 76) `func buildAllSeeds(`
- `BuildFAT12Minimal` (line 290) `func BuildFAT12Minimal(`
- `FuzzFAT32BPB` (line 343) `func FuzzFAT32BPB(` - *FuzzFAT32BPB mutates individual BPB fields and checks structural consistency of the generated images.  The corpus is seeded with known interesting ...*
- `FuzzGPTNEnt` (line 398) `func FuzzGPTNEnt(` - *FuzzGPTNEnt mutates GPTH_PtNum to explore the loop bound behaviour.*
- `FuzzExFATNumLabel` (line 449) `func FuzzExFATNumLabel(` - *FuzzExFATNumLabel mutates the XDIR_NumLabel byte in an exFAT volume label entry and checks structural invariants of the generated image.*
- `FuzzFAT16LFNLength` (line 507) `func FuzzFAT16LFNLength(` - *FuzzFAT16LFNLength mutates the length of the LFN filename.*

### H (5 files)

#### `diskio.h`
**Path:** `FatFs-R0.16/source/diskio.h`

**Macros:**
- `_DISKIO_DEFINED` (line 6)
- `STA_NOINIT` (line 37)
- `STA_NODISK` (line 39)
- `STA_PROTECT` (line 40)
- `CTRL_SYNC` (line 46)
- `GET_SECTOR_COUNT` (line 47)
- `GET_SECTOR_SIZE` (line 48)
- `GET_BLOCK_SIZE` (line 49)
- `CTRL_TRIM` (line 50)
- `CTRL_POWER` (line 53)
- `CTRL_LOCK` (line 54)
- `CTRL_EJECT` (line 55)
- `CTRL_FORMAT` (line 56)
- `MMC_GET_TYPE` (line 59)
- `MMC_GET_CSD` (line 60)
- `MMC_GET_CID` (line 61)
- `MMC_GET_OCR` (line 62)
- `MMC_GET_SDSTAT` (line 63)
- `ISDIO_READ` (line 64)
- `ISDIO_WRITE` (line 65)
- `ISDIO_MRITE` (line 66)
- `ATA_GET_REV` (line 69)
- `ATA_GET_MODEL` (line 70)
- `ATA_GET_SN` (line 71)

#### `ff.h`
**Path:** `FatFs-R0.16/source/ff.h`

**Macros:**
- `FF_DEFINED` (line 23)
- `FF_INTDEF` (line 40)
- `isnan` (line 44)
- `isinf` (line 45)
- `FF_INTDEF` (line 48)
- `FF_INTDEF` (line 58)
- `_T` (line 93)
- `_TEXT` (line 94)
- `_T` (line 97)
- `_TEXT` (line 98)
- `_T` (line 101)
- `_TEXT` (line 102)
- `_T` (line 107)
- `_TEXT` (line 108)
- `f_eof` (line 359)
- `f_error` (line 361)
- `f_tell` (line 362)
- `f_size` (line 363)
- `f_rewind` (line 364)
- `f_rewinddir` (line 365)
- `f_rmdir` (line 366)
- `f_unmount` (line 367)
- `FA_READ` (line 412)
- `FA_WRITE` (line 413)
- `FA_OPEN_EXISTING` (line 414)
- `FA_CREATE_NEW` (line 415)
- `FA_CREATE_ALWAYS` (line 416)
- `FA_OPEN_ALWAYS` (line 417)
- `FA_OPEN_APPEND` (line 418)
- `CREATE_LINKMAP` (line 421)
- `FM_FAT` (line 424)
- `FM_FAT32` (line 425)
- `FM_EXFAT` (line 426)
- `FM_ANY` (line 427)
- `FM_SFD` (line 428)
- `FS_FAT12` (line 431)
- `FS_FAT16` (line 432)
- `FS_FAT32` (line 433)
- `FS_EXFAT` (line 434)
- `AM_RDO` (line 437)
- `AM_HID` (line 438)
- `AM_SYS` (line 439)
- `AM_DIR` (line 440)
- `AM_ARC` (line 441)

#### `ffconf.h`
**Path:** `FatFs-R0.16/source/ffconf.h`

**Macros:**
- `FFCONF_DEF` (line 4)
- `FF_FS_READONLY` (line 10)
- `FF_FS_MINIMIZE` (line 16)
- `FF_USE_FIND` (line 26)
- `FF_USE_MKFS` (line 31)
- `FF_USE_FASTSEEK` (line 35)
- `FF_USE_EXPAND` (line 39)
- `FF_USE_CHMOD` (line 43)
- `FF_USE_LABEL` (line 48)
- `FF_USE_FORWARD` (line 53)
- `FF_USE_STRFUNC` (line 57)
- `FF_PRINT_LLI` (line 60)
- `FF_PRINT_FLOAT` (line 61)
- `FF_STRF_ENCODE` (line 62)
- `FF_CODE_PAGE` (line 86)
- `FF_USE_LFN` (line 114)
- `FF_MAX_LFN` (line 117)
- `FF_LFN_UNICODE` (line 134)
- `FF_LFN_BUF` (line 146)
- `FF_SFN_BUF` (line 149)
- `FF_FS_RPATH` (line 154)
- `FF_PATH_DEPTH` (line 163)
- `FF_VOLUMES` (line 180)
- `FF_STR_VOLUME_ID` (line 183)
- `FF_VOLUME_STRS` (line 186)
- `FF_MULTI_PARTITION` (line 197)
- `FF_MIN_SS` (line 206)
- `FF_MAX_SS` (line 209)
- `FF_LBA64` (line 216)
- `FF_MIN_GPT` (line 221)
- `FF_USE_TRIM` (line 226)
- `FF_FS_TINY` (line 238)
- `FF_FS_EXFAT` (line 244)
- `FF_FS_NORTC` (line 250)
- `FF_NORTC_MON` (line 253)
- `FF_NORTC_MDAY` (line 254)
- `FF_NORTC_YEAR` (line 255)
- `FF_FS_CRTIME` (line 264)
- `FF_FS_NOFSINFO` (line 269)
- `FF_FS_LOCK` (line 281)
- `FF_FS_REENTRANT` (line 293)
- `FF_FS_TIMEOUT` (line 296)

#### `diskio_ramdisk.h`
**Path:** `harness/diskio_ramdisk.h`

**Macros:**
- `DISKIO_RAMDISK_H` (line 6)
- `RAMDISK_SECTOR_SIZE` (line 12)
- `RAMDISK_SECTOR_COUNT` (line 14)
- `RAMDISK_SIZE_BYTES` (line 15)

#### `test_ffconf.h`
**Path:** `harness/test_ffconf.h`

**Macros:**
- `TEST_FFCONF_H` (line 22)
- `FFCONF_DEF` (line 25)
- `FF_FS_READONLY` (line 28)
- `FF_FS_MINIMIZE` (line 29)
- `FF_USE_FIND` (line 30)
- `FF_USE_MKFS` (line 31)
- `FF_USE_FASTSEEK` (line 32)
- `FF_USE_EXPAND` (line 33)
- `FF_USE_CHMOD` (line 34)
- `FF_USE_LABEL` (line 35)
- `FF_USE_FORWARD` (line 36)
- `FF_USE_STRFUNC` (line 37)
- `FF_PRINT_LLI` (line 38)
- `FF_PRINT_FLOAT` (line 39)
- `FF_STRF_ENCODE` (line 40)
- `FF_CODE_PAGE` (line 43)
- `FF_USE_LFN` (line 44)
- `FF_MAX_LFN` (line 45)
- `FF_LFN_UNICODE` (line 46)
- `FF_LFN_BUF` (line 47)
- `FF_SFN_BUF` (line 48)
- `FF_FS_RPATH` (line 49)
- `FF_PATH_DEPTH` (line 50)
- `FF_VOLUMES` (line 53)
- `FF_STR_VOLUME_ID` (line 54)
- `FF_VOLUME_STRS` (line 55)
- `FF_MULTI_PARTITION` (line 56)
- `FF_MIN_SS` (line 57)
- `FF_MAX_SS` (line 58)
- `FF_LBA64` (line 59)
- `FF_MIN_GPT` (line 60)
- `FF_USE_TRIM` (line 61)
- `FF_FS_TINY` (line 64)
- `FF_FS_EXFAT` (line 65)
- `FF_FS_NORTC` (line 66)
- `FF_NORTC_MON` (line 67)
- `FF_NORTC_MDAY` (line 68)
- `FF_NORTC_YEAR` (line 69)
- `FF_FS_CRTIME` (line 70)
- `FF_FS_NOFSINFO` (line 71)
- `FF_FS_LOCK` (line 72)
- `FF_FS_REENTRANT` (line 73)

### PY (1 files)

#### `gen_exploit_image.py`
**Path:** `esp32-qemu-test/scripts/gen_exploit_image.py`

**Functions:**
- `lfn_checksum` (line 67) `def lfn_checksum(short_name_11)` - *Calculate VFAT LFN checksum for an 8.3 short name (11 bytes).*
- `build_lfn_entries` (line 76) `def build_lfn_entries(long_name, short_name_11)` - *Build VFAT LFN entries followed by the 8.3 entry for the same file.*
- `resolve_symbol_address` (line 115) `def resolve_symbol_address(elf_path, symbol_name)` - *Resolve a symbol address from an ELF using nm.*
- `build_xtensa_uart_shellcode` (line 149) `def build_xtensa_uart_shellcode()` - *Assemble raw Xtensa bytes that write a marker directly to UART0 and return.
These bytes are copied from FIRMWARE.BIN into g_ota_region.ctx.fw_header.*
- `build_payload_sector` (line 271) `def build_payload_sector(shellcode, callback_target_addr)` - *Build sector-8 payload bytes. The file starts as a normal firmware header
read, then overwrites the post-update callback in ota_update_ctx_t.*
- `generate_bug1_espidf_image` (line 282) `def generate_bug1_espidf_image(shellcode, callback_target_addr)` - *Generate a crafted FAT32 image for the ESP32 PoC.

This keeps the CVE-2026-6682-style geometry corruption while embedding a
long VFAT filename entry used by the CVE-2026-6688 caller-copy probe.

Returns bytes of length PARTITION_SIZE.*
- `inject_into_flash` (line 389) `def inject_into_flash(flash_path, output_path, shellcode, callback_target_addr)` - *Read the merged ESP32 flash image, inject the exploit FatFs partition
at PARTITION_OFFSET, and write the result.*
- `main` (line 456) `def main()`

### SH (2 files)

#### `run.sh`
**Path:** `esp32-qemu-test/run.sh`

**Functions:**
- `usage` (line 25)
- `image_exists` (line 35)
- `ensure_image` (line 39)
- `do_build` (line 46)
- `do_run` (line 53)
- `do_shell` (line 63)

#### `run_test.sh`
**Path:** `esp32-qemu-test/scripts/run_test.sh`

*No symbols extracted*
