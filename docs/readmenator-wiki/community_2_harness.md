# harness

*Community 2 | 5 files | cohesion 0.29*

## Definition

This community groups 5 file(s) rooted at `harness` with dominant language c (cohesion 0.29). Central symbols: `B4_BYTES_PER_SEC`, `B4_CLUS2SEC`, `B4_DATA_OFFSET_SECS`, `B4_FAT_OFFSET_SECS`, `B4_FAT_SIZE_SECS`, `B4_N_FATS`, `B4_RESERVED_SECS`, `B4_ROOT_DIR_SECS`. Core file: `harness/exploit_disks.c` (53 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `harness/diskio_ramdisk.c` | c | utility | 9 | yes |
| `harness/diskio_ramdisk.h` | h | utility | 10 | yes |
| `harness/exploit_disks.c` | c | utility | 53 | yes |
| `harness/libfuzzer_harness.c` | c | utility | 2 | yes |
| `harness/test_harness.c` | c | testing | 48 | yes |

## Key Symbols

- `ramdisk_reset_stats` (function, `harness/diskio_ramdisk.c:35`) `void ramdisk_reset_stats(void)`
- `ramdisk_load` (function, `harness/diskio_ramdisk.c:46`) `void ramdisk_load(const BYTE *image, UINT size)` - Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.  Any sector beyond the im
- `ramdisk_eject` (function, `harness/diskio_ramdisk.c:55`) `void ramdisk_eject(void)` - Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.  Any sector beyond the im
- `disk_status` (function, `harness/diskio_ramdisk.c:62`) `DSTATUS disk_status(BYTE pdrv)`
- `disk_initialize` (function, `harness/diskio_ramdisk.c:68`) `DSTATUS disk_initialize(BYTE pdrv)`
- `disk_read` (function, `harness/diskio_ramdisk.c:75`) `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)`
- `disk_write` (function, `harness/diskio_ramdisk.c:95`) `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)`
- `disk_ioctl` (function, `harness/diskio_ramdisk.c:114`) `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)`
- `get_fattime` (function, `harness/diskio_ramdisk.c:137`) `DWORD get_fattime(void)`
- `DISKIO_RAMDISK_H` (macro, `harness/diskio_ramdisk.h:6`) `#define DISKIO_RAMDISK_H`
- `RAMDISK_SECTOR_SIZE` (macro, `harness/diskio_ramdisk.h:13`) `#define RAMDISK_SECTOR_SIZE`
- `RAMDISK_SECTOR_COUNT` (macro, `harness/diskio_ramdisk.h:14`) `#define RAMDISK_SECTOR_COUNT`
- `RAMDISK_SIZE_BYTES` (macro, `harness/diskio_ramdisk.h:15`) `#define RAMDISK_SIZE_BYTES`
- `ramdisk` (variable, `harness/diskio_ramdisk.h:19`) `extern BYTE ramdisk[RAMDISK_SECTOR_COUNT * RAMDISK_SECTOR_SIZE];`
- `ramdisk_read_count` (variable, `harness/diskio_ramdisk.h:23`) `extern volatile uint32_t ramdisk_read_count;`
- `ramdisk_write_count` (variable, `harness/diskio_ramdisk.h:24`) `extern volatile uint32_t ramdisk_write_count;`
- `ramdisk_reset_stats` (function, `harness/diskio_ramdisk.h:26`) `void ramdisk_reset_stats(void);`
- `ramdisk_load` (function, `harness/diskio_ramdisk.h:31`) `void ramdisk_load(const BYTE *image, UINT size);` - /* ── backing store (accessible for direct inspection in tests) ──────────── extern BYTE ramdisk[RAM
- `ramdisk_eject` (function, `harness/diskio_ramdisk.h:34`) `void ramdisk_eject(void);` - /* ── instrumentation ────────────────────────────────────────────────────── extern volatile uint32_
- `exploit_disks` (function, `harness/exploit_disks.c:49`) `*   make exploit_disks            (see Makefile target)  *  * Expected output:`
- `IMG_DIR` (macro, `harness/exploit_disks.c:94`) `#define IMG_DIR`
- `st32le` (function, `harness/exploit_disks.c:99`) `static inline void st32le(uint8_t *p, uint32_t v)`
- `st64le` (function, `harness/exploit_disks.c:102`) `static inline void st64le(uint8_t *p, uint64_t v)`
- `INFO` (macro, `harness/exploit_disks.c:108`) `#define INFO(fmt, ...)`
- `PASS` (macro, `harness/exploit_disks.c:109`) `#define PASS(label)`
- `FAIL` (macro, `harness/exploit_disks.c:110`) `#define FAIL(label)`
- `SKIP` (macro, `harness/exploit_disks.c:111`) `#define SKIP(label)`
- `save_image` (function, `harness/exploit_disks.c:116`) `static int save_image(const char *name, const uint8_t *buf, size_t sz)` - -------------------------------------------------------------------------- I/O helpers *------------
- `load_ramdisk` (function, `harness/exploit_disks.c:129`) `static void load_ramdisk(const uint8_t *buf, size_t sz)`
- `bug1_write_vbr` (function, `harness/exploit_disks.c:156`) `static void bug1_write_vbr(uint8_t *disk)` - clst2sect(2) = 6 → attacker plants root-dir entry at sector 6 clst2sect(4) = 8 → attacker plants fil

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 4
- Cross-boundary resolved imports (EXTRACTED): 10

## Connections

- [EXTRACTED] depends_on community 2 <-> 1 (strength 0.9): Extracted import edge crosses communities: harness/diskio_ramdisk.c imports FatFs-R0.16/source/ff.h.
- [EXTRACTED] depends_on community 2 <-> 0 (strength 0.9): Extracted import edge crosses communities: harness/diskio_ramdisk.c imports FatFs-R0.16/source/diskio.h.
- [INFERRED] shares_context community 2 <-> 3 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 2 (harness) and community 3 (orphans).

## Risks

- [dataflow DEAD_STORE] `harness/exploit_disks.c:877` `Zephyr` `lab`: `lab` assigned at line 877 but never read afterwards.

## Open Questions

- What would break if the most connected file in harness changed?
- Should harness be split, given cohesion 0.29?

## Sources

- `harness/diskio_ramdisk.c`
- `harness/diskio_ramdisk.h`
- `harness/exploit_disks.c`
- `harness/libfuzzer_harness.c`
- `harness/test_harness.c`
