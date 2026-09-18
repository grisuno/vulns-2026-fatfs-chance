# API

## FatFs-R0.16/documents/res/app1.c

### open_append (function) `FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* p...`
- Defined: `FatFs-R0.16/documents/res/app1.c:6`

### main (function) `int main (void)`
- Defined: `FatFs-R0.16/documents/res/app1.c:25`

## FatFs-R0.16/documents/res/app2.c

### delete_node (function) `FRESULT delete_node (
    TCHAR* path,    /* Path name buffer with the sub-directory to delete */...`
- Defined: `FatFs-R0.16/documents/res/app2.c:9`

## FatFs-R0.16/documents/res/app3.c

### allocate_contiguous_clusters (function) `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:error or not contig...`
- Defined: `FatFs-R0.16/documents/res/app3.c:20`

### main (function) `int main (void)`
- Defined: `FatFs-R0.16/documents/res/app3.c:78`

## FatFs-R0.16/documents/res/app4.c

### pn (function) `static DWORD pn (       /* Pseudo random number generator */
    DWORD pns   /* 0:Initialize, !0:...`
- Defined: `FatFs-R0.16/documents/res/app4.c:14`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### test_diskio (function) `int test_diskio (
    BYTE pdrv,      /* Physical drive number to be checked (all data on the dri...`
- Defined: `FatFs-R0.16/documents/res/app4.c:36`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### main (function) `int main (int argc, char* argv[])`
- Defined: `FatFs-R0.16/documents/res/app4.c:299`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/documents/res/app5.c

### test_contiguous_file (function) `FRESULT test_contiguous_file (
    FIL* fp,    /* [IN]  Open file object to be checked */
    int...`
- Defined: `FatFs-R0.16/documents/res/app5.c:5`

## FatFs-R0.16/documents/res/app6.c

### test_raw_speed (function) `int test_raw_speed (
    BYTE pdrv,      /* Physical drive number */
    DWORD lba,      /* Start...`
- Defined: `FatFs-R0.16/documents/res/app6.c:11`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/diskio.c

### disk_status (function) `DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)`
- Defined: `FatFs-R0.16/source/diskio.c:27`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_initialize (function) `DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)`
- Defined: `FatFs-R0.16/source/diskio.c:65`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_read (function) `DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		...`
- Defined: `FatFs-R0.16/source/diskio.c:103`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_write (function) `DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE ...`
- Defined: `FatFs-R0.16/source/diskio.c:153`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_ioctl (function) `DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code *...`
- Defined: `FatFs-R0.16/source/diskio.c:202`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/ff.c

### dbc_1st (function) `static int dbc_1st (BYTE c)`
- Defined: `FatFs-R0.16/source/ff.c:693`
- Doc: ptr++ = (BYTE)val; val >>= 8; ptr++ = (BYTE)val; val >>= 8; ptr++ = (BYTE)val; } #endif #endif	/* !FF_FS_READONLY /*----
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dbc_2nd (function) `static int dbc_2nd (BYTE c)`
- Defined: `FatFs-R0.16/source/ff.c:713`
- Doc: } #elif FF_CODE_PAGE >= 900	/* DBCS fixed code page if (c >= DbcTbl[0]) { if (c <= DbcTbl[1]) return 1; if (c >= DbcTbl[
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### tchar2uni (function) `static DWORD tchar2uni (	/* Returns a character in UTF-16 encoding (>=0x10000 on surrogate pair, ...`
- Defined: `FatFs-R0.16/source/ff.c:737`
- Doc: if (c <= DbcTbl[5]) return 1; if (c >= DbcTbl[6] && c <= DbcTbl[7]) return 1; if (c >= DbcTbl[8] && c <= DbcTbl[9]) retu
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### put_utf (function) `static UINT put_utf (	/* Returns number of encoding units written (0:buffer overflow or wrong enc...`
- Defined: `FatFs-R0.16/source/ff.c:806`
- Doc: } if (wc != 0) { wc = ff_oem2uni(wc, CODEPAGE);	/* ANSI/OEM ==> Unicode if (wc == 0) return 0xFFFFFFFF;	/* Invalid code?
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### lock_volume (function) `static int lock_volume (	/* 1:Ok, 0:timeout */
	FATFS* fs,				/* Filesystem object to lock */
	in...`
- Defined: `FatFs-R0.16/source/ff.c:896`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### unlock_volume (function) `static void unlock_volume (
	FATFS* fs,		/* Filesystem object */
	FRESULT res		/* Result code to ...`
- Defined: `FatFs-R0.16/source/ff.c:922`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### chk_share (function) `static FRESULT chk_share (	/* Check if the file can be accessed */
	DIR* dp,		/* Directory object...`
- Defined: `FatFs-R0.16/source/ff.c:947`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### inc_share (function) `static UINT inc_share (	/* Increment object open counter and returns its index (0:Internal error)...`
- Defined: `FatFs-R0.16/source/ff.c:983`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dec_share (function) `static FRESULT dec_share (	/* Decrement object open counter */
	UINT i			/* Semaphore index (1..)...`
- Defined: `FatFs-R0.16/source/ff.c:1014`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### clear_share (function) `static void clear_share (	/* Clear all lock entries of the volume */
	FATFS* fs
)`
- Defined: `FatFs-R0.16/source/ff.c:1038`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### sync_window (function) `static FRESULT sync_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs			/* Filesystem object...`
- Defined: `FatFs-R0.16/source/ff.c:1057`
- Doc: for (i = 0; i < FF_FS_LOCK; i++) { if (Files[i].fs == fs) Files[i].fs = 0; } } #endif	/* FF_FS_LOCK /*------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### move_window (function) `static FRESULT move_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs,		/* Filesystem object...`
- Defined: `FatFs-R0.16/source/ff.c:1079`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### sync_fs (function) `static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs		/* Filesystem object */
)`
- Defined: `FatFs-R0.16/source/ff.c:1110`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### clst2sect (function) `static LBA_t clst2sect (	/* !=0:Sector number, 0:Failed (invalid cluster#) */
	FATFS* fs,		/* Fil...`
- Defined: `FatFs-R0.16/source/ff.c:1159`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### get_fat (function) `static DWORD get_fat (		/* 0xFFFFFFFF:Disk error, 1:Internal error, 2..0x7FFFFFFF:Cluster status ...`
- Defined: `FatFs-R0.16/source/ff.c:1176`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### put_fat (function) `static FRESULT put_fat (	/* FR_OK(0):succeeded, !=0:error */
	FATFS* fs,		/* Corresponding filesy...`
- Defined: `FatFs-R0.16/source/ff.c:1254`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### find_bitmap (function) `static DWORD find_bitmap (	/* 0:Not found, 2..:Cluster block found, 0xFFFFFFFF:Disk error */
	FAT...`
- Defined: `FatFs-R0.16/source/ff.c:1319`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### change_bitmap (function) `static FRESULT change_bitmap (
	FATFS* fs,	/* Filesystem object */
	DWORD clst,	/* Cluster number...`
- Defined: `FatFs-R0.16/source/ff.c:1359`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### fill_first_frag (function) `static FRESULT fill_first_frag (
	FFOBJID* obj	/* Pointer to the corresponding object */
)`
- Defined: `FatFs-R0.16/source/ff.c:1395`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### fill_last_frag (function) `static FRESULT fill_last_frag (
	FFOBJID* obj,	/* Pointer to the corresponding object */
	DWORD l...`
- Defined: `FatFs-R0.16/source/ff.c:1418`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### remove_chain (function) `static FRESULT remove_chain (	/* FR_OK(0):succeeded, !=0:error */
	FFOBJID* obj,		/* Correspondin...`
- Defined: `FatFs-R0.16/source/ff.c:1444`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### create_chain (function) `static DWORD create_chain (	/* 0:No free cluster, 1:Internal error, 0xFFFFFFFF:Disk error, >=2:Ne...`
- Defined: `FatFs-R0.16/source/ff.c:1539`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### clmt_clust (function) `static DWORD clmt_clust (	/* <2:Error, >=2:Cluster number */
	FIL* fp,		/* Pointer to the file ob...`
- Defined: `FatFs-R0.16/source/ff.c:1644`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_clear (function) `static FRESULT dir_clear (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS *fs,		/* Filesystem object *...`
- Defined: `FatFs-R0.16/source/ff.c:1675`
- Doc: if !FF_FS_READONLY
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_sdi (function) `static FRESULT dir_sdi (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,		/* Pointer to directory o...`
- Defined: `FatFs-R0.16/source/ff.c:1714`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_next (function) `static FRESULT dir_next (	/* FR_OK(0):succeeded, FR_NO_FILE:End of table, FR_DENIED:Could not str...`
- Defined: `FatFs-R0.16/source/ff.c:1762`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_alloc (function) `static FRESULT dir_alloc (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,				/* Pointer to the dir...`
- Defined: `FatFs-R0.16/source/ff.c:1823`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### ld_clust (function) `static DWORD ld_clust (	/* Returns the top cluster value of the SFN entry */
	FATFS* fs,			/* Poi...`
- Defined: `FatFs-R0.16/source/ff.c:1865`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### st_clust (function) `static void st_clust (
	FATFS* fs,	/* Pointer to the fs object */
	BYTE* dir,	/* Pointer to the k...`
- Defined: `FatFs-R0.16/source/ff.c:1882`
- Doc: if !FF_FS_READONLY
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### cmp_lfn (function) `static int cmp_lfn (		/* 1:matched, 0:not matched */
	const WCHAR* lfnbuf,	/* Pointer to the LFN ...`
- Defined: `FatFs-R0.16/source/ff.c:1902`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### pick_lfn (function) `static int pick_lfn (	/* 1:succeeded, 0:buffer overflow or invalid LFN entry */
	WCHAR* lfnbuf,		...`
- Defined: `FatFs-R0.16/source/ff.c:1938`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### put_lfn (function) `static void put_lfn (
	const WCHAR* lfn,	/* Pointer to the LFN */
	BYTE* dir,			/* Pointer to the...`
- Defined: `FatFs-R0.16/source/ff.c:1976`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### gen_numname (function) `static void gen_numname (
	BYTE* dst,			/* Pointer to the buffer to store numbered SFN */
	const ...`
- Defined: `FatFs-R0.16/source/ff.c:2013`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### sum_sfn (function) `static BYTE sum_sfn (
	const BYTE* dir		/* Pointer to the SFN entry */
)`
- Defined: `FatFs-R0.16/source/ff.c:2070`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### xdir_sum (function) `static WORD xdir_sum (	/* Get checksum of the directoly entry block */
	const BYTE* dir		/* Direc...`
- Defined: `FatFs-R0.16/source/ff.c:2092`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### xname_sum (function) `static WORD xname_sum (	/* Get check sum (to be used as hash) of the file name */
	const WCHAR* n...`
- Defined: `FatFs-R0.16/source/ff.c:2113`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### xsum32 (function) `static DWORD xsum32 (	/* Returns 32-bit checksum */
	BYTE  dat,			/* Byte to be calculated (byte-...`
- Defined: `FatFs-R0.16/source/ff.c:2131`
- Doc: if !FF_FS_READONLY && FF_USE_MKFS
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### load_xdir (function) `static FRESULT load_xdir (	/* FR_INT_ERR: invalid entry block */
	DIR* dp					/* Reading director...`
- Defined: `FatFs-R0.16/source/ff.c:2147`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### init_alloc_info (function) `static void init_alloc_info (
	FFOBJID* dobj,	/* Object allocation information to be initialized ...`
- Defined: `FatFs-R0.16/source/ff.c:2199`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### load_obj_xdir (function) `static FRESULT load_obj_xdir (
	DIR* dp,			/* Blank directory object to be used to access contain...`
- Defined: `FatFs-R0.16/source/ff.c:2225`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### store_xdir (function) `static FRESULT store_xdir (
	DIR* dp				/* Pointer to the directory object */
)`
- Defined: `FatFs-R0.16/source/ff.c:2254`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### create_xdir (function) `static void create_xdir (
	BYTE* dirb,			/* Pointer to the directory entry block buffer */
	const...`
- Defined: `FatFs-R0.16/source/ff.c:2288`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_read (function) `static FRESULT dir_read (
	DIR* dp,		/* Pointer to the directory object */
	int vol			/* Filtered...`
- Defined: `FatFs-R0.16/source/ff.c:2334`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_find (function) `static FRESULT dir_find (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp					/* Pointer to the dire...`
- Defined: `FatFs-R0.16/source/ff.c:2412`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_register (function) `static FRESULT dir_register (	/* FR_OK:succeeded, FR_DENIED:no free entry or too many SFN collisi...`
- Defined: `FatFs-R0.16/source/ff.c:2494`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_remove (function) `static FRESULT dir_remove (	/* FR_OK:Succeeded, FR_DISK_ERR:A disk error */
	DIR* dp					/* Direc...`
- Defined: `FatFs-R0.16/source/ff.c:2607`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### get_fileinfo (function) `static void get_fileinfo (
	DIR* dp,			/* Pointer to the directory object */
	FILINFO* fno		/* Po...`
- Defined: `FatFs-R0.16/source/ff.c:2653`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### get_achar (function) `static DWORD get_achar (	/* Get a character and advance ptr */
	const TCHAR** ptr		/* Pointer to ...`
- Defined: `FatFs-R0.16/source/ff.c:2807`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### pattern_match (function) `static int pattern_match (	/* 0:mismatched, 1:matched */
	const TCHAR* pat,	/* Matching pattern *...`
- Defined: `FatFs-R0.16/source/ff.c:2838`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### create_name (function) `static FRESULT create_name (	/* FR_OK: successful, FR_INVALID_NAME: could not create */
	DIR* dp,...`
- Defined: `FatFs-R0.16/source/ff.c:2892`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### follow_path (function) `static FRESULT follow_path (	/* FR_OK(0): successful, !=0: error code */
	DIR* dp,					/* Directo...`
- Defined: `FatFs-R0.16/source/ff.c:3101`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### get_ldnumber (function) `static int get_ldnumber (	/* Returns logical drive number (-1:invalid drive number or null pointe...`
- Defined: `FatFs-R0.16/source/ff.c:3220`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### crc32 (function) `static DWORD crc32 (	/* Returns next CRC value */
	DWORD crc,			/* Current CRC value */
	BYTE d		...`
- Defined: `FatFs-R0.16/source/ff.c:3297`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### test_gpt_header (function) `static int test_gpt_header (	/* 0:Invalid, 1:Valid */
	const BYTE* gpth			/* Pointer to the GPT h...`
- Defined: `FatFs-R0.16/source/ff.c:3315`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### make_rand (function) `static DWORD make_rand (	/* Returns a seed value for next */
	DWORD seed,				/* Seed value */
	BY...`
- Defined: `FatFs-R0.16/source/ff.c:3339`
- Doc: if (hlen < 92 || hlen > FF_MIN_SS) return 0; for (i = 0, bcc = 0xFFFFFFFF; i < hlen; i++) {			/* Check header BCC bcc = 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### check_fs (function) `static UINT check_fs (	/* 0:FAT/FAT32 VBR, 1:exFAT VBR, 2:Not FAT and valid BS, 3:Not FAT and inv...`
- Defined: `FatFs-R0.16/source/ff.c:3367`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### find_volume (function) `static UINT find_volume (	/* Returns BS status found in the hosting drive */
	FATFS* fs,		/* File...`
- Defined: `FatFs-R0.16/source/ff.c:3407`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### mount_volume (function) `static FRESULT mount_volume (	/* FR_OK(0): successful, !=0: an error occurred */
	const TCHAR** p...`
- Defined: `FatFs-R0.16/source/ff.c:3461`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### validate (function) `static FRESULT validate (	/* Returns FR_OK or FR_INVALID_OBJECT */
	FFOBJID* obj,			/* Pointer to...`
- Defined: `FatFs-R0.16/source/ff.c:3695`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_open (function) `FRESULT f_open (
	FIL* fp,			/* Pointer to the blank file object */
	const TCHAR* path,	/* Pointe...`
- Defined: `FatFs-R0.16/source/ff.c:3799`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_read (function) `FRESULT f_read (
	FIL* fp, 	/* Open file to be read */
	void* buff,	/* Data buffer to store the r...`
- Defined: `FatFs-R0.16/source/ff.c:3996`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_write (function) `FRESULT f_write (
	FIL* fp,			/* Open file to be written */
	const void* buff,	/* Data to be writ...`
- Defined: `FatFs-R0.16/source/ff.c:4097`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_sync (function) `FRESULT f_sync (
	FIL* fp		/* Open file to be synced */
)`
- Defined: `FatFs-R0.16/source/ff.c:4218`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_close (function) `FRESULT f_close (
	FIL* fp		/* Open file to be closed */
)`
- Defined: `FatFs-R0.16/source/ff.c:4299`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_chdrive (function) `FRESULT f_chdrive (
	const TCHAR* path		/* Drive number to set */
)`
- Defined: `FatFs-R0.16/source/ff.c:4335`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_chdir (function) `FRESULT f_chdir (
	const TCHAR* path	/* Pointer to the directory path */
)`
- Defined: `FatFs-R0.16/source/ff.c:4357`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_getcwd (function) `FRESULT f_getcwd (
	TCHAR* buff,	/* Pointer to the buffer to store the current direcotry path */
...`
- Defined: `FatFs-R0.16/source/ff.c:4419`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_lseek (function) `FRESULT f_lseek (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t ofs		/* File pointer from ...`
- Defined: `FatFs-R0.16/source/ff.c:4555`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_opendir (function) `FRESULT f_opendir (
	DIR* dp,			/* Pointer to directory object to create */
	const TCHAR* path	/*...`
- Defined: `FatFs-R0.16/source/ff.c:4719`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_closedir (function) `FRESULT f_closedir (
	DIR *dp		/* Pointer to the directory object to be closed */
)`
- Defined: `FatFs-R0.16/source/ff.c:4781`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_readdir (function) `FRESULT f_readdir (
	DIR* dp,			/* Pointer to the open directory object */
	FILINFO* fno		/* Poin...`
- Defined: `FatFs-R0.16/source/ff.c:4811`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_findnext (function) `FRESULT f_findnext (
	DIR* dp,		/* Pointer to the open directory object */
	FILINFO* fno	/* Point...`
- Defined: `FatFs-R0.16/source/ff.c:4850`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_findfirst (function) `FRESULT f_findfirst (
	DIR* dp,				/* Pointer to the blank directory object */
	FILINFO* fno,			/...`
- Defined: `FatFs-R0.16/source/ff.c:4875`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_stat (function) `FRESULT f_stat (
	const TCHAR* path,	/* Pointer to the file path */
	FILINFO* fno		/* Pointer to ...`
- Defined: `FatFs-R0.16/source/ff.c:4902`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_getfree (function) `FRESULT f_getfree (
	const TCHAR* path,	/* Logical drive number */
	DWORD* nclst,		/* Pointer to ...`
- Defined: `FatFs-R0.16/source/ff.c:4939`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_truncate (function) `FRESULT f_truncate (
	FIL* fp		/* Pointer to the file object */
)`
- Defined: `FatFs-R0.16/source/ff.c:5036`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_unlink (function) `FRESULT f_unlink (
	const TCHAR* path		/* Pointer to the file or directory path */
)`
- Defined: `FatFs-R0.16/source/ff.c:5087`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_mkdir (function) `FRESULT f_mkdir (
	const TCHAR* path		/* Pointer to the directory path */
)`
- Defined: `FatFs-R0.16/source/ff.c:5176`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_rename (function) `FRESULT f_rename (
	const TCHAR* path_old,	/* Pointer to the object name to be renamed */
	const ...`
- Defined: `FatFs-R0.16/source/ff.c:5261`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_chmod (function) `FRESULT f_chmod (
	const TCHAR* path,	/* Pointer to the file path */
	BYTE attr,			/* Attribute b...`
- Defined: `FatFs-R0.16/source/ff.c:5385`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_utime (function) `FRESULT f_utime (
	const TCHAR* path,	/* Pointer to the file/directory name */
	const FILINFO* fn...`
- Defined: `FatFs-R0.16/source/ff.c:5434`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_getlabel (function) `FRESULT f_getlabel (
	const TCHAR* path,	/* Logical drive number */
	TCHAR* label,		/* Buffer to ...`
- Defined: `FatFs-R0.16/source/ff.c:5502`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_setlabel (function) `FRESULT f_setlabel (
	const TCHAR* label	/* Volume label to set with heading logical drive number...`
- Defined: `FatFs-R0.16/source/ff.c:5603`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_expand (function) `FRESULT f_expand (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t fsz,	/* File size to be e...`
- Defined: `FatFs-R0.16/source/ff.c:5726`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_forward (function) `FRESULT f_forward (
	FIL* fp, 						/* Pointer to the file object */
	UINT (*func)(const BYTE*,UI...`
- Defined: `FatFs-R0.16/source/ff.c:5822`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### create_partition (function) `static FRESULT create_partition (
	BYTE drv,			/* Physical drive number */
	const LBA_t plst[],	/...`
- Defined: `FatFs-R0.16/source/ff.c:5900`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_mkfs (function) `FRESULT f_mkfs (
	const TCHAR* path,		/* Logical drive number */
	const MKFS_PARM* opt,	/* Format...`
- Defined: `FatFs-R0.16/source/ff.c:6043`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_fdisk (function) `FRESULT f_fdisk (
	BYTE pdrv,			/* Physical drive number */
	const LBA_t ptbl[],	/* Pointer to th...`
- Defined: `FatFs-R0.16/source/ff.c:6548`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_gets (function) `TCHAR* f_gets (
	TCHAR* buff,	/* Pointer to the buffer to store read string */
	int len,		/* Size...`
- Defined: `FatFs-R0.16/source/ff.c:6588`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### putc_bfd (function) `static void putc_bfd (putbuff* pb, TCHAR c)`
- Defined: `FatFs-R0.16/source/ff.c:6740`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### putc_flush (function) `static int putc_flush (putbuff* pb)`
- Defined: `FatFs-R0.16/source/ff.c:6871`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### putc_init (function) `static void putc_init (putbuff* pb, FIL* fp)`
- Defined: `FatFs-R0.16/source/ff.c:6886`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_putc (function) `int f_putc (
	TCHAR c,	/* A character to be output */
	FIL* fp		/* Pointer to the file object */
)`
- Defined: `FatFs-R0.16/source/ff.c:6894`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_puts (function) `int f_puts (
	const TCHAR* str,	/* Pointer to the string to be output */
	FIL* fp				/* Pointer t...`
- Defined: `FatFs-R0.16/source/ff.c:6914`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### ftoa (function) `static void ftoa (
	char* buf,	/* Buffer to output the floating point string */
	double val,	/* V...`
- Defined: `FatFs-R0.16/source/ff.c:6980`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_printf (function) `int f_printf (
	FIL* fp,			/* Pointer to the file object */
	const TCHAR* fmt,	/* Pointer to the ...`
- Defined: `FatFs-R0.16/source/ff.c:7057`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_setcp (function) `FRESULT f_setcp (
	WORD cp		/* Value to be set as active code page */
)`
- Defined: `FatFs-R0.16/source/ff.c:7226`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/ff.h

### f_putc (function) `int f_putc (TCHAR c, FIL* fp);`
- Defined: `FatFs-R0.16/source/ff.h:353`
- Doc: FRESULT f_chmod (const TCHAR* path, BYTE attr, BYTE mask);			/* Change attribute of a file/dir FRESULT f_utime (const TC
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_puts (function) `int f_puts (const TCHAR* str, FIL* cp);`
- Defined: `FatFs-R0.16/source/ff.h:354`
- Doc: FRESULT f_utime (const TCHAR* path, const FILINFO* fno);			/* Change timestamp of a file/dir FRESULT f_chdir (const TCHA
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_printf (function) `int f_printf (FIL* fp, const TCHAR* str, ...);`
- Defined: `FatFs-R0.16/source/ff.h:355`
- Doc: FRESULT f_chdir (const TCHAR* path);								/* Change current directory FRESULT f_chdrive (const TCHAR* path);								/*
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_gets (function) `TCHAR* f_gets (TCHAR* buff, int len, FIL* fp);`
- Defined: `FatFs-R0.16/source/ff.h:356`
- Doc: FRESULT f_chdrive (const TCHAR* path);								/* Change current drive FRESULT f_getcwd (TCHAR* buff, UINT len);							/*
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ff_memalloc (function) `void* ff_memalloc (UINT msize);`
- Defined: `FatFs-R0.16/source/ff.h:394`
- Doc: /* LFN support functions (defined in ffunicode.c) #if FF_USE_LFN >= 1 WCHAR ff_oem2uni (WCHAR oem, WORD cp);	/* OEM code
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ff_memfree (function) `void ff_memfree (void* mblock);`
- Defined: `FatFs-R0.16/source/ff.h:395`
- Doc: /* LFN support functions (defined in ffunicode.c) #if FF_USE_LFN >= 1 WCHAR ff_oem2uni (WCHAR oem, WORD cp);	/* OEM code
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ff_mutex_create (function) `int ff_mutex_create (int vol);`
- Defined: `FatFs-R0.16/source/ff.h:398`
- Doc: #if FF_USE_LFN >= 1 WCHAR ff_oem2uni (WCHAR oem, WORD cp);	/* OEM code to Unicode conversion WCHAR ff_uni2oem (DWORD uni
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ff_mutex_delete (function) `void ff_mutex_delete (int vol);`
- Defined: `FatFs-R0.16/source/ff.h:399`
- Doc: WCHAR ff_oem2uni (WCHAR oem, WORD cp);	/* OEM code to Unicode conversion WCHAR ff_uni2oem (DWORD uni, WORD cp);	/* Unico
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ff_mutex_take (function) `int ff_mutex_take (int vol);`
- Defined: `FatFs-R0.16/source/ff.h:400`
- Doc: WCHAR ff_uni2oem (DWORD uni, WORD cp);	/* Unicode to OEM code conversion DWORD ff_wtoupper (DWORD uni);			/* Unicode upp
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ff_mutex_give (function) `void ff_mutex_give (int vol);`
- Defined: `FatFs-R0.16/source/ff.h:401`
- Doc: DWORD ff_wtoupper (DWORD uni);			/* Unicode upper-case conversion #endif /* O/S dependent functions (samples available i
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

## FatFs-R0.16/source/ffsystem.c

### ff_memalloc (function) `void* ff_memalloc (	/* Returns pointer to the allocated memory block (null if not enough core) */...`
- Defined: `FatFs-R0.16/source/ffsystem.c:17`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_memfree (function) `void ff_memfree (
	void* mblock	/* Pointer to the memory block to free (no effect if null) */
)`
- Defined: `FatFs-R0.16/source/ffsystem.c:25`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_mutex_create (function) `int ff_mutex_create (	/* Returns 1:Function succeeded or 0:Could not create the mutex */
	int vol...`
- Defined: `FatFs-R0.16/source/ffsystem.c:79`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_mutex_delete (function) `void ff_mutex_delete (	/* Returns 1:Function succeeded or 0:Could not delete due to an error */
	...`
- Defined: `FatFs-R0.16/source/ffsystem.c:120`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_mutex_take (function) `int ff_mutex_take (	/* Returns 1:Succeeded or 0:Timeout */
	int vol			/* Mutex ID: Volume mutex (...`
- Defined: `FatFs-R0.16/source/ffsystem.c:152`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_mutex_give (function) `void ff_mutex_give (
	int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (...`
- Defined: `FatFs-R0.16/source/ffsystem.c:185`
- Depends on: `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/ffunicode.c

### ff_uni2oem (function) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15222`
- Doc: if FF_CODE_PAGE != 0 && FF_CODE_PAGE < 900
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_oem2uni (function) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15244`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_uni2oem (function) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15275`
- Doc: if FF_CODE_PAGE >= 900
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_oem2uni (function) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15311`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_uni2oem (function) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15358`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_oem2uni (function) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15410`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_wtoupper (function) `DWORD ff_wtoupper (	/* Returns up-converted code point */
	DWORD uni		/* Unicode code point to be...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15464`
- Depends on: `FatFs-R0.16/source/ff.h`

## esp32-qemu-test/app/main/fatfs_vuln_test.c

### __attribute__ (function) `__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const struct dirent *entry)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:55`

### legitimate_update_callback (function) `static void legitimate_update_callback(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:67`

### run_lfn_copy_probe (function) `static bool run_lfn_copy_probe(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:72`

### get_firmware_size (function) `static long get_firmware_size(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:121`

### read_firmware_image (function) `static bool read_firmware_image(int fd, size_t firmware_size)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:134`

### run_update_flow (function) `static void run_update_flow(long attacker_fsize)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:152`

### app_main (function) `void app_main(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:170`

### readdir (function) `* readdir() returns an attacker-controlled long filename, then application * code copies it into a fixed 32-byte stack/global buffer without bounds * checks, matching public ESP32 code patterns. */ DI`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:76`

## esp32-qemu-test/run.sh

### usage (function)
- Defined: `esp32-qemu-test/run.sh:25`

### image_exists (function)
- Defined: `esp32-qemu-test/run.sh:35`

### ensure_image (function)
- Defined: `esp32-qemu-test/run.sh:39`

### do_build (function)
- Defined: `esp32-qemu-test/run.sh:46`

### do_run (function)
- Defined: `esp32-qemu-test/run.sh:53`

### do_shell (function)
- Defined: `esp32-qemu-test/run.sh:63`

## esp32-qemu-test/scripts/gen_exploit_image.py

### lfn_checksum (function) `def lfn_checksum(short_name_11)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:67`
- Doc: Calculate VFAT LFN checksum for an 8.3 short name (11 bytes).

### build_lfn_entries (function) `def build_lfn_entries(long_name, short_name_11)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:76`
- Doc: Build VFAT LFN entries followed by the 8.3 entry for the same file.

### resolve_symbol_address (function) `def resolve_symbol_address(elf_path, symbol_name)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:115`
- Doc: Resolve a symbol address from an ELF using nm.

### build_xtensa_uart_shellcode (function) `def build_xtensa_uart_shellcode()`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:149`
- Doc: Assemble raw Xtensa bytes that write a marker directly to UART0 and return.

### build_payload_sector (function) `def build_payload_sector(shellcode, callback_target_addr)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:271`
- Doc: Build sector-8 payload bytes. The file starts as a normal firmware header

### generate_bug1_espidf_image (function) `def generate_bug1_espidf_image(shellcode, callback_target_addr)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:282`
- Doc: Generate a crafted FAT32 image for the ESP32 PoC.

### inject_into_flash (function) `def inject_into_flash(flash_path, output_path, shellcode, callback_target_addr)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:389`
- Doc: Read the merged ESP32 flash image, inject the exploit FatFs partition

### main (function) `def main()`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:456`

## fuzzer/fat_image.go

### le16 (function) `func le16(`
- Defined: `fuzzer/fat_image.go:19`

### le32 (function) `func le32(`
- Defined: `fuzzer/fat_image.go:20`

### le64 (function) `func le64(`
- Defined: `fuzzer/fat_image.go:21`

### newDisk (function) `func newDisk(`
- Defined: `fuzzer/fat_image.go:29`
- Doc: newDisk returns a zeroed byte slice of min(totalSectors, maxDiskSectors) * 512 bytes.  Callers should still write the in

### DefaultFAT16Config (function) `func DefaultFAT16Config(`
- Defined: `fuzzer/fat_image.go:52`
- Doc: DefaultFAT16Config returns a valid, minimal 1 MiB FAT16 configuration.

### BuildFAT16 (function) `func BuildFAT16(`
- Defined: `fuzzer/fat_image.go:65`
- Doc: BuildFAT16 constructs a minimal FAT16 disk image from the given config.

### FAT16DataSector (function) `func FAT16DataSector(`
- Defined: `fuzzer/fat_image.go:107`
- Doc: FAT16DataSector returns the first sector of cluster c (c >= 2).

### DefaultFAT32Config (function) `func DefaultFAT32Config(`
- Defined: `fuzzer/fat_image.go:131`
- Doc: DefaultFAT32Config returns a valid FAT32 configuration sized to fit in the test harness RAM disk (4096 sectors = 2 MiB).

### BuildFAT32 (function) `func BuildFAT32(`
- Defined: `fuzzer/fat_image.go:144`
- Doc: BuildFAT32 constructs a minimal FAT32 disk image.

### BuildGPTImage (function) `func BuildGPTImage(`
- Defined: `fuzzer/fat_image.go:214`
- Doc: BuildGPTImage constructs a disk image with a GPT-protective MBR, a GPT header at sector 1 declaring nPartitions entries,

### BuildExFATImage (function) `func BuildExFATImage(`
- Defined: `fuzzer/fat_image.go:262`
- Doc: BuildExFATImage creates a minimal exFAT VBR. When numClusters == 0, n_fatent becomes 2 in FatFs, which is the divide-by-

### MutateFAT32BPB (function) `func MutateFAT32BPB(`
- Defined: `fuzzer/fat_image.go:303`
- Doc: MutateFAT32BPB returns a copy of a FAT32 disk image with the named BPB field set to value.

### RandomMutate (function) `func RandomMutate(`
- Defined: `fuzzer/fat_image.go:324`
- Doc: RandomMutate applies a single random byte-flip to a copy of disk.

### BuildExFATWithLargeLabel (function) `func BuildExFATWithLargeLabel(`
- Defined: `fuzzer/fat_image.go:354`
- Doc: volume-label directory entry has XDIR_NumLabel set to numLabel.  The exFAT spec limits XDIR_NumLabel to 11 characters.  

### sfnChecksum (function) `func sfnChecksum(`
- Defined: `fuzzer/fat_image.go:430`
- Doc: sfnChecksum computes the LFN checksum of an 11-byte FAT SFN (matching sum_sfn() in ff.c).

### BuildFAT16WithLFNFile (function) `func BuildFAT16WithLFNFile(`
- Defined: `fuzzer/fat_image.go:451`
- Doc: BuildFAT16WithLFNFile returns a FAT16 image identical to BuildFAT16(cfg) but with one file in the root directory whose L

## fuzzer/main.go

### main (function) `func main(`
- Defined: `fuzzer/main.go:51`

### buildAllSeeds (function) `func buildAllSeeds(`
- Defined: `fuzzer/main.go:76`

### BuildFAT12Minimal (function) `func BuildFAT12Minimal(`
- Defined: `fuzzer/main.go:290`

### FuzzFAT32BPB (function) `func FuzzFAT32BPB(`
- Defined: `fuzzer/main.go:343`
- Doc: FuzzFAT32BPB mutates individual BPB fields and checks structural consistency of the generated images.  The corpus is see

### FuzzGPTNEnt (function) `func FuzzGPTNEnt(`
- Defined: `fuzzer/main.go:398`
- Doc: FuzzGPTNEnt mutates GPTH_PtNum to explore the loop bound behaviour.

### FuzzExFATNumLabel (function) `func FuzzExFATNumLabel(`
- Defined: `fuzzer/main.go:449`
- Doc: FuzzExFATNumLabel mutates the XDIR_NumLabel byte in an exFAT volume label entry and checks structural invariants of the 

### FuzzFAT16LFNLength (function) `func FuzzFAT16LFNLength(`
- Defined: `fuzzer/main.go:507`
- Doc: FuzzFAT16LFNLength mutates the length of the LFN filename.

## harness/diskio_ramdisk.c

### ramdisk_reset_stats (function) `void ramdisk_reset_stats(void)`
- Defined: `harness/diskio_ramdisk.c:35`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### ramdisk_load (function) `void ramdisk_load(const BYTE *image, UINT size)`
- Defined: `harness/diskio_ramdisk.c:46`
- Doc: Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.  Any sector beyond the image is left zeroed. 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### ramdisk_eject (function) `void ramdisk_eject(void)`
- Defined: `harness/diskio_ramdisk.c:55`
- Doc: Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.  Any sector beyond the image is left zeroed. 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### disk_status (function) `DSTATUS disk_status(BYTE pdrv)`
- Defined: `harness/diskio_ramdisk.c:62`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### disk_initialize (function) `DSTATUS disk_initialize(BYTE pdrv)`
- Defined: `harness/diskio_ramdisk.c:68`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### disk_read (function) `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)`
- Defined: `harness/diskio_ramdisk.c:75`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### disk_write (function) `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)`
- Defined: `harness/diskio_ramdisk.c:95`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### disk_ioctl (function) `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)`
- Defined: `harness/diskio_ramdisk.c:114`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### get_fattime (function) `DWORD get_fattime(void)`
- Defined: `harness/diskio_ramdisk.c:137`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/diskio_ramdisk.h

### ramdisk_reset_stats (function) `void ramdisk_reset_stats(void);`
- Defined: `harness/diskio_ramdisk.h:26`
- Depends on: `FatFs-R0.16/source/ff.h`
- Imported by: `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ramdisk_load (function) `void ramdisk_load(const BYTE *image, UINT size);`
- Defined: `harness/diskio_ramdisk.h:31`
- Doc: /* ── backing store (accessible for direct inspection in tests) ──────────── extern BYTE ramdisk[RAMDISK_SECTOR_COUNT * 
- Depends on: `FatFs-R0.16/source/ff.h`
- Imported by: `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ramdisk_eject (function) `void ramdisk_eject(void);`
- Defined: `harness/diskio_ramdisk.h:34`
- Doc: /* ── instrumentation ────────────────────────────────────────────────────── extern volatile uint32_t ramdisk_read_count
- Depends on: `FatFs-R0.16/source/ff.h`
- Imported by: `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

## harness/exploit_disks.c

### exploit_disks (function) `*   make exploit_disks            (see Makefile target)
 *
 * Expected output:
 *   Generating 14...`
- Defined: `harness/exploit_disks.c:49`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### st32le (function) `static inline void st32le(uint8_t *p, uint32_t v)`
- Defined: `harness/exploit_disks.c:99`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### st64le (function) `static inline void st64le(uint8_t *p, uint64_t v)`
- Defined: `harness/exploit_disks.c:102`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### save_image (function) `static int save_image(const char *name, const uint8_t *buf, size_t sz)`
- Defined: `harness/exploit_disks.c:116`
- Doc: -------------------------------------------------------------------------- I/O helpers *--------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### load_ramdisk (function) `static void load_ramdisk(const uint8_t *buf, size_t sz)`
- Defined: `harness/exploit_disks.c:129`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug1_write_vbr (function) `static void bug1_write_vbr(uint8_t *disk)`
- Defined: `harness/exploit_disks.c:156`
- Doc: clst2sect(2) = 6 → attacker plants root-dir entry at sector 6 clst2sect(4) = 8 → attacker plants file payload at sector 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug1_fill_payload (function) `static void bug1_fill_payload(uint8_t *disk,
                               const uint8_t *payloa...`
- Defined: `harness/exploit_disks.c:227`
- Doc: bug1_fill_payload  —  write exploit bytes into sector 8 (cluster 4).  The first payload_sz bytes of sector 8 are filled 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug1_build (function) `static uint8_t *bug1_build(uint32_t file_size,
                            const uint8_t *payload...`
- Defined: `harness/exploit_disks.c:241`
- Doc: Allocate and build a complete CVE-2026-6682 image for a given file_size / payload. * Returns pointer to RAMDISK_SIZE_BYT
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug1_verify (function) `static int bug1_verify(uint8_t *disk, const char *filename)`
- Defined: `harness/exploit_disks.c:255`
- Doc: static uint8_t *bug1_build(uint32_t file_size, const uint8_t *payload, uint32_t payload_sz, uint8_t fill, const char *fn
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### Payload (function) `*   Payload (sector 8): placeholder address 0xDEADBEEFCAFEBABE
 *   Simulates: embedded OTA reade...`
- Defined: `harness/exploit_disks.c:293`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug1_espidf (function) `static void gen_bug1_espidf(void)`
- Defined: `harness/exploit_disks.c:317`
- Doc: -------------------------------------------------------------------------- CVE-2026-6682  image 2:  ESP-IDF stat/malloc/
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug1_stm32 (function) `static void gen_bug1_stm32(void)`
- Defined: `harness/exploit_disks.c:338`
- Doc: -------------------------------------------------------------------------- CVE-2026-6682  image 3:  STM32 CubeMX firmwar
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug1_keystone3 (function) `static void gen_bug1_keystone3(void)`
- Defined: `harness/exploit_disks.c:359`
- Doc: -------------------------------------------------------------------------- CVE-2026-6682  image 4:  Keystone3 hardware w
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug1_ardupilot (function) `static void gen_bug1_ardupilot(void)`
- Defined: `harness/exploit_disks.c:382`
- Doc: -------------------------------------------------------------------------- CVE-2026-6682  image 5:  ArduPilot / Mbed OS 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug2_exfat (function) `static void gen_bug2_exfat(void)`
- Defined: `harness/exploit_disks.c:456`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### MicroPython (function) `*                            MicroPython (if the port enables FF_LBA64)
 *
 * R0.16 fix:  test_gp...`
- Defined: `harness/exploit_disks.c:498`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### chain (function) `*   An application writes 64 bytes to the END of cluster chain (fp->sect = X,
 *   FA_DIRTY set),...`
- Defined: `harness/exploit_disks.c:576`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug4_set_fat16_entry (function) `static void bug4_set_fat16_entry(uint8_t *disk, uint16_t cluster, uint16_t value)`
- Defined: `harness/exploit_disks.c:638`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug4_fragmented (function) `static void gen_bug4_fragmented(void)`
- Defined: `harness/exploit_disks.c:648`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### Zephyr (function) `*                     Zephyr (R0.16), ArduPilot (R0.14b),
 *                     RIOT-OS (R0.15),...`
- Defined: `harness/exploit_disks.c:836`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug6_verify_overflow (function) `static int bug6_verify_overflow(uint8_t *disk, const char *imgname,
                             ...`
- Defined: `harness/exploit_disks.c:893`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug6_stm32 (function) `static void gen_bug6_stm32(void)`
- Defined: `harness/exploit_disks.c:933`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug6_zephyr (function) `static void gen_bug6_zephyr(void)`
- Defined: `harness/exploit_disks.c:948`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### layout (function) `*
 * Directory layout (FAT16):
 *   Entries in order: LFN entries (N × 32 bytes) then 8.3 SFN ent...`
- Defined: `harness/exploit_disks.c:990`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug7_build (function) `static void bug7_build(uint8_t *disk, int lfn_len, uint16_t dirent_name_size)`
- Defined: `harness/exploit_disks.c:1007`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug7_verify (function) `static int bug7_verify(uint8_t *disk, const char *imgname, int expected_lfn_len)`
- Defined: `harness/exploit_disks.c:1060`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug7_max255 (function) `static void gen_bug7_max255(void)`
- Defined: `harness/exploit_disks.c:1096`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug7_zephyr (function) `static void gen_bug7_zephyr(void)`
- Defined: `harness/exploit_disks.c:1112`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### main (function) `int main(void)`
- Defined: `harness/exploit_disks.c:1273`
- Doc: =========================================================================== main *======================================
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### code (function) `* * Vulnerable code (ff.c non-tiny path, f_read multi-sector branch): * disk_read(pdrv, rbuff, sect, cc);`
- Defined: `harness/exploit_disks.c:564`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### cc (function) `* if cc (sectors remaining) is also large, 0xFFFFFFFC < cc → TRUE * → memcpy fires at offset 0xFFFFFFFC * 512 (out of bounds) */ bug4_set_fat16_entry(disk, 2, 4);`
- Defined: `harness/exploit_disks.c:673`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/ffunicode_stub.c

### ff_uni2oem (function) `* ff_uni2oem() and ff_wtoupper() which normally come from ffunicode.c.
 * These stubs are suffici...`
- Defined: `harness/ffunicode_stub.c:5`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_uni2oem (function) `WCHAR ff_uni2oem(DWORD uni, WORD cp)`
- Defined: `harness/ffunicode_stub.c:18`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_wtoupper (function) `DWORD ff_wtoupper(DWORD chr)`
- Defined: `harness/ffunicode_stub.c:25`
- Doc: WCHAR ff_oem2uni(WCHAR oem, WORD cp) { (void)cp; return (oem < 0x80) ? oem : 0; } WCHAR ff_uni2oem(DWORD uni, WORD cp) {
- Depends on: `FatFs-R0.16/source/ff.h`

## harness/libfuzzer_harness.c

### Usage (function) `*
 * Usage (libFuzzer):
 *   ./fuzz_fatfs -max_len=2097152 corpus/
 *
 * Usage (AFL++):
 *   afl-...`
- Defined: `harness/libfuzzer_harness.c:10`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### main (function) `int main(int argc, char **argv)`
- Defined: `harness/libfuzzer_harness.c:128`
- Doc: f_close(&fp); break; /* process at most one file per fuzz iteration } f_closedir(&dj); } done: f_mount(NULL, "0:", 0); r
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/rce_demo.c

### Build (function) `*
 * Build (without sanitisers, without stack protector — lets the overflow
 * reach the function...`
- Defined: `harness/rce_demo.c:46`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### st32le (function) `static inline void st32le(uint8_t *p, uint32_t v)`
- Defined: `harness/rce_demo.c:73`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### st64le (function) `static inline void st64le(uint8_t *p, uint64_t v)`
- Defined: `harness/rce_demo.c:76`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### safe_update_complete (function) `static void safe_update_complete(void)`
- Defined: `harness/rce_demo.c:123`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### __attribute__ (function) `__attribute__((noinline))
static void rce_win(void)`
- Defined: `harness/rce_demo.c:132`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### vulnerable_ota_check (function) `static void vulnerable_ota_check(void)`
- Defined: `harness/rce_demo.c:155`
- Doc: This function is the VICTIM.  It contains no deliberately insecure code except for one extremely common mistake:  f_read
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_exploit_image (function) `static void build_exploit_image(uint8_t *disk, size_t disk_bytes,
                               ...`
- Defined: `harness/rce_demo.c:232`
- Doc: → database = sector 6   (inside FAT area [4, ∞)) → clst2sect(2) = 6  (root dir reads from sector 6) → clst2sect(4) = 8  
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### save_image (function) `static int save_image(const char *path, const uint8_t *disk, size_t sz)`
- Defined: `harness/rce_demo.c:348`
- Doc: printf("             version    [%u..%u)  = 0x00010000\n", FW_HDR_SIZE + 4, FW_HDR_SIZE + 8); printf("             on_ap
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### load_image (function) `static int load_image(const char *path)`
- Defined: `harness/rce_demo.c:363`
- Doc: { FILE *f = fopen(path, "wb"); if (!f) { perror(path); return -1; } size_t written = fwrite(disk, 1, sz, f); fclose(f); 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### main (function) `int main(void)`
- Defined: `harness/rce_demo.c:380`
- Doc: =========================================================================== main *======================================
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### fasize (function) `* fasize (DWORD) = 0x80000001 * 2 = 0x100000002 → truncates to 2 * sysect = 4 + 2 + 0 = 6 → database = sector 6 (inside FAT!) */ st32le(&vbr[36], 0x80000001U);`
- Defined: `harness/rce_demo.c:258`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/test_harness.c

### buffers (function) `*         buffers (e.g. char path[16]) and unchecked string copies
 *         (sprintf, strcat) o...`
- Defined: `harness/test_harness.c:36`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### st32le (function) `static inline void st32le(BYTE *p, uint32_t v)`
- Defined: `harness/test_harness.c:65`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### st64le (function) `static inline void st64le(BYTE *p, uint64_t v)`
- Defined: `harness/test_harness.c:70`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### rce_proof_of_execution (function) `static void rce_proof_of_execution(void)`
- Defined: `harness/test_harness.c:119`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_fat32_bug1 (function) `static void build_fat32_bug1(BYTE *disk, size_t disk_bytes)`
- Defined: `harness/test_harness.c:121`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### MCUs (function) `*    common on embedded MCUs (STM32, RP2040, ESP32, …).  The resulting call
 *    invokes rce_pro...`
- Defined: `harness/test_harness.c:261`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug1_rce_exploit (function) `static int test_bug1_rce_exploit(void)`
- Defined: `harness/test_harness.c:339`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_gpt_image (function) `static void build_gpt_image(BYTE *disk, size_t disk_bytes, uint32_t n_ent)`
- Defined: `harness/test_harness.c:459`
- Doc: Minimal protective-MBR + GPT header disk image builder.  Only as much structure as find_volume needs to enter the loop: 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### releases (function) `*
 * Historical note: older FatFs releases (before test_gpt_header was
 * introduced) had no such...`
- Defined: `harness/test_harness.c:510`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug4_stale_cache_skip (function) `static int test_bug4_stale_cache_skip(void)`
- Defined: `harness/test_harness.c:601`
- Doc: through a range that includes X. 4. The bulk disk_read() returns stale (pre-write) data for sector X; the cache copy tha
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### layout (function) `*
 * Disk layout (FAT16, 4 sectors/cluster):
 *   Sectors  0           VBR
 *   Sectors  1-4     ...`
- Defined: `harness/test_harness.c:694`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_fat16_base (function) `static void build_fat16_base(BYTE *disk, size_t disk_bytes)`
- Defined: `harness/test_harness.c:726`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### __attribute__ (function) `__attribute__((unused))
static void fat16_set_chain(BYTE *disk, uint16_t cluster, uint16_t next)`
- Defined: `harness/test_harness.c:764`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug5_infoleak_lseek (function) `static int test_bug5_infoleak_lseek(void)`
- Defined: `harness/test_harness.c:782`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### pass (function) `*      or pass (sizeof_label - di) instead of the hard-coded 4.
 *===============================...`
- Defined: `harness/test_harness.c:927`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug6_getlabel_exfat_overflow (function) `static int test_bug6_getlabel_exfat_overflow(void)`
- Defined: `harness/test_harness.c:999`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### sfn_checksum_b7 (function) `static BYTE sfn_checksum_b7(const BYTE sfn[11])`
- Defined: `harness/test_harness.c:1090`
- Doc: char fname[13];                     // SFN-sized buffer strcpy(fname, fno.fname);           // overflows if LFN > 12 cha
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_fat16_with_lfn (function) `static void build_fat16_with_lfn(BYTE *disk, size_t disk_bytes)`
- Defined: `harness/test_harness.c:1105`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug7_lfn_path_overflow (function) `static int test_bug7_lfn_path_overflow(void)`
- Defined: `harness/test_harness.c:1157`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### main (function) `int main(void)`
- Defined: `harness/test_harness.c:1257`
- Doc: =========================================================================== main *======================================
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### code (function) `* * Vulnerable code (ff.c ~line 3600): * * fasize = ld_16(fs->win + BPB_FATSz16);`
- Defined: `harness/test_harness.c:89`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### truncated (function) `* truncated (DWORD) → 0x00000002 * * sysect = 4 (reserved) + 2 (fake fasize) + 0 (no root) = 6 * * fs->database = bsect(0) + 6 = sector 6 ← within FAT area! */ st32le(&vbr[36], 0x80000001U);`
- Defined: `harness/test_harness.c:146`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### move_window (function) `* move_window(fs, pt_lba + i * SZ_GPTE / SS(fs));`
- Defined: `harness/test_harness.c:435`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memcpy (function) `* memcpy(rbuff + ((fp->sect - sect) * SS(fs)), fp->buf, SS(fs));`
- Defined: `harness/test_harness.c:561`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### byte (function) `* sentinel byte (0xC3) so that any write beyond offset 24 is visible. * * f_getlabel must receive a pointer to byte 0 of probe so that the * * overflow lands in the same contiguous allocation (detecta`
- Defined: `harness/test_harness.c:1023`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### sprintf (function) `* sprintf(path, "0:/%s", fno.fname);`
- Defined: `harness/test_harness.c:1075`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### strcpy (function) `* strcpy(fname, fno.fname);`
- Defined: `harness/test_harness.c:1078`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### strcat (function) `* strcat(path, fno.fname);`
- Defined: `harness/test_harness.c:1213`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`
