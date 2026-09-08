# Symbols

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `f_close` | function | `FatFs-R0.16/documents/res/app1.c:40` | `f_close(&fil);` |
| `f_mount` | function | `FatFs-R0.16/documents/res/app1.c:32` | `f_mount(&fs, "", 0);` |
| `f_printf` | function | `FatFs-R0.16/documents/res/app1.c:37` | `f_printf(&fil, "%02u/%02u/%u, %2u:%02u\n", Mday, Mon, Year, Hour, Min);` |
| `main` | function | `FatFs-R0.16/documents/res/app1.c:23` | `int main (void)` |
| `open_append` | function | `FatFs-R0.16/documents/res/app1.c:5` | `FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* p...` |
| `_tcscpy` | function | `FatFs-R0.16/documents/res/app2.c:65` | `_tcscpy(buff, _T("5:dir"));` |
| `_tprintf` | function | `FatFs-R0.16/documents/res/app2.c:72` | `_tprintf(_T("Failed to delete the directory. (%u)\n"), fr);` |
| `delete_node` | function | `FatFs-R0.16/documents/res/app2.c:7` | `FRESULT delete_node (
    TCHAR* path,    /* Path name buffer with the sub-directory to delete */...` |
| `f_closedir` | function | `FatFs-R0.16/documents/res/app2.c:45` | `f_closedir(&dir);` |
| `f_mount` | function | `FatFs-R0.16/documents/res/app2.c:60` | `f_mount(&fs, _T("5:"), 0);` |
| `allocate_contiguous_clusters` | function | `FatFs-R0.16/documents/res/app3.c:18` | `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:error or not contig...` |
| `clust2sect` | function | `FatFs-R0.16/documents/res/app3.c:15` | `DWORD clust2sect (FATFS* fs, DWORD clst);` |
| `f_close` | function | `FatFs-R0.16/documents/res/app3.c:97` | `f_close(&fil);` |
| `f_mount` | function | `FatFs-R0.16/documents/res/app3.c:88` | `f_mount(&fs, "", 0);` |
| `get_fat` | function | `FatFs-R0.16/documents/res/app3.c:16` | `DWORD get_fat (FATFS* fs, DWORD clst);` |
| `main` | function | `FatFs-R0.16/documents/res/app3.c:76` | `int main (void)` |
| `printf` | function | `FatFs-R0.16/documents/res/app3.c:96` | `printf("Function failed due to any error or insufficient contiguous area.\n");` |
| `put_fat` | function | `FatFs-R0.16/documents/res/app3.c:17` | `FRESULT put_fat (FATFS* fs, DWORD clst, DWORD val);` |
| `main` | function | `FatFs-R0.16/documents/res/app4.c:296` | `int main (int argc, char* argv[])` |
| `memset` | function | `FatFs-R0.16/documents/res/app4.c:137` | `memset(pbuff, 0, sz_sect);` |
| `pn` | function | `FatFs-R0.16/documents/res/app4.c:11` | `static DWORD pn (       /* Pseudo random number generator */
    DWORD pns   /* 0:Initialize, !0:...` |
| `printf` | function | `FatFs-R0.16/documents/res/app4.c:49` | `printf("test_diskio(%u, %u, 0x%08X, 0x%08X)\n", pdrv, ncyc, (UINT)buff, sz_buff);` |
| `test_diskio` | function | `FatFs-R0.16/documents/res/app4.c:34` | `int test_diskio (
    BYTE pdrv,      /* Physical drive number to be checked (all data on the dri...` |
| `test_contiguous_file` | function | `FatFs-R0.16/documents/res/app5.c:4` | `FRESULT test_contiguous_file (
    FIL* fp,    /* [IN]  Open file object to be checked */
    int...` |
| `printf` | function | `FatFs-R0.16/documents/res/app6.c:25` | `printf("\ndisk_ioctl() failed.\n");` |
| `test_raw_speed` | function | `FatFs-R0.16/documents/res/app6.c:9` | `int test_raw_speed (
    BYTE pdrv,      /* Physical drive number */
    DWORD lba,      /* Start...` |
| `DEV_FLASH` | macro | `FatFs-R0.16/source/diskio.c:18` | `#define DEV_FLASH` |
| `DEV_MMC` | macro | `FatFs-R0.16/source/diskio.c:19` | `#define DEV_MMC` |
| `DEV_USB` | macro | `FatFs-R0.16/source/diskio.c:20` | `#define DEV_USB` |
| `disk_initialize` | function | `FatFs-R0.16/source/diskio.c:64` | `DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)` |
| `disk_ioctl` | function | `FatFs-R0.16/source/diskio.c:201` | `DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code *...` |
| `disk_read` | function | `FatFs-R0.16/source/diskio.c:102` | `DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		...` |
| `disk_status` | function | `FatFs-R0.16/source/diskio.c:26` | `DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)` |
| `disk_write` | function | `FatFs-R0.16/source/diskio.c:152` | `DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE ...` |
| `ATA_GET_MODEL` | macro | `FatFs-R0.16/source/diskio.h:70` | `#define ATA_GET_MODEL` |
| `ATA_GET_REV` | macro | `FatFs-R0.16/source/diskio.h:69` | `#define ATA_GET_REV` |
| `ATA_GET_SN` | macro | `FatFs-R0.16/source/diskio.h:71` | `#define ATA_GET_SN` |
| `CTRL_EJECT` | macro | `FatFs-R0.16/source/diskio.h:55` | `#define CTRL_EJECT` |
| `CTRL_FORMAT` | macro | `FatFs-R0.16/source/diskio.h:56` | `#define CTRL_FORMAT` |
| `CTRL_LOCK` | macro | `FatFs-R0.16/source/diskio.h:54` | `#define CTRL_LOCK` |
| `CTRL_POWER` | macro | `FatFs-R0.16/source/diskio.h:53` | `#define CTRL_POWER` |
| `CTRL_SYNC` | macro | `FatFs-R0.16/source/diskio.h:46` | `#define CTRL_SYNC` |
| `CTRL_TRIM` | macro | `FatFs-R0.16/source/diskio.h:50` | `#define CTRL_TRIM` |
| `DSTATUS` | variable | `FatFs-R0.16/source/diskio.h:9` | `extern "C" { #endif /* Status of Disk Functions */ typedef BYTE DSTATUS;` |
| `DSTATUS` | type_alias | `FatFs-R0.16/source/diskio.h:13` | `typedef BYTE DSTATUS;` |
| `GET_BLOCK_SIZE` | macro | `FatFs-R0.16/source/diskio.h:49` | `#define GET_BLOCK_SIZE` |
| `GET_SECTOR_COUNT` | macro | `FatFs-R0.16/source/diskio.h:47` | `#define GET_SECTOR_COUNT` |
| `GET_SECTOR_SIZE` | macro | `FatFs-R0.16/source/diskio.h:48` | `#define GET_SECTOR_SIZE` |
| `ISDIO_MRITE` | macro | `FatFs-R0.16/source/diskio.h:66` | `#define ISDIO_MRITE` |
| `ISDIO_READ` | macro | `FatFs-R0.16/source/diskio.h:64` | `#define ISDIO_READ` |
| `ISDIO_WRITE` | macro | `FatFs-R0.16/source/diskio.h:65` | `#define ISDIO_WRITE` |
| `MMC_GET_CID` | macro | `FatFs-R0.16/source/diskio.h:61` | `#define MMC_GET_CID` |
| `MMC_GET_CSD` | macro | `FatFs-R0.16/source/diskio.h:60` | `#define MMC_GET_CSD` |
| `MMC_GET_OCR` | macro | `FatFs-R0.16/source/diskio.h:62` | `#define MMC_GET_OCR` |
| `MMC_GET_SDSTAT` | macro | `FatFs-R0.16/source/diskio.h:63` | `#define MMC_GET_SDSTAT` |
| `MMC_GET_TYPE` | macro | `FatFs-R0.16/source/diskio.h:59` | `#define MMC_GET_TYPE` |
| `STA_NODISK` | macro | `FatFs-R0.16/source/diskio.h:39` | `#define STA_NODISK` |
| `STA_NOINIT` | macro | `FatFs-R0.16/source/diskio.h:37` | `#define STA_NOINIT` |
| `STA_PROTECT` | macro | `FatFs-R0.16/source/diskio.h:40` | `#define STA_PROTECT` |
| `_DISKIO_DEFINED` | macro | `FatFs-R0.16/source/diskio.h:6` | `#define _DISKIO_DEFINED` |
| `disk_initialize` | function | `FatFs-R0.16/source/diskio.h:27` | `DSTATUS disk_initialize (BYTE pdrv);` |
| `disk_ioctl` | function | `FatFs-R0.16/source/diskio.h:33` | `DRESULT disk_ioctl (BYTE pdrv, BYTE cmd, void* buff);` |
| `disk_read` | function | `FatFs-R0.16/source/diskio.h:31` | `DRESULT disk_read (BYTE pdrv, BYTE* buff, LBA_t sector, UINT count);` |
| `disk_status` | function | `FatFs-R0.16/source/diskio.h:30` | `DSTATUS disk_status (BYTE pdrv);` |
| `disk_write` | function | `FatFs-R0.16/source/diskio.h:32` | `DRESULT disk_write (BYTE pdrv, const BYTE* buff, LBA_t sector, UINT count);` |
| `ABORT` | macro | `FatFs-R0.16/source/ff.c:234` | `#define ABORT(fs, res)` |
| `ABORT` | function | `FatFs-R0.16/source/ff.c:4189` | `ABORT(fs, FR_DISK_ERR);` |
| `AM_LFN` | macro | `FatFs-R0.16/source/ff.c:65` | `#define AM_LFN` |
| `AM_MASK` | macro | `FatFs-R0.16/source/ff.c:66` | `#define AM_MASK` |
| `AM_MASKX` | macro | `FatFs-R0.16/source/ff.c:67` | `#define AM_MASKX` |
| `AM_VOL` | macro | `FatFs-R0.16/source/ff.c:64` | `#define AM_VOL` |
| `BPB_BkBootSec32` | macro | `FatFs-R0.16/source/ff.c:122` | `#define BPB_BkBootSec32` |
| `BPB_BytsPerSec` | macro | `FatFs-R0.16/source/ff.c:96` | `#define BPB_BytsPerSec` |
| `BPB_BytsPerSecEx` | macro | `FatFs-R0.16/source/ff.c:142` | `#define BPB_BytsPerSecEx` |
| `BPB_DataOfsEx` | macro | `FatFs-R0.16/source/ff.c:136` | `#define BPB_DataOfsEx` |
| `BPB_DrvNumEx` | macro | `FatFs-R0.16/source/ff.c:145` | `#define BPB_DrvNumEx` |
| `BPB_ExtFlags32` | macro | `FatFs-R0.16/source/ff.c:118` | `#define BPB_ExtFlags32` |
| `BPB_FATSz16` | macro | `FatFs-R0.16/source/ff.c:103` | `#define BPB_FATSz16` |
| `BPB_FATSz32` | macro | `FatFs-R0.16/source/ff.c:116` | `#define BPB_FATSz32` |
| `BPB_FSInfo32` | macro | `FatFs-R0.16/source/ff.c:121` | `#define BPB_FSInfo32` |
| `BPB_FSVer32` | macro | `FatFs-R0.16/source/ff.c:119` | `#define BPB_FSVer32` |
| `BPB_FSVerEx` | macro | `FatFs-R0.16/source/ff.c:140` | `#define BPB_FSVerEx` |
| `BPB_FatOfsEx` | macro | `FatFs-R0.16/source/ff.c:134` | `#define BPB_FatOfsEx` |
| `BPB_FatSzEx` | macro | `FatFs-R0.16/source/ff.c:135` | `#define BPB_FatSzEx` |
| `BPB_HiddSec` | macro | `FatFs-R0.16/source/ff.c:106` | `#define BPB_HiddSec` |
| `BPB_Media` | macro | `FatFs-R0.16/source/ff.c:102` | `#define BPB_Media` |
| `BPB_NumClusEx` | macro | `FatFs-R0.16/source/ff.c:137` | `#define BPB_NumClusEx` |
| `BPB_NumFATs` | macro | `FatFs-R0.16/source/ff.c:99` | `#define BPB_NumFATs` |
| `BPB_NumFATsEx` | macro | `FatFs-R0.16/source/ff.c:144` | `#define BPB_NumFATsEx` |
| `BPB_NumHeads` | macro | `FatFs-R0.16/source/ff.c:105` | `#define BPB_NumHeads` |
| `BPB_PercInUseEx` | macro | `FatFs-R0.16/source/ff.c:146` | `#define BPB_PercInUseEx` |
| `BPB_RootClus32` | macro | `FatFs-R0.16/source/ff.c:120` | `#define BPB_RootClus32` |
| `BPB_RootClusEx` | macro | `FatFs-R0.16/source/ff.c:138` | `#define BPB_RootClusEx` |
| `BPB_RootEntCnt` | macro | `FatFs-R0.16/source/ff.c:100` | `#define BPB_RootEntCnt` |
| `BPB_RsvdEx` | macro | `FatFs-R0.16/source/ff.c:147` | `#define BPB_RsvdEx` |
| `BPB_RsvdSecCnt` | macro | `FatFs-R0.16/source/ff.c:98` | `#define BPB_RsvdSecCnt` |
| `BPB_SecPerClus` | macro | `FatFs-R0.16/source/ff.c:97` | `#define BPB_SecPerClus` |
| `BPB_SecPerClusEx` | macro | `FatFs-R0.16/source/ff.c:143` | `#define BPB_SecPerClusEx` |
| `BPB_SecPerTrk` | macro | `FatFs-R0.16/source/ff.c:104` | `#define BPB_SecPerTrk` |
| `BPB_TotSec16` | macro | `FatFs-R0.16/source/ff.c:101` | `#define BPB_TotSec16` |
| `BPB_TotSec32` | macro | `FatFs-R0.16/source/ff.c:107` | `#define BPB_TotSec32` |
| `BPB_TotSecEx` | macro | `FatFs-R0.16/source/ff.c:133` | `#define BPB_TotSecEx` |
| `BPB_VolFlagEx` | macro | `FatFs-R0.16/source/ff.c:141` | `#define BPB_VolFlagEx` |
| `BPB_VolIDEx` | macro | `FatFs-R0.16/source/ff.c:139` | `#define BPB_VolIDEx` |
| `BPB_VolOfsEx` | macro | `FatFs-R0.16/source/ff.c:132` | `#define BPB_VolOfsEx` |
| `BPB_ZeroedEx` | macro | `FatFs-R0.16/source/ff.c:130` | `#define BPB_ZeroedEx` |
| `BS_55AA` | macro | `FatFs-R0.16/source/ff.c:115` | `#define BS_55AA` |
| `BS_BootCode` | macro | `FatFs-R0.16/source/ff.c:114` | `#define BS_BootCode` |
| `BS_BootCode32` | macro | `FatFs-R0.16/source/ff.c:129` | `#define BS_BootCode32` |
| `BS_BootCodeEx` | macro | `FatFs-R0.16/source/ff.c:148` | `#define BS_BootCodeEx` |
| `BS_BootSig` | macro | `FatFs-R0.16/source/ff.c:110` | `#define BS_BootSig` |
| `BS_BootSig32` | macro | `FatFs-R0.16/source/ff.c:125` | `#define BS_BootSig32` |
| `BS_DrvNum` | macro | `FatFs-R0.16/source/ff.c:108` | `#define BS_DrvNum` |
| `BS_DrvNum32` | macro | `FatFs-R0.16/source/ff.c:123` | `#define BS_DrvNum32` |
| `BS_FilSysType` | macro | `FatFs-R0.16/source/ff.c:113` | `#define BS_FilSysType` |
| `BS_FilSysType32` | macro | `FatFs-R0.16/source/ff.c:128` | `#define BS_FilSysType32` |
| `BS_JmpBoot` | macro | `FatFs-R0.16/source/ff.c:93` | `#define BS_JmpBoot` |
| `BS_NTres` | macro | `FatFs-R0.16/source/ff.c:109` | `#define BS_NTres` |
| `BS_NTres32` | macro | `FatFs-R0.16/source/ff.c:124` | `#define BS_NTres32` |
| `BS_OEMName` | macro | `FatFs-R0.16/source/ff.c:95` | `#define BS_OEMName` |
| `BS_VolID` | macro | `FatFs-R0.16/source/ff.c:111` | `#define BS_VolID` |
| `BS_VolID32` | macro | `FatFs-R0.16/source/ff.c:126` | `#define BS_VolID32` |
| `BS_VolLab` | macro | `FatFs-R0.16/source/ff.c:112` | `#define BS_VolLab` |
| `BS_VolLab32` | macro | `FatFs-R0.16/source/ff.c:127` | `#define BS_VolLab32` |
| `CODEPAGE` | macro | `FatFs-R0.16/source/ff.c:568` | `#define CODEPAGE` |
| `CODEPAGE` | macro | `FatFs-R0.16/source/ff.c:596` | `#define CODEPAGE` |
| `CODEPAGE` | macro | `FatFs-R0.16/source/ff.c:600` | `#define CODEPAGE` |
| `DDEM` | macro | `FatFs-R0.16/source/ff.c:188` | `#define DDEM` |
| `DEF_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:502` | `#define DEF_NAMEBUFF` |
| `DEF_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:525` | `#define DEF_NAMEBUFF` |
| `DEF_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:532` | `#define DEF_NAMEBUFF` |
| `DEF_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:536` | `#define DEF_NAMEBUFF` |
| `DEF_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:544` | `#define DEF_NAMEBUFF` |
| `DEF_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:548` | `#define DEF_NAMEBUFF` |
| `DIR_Attr` | macro | `FatFs-R0.16/source/ff.c:151` | `#define DIR_Attr` |
| `DIR_CrtTime` | macro | `FatFs-R0.16/source/ff.c:154` | `#define DIR_CrtTime` |
| `DIR_CrtTime10` | macro | `FatFs-R0.16/source/ff.c:153` | `#define DIR_CrtTime10` |
| `DIR_FileSize` | macro | `FatFs-R0.16/source/ff.c:159` | `#define DIR_FileSize` |
| `DIR_FstClusHI` | macro | `FatFs-R0.16/source/ff.c:156` | `#define DIR_FstClusHI` |
| `DIR_FstClusLO` | macro | `FatFs-R0.16/source/ff.c:158` | `#define DIR_FstClusLO` |
| `DIR_LstAccDate` | macro | `FatFs-R0.16/source/ff.c:155` | `#define DIR_LstAccDate` |
| `DIR_ModTime` | macro | `FatFs-R0.16/source/ff.c:157` | `#define DIR_ModTime` |
| `DIR_NTres` | macro | `FatFs-R0.16/source/ff.c:152` | `#define DIR_NTres` |
| `DIR_Name` | macro | `FatFs-R0.16/source/ff.c:149` | `#define DIR_Name` |
| `DIR_READ_FILE` | macro | `FatFs-R0.16/source/ff.c:2330` | `#define DIR_READ_FILE(dp)` |
| `DIR_READ_LABEL` | macro | `FatFs-R0.16/source/ff.c:2332` | `#define DIR_READ_LABEL(dp)` |
| `ET_BITMAP` | macro | `FatFs-R0.16/source/ff.c:83` | `#define	ET_BITMAP` |
| `ET_FILEDIR` | macro | `FatFs-R0.16/source/ff.c:86` | `#define	ET_FILEDIR` |
| `ET_FILENAME` | macro | `FatFs-R0.16/source/ff.c:88` | `#define	ET_FILENAME` |
| `ET_STREAM` | macro | `FatFs-R0.16/source/ff.c:87` | `#define	ET_STREAM` |
| `ET_UPCASE` | macro | `FatFs-R0.16/source/ff.c:84` | `#define	ET_UPCASE` |
| `ET_VLABEL` | macro | `FatFs-R0.16/source/ff.c:85` | `#define	ET_VLABEL` |
| `FA_DIRTY` | macro | `FatFs-R0.16/source/ff.c:60` | `#define FA_DIRTY` |
| `FA_MODIFIED` | macro | `FatFs-R0.16/source/ff.c:59` | `#define FA_MODIFIED` |
| `FA_SEEKEND` | macro | `FatFs-R0.16/source/ff.c:58` | `#define FA_SEEKEND` |
| `FILESEM` | struct | `FatFs-R0.16/source/ff.c:285` | `` |
| `FIND_RECURS` | macro | `FatFs-R0.16/source/ff.c:2803` | `#define FIND_RECURS` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:504` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:527` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:534` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:538` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:546` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:550` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | function | `FatFs-R0.16/source/ff.c:3980` | `FREE_NAMEBUFF();` |
| `FSI_Free_Count` | macro | `FatFs-R0.16/source/ff.c:194` | `#define FSI_Free_Count` |
| `FSI_LeadSig` | macro | `FatFs-R0.16/source/ff.c:191` | `#define FSI_LeadSig` |
| `FSI_Nxt_Free` | macro | `FatFs-R0.16/source/ff.c:195` | `#define FSI_Nxt_Free` |
| `FSI_StrucSig` | macro | `FatFs-R0.16/source/ff.c:193` | `#define FSI_StrucSig` |
| `FSI_TrailSig` | macro | `FatFs-R0.16/source/ff.c:196` | `#define FSI_TrailSig` |
| `GET_FATTIME` | macro | `FatFs-R0.16/source/ff.c:274` | `#define GET_FATTIME()` |
| `GET_FATTIME` | macro | `FatFs-R0.16/source/ff.c:276` | `#define GET_FATTIME()` |
| `GPTE_Flags` | macro | `FatFs-R0.16/source/ff.c:229` | `#define GPTE_Flags` |
| `GPTE_FstLba` | macro | `FatFs-R0.16/source/ff.c:227` | `#define GPTE_FstLba` |
| `GPTE_LstLba` | macro | `FatFs-R0.16/source/ff.c:228` | `#define GPTE_LstLba` |
| `GPTE_Name` | macro | `FatFs-R0.16/source/ff.c:230` | `#define GPTE_Name` |
| `GPTE_PtGuid` | macro | `FatFs-R0.16/source/ff.c:225` | `#define GPTE_PtGuid` |
| `GPTE_UpGuid` | macro | `FatFs-R0.16/source/ff.c:226` | `#define GPTE_UpGuid` |
| `GPTH_BakLba` | macro | `FatFs-R0.16/source/ff.c:216` | `#define GPTH_BakLba` |
| `GPTH_Bcc` | macro | `FatFs-R0.16/source/ff.c:214` | `#define GPTH_Bcc` |
| `GPTH_CurLba` | macro | `FatFs-R0.16/source/ff.c:215` | `#define GPTH_CurLba` |
| `GPTH_DskGuid` | macro | `FatFs-R0.16/source/ff.c:219` | `#define GPTH_DskGuid` |
| `GPTH_FstLba` | macro | `FatFs-R0.16/source/ff.c:217` | `#define GPTH_FstLba` |
| `GPTH_LstLba` | macro | `FatFs-R0.16/source/ff.c:218` | `#define GPTH_LstLba` |
| `GPTH_PtBcc` | macro | `FatFs-R0.16/source/ff.c:223` | `#define GPTH_PtBcc` |
| `GPTH_PtNum` | macro | `FatFs-R0.16/source/ff.c:221` | `#define GPTH_PtNum` |
| `GPTH_PtOfs` | macro | `FatFs-R0.16/source/ff.c:220` | `#define GPTH_PtOfs` |
| `GPTH_PteSize` | macro | `FatFs-R0.16/source/ff.c:222` | `#define GPTH_PteSize` |
| `GPTH_Rev` | macro | `FatFs-R0.16/source/ff.c:212` | `#define GPTH_Rev` |
| `GPTH_Sign` | macro | `FatFs-R0.16/source/ff.c:210` | `#define GPTH_Sign` |
| `GPTH_Size` | macro | `FatFs-R0.16/source/ff.c:213` | `#define GPTH_Size` |
| `GPT_ALIGN` | macro | `FatFs-R0.16/source/ff.c:5894` | `#define	GPT_ALIGN` |
| `GPT_ITEMS` | macro | `FatFs-R0.16/source/ff.c:5895` | `#define GPT_ITEMS` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:503` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:526` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:533` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:537` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:545` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:549` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | function | `FatFs-R0.16/source/ff.c:3820` | `INIT_NAMEBUFF(fs);` |
| `IsDigit` | macro | `FatFs-R0.16/source/ff.c:49` | `#define IsDigit(c)` |
| `IsLower` | macro | `FatFs-R0.16/source/ff.c:48` | `#define IsLower(c)` |
| `IsSeparator` | macro | `FatFs-R0.16/source/ff.c:50` | `#define IsSeparator(c)` |
| `IsSurrogate` | macro | `FatFs-R0.16/source/ff.c:52` | `#define IsSurrogate(c)` |
| `IsSurrogateH` | macro | `FatFs-R0.16/source/ff.c:53` | `#define IsSurrogateH(c)` |
| `IsSurrogateL` | macro | `FatFs-R0.16/source/ff.c:54` | `#define IsSurrogateL(c)` |
| `IsTerminator` | macro | `FatFs-R0.16/source/ff.c:51` | `#define IsTerminator(c)` |
| `IsUpper` | macro | `FatFs-R0.16/source/ff.c:47` | `#define IsUpper(c)` |
| `LD2PD` | macro | `FatFs-R0.16/source/ff.c:250` | `#define LD2PD(vol)` |
| `LD2PD` | macro | `FatFs-R0.16/source/ff.c:253` | `#define LD2PD(vol)` |
| `LD2PT` | macro | `FatFs-R0.16/source/ff.c:251` | `#define LD2PT(vol)` |
| `LD2PT` | macro | `FatFs-R0.16/source/ff.c:254` | `#define LD2PT(vol)` |
| `LDIR_Attr` | macro | `FatFs-R0.16/source/ff.c:161` | `#define LDIR_Attr` |
| `LDIR_Chksum` | macro | `FatFs-R0.16/source/ff.c:163` | `#define LDIR_Chksum` |
| `LDIR_FstClusLO` | macro | `FatFs-R0.16/source/ff.c:164` | `#define LDIR_FstClusLO` |
| `LDIR_Ord` | macro | `FatFs-R0.16/source/ff.c:160` | `#define LDIR_Ord` |
| `LDIR_Type` | macro | `FatFs-R0.16/source/ff.c:162` | `#define LDIR_Type` |
| `LEAVE_FF` | macro | `FatFs-R0.16/source/ff.c:242` | `#define LEAVE_FF(fs, res)` |
| `LEAVE_FF` | macro | `FatFs-R0.16/source/ff.c:244` | `#define LEAVE_FF(fs, res)` |
| `LEAVE_FF` | function | `FatFs-R0.16/source/ff.c:3789` | `LEAVE_FF(fs, res);` |
| `LEAVE_MKFS` | macro | `FatFs-R0.16/source/ff.c:505` | `#define LEAVE_MKFS(res)` |
| `LEAVE_MKFS` | macro | `FatFs-R0.16/source/ff.c:528` | `#define LEAVE_MKFS(res)` |
| `LEAVE_MKFS` | macro | `FatFs-R0.16/source/ff.c:540` | `#define LEAVE_MKFS(res)` |
| `LEAVE_MKFS` | macro | `FatFs-R0.16/source/ff.c:552` | `#define LEAVE_MKFS(res)` |
| `LEAVE_MKFS` | function | `FatFs-R0.16/source/ff.c:6397` | `LEAVE_MKFS(FR_MKFS_ABORTED);` |
| `LLEF` | macro | `FatFs-R0.16/source/ff.c:190` | `#define LLEF` |
| `MAXDIRB` | macro | `FatFs-R0.16/source/ff.c:518` | `#define MAXDIRB(nc)` |
| `MAX_DIR` | macro | `FatFs-R0.16/source/ff.c:38` | `#define MAX_DIR` |
| `MAX_DIR_EX` | macro | `FatFs-R0.16/source/ff.c:39` | `#define MAX_DIR_EX` |
| `MAX_EXFAT` | macro | `FatFs-R0.16/source/ff.c:43` | `#define MAX_EXFAT` |
| `MAX_FAT12` | macro | `FatFs-R0.16/source/ff.c:40` | `#define MAX_FAT12` |
| `MAX_FAT16` | macro | `FatFs-R0.16/source/ff.c:41` | `#define MAX_FAT16` |
| `MAX_FAT32` | macro | `FatFs-R0.16/source/ff.c:42` | `#define MAX_FAT32` |
| `MAX_MALLOC` | macro | `FatFs-R0.16/source/ff.c:553` | `#define MAX_MALLOC` |
| `MBR_Table` | macro | `FatFs-R0.16/source/ff.c:197` | `#define MBR_Table` |
| `MERGE_2STR` | macro | `FatFs-R0.16/source/ff.c:442` | `#define MERGE_2STR(a, b)` |
| `MKCVTBL` | macro | `FatFs-R0.16/source/ff.c:443` | `#define MKCVTBL(hd, cp)` |
| `NSFLAG` | macro | `FatFs-R0.16/source/ff.c:71` | `#define NSFLAG` |
| `NS_BODY` | macro | `FatFs-R0.16/source/ff.c:75` | `#define NS_BODY` |
| `NS_DOT` | macro | `FatFs-R0.16/source/ff.c:77` | `#define NS_DOT` |
| `NS_EXT` | macro | `FatFs-R0.16/source/ff.c:76` | `#define NS_EXT` |
| `NS_LAST` | macro | `FatFs-R0.16/source/ff.c:74` | `#define NS_LAST` |
| `NS_LFN` | macro | `FatFs-R0.16/source/ff.c:73` | `#define NS_LFN` |
| `NS_LOSS` | macro | `FatFs-R0.16/source/ff.c:72` | `#define NS_LOSS` |
| `NS_NOLFN` | macro | `FatFs-R0.16/source/ff.c:78` | `#define NS_NOLFN` |
| `NS_NONAME` | macro | `FatFs-R0.16/source/ff.c:79` | `#define NS_NONAME` |
| `N_SEC_TRACK` | macro | `FatFs-R0.16/source/ff.c:5892` | `#define N_SEC_TRACK` |
| `PTE_Boot` | macro | `FatFs-R0.16/source/ff.c:200` | `#define PTE_Boot` |
| `PTE_EdCyl` | macro | `FatFs-R0.16/source/ff.c:207` | `#define PTE_EdCyl` |
| `PTE_EdHead` | macro | `FatFs-R0.16/source/ff.c:205` | `#define PTE_EdHead` |
| `PTE_EdSec` | macro | `FatFs-R0.16/source/ff.c:206` | `#define PTE_EdSec` |
| `PTE_SizLba` | macro | `FatFs-R0.16/source/ff.c:209` | `#define PTE_SizLba` |
| `PTE_StCyl` | macro | `FatFs-R0.16/source/ff.c:203` | `#define PTE_StCyl` |
| `PTE_StHead` | macro | `FatFs-R0.16/source/ff.c:201` | `#define PTE_StHead` |
| `PTE_StLba` | macro | `FatFs-R0.16/source/ff.c:208` | `#define PTE_StLba` |
| `PTE_StSec` | macro | `FatFs-R0.16/source/ff.c:202` | `#define PTE_StSec` |
| `PTE_System` | macro | `FatFs-R0.16/source/ff.c:204` | `#define PTE_System` |
| `RDDEM` | macro | `FatFs-R0.16/source/ff.c:189` | `#define RDDEM` |
| `SS` | macro | `FatFs-R0.16/source/ff.c:263` | `#define SS(fs)` |
| `SS` | macro | `FatFs-R0.16/source/ff.c:265` | `#define SS(fs)` |
| `SZDIRE` | macro | `FatFs-R0.16/source/ff.c:186` | `#define SZDIRE` |
| `SZ_GPTE` | macro | `FatFs-R0.16/source/ff.c:224` | `#define SZ_GPTE` |
| `SZ_NUM_BUF` | macro | `FatFs-R0.16/source/ff.c:6717` | `#define SZ_NUM_BUF` |
| `SZ_PTE` | macro | `FatFs-R0.16/source/ff.c:199` | `#define SZ_PTE` |
| `SZ_PUTC_BUF` | macro | `FatFs-R0.16/source/ff.c:6716` | `#define SZ_PUTC_BUF` |
| `TBL_CT437` | macro | `FatFs-R0.16/source/ff.c:295` | `#define TBL_CT437` |
| `TBL_CT720` | macro | `FatFs-R0.16/source/ff.c:303` | `#define TBL_CT720` |
| `TBL_CT737` | macro | `FatFs-R0.16/source/ff.c:311` | `#define TBL_CT737` |
| `TBL_CT771` | macro | `FatFs-R0.16/source/ff.c:319` | `#define TBL_CT771` |
| `TBL_CT775` | macro | `FatFs-R0.16/source/ff.c:327` | `#define TBL_CT775` |
| `TBL_CT850` | macro | `FatFs-R0.16/source/ff.c:335` | `#define TBL_CT850` |
| `TBL_CT852` | macro | `FatFs-R0.16/source/ff.c:343` | `#define TBL_CT852` |
| `TBL_CT855` | macro | `FatFs-R0.16/source/ff.c:351` | `#define TBL_CT855` |
| `TBL_CT857` | macro | `FatFs-R0.16/source/ff.c:359` | `#define TBL_CT857` |
| `TBL_CT860` | macro | `FatFs-R0.16/source/ff.c:367` | `#define TBL_CT860` |
| `TBL_CT861` | macro | `FatFs-R0.16/source/ff.c:375` | `#define TBL_CT861` |
| `TBL_CT862` | macro | `FatFs-R0.16/source/ff.c:383` | `#define TBL_CT862` |
| `TBL_CT863` | macro | `FatFs-R0.16/source/ff.c:391` | `#define TBL_CT863` |
| `TBL_CT864` | macro | `FatFs-R0.16/source/ff.c:399` | `#define TBL_CT864` |
| `TBL_CT865` | macro | `FatFs-R0.16/source/ff.c:407` | `#define TBL_CT865` |
| `TBL_CT866` | macro | `FatFs-R0.16/source/ff.c:415` | `#define TBL_CT866` |
| `TBL_CT869` | macro | `FatFs-R0.16/source/ff.c:423` | `#define TBL_CT869` |
| `TBL_DC932` | macro | `FatFs-R0.16/source/ff.c:435` | `#define TBL_DC932` |
| `TBL_DC936` | macro | `FatFs-R0.16/source/ff.c:436` | `#define TBL_DC936` |
| `TBL_DC949` | macro | `FatFs-R0.16/source/ff.c:437` | `#define TBL_DC949` |
| `TBL_DC950` | macro | `FatFs-R0.16/source/ff.c:438` | `#define TBL_DC950` |
| `XDIR_AccTZ` | macro | `FatFs-R0.16/source/ff.c:179` | `#define XDIR_AccTZ` |
| `XDIR_AccTime` | macro | `FatFs-R0.16/source/ff.c:174` | `#define XDIR_AccTime` |
| `XDIR_Attr` | macro | `FatFs-R0.16/source/ff.c:171` | `#define XDIR_Attr` |
| `XDIR_CaseSum` | macro | `FatFs-R0.16/source/ff.c:168` | `#define XDIR_CaseSum` |
| `XDIR_CrtTZ` | macro | `FatFs-R0.16/source/ff.c:177` | `#define XDIR_CrtTZ` |
| `XDIR_CrtTime` | macro | `FatFs-R0.16/source/ff.c:172` | `#define XDIR_CrtTime` |
| `XDIR_CrtTime10` | macro | `FatFs-R0.16/source/ff.c:175` | `#define XDIR_CrtTime10` |
| `XDIR_FileSize` | macro | `FatFs-R0.16/source/ff.c:185` | `#define XDIR_FileSize` |
| `XDIR_FstClus` | macro | `FatFs-R0.16/source/ff.c:184` | `#define XDIR_FstClus` |
| `XDIR_GenFlags` | macro | `FatFs-R0.16/source/ff.c:180` | `#define XDIR_GenFlags` |
| `XDIR_Label` | macro | `FatFs-R0.16/source/ff.c:167` | `#define XDIR_Label` |
| `XDIR_ModTZ` | macro | `FatFs-R0.16/source/ff.c:178` | `#define XDIR_ModTZ` |
| `XDIR_ModTime` | macro | `FatFs-R0.16/source/ff.c:173` | `#define XDIR_ModTime` |
| `XDIR_ModTime10` | macro | `FatFs-R0.16/source/ff.c:176` | `#define XDIR_ModTime10` |
| `XDIR_NameHash` | macro | `FatFs-R0.16/source/ff.c:182` | `#define XDIR_NameHash` |
| `XDIR_NumLabel` | macro | `FatFs-R0.16/source/ff.c:166` | `#define XDIR_NumLabel` |
| `XDIR_NumName` | macro | `FatFs-R0.16/source/ff.c:181` | `#define XDIR_NumName` |
| `XDIR_NumSec` | macro | `FatFs-R0.16/source/ff.c:169` | `#define XDIR_NumSec` |
| `XDIR_SetSum` | macro | `FatFs-R0.16/source/ff.c:170` | `#define XDIR_SetSum` |
| `XDIR_Type` | macro | `FatFs-R0.16/source/ff.c:165` | `#define XDIR_Type` |
| `XDIR_ValidFileSize` | macro | `FatFs-R0.16/source/ff.c:183` | `#define XDIR_ValidFileSize` |
| `change_bitmap` | function | `FatFs-R0.16/source/ff.c:1358` | `static FRESULT change_bitmap (
	FATFS* fs,	/* Filesystem object */
	DWORD clst,	/* Cluster number...` |
| `check_fs` | function | `FatFs-R0.16/source/ff.c:3366` | `static UINT check_fs (	/* 0:FAT/FAT32 VBR, 1:exFAT VBR, 2:Not FAT and valid BS, 3:Not FAT and inv...` |
| `chk_share` | function | `FatFs-R0.16/source/ff.c:946` | `static FRESULT chk_share (	/* Check if the file can be accessed */
	DIR* dp,		/* Directory object...` |
| `clear_share` | function | `FatFs-R0.16/source/ff.c:1036` | `static void clear_share (	/* Clear all lock entries of the volume */
	FATFS* fs
)` |
| `clmt_clust` | function | `FatFs-R0.16/source/ff.c:1643` | `static DWORD clmt_clust (	/* <2:Error, >=2:Cluster number */
	FIL* fp,		/* Pointer to the file ob...` |
| `clst2sect` | function | `FatFs-R0.16/source/ff.c:1158` | `static LBA_t clst2sect (	/* !=0:Sector number, 0:Failed (invalid cluster#) */
	FATFS* fs,		/* Fil...` |
| `cmp_lfn` | function | `FatFs-R0.16/source/ff.c:1901` | `static int cmp_lfn (		/* 1:matched, 0:not matched */
	const WCHAR* lfnbuf,	/* Pointer to the LFN ...` |
| `crc32` | function | `FatFs-R0.16/source/ff.c:3296` | `static DWORD crc32 (	/* Returns next CRC value */
	DWORD crc,			/* Current CRC value */
	BYTE d		...` |
| `create_chain` | function | `FatFs-R0.16/source/ff.c:1538` | `static DWORD create_chain (	/* 0:No free cluster, 1:Internal error, 0xFFFFFFFF:Disk error, >=2:Ne...` |
| `create_name` | function | `FatFs-R0.16/source/ff.c:2891` | `static FRESULT create_name (	/* FR_OK: successful, FR_INVALID_NAME: could not create */
	DIR* dp,...` |
| `create_partition` | function | `FatFs-R0.16/source/ff.c:5899` | `static FRESULT create_partition (
	BYTE drv,			/* Physical drive number */
	const LBA_t plst[],	/...` |
| `create_xdir` | function | `FatFs-R0.16/source/ff.c:2287` | `static void create_xdir (
	BYTE* dirb,			/* Pointer to the directory entry block buffer */
	const...` |
| `dbc_1st` | function | `FatFs-R0.16/source/ff.c:693` | `static int dbc_1st (BYTE c)` |
| `dbc_2nd` | function | `FatFs-R0.16/source/ff.c:713` | `static int dbc_2nd (BYTE c)` |
| `dec_share` | function | `FatFs-R0.16/source/ff.c:1012` | `static FRESULT dec_share (	/* Decrement object open counter */
	UINT i			/* Semaphore index (1..)...` |
| `dir_alloc` | function | `FatFs-R0.16/source/ff.c:1822` | `static FRESULT dir_alloc (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,				/* Pointer to the dir...` |
| `dir_clear` | function | `FatFs-R0.16/source/ff.c:1675` | `static FRESULT dir_clear (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS *fs,		/* Filesystem object *...` |
| `dir_find` | function | `FatFs-R0.16/source/ff.c:2411` | `static FRESULT dir_find (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp					/* Pointer to the dire...` |
| `dir_next` | function | `FatFs-R0.16/source/ff.c:1761` | `static FRESULT dir_next (	/* FR_OK(0):succeeded, FR_NO_FILE:End of table, FR_DENIED:Could not str...` |
| `dir_read` | function | `FatFs-R0.16/source/ff.c:2333` | `static FRESULT dir_read (
	DIR* dp,		/* Pointer to the directory object */
	int vol			/* Filtered...` |
| `dir_register` | function | `FatFs-R0.16/source/ff.c:2493` | `static FRESULT dir_register (	/* FR_OK:succeeded, FR_DENIED:no free entry or too many SFN collisi...` |
| `dir_remove` | function | `FatFs-R0.16/source/ff.c:2606` | `static FRESULT dir_remove (	/* FR_OK:Succeeded, FR_DISK_ERR:A disk error */
	DIR* dp					/* Direc...` |
| `dir_sdi` | function | `FatFs-R0.16/source/ff.c:1713` | `static FRESULT dir_sdi (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,		/* Pointer to directory o...` |
| `disk_ioctl` | function | `FatFs-R0.16/source/ff.c:1495` | `disk_ioctl(fs->pdrv, CTRL_TRIM, rt);` |
| `disk_write` | function | `FatFs-R0.16/source/ff.c:1129` | `disk_write(fs->pdrv, fs->win, fs->winsect = fs->volbase + 1, 1);` |
| `f_chdir` | function | `FatFs-R0.16/source/ff.c:4356` | `FRESULT f_chdir (
	const TCHAR* path	/* Pointer to the directory path */
)` |
| `f_chdrive` | function | `FatFs-R0.16/source/ff.c:4334` | `FRESULT f_chdrive (
	const TCHAR* path		/* Drive number to set */
)` |
| `f_chmod` | function | `FatFs-R0.16/source/ff.c:5384` | `FRESULT f_chmod (
	const TCHAR* path,	/* Pointer to the file path */
	BYTE attr,			/* Attribute b...` |
| `f_close` | function | `FatFs-R0.16/source/ff.c:4298` | `FRESULT f_close (
	FIL* fp		/* Open file to be closed */
)` |
| `f_closedir` | function | `FatFs-R0.16/source/ff.c:4780` | `FRESULT f_closedir (
	DIR *dp		/* Pointer to the directory object to be closed */
)` |
| `f_expand` | function | `FatFs-R0.16/source/ff.c:5725` | `FRESULT f_expand (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t fsz,	/* File size to be e...` |
| `f_fdisk` | function | `FatFs-R0.16/source/ff.c:6547` | `FRESULT f_fdisk (
	BYTE pdrv,			/* Physical drive number */
	const LBA_t ptbl[],	/* Pointer to th...` |
| `f_findfirst` | function | `FatFs-R0.16/source/ff.c:4874` | `FRESULT f_findfirst (
	DIR* dp,				/* Pointer to the blank directory object */
	FILINFO* fno,			/...` |
| `f_findnext` | function | `FatFs-R0.16/source/ff.c:4849` | `FRESULT f_findnext (
	DIR* dp,		/* Pointer to the open directory object */
	FILINFO* fno	/* Point...` |
| `f_forward` | function | `FatFs-R0.16/source/ff.c:5821` | `FRESULT f_forward (
	FIL* fp, 						/* Pointer to the file object */
	UINT (*func)(const BYTE*,UI...` |
| `f_getcwd` | function | `FatFs-R0.16/source/ff.c:4418` | `FRESULT f_getcwd (
	TCHAR* buff,	/* Pointer to the buffer to store the current direcotry path */
...` |
| `f_getfree` | function | `FatFs-R0.16/source/ff.c:4938` | `FRESULT f_getfree (
	const TCHAR* path,	/* Logical drive number */
	DWORD* nclst,		/* Pointer to ...` |
| `f_getlabel` | function | `FatFs-R0.16/source/ff.c:5501` | `FRESULT f_getlabel (
	const TCHAR* path,	/* Logical drive number */
	TCHAR* label,		/* Buffer to ...` |
| `f_gets` | function | `FatFs-R0.16/source/ff.c:6587` | `TCHAR* f_gets (
	TCHAR* buff,	/* Pointer to the buffer to store read string */
	int len,		/* Size...` |
| `f_lseek` | function | `FatFs-R0.16/source/ff.c:4554` | `FRESULT f_lseek (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t ofs		/* File pointer from ...` |
| `f_mkdir` | function | `FatFs-R0.16/source/ff.c:5175` | `FRESULT f_mkdir (
	const TCHAR* path		/* Pointer to the directory path */
)` |
| `f_mkfs` | function | `FatFs-R0.16/source/ff.c:6040` | `FRESULT f_mkfs (
	const TCHAR* path,		/* Logical drive number */
	const MKFS_PARM* opt,	/* Format...` |
| `f_open` | function | `FatFs-R0.16/source/ff.c:3798` | `FRESULT f_open (
	FIL* fp,			/* Pointer to the blank file object */
	const TCHAR* path,	/* Pointe...` |
| `f_opendir` | function | `FatFs-R0.16/source/ff.c:4718` | `FRESULT f_opendir (
	DIR* dp,			/* Pointer to directory object to create */
	const TCHAR* path	/*...` |
| `f_printf` | function | `FatFs-R0.16/source/ff.c:7054` | `int f_printf (
	FIL* fp,			/* Pointer to the file object */
	const TCHAR* fmt,	/* Pointer to the ...` |
| `f_putc` | function | `FatFs-R0.16/source/ff.c:6891` | `int f_putc (
	TCHAR c,	/* A character to be output */
	FIL* fp		/* Pointer to the file object */
)` |
| `f_puts` | function | `FatFs-R0.16/source/ff.c:6913` | `int f_puts (
	const TCHAR* str,	/* Pointer to the string to be output */
	FIL* fp				/* Pointer t...` |
| `f_read` | function | `FatFs-R0.16/source/ff.c:3995` | `FRESULT f_read (
	FIL* fp, 	/* Open file to be read */
	void* buff,	/* Data buffer to store the r...` |
| `f_readdir` | function | `FatFs-R0.16/source/ff.c:4810` | `FRESULT f_readdir (
	DIR* dp,			/* Pointer to the open directory object */
	FILINFO* fno		/* Poin...` |
| `f_rename` | function | `FatFs-R0.16/source/ff.c:5260` | `FRESULT f_rename (
	const TCHAR* path_old,	/* Pointer to the object name to be renamed */
	const ...` |
| `f_setcp` | function | `FatFs-R0.16/source/ff.c:7225` | `FRESULT f_setcp (
	WORD cp		/* Value to be set as active code page */
)` |
| `f_setlabel` | function | `FatFs-R0.16/source/ff.c:5602` | `FRESULT f_setlabel (
	const TCHAR* label	/* Volume label to set with heading logical drive number...` |
| `f_stat` | function | `FatFs-R0.16/source/ff.c:4901` | `FRESULT f_stat (
	const TCHAR* path,	/* Pointer to the file path */
	FILINFO* fno		/* Pointer to ...` |
| `f_sync` | function | `FatFs-R0.16/source/ff.c:4217` | `FRESULT f_sync (
	FIL* fp		/* Open file to be synced */
)` |
| `f_truncate` | function | `FatFs-R0.16/source/ff.c:5035` | `FRESULT f_truncate (
	FIL* fp		/* Pointer to the file object */
)` |
| `f_unlink` | function | `FatFs-R0.16/source/ff.c:5086` | `FRESULT f_unlink (
	const TCHAR* path		/* Pointer to the file or directory path */
)` |
| `f_utime` | function | `FatFs-R0.16/source/ff.c:5433` | `FRESULT f_utime (
	const TCHAR* path,	/* Pointer to the file/directory name */
	const FILINFO* fn...` |
| `f_write` | function | `FatFs-R0.16/source/ff.c:4096` | `FRESULT f_write (
	FIL* fp,			/* Open file to be written */
	const void* buff,	/* Data to be writ...` |
| `ff_memfree` | function | `FatFs-R0.16/source/ff.c:1696` | `ff_memfree(ibuf);` |
| `ff_mutex_delete` | function | `FatFs-R0.16/source/ff.c:3762` | `ff_mutex_delete(vol);` |
| `ff_mutex_give` | function | `FatFs-R0.16/source/ff.c:912` | `ff_mutex_give(fs->ldrv);` |
| `fill_first_frag` | function | `FatFs-R0.16/source/ff.c:1394` | `static FRESULT fill_first_frag (
	FFOBJID* obj	/* Pointer to the corresponding object */
)` |
| `fill_last_frag` | function | `FatFs-R0.16/source/ff.c:1417` | `static FRESULT fill_last_frag (
	FFOBJID* obj,	/* Pointer to the corresponding object */
	DWORD l...` |
| `find_bitmap` | function | `FatFs-R0.16/source/ff.c:1318` | `static DWORD find_bitmap (	/* 0:Not found, 2..:Cluster block found, 0xFFFFFFFF:Disk error */
	FAT...` |
| `find_volume` | function | `FatFs-R0.16/source/ff.c:3406` | `static UINT find_volume (	/* Returns BS status found in the hosting drive */
	FATFS* fs,		/* File...` |
| `follow_path` | function | `FatFs-R0.16/source/ff.c:3100` | `static FRESULT follow_path (	/* FR_OK(0): successful, !=0: error code */
	DIR* dp,					/* Directo...` |
| `ftoa` | function | `FatFs-R0.16/source/ff.c:6978` | `static void ftoa (
	char* buf,	/* Buffer to output the floating point string */
	double val,	/* V...` |
| `gen_numname` | function | `FatFs-R0.16/source/ff.c:2012` | `static void gen_numname (
	BYTE* dst,			/* Pointer to the buffer to store numbered SFN */
	const ...` |
| `get_achar` | function | `FatFs-R0.16/source/ff.c:2805` | `static DWORD get_achar (	/* Get a character and advance ptr */
	const TCHAR** ptr		/* Pointer to ...` |
| `get_fat` | function | `FatFs-R0.16/source/ff.c:1175` | `static DWORD get_fat (		/* 0xFFFFFFFF:Disk error, 1:Internal error, 2..0x7FFFFFFF:Cluster status ...` |
| `get_fileinfo` | function | `FatFs-R0.16/source/ff.c:2652` | `static void get_fileinfo (
	DIR* dp,			/* Pointer to the directory object */
	FILINFO* fno		/* Po...` |
| `get_ldnumber` | function | `FatFs-R0.16/source/ff.c:3219` | `static int get_ldnumber (	/* Returns logical drive number (-1:invalid drive number or null pointe...` |
| `inc_share` | function | `FatFs-R0.16/source/ff.c:981` | `static UINT inc_share (	/* Increment object open counter and returns its index (0:Internal error)...` |
| `init_alloc_info` | function | `FatFs-R0.16/source/ff.c:2198` | `static void init_alloc_info (
	FFOBJID* dobj,	/* Object allocation information to be initialized ...` |
| `ld_clust` | function | `FatFs-R0.16/source/ff.c:1864` | `static DWORD ld_clust (	/* Returns the top cluster value of the SFN entry */
	FATFS* fs,			/* Poi...` |
| `load_obj_xdir` | function | `FatFs-R0.16/source/ff.c:2224` | `static FRESULT load_obj_xdir (
	DIR* dp,			/* Blank directory object to be used to access contain...` |
| `load_xdir` | function | `FatFs-R0.16/source/ff.c:2146` | `static FRESULT load_xdir (	/* FR_INT_ERR: invalid entry block */
	DIR* dp					/* Reading director...` |
| `lock_volume` | function | `FatFs-R0.16/source/ff.c:895` | `static int lock_volume (	/* 1:Ok, 0:timeout */
	FATFS* fs,				/* Filesystem object to lock */
	in...` |
| `make_rand` | function | `FatFs-R0.16/source/ff.c:3339` | `static DWORD make_rand (	/* Returns a seed value for next */
	DWORD seed,				/* Seed value */
	BY...` |
| `memcpy` | function | `FatFs-R0.16/source/ff.c:2022` | `memcpy(dst, src, 11);` |
| `memset` | function | `FatFs-R0.16/source/ff.c:1123` | `memset(fs->win, 0, sizeof fs->win);` |
| `mount_volume` | function | `FatFs-R0.16/source/ff.c:3460` | `static FRESULT mount_volume (	/* FR_OK(0): successful, !=0: an error occurred */
	const TCHAR** p...` |
| `move_window` | function | `FatFs-R0.16/source/ff.c:1077` | `static FRESULT move_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs,		/* Filesystem object...` |
| `pattern_match` | function | `FatFs-R0.16/source/ff.c:2836` | `static int pattern_match (	/* 0:mismatched, 1:matched */
	const TCHAR* pat,	/* Matching pattern *...` |
| `pick_lfn` | function | `FatFs-R0.16/source/ff.c:1937` | `static int pick_lfn (	/* 1:succeeded, 0:buffer overflow or invalid LFN entry */
	WCHAR* lfnbuf,		...` |
| `put_fat` | function | `FatFs-R0.16/source/ff.c:1253` | `static FRESULT put_fat (	/* FR_OK(0):succeeded, !=0:error */
	FATFS* fs,		/* Corresponding filesy...` |
| `put_lfn` | function | `FatFs-R0.16/source/ff.c:1975` | `static void put_lfn (
	const WCHAR* lfn,	/* Pointer to the LFN */
	BYTE* dir,			/* Pointer to the...` |
| `put_utf` | function | `FatFs-R0.16/source/ff.c:806` | `static UINT put_utf (	/* Returns number of encoding units written (0:buffer overflow or wrong enc...` |
| `putbuff` | struct | `FatFs-R0.16/source/ff.c:6725` | `` |
| `putc_bfd` | function | `FatFs-R0.16/source/ff.c:6739` | `static void putc_bfd (putbuff* pb, TCHAR c)` |
| `putc_flush` | function | `FatFs-R0.16/source/ff.c:6870` | `static int putc_flush (putbuff* pb)` |
| `putc_init` | function | `FatFs-R0.16/source/ff.c:6885` | `static void putc_init (putbuff* pb, FIL* fp)` |
| `remove_chain` | function | `FatFs-R0.16/source/ff.c:1443` | `static FRESULT remove_chain (	/* FR_OK(0):succeeded, !=0:error */
	FFOBJID* obj,		/* Correspondin...` |
| `st_16` | function | `FatFs-R0.16/source/ff.c:1284` | `st_16(fs->win + clst * 2 % SS(fs), (WORD)val);` |
| `st_32` | function | `FatFs-R0.16/source/ff.c:1124` | `st_32(fs->win + FSI_LeadSig, 0x41615252);` |
| `st_64` | function | `FatFs-R0.16/source/ff.c:2527` | `st_64(fs->dirbuf + XDIR_FileSize, dp->obj.objsize);` |
| `st_clust` | function | `FatFs-R0.16/source/ff.c:1882` | `static void st_clust (
	FATFS* fs,	/* Pointer to the fs object */
	BYTE* dir,	/* Pointer to the k...` |
| `store_xdir` | function | `FatFs-R0.16/source/ff.c:2253` | `static FRESULT store_xdir (
	DIR* dp				/* Pointer to the directory object */
)` |
| `sum_sfn` | function | `FatFs-R0.16/source/ff.c:2069` | `static BYTE sum_sfn (
	const BYTE* dir		/* Pointer to the SFN entry */
)` |
| `sync_fs` | function | `FatFs-R0.16/source/ff.c:1109` | `static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs		/* Filesystem object */
)` |
| `sync_window` | function | `FatFs-R0.16/source/ff.c:1057` | `static FRESULT sync_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs			/* Filesystem object...` |
| `tchar2uni` | function | `FatFs-R0.16/source/ff.c:737` | `static DWORD tchar2uni (	/* Returns a character in UTF-16 encoding (>=0x10000 on surrogate pair, ...` |
| `test_gpt_header` | function | `FatFs-R0.16/source/ff.c:3314` | `static int test_gpt_header (	/* 0:Invalid, 1:Valid */
	const BYTE* gpth			/* Pointer to the GPT h...` |
| `unlock_volume` | function | `FatFs-R0.16/source/ff.c:920` | `static void unlock_volume (
	FATFS* fs,		/* Filesystem object */
	FRESULT res		/* Result code to ...` |
| `va_end` | function | `FatFs-R0.16/source/ff.c:7210` | `va_end(arp);` |
| `va_start` | function | `FatFs-R0.16/source/ff.c:7079` | `va_start(arp, fmt);` |
| `validate` | function | `FatFs-R0.16/source/ff.c:3694` | `static FRESULT validate (	/* Returns FR_OK or FR_INVALID_OBJECT */
	FFOBJID* obj,			/* Pointer to...` |
| `xdir_sum` | function | `FatFs-R0.16/source/ff.c:2091` | `static WORD xdir_sum (	/* Get checksum of the directoly entry block */
	const BYTE* dir		/* Direc...` |
| `xname_sum` | function | `FatFs-R0.16/source/ff.c:2110` | `static WORD xname_sum (	/* Get check sum (to be used as hash) of the file name */
	const WCHAR* n...` |
| `xsum32` | function | `FatFs-R0.16/source/ff.c:2131` | `static DWORD xsum32 (	/* Returns 32-bit checksum */
	BYTE  dat,			/* Byte to be calculated (byte-...` |
| `AM_ARC` | macro | `FatFs-R0.16/source/ff.h:441` | `#define AM_ARC` |
| `AM_DIR` | macro | `FatFs-R0.16/source/ff.h:440` | `#define AM_DIR` |
| `AM_HID` | macro | `FatFs-R0.16/source/ff.h:438` | `#define	AM_HID` |
| `AM_RDO` | macro | `FatFs-R0.16/source/ff.h:437` | `#define	AM_RDO` |
| `AM_SYS` | macro | `FatFs-R0.16/source/ff.h:439` | `#define	AM_SYS` |
| `BYTE` | type_alias | `FatFs-R0.16/source/ff.h:51` | `typedef unsigned char BYTE;` |
| `BYTE` | type_alias | `FatFs-R0.16/source/ff.h:60` | `typedef unsigned char BYTE;` |
| `CREATE_LINKMAP` | macro | `FatFs-R0.16/source/ff.h:421` | `#define CREATE_LINKMAP` |
| `DWORD` | type_alias | `FatFs-R0.16/source/ff.h:53` | `typedef uint32_t DWORD;` |
| `DWORD` | type_alias | `FatFs-R0.16/source/ff.h:62` | `typedef unsigned long DWORD;` |
| `FATFS` | struct | `FatFs-R0.16/source/ff.h:150` | `` |
| `FA_CREATE_ALWAYS` | macro | `FatFs-R0.16/source/ff.h:416` | `#define	FA_CREATE_ALWAYS` |
| `FA_CREATE_NEW` | macro | `FatFs-R0.16/source/ff.h:415` | `#define	FA_CREATE_NEW` |
| `FA_OPEN_ALWAYS` | macro | `FatFs-R0.16/source/ff.h:417` | `#define	FA_OPEN_ALWAYS` |
| `FA_OPEN_APPEND` | macro | `FatFs-R0.16/source/ff.h:418` | `#define	FA_OPEN_APPEND` |
| `FA_OPEN_EXISTING` | macro | `FatFs-R0.16/source/ff.h:414` | `#define	FA_OPEN_EXISTING` |
| `FA_READ` | macro | `FatFs-R0.16/source/ff.h:412` | `#define	FA_READ` |
| `FA_WRITE` | macro | `FatFs-R0.16/source/ff.h:413` | `#define	FA_WRITE` |
| `FFOBJID` | struct | `FatFs-R0.16/source/ff.h:195` | `` |
| `FFXCWDL` | struct | `FatFs-R0.16/source/ff.h:136` | `` |
| `FFXCWDS` | struct | `FatFs-R0.16/source/ff.h:141` | `` |
| `FF_DEFINED` | macro | `FatFs-R0.16/source/ff.h:23` | `#define FF_DEFINED` |
| `FF_INTDEF` | macro | `FatFs-R0.16/source/ff.h:40` | `#define FF_INTDEF` |
| `FF_INTDEF` | macro | `FatFs-R0.16/source/ff.h:48` | `#define FF_INTDEF` |
| `FF_INTDEF` | macro | `FatFs-R0.16/source/ff.h:58` | `#define FF_INTDEF` |
| `FIL` | struct | `FatFs-R0.16/source/ff.h:218` | `` |
| `FILINFO` | struct | `FatFs-R0.16/source/ff.h:260` | `` |
| `FM_ANY` | macro | `FatFs-R0.16/source/ff.h:427` | `#define FM_ANY` |
| `FM_EXFAT` | macro | `FatFs-R0.16/source/ff.h:426` | `#define FM_EXFAT` |
| `FM_FAT` | macro | `FatFs-R0.16/source/ff.h:424` | `#define FM_FAT` |
| `FM_FAT32` | macro | `FatFs-R0.16/source/ff.h:425` | `#define FM_FAT32` |
| `FM_SFD` | macro | `FatFs-R0.16/source/ff.h:428` | `#define FM_SFD` |
| `FSIZE_t` | type_alias | `FatFs-R0.16/source/ff.h:73` | `typedef QWORD FSIZE_t;` |
| `FSIZE_t` | type_alias | `FatFs-R0.16/source/ff.h:83` | `typedef DWORD FSIZE_t;` |
| `FS_EXFAT` | macro | `FatFs-R0.16/source/ff.h:434` | `#define FS_EXFAT` |
| `FS_FAT12` | macro | `FatFs-R0.16/source/ff.h:431` | `#define FS_FAT12` |
| `FS_FAT16` | macro | `FatFs-R0.16/source/ff.h:432` | `#define FS_FAT16` |
| `FS_FAT32` | macro | `FatFs-R0.16/source/ff.h:433` | `#define FS_FAT32` |
| `LBA_t` | type_alias | `FatFs-R0.16/source/ff.h:75` | `typedef QWORD LBA_t;` |
| `LBA_t` | type_alias | `FatFs-R0.16/source/ff.h:77` | `typedef DWORD LBA_t;` |
| `LBA_t` | type_alias | `FatFs-R0.16/source/ff.h:84` | `typedef DWORD LBA_t;` |
| `MKFS_PARM` | struct | `FatFs-R0.16/source/ff.h:281` | `` |
| `PARTITION` | struct | `FatFs-R0.16/source/ff.h:116` | `` |
| `QWORD` | variable | `FatFs-R0.16/source/ff.h:26` | `extern "C" { #endif #if !defined(FFCONF_DEF) #include "ffconf.h" /* FatFs configuration options */ #endif #if FF_DEFINED` |
| `QWORD` | type_alias | `FatFs-R0.16/source/ff.h:42` | `typedef unsigned __int64 QWORD;` |
| `QWORD` | type_alias | `FatFs-R0.16/source/ff.h:54` | `typedef uint64_t QWORD;` |
| `TCHAR` | type_alias | `FatFs-R0.16/source/ff.h:92` | `typedef WCHAR TCHAR;` |
| `TCHAR` | type_alias | `FatFs-R0.16/source/ff.h:96` | `typedef char TCHAR;` |
| `TCHAR` | type_alias | `FatFs-R0.16/source/ff.h:100` | `typedef DWORD TCHAR;` |
| `TCHAR` | type_alias | `FatFs-R0.16/source/ff.h:106` | `typedef char TCHAR;` |
| `UINT` | type_alias | `FatFs-R0.16/source/ff.h:50` | `typedef unsigned int UINT;` |
| `UINT` | type_alias | `FatFs-R0.16/source/ff.h:59` | `typedef unsigned int UINT;` |
| `VolToPart` | variable | `FatFs-R0.16/source/ff.h:120` | `extern PARTITION VolToPart[];` |
| `VolumeStr` | variable | `FatFs-R0.16/source/ff.h:125` | `extern const char* VolumeStr[FF_VOLUMES];` |
| `WCHAR` | type_alias | `FatFs-R0.16/source/ff.h:55` | `typedef WORD WCHAR;` |
| `WCHAR` | type_alias | `FatFs-R0.16/source/ff.h:63` | `typedef WORD WCHAR;` |
| `WORD` | type_alias | `FatFs-R0.16/source/ff.h:52` | `typedef uint16_t WORD;` |
| `WORD` | type_alias | `FatFs-R0.16/source/ff.h:61` | `typedef unsigned short WORD;` |
| `_T` | macro | `FatFs-R0.16/source/ff.h:93` | `#define _T(x)` |
| `_T` | macro | `FatFs-R0.16/source/ff.h:97` | `#define _T(x)` |
| `_T` | macro | `FatFs-R0.16/source/ff.h:101` | `#define _T(x)` |
| `_T` | macro | `FatFs-R0.16/source/ff.h:107` | `#define _T(x)` |
| `_TEXT` | macro | `FatFs-R0.16/source/ff.h:94` | `#define _TEXT(x)` |
| `_TEXT` | macro | `FatFs-R0.16/source/ff.h:98` | `#define _TEXT(x)` |
| `_TEXT` | macro | `FatFs-R0.16/source/ff.h:102` | `#define _TEXT(x)` |
| `_TEXT` | macro | `FatFs-R0.16/source/ff.h:108` | `#define _TEXT(x)` |
| `f_chdir` | function | `FatFs-R0.16/source/ff.h:341` | `FRESULT f_chdir (const TCHAR* path);` |
| `f_chdrive` | function | `FatFs-R0.16/source/ff.h:342` | `FRESULT f_chdrive (const TCHAR* path);` |
| `f_chmod` | function | `FatFs-R0.16/source/ff.h:339` | `FRESULT f_chmod (const TCHAR* path, BYTE attr, BYTE mask);` |
| `f_close` | function | `FatFs-R0.16/source/ff.h:324` | `FRESULT f_close (FIL* fp);` |
| `f_closedir` | function | `FatFs-R0.16/source/ff.h:331` | `FRESULT f_closedir (DIR* dp);` |
| `f_eof` | macro | `FatFs-R0.16/source/ff.h:359` | `#define f_eof(fp)` |
| `f_error` | macro | `FatFs-R0.16/source/ff.h:361` | `#define f_error(fp)` |
| `f_expand` | function | `FatFs-R0.16/source/ff.h:348` | `FRESULT f_expand (FIL* fp, FSIZE_t fsz, BYTE opt);` |
| `f_fdisk` | function | `FatFs-R0.16/source/ff.h:351` | `FRESULT f_fdisk (BYTE pdrv, const LBA_t ptbl[], void* work);` |
| `f_findfirst` | function | `FatFs-R0.16/source/ff.h:333` | `FRESULT f_findfirst (DIR* dp, FILINFO* fno, const TCHAR* path, const TCHAR* pattern);` |
| `f_findnext` | function | `FatFs-R0.16/source/ff.h:334` | `FRESULT f_findnext (DIR* dp, FILINFO* fno);` |
| `f_forward` | function | `FatFs-R0.16/source/ff.h:347` | `FRESULT f_forward (FIL* fp, UINT(*func)(const BYTE*,UINT), UINT btf, UINT* bf);` |
| `f_getcwd` | function | `FatFs-R0.16/source/ff.h:343` | `FRESULT f_getcwd (TCHAR* buff, UINT len);` |
| `f_getfree` | function | `FatFs-R0.16/source/ff.h:344` | `FRESULT f_getfree (const TCHAR* path, DWORD* nclst, FATFS** fatfs);` |
| `f_getlabel` | function | `FatFs-R0.16/source/ff.h:345` | `FRESULT f_getlabel (const TCHAR* path, TCHAR* label, DWORD* vsn);` |
| `f_gets` | function | `FatFs-R0.16/source/ff.h:356` | `TCHAR* f_gets (TCHAR* buff, int len, FIL* fp);` |
| `f_lseek` | function | `FatFs-R0.16/source/ff.h:327` | `FRESULT f_lseek (FIL* fp, FSIZE_t ofs);` |
| `f_mkdir` | function | `FatFs-R0.16/source/ff.h:335` | `FRESULT f_mkdir (const TCHAR* path);` |
| `f_mkfs` | function | `FatFs-R0.16/source/ff.h:350` | `FRESULT f_mkfs (const TCHAR* path, const MKFS_PARM* opt, void* work, UINT len);` |
| `f_mount` | function | `FatFs-R0.16/source/ff.h:349` | `FRESULT f_mount (FATFS* fs, const TCHAR* path, BYTE opt);` |
| `f_open` | function | `FatFs-R0.16/source/ff.h:322` | `FRESULT f_open (FIL* fp, const TCHAR* path, BYTE mode);` |
| `f_opendir` | function | `FatFs-R0.16/source/ff.h:330` | `FRESULT f_opendir (DIR* dp, const TCHAR* path);` |
| `f_printf` | function | `FatFs-R0.16/source/ff.h:355` | `int f_printf (FIL* fp, const TCHAR* str, ...);` |
| `f_putc` | function | `FatFs-R0.16/source/ff.h:353` | `int f_putc (TCHAR c, FIL* fp);` |
| `f_puts` | function | `FatFs-R0.16/source/ff.h:354` | `int f_puts (const TCHAR* str, FIL* cp);` |
| `f_read` | function | `FatFs-R0.16/source/ff.h:325` | `FRESULT f_read (FIL* fp, void* buff, UINT btr, UINT* br);` |
| `f_readdir` | function | `FatFs-R0.16/source/ff.h:332` | `FRESULT f_readdir (DIR* dp, FILINFO* fno);` |
| `f_rename` | function | `FatFs-R0.16/source/ff.h:337` | `FRESULT f_rename (const TCHAR* path_old, const TCHAR* path_new);` |
| `f_rewind` | macro | `FatFs-R0.16/source/ff.h:364` | `#define f_rewind(fp)` |
| `f_rewinddir` | macro | `FatFs-R0.16/source/ff.h:365` | `#define f_rewinddir(dp)` |
| `f_rmdir` | macro | `FatFs-R0.16/source/ff.h:366` | `#define f_rmdir(path)` |
| `f_setcp` | function | `FatFs-R0.16/source/ff.h:352` | `FRESULT f_setcp (WORD cp);` |
| `f_setlabel` | function | `FatFs-R0.16/source/ff.h:346` | `FRESULT f_setlabel (const TCHAR* label);` |
| `f_size` | macro | `FatFs-R0.16/source/ff.h:363` | `#define f_size(fp)` |
| `f_stat` | function | `FatFs-R0.16/source/ff.h:338` | `FRESULT f_stat (const TCHAR* path, FILINFO* fno);` |
| `f_sync` | function | `FatFs-R0.16/source/ff.h:329` | `FRESULT f_sync (FIL* fp);` |
| `f_tell` | macro | `FatFs-R0.16/source/ff.h:362` | `#define f_tell(fp)` |
| `f_truncate` | function | `FatFs-R0.16/source/ff.h:328` | `FRESULT f_truncate (FIL* fp);` |
| `f_unlink` | function | `FatFs-R0.16/source/ff.h:336` | `FRESULT f_unlink (const TCHAR* path);` |
| `f_unmount` | macro | `FatFs-R0.16/source/ff.h:367` | `#define f_unmount(path)` |
| `f_utime` | function | `FatFs-R0.16/source/ff.h:340` | `FRESULT f_utime (const TCHAR* path, const FILINFO* fno);` |
| `f_write` | function | `FatFs-R0.16/source/ff.h:326` | `FRESULT f_write (FIL* fp, const void* buff, UINT btw, UINT* bw);` |
| `ff_memalloc` | function | `FatFs-R0.16/source/ff.h:394` | `void* ff_memalloc (UINT msize);` |
| `ff_memfree` | function | `FatFs-R0.16/source/ff.h:395` | `void ff_memfree (void* mblock);` |
| `ff_mutex_create` | function | `FatFs-R0.16/source/ff.h:398` | `int ff_mutex_create (int vol);` |
| `ff_mutex_delete` | function | `FatFs-R0.16/source/ff.h:399` | `void ff_mutex_delete (int vol);` |
| `ff_mutex_give` | function | `FatFs-R0.16/source/ff.h:401` | `void ff_mutex_give (int vol);` |
| `ff_mutex_take` | function | `FatFs-R0.16/source/ff.h:400` | `int ff_mutex_take (int vol);` |
| `ff_oem2uni` | function | `FatFs-R0.16/source/ff.h:385` | `WCHAR ff_oem2uni (WCHAR oem, WORD cp);` |
| `ff_uni2oem` | function | `FatFs-R0.16/source/ff.h:386` | `WCHAR ff_uni2oem (DWORD uni, WORD cp);` |
| `ff_wtoupper` | function | `FatFs-R0.16/source/ff.h:387` | `DWORD ff_wtoupper (DWORD uni);` |
| `get_fattime` | function | `FatFs-R0.16/source/ff.h:378` | `DWORD get_fattime (void);` |
| `isinf` | macro | `FatFs-R0.16/source/ff.h:45` | `#define isinf(v)` |
| `isnan` | macro | `FatFs-R0.16/source/ff.h:44` | `#define isnan(v)` |
| `FFCONF_DEF` | macro | `FatFs-R0.16/source/ffconf.h:4` | `#define FFCONF_DEF` |
| `FF_CODE_PAGE` | macro | `FatFs-R0.16/source/ffconf.h:86` | `#define FF_CODE_PAGE` |
| `FF_FS_CRTIME` | macro | `FatFs-R0.16/source/ffconf.h:264` | `#define FF_FS_CRTIME` |
| `FF_FS_EXFAT` | macro | `FatFs-R0.16/source/ffconf.h:244` | `#define FF_FS_EXFAT` |
| `FF_FS_LOCK` | macro | `FatFs-R0.16/source/ffconf.h:281` | `#define FF_FS_LOCK` |
| `FF_FS_MINIMIZE` | macro | `FatFs-R0.16/source/ffconf.h:16` | `#define FF_FS_MINIMIZE` |
| `FF_FS_NOFSINFO` | macro | `FatFs-R0.16/source/ffconf.h:269` | `#define FF_FS_NOFSINFO` |
| `FF_FS_NORTC` | macro | `FatFs-R0.16/source/ffconf.h:250` | `#define FF_FS_NORTC` |
| `FF_FS_READONLY` | macro | `FatFs-R0.16/source/ffconf.h:10` | `#define FF_FS_READONLY` |
| `FF_FS_REENTRANT` | macro | `FatFs-R0.16/source/ffconf.h:293` | `#define FF_FS_REENTRANT` |
| `FF_FS_RPATH` | macro | `FatFs-R0.16/source/ffconf.h:154` | `#define FF_FS_RPATH` |
| `FF_FS_TIMEOUT` | macro | `FatFs-R0.16/source/ffconf.h:296` | `#define FF_FS_TIMEOUT` |
| `FF_FS_TINY` | macro | `FatFs-R0.16/source/ffconf.h:238` | `#define FF_FS_TINY` |
| `FF_LBA64` | macro | `FatFs-R0.16/source/ffconf.h:216` | `#define FF_LBA64` |
| `FF_LFN_BUF` | macro | `FatFs-R0.16/source/ffconf.h:146` | `#define FF_LFN_BUF` |
| `FF_LFN_UNICODE` | macro | `FatFs-R0.16/source/ffconf.h:134` | `#define FF_LFN_UNICODE` |
| `FF_MAX_LFN` | macro | `FatFs-R0.16/source/ffconf.h:117` | `#define FF_MAX_LFN` |
| `FF_MAX_SS` | macro | `FatFs-R0.16/source/ffconf.h:209` | `#define FF_MAX_SS` |
| `FF_MIN_GPT` | macro | `FatFs-R0.16/source/ffconf.h:221` | `#define FF_MIN_GPT` |
| `FF_MIN_SS` | macro | `FatFs-R0.16/source/ffconf.h:206` | `#define FF_MIN_SS` |
| `FF_MULTI_PARTITION` | macro | `FatFs-R0.16/source/ffconf.h:197` | `#define FF_MULTI_PARTITION` |
| `FF_NORTC_MDAY` | macro | `FatFs-R0.16/source/ffconf.h:254` | `#define FF_NORTC_MDAY` |
| `FF_NORTC_MON` | macro | `FatFs-R0.16/source/ffconf.h:253` | `#define FF_NORTC_MON` |
| `FF_NORTC_YEAR` | macro | `FatFs-R0.16/source/ffconf.h:255` | `#define FF_NORTC_YEAR` |
| `FF_PATH_DEPTH` | macro | `FatFs-R0.16/source/ffconf.h:163` | `#define FF_PATH_DEPTH` |
| `FF_PRINT_FLOAT` | macro | `FatFs-R0.16/source/ffconf.h:61` | `#define FF_PRINT_FLOAT` |
| `FF_PRINT_LLI` | macro | `FatFs-R0.16/source/ffconf.h:60` | `#define FF_PRINT_LLI` |
| `FF_SFN_BUF` | macro | `FatFs-R0.16/source/ffconf.h:149` | `#define FF_SFN_BUF` |
| `FF_STRF_ENCODE` | macro | `FatFs-R0.16/source/ffconf.h:62` | `#define FF_STRF_ENCODE` |
| `FF_STR_VOLUME_ID` | macro | `FatFs-R0.16/source/ffconf.h:183` | `#define FF_STR_VOLUME_ID` |
| `FF_USE_CHMOD` | macro | `FatFs-R0.16/source/ffconf.h:43` | `#define FF_USE_CHMOD` |
| `FF_USE_EXPAND` | macro | `FatFs-R0.16/source/ffconf.h:39` | `#define FF_USE_EXPAND` |
| `FF_USE_FASTSEEK` | macro | `FatFs-R0.16/source/ffconf.h:35` | `#define FF_USE_FASTSEEK` |
| `FF_USE_FIND` | macro | `FatFs-R0.16/source/ffconf.h:26` | `#define FF_USE_FIND` |
| `FF_USE_FORWARD` | macro | `FatFs-R0.16/source/ffconf.h:53` | `#define FF_USE_FORWARD` |
| `FF_USE_LABEL` | macro | `FatFs-R0.16/source/ffconf.h:48` | `#define FF_USE_LABEL` |
| `FF_USE_LFN` | macro | `FatFs-R0.16/source/ffconf.h:114` | `#define FF_USE_LFN` |
| `FF_USE_MKFS` | macro | `FatFs-R0.16/source/ffconf.h:31` | `#define FF_USE_MKFS` |
| `FF_USE_STRFUNC` | macro | `FatFs-R0.16/source/ffconf.h:57` | `#define FF_USE_STRFUNC` |
| `FF_USE_TRIM` | macro | `FatFs-R0.16/source/ffconf.h:226` | `#define FF_USE_TRIM` |
| `FF_VOLUMES` | macro | `FatFs-R0.16/source/ffconf.h:180` | `#define FF_VOLUMES` |
| `FF_VOLUME_STRS` | macro | `FatFs-R0.16/source/ffconf.h:186` | `#define FF_VOLUME_STRS` |
| `CloseHandle` | function | `FatFs-R0.16/source/ffsystem.c:125` | `CloseHandle(Mutex[vol]);` |
| `OSMutexDel` | function | `FatFs-R0.16/source/ffsystem.c:132` | `OSMutexDel(Mutex[vol], OS_DEL_ALWAYS, &err);` |
| `OSMutexPend` | function | `FatFs-R0.16/source/ffsystem.c:164` | `OSMutexPend(Mutex[vol], FF_FS_TIMEOUT, &err));` |
| `OSMutexPost` | function | `FatFs-R0.16/source/ffsystem.c:196` | `OSMutexPost(Mutex[vol]);` |
| `OS_TYPE` | macro | `FatFs-R0.16/source/ffsystem.c:41` | `#define OS_TYPE` |
| `ReleaseMutex` | function | `FatFs-R0.16/source/ffsystem.c:190` | `ReleaseMutex(Mutex[vol]);` |
| `del_mtx` | function | `FatFs-R0.16/source/ffsystem.c:128` | `del_mtx(Mutex[vol]);` |
| `ff_memalloc` | function | `FatFs-R0.16/source/ffsystem.c:15` | `void* ff_memalloc (	/* Returns pointer to the allocated memory block (null if not enough core) */...` |
| `ff_memfree` | function | `FatFs-R0.16/source/ffsystem.c:23` | `void ff_memfree (
	void* mblock	/* Pointer to the memory block to free (no effect if null) */
)` |
| `ff_mutex_create` | function | `FatFs-R0.16/source/ffsystem.c:78` | `int ff_mutex_create (	/* Returns 1:Function succeeded or 0:Could not create the mutex */
	int vol...` |
| `ff_mutex_delete` | function | `FatFs-R0.16/source/ffsystem.c:119` | `void ff_mutex_delete (	/* Returns 1:Function succeeded or 0:Could not delete due to an error */
	...` |
| `ff_mutex_give` | function | `FatFs-R0.16/source/ffsystem.c:184` | `void ff_mutex_give (
	int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (...` |
| `ff_mutex_take` | function | `FatFs-R0.16/source/ffsystem.c:151` | `int ff_mutex_take (	/* Returns 1:Succeeded or 0:Timeout */
	int vol			/* Mutex ID: Volume mutex (...` |
| `free` | function | `FatFs-R0.16/source/ffsystem.c:29` | `free(mblock);` |
| `malloc` | function | `FatFs-R0.16/source/ffsystem.c:21` | `return malloc((size_t)msize);` |
| `osMutexDef` | function | `FatFs-R0.16/source/ffsystem.c:104` | `osMutexDef(cmsis_os_mutex);` |
| `osMutexDelete` | function | `FatFs-R0.16/source/ffsystem.c:139` | `osMutexDelete(Mutex[vol]);` |
| `osMutexRelease` | function | `FatFs-R0.16/source/ffsystem.c:202` | `osMutexRelease(Mutex[vol]);` |
| `unl_mtx` | function | `FatFs-R0.16/source/ffsystem.c:193` | `unl_mtx(Mutex[vol]);` |
| `vSemaphoreDelete` | function | `FatFs-R0.16/source/ffsystem.c:136` | `vSemaphoreDelete(Mutex[vol]);` |
| `xSemaphoreGive` | function | `FatFs-R0.16/source/ffsystem.c:199` | `xSemaphoreGive(Mutex[vol]);` |
| `CVTBL` | macro | `FatFs-R0.16/source/ffunicode.c:31` | `#define CVTBL(tbl, cp)` |
| `MERGE2` | macro | `FatFs-R0.16/source/ffunicode.c:29` | `#define MERGE2(a, b)` |
| `ff_oem2uni` | function | `FatFs-R0.16/source/ffunicode.c:15243` | `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...` |
| `ff_oem2uni` | function | `FatFs-R0.16/source/ffunicode.c:15309` | `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...` |
| `ff_oem2uni` | function | `FatFs-R0.16/source/ffunicode.c:15408` | `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...` |
| `ff_uni2oem` | function | `FatFs-R0.16/source/ffunicode.c:15222` | `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...` |
| `ff_uni2oem` | function | `FatFs-R0.16/source/ffunicode.c:15275` | `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...` |
| `ff_uni2oem` | function | `FatFs-R0.16/source/ffunicode.c:15356` | `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...` |
| `ff_wtoupper` | function | `FatFs-R0.16/source/ffunicode.c:15463` | `DWORD ff_wtoupper (	/* Returns up-converted code point */
	DWORD uni		/* Unicode code point to be...` |
| `CANARY_CRC` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:42` | `#define CANARY_CRC` |
| `CANARY_VERSION` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:44` | `#define CANARY_VERSION` |
| `ESP_LOGE` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:82` | `ESP_LOGE(TAG, "opendir failed: errno=%d", errno);` |
| `ESP_LOGI` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:69` | `ESP_LOGI(TAG, "update callback completed");` |
| `FW_HDR_SIZE` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:24` | `#define FW_HDR_SIZE` |
| `LFN_GUARD_VALUE` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:45` | `#define LFN_GUARD_VALUE` |
| `MOUNT_POINT` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:22` | `#define MOUNT_POINT` |
| `OTA_READ_SLAB_SIZE` | macro | `esp32-qemu-test/app/main/fatfs_vuln_test.c:27` | `#define OTA_READ_SLAB_SIZE` |
| `__attribute__` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:54` | `__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const struct dirent *entry)` |
| `app_main` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:170` | `void app_main(void)` |
| `close` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:161` | `close(fd);` |
| `closedir` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:116` | `closedir(dir);` |
| `ctx` | type_alias | `esp32-qemu-test/app/main/fatfs_vuln_test.c:35` | `typedef struct ota_exec_region { ota_update_ctx_t ctx;` |
| `esp_vfs_fat_spiflash_unmount_ro` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:200` | `esp_vfs_fat_spiflash_unmount_ro(MOUNT_POINT, "storage");` |
| `fflush` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:204` | `fflush(stdout);` |
| `fw_header` | type_alias | `esp32-qemu-test/app/main/fatfs_vuln_test.c:28` | `typedef struct ota_update_ctx { uint8_t fw_header[FW_HDR_SIZE];` |
| `get_firmware_size` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:120` | `static long get_firmware_size(void)` |
| `legitimate_update_callback` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:66` | `static void legitimate_update_callback(void)` |
| `lfn_overflow_probe` | struct | `esp32-qemu-test/app/main/fatfs_vuln_test.c:48` | `` |
| `memset` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:93` | `memset((void *)&g_lfn_probe, 0, sizeof(g_lfn_probe));` |
| `name` | type_alias | `esp32-qemu-test/app/main/fatfs_vuln_test.c:47` | `typedef struct lfn_overflow_probe { char name[32];` |
| `ota_exec_region` | struct | `esp32-qemu-test/app/main/fatfs_vuln_test.c:36` | `` |
| `ota_update_ctx` | struct | `esp32-qemu-test/app/main/fatfs_vuln_test.c:29` | `` |
| `printf` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:202` | `printf("\n");` |
| `read_firmware_image` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:133` | `static bool read_firmware_image(int fd, size_t firmware_size)` |
| `readdir` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:76` | `* readdir() returns an attacker-controlled long filename, then application * code copies it into a fixed 32-byte stack/g` |
| `run_lfn_copy_probe` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:71` | `static bool run_lfn_copy_probe(void)` |
| `run_update_flow` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:151` | `static void run_update_flow(long attacker_fsize)` |
| `strcat` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:60` | `strcat(dst, "/");` |
| `strcpy` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:59` | `strcpy(dst, "");` |
| `unsafe_copy_dirent_name` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:103` | `unsafe_copy_dirent_name(g_lfn_probe.name, entry);` |
| `vTaskDelay` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:172` | `vTaskDelay(pdMS_TO_TICKS(100));` |
| `void` | function | `esp32-qemu-test/app/main/fatfs_vuln_test.c:33` | `void (*on_complete)(void);` |
| `do_build` | function | `esp32-qemu-test/run.sh:46` | `` |
| `do_run` | function | `esp32-qemu-test/run.sh:53` | `` |
| `do_shell` | function | `esp32-qemu-test/run.sh:63` | `` |
| `ensure_image` | function | `esp32-qemu-test/run.sh:39` | `` |
| `image_exists` | function | `esp32-qemu-test/run.sh:35` | `` |
| `usage` | function | `esp32-qemu-test/run.sh:25` | `` |
| `build_lfn_entries` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:76` | `def build_lfn_entries(long_name, short_name_11)` |
| `build_payload_sector` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:271` | `def build_payload_sector(shellcode, callback_target_addr)` |
| `build_xtensa_uart_shellcode` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:149` | `def build_xtensa_uart_shellcode()` |
| `generate_bug1_espidf_image` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:282` | `def generate_bug1_espidf_image(shellcode, callback_target_addr)` |
| `inject_into_flash` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:389` | `def inject_into_flash(flash_path, output_path, shellcode, callback_target_addr)` |
| `lfn_checksum` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:67` | `def lfn_checksum(short_name_11)` |
| `main` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:456` | `def main()` |
| `resolve_symbol_address` | function | `esp32-qemu-test/scripts/gen_exploit_image.py:115` | `def resolve_symbol_address(elf_path, symbol_name)` |
| `BuildExFATImage` | function | `fuzzer/fat_image.go:262` | `func BuildExFATImage(` |
| `BuildExFATWithLargeLabel` | function | `fuzzer/fat_image.go:354` | `func BuildExFATWithLargeLabel(` |
| `BuildFAT16` | function | `fuzzer/fat_image.go:65` | `func BuildFAT16(` |
| `BuildFAT16WithLFNFile` | function | `fuzzer/fat_image.go:451` | `func BuildFAT16WithLFNFile(` |
| `BuildFAT32` | function | `fuzzer/fat_image.go:144` | `func BuildFAT32(` |
| `BuildGPTImage` | function | `fuzzer/fat_image.go:214` | `func BuildGPTImage(` |
| `DefaultFAT16Config` | function | `fuzzer/fat_image.go:52` | `func DefaultFAT16Config(` |
| `DefaultFAT32Config` | function | `fuzzer/fat_image.go:131` | `func DefaultFAT32Config(` |
| `FAT16Config` | struct | `fuzzer/fat_image.go:41` | `` |
| `FAT16DataSector` | function | `fuzzer/fat_image.go:107` | `func FAT16DataSector(` |
| `FAT32Config` | struct | `fuzzer/fat_image.go:118` | `` |
| `MutateFAT32BPB` | function | `fuzzer/fat_image.go:303` | `func MutateFAT32BPB(` |
| `RandomMutate` | function | `fuzzer/fat_image.go:324` | `func RandomMutate(` |
| `le16` | function | `fuzzer/fat_image.go:19` | `func le16(` |
| `le32` | function | `fuzzer/fat_image.go:20` | `func le32(` |
| `le64` | function | `fuzzer/fat_image.go:21` | `func le64(` |
| `newDisk` | function | `fuzzer/fat_image.go:29` | `func newDisk(` |
| `sfnChecksum` | function | `fuzzer/fat_image.go:430` | `func sfnChecksum(` |
| `BuildFAT12Minimal` | function | `fuzzer/main.go:290` | `func BuildFAT12Minimal(` |
| `FuzzExFATNumLabel` | function | `fuzzer/main.go:449` | `func FuzzExFATNumLabel(` |
| `FuzzFAT16LFNLength` | function | `fuzzer/main.go:507` | `func FuzzFAT16LFNLength(` |
| `FuzzFAT32BPB` | function | `fuzzer/main.go:343` | `func FuzzFAT32BPB(` |
| `FuzzGPTNEnt` | function | `fuzzer/main.go:398` | `func FuzzGPTNEnt(` |
| `buildAllSeeds` | function | `fuzzer/main.go:76` | `func buildAllSeeds(` |
| `main` | function | `fuzzer/main.go:51` | `func main(` |
| `disk_initialize` | function | `harness/diskio_ramdisk.c:67` | `DSTATUS disk_initialize(BYTE pdrv)` |
| `disk_ioctl` | function | `harness/diskio_ramdisk.c:113` | `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)` |
| `disk_read` | function | `harness/diskio_ramdisk.c:74` | `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)` |
| `disk_status` | function | `harness/diskio_ramdisk.c:61` | `DSTATUS disk_status(BYTE pdrv)` |
| `disk_write` | function | `harness/diskio_ramdisk.c:94` | `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)` |
| `get_fattime` | function | `harness/diskio_ramdisk.c:136` | `DWORD get_fattime(void)` |
| `memcpy` | function | `harness/diskio_ramdisk.c:50` | `memcpy(ramdisk, image, bytes);` |
| `memset` | function | `harness/diskio_ramdisk.c:49` | `memset(ramdisk, 0, sizeof(ramdisk));` |
| `ramdisk_eject` | function | `harness/diskio_ramdisk.c:55` | `void ramdisk_eject(void)` |
| `ramdisk_load` | function | `harness/diskio_ramdisk.c:46` | `void ramdisk_load(const BYTE *image, UINT size)` |
| `ramdisk_reset_stats` | function | `harness/diskio_ramdisk.c:34` | `void ramdisk_reset_stats(void)` |
| `DISKIO_RAMDISK_H` | macro | `harness/diskio_ramdisk.h:6` | `#define DISKIO_RAMDISK_H` |
| `RAMDISK_SECTOR_COUNT` | macro | `harness/diskio_ramdisk.h:14` | `#define RAMDISK_SECTOR_COUNT` |
| `RAMDISK_SECTOR_SIZE` | macro | `harness/diskio_ramdisk.h:12` | `#define RAMDISK_SECTOR_SIZE` |
| `RAMDISK_SIZE_BYTES` | macro | `harness/diskio_ramdisk.h:15` | `#define RAMDISK_SIZE_BYTES` |
| `ramdisk` | variable | `harness/diskio_ramdisk.h:18` | `extern BYTE ramdisk[RAMDISK_SECTOR_COUNT * RAMDISK_SECTOR_SIZE];` |
| `ramdisk_eject` | function | `harness/diskio_ramdisk.h:34` | `void ramdisk_eject(void);` |
| `ramdisk_load` | function | `harness/diskio_ramdisk.h:31` | `void ramdisk_load(const BYTE *image, UINT size);` |
| `ramdisk_read_count` | variable | `harness/diskio_ramdisk.h:22` | `extern volatile uint32_t ramdisk_read_count;` |
| `ramdisk_reset_stats` | function | `harness/diskio_ramdisk.h:25` | `void ramdisk_reset_stats(void);` |
| `ramdisk_write_count` | variable | `harness/diskio_ramdisk.h:24` | `extern volatile uint32_t ramdisk_write_count;` |
| `B4_BYTES_PER_SEC` | macro | `harness/exploit_disks.c:592` | `#define B4_BYTES_PER_SEC` |
| `B4_CLUS2SEC` | macro | `harness/exploit_disks.c:604` | `#define B4_CLUS2SEC(c)` |
| `B4_DATA_OFFSET_SECS` | macro | `harness/exploit_disks.c:603` | `#define B4_DATA_OFFSET_SECS` |
| `B4_FAT_OFFSET_SECS` | macro | `harness/exploit_disks.c:601` | `#define B4_FAT_OFFSET_SECS(n)` |
| `B4_FAT_SIZE_SECS` | macro | `harness/exploit_disks.c:597` | `#define B4_FAT_SIZE_SECS` |
| `B4_N_FATS` | macro | `harness/exploit_disks.c:595` | `#define B4_N_FATS` |
| `B4_RESERVED_SECS` | macro | `harness/exploit_disks.c:594` | `#define B4_RESERVED_SECS` |
| `B4_ROOT_DIR_SECS` | macro | `harness/exploit_disks.c:599` | `#define B4_ROOT_DIR_SECS` |
| `B4_ROOT_ENTRIES` | macro | `harness/exploit_disks.c:596` | `#define B4_ROOT_ENTRIES` |
| `B4_ROOT_OFFSET_SECS` | macro | `harness/exploit_disks.c:602` | `#define B4_ROOT_OFFSET_SECS` |
| `B4_SEC_PER_CLUS` | macro | `harness/exploit_disks.c:593` | `#define B4_SEC_PER_CLUS` |
| `B4_SYS_SECS` | macro | `harness/exploit_disks.c:600` | `#define B4_SYS_SECS` |
| `B4_TOT_SECS` | macro | `harness/exploit_disks.c:598` | `#define B4_TOT_SECS` |
| `B5_CLUS2SEC` | macro | `harness/exploit_disks.c:739` | `#define B5_CLUS2SEC(c)` |
| `B5_SECRET` | macro | `harness/exploit_disks.c:740` | `#define B5_SECRET` |
| `B5_SEC_PER_CLUS` | macro | `harness/exploit_disks.c:738` | `#define B5_SEC_PER_CLUS` |
| `B5_WRITE_SIZE` | macro | `harness/exploit_disks.c:741` | `#define B5_WRITE_SIZE` |
| `FAIL` | macro | `harness/exploit_disks.c:110` | `#define FAIL(label)` |
| `FAIL` | function | `harness/exploit_disks.c:262` | `FAIL(filename);` |
| `IMG_DIR` | macro | `harness/exploit_disks.c:94` | `#define IMG_DIR` |
| `INFO` | macro | `harness/exploit_disks.c:107` | `#define INFO(fmt, ...)` |
| `INFO` | function | `harness/exploit_disks.c:261` | `INFO("f_mount returned %d (expected FR_OK=0)", (int)res);` |
| `MicroPython` | function | `harness/exploit_disks.c:498` | `*                            MicroPython (if the port enables FF_LBA64)
 *
 * R0.16 fix:  test_gp...` |
| `PASS` | macro | `harness/exploit_disks.c:109` | `#define PASS(label)` |
| `PASS` | function | `harness/exploit_disks.c:284` | `PASS(filename);` |
| `Payload` | function | `harness/exploit_disks.c:293` | `*   Payload (sector 8): placeholder address 0xDEADBEEFCAFEBABE
 *   Simulates: embedded OTA reade...` |
| `SKIP` | macro | `harness/exploit_disks.c:111` | `#define SKIP(label)` |
| `Zephyr` | function | `harness/exploit_disks.c:836` | `*                     Zephyr (R0.16), ArduPilot (R0.14b),
 *                     RIOT-OS (R0.15),...` |
| `bug1_build` | function | `harness/exploit_disks.c:241` | `static uint8_t *bug1_build(uint32_t file_size,
                            const uint8_t *payload...` |
| `bug1_fill_payload` | function | `harness/exploit_disks.c:227` | `static void bug1_fill_payload(uint8_t *disk,
                               const uint8_t *payloa...` |
| `bug1_plant_dir_entry` | function | `harness/exploit_disks.c:249` | `bug1_plant_dir_entry(disk, fname8, ext3, file_size, 4);` |
| `bug1_verify` | function | `harness/exploit_disks.c:255` | `static int bug1_verify(uint8_t *disk, const char *filename)` |
| `bug1_write_vbr` | function | `harness/exploit_disks.c:156` | `static void bug1_write_vbr(uint8_t *disk)` |
| `bug2_write_vbr` | function | `harness/exploit_disks.c:469` | `bug2_write_vbr(disk, 0);` |
| `bug4_set_fat16_entry` | function | `harness/exploit_disks.c:637` | `static void bug4_set_fat16_entry(uint8_t *disk, uint16_t cluster, uint16_t value)` |
| `bug4_write_fat16_base` | function | `harness/exploit_disks.c:660` | `bug4_write_fat16_base(disk);` |
| `bug6_build_exfat_label` | function | `harness/exploit_disks.c:942` | `bug6_build_exfat_label(disk, 128);` |
| `bug6_verify_overflow` | function | `harness/exploit_disks.c:892` | `static int bug6_verify_overflow(uint8_t *disk, const char *imgname,
                             ...` |
| `bug7_build` | function | `harness/exploit_disks.c:1006` | `static void bug7_build(uint8_t *disk, int lfn_len, uint16_t dirent_name_size)` |
| `bug7_verify` | function | `harness/exploit_disks.c:1059` | `static int bug7_verify(uint8_t *disk, const char *imgname, int expected_lfn_len)` |
| `cc` | function | `harness/exploit_disks.c:673` | `* if cc (sectors remaining) is also large, 0xFFFFFFFC < cc → TRUE * → memcpy fires at offset 0xFFFFFFFC * 512 (out of bo` |
| `chain` | function | `harness/exploit_disks.c:576` | `*   An application writes 64 bytes to the END of cluster chain (fp->sect = X,
 *   FA_DIRTY set),...` |
| `code` | function | `harness/exploit_disks.c:563` | `* * Vulnerable code (ff.c non-tiny path, f_read multi-sector branch): * disk_read(pdrv, rbuff, sect, cc);` |
| `exploit_disks` | function | `harness/exploit_disks.c:49` | `*   make exploit_disks            (see Makefile target)
 *
 * Expected output:
 *   Generating 14...` |
| `f_close` | function | `harness/exploit_disks.c:788` | `f_close(&fp);` |
| `f_closedir` | function | `harness/exploit_disks.c:1072` | `f_closedir(&dj);` |
| `f_mount` | function | `harness/exploit_disks.c:263` | `f_mount(NULL, "0:", 0);` |
| `f_opendir` | function | `harness/exploit_disks.c:1245` | `f_opendir(&dj, "0:/");` |
| `f_read` | function | `harness/exploit_disks.c:795` | `f_read(&fp, rbuf, lseek_target, &br);` |
| `f_sync` | function | `harness/exploit_disks.c:787` | `f_sync(&fp);` |
| `fclose` | function | `harness/exploit_disks.c:123` | `fclose(f);` |
| `free` | function | `harness/exploit_disks.c:306` | `free(disk);` |
| `gen_bug1_ardupilot` | function | `harness/exploit_disks.c:382` | `static void gen_bug1_ardupilot(void)` |
| `gen_bug1_espidf` | function | `harness/exploit_disks.c:317` | `static void gen_bug1_espidf(void)` |
| `gen_bug1_fat32` | function | `harness/exploit_disks.c:1288` | `gen_bug1_fat32();` |
| `gen_bug1_keystone3` | function | `harness/exploit_disks.c:359` | `static void gen_bug1_keystone3(void)` |
| `gen_bug1_stm32` | function | `harness/exploit_disks.c:338` | `static void gen_bug1_stm32(void)` |
| `gen_bug2_exfat` | function | `harness/exploit_disks.c:455` | `static void gen_bug2_exfat(void)` |
| `gen_bug3_gpt` | function | `harness/exploit_disks.c:1298` | `gen_bug3_gpt();` |
| `gen_bug4_fragmented` | function | `harness/exploit_disks.c:647` | `static void gen_bug4_fragmented(void)` |
| `gen_bug5_stale` | function | `harness/exploit_disks.c:1304` | `gen_bug5_stale();` |
| `gen_bug6_stm32` | function | `harness/exploit_disks.c:932` | `static void gen_bug6_stm32(void)` |
| `gen_bug6_zephyr` | function | `harness/exploit_disks.c:947` | `static void gen_bug6_zephyr(void)` |
| `gen_bug7_grblhal` | function | `harness/exploit_disks.c:1313` | `gen_bug7_grblhal();` |
| `gen_bug7_max255` | function | `harness/exploit_disks.c:1095` | `static void gen_bug7_max255(void)` |
| `gen_bug7_zephyr` | function | `harness/exploit_disks.c:1111` | `static void gen_bug7_zephyr(void)` |
| `layout` | function | `harness/exploit_disks.c:989` | `*
 * Directory layout (FAT16):
 *   Entries in order: LFN entries (N × 32 bytes) then 8.3 SFN ent...` |
| `load_ramdisk` | function | `harness/exploit_disks.c:128` | `static void load_ramdisk(const uint8_t *buf, size_t sz)` |
| `main` | function | `harness/exploit_disks.c:1273` | `int main(void)` |
| `memcpy` | function | `harness/exploit_disks.c:160` | `memcpy(&vbr[3], "MSDOS5.0", 8);` |
| `memset` | function | `harness/exploit_disks.c:211` | `memset(dir6, 0, 512);` |
| `perror` | function | `harness/exploit_disks.c:1277` | `perror("mkdir " IMG_DIR);` |
| `printf` | function | `harness/exploit_disks.c:125` | `printf(" [IMG] %s (%zu bytes)\n", path, sz);` |
| `ramdisk_load` | function | `harness/exploit_disks.c:131` | `ramdisk_load(buf, (UINT)sz);` |
| `ramdisk_reset_stats` | function | `harness/exploit_disks.c:544` | `ramdisk_reset_stats();` |
| `save_image` | function | `harness/exploit_disks.c:116` | `static int save_image(const char *name, const uint8_t *buf, size_t sz)` |
| `snprintf` | function | `harness/exploit_disks.c:119` | `snprintf(path, sizeof(path), IMG_DIR "/%s", name);` |
| `st16le` | function | `harness/exploit_disks.c:161` | `st16le(&vbr[11], 512);` |
| `st32le` | function | `harness/exploit_disks.c:99` | `static inline void st32le(uint8_t *p, uint32_t v)` |
| `st64le` | function | `harness/exploit_disks.c:102` | `static inline void st64le(uint8_t *p, uint64_t v)` |
| `ff_uni2oem` | function | `harness/ffunicode_stub.c:5` | `* ff_uni2oem() and ff_wtoupper() which normally come from ffunicode.c.
 * These stubs are suffici...` |
| `ff_uni2oem` | function | `harness/ffunicode_stub.c:17` | `WCHAR ff_uni2oem(DWORD uni, WORD cp)` |
| `ff_wtoupper` | function | `harness/ffunicode_stub.c:25` | `DWORD ff_wtoupper(DWORD chr)` |
| `LLVMFuzzerTestOneInput` | function | `harness/libfuzzer_harness.c:140` | `LLVMFuzzerTestOneInput(buf, (size_t)sz);` |
| `Usage` | function | `harness/libfuzzer_harness.c:9` | `*
 * Usage (libFuzzer):
 *   ./fuzz_fatfs -max_len=2097152 corpus/
 *
 * Usage (AFL++):
 *   afl-...` |
| `f_close` | function | `harness/libfuzzer_harness.c:114` | `f_close(&fp);` |
| `f_closedir` | function | `harness/libfuzzer_harness.c:75` | `f_closedir(&dj);` |
| `f_getlabel` | function | `harness/libfuzzer_harness.c:61` | `f_getlabel("0:", label_buf, NULL);` |
| `f_lseek` | function | `harness/libfuzzer_harness.c:106` | `f_lseek(&fp, mid);` |
| `f_mount` | function | `harness/libfuzzer_harness.c:119` | `done: f_mount(NULL, "0:", 0);` |
| `f_read` | function | `harness/libfuzzer_harness.c:102` | `f_read(&fp, buf, sizeof(buf), &br);` |
| `fclose` | function | `harness/libfuzzer_harness.c:139` | `fclose(f);` |
| `fread` | function | `harness/libfuzzer_harness.c:138` | `fread(buf, 1, (size_t)sz, f);` |
| `free` | function | `harness/libfuzzer_harness.c:62` | `free(label_buf);` |
| `fseek` | function | `harness/libfuzzer_harness.c:133` | `fseek(f, 0, SEEK_END);` |
| `main` | function | `harness/libfuzzer_harness.c:128` | `int main(int argc, char **argv)` |
| `memcpy` | function | `harness/libfuzzer_harness.c:92` | `memcpy(path, "0:/", 3);` |
| `memset` | function | `harness/libfuzzer_harness.c:45` | `memset(&fs, 0, sizeof(fs));` |
| `ramdisk_load` | function | `harness/libfuzzer_harness.c:42` | `ramdisk_load((const BYTE *)data, (UINT)size);` |
| `strncat` | function | `harness/libfuzzer_harness.c:94` | `strncat(path, fno.fname, sizeof(path) - sizeof("0:/"));` |
| `Build` | function | `harness/rce_demo.c:45` | `*
 * Build (without sanitisers, without stack protector — lets the overflow
 * reach the function...` |
| `FW_HDR_SIZE` | macro | `harness/rce_demo.c:95` | `#define FW_HDR_SIZE` |
| `__attribute__` | function | `harness/rce_demo.c:131` | `__attribute__((noinline))
static void rce_win(void)` |
| `assert` | function | `harness/rce_demo.c:394` | `assert(sizeof(void *) == 8 && "Demo assumes LP64 — adjust FW_HDR_SIZE or struct if needed");` |
| `build_exploit_image` | function | `harness/rce_demo.c:232` | `static void build_exploit_image(uint8_t *disk, size_t disk_bytes,
                               ...` |
| `f_close` | function | `harness/rce_demo.c:197` | `f_close(&fp);` |
| `f_mount` | function | `harness/rce_demo.c:465` | `f_mount(NULL, "0:", 0);` |
| `fasize` | function | `harness/rce_demo.c:258` | `* fasize (DWORD) = 0x80000001 * 2 = 0x100000002 → truncates to 2 * sysect = 4 + 2 + 0 = 6 → database = sector 6 (inside ` |
| `fclose` | function | `harness/rce_demo.c:353` | `fclose(f);` |
| `fprintf` | function | `harness/rce_demo.c:355` | `fprintf(stderr, "save_image: short write %zu / %zu\n", written, sz);` |
| `fw_header` | type_alias | `harness/rce_demo.c:97` | `typedef struct ota_ctx { uint8_t fw_header[FW_HDR_SIZE];` |
| `load_image` | function | `harness/rce_demo.c:363` | `static int load_image(const char *path)` |
| `main` | function | `harness/rce_demo.c:380` | `int main(void)` |
| `memcpy` | function | `harness/rce_demo.c:241` | `memcpy(&vbr[3], "MSDOS5.0", 8);` |
| `memset` | function | `harness/rce_demo.c:158` | `memset(&ctx, 0, sizeof(ctx));` |
| `ota_ctx` | struct | `harness/rce_demo.c:98` | `` |
| `printf` | function | `harness/rce_demo.c:160` | `printf(" [OTA] ctx at %p\n", (void *)&ctx);` |
| `puts` | function | `harness/rce_demo.c:125` | `puts(" [on_apply] safe_update_complete() — normal path");` |
| `ramdisk_load` | function | `harness/rce_demo.c:371` | `ramdisk_load(buf, (UINT)n);` |
| `safe_update_complete` | function | `harness/rce_demo.c:123` | `static void safe_update_complete(void)` |
| `save_image` | function | `harness/rce_demo.c:348` | `static int save_image(const char *path, const uint8_t *disk, size_t sz)` |
| `st16le` | function | `harness/rce_demo.c:242` | `st16le(&vbr[11], 512);` |
| `st32le` | function | `harness/rce_demo.c:73` | `static inline void st32le(uint8_t *p, uint32_t v)` |
| `st64le` | function | `harness/rce_demo.c:76` | `static inline void st64le(uint8_t *p, uint64_t v)` |
| `void` | function | `harness/rce_demo.c:102` | `void (*on_apply)(void);` |
| `vulnerable_ota_check` | function | `harness/rce_demo.c:155` | `static void vulnerable_ota_check(void)` |
| `FFCONF_DEF` | macro | `harness/test_ffconf.h:25` | `#define FFCONF_DEF` |
| `FF_CODE_PAGE` | macro | `harness/test_ffconf.h:43` | `#define FF_CODE_PAGE` |
| `FF_FS_CRTIME` | macro | `harness/test_ffconf.h:70` | `#define FF_FS_CRTIME` |
| `FF_FS_EXFAT` | macro | `harness/test_ffconf.h:65` | `#define FF_FS_EXFAT` |
| `FF_FS_LOCK` | macro | `harness/test_ffconf.h:72` | `#define FF_FS_LOCK` |
| `FF_FS_MINIMIZE` | macro | `harness/test_ffconf.h:29` | `#define FF_FS_MINIMIZE` |
| `FF_FS_NOFSINFO` | macro | `harness/test_ffconf.h:71` | `#define FF_FS_NOFSINFO` |
| `FF_FS_NORTC` | macro | `harness/test_ffconf.h:66` | `#define FF_FS_NORTC` |
| `FF_FS_READONLY` | macro | `harness/test_ffconf.h:28` | `#define FF_FS_READONLY` |
| `FF_FS_REENTRANT` | macro | `harness/test_ffconf.h:73` | `#define FF_FS_REENTRANT` |
| `FF_FS_RPATH` | macro | `harness/test_ffconf.h:49` | `#define FF_FS_RPATH` |
| `FF_FS_TINY` | macro | `harness/test_ffconf.h:64` | `#define FF_FS_TINY` |
| `FF_LBA64` | macro | `harness/test_ffconf.h:59` | `#define FF_LBA64` |
| `FF_LFN_BUF` | macro | `harness/test_ffconf.h:47` | `#define FF_LFN_BUF` |
| `FF_LFN_UNICODE` | macro | `harness/test_ffconf.h:46` | `#define FF_LFN_UNICODE` |
| `FF_MAX_LFN` | macro | `harness/test_ffconf.h:45` | `#define FF_MAX_LFN` |
| `FF_MAX_SS` | macro | `harness/test_ffconf.h:58` | `#define FF_MAX_SS` |
| `FF_MIN_GPT` | macro | `harness/test_ffconf.h:60` | `#define FF_MIN_GPT` |
| `FF_MIN_SS` | macro | `harness/test_ffconf.h:57` | `#define FF_MIN_SS` |
| `FF_MULTI_PARTITION` | macro | `harness/test_ffconf.h:56` | `#define FF_MULTI_PARTITION` |
| `FF_NORTC_MDAY` | macro | `harness/test_ffconf.h:68` | `#define FF_NORTC_MDAY` |
| `FF_NORTC_MON` | macro | `harness/test_ffconf.h:67` | `#define FF_NORTC_MON` |
| `FF_NORTC_YEAR` | macro | `harness/test_ffconf.h:69` | `#define FF_NORTC_YEAR` |
| `FF_PATH_DEPTH` | macro | `harness/test_ffconf.h:50` | `#define FF_PATH_DEPTH` |
| `FF_PRINT_FLOAT` | macro | `harness/test_ffconf.h:39` | `#define FF_PRINT_FLOAT` |
| `FF_PRINT_LLI` | macro | `harness/test_ffconf.h:38` | `#define FF_PRINT_LLI` |
| `FF_SFN_BUF` | macro | `harness/test_ffconf.h:48` | `#define FF_SFN_BUF` |
| `FF_STRF_ENCODE` | macro | `harness/test_ffconf.h:40` | `#define FF_STRF_ENCODE` |
| `FF_STR_VOLUME_ID` | macro | `harness/test_ffconf.h:54` | `#define FF_STR_VOLUME_ID` |
| `FF_USE_CHMOD` | macro | `harness/test_ffconf.h:34` | `#define FF_USE_CHMOD` |
| `FF_USE_EXPAND` | macro | `harness/test_ffconf.h:33` | `#define FF_USE_EXPAND` |
| `FF_USE_FASTSEEK` | macro | `harness/test_ffconf.h:32` | `#define FF_USE_FASTSEEK` |
| `FF_USE_FIND` | macro | `harness/test_ffconf.h:30` | `#define FF_USE_FIND` |
| `FF_USE_FORWARD` | macro | `harness/test_ffconf.h:36` | `#define FF_USE_FORWARD` |
| `FF_USE_LABEL` | macro | `harness/test_ffconf.h:35` | `#define FF_USE_LABEL` |
| `FF_USE_LFN` | macro | `harness/test_ffconf.h:44` | `#define FF_USE_LFN` |
| `FF_USE_MKFS` | macro | `harness/test_ffconf.h:31` | `#define FF_USE_MKFS` |
| `FF_USE_STRFUNC` | macro | `harness/test_ffconf.h:37` | `#define FF_USE_STRFUNC` |
| `FF_USE_TRIM` | macro | `harness/test_ffconf.h:61` | `#define FF_USE_TRIM` |
| `FF_VOLUMES` | macro | `harness/test_ffconf.h:53` | `#define FF_VOLUMES` |
| `FF_VOLUME_STRS` | macro | `harness/test_ffconf.h:55` | `#define FF_VOLUME_STRS` |
| `TEST_FFCONF_H` | macro | `harness/test_ffconf.h:22` | `#define TEST_FFCONF_H` |
| `B7_FILE_SIZE` | macro | `harness/test_harness.c:1103` | `#define B7_FILE_SIZE` |
| `B7_LFN_LEN` | macro | `harness/test_harness.c:1102` | `#define B7_LFN_LEN` |
| `F16_BYTES_PER_SEC` | macro | `harness/test_harness.c:703` | `#define F16_BYTES_PER_SEC` |
| `F16_CLUS2SEC` | macro | `harness/test_harness.c:717` | `#define F16_CLUS2SEC(c)` |
| `F16_DATA_OFFSET_SECS` | macro | `harness/test_harness.c:716` | `#define F16_DATA_OFFSET_SECS` |
| `F16_FAT_OFFSET_SECS` | macro | `harness/test_harness.c:714` | `#define F16_FAT_OFFSET_SECS(n)` |
| `F16_FAT_SIZE_SECS` | macro | `harness/test_harness.c:708` | `#define F16_FAT_SIZE_SECS` |
| `F16_N_FATS` | macro | `harness/test_harness.c:706` | `#define F16_N_FATS` |
| `F16_RESERVED_SECS` | macro | `harness/test_harness.c:705` | `#define F16_RESERVED_SECS` |
| `F16_ROOT_DIR_SECS` | macro | `harness/test_harness.c:710` | `#define F16_ROOT_DIR_SECS` |
| `F16_ROOT_ENTRIES` | macro | `harness/test_harness.c:707` | `#define F16_ROOT_ENTRIES` |
| `F16_ROOT_OFFSET_SECS` | macro | `harness/test_harness.c:715` | `#define F16_ROOT_OFFSET_SECS` |
| `F16_SEC_PER_CLUS` | macro | `harness/test_harness.c:704` | `#define F16_SEC_PER_CLUS` |
| `F16_SYS_SECS` | macro | `harness/test_harness.c:712` | `#define F16_SYS_SECS` |
| `F16_TOT_SECS` | macro | `harness/test_harness.c:709` | `#define F16_TOT_SECS` |
| `INFO` | macro | `harness/test_harness.c:83` | `#define INFO(fmt, ...)` |
| `INFO` | function | `harness/test_harness.c:193` | `INFO("f_mount() returned %d (FR_OK=0, FR_NO_FILESYSTEM=13)", (int)res);` |
| `LSEEK_TARGET` | macro | `harness/test_harness.c:780` | `#define LSEEK_TARGET` |
| `MCUs` | function | `harness/test_harness.c:261` | `*    common on embedded MCUs (STM32, RP2040, ESP32, …).  The resulting call
 *    invokes rce_pro...` |
| `RESULT` | macro | `harness/test_harness.c:77` | `#define RESULT(label, cond)` |
| `RESULT` | function | `harness/test_harness.c:197` | `RESULT("CVE-2026-6682 FAT32 integer overflow", 0);` |
| `SECRET_PATTERN` | macro | `harness/test_harness.c:774` | `#define SECRET_PATTERN` |
| `WRITE_SIZE` | macro | `harness/test_harness.c:779` | `#define WRITE_SIZE` |
| `__attribute__` | function | `harness/test_harness.c:763` | `__attribute__((unused))
static void fat16_set_chain(BYTE *disk, uint16_t cluster, uint16_t next)` |
| `buffers` | function | `harness/test_harness.c:36` | `*         buffers (e.g. char path[16]) and unchecked string copies
 *         (sprintf, strcat) o...` |
| `build_exfat_large_label` | function | `harness/test_harness.c:1007` | `build_exfat_large_label(image, sizeof(image), 128);` |
| `build_fat16_base` | function | `harness/test_harness.c:725` | `static void build_fat16_base(BYTE *disk, size_t disk_bytes)` |
| `build_fat16_with_lfn` | function | `harness/test_harness.c:1104` | `static void build_fat16_with_lfn(BYTE *disk, size_t disk_bytes)` |
| `build_fat32_bug1` | function | `harness/test_harness.c:120` | `static void build_fat32_bug1(BYTE *disk, size_t disk_bytes)` |
| `build_fat32_rce_image` | function | `harness/test_harness.c:355` | `build_fat32_rce_image(image, sizeof(image), target);` |
| `build_gpt_image` | function | `harness/test_harness.c:459` | `static void build_gpt_image(BYTE *disk, size_t disk_bytes, uint32_t n_ent)` |
| `byte` | function | `harness/test_harness.c:1023` | `* sentinel byte (0xC3) so that any write beyond offset 24 is visible. * * f_getlabel must receive a pointer to byte 0 of` |
| `code` | function | `harness/test_harness.c:88` | `* * Vulnerable code (ff.c ~line 3600): * * fasize = ld_16(fs->win + BPB_FATSz16);` |
| `f_close` | function | `harness/test_harness.c:404` | `f_close(&fp);` |
| `f_closedir` | function | `harness/test_harness.c:1194` | `f_closedir(&dj);` |
| `f_mount` | function | `harness/test_harness.c:226` | `f_mount(NULL, "0:", 0);` |
| `f_sync` | function | `harness/test_harness.c:837` | `f_sync(&fp);` |
| `fn` | function | `harness/test_harness.c:418` | `fn();` |
| `free` | function | `harness/test_harness.c:831` | `free(payload);` |
| `layout` | function | `harness/test_harness.c:693` | `*
 * Disk layout (FAT16, 4 sectors/cluster):
 *   Sectors  0           VBR
 *   Sectors  1-4     ...` |
| `main` | function | `harness/test_harness.c:1257` | `int main(void)` |
| `memcpy` | function | `harness/test_harness.c:129` | `memcpy(&vbr[3], "MSDOS5.0", 8);` |
| `memset` | function | `harness/test_harness.c:123` | `memset(disk, 0, disk_bytes);` |
| `move_window` | function | `harness/test_harness.c:435` | `* move_window(fs, pt_lba + i * SZ_GPTE / SS(fs));` |
| `pass` | function | `harness/test_harness.c:927` | `*      or pass (sizeof_label - di) instead of the hard-coded 4.
 *===============================...` |
| `printf` | function | `harness/test_harness.c:182` | `printf("\n[CVE-2026-6682] FAT32 sector-count integer overflow in mount_volume()\n");` |
| `ramdisk_load` | function | `harness/test_harness.c:188` | `ramdisk_load(image, sizeof(image));` |
| `ramdisk_reset_stats` | function | `harness/test_harness.c:529` | `ramdisk_reset_stats();` |
| `rce_proof_of_execution` | function | `harness/test_harness.c:119` | `static void rce_proof_of_execution(void)` |
| `releases` | function | `harness/test_harness.c:509` | `*
 * Historical note: older FatFs releases (before test_gpt_header was
 * introduced) had no such...` |
| `sfn_checksum_b7` | function | `harness/test_harness.c:1090` | `static BYTE sfn_checksum_b7(const BYTE sfn[11])` |
| `sprintf` | function | `harness/test_harness.c:1075` | `* sprintf(path, "0:/%s", fno.fname);` |
| `st16le` | function | `harness/test_harness.c:130` | `st16le(&vbr[11], 512);` |
| `st32le` | function | `harness/test_harness.c:65` | `static inline void st32le(BYTE *p, uint32_t v)` |
| `st64le` | function | `harness/test_harness.c:70` | `static inline void st64le(BYTE *p, uint64_t v)` |
| `strcat` | function | `harness/test_harness.c:1213` | `* strcat(path, fno.fname);` |
| `strcpy` | function | `harness/test_harness.c:1078` | `* strcpy(fname, fno.fname);` |
| `test_bug1_rce_exploit` | function | `harness/test_harness.c:338` | `static int test_bug1_rce_exploit(void)` |
| `test_bug4_stale_cache_skip` | function | `harness/test_harness.c:601` | `static int test_bug4_stale_cache_skip(void)` |
| `test_bug5_infoleak_lseek` | function | `harness/test_harness.c:781` | `static int test_bug5_infoleak_lseek(void)` |
| `test_bug6_getlabel_exfat_overflow` | function | `harness/test_harness.c:998` | `static int test_bug6_getlabel_exfat_overflow(void)` |
| `test_bug7_lfn_path_overflow` | function | `harness/test_harness.c:1156` | `static int test_bug7_lfn_path_overflow(void)` |
| `truncated` | function | `harness/test_harness.c:146` | `* truncated (DWORD) → 0x00000002 * * sysect = 4 (reserved) + 2 (fake fasize) + 0 (no root) = 6 * * fs->database = bsect(` |
| `write_fat16_entry` | function | `harness/test_harness.c:769` | `write_fat16_entry(fat, cluster, next);` |
