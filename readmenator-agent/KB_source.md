# Subsystem: source

## FatFs-R0.16/source/diskio.c
- Layer: infrastructure
- Doc: -----------------------------------------------------------------------
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
- Layer: infrastructure
- Doc: -----------------------------------------------------------------------
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

## FatFs-R0.16/source/ff.c
- Layer: utility
- Doc: ----------------------------------------------------------------------------
- Language: c
- Symbols:
  - `FILESEM` (struct, line 285)
  - `putbuff` (struct, line 6725)
  - `dbc_1st` (function, line 693) `static int dbc_1st (BYTE c)`
  - `dbc_2nd` (function, line 713) `static int dbc_2nd (BYTE c)`
  - `tchar2uni` (function, line 737) `static DWORD tchar2uni (	/* Returns a character in UTF-16 encoding (>=0x10000 on surrogate pair, ...`
  - `put_utf` (function, line 806) `static UINT put_utf (	/* Returns number of encoding units written (0:buffer overflow or wrong enc...`
  - `lock_volume` (function, line 896) `static int lock_volume (	/* 1:Ok, 0:timeout */
	FATFS* fs,				/* Filesystem object to lock */
	in...`
  - `unlock_volume` (function, line 922) `static void unlock_volume (
	FATFS* fs,		/* Filesystem object */
	FRESULT res		/* Result code to ...`
  - `chk_share` (function, line 947) `static FRESULT chk_share (	/* Check if the file can be accessed */
	DIR* dp,		/* Directory object...`
  - `inc_share` (function, line 983) `static UINT inc_share (	/* Increment object open counter and returns its index (0:Internal error)...`
  - `dec_share` (function, line 1014) `static FRESULT dec_share (	/* Decrement object open counter */
	UINT i			/* Semaphore index (1..)...`
  - `clear_share` (function, line 1038) `static void clear_share (	/* Clear all lock entries of the volume */
	FATFS* fs
)`
  - `sync_window` (function, line 1057) `static FRESULT sync_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs			/* Filesystem object...`
  - `move_window` (function, line 1079) `static FRESULT move_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs,		/* Filesystem object...`
  - `sync_fs` (function, line 1110) `static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs		/* Filesystem object */
)`
  - `clst2sect` (function, line 1159) `static LBA_t clst2sect (	/* !=0:Sector number, 0:Failed (invalid cluster#) */
	FATFS* fs,		/* Fil...`
  - `get_fat` (function, line 1176) `static DWORD get_fat (		/* 0xFFFFFFFF:Disk error, 1:Internal error, 2..0x7FFFFFFF:Cluster status ...`
  - `put_fat` (function, line 1254) `static FRESULT put_fat (	/* FR_OK(0):succeeded, !=0:error */
	FATFS* fs,		/* Corresponding filesy...`
  - `find_bitmap` (function, line 1319) `static DWORD find_bitmap (	/* 0:Not found, 2..:Cluster block found, 0xFFFFFFFF:Disk error */
	FAT...`
  - `change_bitmap` (function, line 1359) `static FRESULT change_bitmap (
	FATFS* fs,	/* Filesystem object */
	DWORD clst,	/* Cluster number...`
  - `fill_first_frag` (function, line 1395) `static FRESULT fill_first_frag (
	FFOBJID* obj	/* Pointer to the corresponding object */
)`
  - `fill_last_frag` (function, line 1418) `static FRESULT fill_last_frag (
	FFOBJID* obj,	/* Pointer to the corresponding object */
	DWORD l...`
  - `remove_chain` (function, line 1444) `static FRESULT remove_chain (	/* FR_OK(0):succeeded, !=0:error */
	FFOBJID* obj,		/* Correspondin...`
  - `create_chain` (function, line 1539) `static DWORD create_chain (	/* 0:No free cluster, 1:Internal error, 0xFFFFFFFF:Disk error, >=2:Ne...`
  - `clmt_clust` (function, line 1644) `static DWORD clmt_clust (	/* <2:Error, >=2:Cluster number */
	FIL* fp,		/* Pointer to the file ob...`
  - `dir_clear` (function, line 1675) `static FRESULT dir_clear (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS *fs,		/* Filesystem object *...`
  - `dir_sdi` (function, line 1714) `static FRESULT dir_sdi (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,		/* Pointer to directory o...`
  - `dir_next` (function, line 1762) `static FRESULT dir_next (	/* FR_OK(0):succeeded, FR_NO_FILE:End of table, FR_DENIED:Could not str...`
  - `dir_alloc` (function, line 1823) `static FRESULT dir_alloc (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,				/* Pointer to the dir...`
  - `ld_clust` (function, line 1865) `static DWORD ld_clust (	/* Returns the top cluster value of the SFN entry */
	FATFS* fs,			/* Poi...`
  - `st_clust` (function, line 1882) `static void st_clust (
	FATFS* fs,	/* Pointer to the fs object */
	BYTE* dir,	/* Pointer to the k...`
  - `cmp_lfn` (function, line 1902) `static int cmp_lfn (		/* 1:matched, 0:not matched */
	const WCHAR* lfnbuf,	/* Pointer to the LFN ...`
  - `pick_lfn` (function, line 1938) `static int pick_lfn (	/* 1:succeeded, 0:buffer overflow or invalid LFN entry */
	WCHAR* lfnbuf,		...`
  - `put_lfn` (function, line 1976) `static void put_lfn (
	const WCHAR* lfn,	/* Pointer to the LFN */
	BYTE* dir,			/* Pointer to the...`
  - `gen_numname` (function, line 2013) `static void gen_numname (
	BYTE* dst,			/* Pointer to the buffer to store numbered SFN */
	const ...`
  - `sum_sfn` (function, line 2070) `static BYTE sum_sfn (
	const BYTE* dir		/* Pointer to the SFN entry */
)`
  - `xdir_sum` (function, line 2092) `static WORD xdir_sum (	/* Get checksum of the directoly entry block */
	const BYTE* dir		/* Direc...`
  - `xname_sum` (function, line 2113) `static WORD xname_sum (	/* Get check sum (to be used as hash) of the file name */
	const WCHAR* n...`
  - `xsum32` (function, line 2131) `static DWORD xsum32 (	/* Returns 32-bit checksum */
	BYTE  dat,			/* Byte to be calculated (byte-...`
  - `load_xdir` (function, line 2147) `static FRESULT load_xdir (	/* FR_INT_ERR: invalid entry block */
	DIR* dp					/* Reading director...`
  - `init_alloc_info` (function, line 2199) `static void init_alloc_info (
	FFOBJID* dobj,	/* Object allocation information to be initialized ...`
  - `load_obj_xdir` (function, line 2225) `static FRESULT load_obj_xdir (
	DIR* dp,			/* Blank directory object to be used to access contain...`
  - `store_xdir` (function, line 2254) `static FRESULT store_xdir (
	DIR* dp				/* Pointer to the directory object */
)`
  - `create_xdir` (function, line 2288) `static void create_xdir (
	BYTE* dirb,			/* Pointer to the directory entry block buffer */
	const...`
  - `dir_read` (function, line 2334) `static FRESULT dir_read (
	DIR* dp,		/* Pointer to the directory object */
	int vol			/* Filtered...`
  - `dir_find` (function, line 2412) `static FRESULT dir_find (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp					/* Pointer to the dire...`
  - `dir_register` (function, line 2494) `static FRESULT dir_register (	/* FR_OK:succeeded, FR_DENIED:no free entry or too many SFN collisi...`
  - `dir_remove` (function, line 2607) `static FRESULT dir_remove (	/* FR_OK:Succeeded, FR_DISK_ERR:A disk error */
	DIR* dp					/* Direc...`
  - `get_fileinfo` (function, line 2653) `static void get_fileinfo (
	DIR* dp,			/* Pointer to the directory object */
	FILINFO* fno		/* Po...`
  - `get_achar` (function, line 2807) `static DWORD get_achar (	/* Get a character and advance ptr */
	const TCHAR** ptr		/* Pointer to ...`
  - `pattern_match` (function, line 2838) `static int pattern_match (	/* 0:mismatched, 1:matched */
	const TCHAR* pat,	/* Matching pattern *...`
  - `create_name` (function, line 2892) `static FRESULT create_name (	/* FR_OK: successful, FR_INVALID_NAME: could not create */
	DIR* dp,...`
  - `follow_path` (function, line 3101) `static FRESULT follow_path (	/* FR_OK(0): successful, !=0: error code */
	DIR* dp,					/* Directo...`
  - `get_ldnumber` (function, line 3220) `static int get_ldnumber (	/* Returns logical drive number (-1:invalid drive number or null pointe...`
  - `crc32` (function, line 3297) `static DWORD crc32 (	/* Returns next CRC value */
	DWORD crc,			/* Current CRC value */
	BYTE d		...`
  - `test_gpt_header` (function, line 3315) `static int test_gpt_header (	/* 0:Invalid, 1:Valid */
	const BYTE* gpth			/* Pointer to the GPT h...`
  - `make_rand` (function, line 3339) `static DWORD make_rand (	/* Returns a seed value for next */
	DWORD seed,				/* Seed value */
	BY...`
  - `check_fs` (function, line 3367) `static UINT check_fs (	/* 0:FAT/FAT32 VBR, 1:exFAT VBR, 2:Not FAT and valid BS, 3:Not FAT and inv...`
  - `find_volume` (function, line 3407) `static UINT find_volume (	/* Returns BS status found in the hosting drive */
	FATFS* fs,		/* File...`
  - `mount_volume` (function, line 3461) `static FRESULT mount_volume (	/* FR_OK(0): successful, !=0: an error occurred */
	const TCHAR** p...`
  - `validate` (function, line 3695) `static FRESULT validate (	/* Returns FR_OK or FR_INVALID_OBJECT */
	FFOBJID* obj,			/* Pointer to...`
  - `f_open` (function, line 3799) `FRESULT f_open (
	FIL* fp,			/* Pointer to the blank file object */
	const TCHAR* path,	/* Pointe...`
  - `f_read` (function, line 3996) `FRESULT f_read (
	FIL* fp, 	/* Open file to be read */
	void* buff,	/* Data buffer to store the r...`
  - `f_write` (function, line 4097) `FRESULT f_write (
	FIL* fp,			/* Open file to be written */
	const void* buff,	/* Data to be writ...`
  - `f_sync` (function, line 4218) `FRESULT f_sync (
	FIL* fp		/* Open file to be synced */
)`
  - `f_close` (function, line 4299) `FRESULT f_close (
	FIL* fp		/* Open file to be closed */
)`
  - `f_chdrive` (function, line 4335) `FRESULT f_chdrive (
	const TCHAR* path		/* Drive number to set */
)`
  - `f_chdir` (function, line 4357) `FRESULT f_chdir (
	const TCHAR* path	/* Pointer to the directory path */
)`
  - `f_getcwd` (function, line 4419) `FRESULT f_getcwd (
	TCHAR* buff,	/* Pointer to the buffer to store the current direcotry path */
...`
  - `f_lseek` (function, line 4555) `FRESULT f_lseek (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t ofs		/* File pointer from ...`
  - `f_opendir` (function, line 4719) `FRESULT f_opendir (
	DIR* dp,			/* Pointer to directory object to create */
	const TCHAR* path	/*...`
  - `f_closedir` (function, line 4781) `FRESULT f_closedir (
	DIR *dp		/* Pointer to the directory object to be closed */
)`
  - `f_readdir` (function, line 4811) `FRESULT f_readdir (
	DIR* dp,			/* Pointer to the open directory object */
	FILINFO* fno		/* Poin...`
  - `f_findnext` (function, line 4850) `FRESULT f_findnext (
	DIR* dp,		/* Pointer to the open directory object */
	FILINFO* fno	/* Point...`
  - `f_findfirst` (function, line 4875) `FRESULT f_findfirst (
	DIR* dp,				/* Pointer to the blank directory object */
	FILINFO* fno,			/...`
  - `f_stat` (function, line 4902) `FRESULT f_stat (
	const TCHAR* path,	/* Pointer to the file path */
	FILINFO* fno		/* Pointer to ...`
  - `f_getfree` (function, line 4939) `FRESULT f_getfree (
	const TCHAR* path,	/* Logical drive number */
	DWORD* nclst,		/* Pointer to ...`
  - `f_truncate` (function, line 5036) `FRESULT f_truncate (
	FIL* fp		/* Pointer to the file object */
)`
  - `f_unlink` (function, line 5087) `FRESULT f_unlink (
	const TCHAR* path		/* Pointer to the file or directory path */
)`
  - `f_mkdir` (function, line 5176) `FRESULT f_mkdir (
	const TCHAR* path		/* Pointer to the directory path */
)`
  - `f_rename` (function, line 5261) `FRESULT f_rename (
	const TCHAR* path_old,	/* Pointer to the object name to be renamed */
	const ...`
  - `f_chmod` (function, line 5385) `FRESULT f_chmod (
	const TCHAR* path,	/* Pointer to the file path */
	BYTE attr,			/* Attribute b...`
  - `f_utime` (function, line 5434) `FRESULT f_utime (
	const TCHAR* path,	/* Pointer to the file/directory name */
	const FILINFO* fn...`
  - `f_getlabel` (function, line 5502) `FRESULT f_getlabel (
	const TCHAR* path,	/* Logical drive number */
	TCHAR* label,		/* Buffer to ...`
  - `f_setlabel` (function, line 5603) `FRESULT f_setlabel (
	const TCHAR* label	/* Volume label to set with heading logical drive number...`
  - `f_expand` (function, line 5726) `FRESULT f_expand (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t fsz,	/* File size to be e...`
  - `f_forward` (function, line 5822) `FRESULT f_forward (
	FIL* fp, 						/* Pointer to the file object */
	UINT (*func)(const BYTE*,UI...`
  - `create_partition` (function, line 5900) `static FRESULT create_partition (
	BYTE drv,			/* Physical drive number */
	const LBA_t plst[],	/...`
  - `f_mkfs` (function, line 6043) `FRESULT f_mkfs (
	const TCHAR* path,		/* Logical drive number */
	const MKFS_PARM* opt,	/* Format...`
  - `f_fdisk` (function, line 6548) `FRESULT f_fdisk (
	BYTE pdrv,			/* Physical drive number */
	const LBA_t ptbl[],	/* Pointer to th...`
  - `f_gets` (function, line 6588) `TCHAR* f_gets (
	TCHAR* buff,	/* Pointer to the buffer to store read string */
	int len,		/* Size...`
  - `putc_bfd` (function, line 6740) `static void putc_bfd (putbuff* pb, TCHAR c)`
  - `putc_flush` (function, line 6871) `static int putc_flush (putbuff* pb)`
  - `putc_init` (function, line 6886) `static void putc_init (putbuff* pb, FIL* fp)`
  - `f_putc` (function, line 6894) `int f_putc (
	TCHAR c,	/* A character to be output */
	FIL* fp		/* Pointer to the file object */
)`
  - `f_puts` (function, line 6914) `int f_puts (
	const TCHAR* str,	/* Pointer to the string to be output */
	FIL* fp				/* Pointer t...`
  - `ftoa` (function, line 6980) `static void ftoa (
	char* buf,	/* Buffer to output the floating point string */
	double val,	/* V...`
  - `f_printf` (function, line 7057) `int f_printf (
	FIL* fp,			/* Pointer to the file object */
	const TCHAR* fmt,	/* Pointer to the ...`
  - `f_setcp` (function, line 7226) `FRESULT f_setcp (
	WORD cp		/* Value to be set as active code page */
)`
  - `MAX_DIR` (macro, line 38) `#define MAX_DIR`
  - `MAX_DIR_EX` (macro, line 39) `#define MAX_DIR_EX`
  - `MAX_FAT12` (macro, line 40) `#define MAX_FAT12`
  - `MAX_FAT16` (macro, line 41) `#define MAX_FAT16`
  - `MAX_FAT32` (macro, line 42) `#define MAX_FAT32`
  - `MAX_EXFAT` (macro, line 43) `#define MAX_EXFAT`
  - `IsUpper` (macro, line 47) `#define IsUpper(c)`
  - `IsLower` (macro, line 48) `#define IsLower(c)`
  - `IsDigit` (macro, line 49) `#define IsDigit(c)`
  - `IsSeparator` (macro, line 50) `#define IsSeparator(c)`
  - `IsTerminator` (macro, line 51) `#define IsTerminator(c)`
  - `IsSurrogate` (macro, line 52) `#define IsSurrogate(c)`
  - `IsSurrogateH` (macro, line 53) `#define IsSurrogateH(c)`
  - `IsSurrogateL` (macro, line 54) `#define IsSurrogateL(c)`
  - `FA_SEEKEND` (macro, line 58) `#define FA_SEEKEND`
  - `FA_MODIFIED` (macro, line 59) `#define FA_MODIFIED`
  - `FA_DIRTY` (macro, line 60) `#define FA_DIRTY`
  - `AM_VOL` (macro, line 64) `#define AM_VOL`
  - `AM_LFN` (macro, line 65) `#define AM_LFN`
  - `AM_MASK` (macro, line 66) `#define AM_MASK`
  - `AM_MASKX` (macro, line 67) `#define AM_MASKX`
  - `NSFLAG` (macro, line 71) `#define NSFLAG`
  - `NS_LOSS` (macro, line 72) `#define NS_LOSS`
  - `NS_LFN` (macro, line 73) `#define NS_LFN`
  - `NS_LAST` (macro, line 74) `#define NS_LAST`
  - `NS_BODY` (macro, line 75) `#define NS_BODY`
  - `NS_EXT` (macro, line 76) `#define NS_EXT`
  - `NS_DOT` (macro, line 77) `#define NS_DOT`
  - `NS_NOLFN` (macro, line 78) `#define NS_NOLFN`
  - `NS_NONAME` (macro, line 79) `#define NS_NONAME`
  - `ET_BITMAP` (macro, line 83) `#define	ET_BITMAP`
  - `ET_UPCASE` (macro, line 84) `#define	ET_UPCASE`
  - `ET_VLABEL` (macro, line 85) `#define	ET_VLABEL`
  - `ET_FILEDIR` (macro, line 86) `#define	ET_FILEDIR`
  - `ET_STREAM` (macro, line 87) `#define	ET_STREAM`
  - `ET_FILENAME` (macro, line 88) `#define	ET_FILENAME`
  - `BS_JmpBoot` (macro, line 94) `#define BS_JmpBoot`
  - `BS_OEMName` (macro, line 95) `#define BS_OEMName`
  - `BPB_BytsPerSec` (macro, line 96) `#define BPB_BytsPerSec`
  - `BPB_SecPerClus` (macro, line 97) `#define BPB_SecPerClus`
  - `BPB_RsvdSecCnt` (macro, line 98) `#define BPB_RsvdSecCnt`
  - `BPB_NumFATs` (macro, line 99) `#define BPB_NumFATs`
  - `BPB_RootEntCnt` (macro, line 100) `#define BPB_RootEntCnt`
  - `BPB_TotSec16` (macro, line 101) `#define BPB_TotSec16`
  - `BPB_Media` (macro, line 102) `#define BPB_Media`
  - `BPB_FATSz16` (macro, line 103) `#define BPB_FATSz16`
  - `BPB_SecPerTrk` (macro, line 104) `#define BPB_SecPerTrk`
  - `BPB_NumHeads` (macro, line 105) `#define BPB_NumHeads`
  - `BPB_HiddSec` (macro, line 106) `#define BPB_HiddSec`
  - `BPB_TotSec32` (macro, line 107) `#define BPB_TotSec32`
  - `BS_DrvNum` (macro, line 108) `#define BS_DrvNum`
  - `BS_NTres` (macro, line 109) `#define BS_NTres`
  - `BS_BootSig` (macro, line 110) `#define BS_BootSig`
  - `BS_VolID` (macro, line 111) `#define BS_VolID`
  - `BS_VolLab` (macro, line 112) `#define BS_VolLab`
  - `BS_FilSysType` (macro, line 113) `#define BS_FilSysType`
  - `BS_BootCode` (macro, line 114) `#define BS_BootCode`
  - `BS_55AA` (macro, line 115) `#define BS_55AA`
  - `BPB_FATSz32` (macro, line 117) `#define BPB_FATSz32`
  - `BPB_ExtFlags32` (macro, line 118) `#define BPB_ExtFlags32`
  - `BPB_FSVer32` (macro, line 119) `#define BPB_FSVer32`
  - `BPB_RootClus32` (macro, line 120) `#define BPB_RootClus32`
  - `BPB_FSInfo32` (macro, line 121) `#define BPB_FSInfo32`
  - `BPB_BkBootSec32` (macro, line 122) `#define BPB_BkBootSec32`
  - `BS_DrvNum32` (macro, line 123) `#define BS_DrvNum32`
  - `BS_NTres32` (macro, line 124) `#define BS_NTres32`
  - `BS_BootSig32` (macro, line 125) `#define BS_BootSig32`
  - `BS_VolID32` (macro, line 126) `#define BS_VolID32`
  - `BS_VolLab32` (macro, line 127) `#define BS_VolLab32`
  - `BS_FilSysType32` (macro, line 128) `#define BS_FilSysType32`
  - `BS_BootCode32` (macro, line 129) `#define BS_BootCode32`
  - `BPB_ZeroedEx` (macro, line 131) `#define BPB_ZeroedEx`
  - `BPB_VolOfsEx` (macro, line 132) `#define BPB_VolOfsEx`
  - `BPB_TotSecEx` (macro, line 133) `#define BPB_TotSecEx`
  - `BPB_FatOfsEx` (macro, line 134) `#define BPB_FatOfsEx`
  - `BPB_FatSzEx` (macro, line 135) `#define BPB_FatSzEx`
  - `BPB_DataOfsEx` (macro, line 136) `#define BPB_DataOfsEx`
  - `BPB_NumClusEx` (macro, line 137) `#define BPB_NumClusEx`
  - `BPB_RootClusEx` (macro, line 138) `#define BPB_RootClusEx`
  - `BPB_VolIDEx` (macro, line 139) `#define BPB_VolIDEx`
  - `BPB_FSVerEx` (macro, line 140) `#define BPB_FSVerEx`
  - `BPB_VolFlagEx` (macro, line 141) `#define BPB_VolFlagEx`
  - `BPB_BytsPerSecEx` (macro, line 142) `#define BPB_BytsPerSecEx`
  - `BPB_SecPerClusEx` (macro, line 143) `#define BPB_SecPerClusEx`
  - `BPB_NumFATsEx` (macro, line 144) `#define BPB_NumFATsEx`
  - `BPB_DrvNumEx` (macro, line 145) `#define BPB_DrvNumEx`
  - `BPB_PercInUseEx` (macro, line 146) `#define BPB_PercInUseEx`
  - `BPB_RsvdEx` (macro, line 147) `#define BPB_RsvdEx`
  - `BS_BootCodeEx` (macro, line 148) `#define BS_BootCodeEx`
  - `DIR_Name` (macro, line 150) `#define DIR_Name`
  - `DIR_Attr` (macro, line 151) `#define DIR_Attr`
  - `DIR_NTres` (macro, line 152) `#define DIR_NTres`
  - `DIR_CrtTime10` (macro, line 153) `#define DIR_CrtTime10`
  - `DIR_CrtTime` (macro, line 154) `#define DIR_CrtTime`
  - `DIR_LstAccDate` (macro, line 155) `#define DIR_LstAccDate`
  - `DIR_FstClusHI` (macro, line 156) `#define DIR_FstClusHI`
  - `DIR_ModTime` (macro, line 157) `#define DIR_ModTime`
  - `DIR_FstClusLO` (macro, line 158) `#define DIR_FstClusLO`
  - `DIR_FileSize` (macro, line 159) `#define DIR_FileSize`
  - `LDIR_Ord` (macro, line 160) `#define LDIR_Ord`
  - `LDIR_Attr` (macro, line 161) `#define LDIR_Attr`
  - `LDIR_Type` (macro, line 162) `#define LDIR_Type`
  - `LDIR_Chksum` (macro, line 163) `#define LDIR_Chksum`
  - `LDIR_FstClusLO` (macro, line 164) `#define LDIR_FstClusLO`
  - `XDIR_Type` (macro, line 165) `#define XDIR_Type`
  - `XDIR_NumLabel` (macro, line 166) `#define XDIR_NumLabel`
  - `XDIR_Label` (macro, line 167) `#define XDIR_Label`
  - `XDIR_CaseSum` (macro, line 168) `#define XDIR_CaseSum`
  - `XDIR_NumSec` (macro, line 169) `#define XDIR_NumSec`
  - `XDIR_SetSum` (macro, line 170) `#define XDIR_SetSum`
  - `XDIR_Attr` (macro, line 171) `#define XDIR_Attr`
  - `XDIR_CrtTime` (macro, line 172) `#define XDIR_CrtTime`
  - `XDIR_ModTime` (macro, line 173) `#define XDIR_ModTime`
  - `XDIR_AccTime` (macro, line 174) `#define XDIR_AccTime`
  - `XDIR_CrtTime10` (macro, line 175) `#define XDIR_CrtTime10`
  - `XDIR_ModTime10` (macro, line 176) `#define XDIR_ModTime10`
  - `XDIR_CrtTZ` (macro, line 177) `#define XDIR_CrtTZ`
  - `XDIR_ModTZ` (macro, line 178) `#define XDIR_ModTZ`
  - `XDIR_AccTZ` (macro, line 179) `#define XDIR_AccTZ`
  - `XDIR_GenFlags` (macro, line 180) `#define XDIR_GenFlags`
  - `XDIR_NumName` (macro, line 181) `#define XDIR_NumName`
  - `XDIR_NameHash` (macro, line 182) `#define XDIR_NameHash`
  - `XDIR_ValidFileSize` (macro, line 183) `#define XDIR_ValidFileSize`
  - `XDIR_FstClus` (macro, line 184) `#define XDIR_FstClus`
  - `XDIR_FileSize` (macro, line 185) `#define XDIR_FileSize`
  - `SZDIRE` (macro, line 187) `#define SZDIRE`
  - `DDEM` (macro, line 188) `#define DDEM`
  - `RDDEM` (macro, line 189) `#define RDDEM`
  - `LLEF` (macro, line 190) `#define LLEF`
  - `FSI_LeadSig` (macro, line 192) `#define FSI_LeadSig`
  - `FSI_StrucSig` (macro, line 193) `#define FSI_StrucSig`
  - `FSI_Free_Count` (macro, line 194) `#define FSI_Free_Count`
  - `FSI_Nxt_Free` (macro, line 195) `#define FSI_Nxt_Free`
  - `FSI_TrailSig` (macro, line 196) `#define FSI_TrailSig`
  - `MBR_Table` (macro, line 198) `#define MBR_Table`
  - `SZ_PTE` (macro, line 199) `#define SZ_PTE`
  - `PTE_Boot` (macro, line 200) `#define PTE_Boot`
  - `PTE_StHead` (macro, line 201) `#define PTE_StHead`
  - `PTE_StSec` (macro, line 202) `#define PTE_StSec`
  - `PTE_StCyl` (macro, line 203) `#define PTE_StCyl`
  - `PTE_System` (macro, line 204) `#define PTE_System`
  - `PTE_EdHead` (macro, line 205) `#define PTE_EdHead`
  - `PTE_EdSec` (macro, line 206) `#define PTE_EdSec`
  - `PTE_EdCyl` (macro, line 207) `#define PTE_EdCyl`
  - `PTE_StLba` (macro, line 208) `#define PTE_StLba`
  - `PTE_SizLba` (macro, line 209) `#define PTE_SizLba`
  - `GPTH_Sign` (macro, line 211) `#define GPTH_Sign`
  - `GPTH_Rev` (macro, line 212) `#define GPTH_Rev`
  - `GPTH_Size` (macro, line 213) `#define GPTH_Size`
  - `GPTH_Bcc` (macro, line 214) `#define GPTH_Bcc`
  - `GPTH_CurLba` (macro, line 215) `#define GPTH_CurLba`
  - `GPTH_BakLba` (macro, line 216) `#define GPTH_BakLba`
  - `GPTH_FstLba` (macro, line 217) `#define GPTH_FstLba`
  - `GPTH_LstLba` (macro, line 218) `#define GPTH_LstLba`
  - `GPTH_DskGuid` (macro, line 219) `#define GPTH_DskGuid`
  - `GPTH_PtOfs` (macro, line 220) `#define GPTH_PtOfs`
  - `GPTH_PtNum` (macro, line 221) `#define GPTH_PtNum`
  - `GPTH_PteSize` (macro, line 222) `#define GPTH_PteSize`
  - `GPTH_PtBcc` (macro, line 223) `#define GPTH_PtBcc`
  - `SZ_GPTE` (macro, line 224) `#define SZ_GPTE`
  - `GPTE_PtGuid` (macro, line 225) `#define GPTE_PtGuid`
  - `GPTE_UpGuid` (macro, line 226) `#define GPTE_UpGuid`
  - `GPTE_FstLba` (macro, line 227) `#define GPTE_FstLba`
  - `GPTE_LstLba` (macro, line 228) `#define GPTE_LstLba`
  - `GPTE_Flags` (macro, line 229) `#define GPTE_Flags`
  - `GPTE_Name` (macro, line 230) `#define GPTE_Name`
  - `ABORT` (macro, line 234) `#define ABORT(fs, res)`
  - `LEAVE_FF` (macro, line 242) `#define LEAVE_FF(fs, res)`
  - `LEAVE_FF` (macro, line 244) `#define LEAVE_FF(fs, res)`
  - `LD2PD` (macro, line 250) `#define LD2PD(vol)`
  - `LD2PT` (macro, line 251) `#define LD2PT(vol)`
  - `LD2PD` (macro, line 253) `#define LD2PD(vol)`
  - `LD2PT` (macro, line 254) `#define LD2PT(vol)`
  - `SS` (macro, line 263) `#define SS(fs)`
  - `SS` (macro, line 265) `#define SS(fs)`
  - `GET_FATTIME` (macro, line 274) `#define GET_FATTIME()`
  - `GET_FATTIME` (macro, line 276) `#define GET_FATTIME()`
  - `TBL_CT437` (macro, line 295) `#define TBL_CT437`
  - `TBL_CT720` (macro, line 303) `#define TBL_CT720`
  - `TBL_CT737` (macro, line 311) `#define TBL_CT737`
  - `TBL_CT771` (macro, line 319) `#define TBL_CT771`
  - `TBL_CT775` (macro, line 327) `#define TBL_CT775`
  - `TBL_CT850` (macro, line 335) `#define TBL_CT850`
  - `TBL_CT852` (macro, line 343) `#define TBL_CT852`
  - `TBL_CT855` (macro, line 351) `#define TBL_CT855`
  - `TBL_CT857` (macro, line 359) `#define TBL_CT857`
  - `TBL_CT860` (macro, line 367) `#define TBL_CT860`
  - `TBL_CT861` (macro, line 375) `#define TBL_CT861`
  - `TBL_CT862` (macro, line 383) `#define TBL_CT862`
  - `TBL_CT863` (macro, line 391) `#define TBL_CT863`
  - `TBL_CT864` (macro, line 399) `#define TBL_CT864`
  - `TBL_CT865` (macro, line 407) `#define TBL_CT865`
  - `TBL_CT866` (macro, line 415) `#define TBL_CT866`
  - `TBL_CT869` (macro, line 423) `#define TBL_CT869`
  - `TBL_DC932` (macro, line 435) `#define TBL_DC932`
  - `TBL_DC936` (macro, line 436) `#define TBL_DC936`
  - `TBL_DC949` (macro, line 437) `#define TBL_DC949`
  - `TBL_DC950` (macro, line 438) `#define TBL_DC950`
  - `MERGE_2STR` (macro, line 442) `#define MERGE_2STR(a, b)`
  - `MKCVTBL` (macro, line 443) `#define MKCVTBL(hd, cp)`
  - `DEF_NAMEBUFF` (macro, line 502) `#define DEF_NAMEBUFF`
  - `INIT_NAMEBUFF` (macro, line 503) `#define INIT_NAMEBUFF(fs)`
  - `FREE_NAMEBUFF` (macro, line 504) `#define FREE_NAMEBUFF()`
  - `LEAVE_MKFS` (macro, line 505) `#define LEAVE_MKFS(res)`
  - `MAXDIRB` (macro, line 518) `#define MAXDIRB(nc)`
  - `DEF_NAMEBUFF` (macro, line 525) `#define DEF_NAMEBUFF`
  - `INIT_NAMEBUFF` (macro, line 526) `#define INIT_NAMEBUFF(fs)`
  - `FREE_NAMEBUFF` (macro, line 527) `#define FREE_NAMEBUFF()`
  - `LEAVE_MKFS` (macro, line 528) `#define LEAVE_MKFS(res)`
  - `DEF_NAMEBUFF` (macro, line 532) `#define DEF_NAMEBUFF`
  - `INIT_NAMEBUFF` (macro, line 533) `#define INIT_NAMEBUFF(fs)`
  - `FREE_NAMEBUFF` (macro, line 534) `#define FREE_NAMEBUFF()`
  - `DEF_NAMEBUFF` (macro, line 536) `#define DEF_NAMEBUFF`
  - `INIT_NAMEBUFF` (macro, line 537) `#define INIT_NAMEBUFF(fs)`
  - `FREE_NAMEBUFF` (macro, line 538) `#define FREE_NAMEBUFF()`
  - `LEAVE_MKFS` (macro, line 540) `#define LEAVE_MKFS(res)`
  - `DEF_NAMEBUFF` (macro, line 544) `#define DEF_NAMEBUFF`
  - `INIT_NAMEBUFF` (macro, line 545) `#define INIT_NAMEBUFF(fs)`
  - `FREE_NAMEBUFF` (macro, line 546) `#define FREE_NAMEBUFF()`
  - `DEF_NAMEBUFF` (macro, line 548) `#define DEF_NAMEBUFF`
  - `INIT_NAMEBUFF` (macro, line 549) `#define INIT_NAMEBUFF(fs)`
  - `FREE_NAMEBUFF` (macro, line 550) `#define FREE_NAMEBUFF()`
  - `LEAVE_MKFS` (macro, line 552) `#define LEAVE_MKFS(res)`
  - `MAX_MALLOC` (macro, line 553) `#define MAX_MALLOC`
  - `CODEPAGE` (macro, line 568) `#define CODEPAGE`
  - `CODEPAGE` (macro, line 596) `#define CODEPAGE`
  - `CODEPAGE` (macro, line 600) `#define CODEPAGE`
  - `DIR_READ_FILE` (macro, line 2331) `#define DIR_READ_FILE(dp)`
  - `DIR_READ_LABEL` (macro, line 2332) `#define DIR_READ_LABEL(dp)`
  - `FIND_RECURS` (macro, line 2804) `#define FIND_RECURS`
  - `N_SEC_TRACK` (macro, line 5893) `#define N_SEC_TRACK`
  - `GPT_ALIGN` (macro, line 5894) `#define	GPT_ALIGN`
  - `GPT_ITEMS` (macro, line 5895) `#define GPT_ITEMS`
  - `SZ_PUTC_BUF` (macro, line 6716) `#define SZ_PUTC_BUF`
  - `SZ_NUM_BUF` (macro, line 6717) `#define SZ_NUM_BUF`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/ff.h
- Layer: utility
- Doc: ----------------------------------------------------------------------------
- Language: h
- Symbols:
  - `PARTITION` (struct, line 116)
  - `FFXCWDL` (struct, line 136)
  - `FFXCWDS` (struct, line 141)
  - `FATFS` (struct, line 150)
  - `FFOBJID` (struct, line 195)
  - `FIL` (struct, line 218)
  - `FILINFO` (struct, line 260)
  - `MKFS_PARM` (struct, line 281)
  - `QWORD` (type_alias, line 42) `typedef unsigned __int64 QWORD;`
  - `UINT` (type_alias, line 50) `typedef unsigned int UINT;`
  - `BYTE` (type_alias, line 51) `typedef unsigned char BYTE;`
  - `WORD` (type_alias, line 52) `typedef uint16_t WORD;`
  - `DWORD` (type_alias, line 53) `typedef uint32_t DWORD;`
  - `QWORD` (type_alias, line 54) `typedef uint64_t QWORD;`
  - `WCHAR` (type_alias, line 55) `typedef WORD WCHAR;`
  - `UINT` (type_alias, line 59) `typedef unsigned int UINT;`
  - `BYTE` (type_alias, line 60) `typedef unsigned char BYTE;`
  - `WORD` (type_alias, line 61) `typedef unsigned short WORD;`
  - `DWORD` (type_alias, line 62) `typedef unsigned long DWORD;`
  - `WCHAR` (type_alias, line 63) `typedef WORD WCHAR;`
  - `FSIZE_t` (type_alias, line 73) `typedef QWORD FSIZE_t;`
  - `LBA_t` (type_alias, line 75) `typedef QWORD LBA_t;`
  - `LBA_t` (type_alias, line 77) `typedef DWORD LBA_t;`
  - `FSIZE_t` (type_alias, line 83) `typedef DWORD FSIZE_t;`
  - `LBA_t` (type_alias, line 84) `typedef DWORD LBA_t;`
  - `TCHAR` (type_alias, line 92) `typedef WCHAR TCHAR;`
  - `TCHAR` (type_alias, line 96) `typedef char TCHAR;`
  - `TCHAR` (type_alias, line 100) `typedef DWORD TCHAR;`
  - `TCHAR` (type_alias, line 106) `typedef char TCHAR;`
  - `f_putc` (function, line 353) `int f_putc (TCHAR c, FIL* fp);`
  - `f_puts` (function, line 354) `int f_puts (const TCHAR* str, FIL* cp);`
  - `f_printf` (function, line 355) `int f_printf (FIL* fp, const TCHAR* str, ...);`
  - `f_gets` (function, line 356) `TCHAR* f_gets (TCHAR* buff, int len, FIL* fp);`
  - `ff_memalloc` (function, line 394) `void* ff_memalloc (UINT msize);`
  - `ff_memfree` (function, line 395) `void ff_memfree (void* mblock);`
  - `ff_mutex_create` (function, line 398) `int ff_mutex_create (int vol);`
  - `ff_mutex_delete` (function, line 399) `void ff_mutex_delete (int vol);`
  - `ff_mutex_take` (function, line 400) `int ff_mutex_take (int vol);`
  - `ff_mutex_give` (function, line 401) `void ff_mutex_give (int vol);`
  - `QWORD` (variable, line 26) `extern "C" { #endif #if !defined(FFCONF_DEF) #include "ffconf.h" /* FatFs configuration options */ #endif #if FF_DEFINED != FFCONF_DEF #error Wrong configuration file (ffconf.h). #endif /* Integer typ`
  - `VolToPart` (variable, line 120) `extern PARTITION VolToPart[];`
  - `VolumeStr` (variable, line 125) `extern const char* VolumeStr[FF_VOLUMES];`
  - `FF_DEFINED` (macro, line 23) `#define FF_DEFINED`
  - `FF_INTDEF` (macro, line 40) `#define FF_INTDEF`
  - `isnan` (macro, line 44) `#define isnan(v)`
  - `isinf` (macro, line 45) `#define isinf(v)`
  - `FF_INTDEF` (macro, line 48) `#define FF_INTDEF`
  - `FF_INTDEF` (macro, line 58) `#define FF_INTDEF`
  - `_T` (macro, line 93) `#define _T(x)`
  - `_TEXT` (macro, line 94) `#define _TEXT(x)`
  - `_T` (macro, line 97) `#define _T(x)`
  - `_TEXT` (macro, line 98) `#define _TEXT(x)`
  - `_T` (macro, line 101) `#define _T(x)`
  - `_TEXT` (macro, line 102) `#define _TEXT(x)`
  - `_T` (macro, line 107) `#define _T(x)`
  - `_TEXT` (macro, line 108) `#define _TEXT(x)`
  - `f_eof` (macro, line 360) `#define f_eof(fp)`
  - `f_error` (macro, line 361) `#define f_error(fp)`
  - `f_tell` (macro, line 362) `#define f_tell(fp)`
  - `f_size` (macro, line 363) `#define f_size(fp)`
  - `f_rewind` (macro, line 364) `#define f_rewind(fp)`
  - `f_rewinddir` (macro, line 365) `#define f_rewinddir(dp)`
  - `f_rmdir` (macro, line 366) `#define f_rmdir(path)`
  - `f_unmount` (macro, line 367) `#define f_unmount(path)`
  - `FA_READ` (macro, line 412) `#define	FA_READ`
  - `FA_WRITE` (macro, line 413) `#define	FA_WRITE`
  - `FA_OPEN_EXISTING` (macro, line 414) `#define	FA_OPEN_EXISTING`
  - `FA_CREATE_NEW` (macro, line 415) `#define	FA_CREATE_NEW`
  - `FA_CREATE_ALWAYS` (macro, line 416) `#define	FA_CREATE_ALWAYS`
  - `FA_OPEN_ALWAYS` (macro, line 417) `#define	FA_OPEN_ALWAYS`
  - `FA_OPEN_APPEND` (macro, line 418) `#define	FA_OPEN_APPEND`
  - `CREATE_LINKMAP` (macro, line 421) `#define CREATE_LINKMAP`
  - `FM_FAT` (macro, line 424) `#define FM_FAT`
  - `FM_FAT32` (macro, line 425) `#define FM_FAT32`
  - `FM_EXFAT` (macro, line 426) `#define FM_EXFAT`
  - `FM_ANY` (macro, line 427) `#define FM_ANY`
  - `FM_SFD` (macro, line 428) `#define FM_SFD`
  - `FS_FAT12` (macro, line 431) `#define FS_FAT12`
  - `FS_FAT16` (macro, line 432) `#define FS_FAT16`
  - `FS_FAT32` (macro, line 433) `#define FS_FAT32`
  - `FS_EXFAT` (macro, line 434) `#define FS_EXFAT`
  - `AM_RDO` (macro, line 437) `#define	AM_RDO`
  - `AM_HID` (macro, line 438) `#define	AM_HID`
  - `AM_SYS` (macro, line 439) `#define	AM_SYS`
  - `AM_DIR` (macro, line 440) `#define AM_DIR`
  - `AM_ARC` (macro, line 441) `#define AM_ARC`
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

## FatFs-R0.16/source/ffconf.h
- Layer: utility
- Doc: ---------------------------------------------------------------------------
- Language: h
- Symbols:
  - `FFCONF_DEF` (macro, line 5) `#define FFCONF_DEF`
  - `FF_FS_READONLY` (macro, line 11) `#define FF_FS_READONLY`
  - `FF_FS_MINIMIZE` (macro, line 18) `#define FF_FS_MINIMIZE`
  - `FF_USE_FIND` (macro, line 28) `#define FF_USE_FIND`
  - `FF_USE_MKFS` (macro, line 33) `#define FF_USE_MKFS`
  - `FF_USE_FASTSEEK` (macro, line 37) `#define FF_USE_FASTSEEK`
  - `FF_USE_EXPAND` (macro, line 41) `#define FF_USE_EXPAND`
  - `FF_USE_CHMOD` (macro, line 45) `#define FF_USE_CHMOD`
  - `FF_USE_LABEL` (macro, line 50) `#define FF_USE_LABEL`
  - `FF_USE_FORWARD` (macro, line 55) `#define FF_USE_FORWARD`
  - `FF_USE_STRFUNC` (macro, line 59) `#define FF_USE_STRFUNC`
  - `FF_PRINT_LLI` (macro, line 60) `#define FF_PRINT_LLI`
  - `FF_PRINT_FLOAT` (macro, line 61) `#define FF_PRINT_FLOAT`
  - `FF_STRF_ENCODE` (macro, line 62) `#define FF_STRF_ENCODE`
  - `FF_CODE_PAGE` (macro, line 87) `#define FF_CODE_PAGE`
  - `FF_USE_LFN` (macro, line 116) `#define FF_USE_LFN`
  - `FF_MAX_LFN` (macro, line 117) `#define FF_MAX_LFN`
  - `FF_LFN_UNICODE` (macro, line 136) `#define FF_LFN_UNICODE`
  - `FF_LFN_BUF` (macro, line 148) `#define FF_LFN_BUF`
  - `FF_SFN_BUF` (macro, line 149) `#define FF_SFN_BUF`
  - `FF_FS_RPATH` (macro, line 156) `#define FF_FS_RPATH`
  - `FF_PATH_DEPTH` (macro, line 165) `#define FF_PATH_DEPTH`
  - `FF_VOLUMES` (macro, line 181) `#define FF_VOLUMES`
  - `FF_STR_VOLUME_ID` (macro, line 185) `#define FF_STR_VOLUME_ID`
  - `FF_VOLUME_STRS` (macro, line 186) `#define FF_VOLUME_STRS`
  - `FF_MULTI_PARTITION` (macro, line 199) `#define FF_MULTI_PARTITION`
  - `FF_MIN_SS` (macro, line 208) `#define FF_MIN_SS`
  - `FF_MAX_SS` (macro, line 209) `#define FF_MAX_SS`
  - `FF_LBA64` (macro, line 218) `#define FF_LBA64`
  - `FF_MIN_GPT` (macro, line 223) `#define FF_MIN_GPT`
  - `FF_USE_TRIM` (macro, line 228) `#define FF_USE_TRIM`
  - `FF_FS_TINY` (macro, line 239) `#define FF_FS_TINY`
  - `FF_FS_EXFAT` (macro, line 246) `#define FF_FS_EXFAT`
  - `FF_FS_NORTC` (macro, line 252) `#define FF_FS_NORTC`
  - `FF_NORTC_MON` (macro, line 253) `#define FF_NORTC_MON`
  - `FF_NORTC_MDAY` (macro, line 254) `#define FF_NORTC_MDAY`
  - `FF_NORTC_YEAR` (macro, line 255) `#define FF_NORTC_YEAR`
  - `FF_FS_CRTIME` (macro, line 266) `#define FF_FS_CRTIME`
  - `FF_FS_NOFSINFO` (macro, line 271) `#define FF_FS_NOFSINFO`
  - `FF_FS_LOCK` (macro, line 283) `#define FF_FS_LOCK`
  - `FF_FS_REENTRANT` (macro, line 295) `#define FF_FS_REENTRANT`
  - `FF_FS_TIMEOUT` (macro, line 296) `#define FF_FS_TIMEOUT`
- Imported by: `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/ffsystem.c
- Layer: utility
- Doc: ------------------------------------------------------------------------
- Language: c
- Symbols:
  - `ff_memalloc` (function, line 17) `void* ff_memalloc (	/* Returns pointer to the allocated memory block (null if not enough core) */...`
  - `ff_memfree` (function, line 25) `void ff_memfree (
	void* mblock	/* Pointer to the memory block to free (no effect if null) */
)`
  - `ff_mutex_create` (function, line 79) `int ff_mutex_create (	/* Returns 1:Function succeeded or 0:Could not create the mutex */
	int vol...`
  - `ff_mutex_delete` (function, line 120) `void ff_mutex_delete (	/* Returns 1:Function succeeded or 0:Could not delete due to an error */
	...`
  - `ff_mutex_take` (function, line 152) `int ff_mutex_take (	/* Returns 1:Succeeded or 0:Timeout */
	int vol			/* Mutex ID: Volume mutex (...`
  - `ff_mutex_give` (function, line 185) `void ff_mutex_give (
	int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (...`
  - `OS_TYPE` (macro, line 42) `#define OS_TYPE`
- Depends on: `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/ffunicode.c
- Layer: utility
- Doc: ------------------------------------------------------------------------
- Language: c
- Symbols:
  - `ff_uni2oem` (function, line 15222) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
  - `ff_oem2uni` (function, line 15244) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
  - `ff_uni2oem` (function, line 15275) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
  - `ff_oem2uni` (function, line 15311) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
  - `ff_uni2oem` (function, line 15358) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
  - `ff_oem2uni` (function, line 15410) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
  - `ff_wtoupper` (function, line 15464) `DWORD ff_wtoupper (	/* Returns up-converted code point */
	DWORD uni		/* Unicode code point to be...`
  - `MERGE2` (macro, line 30) `#define MERGE2(a, b)`
  - `CVTBL` (macro, line 31) `#define CVTBL(tbl, cp)`
- Depends on: `FatFs-R0.16/source/ff.h`
