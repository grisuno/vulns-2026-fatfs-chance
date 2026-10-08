# Subsystem: source (page 1 of 3)
Pages: [KB_source.md](KB_source.md), [KB_source_p2.md](KB_source_p2.md), [KB_source_p3.md](KB_source_p3.md)

## FatFs-R0.16/source/diskio.c
- Layer: utility
- Language: c
- Symbols:
  - `disk_status` (function, line 27) `DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)`
  - `disk_initialize` (function, line 65) `DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)`
  - `disk_read` (function, line 103) `DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		...`
  - `disk_write` (function, line 153) `DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE ...`
  - `disk_ioctl` (function, line 202) `DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code *...`
  - `DEV_FLASH` (macro, line 18) `#define DEV_FLASH`
  - `DEV_MMC` (macro, line 19) `#define DEV_MMC`
  - `DEV_USB` (macro, line 20) `#define DEV_USB`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/diskio.h
- Doc: DSTATUS: ifdef __cplusplus
- Layer: utility
- Language: h
- Symbols:
  - `DSTATUS` (type_alias, line 13) `typedef BYTE DSTATUS;`
  - `DSTATUS` (variable, line 9) `extern "C" { #endif /* Status of Disk Functions */ typedef BYTE DSTATUS;`
  - `_DISKIO_DEFINED` (macro, line 6) `#define _DISKIO_DEFINED`
  - `STA_NOINIT` (macro, line 38) `#define STA_NOINIT`
  - `STA_NODISK` (macro, line 39) `#define STA_NODISK`
  - `STA_PROTECT` (macro, line 40) `#define STA_PROTECT`
  - `CTRL_SYNC` (macro, line 46) `#define CTRL_SYNC`
  - `GET_SECTOR_COUNT` (macro, line 47) `#define GET_SECTOR_COUNT`
  - `GET_SECTOR_SIZE` (macro, line 48) `#define GET_SECTOR_SIZE`
  - `GET_BLOCK_SIZE` (macro, line 49) `#define GET_BLOCK_SIZE`
  - `CTRL_TRIM` (macro, line 50) `#define CTRL_TRIM`
  - `CTRL_POWER` (macro, line 53) `#define CTRL_POWER`
  - `CTRL_LOCK` (macro, line 54) `#define CTRL_LOCK`
  - `CTRL_EJECT` (macro, line 55) `#define CTRL_EJECT`
  - `CTRL_FORMAT` (macro, line 56) `#define CTRL_FORMAT`
  - `MMC_GET_TYPE` (macro, line 59) `#define MMC_GET_TYPE`
  - `MMC_GET_CSD` (macro, line 60) `#define MMC_GET_CSD`
  - `MMC_GET_CID` (macro, line 61) `#define MMC_GET_CID`
  - `MMC_GET_OCR` (macro, line 62) `#define MMC_GET_OCR`
  - `MMC_GET_SDSTAT` (macro, line 63) `#define MMC_GET_SDSTAT`
  - `ISDIO_READ` (macro, line 64) `#define ISDIO_READ`
  - `ISDIO_WRITE` (macro, line 65) `#define ISDIO_WRITE`
  - `ISDIO_MRITE` (macro, line 66) `#define ISDIO_MRITE`
  - `ATA_GET_REV` (macro, line 69) `#define ATA_GET_REV`
  - `ATA_GET_MODEL` (macro, line 70) `#define ATA_GET_MODEL`
  - `ATA_GET_SN` (macro, line 71) `#define ATA_GET_SN`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`


Next: [KB_source_p2.md](KB_source_p2.md)
