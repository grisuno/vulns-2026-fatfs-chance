# Symbols (page 1 of 2)
Pages: [SYMBOLS.md](SYMBOLS.md), [SYMBOLS_p2.md](SYMBOLS_p2.md)

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `main` | function | `FatFs-R0.16/documents/res/app1.c:25` | `int main (void)` |
| `open_append` | function | `FatFs-R0.16/documents/res/app1.c:6` | `FRESULT open_append (     FIL* fp,            /* [OUT] File object to create */     const char* p...` |
| `delete_node` | function | `FatFs-R0.16/documents/res/app2.c:9` | `FRESULT delete_node (     TCHAR* path,    /* Path name buffer with the sub-directory to delete */...` |
| `allocate_contiguous_clusters` | function | `FatFs-R0.16/documents/res/app3.c:20` | `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:error or not contig...` |
| `main` | function | `FatFs-R0.16/documents/res/app3.c:78` | `int main (void)` |
| `main` | function | `FatFs-R0.16/documents/res/app4.c:299` | `int main (int argc, char* argv[])` |
| `pn` | function | `FatFs-R0.16/documents/res/app4.c:14` | `static DWORD pn (       /* Pseudo random number generator */     DWORD pns   /* 0:Initialize, !0:...` |
| `test_diskio` | function | `FatFs-R0.16/documents/res/app4.c:36` | `int test_diskio (     BYTE pdrv,      /* Physical drive number to be checked (all data on the dri...` |
| `test_contiguous_file` | function | `FatFs-R0.16/documents/res/app5.c:5` | `FRESULT test_contiguous_file (     FIL* fp,    /* [IN]  Open file object to be checked */     int...` |
| `test_raw_speed` | function | `FatFs-R0.16/documents/res/app6.c:11` | `int test_raw_speed (     BYTE pdrv,      /* Physical drive number */     DWORD lba,      /* Start...` |
| `DEV_FLASH` | macro | `FatFs-R0.16/source/diskio.c:18` | `#define DEV_FLASH` |
| `DEV_MMC` | macro | `FatFs-R0.16/source/diskio.c:19` | `#define DEV_MMC` |
| `DEV_USB` | macro | `FatFs-R0.16/source/diskio.c:20` | `#define DEV_USB` |
| `disk_initialize` | function | `FatFs-R0.16/source/diskio.c:65` | `DSTATUS disk_initialize ( 	BYTE pdrv				/* Physical drive nmuber to identify the drive */ )` |
| `disk_ioctl` | function | `FatFs-R0.16/source/diskio.c:202` | `DRESULT disk_ioctl ( 	BYTE pdrv,		/* Physical drive nmuber (0..) */ 	BYTE cmd,		/* Control code *...` |
| `disk_read` | function | `FatFs-R0.16/source/diskio.c:103` | `DRESULT disk_read ( 	BYTE pdrv,		/* Physical drive nmuber to identify the drive */ 	BYTE *buff,		...` |
| `disk_status` | function | `FatFs-R0.16/source/diskio.c:27` | `DSTATUS disk_status ( 	BYTE pdrv		/* Physical drive nmuber to identify the drive */ )` |
| `disk_write` | function | `FatFs-R0.16/source/diskio.c:153` | `DRESULT disk_write ( 	BYTE pdrv,			/* Physical drive nmuber to identify the drive */ 	const BYTE ...` |
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
| `STA_NOINIT` | macro | `FatFs-R0.16/source/diskio.h:38` | `#define STA_NOINIT` |
| `STA_PROTECT` | macro | `FatFs-R0.16/source/diskio.h:40` | `#define STA_PROTECT` |
| `_DISKIO_DEFINED` | macro | `FatFs-R0.16/source/diskio.h:6` | `#define _DISKIO_DEFINED` |
| `ABORT` | macro | `FatFs-R0.16/source/ff.c:234` | `#define ABORT(fs, res)` |
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
| `BPB_FATSz32` | macro | `FatFs-R0.16/source/ff.c:117` | `#define BPB_FATSz32` |
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
| `BPB_ZeroedEx` | macro | `FatFs-R0.16/source/ff.c:131` | `#define BPB_ZeroedEx` |
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
| `BS_JmpBoot` | macro | `FatFs-R0.16/source/ff.c:94` | `#define BS_JmpBoot` |
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
| `DIR_Name` | macro | `FatFs-R0.16/source/ff.c:150` | `#define DIR_Name` |
| `DIR_READ_FILE` | macro | `FatFs-R0.16/source/ff.c:2331` | `#define DIR_READ_FILE(dp)` |
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
| `FIND_RECURS` | macro | `FatFs-R0.16/source/ff.c:2804` | `#define FIND_RECURS` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:504` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:527` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:534` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:538` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:546` | `#define FREE_NAMEBUFF()` |
| `FREE_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:550` | `#define FREE_NAMEBUFF()` |
| `FSI_Free_Count` | macro | `FatFs-R0.16/source/ff.c:194` | `#define FSI_Free_Count` |
| `FSI_LeadSig` | macro | `FatFs-R0.16/source/ff.c:192` | `#define FSI_LeadSig` |
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
| `GPTH_Sign` | macro | `FatFs-R0.16/source/ff.c:211` | `#define GPTH_Sign` |
| `GPTH_Size` | macro | `FatFs-R0.16/source/ff.c:213` | `#define GPTH_Size` |
| `GPT_ALIGN` | macro | `FatFs-R0.16/source/ff.c:5894` | `#define	GPT_ALIGN` |
| `GPT_ITEMS` | macro | `FatFs-R0.16/source/ff.c:5895` | `#define GPT_ITEMS` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:503` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:526` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:533` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:537` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:545` | `#define INIT_NAMEBUFF(fs)` |
| `INIT_NAMEBUFF` | macro | `FatFs-R0.16/source/ff.c:549` | `#define INIT_NAMEBUFF(fs)` |
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
| `LEAVE_MKFS` | macro | `FatFs-R0.16/source/ff.c:505` | `#define LEAVE_MKFS(res)` |
| `LEAVE_MKFS` | macro | `FatFs-R0.16/source/ff.c:528` | `#define LEAVE_MKFS(res)` |
| `LEAVE_MKFS` | macro | `FatFs-R0.16/source/ff.c:540` | `#define LEAVE_MKFS(res)` |
| `LEAVE_MKFS` | macro | `FatFs-R0.16/source/ff.c:552` | `#define LEAVE_MKFS(res)` |
| `LLEF` | macro | `FatFs-R0.16/source/ff.c:190` | `#define LLEF` |
| `MAXDIRB` | macro | `FatFs-R0.16/source/ff.c:518` | `#define MAXDIRB(nc)` |
| `MAX_DIR` | macro | `FatFs-R0.16/source/ff.c:38` | `#define MAX_DIR` |
| `MAX_DIR_EX` | macro | `FatFs-R0.16/source/ff.c:39` | `#define MAX_DIR_EX` |
| `MAX_EXFAT` | macro | `FatFs-R0.16/source/ff.c:43` | `#define MAX_EXFAT` |
| `MAX_FAT12` | macro | `FatFs-R0.16/source/ff.c:40` | `#define MAX_FAT12` |
| `MAX_FAT16` | macro | `FatFs-R0.16/source/ff.c:41` | `#define MAX_FAT16` |
| `MAX_FAT32` | macro | `FatFs-R0.16/source/ff.c:42` | `#define MAX_FAT32` |
| `MAX_MALLOC` | macro | `FatFs-R0.16/source/ff.c:553` | `#define MAX_MALLOC` |
| `MBR_Table` | macro | `FatFs-R0.16/source/ff.c:198` | `#define MBR_Table` |
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
| `N_SEC_TRACK` | macro | `FatFs-R0.16/source/ff.c:5893` | `#define N_SEC_TRACK` |
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
| `SZDIRE` | macro | `FatFs-R0.16/source/ff.c:187` | `#define SZDIRE` |
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
| `change_bitmap` | function | `FatFs-R0.16/source/ff.c:1359` | `static FRESULT change_bitmap ( 	FATFS* fs,	/* Filesystem object */ 	DWORD clst,	/* Cluster number...` |
| `check_fs` | function | `FatFs-R0.16/source/ff.c:3367` | `static UINT check_fs (	/* 0:FAT/FAT32 VBR, 1:exFAT VBR, 2:Not FAT and valid BS, 3:Not FAT and inv...` |
| `chk_share` | function | `FatFs-R0.16/source/ff.c:947` | `static FRESULT chk_share (	/* Check if the file can be accessed */ 	DIR* dp,		/* Directory object...` |
| `clear_share` | function | `FatFs-R0.16/source/ff.c:1038` | `static void clear_share (	/* Clear all lock entries of the volume */ 	FATFS* fs )` |
| `clmt_clust` | function | `FatFs-R0.16/source/ff.c:1644` | `static DWORD clmt_clust (	/* <2:Error, >=2:Cluster number */ 	FIL* fp,		/* Pointer to the file ob...` |
| `clst2sect` | function | `FatFs-R0.16/source/ff.c:1159` | `static LBA_t clst2sect (	/* !=0:Sector number, 0:Failed (invalid cluster#) */ 	FATFS* fs,		/* Fil...` |
| `cmp_lfn` | function | `FatFs-R0.16/source/ff.c:1902` | `static int cmp_lfn (		/* 1:matched, 0:not matched */ 	const WCHAR* lfnbuf,	/* Pointer to the LFN ...` |
| `crc32` | function | `FatFs-R0.16/source/ff.c:3297` | `static DWORD crc32 (	/* Returns next CRC value */ 	DWORD crc,			/* Current CRC value */ 	BYTE d		...` |
| `create_chain` | function | `FatFs-R0.16/source/ff.c:1539` | `static DWORD create_chain (	/* 0:No free cluster, 1:Internal error, 0xFFFFFFFF:Disk error, >=2:Ne...` |
| `create_name` | function | `FatFs-R0.16/source/ff.c:2892` | `static FRESULT create_name (	/* FR_OK: successful, FR_INVALID_NAME: could not create */ 	DIR* dp,...` |
| `create_partition` | function | `FatFs-R0.16/source/ff.c:5900` | `static FRESULT create_partition ( 	BYTE drv,			/* Physical drive number */ 	const LBA_t plst[],	/...` |
| `create_xdir` | function | `FatFs-R0.16/source/ff.c:2288` | `static void create_xdir ( 	BYTE* dirb,			/* Pointer to the directory entry block buffer */ 	const...` |
| `dbc_1st` | function | `FatFs-R0.16/source/ff.c:693` | `static int dbc_1st (BYTE c)` |
| `dbc_2nd` | function | `FatFs-R0.16/source/ff.c:713` | `static int dbc_2nd (BYTE c)` |
| `dec_share` | function | `FatFs-R0.16/source/ff.c:1014` | `static FRESULT dec_share (	/* Decrement object open counter */ 	UINT i			/* Semaphore index (1..)...` |
| `dir_alloc` | function | `FatFs-R0.16/source/ff.c:1823` | `static FRESULT dir_alloc (	/* FR_OK(0):succeeded, !=0:error */ 	DIR* dp,				/* Pointer to the dir...` |
| `dir_clear` | function | `FatFs-R0.16/source/ff.c:1675` | `static FRESULT dir_clear (	/* Returns FR_OK or FR_DISK_ERR */ 	FATFS *fs,		/* Filesystem object *...` |
| `dir_find` | function | `FatFs-R0.16/source/ff.c:2412` | `static FRESULT dir_find (	/* FR_OK(0):succeeded, !=0:error */ 	DIR* dp					/* Pointer to the dire...` |
| `dir_next` | function | `FatFs-R0.16/source/ff.c:1762` | `static FRESULT dir_next (	/* FR_OK(0):succeeded, FR_NO_FILE:End of table, FR_DENIED:Could not str...` |
| `dir_read` | function | `FatFs-R0.16/source/ff.c:2334` | `static FRESULT dir_read ( 	DIR* dp,		/* Pointer to the directory object */ 	int vol			/* Filtered...` |
| `dir_register` | function | `FatFs-R0.16/source/ff.c:2494` | `static FRESULT dir_register (	/* FR_OK:succeeded, FR_DENIED:no free entry or too many SFN collisi...` |
| `dir_remove` | function | `FatFs-R0.16/source/ff.c:2607` | `static FRESULT dir_remove (	/* FR_OK:Succeeded, FR_DISK_ERR:A disk error */ 	DIR* dp					/* Direc...` |
| `dir_sdi` | function | `FatFs-R0.16/source/ff.c:1714` | `static FRESULT dir_sdi (	/* FR_OK(0):succeeded, !=0:error */ 	DIR* dp,		/* Pointer to directory o...` |
| `f_chdir` | function | `FatFs-R0.16/source/ff.c:4357` | `FRESULT f_chdir ( 	const TCHAR* path	/* Pointer to the directory path */ )` |
| `f_chdrive` | function | `FatFs-R0.16/source/ff.c:4335` | `FRESULT f_chdrive ( 	const TCHAR* path		/* Drive number to set */ )` |
| `f_chmod` | function | `FatFs-R0.16/source/ff.c:5385` | `FRESULT f_chmod ( 	const TCHAR* path,	/* Pointer to the file path */ 	BYTE attr,			/* Attribute b...` |
| `f_close` | function | `FatFs-R0.16/source/ff.c:4299` | `FRESULT f_close ( 	FIL* fp		/* Open file to be closed */ )` |
| `f_closedir` | function | `FatFs-R0.16/source/ff.c:4781` | `FRESULT f_closedir ( 	DIR *dp		/* Pointer to the directory object to be closed */ )` |
| `f_expand` | function | `FatFs-R0.16/source/ff.c:5726` | `FRESULT f_expand ( 	FIL* fp,		/* Pointer to the file object */ 	FSIZE_t fsz,	/* File size to be e...` |
| `f_fdisk` | function | `FatFs-R0.16/source/ff.c:6548` | `FRESULT f_fdisk ( 	BYTE pdrv,			/* Physical drive number */ 	const LBA_t ptbl[],	/* Pointer to th...` |
| `f_findfirst` | function | `FatFs-R0.16/source/ff.c:4875` | `FRESULT f_findfirst ( 	DIR* dp,				/* Pointer to the blank directory object */ 	FILINFO* fno,			/...` |
| `f_findnext` | function | `FatFs-R0.16/source/ff.c:4850` | `FRESULT f_findnext ( 	DIR* dp,		/* Pointer to the open directory object */ 	FILINFO* fno	/* Point...` |
| `f_forward` | function | `FatFs-R0.16/source/ff.c:5822` | `FRESULT f_forward ( 	FIL* fp, 						/* Pointer to the file object */ 	UINT (*func)(const BYTE*,UI...` |
| `f_getcwd` | function | `FatFs-R0.16/source/ff.c:4419` | `FRESULT f_getcwd ( 	TCHAR* buff,	/* Pointer to the buffer to store the current direcotry path */ ...` |
| `f_getfree` | function | `FatFs-R0.16/source/ff.c:4939` | `FRESULT f_getfree ( 	const TCHAR* path,	/* Logical drive number */ 	DWORD* nclst,		/* Pointer to ...` |
| `f_getlabel` | function | `FatFs-R0.16/source/ff.c:5502` | `FRESULT f_getlabel ( 	const TCHAR* path,	/* Logical drive number */ 	TCHAR* label,		/* Buffer to ...` |
| `f_gets` | function | `FatFs-R0.16/source/ff.c:6588` | `TCHAR* f_gets ( 	TCHAR* buff,	/* Pointer to the buffer to store read string */ 	int len,		/* Size...` |
| `f_lseek` | function | `FatFs-R0.16/source/ff.c:4555` | `FRESULT f_lseek ( 	FIL* fp,		/* Pointer to the file object */ 	FSIZE_t ofs		/* File pointer from ...` |
| `f_mkdir` | function | `FatFs-R0.16/source/ff.c:5176` | `FRESULT f_mkdir ( 	const TCHAR* path		/* Pointer to the directory path */ )` |
| `f_mkfs` | function | `FatFs-R0.16/source/ff.c:6043` | `FRESULT f_mkfs ( 	const TCHAR* path,		/* Logical drive number */ 	const MKFS_PARM* opt,	/* Format...` |
| `f_open` | function | `FatFs-R0.16/source/ff.c:3799` | `FRESULT f_open ( 	FIL* fp,			/* Pointer to the blank file object */ 	const TCHAR* path,	/* Pointe...` |
| `f_opendir` | function | `FatFs-R0.16/source/ff.c:4719` | `FRESULT f_opendir ( 	DIR* dp,			/* Pointer to directory object to create */ 	const TCHAR* path	/*...` |
| `f_printf` | function | `FatFs-R0.16/source/ff.c:7057` | `int f_printf ( 	FIL* fp,			/* Pointer to the file object */ 	const TCHAR* fmt,	/* Pointer to the ...` |
| `f_putc` | function | `FatFs-R0.16/source/ff.c:6894` | `int f_putc ( 	TCHAR c,	/* A character to be output */ 	FIL* fp		/* Pointer to the file object */ )` |
| `f_puts` | function | `FatFs-R0.16/source/ff.c:6914` | `int f_puts ( 	const TCHAR* str,	/* Pointer to the string to be output */ 	FIL* fp				/* Pointer t...` |
| `f_read` | function | `FatFs-R0.16/source/ff.c:3996` | `FRESULT f_read ( 	FIL* fp, 	/* Open file to be read */ 	void* buff,	/* Data buffer to store the r...` |
| `f_readdir` | function | `FatFs-R0.16/source/ff.c:4811` | `FRESULT f_readdir ( 	DIR* dp,			/* Pointer to the open directory object */ 	FILINFO* fno		/* Poin...` |
| `f_rename` | function | `FatFs-R0.16/source/ff.c:5261` | `FRESULT f_rename ( 	const TCHAR* path_old,	/* Pointer to the object name to be renamed */ 	const ...` |
| `f_setcp` | function | `FatFs-R0.16/source/ff.c:7226` | `FRESULT f_setcp ( 	WORD cp		/* Value to be set as active code page */ )` |
| `f_setlabel` | function | `FatFs-R0.16/source/ff.c:5603` | `FRESULT f_setlabel ( 	const TCHAR* label	/* Volume label to set with heading logical drive number...` |
| `f_stat` | function | `FatFs-R0.16/source/ff.c:4902` | `FRESULT f_stat ( 	const TCHAR* path,	/* Pointer to the file path */ 	FILINFO* fno		/* Pointer to ...` |
| `f_sync` | function | `FatFs-R0.16/source/ff.c:4218` | `FRESULT f_sync ( 	FIL* fp		/* Open file to be synced */ )` |
| `f_truncate` | function | `FatFs-R0.16/source/ff.c:5036` | `FRESULT f_truncate ( 	FIL* fp		/* Pointer to the file object */ )` |
| `f_unlink` | function | `FatFs-R0.16/source/ff.c:5087` | `FRESULT f_unlink ( 	const TCHAR* path		/* Pointer to the file or directory path */ )` |
| `f_utime` | function | `FatFs-R0.16/source/ff.c:5434` | `FRESULT f_utime ( 	const TCHAR* path,	/* Pointer to the file/directory name */ 	const FILINFO* fn...` |
| `f_write` | function | `FatFs-R0.16/source/ff.c:4097` | `FRESULT f_write ( 	FIL* fp,			/* Open file to be written */ 	const void* buff,	/* Data to be writ...` |
| `fill_first_frag` | function | `FatFs-R0.16/source/ff.c:1395` | `static FRESULT fill_first_frag ( 	FFOBJID* obj	/* Pointer to the corresponding object */ )` |
| `fill_last_frag` | function | `FatFs-R0.16/source/ff.c:1418` | `static FRESULT fill_last_frag ( 	FFOBJID* obj,	/* Pointer to the corresponding object */ 	DWORD l...` |
| `find_bitmap` | function | `FatFs-R0.16/source/ff.c:1319` | `static DWORD find_bitmap (	/* 0:Not found, 2..:Cluster block found, 0xFFFFFFFF:Disk error */ 	FAT...` |
| `find_volume` | function | `FatFs-R0.16/source/ff.c:3407` | `static UINT find_volume (	/* Returns BS status found in the hosting drive */ 	FATFS* fs,		/* File...` |
| `follow_path` | function | `FatFs-R0.16/source/ff.c:3101` | `static FRESULT follow_path (	/* FR_OK(0): successful, !=0: error code */ 	DIR* dp,					/* Directo...` |
| `ftoa` | function | `FatFs-R0.16/source/ff.c:6980` | `static void ftoa ( 	char* buf,	/* Buffer to output the floating point string */ 	double val,	/* V...` |
| `gen_numname` | function | `FatFs-R0.16/source/ff.c:2013` | `static void gen_numname ( 	BYTE* dst,			/* Pointer to the buffer to store numbered SFN */ 	const ...` |
| `get_achar` | function | `FatFs-R0.16/source/ff.c:2807` | `static DWORD get_achar (	/* Get a character and advance ptr */ 	const TCHAR** ptr		/* Pointer to ...` |
| `get_fat` | function | `FatFs-R0.16/source/ff.c:1176` | `static DWORD get_fat (		/* 0xFFFFFFFF:Disk error, 1:Internal error, 2..0x7FFFFFFF:Cluster status ...` |
| `get_fileinfo` | function | `FatFs-R0.16/source/ff.c:2653` | `static void get_fileinfo ( 	DIR* dp,			/* Pointer to the directory object */ 	FILINFO* fno		/* Po...` |
| `get_ldnumber` | function | `FatFs-R0.16/source/ff.c:3220` | `static int get_ldnumber (	/* Returns logical drive number (-1:invalid drive number or null pointe...` |
| `inc_share` | function | `FatFs-R0.16/source/ff.c:983` | `static UINT inc_share (	/* Increment object open counter and returns its index (0:Internal error)...` |
| `init_alloc_info` | function | `FatFs-R0.16/source/ff.c:2199` | `static void init_alloc_info ( 	FFOBJID* dobj,	/* Object allocation information to be initialized ...` |
| `ld_clust` | function | `FatFs-R0.16/source/ff.c:1865` | `static DWORD ld_clust (	/* Returns the top cluster value of the SFN entry */ 	FATFS* fs,			/* Poi...` |
| `load_obj_xdir` | function | `FatFs-R0.16/source/ff.c:2225` | `static FRESULT load_obj_xdir ( 	DIR* dp,			/* Blank directory object to be used to access contain...` |
| `load_xdir` | function | `FatFs-R0.16/source/ff.c:2147` | `static FRESULT load_xdir (	/* FR_INT_ERR: invalid entry block */ 	DIR* dp					/* Reading director...` |
| `lock_volume` | function | `FatFs-R0.16/source/ff.c:896` | `static int lock_volume (	/* 1:Ok, 0:timeout */ 	FATFS* fs,				/* Filesystem object to lock */ 	in...` |
| `make_rand` | function | `FatFs-R0.16/source/ff.c:3339` | `static DWORD make_rand (	/* Returns a seed value for next */ 	DWORD seed,				/* Seed value */ 	BY...` |
| `mount_volume` | function | `FatFs-R0.16/source/ff.c:3461` | `static FRESULT mount_volume (	/* FR_OK(0): successful, !=0: an error occurred */ 	const TCHAR** p...` |
| `move_window` | function | `FatFs-R0.16/source/ff.c:1079` | `static FRESULT move_window (	/* Returns FR_OK or FR_DISK_ERR */ 	FATFS* fs,		/* Filesystem object...` |
| `pattern_match` | function | `FatFs-R0.16/source/ff.c:2838` | `static int pattern_match (	/* 0:mismatched, 1:matched */ 	const TCHAR* pat,	/* Matching pattern *...` |
| `pick_lfn` | function | `FatFs-R0.16/source/ff.c:1938` | `static int pick_lfn (	/* 1:succeeded, 0:buffer overflow or invalid LFN entry */ 	WCHAR* lfnbuf,		...` |
| `put_fat` | function | `FatFs-R0.16/source/ff.c:1254` | `static FRESULT put_fat (	/* FR_OK(0):succeeded, !=0:error */ 	FATFS* fs,		/* Corresponding filesy...` |
| `put_lfn` | function | `FatFs-R0.16/source/ff.c:1976` | `static void put_lfn ( 	const WCHAR* lfn,	/* Pointer to the LFN */ 	BYTE* dir,			/* Pointer to the...` |
| `put_utf` | function | `FatFs-R0.16/source/ff.c:806` | `static UINT put_utf (	/* Returns number of encoding units written (0:buffer overflow or wrong enc...` |
| `putbuff` | struct | `FatFs-R0.16/source/ff.c:6725` | `` |
| `putc_bfd` | function | `FatFs-R0.16/source/ff.c:6740` | `static void putc_bfd (putbuff* pb, TCHAR c)` |
| `putc_flush` | function | `FatFs-R0.16/source/ff.c:6871` | `static int putc_flush (putbuff* pb)` |
| `putc_init` | function | `FatFs-R0.16/source/ff.c:6886` | `static void putc_init (putbuff* pb, FIL* fp)` |
| `remove_chain` | function | `FatFs-R0.16/source/ff.c:1444` | `static FRESULT remove_chain (	/* FR_OK(0):succeeded, !=0:error */ 	FFOBJID* obj,		/* Correspondin...` |
| `st_clust` | function | `FatFs-R0.16/source/ff.c:1882` | `static void st_clust ( 	FATFS* fs,	/* Pointer to the fs object */ 	BYTE* dir,	/* Pointer to the k...` |
| `store_xdir` | function | `FatFs-R0.16/source/ff.c:2254` | `static FRESULT store_xdir ( 	DIR* dp				/* Pointer to the directory object */ )` |
| `sum_sfn` | function | `FatFs-R0.16/source/ff.c:2070` | `static BYTE sum_sfn ( 	const BYTE* dir		/* Pointer to the SFN entry */ )` |
| `sync_fs` | function | `FatFs-R0.16/source/ff.c:1110` | `static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR */ 	FATFS* fs		/* Filesystem object */ )` |
| `sync_window` | function | `FatFs-R0.16/source/ff.c:1057` | `static FRESULT sync_window (	/* Returns FR_OK or FR_DISK_ERR */ 	FATFS* fs			/* Filesystem object...` |
| `tchar2uni` | function | `FatFs-R0.16/source/ff.c:737` | `static DWORD tchar2uni (	/* Returns a character in UTF-16 encoding (>=0x10000 on surrogate pair, ...` |
| `test_gpt_header` | function | `FatFs-R0.16/source/ff.c:3315` | `static int test_gpt_header (	/* 0:Invalid, 1:Valid */ 	const BYTE* gpth			/* Pointer to the GPT h...` |
| `unlock_volume` | function | `FatFs-R0.16/source/ff.c:922` | `static void unlock_volume ( 	FATFS* fs,		/* Filesystem object */ 	FRESULT res		/* Result code to ...` |
| `validate` | function | `FatFs-R0.16/source/ff.c:3695` | `static FRESULT validate (	/* Returns FR_OK or FR_INVALID_OBJECT */ 	FFOBJID* obj,			/* Pointer to...` |
| `xdir_sum` | function | `FatFs-R0.16/source/ff.c:2092` | `static WORD xdir_sum (	/* Get checksum of the directoly entry block */ 	const BYTE* dir		/* Direc...` |
| `xname_sum` | function | `FatFs-R0.16/source/ff.c:2113` | `static WORD xname_sum (	/* Get check sum (to be used as hash) of the file name */ 	const WCHAR* n...` |
| `xsum32` | function | `FatFs-R0.16/source/ff.c:2131` | `static DWORD xsum32 (	/* Returns 32-bit checksum */ 	BYTE  dat,			/* Byte to be calculated (byte-...` |
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
| `QWORD` | variable | `FatFs-R0.16/source/ff.h:26` | `extern "C" { #endif #if !defined(FFCONF_DEF) #include "ffconf.h" /* FatFs configuration options */ #endif #if...` |
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
| `f_eof` | macro | `FatFs-R0.16/source/ff.h:360` | `#define f_eof(fp)` |
| `f_error` | macro | `FatFs-R0.16/source/ff.h:361` | `#define f_error(fp)` |
| `f_gets` | function | `FatFs-R0.16/source/ff.h:356` | `TCHAR* f_gets (TCHAR* buff, int len, FIL* fp);` |
| `f_printf` | function | `FatFs-R0.16/source/ff.h:355` | `int f_printf (FIL* fp, const TCHAR* str, ...);` |
| `f_putc` | function | `FatFs-R0.16/source/ff.h:353` | `int f_putc (TCHAR c, FIL* fp);` |
| `f_puts` | function | `FatFs-R0.16/source/ff.h:354` | `int f_puts (const TCHAR* str, FIL* cp);` |
| `f_rewind` | macro | `FatFs-R0.16/source/ff.h:364` | `#define f_rewind(fp)` |
| `f_rewinddir` | macro | `FatFs-R0.16/source/ff.h:365` | `#define f_rewinddir(dp)` |
| `f_rmdir` | macro | `FatFs-R0.16/source/ff.h:366` | `#define f_rmdir(path)` |
| `f_size` | macro | `FatFs-R0.16/source/ff.h:363` | `#define f_size(fp)` |
| `f_tell` | macro | `FatFs-R0.16/source/ff.h:362` | `#define f_tell(fp)` |
| `f_unmount` | macro | `FatFs-R0.16/source/ff.h:367` | `#define f_unmount(path)` |
| `ff_memalloc` | function | `FatFs-R0.16/source/ff.h:394` | `void* ff_memalloc (UINT msize);` |
| `ff_memfree` | function | `FatFs-R0.16/source/ff.h:395` | `void ff_memfree (void* mblock);` |
| `ff_mutex_create` | function | `FatFs-R0.16/source/ff.h:398` | `int ff_mutex_create (int vol);` |
| `ff_mutex_delete` | function | `FatFs-R0.16/source/ff.h:399` | `void ff_mutex_delete (int vol);` |
| `ff_mutex_give` | function | `FatFs-R0.16/source/ff.h:401` | `void ff_mutex_give (int vol);` |
| `ff_mutex_take` | function | `FatFs-R0.16/source/ff.h:400` | `int ff_mutex_take (int vol);` |
| `isinf` | macro | `FatFs-R0.16/source/ff.h:45` | `#define isinf(v)` |
| `isnan` | macro | `FatFs-R0.16/source/ff.h:44` | `#define isnan(v)` |
| `FFCONF_DEF` | macro | `FatFs-R0.16/source/ffconf.h:5` | `#define FFCONF_DEF` |
| `FF_CODE_PAGE` | macro | `FatFs-R0.16/source/ffconf.h:87` | `#define FF_CODE_PAGE` |
| `FF_FS_CRTIME` | macro | `FatFs-R0.16/source/ffconf.h:266` | `#define FF_FS_CRTIME` |
| `FF_FS_EXFAT` | macro | `FatFs-R0.16/source/ffconf.h:246` | `#define FF_FS_EXFAT` |
| `FF_FS_LOCK` | macro | `FatFs-R0.16/source/ffconf.h:283` | `#define FF_FS_LOCK` |
| `FF_FS_MINIMIZE` | macro | `FatFs-R0.16/source/ffconf.h:18` | `#define FF_FS_MINIMIZE` |
| `FF_FS_NOFSINFO` | macro | `FatFs-R0.16/source/ffconf.h:271` | `#define FF_FS_NOFSINFO` |
| `FF_FS_NORTC` | macro | `FatFs-R0.16/source/ffconf.h:252` | `#define FF_FS_NORTC` |
| `FF_FS_READONLY` | macro | `FatFs-R0.16/source/ffconf.h:11` | `#define FF_FS_READONLY` |
| `FF_FS_REENTRANT` | macro | `FatFs-R0.16/source/ffconf.h:295` | `#define FF_FS_REENTRANT` |
| `FF_FS_RPATH` | macro | `FatFs-R0.16/source/ffconf.h:156` | `#define FF_FS_RPATH` |
| `FF_FS_TIMEOUT` | macro | `FatFs-R0.16/source/ffconf.h:296` | `#define FF_FS_TIMEOUT` |
| `FF_FS_TINY` | macro | `FatFs-R0.16/source/ffconf.h:239` | `#define FF_FS_TINY` |
| `FF_LBA64` | macro | `FatFs-R0.16/source/ffconf.h:218` | `#define FF_LBA64` |
| `FF_LFN_BUF` | macro | `FatFs-R0.16/source/ffconf.h:148` | `#define FF_LFN_BUF` |
| `FF_LFN_UNICODE` | macro | `FatFs-R0.16/source/ffconf.h:136` | `#define FF_LFN_UNICODE` |
| `FF_MAX_LFN` | macro | `FatFs-R0.16/source/ffconf.h:117` | `#define FF_MAX_LFN` |
| `FF_MAX_SS` | macro | `FatFs-R0.16/source/ffconf.h:209` | `#define FF_MAX_SS` |
| `FF_MIN_GPT` | macro | `FatFs-R0.16/source/ffconf.h:223` | `#define FF_MIN_GPT` |
| `FF_MIN_SS` | macro | `FatFs-R0.16/source/ffconf.h:208` | `#define FF_MIN_SS` |
| `FF_MULTI_PARTITION` | macro | `FatFs-R0.16/source/ffconf.h:199` | `#define FF_MULTI_PARTITION` |
| `FF_NORTC_MDAY` | macro | `FatFs-R0.16/source/ffconf.h:254` | `#define FF_NORTC_MDAY` |
| `FF_NORTC_MON` | macro | `FatFs-R0.16/source/ffconf.h:253` | `#define FF_NORTC_MON` |
| `FF_NORTC_YEAR` | macro | `FatFs-R0.16/source/ffconf.h:255` | `#define FF_NORTC_YEAR` |
| `FF_PATH_DEPTH` | macro | `FatFs-R0.16/source/ffconf.h:165` | `#define FF_PATH_DEPTH` |
| `FF_PRINT_FLOAT` | macro | `FatFs-R0.16/source/ffconf.h:61` | `#define FF_PRINT_FLOAT` |
| `FF_PRINT_LLI` | macro | `FatFs-R0.16/source/ffconf.h:60` | `#define FF_PRINT_LLI` |
| `FF_SFN_BUF` | macro | `FatFs-R0.16/source/ffconf.h:149` | `#define FF_SFN_BUF` |
| `FF_STRF_ENCODE` | macro | `FatFs-R0.16/source/ffconf.h:62` | `#define FF_STRF_ENCODE` |

Next: [SYMBOLS_p2.md](SYMBOLS_p2.md)
