# FatFs-R0.16/source: ff

*Community 0 | 6 files | cohesion 0.33*

## Definition

This community groups 6 file(s) rooted at `FatFs-R0.16/source` with dominant language c (cohesion 0.33). Central symbols: `ABORT`, `AM_LFN`, `AM_MASK`, `AM_MASKX`, `AM_VOL`, `ATA_GET_MODEL`, `ATA_GET_REV`, `ATA_GET_SN`. Core file: `FatFs-R0.16/source/ff.c` (334 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `FatFs-R0.16/documents/res/app4.c` | c | utility | 3 | yes |
| `FatFs-R0.16/documents/res/app6.c` | c | utility | 1 | yes |
| `FatFs-R0.16/source/diskio.c` | c | utility | 8 | yes |
| `FatFs-R0.16/source/diskio.h` | h | utility | 26 | yes |
| `FatFs-R0.16/source/ff.c` | c | utility | 334 | yes |
| `harness/rce_demo.c` | c | utility | 14 | yes |

## Key Symbols

- `pn` (function, `FatFs-R0.16/documents/res/app4.c:14`) `static DWORD pn (       /* Pseudo random number generator */     DWORD pns   /*`
- `test_diskio` (function, `FatFs-R0.16/documents/res/app4.c:36`) `int test_diskio (     BYTE pdrv,      /* Physical drive number to be checked (al`
- `main` (function, `FatFs-R0.16/documents/res/app4.c:299`) `int main (int argc, char* argv[])`
- `test_raw_speed` (function, `FatFs-R0.16/documents/res/app6.c:11`) `int test_raw_speed (     BYTE pdrv,      /* Physical drive number */     DWORD l`
- `DEV_FLASH` (macro, `FatFs-R0.16/source/diskio.c:18`) `#define DEV_FLASH`
- `DEV_MMC` (macro, `FatFs-R0.16/source/diskio.c:19`) `#define DEV_MMC`
- `DEV_USB` (macro, `FatFs-R0.16/source/diskio.c:20`) `#define DEV_USB`
- `disk_status` (function, `FatFs-R0.16/source/diskio.c:27`) `DSTATUS disk_status ( 	BYTE pdrv		/* Physical drive nmuber to identify the drive`
- `disk_initialize` (function, `FatFs-R0.16/source/diskio.c:65`) `DSTATUS disk_initialize ( 	BYTE pdrv				/* Physical drive nmuber to identify the`
- `disk_read` (function, `FatFs-R0.16/source/diskio.c:103`) `DRESULT disk_read ( 	BYTE pdrv,		/* Physical drive nmuber to identify the drive`
- `disk_write` (function, `FatFs-R0.16/source/diskio.c:153`) `DRESULT disk_write ( 	BYTE pdrv,			/* Physical drive nmuber to identify the driv`
- `disk_ioctl` (function, `FatFs-R0.16/source/diskio.c:202`) `DRESULT disk_ioctl ( 	BYTE pdrv,		/* Physical drive nmuber (0..) */ 	BYTE cmd,`
- `_DISKIO_DEFINED` (macro, `FatFs-R0.16/source/diskio.h:6`) `#define _DISKIO_DEFINED`
- `DSTATUS` (variable, `FatFs-R0.16/source/diskio.h:9`) `extern "C" { #endif /* Status of Disk Functions */ typedef BYTE DSTATUS;` - ifdef __cplusplus
- `DSTATUS` (type_alias, `FatFs-R0.16/source/diskio.h:13`) `typedef BYTE DSTATUS;` - ----------------------------------------------------------------------/ Low level disk interface mod
- `STA_NOINIT` (macro, `FatFs-R0.16/source/diskio.h:38`) `#define STA_NOINIT`
- `STA_NODISK` (macro, `FatFs-R0.16/source/diskio.h:39`) `#define STA_NODISK`
- `STA_PROTECT` (macro, `FatFs-R0.16/source/diskio.h:40`) `#define STA_PROTECT`
- `CTRL_SYNC` (macro, `FatFs-R0.16/source/diskio.h:46`) `#define CTRL_SYNC`
- `GET_SECTOR_COUNT` (macro, `FatFs-R0.16/source/diskio.h:47`) `#define GET_SECTOR_COUNT`
- `GET_SECTOR_SIZE` (macro, `FatFs-R0.16/source/diskio.h:48`) `#define GET_SECTOR_SIZE`
- `GET_BLOCK_SIZE` (macro, `FatFs-R0.16/source/diskio.h:49`) `#define GET_BLOCK_SIZE`
- `CTRL_TRIM` (macro, `FatFs-R0.16/source/diskio.h:50`) `#define CTRL_TRIM`
- `CTRL_POWER` (macro, `FatFs-R0.16/source/diskio.h:53`) `#define CTRL_POWER`
- `CTRL_LOCK` (macro, `FatFs-R0.16/source/diskio.h:54`) `#define CTRL_LOCK`
- `CTRL_EJECT` (macro, `FatFs-R0.16/source/diskio.h:55`) `#define CTRL_EJECT`
- `CTRL_FORMAT` (macro, `FatFs-R0.16/source/diskio.h:56`) `#define CTRL_FORMAT`
- `MMC_GET_TYPE` (macro, `FatFs-R0.16/source/diskio.h:59`) `#define MMC_GET_TYPE`
- `MMC_GET_CSD` (macro, `FatFs-R0.16/source/diskio.h:60`) `#define MMC_GET_CSD`
- `MMC_GET_CID` (macro, `FatFs-R0.16/source/diskio.h:61`) `#define MMC_GET_CID`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 5
- Cross-boundary resolved imports (EXTRACTED): 10

## Connections

- [EXTRACTED] depends_on community 0 <-> 1 (strength 0.9): Extracted import edge crosses communities: FatFs-R0.16/documents/res/app4.c imports FatFs-R0.16/source/ff.h.
- [EXTRACTED] depends_on community 2 <-> 0 (strength 0.9): Extracted import edge crosses communities: harness/diskio_ramdisk.c imports FatFs-R0.16/source/diskio.h.
- [INFERRED] bridges community 0 <-> 1 (strength 0.7): Inferred cross-community bridge: FatFs-R0.16/source/diskio.h reaches FatFs-R0.16/source/ffconf.h in 3 hops.
- [INFERRED] bridges community 0 <-> 1 (strength 0.7): Inferred cross-community bridge: FatFs-R0.16/source/diskio.h reaches FatFs-R0.16/source/ffsystem.c in 3 hops.
- [INFERRED] bridges community 0 <-> 1 (strength 0.7): Inferred cross-community bridge: FatFs-R0.16/source/diskio.h reaches FatFs-R0.16/source/ffunicode.c in 3 hops.
- [INFERRED] bridges community 0 <-> 1 (strength 0.7): Inferred cross-community bridge: FatFs-R0.16/source/diskio.h reaches harness/ffunicode_stub.c in 3 hops.
- [INFERRED] shares_context community 0 <-> 3 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 0 (FatFs-R0.16/source: ff) and community 3 (orphans).

## Risks

- No scoped security, taint, cycle, or layer risks.

## Open Questions

- What would break if the most connected file in FatFs-R0.16/source: ff changed?
- Should FatFs-R0.16/source: ff be split, given cohesion 0.33?

## Sources

- `FatFs-R0.16/documents/res/app4.c`
- `FatFs-R0.16/documents/res/app6.c`
- `FatFs-R0.16/source/diskio.c`
- `FatFs-R0.16/source/diskio.h`
- `FatFs-R0.16/source/ff.c`
- `harness/rce_demo.c`
