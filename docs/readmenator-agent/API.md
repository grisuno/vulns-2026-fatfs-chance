# API

## FatFs-R0.16/documents/res/app1.c
- `open_append` (function) `FatFs-R0.16/documents/res/app1.c:6` `FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* p...`
- `main` (function) `FatFs-R0.16/documents/res/app1.c:25` `int main (void)`

## FatFs-R0.16/documents/res/app2.c
- `delete_node` (function) `FatFs-R0.16/documents/res/app2.c:9` `FRESULT delete_node (
    TCHAR* path,    /* Path name buffer with the sub-directory to delete */...`

## FatFs-R0.16/documents/res/app3.c
- `allocate_contiguous_clusters` (function) `FatFs-R0.16/documents/res/app3.c:20` `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:error or not contig...`
- `main` (function) `FatFs-R0.16/documents/res/app3.c:78` `int main (void)`

## FatFs-R0.16/documents/res/app4.c
Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`
- `pn` (function) `FatFs-R0.16/documents/res/app4.c:14` `static DWORD pn (       /* Pseudo random number generator */
    DWORD pns   /* 0:Initialize, !0:...`
- `test_diskio` (function) `FatFs-R0.16/documents/res/app4.c:36` `int test_diskio (
    BYTE pdrv,      /* Physical drive number to be checked (all data on the dri...`
- `main` (function) `FatFs-R0.16/documents/res/app4.c:299` `int main (int argc, char* argv[])`

## FatFs-R0.16/documents/res/app5.c
- `test_contiguous_file` (function) `FatFs-R0.16/documents/res/app5.c:5` `FRESULT test_contiguous_file (
    FIL* fp,    /* [IN]  Open file object to be checked */
    int...`

## FatFs-R0.16/documents/res/app6.c
Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`
- `test_raw_speed` (function) `FatFs-R0.16/documents/res/app6.c:11` `int test_raw_speed (
    BYTE pdrv,      /* Physical drive number */
    DWORD lba,      /* Start...`

## FatFs-R0.16/source/diskio.c
Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`
- `disk_status` (function) `FatFs-R0.16/source/diskio.c:27` `DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)`
- `disk_initialize` (function) `FatFs-R0.16/source/diskio.c:65` `DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)`
- `disk_read` (function) `FatFs-R0.16/source/diskio.c:103` `DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		...`
- `disk_write` (function) `FatFs-R0.16/source/diskio.c:153` `DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE ...`
- `disk_ioctl` (function) `FatFs-R0.16/source/diskio.c:202` `DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code *...`

## FatFs-R0.16/source/ff.c
Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`
- `dbc_1st` (function) `FatFs-R0.16/source/ff.c:693` `static int dbc_1st (BYTE c)` -- ptr++ = (BYTE)val; val >>= 8; ptr++ = (BYTE)val; val >>= 8; ptr++ = (BYTE)val; } #endif #endif	/* !FF_FS_READONLY /*
- `dbc_2nd` (function) `FatFs-R0.16/source/ff.c:713` `static int dbc_2nd (BYTE c)` -- } #elif FF_CODE_PAGE >= 900	/* DBCS fixed code page if (c >= DbcTbl[0]) { if (c <= DbcTbl[1]) return 1; if (c >=...
- `tchar2uni` (function) `FatFs-R0.16/source/ff.c:737` `static DWORD tchar2uni (	/* Returns a character in UTF-16 encoding (>=0x10000 on surrogate pair, ...` -- if (c <= DbcTbl[5]) return 1; if (c >= DbcTbl[6] && c <= DbcTbl[7]) return 1; if (c >= DbcTbl[8] && c <= DbcTbl[9])...
- `put_utf` (function) `FatFs-R0.16/source/ff.c:806` `static UINT put_utf (	/* Returns number of encoding units written (0:buffer overflow or wrong enc...` -- } if (wc != 0) { wc = ff_oem2uni(wc, CODEPAGE);	/* ANSI/OEM ==> Unicode if (wc == 0) return 0xFFFFFFFF;	/* Invalid...
- `lock_volume` (function) `FatFs-R0.16/source/ff.c:896` `static int lock_volume (	/* 1:Ok, 0:timeout */
	FATFS* fs,				/* Filesystem object to lock */
	in...`
- `unlock_volume` (function) `FatFs-R0.16/source/ff.c:922` `static void unlock_volume (
	FATFS* fs,		/* Filesystem object */
	FRESULT res		/* Result code to ...`
- `chk_share` (function) `FatFs-R0.16/source/ff.c:947` `static FRESULT chk_share (	/* Check if the file can be accessed */
	DIR* dp,		/* Directory object...`
- `inc_share` (function) `FatFs-R0.16/source/ff.c:983` `static UINT inc_share (	/* Increment object open counter and returns its index (0:Internal error)...`
- `dec_share` (function) `FatFs-R0.16/source/ff.c:1014` `static FRESULT dec_share (	/* Decrement object open counter */
	UINT i			/* Semaphore index (1..)...`
- `clear_share` (function) `FatFs-R0.16/source/ff.c:1038` `static void clear_share (	/* Clear all lock entries of the volume */
	FATFS* fs
)`
- `sync_window` (function) `FatFs-R0.16/source/ff.c:1057` `static FRESULT sync_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs			/* Filesystem object...` -- for (i = 0; i < FF_FS_LOCK; i++) { if (Files[i].fs == fs) Files[i].fs = 0; } } #endif	/* FF_FS_LOCK /*
- `move_window` (function) `FatFs-R0.16/source/ff.c:1079` `static FRESULT move_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs,		/* Filesystem object...`
- `sync_fs` (function) `FatFs-R0.16/source/ff.c:1110` `static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs		/* Filesystem object */
)`
- `clst2sect` (function) `FatFs-R0.16/source/ff.c:1159` `static LBA_t clst2sect (	/* !=0:Sector number, 0:Failed (invalid cluster#) */
	FATFS* fs,		/* Fil...`
- `get_fat` (function) `FatFs-R0.16/source/ff.c:1176` `static DWORD get_fat (		/* 0xFFFFFFFF:Disk error, 1:Internal error, 2..0x7FFFFFFF:Cluster status ...`
- `put_fat` (function) `FatFs-R0.16/source/ff.c:1254` `static FRESULT put_fat (	/* FR_OK(0):succeeded, !=0:error */
	FATFS* fs,		/* Corresponding filesy...`
- `find_bitmap` (function) `FatFs-R0.16/source/ff.c:1319` `static DWORD find_bitmap (	/* 0:Not found, 2..:Cluster block found, 0xFFFFFFFF:Disk error */
	FAT...`
- `change_bitmap` (function) `FatFs-R0.16/source/ff.c:1359` `static FRESULT change_bitmap (
	FATFS* fs,	/* Filesystem object */
	DWORD clst,	/* Cluster number...`
- `fill_first_frag` (function) `FatFs-R0.16/source/ff.c:1395` `static FRESULT fill_first_frag (
	FFOBJID* obj	/* Pointer to the corresponding object */
)`
- `fill_last_frag` (function) `FatFs-R0.16/source/ff.c:1418` `static FRESULT fill_last_frag (
	FFOBJID* obj,	/* Pointer to the corresponding object */
	DWORD l...`
- `remove_chain` (function) `FatFs-R0.16/source/ff.c:1444` `static FRESULT remove_chain (	/* FR_OK(0):succeeded, !=0:error */
	FFOBJID* obj,		/* Correspondin...`
- `create_chain` (function) `FatFs-R0.16/source/ff.c:1539` `static DWORD create_chain (	/* 0:No free cluster, 1:Internal error, 0xFFFFFFFF:Disk error, >=2:Ne...`
- `clmt_clust` (function) `FatFs-R0.16/source/ff.c:1644` `static DWORD clmt_clust (	/* <2:Error, >=2:Cluster number */
	FIL* fp,		/* Pointer to the file ob...`
- `dir_clear` (function) `FatFs-R0.16/source/ff.c:1675` `static FRESULT dir_clear (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS *fs,		/* Filesystem object *...` -- if !FF_FS_READONLY
- `dir_sdi` (function) `FatFs-R0.16/source/ff.c:1714` `static FRESULT dir_sdi (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,		/* Pointer to directory o...`
- `dir_next` (function) `FatFs-R0.16/source/ff.c:1762` `static FRESULT dir_next (	/* FR_OK(0):succeeded, FR_NO_FILE:End of table, FR_DENIED:Could not str...`
- `dir_alloc` (function) `FatFs-R0.16/source/ff.c:1823` `static FRESULT dir_alloc (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,				/* Pointer to the dir...`
- `ld_clust` (function) `FatFs-R0.16/source/ff.c:1865` `static DWORD ld_clust (	/* Returns the top cluster value of the SFN entry */
	FATFS* fs,			/* Poi...`
- `st_clust` (function) `FatFs-R0.16/source/ff.c:1882` `static void st_clust (
	FATFS* fs,	/* Pointer to the fs object */
	BYTE* dir,	/* Pointer to the k...` -- if !FF_FS_READONLY
- `cmp_lfn` (function) `FatFs-R0.16/source/ff.c:1902` `static int cmp_lfn (		/* 1:matched, 0:not matched */
	const WCHAR* lfnbuf,	/* Pointer to the LFN ...`
- `pick_lfn` (function) `FatFs-R0.16/source/ff.c:1938` `static int pick_lfn (	/* 1:succeeded, 0:buffer overflow or invalid LFN entry */
	WCHAR* lfnbuf,		...`
- `put_lfn` (function) `FatFs-R0.16/source/ff.c:1976` `static void put_lfn (
	const WCHAR* lfn,	/* Pointer to the LFN */
	BYTE* dir,			/* Pointer to the...`
- `gen_numname` (function) `FatFs-R0.16/source/ff.c:2013` `static void gen_numname (
	BYTE* dst,			/* Pointer to the buffer to store numbered SFN */
	const ...`
- `sum_sfn` (function) `FatFs-R0.16/source/ff.c:2070` `static BYTE sum_sfn (
	const BYTE* dir		/* Pointer to the SFN entry */
)`
- `xdir_sum` (function) `FatFs-R0.16/source/ff.c:2092` `static WORD xdir_sum (	/* Get checksum of the directoly entry block */
	const BYTE* dir		/* Direc...`
- `xname_sum` (function) `FatFs-R0.16/source/ff.c:2113` `static WORD xname_sum (	/* Get check sum (to be used as hash) of the file name */
	const WCHAR* n...`
- `xsum32` (function) `FatFs-R0.16/source/ff.c:2131` `static DWORD xsum32 (	/* Returns 32-bit checksum */
	BYTE  dat,			/* Byte to be calculated (byte-...` -- if !FF_FS_READONLY && FF_USE_MKFS
- `load_xdir` (function) `FatFs-R0.16/source/ff.c:2147` `static FRESULT load_xdir (	/* FR_INT_ERR: invalid entry block */
	DIR* dp					/* Reading director...`
- `init_alloc_info` (function) `FatFs-R0.16/source/ff.c:2199` `static void init_alloc_info (
	FFOBJID* dobj,	/* Object allocation information to be initialized ...`
- `load_obj_xdir` (function) `FatFs-R0.16/source/ff.c:2225` `static FRESULT load_obj_xdir (
	DIR* dp,			/* Blank directory object to be used to access contain...`
- `store_xdir` (function) `FatFs-R0.16/source/ff.c:2254` `static FRESULT store_xdir (
	DIR* dp				/* Pointer to the directory object */
)`
- `create_xdir` (function) `FatFs-R0.16/source/ff.c:2288` `static void create_xdir (
	BYTE* dirb,			/* Pointer to the directory entry block buffer */
	const...`
- `dir_read` (function) `FatFs-R0.16/source/ff.c:2334` `static FRESULT dir_read (
	DIR* dp,		/* Pointer to the directory object */
	int vol			/* Filtered...`
- `dir_find` (function) `FatFs-R0.16/source/ff.c:2412` `static FRESULT dir_find (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp					/* Pointer to the dire...`
- `dir_register` (function) `FatFs-R0.16/source/ff.c:2494` `static FRESULT dir_register (	/* FR_OK:succeeded, FR_DENIED:no free entry or too many SFN collisi...`
- `dir_remove` (function) `FatFs-R0.16/source/ff.c:2607` `static FRESULT dir_remove (	/* FR_OK:Succeeded, FR_DISK_ERR:A disk error */
	DIR* dp					/* Direc...`
- `get_fileinfo` (function) `FatFs-R0.16/source/ff.c:2653` `static void get_fileinfo (
	DIR* dp,			/* Pointer to the directory object */
	FILINFO* fno		/* Po...`
- `get_achar` (function) `FatFs-R0.16/source/ff.c:2807` `static DWORD get_achar (	/* Get a character and advance ptr */
	const TCHAR** ptr		/* Pointer to ...`
- `pattern_match` (function) `FatFs-R0.16/source/ff.c:2838` `static int pattern_match (	/* 0:mismatched, 1:matched */
	const TCHAR* pat,	/* Matching pattern *...`
- `create_name` (function) `FatFs-R0.16/source/ff.c:2892` `static FRESULT create_name (	/* FR_OK: successful, FR_INVALID_NAME: could not create */
	DIR* dp,...`
- `follow_path` (function) `FatFs-R0.16/source/ff.c:3101` `static FRESULT follow_path (	/* FR_OK(0): successful, !=0: error code */
	DIR* dp,					/* Directo...`
- `get_ldnumber` (function) `FatFs-R0.16/source/ff.c:3220` `static int get_ldnumber (	/* Returns logical drive number (-1:invalid drive number or null pointe...`
- `crc32` (function) `FatFs-R0.16/source/ff.c:3297` `static DWORD crc32 (	/* Returns next CRC value */
	DWORD crc,			/* Current CRC value */
	BYTE d		...`
- `test_gpt_header` (function) `FatFs-R0.16/source/ff.c:3315` `static int test_gpt_header (	/* 0:Invalid, 1:Valid */
	const BYTE* gpth			/* Pointer to the GPT h...`
- `make_rand` (function) `FatFs-R0.16/source/ff.c:3339` `static DWORD make_rand (	/* Returns a seed value for next */
	DWORD seed,				/* Seed value */
	BY...` -- if (hlen < 92 || hlen > FF_MIN_SS) return 0; for (i = 0, bcc = 0xFFFFFFFF; i < hlen; i++) {			/* Check header BCC...
- `check_fs` (function) `FatFs-R0.16/source/ff.c:3367` `static UINT check_fs (	/* 0:FAT/FAT32 VBR, 1:exFAT VBR, 2:Not FAT and valid BS, 3:Not FAT and inv...`
- `find_volume` (function) `FatFs-R0.16/source/ff.c:3407` `static UINT find_volume (	/* Returns BS status found in the hosting drive */
	FATFS* fs,		/* File...`
- `mount_volume` (function) `FatFs-R0.16/source/ff.c:3461` `static FRESULT mount_volume (	/* FR_OK(0): successful, !=0: an error occurred */
	const TCHAR** p...`
- `validate` (function) `FatFs-R0.16/source/ff.c:3695` `static FRESULT validate (	/* Returns FR_OK or FR_INVALID_OBJECT */
	FFOBJID* obj,			/* Pointer to...`
- `f_open` (function) `FatFs-R0.16/source/ff.c:3799` `FRESULT f_open (
	FIL* fp,			/* Pointer to the blank file object */
	const TCHAR* path,	/* Pointe...`
- `f_read` (function) `FatFs-R0.16/source/ff.c:3996` `FRESULT f_read (
	FIL* fp, 	/* Open file to be read */
	void* buff,	/* Data buffer to store the r...`
- `f_write` (function) `FatFs-R0.16/source/ff.c:4097` `FRESULT f_write (
	FIL* fp,			/* Open file to be written */
	const void* buff,	/* Data to be writ...`
- `f_sync` (function) `FatFs-R0.16/source/ff.c:4218` `FRESULT f_sync (
	FIL* fp		/* Open file to be synced */
)`
- `f_close` (function) `FatFs-R0.16/source/ff.c:4299` `FRESULT f_close (
	FIL* fp		/* Open file to be closed */
)`
- `f_chdrive` (function) `FatFs-R0.16/source/ff.c:4335` `FRESULT f_chdrive (
	const TCHAR* path		/* Drive number to set */
)`
- `f_chdir` (function) `FatFs-R0.16/source/ff.c:4357` `FRESULT f_chdir (
	const TCHAR* path	/* Pointer to the directory path */
)`
- `f_getcwd` (function) `FatFs-R0.16/source/ff.c:4419` `FRESULT f_getcwd (
	TCHAR* buff,	/* Pointer to the buffer to store the current direcotry path */
...`
- `f_lseek` (function) `FatFs-R0.16/source/ff.c:4555` `FRESULT f_lseek (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t ofs		/* File pointer from ...`
- `f_opendir` (function) `FatFs-R0.16/source/ff.c:4719` `FRESULT f_opendir (
	DIR* dp,			/* Pointer to directory object to create */
	const TCHAR* path	/*...`
- `f_closedir` (function) `FatFs-R0.16/source/ff.c:4781` `FRESULT f_closedir (
	DIR *dp		/* Pointer to the directory object to be closed */
)`
- `f_readdir` (function) `FatFs-R0.16/source/ff.c:4811` `FRESULT f_readdir (
	DIR* dp,			/* Pointer to the open directory object */
	FILINFO* fno		/* Poin...`
- `f_findnext` (function) `FatFs-R0.16/source/ff.c:4850` `FRESULT f_findnext (
	DIR* dp,		/* Pointer to the open directory object */
	FILINFO* fno	/* Point...`
- `f_findfirst` (function) `FatFs-R0.16/source/ff.c:4875` `FRESULT f_findfirst (
	DIR* dp,				/* Pointer to the blank directory object */
	FILINFO* fno,			/...`
- `f_stat` (function) `FatFs-R0.16/source/ff.c:4902` `FRESULT f_stat (
	const TCHAR* path,	/* Pointer to the file path */
	FILINFO* fno		/* Pointer to ...`
- `f_getfree` (function) `FatFs-R0.16/source/ff.c:4939` `FRESULT f_getfree (
	const TCHAR* path,	/* Logical drive number */
	DWORD* nclst,		/* Pointer to ...`
- `f_truncate` (function) `FatFs-R0.16/source/ff.c:5036` `FRESULT f_truncate (
	FIL* fp		/* Pointer to the file object */
)`
- `f_unlink` (function) `FatFs-R0.16/source/ff.c:5087` `FRESULT f_unlink (
	const TCHAR* path		/* Pointer to the file or directory path */
)`
- `f_mkdir` (function) `FatFs-R0.16/source/ff.c:5176` `FRESULT f_mkdir (
	const TCHAR* path		/* Pointer to the directory path */
)`
- `f_rename` (function) `FatFs-R0.16/source/ff.c:5261` `FRESULT f_rename (
	const TCHAR* path_old,	/* Pointer to the object name to be renamed */
	const ...`
- `f_chmod` (function) `FatFs-R0.16/source/ff.c:5385` `FRESULT f_chmod (
	const TCHAR* path,	/* Pointer to the file path */
	BYTE attr,			/* Attribute b...`
- `f_utime` (function) `FatFs-R0.16/source/ff.c:5434` `FRESULT f_utime (
	const TCHAR* path,	/* Pointer to the file/directory name */
	const FILINFO* fn...`
- `f_getlabel` (function) `FatFs-R0.16/source/ff.c:5502` `FRESULT f_getlabel (
	const TCHAR* path,	/* Logical drive number */
	TCHAR* label,		/* Buffer to ...`
- `f_setlabel` (function) `FatFs-R0.16/source/ff.c:5603` `FRESULT f_setlabel (
	const TCHAR* label	/* Volume label to set with heading logical drive number...`
- `f_expand` (function) `FatFs-R0.16/source/ff.c:5726` `FRESULT f_expand (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t fsz,	/* File size to be e...`
- `f_forward` (function) `FatFs-R0.16/source/ff.c:5822` `FRESULT f_forward (
	FIL* fp, 						/* Pointer to the file object */
	UINT (*func)(const BYTE*,UI...`
- `create_partition` (function) `FatFs-R0.16/source/ff.c:5900` `static FRESULT create_partition (
	BYTE drv,			/* Physical drive number */
	const LBA_t plst[],	/...`
- `f_mkfs` (function) `FatFs-R0.16/source/ff.c:6043` `FRESULT f_mkfs (
	const TCHAR* path,		/* Logical drive number */
	const MKFS_PARM* opt,	/* Format...`
- `f_fdisk` (function) `FatFs-R0.16/source/ff.c:6548` `FRESULT f_fdisk (
	BYTE pdrv,			/* Physical drive number */
	const LBA_t ptbl[],	/* Pointer to th...`
- `f_gets` (function) `FatFs-R0.16/source/ff.c:6588` `TCHAR* f_gets (
	TCHAR* buff,	/* Pointer to the buffer to store read string */
	int len,		/* Size...`
- `putc_bfd` (function) `FatFs-R0.16/source/ff.c:6740` `static void putc_bfd (putbuff* pb, TCHAR c)`
- `putc_flush` (function) `FatFs-R0.16/source/ff.c:6871` `static int putc_flush (putbuff* pb)`
- `putc_init` (function) `FatFs-R0.16/source/ff.c:6886` `static void putc_init (putbuff* pb, FIL* fp)`
- `f_putc` (function) `FatFs-R0.16/source/ff.c:6894` `int f_putc (
	TCHAR c,	/* A character to be output */
	FIL* fp		/* Pointer to the file object */
)`
- `f_puts` (function) `FatFs-R0.16/source/ff.c:6914` `int f_puts (
	const TCHAR* str,	/* Pointer to the string to be output */
	FIL* fp				/* Pointer t...`
- `ftoa` (function) `FatFs-R0.16/source/ff.c:6980` `static void ftoa (
	char* buf,	/* Buffer to output the floating point string */
	double val,	/* V...`
- `f_printf` (function) `FatFs-R0.16/source/ff.c:7057` `int f_printf (
	FIL* fp,			/* Pointer to the file object */
	const TCHAR* fmt,	/* Pointer to the ...`
- `f_setcp` (function) `FatFs-R0.16/source/ff.c:7226` `FRESULT f_setcp (
	WORD cp		/* Value to be set as active code page */
)`

## FatFs-R0.16/source/ff.h
Depends on: `FatFs-R0.16/source/ffconf.h`
Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`
- `f_putc` (function) `FatFs-R0.16/source/ff.h:353` `int f_putc (TCHAR c, FIL* fp);` -- FRESULT f_chmod (const TCHAR* path, BYTE attr, BYTE mask);			/* Change attribute of a file/dir FRESULT f_utime...
- `f_puts` (function) `FatFs-R0.16/source/ff.h:354` `int f_puts (const TCHAR* str, FIL* cp);` -- FRESULT f_utime (const TCHAR* path, const FILINFO* fno);			/* Change timestamp of a file/dir FRESULT f_chdir (const...
- `f_printf` (function) `FatFs-R0.16/source/ff.h:355` `int f_printf (FIL* fp, const TCHAR* str, ...);` -- FRESULT f_chdir (const TCHAR* path);								/* Change current directory FRESULT f_chdrive (const TCHAR*...
- `f_gets` (function) `FatFs-R0.16/source/ff.h:356` `TCHAR* f_gets (TCHAR* buff, int len, FIL* fp);` -- FRESULT f_chdrive (const TCHAR* path);								/* Change current drive FRESULT f_getcwd (TCHAR* buff, UINT...
- `ff_memalloc` (function) `FatFs-R0.16/source/ff.h:394` `void* ff_memalloc (UINT msize);` -- /* LFN support functions (defined in ffunicode.c) #if FF_USE_LFN >= 1 WCHAR ff_oem2uni (WCHAR oem, WORD cp);	/* OEM...
- `ff_memfree` (function) `FatFs-R0.16/source/ff.h:395` `void ff_memfree (void* mblock);` -- /* LFN support functions (defined in ffunicode.c) #if FF_USE_LFN >= 1 WCHAR ff_oem2uni (WCHAR oem, WORD cp);	/* OEM...
- `ff_mutex_create` (function) `FatFs-R0.16/source/ff.h:398` `int ff_mutex_create (int vol);` -- #if FF_USE_LFN >= 1 WCHAR ff_oem2uni (WCHAR oem, WORD cp);	/* OEM code to Unicode conversion WCHAR ff_uni2oem (DWORD...
- `ff_mutex_delete` (function) `FatFs-R0.16/source/ff.h:399` `void ff_mutex_delete (int vol);` -- WCHAR ff_oem2uni (WCHAR oem, WORD cp);	/* OEM code to Unicode conversion WCHAR ff_uni2oem (DWORD uni, WORD cp);	/*...
- `ff_mutex_take` (function) `FatFs-R0.16/source/ff.h:400` `int ff_mutex_take (int vol);` -- WCHAR ff_uni2oem (DWORD uni, WORD cp);	/* Unicode to OEM code conversion DWORD ff_wtoupper (DWORD uni);			/* Unicode...
- `ff_mutex_give` (function) `FatFs-R0.16/source/ff.h:401` `void ff_mutex_give (int vol);` -- DWORD ff_wtoupper (DWORD uni);			/* Unicode upper-case conversion #endif /* O/S dependent functions (samples...

## FatFs-R0.16/source/ffsystem.c
Depends on: `FatFs-R0.16/source/ff.h`
- `ff_memalloc` (function) `FatFs-R0.16/source/ffsystem.c:17` `void* ff_memalloc (	/* Returns pointer to the allocated memory block (null if not enough core) */...`
- `ff_memfree` (function) `FatFs-R0.16/source/ffsystem.c:25` `void ff_memfree (
	void* mblock	/* Pointer to the memory block to free (no effect if null) */
)`
- `ff_mutex_create` (function) `FatFs-R0.16/source/ffsystem.c:79` `int ff_mutex_create (	/* Returns 1:Function succeeded or 0:Could not create the mutex */
	int vol...`
- `ff_mutex_delete` (function) `FatFs-R0.16/source/ffsystem.c:120` `void ff_mutex_delete (	/* Returns 1:Function succeeded or 0:Could not delete due to an error */
	...`
- `ff_mutex_take` (function) `FatFs-R0.16/source/ffsystem.c:152` `int ff_mutex_take (	/* Returns 1:Succeeded or 0:Timeout */
	int vol			/* Mutex ID: Volume mutex (...`
- `ff_mutex_give` (function) `FatFs-R0.16/source/ffsystem.c:185` `void ff_mutex_give (
	int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (...`

## FatFs-R0.16/source/ffunicode.c
Depends on: `FatFs-R0.16/source/ff.h`
- `ff_uni2oem` (function) `FatFs-R0.16/source/ffunicode.c:15222` `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...` -- if FF_CODE_PAGE != 0 && FF_CODE_PAGE < 900
- `ff_oem2uni` (function) `FatFs-R0.16/source/ffunicode.c:15244` `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- `ff_uni2oem` (function) `FatFs-R0.16/source/ffunicode.c:15275` `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...` -- if FF_CODE_PAGE >= 900
- `ff_oem2uni` (function) `FatFs-R0.16/source/ffunicode.c:15311` `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- `ff_uni2oem` (function) `FatFs-R0.16/source/ffunicode.c:15358` `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- `ff_oem2uni` (function) `FatFs-R0.16/source/ffunicode.c:15410` `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- `ff_wtoupper` (function) `FatFs-R0.16/source/ffunicode.c:15464` `DWORD ff_wtoupper (	/* Returns up-converted code point */
	DWORD uni		/* Unicode code point to be...`

## fuzzer/fat_image.go
- `le16` (function) `fuzzer/fat_image.go:19` `func le16(`
- `le32` (function) `fuzzer/fat_image.go:20` `func le32(`
- `le64` (function) `fuzzer/fat_image.go:21` `func le64(`
- `newDisk` (function) `fuzzer/fat_image.go:29` `func newDisk(` -- newDisk returns a zeroed byte slice of min(totalSectors, maxDiskSectors) * 512 bytes.
- `DefaultFAT16Config` (function) `fuzzer/fat_image.go:52` `func DefaultFAT16Config(` -- DefaultFAT16Config returns a valid, minimal 1 MiB FAT16 configuration.
- `BuildFAT16` (function) `fuzzer/fat_image.go:65` `func BuildFAT16(` -- BuildFAT16 constructs a minimal FAT16 disk image from the given config.
- `FAT16DataSector` (function) `fuzzer/fat_image.go:107` `func FAT16DataSector(` -- FAT16DataSector returns the first sector of cluster c (c >= 2).
- `DefaultFAT32Config` (function) `fuzzer/fat_image.go:131` `func DefaultFAT32Config(` -- DefaultFAT32Config returns a valid FAT32 configuration sized to fit in the test harness RAM disk (4096 sectors = 2 MiB).
- `BuildFAT32` (function) `fuzzer/fat_image.go:144` `func BuildFAT32(` -- BuildFAT32 constructs a minimal FAT32 disk image.
- `BuildGPTImage` (function) `fuzzer/fat_image.go:214` `func BuildGPTImage(` -- BuildGPTImage constructs a disk image with a GPT-protective MBR, a GPT header at sector 1 declaring nPartitions...
- `BuildExFATImage` (function) `fuzzer/fat_image.go:262` `func BuildExFATImage(` -- BuildExFATImage creates a minimal exFAT VBR.
- `MutateFAT32BPB` (function) `fuzzer/fat_image.go:303` `func MutateFAT32BPB(` -- MutateFAT32BPB returns a copy of a FAT32 disk image with the named BPB field set to value.
- `RandomMutate` (function) `fuzzer/fat_image.go:324` `func RandomMutate(` -- RandomMutate applies a single random byte-flip to a copy of disk.
- `BuildExFATWithLargeLabel` (function) `fuzzer/fat_image.go:354` `func BuildExFATWithLargeLabel(` -- volume-label directory entry has XDIR_NumLabel set to numLabel.
- `sfnChecksum` (function) `fuzzer/fat_image.go:430` `func sfnChecksum(` -- sfnChecksum computes the LFN checksum of an 11-byte FAT SFN (matching sum_sfn() in ff.c).
- `BuildFAT16WithLFNFile` (function) `fuzzer/fat_image.go:451` `func BuildFAT16WithLFNFile(` -- BuildFAT16WithLFNFile returns a FAT16 image identical to BuildFAT16(cfg) but with one file in the root directory...

## fuzzer/main.go
- `main` (function) `fuzzer/main.go:51` `func main(`
- `buildAllSeeds` (function) `fuzzer/main.go:76` `func buildAllSeeds(`
- `BuildFAT12Minimal` (function) `fuzzer/main.go:290` `func BuildFAT12Minimal(`
- `FuzzFAT32BPB` (function) `fuzzer/main.go:343` `func FuzzFAT32BPB(` -- FuzzFAT32BPB mutates individual BPB fields and checks structural consistency of the generated images.
- `FuzzGPTNEnt` (function) `fuzzer/main.go:398` `func FuzzGPTNEnt(` -- FuzzGPTNEnt mutates GPTH_PtNum to explore the loop bound behaviour.
- `FuzzExFATNumLabel` (function) `fuzzer/main.go:449` `func FuzzExFATNumLabel(` -- FuzzExFATNumLabel mutates the XDIR_NumLabel byte in an exFAT volume label entry and checks structural invariants of...
- `FuzzFAT16LFNLength` (function) `fuzzer/main.go:507` `func FuzzFAT16LFNLength(` -- FuzzFAT16LFNLength mutates the length of the LFN filename.

## harness/diskio_ramdisk.c
Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`
- `ramdisk_reset_stats` (function) `harness/diskio_ramdisk.c:35` `void ramdisk_reset_stats(void)`
- `ramdisk_load` (function) `harness/diskio_ramdisk.c:46` `void ramdisk_load(const BYTE *image, UINT size)` -- Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.
- `ramdisk_eject` (function) `harness/diskio_ramdisk.c:55` `void ramdisk_eject(void)` -- Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.
- `disk_status` (function) `harness/diskio_ramdisk.c:62` `DSTATUS disk_status(BYTE pdrv)`
- `disk_initialize` (function) `harness/diskio_ramdisk.c:68` `DSTATUS disk_initialize(BYTE pdrv)`
- `disk_read` (function) `harness/diskio_ramdisk.c:75` `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)`
- `disk_write` (function) `harness/diskio_ramdisk.c:95` `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)`
- `disk_ioctl` (function) `harness/diskio_ramdisk.c:114` `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)`
- `get_fattime` (function) `harness/diskio_ramdisk.c:137` `DWORD get_fattime(void)`

## harness/diskio_ramdisk.h
Depends on: `FatFs-R0.16/source/ff.h`
Imported by: `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`
- `ramdisk_reset_stats` (function) `harness/diskio_ramdisk.h:26` `void ramdisk_reset_stats(void);`
- `ramdisk_load` (function) `harness/diskio_ramdisk.h:31` `void ramdisk_load(const BYTE *image, UINT size);` -- /* ── backing store (accessible for direct inspection in tests) ──────────── extern BYTE...
- `ramdisk_eject` (function) `harness/diskio_ramdisk.h:34` `void ramdisk_eject(void);` -- /* ── instrumentation ────────────────────────────────────────────────────── extern volatile uint32_t...

## harness/exploit_disks.c
Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`
- `exploit_disks` (function) `harness/exploit_disks.c:49` `*   make exploit_disks            (see Makefile target)
 *
 * Expected output:
 *   Generating 14...`
- `st32le` (function) `harness/exploit_disks.c:99` `static inline void st32le(uint8_t *p, uint32_t v)`
- `st64le` (function) `harness/exploit_disks.c:102` `static inline void st64le(uint8_t *p, uint64_t v)`
- `save_image` (function) `harness/exploit_disks.c:116` `static int save_image(const char *name, const uint8_t *buf, size_t sz)`
- `load_ramdisk` (function) `harness/exploit_disks.c:129` `static void load_ramdisk(const uint8_t *buf, size_t sz)`
- `bug1_write_vbr` (function) `harness/exploit_disks.c:156` `static void bug1_write_vbr(uint8_t *disk)` -- clst2sect(2) = 6 → attacker plants root-dir entry at sector 6 clst2sect(4) = 8 → attacker plants file payload at...
- `bug1_fill_payload` (function) `harness/exploit_disks.c:227` `static void bug1_fill_payload(uint8_t *disk,
                               const uint8_t *payloa...` -- bug1_fill_payload  —  write exploit bytes into sector 8 (cluster 4).
- `bug1_build` (function) `harness/exploit_disks.c:241` `static uint8_t *bug1_build(uint32_t file_size,
                            const uint8_t *payload...` -- Allocate and build a complete CVE-2026-6682 image for a given file_size / payload. * Returns pointer to...
- `bug1_verify` (function) `harness/exploit_disks.c:255` `static int bug1_verify(uint8_t *disk, const char *filename)` -- static uint8_t *bug1_build(uint32_t file_size, const uint8_t *payload, uint32_t payload_sz, uint8_t fill, const char...
- `Payload` (function) `harness/exploit_disks.c:293` `*   Payload (sector 8): placeholder address 0xDEADBEEFCAFEBABE
 *   Simulates: embedded OTA reade...`
- `gen_bug1_espidf` (function) `harness/exploit_disks.c:317` `static void gen_bug1_espidf(void)`
- `gen_bug1_stm32` (function) `harness/exploit_disks.c:338` `static void gen_bug1_stm32(void)`
- `gen_bug1_keystone3` (function) `harness/exploit_disks.c:359` `static void gen_bug1_keystone3(void)`
- `gen_bug1_ardupilot` (function) `harness/exploit_disks.c:382` `static void gen_bug1_ardupilot(void)`
- `gen_bug2_exfat` (function) `harness/exploit_disks.c:456` `static void gen_bug2_exfat(void)`
- `MicroPython` (function) `harness/exploit_disks.c:498` `*                            MicroPython (if the port enables FF_LBA64)
 *
 * R0.16 fix:  test_gp...`
- `code` (function) `harness/exploit_disks.c:564` `* * Vulnerable code (ff.c non-tiny path, f_read multi-sector branch): * disk_read(pdrv, rbuff, sect, cc);`
- `chain` (function) `harness/exploit_disks.c:576` `*   An application writes 64 bytes to the END of cluster chain (fp->sect = X,
 *   FA_DIRTY set),...`
- `bug4_set_fat16_entry` (function) `harness/exploit_disks.c:638` `static void bug4_set_fat16_entry(uint8_t *disk, uint16_t cluster, uint16_t value)`
- `gen_bug4_fragmented` (function) `harness/exploit_disks.c:648` `static void gen_bug4_fragmented(void)`
- `cc` (function) `harness/exploit_disks.c:673` `* if cc (sectors remaining) is also large, 0xFFFFFFFC < cc → TRUE * → memcpy fires at offset 0xFFFFFFFC * 512 (out...`
- `Zephyr` (function) `harness/exploit_disks.c:836` `*                     Zephyr (R0.16), ArduPilot (R0.14b),
 *                     RIOT-OS (R0.15),...`
- `bug6_verify_overflow` (function) `harness/exploit_disks.c:893` `static int bug6_verify_overflow(uint8_t *disk, const char *imgname,
                             ...`
- `gen_bug6_stm32` (function) `harness/exploit_disks.c:933` `static void gen_bug6_stm32(void)`
- `gen_bug6_zephyr` (function) `harness/exploit_disks.c:948` `static void gen_bug6_zephyr(void)`
- `layout` (function) `harness/exploit_disks.c:990` `*
 * Directory layout (FAT16):
 *   Entries in order: LFN entries (N × 32 bytes) then 8.3 SFN ent...`
- `bug7_build` (function) `harness/exploit_disks.c:1007` `static void bug7_build(uint8_t *disk, int lfn_len, uint16_t dirent_name_size)`
- `bug7_verify` (function) `harness/exploit_disks.c:1060` `static int bug7_verify(uint8_t *disk, const char *imgname, int expected_lfn_len)`
- `gen_bug7_max255` (function) `harness/exploit_disks.c:1096` `static void gen_bug7_max255(void)`
- `gen_bug7_zephyr` (function) `harness/exploit_disks.c:1112` `static void gen_bug7_zephyr(void)`
- `main` (function) `harness/exploit_disks.c:1273` `int main(void)`

## harness/libfuzzer_harness.c
Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`
- `Usage` (function) `harness/libfuzzer_harness.c:10` `*
 * Usage (libFuzzer):
 *   ./fuzz_fatfs -max_len=2097152 corpus/
 *
 * Usage (AFL++):
 *   afl-...`
- `main` (function) `harness/libfuzzer_harness.c:128` `int main(int argc, char **argv)` -- f_close(&fp); break; /* process at most one file per fuzz iteration } f_closedir(&dj); } done: f_mount(NULL, "0:"...

## harness/rce_demo.c
Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`
- `Build` (function) `harness/rce_demo.c:46` `*
 * Build (without sanitisers, without stack protector — lets the overflow
 * reach the function...`
- `st32le` (function) `harness/rce_demo.c:73` `static inline void st32le(uint8_t *p, uint32_t v)`
- `st64le` (function) `harness/rce_demo.c:76` `static inline void st64le(uint8_t *p, uint64_t v)`
- `safe_update_complete` (function) `harness/rce_demo.c:123` `static void safe_update_complete(void)`
- `vulnerable_ota_check` (function) `harness/rce_demo.c:155` `static void vulnerable_ota_check(void)` -- This function is the VICTIM.
- `build_exploit_image` (function) `harness/rce_demo.c:232` `static void build_exploit_image(uint8_t *disk, size_t disk_bytes,
                               ...` -- → database = sector 6   (inside FAT area [4, ∞)) → clst2sect(2) = 6  (root dir reads from sector 6) → clst2sect(4) =...
- `fasize` (function) `harness/rce_demo.c:258` `* fasize (DWORD) = 0x80000001 * 2 = 0x100000002 → truncates to 2 * sysect = 4 + 2 + 0 = 6 → database = sector 6...`
- `save_image` (function) `harness/rce_demo.c:348` `static int save_image(const char *path, const uint8_t *disk, size_t sz)` -- printf("             version    [%u..%u)  = 0x00010000\n", FW_HDR_SIZE + 4, FW_HDR_SIZE + 8); printf("...
- `load_image` (function) `harness/rce_demo.c:363` `static int load_image(const char *path)` -- { FILE *f = fopen(path, "wb"); if (!f) { perror(path); return -1; } size_t written = fwrite(disk, 1, sz, f)...
- `main` (function) `harness/rce_demo.c:380` `int main(void)`
