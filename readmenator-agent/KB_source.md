# Subsystem: source

## FatFs-R0.16/source/diskio.c
- Layer: infrastructure
- Doc: -----------------------------------------------------------------------
- Language: c
- Symbols:
  - `disk_status` (function, line 26) `DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)`
  - `disk_initialize` (function, line 64) `DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)`
  - `disk_read` (function, line 102) `DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		...`
  - `disk_write` (function, line 152) `DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE ...`
  - `disk_ioctl` (function, line 201) `DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code *...`
  - `DEV_FLASH` (macro, line 18)
  - `DEV_MMC` (macro, line 19)
  - `DEV_USB` (macro, line 20)

## FatFs-R0.16/source/diskio.h
- Layer: infrastructure
- Doc: -----------------------------------------------------------------------
- Language: h
- Symbols:
  - `_DISKIO_DEFINED` (macro, line 6)
  - `STA_NOINIT` (macro, line 37)
  - `STA_NODISK` (macro, line 39)
  - `STA_PROTECT` (macro, line 40)
  - `CTRL_SYNC` (macro, line 46)
  - `GET_SECTOR_COUNT` (macro, line 47)
  - `GET_SECTOR_SIZE` (macro, line 48)
  - `GET_BLOCK_SIZE` (macro, line 49)
  - `CTRL_TRIM` (macro, line 50)
  - `CTRL_POWER` (macro, line 53)
  - `CTRL_LOCK` (macro, line 54)
  - `CTRL_EJECT` (macro, line 55)
  - `CTRL_FORMAT` (macro, line 56)
  - `MMC_GET_TYPE` (macro, line 59)
  - `MMC_GET_CSD` (macro, line 60)
  - `MMC_GET_CID` (macro, line 61)
  - `MMC_GET_OCR` (macro, line 62)
  - `MMC_GET_SDSTAT` (macro, line 63)
  - `ISDIO_READ` (macro, line 64)
  - `ISDIO_WRITE` (macro, line 65)
  - `ISDIO_MRITE` (macro, line 66)
  - `ATA_GET_REV` (macro, line 69)
  - `ATA_GET_MODEL` (macro, line 70)
  - `ATA_GET_SN` (macro, line 71)

## FatFs-R0.16/source/ff.c
- Layer: utility
- Doc: ----------------------------------------------------------------------------
- Language: c
- Symbols:
  - `dbc_1st` (function, line 693) `static int dbc_1st (BYTE c)`
  - `dbc_2nd` (function, line 713) `static int dbc_2nd (BYTE c)`
  - `tchar2uni` (function, line 737) `static DWORD tchar2uni (	/* Returns a character in UTF-16 encoding (>=0x10000 on surrogate pair, ...`
  - `put_utf` (function, line 806) `static UINT put_utf (	/* Returns number of encoding units written (0:buffer overflow or wrong enc...`
  - `lock_volume` (function, line 895) `static int lock_volume (	/* 1:Ok, 0:timeout */
	FATFS* fs,				/* Filesystem object to lock */
	in...`
  - `unlock_volume` (function, line 920) `static void unlock_volume (
	FATFS* fs,		/* Filesystem object */
	FRESULT res		/* Result code to ...`
  - `chk_share` (function, line 946) `static FRESULT chk_share (	/* Check if the file can be accessed */
	DIR* dp,		/* Directory object...`
  - `inc_share` (function, line 981) `static UINT inc_share (	/* Increment object open counter and returns its index (0:Internal error)...`
  - `dec_share` (function, line 1012) `static FRESULT dec_share (	/* Decrement object open counter */
	UINT i			/* Semaphore index (1..)...`
  - `clear_share` (function, line 1036) `static void clear_share (	/* Clear all lock entries of the volume */
	FATFS* fs
)`
  - `sync_window` (function, line 1057) `static FRESULT sync_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs			/* Filesystem object...`
  - `move_window` (function, line 1077) `static FRESULT move_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs,		/* Filesystem object...`
  - `sync_fs` (function, line 1109) `static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs		/* Filesystem object */
)`
  - `clst2sect` (function, line 1158) `static LBA_t clst2sect (	/* !=0:Sector number, 0:Failed (invalid cluster#) */
	FATFS* fs,		/* Fil...`
  - `get_fat` (function, line 1175) `static DWORD get_fat (		/* 0xFFFFFFFF:Disk error, 1:Internal error, 2..0x7FFFFFFF:Cluster status ...`
  - `put_fat` (function, line 1253) `static FRESULT put_fat (	/* FR_OK(0):succeeded, !=0:error */
	FATFS* fs,		/* Corresponding filesy...`
  - `find_bitmap` (function, line 1318) `static DWORD find_bitmap (	/* 0:Not found, 2..:Cluster block found, 0xFFFFFFFF:Disk error */
	FAT...`
  - `change_bitmap` (function, line 1358) `static FRESULT change_bitmap (
	FATFS* fs,	/* Filesystem object */
	DWORD clst,	/* Cluster number...`
  - `fill_first_frag` (function, line 1394) `static FRESULT fill_first_frag (
	FFOBJID* obj	/* Pointer to the corresponding object */
)`
  - `fill_last_frag` (function, line 1417) `static FRESULT fill_last_frag (
	FFOBJID* obj,	/* Pointer to the corresponding object */
	DWORD l...`
  - `remove_chain` (function, line 1443) `static FRESULT remove_chain (	/* FR_OK(0):succeeded, !=0:error */
	FFOBJID* obj,		/* Correspondin...`
  - `create_chain` (function, line 1538) `static DWORD create_chain (	/* 0:No free cluster, 1:Internal error, 0xFFFFFFFF:Disk error, >=2:Ne...`
  - `clmt_clust` (function, line 1643) `static DWORD clmt_clust (	/* <2:Error, >=2:Cluster number */
	FIL* fp,		/* Pointer to the file ob...`
  - `dir_clear` (function, line 1675) `static FRESULT dir_clear (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS *fs,		/* Filesystem object *...`
  - `dir_sdi` (function, line 1713) `static FRESULT dir_sdi (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,		/* Pointer to directory o...`
  - `dir_next` (function, line 1761) `static FRESULT dir_next (	/* FR_OK(0):succeeded, FR_NO_FILE:End of table, FR_DENIED:Could not str...`
  - `dir_alloc` (function, line 1822) `static FRESULT dir_alloc (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,				/* Pointer to the dir...`
  - `ld_clust` (function, line 1864) `static DWORD ld_clust (	/* Returns the top cluster value of the SFN entry */
	FATFS* fs,			/* Poi...`
  - `st_clust` (function, line 1882) `static void st_clust (
	FATFS* fs,	/* Pointer to the fs object */
	BYTE* dir,	/* Pointer to the k...`
  - `cmp_lfn` (function, line 1901) `static int cmp_lfn (		/* 1:matched, 0:not matched */
	const WCHAR* lfnbuf,	/* Pointer to the LFN ...`
  - `pick_lfn` (function, line 1937) `static int pick_lfn (	/* 1:succeeded, 0:buffer overflow or invalid LFN entry */
	WCHAR* lfnbuf,		...`
  - `put_lfn` (function, line 1975) `static void put_lfn (
	const WCHAR* lfn,	/* Pointer to the LFN */
	BYTE* dir,			/* Pointer to the...`
  - `gen_numname` (function, line 2012) `static void gen_numname (
	BYTE* dst,			/* Pointer to the buffer to store numbered SFN */
	const ...`
  - `sum_sfn` (function, line 2069) `static BYTE sum_sfn (
	const BYTE* dir		/* Pointer to the SFN entry */
)`
  - `xdir_sum` (function, line 2091) `static WORD xdir_sum (	/* Get checksum of the directoly entry block */
	const BYTE* dir		/* Direc...`
  - `xname_sum` (function, line 2110) `static WORD xname_sum (	/* Get check sum (to be used as hash) of the file name */
	const WCHAR* n...`
  - `xsum32` (function, line 2131) `static DWORD xsum32 (	/* Returns 32-bit checksum */
	BYTE  dat,			/* Byte to be calculated (byte-...`
  - `load_xdir` (function, line 2146) `static FRESULT load_xdir (	/* FR_INT_ERR: invalid entry block */
	DIR* dp					/* Reading director...`
  - `init_alloc_info` (function, line 2198) `static void init_alloc_info (
	FFOBJID* dobj,	/* Object allocation information to be initialized ...`
  - `load_obj_xdir` (function, line 2224) `static FRESULT load_obj_xdir (
	DIR* dp,			/* Blank directory object to be used to access contain...`
  - `store_xdir` (function, line 2253) `static FRESULT store_xdir (
	DIR* dp				/* Pointer to the directory object */
)`
  - `create_xdir` (function, line 2287) `static void create_xdir (
	BYTE* dirb,			/* Pointer to the directory entry block buffer */
	const...`
  - `dir_read` (function, line 2333) `static FRESULT dir_read (
	DIR* dp,		/* Pointer to the directory object */
	int vol			/* Filtered...`
  - `dir_find` (function, line 2411) `static FRESULT dir_find (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp					/* Pointer to the dire...`
  - `dir_register` (function, line 2493) `static FRESULT dir_register (	/* FR_OK:succeeded, FR_DENIED:no free entry or too many SFN collisi...`
  - `dir_remove` (function, line 2606) `static FRESULT dir_remove (	/* FR_OK:Succeeded, FR_DISK_ERR:A disk error */
	DIR* dp					/* Direc...`
  - `get_fileinfo` (function, line 2652) `static void get_fileinfo (
	DIR* dp,			/* Pointer to the directory object */
	FILINFO* fno		/* Po...`
  - `get_achar` (function, line 2805) `static DWORD get_achar (	/* Get a character and advance ptr */
	const TCHAR** ptr		/* Pointer to ...`
  - `pattern_match` (function, line 2836) `static int pattern_match (	/* 0:mismatched, 1:matched */
	const TCHAR* pat,	/* Matching pattern *...`
  - `create_name` (function, line 2891) `static FRESULT create_name (	/* FR_OK: successful, FR_INVALID_NAME: could not create */
	DIR* dp,...`
  - `follow_path` (function, line 3100) `static FRESULT follow_path (	/* FR_OK(0): successful, !=0: error code */
	DIR* dp,					/* Directo...`
  - `get_ldnumber` (function, line 3219) `static int get_ldnumber (	/* Returns logical drive number (-1:invalid drive number or null pointe...`
  - `crc32` (function, line 3296) `static DWORD crc32 (	/* Returns next CRC value */
	DWORD crc,			/* Current CRC value */
	BYTE d		...`
  - `test_gpt_header` (function, line 3314) `static int test_gpt_header (	/* 0:Invalid, 1:Valid */
	const BYTE* gpth			/* Pointer to the GPT h...`
  - `make_rand` (function, line 3339) `static DWORD make_rand (	/* Returns a seed value for next */
	DWORD seed,				/* Seed value */
	BY...`
  - `check_fs` (function, line 3366) `static UINT check_fs (	/* 0:FAT/FAT32 VBR, 1:exFAT VBR, 2:Not FAT and valid BS, 3:Not FAT and inv...`
  - `find_volume` (function, line 3406) `static UINT find_volume (	/* Returns BS status found in the hosting drive */
	FATFS* fs,		/* File...`
  - `mount_volume` (function, line 3460) `static FRESULT mount_volume (	/* FR_OK(0): successful, !=0: an error occurred */
	const TCHAR** p...`
  - `validate` (function, line 3694) `static FRESULT validate (	/* Returns FR_OK or FR_INVALID_OBJECT */
	FFOBJID* obj,			/* Pointer to...`
  - `f_open` (function, line 3798) `FRESULT f_open (
	FIL* fp,			/* Pointer to the blank file object */
	const TCHAR* path,	/* Pointe...`
  - `f_read` (function, line 3995) `FRESULT f_read (
	FIL* fp, 	/* Open file to be read */
	void* buff,	/* Data buffer to store the r...`
  - `f_write` (function, line 4096) `FRESULT f_write (
	FIL* fp,			/* Open file to be written */
	const void* buff,	/* Data to be writ...`
  - `f_sync` (function, line 4217) `FRESULT f_sync (
	FIL* fp		/* Open file to be synced */
)`
  - `f_close` (function, line 4298) `FRESULT f_close (
	FIL* fp		/* Open file to be closed */
)`
  - `f_chdrive` (function, line 4334) `FRESULT f_chdrive (
	const TCHAR* path		/* Drive number to set */
)`
  - `f_chdir` (function, line 4356) `FRESULT f_chdir (
	const TCHAR* path	/* Pointer to the directory path */
)`
  - `f_getcwd` (function, line 4418) `FRESULT f_getcwd (
	TCHAR* buff,	/* Pointer to the buffer to store the current direcotry path */
...`
  - `f_lseek` (function, line 4554) `FRESULT f_lseek (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t ofs		/* File pointer from ...`
  - `f_opendir` (function, line 4718) `FRESULT f_opendir (
	DIR* dp,			/* Pointer to directory object to create */
	const TCHAR* path	/*...`
  - `f_closedir` (function, line 4780) `FRESULT f_closedir (
	DIR *dp		/* Pointer to the directory object to be closed */
)`
  - `f_readdir` (function, line 4810) `FRESULT f_readdir (
	DIR* dp,			/* Pointer to the open directory object */
	FILINFO* fno		/* Poin...`
  - `f_findnext` (function, line 4849) `FRESULT f_findnext (
	DIR* dp,		/* Pointer to the open directory object */
	FILINFO* fno	/* Point...`
  - `f_findfirst` (function, line 4874) `FRESULT f_findfirst (
	DIR* dp,				/* Pointer to the blank directory object */
	FILINFO* fno,			/...`
  - `f_stat` (function, line 4901) `FRESULT f_stat (
	const TCHAR* path,	/* Pointer to the file path */
	FILINFO* fno		/* Pointer to ...`
  - `f_getfree` (function, line 4938) `FRESULT f_getfree (
	const TCHAR* path,	/* Logical drive number */
	DWORD* nclst,		/* Pointer to ...`
  - `f_truncate` (function, line 5035) `FRESULT f_truncate (
	FIL* fp		/* Pointer to the file object */
)`
  - `f_unlink` (function, line 5086) `FRESULT f_unlink (
	const TCHAR* path		/* Pointer to the file or directory path */
)`
  - `f_mkdir` (function, line 5175) `FRESULT f_mkdir (
	const TCHAR* path		/* Pointer to the directory path */
)`
  - `f_rename` (function, line 5260) `FRESULT f_rename (
	const TCHAR* path_old,	/* Pointer to the object name to be renamed */
	const ...`
  - `f_chmod` (function, line 5384) `FRESULT f_chmod (
	const TCHAR* path,	/* Pointer to the file path */
	BYTE attr,			/* Attribute b...`
  - `f_utime` (function, line 5433) `FRESULT f_utime (
	const TCHAR* path,	/* Pointer to the file/directory name */
	const FILINFO* fn...`
  - `f_getlabel` (function, line 5501) `FRESULT f_getlabel (
	const TCHAR* path,	/* Logical drive number */
	TCHAR* label,		/* Buffer to ...`
  - `f_setlabel` (function, line 5602) `FRESULT f_setlabel (
	const TCHAR* label	/* Volume label to set with heading logical drive number...`
  - `f_expand` (function, line 5725) `FRESULT f_expand (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t fsz,	/* File size to be e...`
  - `f_forward` (function, line 5821) `FRESULT f_forward (
	FIL* fp, 						/* Pointer to the file object */
	UINT (*func)(const BYTE*,UI...`
  - `create_partition` (function, line 5899) `static FRESULT create_partition (
	BYTE drv,			/* Physical drive number */
	const LBA_t plst[],	/...`
  - `f_mkfs` (function, line 6040) `FRESULT f_mkfs (
	const TCHAR* path,		/* Logical drive number */
	const MKFS_PARM* opt,	/* Format...`
  - `f_fdisk` (function, line 6547) `FRESULT f_fdisk (
	BYTE pdrv,			/* Physical drive number */
	const LBA_t ptbl[],	/* Pointer to th...`
  - `f_gets` (function, line 6587) `TCHAR* f_gets (
	TCHAR* buff,	/* Pointer to the buffer to store read string */
	int len,		/* Size...`
  - `putc_bfd` (function, line 6739) `static void putc_bfd (putbuff* pb, TCHAR c)`
  - `putc_flush` (function, line 6870) `static int putc_flush (putbuff* pb)`
  - `putc_init` (function, line 6885) `static void putc_init (putbuff* pb, FIL* fp)`
  - `f_putc` (function, line 6891) `int f_putc (
	TCHAR c,	/* A character to be output */
	FIL* fp		/* Pointer to the file object */
)`
  - `f_puts` (function, line 6913) `int f_puts (
	const TCHAR* str,	/* Pointer to the string to be output */
	FIL* fp				/* Pointer t...`
  - `ftoa` (function, line 6978) `static void ftoa (
	char* buf,	/* Buffer to output the floating point string */
	double val,	/* V...`
  - `f_printf` (function, line 7054) `int f_printf (
	FIL* fp,			/* Pointer to the file object */
	const TCHAR* fmt,	/* Pointer to the ...`
  - `f_setcp` (function, line 7225) `FRESULT f_setcp (
	WORD cp		/* Value to be set as active code page */
)`
  - `MAX_DIR` (macro, line 38)
  - `MAX_DIR_EX` (macro, line 39)
  - `MAX_FAT12` (macro, line 40)
  - `MAX_FAT16` (macro, line 41)
  - `MAX_FAT32` (macro, line 42)
  - `MAX_EXFAT` (macro, line 43)
  - `IsUpper` (macro, line 47)
  - `IsLower` (macro, line 48)
  - `IsDigit` (macro, line 49)
  - `IsSeparator` (macro, line 50)
  - `IsTerminator` (macro, line 51)
  - `IsSurrogate` (macro, line 52)
  - `IsSurrogateH` (macro, line 53)
  - `IsSurrogateL` (macro, line 54)
  - `FA_SEEKEND` (macro, line 58)
  - `FA_MODIFIED` (macro, line 59)
  - `FA_DIRTY` (macro, line 60)
  - `AM_VOL` (macro, line 64)
  - `AM_LFN` (macro, line 65)
  - `AM_MASK` (macro, line 66)
  - `AM_MASKX` (macro, line 67)
  - `NSFLAG` (macro, line 71)
  - `NS_LOSS` (macro, line 72)
  - `NS_LFN` (macro, line 73)
  - `NS_LAST` (macro, line 74)
  - `NS_BODY` (macro, line 75)
  - `NS_EXT` (macro, line 76)
  - `NS_DOT` (macro, line 77)
  - `NS_NOLFN` (macro, line 78)
  - `NS_NONAME` (macro, line 79)
  - `ET_BITMAP` (macro, line 83)
  - `ET_UPCASE` (macro, line 84)
  - `ET_VLABEL` (macro, line 85)
  - `ET_FILEDIR` (macro, line 86)
  - `ET_STREAM` (macro, line 87)
  - `ET_FILENAME` (macro, line 88)
  - `BS_JmpBoot` (macro, line 93)
  - `BS_OEMName` (macro, line 95)
  - `BPB_BytsPerSec` (macro, line 96)
  - `BPB_SecPerClus` (macro, line 97)
  - `BPB_RsvdSecCnt` (macro, line 98)
  - `BPB_NumFATs` (macro, line 99)
  - `BPB_RootEntCnt` (macro, line 100)
  - `BPB_TotSec16` (macro, line 101)
  - `BPB_Media` (macro, line 102)
  - `BPB_FATSz16` (macro, line 103)
  - `BPB_SecPerTrk` (macro, line 104)
  - `BPB_NumHeads` (macro, line 105)
  - `BPB_HiddSec` (macro, line 106)
  - `BPB_TotSec32` (macro, line 107)
  - `BS_DrvNum` (macro, line 108)
  - `BS_NTres` (macro, line 109)
  - `BS_BootSig` (macro, line 110)
  - `BS_VolID` (macro, line 111)
  - `BS_VolLab` (macro, line 112)
  - `BS_FilSysType` (macro, line 113)
  - `BS_BootCode` (macro, line 114)
  - `BS_55AA` (macro, line 115)
  - `BPB_FATSz32` (macro, line 116)
  - `BPB_ExtFlags32` (macro, line 118)
  - `BPB_FSVer32` (macro, line 119)
  - `BPB_RootClus32` (macro, line 120)
  - `BPB_FSInfo32` (macro, line 121)
  - `BPB_BkBootSec32` (macro, line 122)
  - `BS_DrvNum32` (macro, line 123)
  - `BS_NTres32` (macro, line 124)
  - `BS_BootSig32` (macro, line 125)
  - `BS_VolID32` (macro, line 126)
  - `BS_VolLab32` (macro, line 127)
  - `BS_FilSysType32` (macro, line 128)
  - `BS_BootCode32` (macro, line 129)
  - `BPB_ZeroedEx` (macro, line 130)
  - `BPB_VolOfsEx` (macro, line 132)
  - `BPB_TotSecEx` (macro, line 133)
  - `BPB_FatOfsEx` (macro, line 134)
  - `BPB_FatSzEx` (macro, line 135)
  - `BPB_DataOfsEx` (macro, line 136)
  - `BPB_NumClusEx` (macro, line 137)
  - `BPB_RootClusEx` (macro, line 138)
  - `BPB_VolIDEx` (macro, line 139)
  - `BPB_FSVerEx` (macro, line 140)
  - `BPB_VolFlagEx` (macro, line 141)
  - `BPB_BytsPerSecEx` (macro, line 142)
  - `BPB_SecPerClusEx` (macro, line 143)
  - `BPB_NumFATsEx` (macro, line 144)
  - `BPB_DrvNumEx` (macro, line 145)
  - `BPB_PercInUseEx` (macro, line 146)
  - `BPB_RsvdEx` (macro, line 147)
  - `BS_BootCodeEx` (macro, line 148)
  - `DIR_Name` (macro, line 149)
  - `DIR_Attr` (macro, line 151)
  - `DIR_NTres` (macro, line 152)
  - `DIR_CrtTime10` (macro, line 153)
  - `DIR_CrtTime` (macro, line 154)
  - `DIR_LstAccDate` (macro, line 155)
  - `DIR_FstClusHI` (macro, line 156)
  - `DIR_ModTime` (macro, line 157)
  - `DIR_FstClusLO` (macro, line 158)
  - `DIR_FileSize` (macro, line 159)
  - `LDIR_Ord` (macro, line 160)
  - `LDIR_Attr` (macro, line 161)
  - `LDIR_Type` (macro, line 162)
  - `LDIR_Chksum` (macro, line 163)
  - `LDIR_FstClusLO` (macro, line 164)
  - `XDIR_Type` (macro, line 165)
  - `XDIR_NumLabel` (macro, line 166)
  - `XDIR_Label` (macro, line 167)
  - `XDIR_CaseSum` (macro, line 168)
  - `XDIR_NumSec` (macro, line 169)
  - `XDIR_SetSum` (macro, line 170)
  - `XDIR_Attr` (macro, line 171)
  - `XDIR_CrtTime` (macro, line 172)
  - `XDIR_ModTime` (macro, line 173)
  - `XDIR_AccTime` (macro, line 174)
  - `XDIR_CrtTime10` (macro, line 175)
  - `XDIR_ModTime10` (macro, line 176)
  - `XDIR_CrtTZ` (macro, line 177)
  - `XDIR_ModTZ` (macro, line 178)
  - `XDIR_AccTZ` (macro, line 179)
  - `XDIR_GenFlags` (macro, line 180)
  - `XDIR_NumName` (macro, line 181)
  - `XDIR_NameHash` (macro, line 182)
  - `XDIR_ValidFileSize` (macro, line 183)
  - `XDIR_FstClus` (macro, line 184)
  - `XDIR_FileSize` (macro, line 185)
  - `SZDIRE` (macro, line 186)
  - `DDEM` (macro, line 188)
  - `RDDEM` (macro, line 189)
  - `LLEF` (macro, line 190)
  - `FSI_LeadSig` (macro, line 191)
  - `FSI_StrucSig` (macro, line 193)
  - `FSI_Free_Count` (macro, line 194)
  - `FSI_Nxt_Free` (macro, line 195)
  - `FSI_TrailSig` (macro, line 196)
  - `MBR_Table` (macro, line 197)
  - `SZ_PTE` (macro, line 199)
  - `PTE_Boot` (macro, line 200)
  - `PTE_StHead` (macro, line 201)
  - `PTE_StSec` (macro, line 202)
  - `PTE_StCyl` (macro, line 203)
  - `PTE_System` (macro, line 204)
  - `PTE_EdHead` (macro, line 205)
  - `PTE_EdSec` (macro, line 206)
  - `PTE_EdCyl` (macro, line 207)
  - `PTE_StLba` (macro, line 208)
  - `PTE_SizLba` (macro, line 209)
  - `GPTH_Sign` (macro, line 210)
  - `GPTH_Rev` (macro, line 212)
  - `GPTH_Size` (macro, line 213)
  - `GPTH_Bcc` (macro, line 214)
  - `GPTH_CurLba` (macro, line 215)
  - `GPTH_BakLba` (macro, line 216)
  - `GPTH_FstLba` (macro, line 217)
  - `GPTH_LstLba` (macro, line 218)
  - `GPTH_DskGuid` (macro, line 219)
  - `GPTH_PtOfs` (macro, line 220)
  - `GPTH_PtNum` (macro, line 221)
  - `GPTH_PteSize` (macro, line 222)
  - `GPTH_PtBcc` (macro, line 223)
  - `SZ_GPTE` (macro, line 224)
  - `GPTE_PtGuid` (macro, line 225)
  - `GPTE_UpGuid` (macro, line 226)
  - `GPTE_FstLba` (macro, line 227)
  - `GPTE_LstLba` (macro, line 228)
  - `GPTE_Flags` (macro, line 229)
  - `GPTE_Name` (macro, line 230)
  - `ABORT` (macro, line 234)
  - `LEAVE_FF` (macro, line 242)
  - `LEAVE_FF` (macro, line 244)
  - `LD2PD` (macro, line 250)
  - `LD2PT` (macro, line 251)
  - `LD2PD` (macro, line 253)
  - `LD2PT` (macro, line 254)
  - `SS` (macro, line 263)
  - `SS` (macro, line 265)
  - `GET_FATTIME` (macro, line 274)
  - `GET_FATTIME` (macro, line 276)
  - `TBL_CT437` (macro, line 295)
  - `TBL_CT720` (macro, line 303)
  - `TBL_CT737` (macro, line 311)
  - `TBL_CT771` (macro, line 319)
  - `TBL_CT775` (macro, line 327)
  - `TBL_CT850` (macro, line 335)
  - `TBL_CT852` (macro, line 343)
  - `TBL_CT855` (macro, line 351)
  - `TBL_CT857` (macro, line 359)
  - `TBL_CT860` (macro, line 367)
  - `TBL_CT861` (macro, line 375)
  - `TBL_CT862` (macro, line 383)
  - `TBL_CT863` (macro, line 391)
  - `TBL_CT864` (macro, line 399)
  - `TBL_CT865` (macro, line 407)
  - `TBL_CT866` (macro, line 415)
  - `TBL_CT869` (macro, line 423)
  - `TBL_DC932` (macro, line 435)
  - `TBL_DC936` (macro, line 436)
  - `TBL_DC949` (macro, line 437)
  - `TBL_DC950` (macro, line 438)
  - `MERGE_2STR` (macro, line 442)
  - `MKCVTBL` (macro, line 443)
  - `DEF_NAMEBUFF` (macro, line 502)
  - `INIT_NAMEBUFF` (macro, line 503)
  - `FREE_NAMEBUFF` (macro, line 504)
  - `LEAVE_MKFS` (macro, line 505)
  - `MAXDIRB` (macro, line 518)
  - `DEF_NAMEBUFF` (macro, line 525)
  - `INIT_NAMEBUFF` (macro, line 526)
  - `FREE_NAMEBUFF` (macro, line 527)
  - `LEAVE_MKFS` (macro, line 528)
  - `DEF_NAMEBUFF` (macro, line 532)
  - `INIT_NAMEBUFF` (macro, line 533)
  - `FREE_NAMEBUFF` (macro, line 534)
  - `DEF_NAMEBUFF` (macro, line 536)
  - `INIT_NAMEBUFF` (macro, line 537)
  - `FREE_NAMEBUFF` (macro, line 538)
  - `LEAVE_MKFS` (macro, line 540)
  - `DEF_NAMEBUFF` (macro, line 544)
  - `INIT_NAMEBUFF` (macro, line 545)
  - `FREE_NAMEBUFF` (macro, line 546)
  - `DEF_NAMEBUFF` (macro, line 548)
  - `INIT_NAMEBUFF` (macro, line 549)
  - `FREE_NAMEBUFF` (macro, line 550)
  - `LEAVE_MKFS` (macro, line 552)
  - `MAX_MALLOC` (macro, line 553)
  - `CODEPAGE` (macro, line 568)
  - `CODEPAGE` (macro, line 596)
  - `CODEPAGE` (macro, line 600)
  - `DIR_READ_FILE` (macro, line 2330)
  - `DIR_READ_LABEL` (macro, line 2332)
  - `FIND_RECURS` (macro, line 2803)
  - `N_SEC_TRACK` (macro, line 5892)
  - `GPT_ALIGN` (macro, line 5894)
  - `GPT_ITEMS` (macro, line 5895)
  - `SZ_PUTC_BUF` (macro, line 6716)
  - `SZ_NUM_BUF` (macro, line 6717)

## FatFs-R0.16/source/ff.h
- Layer: utility
- Doc: ----------------------------------------------------------------------------
- Language: h
- Symbols:
  - `FF_DEFINED` (macro, line 23)
  - `FF_INTDEF` (macro, line 40)
  - `isnan` (macro, line 44)
  - `isinf` (macro, line 45)
  - `FF_INTDEF` (macro, line 48)
  - `FF_INTDEF` (macro, line 58)
  - `_T` (macro, line 93)
  - `_TEXT` (macro, line 94)
  - `_T` (macro, line 97)
  - `_TEXT` (macro, line 98)
  - `_T` (macro, line 101)
  - `_TEXT` (macro, line 102)
  - `_T` (macro, line 107)
  - `_TEXT` (macro, line 108)
  - `f_eof` (macro, line 359)
  - `f_error` (macro, line 361)
  - `f_tell` (macro, line 362)
  - `f_size` (macro, line 363)
  - `f_rewind` (macro, line 364)
  - `f_rewinddir` (macro, line 365)
  - `f_rmdir` (macro, line 366)
  - `f_unmount` (macro, line 367)
  - `FA_READ` (macro, line 412)
  - `FA_WRITE` (macro, line 413)
  - `FA_OPEN_EXISTING` (macro, line 414)
  - `FA_CREATE_NEW` (macro, line 415)
  - `FA_CREATE_ALWAYS` (macro, line 416)
  - `FA_OPEN_ALWAYS` (macro, line 417)
  - `FA_OPEN_APPEND` (macro, line 418)
  - `CREATE_LINKMAP` (macro, line 421)
  - `FM_FAT` (macro, line 424)
  - `FM_FAT32` (macro, line 425)
  - `FM_EXFAT` (macro, line 426)
  - `FM_ANY` (macro, line 427)
  - `FM_SFD` (macro, line 428)
  - `FS_FAT12` (macro, line 431)
  - `FS_FAT16` (macro, line 432)
  - `FS_FAT32` (macro, line 433)
  - `FS_EXFAT` (macro, line 434)
  - `AM_RDO` (macro, line 437)
  - `AM_HID` (macro, line 438)
  - `AM_SYS` (macro, line 439)
  - `AM_DIR` (macro, line 440)
  - `AM_ARC` (macro, line 441)

## FatFs-R0.16/source/ffconf.h
- Layer: utility
- Doc: ---------------------------------------------------------------------------
- Language: h
- Symbols:
  - `FFCONF_DEF` (macro, line 4)
  - `FF_FS_READONLY` (macro, line 10)
  - `FF_FS_MINIMIZE` (macro, line 16)
  - `FF_USE_FIND` (macro, line 26)
  - `FF_USE_MKFS` (macro, line 31)
  - `FF_USE_FASTSEEK` (macro, line 35)
  - `FF_USE_EXPAND` (macro, line 39)
  - `FF_USE_CHMOD` (macro, line 43)
  - `FF_USE_LABEL` (macro, line 48)
  - `FF_USE_FORWARD` (macro, line 53)
  - `FF_USE_STRFUNC` (macro, line 57)
  - `FF_PRINT_LLI` (macro, line 60)
  - `FF_PRINT_FLOAT` (macro, line 61)
  - `FF_STRF_ENCODE` (macro, line 62)
  - `FF_CODE_PAGE` (macro, line 86)
  - `FF_USE_LFN` (macro, line 114)
  - `FF_MAX_LFN` (macro, line 117)
  - `FF_LFN_UNICODE` (macro, line 134)
  - `FF_LFN_BUF` (macro, line 146)
  - `FF_SFN_BUF` (macro, line 149)
  - `FF_FS_RPATH` (macro, line 154)
  - `FF_PATH_DEPTH` (macro, line 163)
  - `FF_VOLUMES` (macro, line 180)
  - `FF_STR_VOLUME_ID` (macro, line 183)
  - `FF_VOLUME_STRS` (macro, line 186)
  - `FF_MULTI_PARTITION` (macro, line 197)
  - `FF_MIN_SS` (macro, line 206)
  - `FF_MAX_SS` (macro, line 209)
  - `FF_LBA64` (macro, line 216)
  - `FF_MIN_GPT` (macro, line 221)
  - `FF_USE_TRIM` (macro, line 226)
  - `FF_FS_TINY` (macro, line 238)
  - `FF_FS_EXFAT` (macro, line 244)
  - `FF_FS_NORTC` (macro, line 250)
  - `FF_NORTC_MON` (macro, line 253)
  - `FF_NORTC_MDAY` (macro, line 254)
  - `FF_NORTC_YEAR` (macro, line 255)
  - `FF_FS_CRTIME` (macro, line 264)
  - `FF_FS_NOFSINFO` (macro, line 269)
  - `FF_FS_LOCK` (macro, line 281)
  - `FF_FS_REENTRANT` (macro, line 293)
  - `FF_FS_TIMEOUT` (macro, line 296)

## FatFs-R0.16/source/ffsystem.c
- Layer: utility
- Doc: ------------------------------------------------------------------------
- Language: c
- Symbols:
  - `ff_memalloc` (function, line 15) `void* ff_memalloc (	/* Returns pointer to the allocated memory block (null if not enough core) */...`
  - `ff_memfree` (function, line 23) `void ff_memfree (
	void* mblock	/* Pointer to the memory block to free (no effect if null) */
)`
  - `ff_mutex_create` (function, line 78) `int ff_mutex_create (	/* Returns 1:Function succeeded or 0:Could not create the mutex */
	int vol...`
  - `ff_mutex_delete` (function, line 119) `void ff_mutex_delete (	/* Returns 1:Function succeeded or 0:Could not delete due to an error */
	...`
  - `ff_mutex_take` (function, line 151) `int ff_mutex_take (	/* Returns 1:Succeeded or 0:Timeout */
	int vol			/* Mutex ID: Volume mutex (...`
  - `ff_mutex_give` (function, line 184) `void ff_mutex_give (
	int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (...`
  - `OS_TYPE` (macro, line 41)

## FatFs-R0.16/source/ffunicode.c
- Layer: utility
- Doc: ------------------------------------------------------------------------
- Language: c
- Symbols:
  - `ff_uni2oem` (function, line 15222) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
  - `ff_oem2uni` (function, line 15243) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
  - `ff_uni2oem` (function, line 15275) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
  - `ff_oem2uni` (function, line 15309) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
  - `ff_uni2oem` (function, line 15356) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
  - `ff_oem2uni` (function, line 15408) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
  - `ff_wtoupper` (function, line 15463) `DWORD ff_wtoupper (	/* Returns up-converted code point */
	DWORD uni		/* Unicode code point to be...`
  - `MERGE2` (macro, line 29)
  - `CVTBL` (macro, line 31)
