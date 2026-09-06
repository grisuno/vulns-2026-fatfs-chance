# API

## FatFs-R0.16/documents/res/app1.c

### open_append `FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* p...`
- Defined: `FatFs-R0.16/documents/res/app1.c:5`
- Doc: -----------------------------------------------------------/ Open or create a file in append mode (This function was spe

### main `int main (void)`
- Defined: `FatFs-R0.16/documents/res/app1.c:23`

## FatFs-R0.16/documents/res/app2.c

### delete_node `FRESULT delete_node (
    TCHAR* path,    /* Path name buffer with the sub-directory to delete */...`
- Defined: `FatFs-R0.16/documents/res/app2.c:7`
- Doc: -----------------------------------------------------------/ Delete a sub-directory even if it contains any file -------

## FatFs-R0.16/documents/res/app3.c

### allocate_contiguous_clusters `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:error or not contig...`
- Defined: `FatFs-R0.16/documents/res/app3.c:18`

### main `int main (void)`
- Defined: `FatFs-R0.16/documents/res/app3.c:76`

## FatFs-R0.16/documents/res/app4.c

### pn `static DWORD pn (       /* Pseudo random number generator */
    DWORD pns   /* 0:Initialize, !0:...`
- Defined: `FatFs-R0.16/documents/res/app4.c:11`
- Doc: ---------------------------------------------------------------------/ Low level disk I/O module function checker       

### test_diskio `int test_diskio (
    BYTE pdrv,      /* Physical drive number to be checked (all data on the dri...`
- Defined: `FatFs-R0.16/documents/res/app4.c:34`

### main `int main (int argc, char* argv[])`
- Defined: `FatFs-R0.16/documents/res/app4.c:296`

## FatFs-R0.16/documents/res/app5.c

### test_contiguous_file `FRESULT test_contiguous_file (
    FIL* fp,    /* [IN]  Open file object to be checked */
    int...`
- Defined: `FatFs-R0.16/documents/res/app5.c:4`
- Doc: ---------------------------------------------------------------------/ Test if the file is contiguous                   

## FatFs-R0.16/documents/res/app6.c

### test_raw_speed `int test_raw_speed (
    BYTE pdrv,      /* Physical drive number */
    DWORD lba,      /* Start...`
- Defined: `FatFs-R0.16/documents/res/app6.c:9`
- Doc: include <stdio.h> include <systimer.h> include "diskio.h" include "ff.h"

## FatFs-R0.16/source/diskio.c

### disk_status `DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)`
- Defined: `FatFs-R0.16/source/diskio.c:26`
- Doc: /* Example: Declarations of the platform and disk functions in the project #include "platform.h" #include "storage.h" /*

### disk_initialize `DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)`
- Defined: `FatFs-R0.16/source/diskio.c:64`
- Doc: result = USB_disk_status(); translate the reslut code here return stat; } return STA_NOINIT; } /*-----------------------

### disk_read `DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		...`
- Defined: `FatFs-R0.16/source/diskio.c:102`
- Doc: result = USB_disk_initialize(); translate the reslut code here return stat; } return STA_NOINIT; } /*-------------------

### disk_write `DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE ...`
- Defined: `FatFs-R0.16/source/diskio.c:152`
- Doc: if FF_FS_READONLY == 0

### disk_ioctl `DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code *...`
- Defined: `FatFs-R0.16/source/diskio.c:201`
- Doc: translate the reslut code here return res; } return RES_PARERR; } #endif /*---------------------------------------------

## FatFs-R0.16/source/ff.c

### dbc_1st `static int dbc_1st (BYTE c)`
- Defined: `FatFs-R0.16/source/ff.c:693`
- Doc: ptr++ = (BYTE)val; val >>= 8; ptr++ = (BYTE)val; val >>= 8; ptr++ = (BYTE)val; } #endif #endif	/* !FF_FS_READONLY /*----

### dbc_2nd `static int dbc_2nd (BYTE c)`
- Defined: `FatFs-R0.16/source/ff.c:713`
- Doc: } #elif FF_CODE_PAGE >= 900	/* DBCS fixed code page if (c >= DbcTbl[0]) { if (c <= DbcTbl[1]) return 1; if (c >= DbcTbl[

### tchar2uni `static DWORD tchar2uni (	/* Returns a character in UTF-16 encoding (>=0x10000 on surrogate pair, ...`
- Defined: `FatFs-R0.16/source/ff.c:737`
- Doc: if (c <= DbcTbl[5]) return 1; if (c >= DbcTbl[6] && c <= DbcTbl[7]) return 1; if (c >= DbcTbl[8] && c <= DbcTbl[9]) retu

### put_utf `static UINT put_utf (	/* Returns number of encoding units written (0:buffer overflow or wrong enc...`
- Defined: `FatFs-R0.16/source/ff.c:806`
- Doc: } if (wc != 0) { wc = ff_oem2uni(wc, CODEPAGE);	/* ANSI/OEM ==> Unicode if (wc == 0) return 0xFFFFFFFF;	/* Invalid code?

### lock_volume `static int lock_volume (	/* 1:Ok, 0:timeout */
	FATFS* fs,				/* Filesystem object to lock */
	in...`
- Defined: `FatFs-R0.16/source/ff.c:895`
- Doc: return 2; } if (wc == 0 || szb < 1) return 0;	/* Invalid character or buffer overflow? *buf++ = (TCHAR)wc;					/* Store 

### unlock_volume `static void unlock_volume (
	FATFS* fs,		/* Filesystem object */
	FRESULT res		/* Result code to ...`
- Defined: `FatFs-R0.16/source/ff.c:920`

### chk_share `static FRESULT chk_share (	/* Check if the file can be accessed */
	DIR* dp,		/* Directory object...`
- Defined: `FatFs-R0.16/source/ff.c:946`
- Doc: } #endif ff_mutex_give(fs->ldrv);	/* Unlock the volume } } #endif #if FF_FS_LOCK /*-------------------------------------

### inc_share `static UINT inc_share (	/* Increment object open counter and returns its index (0:Internal error)...`
- Defined: `FatFs-R0.16/source/ff.c:981`

### dec_share `static FRESULT dec_share (	/* Decrement object open counter */
	UINT i			/* Semaphore index (1..)...`
- Defined: `FatFs-R0.16/source/ff.c:1012`

### clear_share `static void clear_share (	/* Clear all lock entries of the volume */
	FATFS* fs
)`
- Defined: `FatFs-R0.16/source/ff.c:1036`

### sync_window `static FRESULT sync_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs			/* Filesystem object...`
- Defined: `FatFs-R0.16/source/ff.c:1057`
- Doc: for (i = 0; i < FF_FS_LOCK; i++) { if (Files[i].fs == fs) Files[i].fs = 0; } } #endif	/* FF_FS_LOCK /*------------------

### move_window `static FRESULT move_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs,		/* Filesystem object...`
- Defined: `FatFs-R0.16/source/ff.c:1077`
- Doc: endif

### sync_fs `static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs		/* Filesystem object */
)`
- Defined: `FatFs-R0.16/source/ff.c:1109`
- Doc: } fs->winsect = sect; } } return res; } #if !FF_FS_READONLY /*----------------------------------------------------------

### clst2sect `static LBA_t clst2sect (	/* !=0:Sector number, 0:Failed (invalid cluster#) */
	FATFS* fs,		/* Fil...`
- Defined: `FatFs-R0.16/source/ff.c:1158`
- Doc: /* Make sure that no pending write process in the lower layer if (disk_ioctl(fs->pdrv, CTRL_SYNC, 0) != RES_OK) res = FR

### get_fat `static DWORD get_fat (		/* 0xFFFFFFFF:Disk error, 1:Internal error, 2..0x7FFFFFFF:Cluster status ...`
- Defined: `FatFs-R0.16/source/ff.c:1175`
- Doc: DWORD clst		/* Cluster# to be converted ) { clst -= 2;		/* Cluster number is origin from 2 if (clst >= fs->n_fatent - 2)

### put_fat `static FRESULT put_fat (	/* FR_OK(0):succeeded, !=0:error */
	FATFS* fs,		/* Corresponding filesy...`
- Defined: `FatFs-R0.16/source/ff.c:1253`
- Doc: val = 1;	/* Internal error } } return val; } #if !FF_FS_READONLY /*-----------------------------------------------------

### find_bitmap `static DWORD find_bitmap (	/* 0:Not found, 2..:Cluster block found, 0xFFFFFFFF:Disk error */
	FAT...`
- Defined: `FatFs-R0.16/source/ff.c:1318`
- Doc: #endif /* !FF_FS_READONLY #if FF_FS_EXFAT && !FF_FS_READONLY /*---------------------------------------------------------

### change_bitmap `static FRESULT change_bitmap (
	FATFS* fs,	/* Filesystem object */
	DWORD clst,	/* Cluster number...`
- Defined: `FatFs-R0.16/source/ff.c:1358`
- Doc: } else { scl = val; ctr = 0;		/* Encountered a cluster in-use, restart to scan } if (val == clst) return 0;	/* All clust

### fill_first_frag `static FRESULT fill_first_frag (
	FFOBJID* obj	/* Pointer to the corresponding object */
)`
- Defined: `FatFs-R0.16/source/ff.c:1394`
- Doc: fs->win[i] ^= bm;	/* Flip the bit fs->wflag = 1; if (--ncl == 0) return FR_OK;	/* All bits processed? } while (bm <<= 1)

### fill_last_frag `static FRESULT fill_last_frag (
	FFOBJID* obj,	/* Pointer to the corresponding object */
	DWORD l...`
- Defined: `FatFs-R0.16/source/ff.c:1417`
- Doc: if (obj->stat == 3) {	/* Has the object been changed 'fragmented' in this session? for (cl = obj->sclust, n = obj->n_con

### remove_chain `static FRESULT remove_chain (	/* FR_OK(0):succeeded, !=0:error */
	FFOBJID* obj,		/* Correspondin...`
- Defined: `FatFs-R0.16/source/ff.c:1443`
- Doc: if (res != FR_OK) return res; obj->n_frag--; } return FR_OK; } #endif	/* FF_FS_EXFAT && !FF_FS_READONLY #if !FF_FS_READO

### create_chain `static DWORD create_chain (	/* 0:No free cluster, 1:Internal error, 0xFFFFFFFF:Disk error, >=2:Ne...`
- Defined: `FatFs-R0.16/source/ff.c:1538`
- Doc: } } } } #endif return FR_OK; } /*----------------------------------------------------------------------- /* FAT handling

### clmt_clust `static DWORD clmt_clust (	/* <2:Error, >=2:Cluster number */
	FIL* fp,		/* Pointer to the file ob...`
- Defined: `FatFs-R0.16/source/ff.c:1643`
- Doc: } return ncl;		/* Return new cluster number or error status } #endif /* !FF_FS_READONLY #if FF_USE_FASTSEEK /*----------

### dir_clear `static FRESULT dir_clear (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS *fs,		/* Filesystem object *...`
- Defined: `FatFs-R0.16/source/ff.c:1675`
- Doc: if !FF_FS_READONLY

### dir_sdi `static FRESULT dir_sdi (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,		/* Pointer to directory o...`
- Defined: `FatFs-R0.16/source/ff.c:1713`
- Doc: { ibuf = fs->win; szb = 1;	/* Use window buffer (many single-sector writes may take a time) for (n = 0; n < fs->csize &&

### dir_next `static FRESULT dir_next (	/* FR_OK(0):succeeded, FR_NO_FILE:End of table, FR_DENIED:Could not str...`
- Defined: `FatFs-R0.16/source/ff.c:1761`
- Doc: dp->clust = clst;					/* Current cluster# if (dp->sect == 0) return FR_INT_ERR; dp->sect += ofs / SS(fs);			/* Sector# o

### dir_alloc `static FRESULT dir_alloc (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,				/* Pointer to the dir...`
- Defined: `FatFs-R0.16/source/ff.c:1822`
- Doc: } dp->dptr = ofs;						/* Current entry dp->dir = fs->win + ofs % SS(fs);	/* Pointer to the entry in the win[] return FR

### ld_clust `static DWORD ld_clust (	/* Returns the top cluster value of the SFN entry */
	FATFS* fs,			/* Poi...`
- Defined: `FatFs-R0.16/source/ff.c:1864`
- Doc: } if (res == FR_NO_FILE) res = FR_DENIED;	/* No directory entry to allocate return res; } #endif	/* !FF_FS_READONLY /*--

### st_clust `static void st_clust (
	FATFS* fs,	/* Pointer to the fs object */
	BYTE* dir,	/* Pointer to the k...`
- Defined: `FatFs-R0.16/source/ff.c:1882`
- Doc: if !FF_FS_READONLY

### cmp_lfn `static int cmp_lfn (		/* 1:matched, 0:not matched */
	const WCHAR* lfnbuf,	/* Pointer to the LFN ...`
- Defined: `FatFs-R0.16/source/ff.c:1901`
- Doc: { st_16(dir + DIR_FstClusLO, (WORD)cl); if (fs->fs_type == FS_FAT32) { st_16(dir + DIR_FstClusHI, (WORD)(cl >> 16)); } }

### pick_lfn `static int pick_lfn (	/* 1:succeeded, 0:buffer overflow or invalid LFN entry */
	WCHAR* lfnbuf,		...`
- Defined: `FatFs-R0.16/source/ff.c:1937`
- Doc: if (chr != 0xFFFF) return 0;	/* Check filler } } if ((dir[LDIR_Ord] & LLEF) && pchr && lfnbuf[ni]) return 0;	/* Last nam

### put_lfn `static void put_lfn (
	const WCHAR* lfn,	/* Pointer to the LFN */
	BYTE* dir,			/* Pointer to the...`
- Defined: `FatFs-R0.16/source/ff.c:1975`
- Doc: if (dir[LDIR_Ord] & LLEF && pchr != 0) {	/* Put terminator if it is the last LFN part and not terminated if (ni >= FF_MA

### gen_numname `static void gen_numname (
	BYTE* dst,			/* Pointer to the buffer to store numbered SFN */
	const ...`
- Defined: `FatFs-R0.16/source/ff.c:2012`
- Doc: } while (++di < 13); if (chr == 0xFFFF || !lfn[ni]) ord |= LLEF;	/* Last LFN part is the start of an enrty set dir[LDIR_

### sum_sfn `static BYTE sum_sfn (
	const BYTE* dir		/* Pointer to the SFN entry */
)`
- Defined: `FatFs-R0.16/source/ff.c:2069`
- Doc: } } do {	/* Append the suffix dst[j++] = (i < 8) ? ns[i++] : ' '; } while (j < 8); } #endif	/* FF_USE_LFN && !FF_FS_READ

### xdir_sum `static WORD xdir_sum (	/* Get checksum of the directoly entry block */
	const BYTE* dir		/* Direc...`
- Defined: `FatFs-R0.16/source/ff.c:2091`
- Doc: do { sum = (sum >> 1) + (sum << 7) + *dir++; } while (--n); return sum; } #endif	/* FF_USE_LFN #if FF_FS_EXFAT /*-------

### xname_sum `static WORD xname_sum (	/* Get check sum (to be used as hash) of the file name */
	const WCHAR* n...`
- Defined: `FatFs-R0.16/source/ff.c:2110`

### xsum32 `static DWORD xsum32 (	/* Returns 32-bit checksum */
	BYTE  dat,			/* Byte to be calculated (byte-...`
- Defined: `FatFs-R0.16/source/ff.c:2131`
- Doc: if !FF_FS_READONLY && FF_USE_MKFS

### load_xdir `static FRESULT load_xdir (	/* FR_INT_ERR: invalid entry block */
	DIR* dp					/* Reading director...`
- Defined: `FatFs-R0.16/source/ff.c:2146`
- Doc: BYTE  dat,			/* Byte to be calculated (byte-by-byte processing) DWORD sum			/* Previous sum value ) { sum = ((sum & 1) ?

### init_alloc_info `static void init_alloc_info (
	FFOBJID* dobj,	/* Object allocation information to be initialized ...`
- Defined: `FatFs-R0.16/source/ff.c:2198`
- Doc: } while ((i += SZDIRE) < sz_ent); /* Sanity check (do it for only accessible object) if (i <= MAXDIRB(FF_MAX_LFN)) { if 

### load_obj_xdir `static FRESULT load_obj_xdir (
	DIR* dp,			/* Blank directory object to be used to access contain...`
- Defined: `FatFs-R0.16/source/ff.c:2224`
- Doc: dobj->c_ofs = sdir->blk_ofs; } dobj->sclust = ld_32(fs->dirbuf + XDIR_FstClus);	/* Start cluster dobj->objsize = ld_64(f

### store_xdir `static FRESULT store_xdir (
	DIR* dp				/* Pointer to the directory object */
)`
- Defined: `FatFs-R0.16/source/ff.c:2253`
- Doc: res = dir_sdi(dp, dp->blk_ofs);	/* Goto object's entry block if (res == FR_OK) { res = load_xdir(dp);		/* Load the objec

### create_xdir `static void create_xdir (
	BYTE* dirb,			/* Pointer to the directory entry block buffer */
	const...`
- Defined: `FatFs-R0.16/source/ff.c:2287`
- Doc: dp->obj.fs->wflag = 1; if (--nent == 0) break;	/* All done? dirb += SZDIRE; res = dir_next(dp, 0);	/* Next entry } retur

### dir_read `static FRESULT dir_read (
	DIR* dp,		/* Pointer to the directory object */
	int vol			/* Filtered...`
- Defined: `FatFs-R0.16/source/ff.c:2333`
- Doc: define DIR_READ_FILE(dp) dir_read(dp, 0) define DIR_READ_LABEL(dp) dir_read(dp, 1)

### dir_find `static FRESULT dir_find (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp					/* Pointer to the dire...`
- Defined: `FatFs-R0.16/source/ff.c:2411`
- Doc: if (res != FR_OK) break; } if (res != FR_OK) dp->sect = 0;		/* Terminate the read operation on error or EOT return res; 

### dir_register `static FRESULT dir_register (	/* FR_OK:succeeded, FR_DENIED:no free entry or too many SFN collisi...`
- Defined: `FatFs-R0.16/source/ff.c:2493`
- Doc: #endif res = dir_next(dp, 0);	/* Next entry } while (res == FR_OK); return res; } #if !FF_FS_READONLY /*----------------

### dir_remove `static FRESULT dir_remove (	/* FR_OK:Succeeded, FR_DISK_ERR:A disk error */
	DIR* dp					/* Direc...`
- Defined: `FatFs-R0.16/source/ff.c:2606`
- Doc: } } return res; } #endif /* !FF_FS_READONLY #if !FF_FS_READONLY && FF_FS_MINIMIZE == 0 /*-------------------------------

### get_fileinfo `static void get_fileinfo (
	DIR* dp,			/* Pointer to the directory object */
	FILINFO* fno		/* Po...`
- Defined: `FatFs-R0.16/source/ff.c:2652`
- Doc: } #endif return res; } #endif /* !FF_FS_READONLY && FF_FS_MINIMIZE == 0 #if FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >= 2 /*--

### get_achar `static DWORD get_achar (	/* Get a character and advance ptr */
	const TCHAR** ptr		/* Pointer to ...`
- Defined: `FatFs-R0.16/source/ff.c:2805`
- Doc: fno->crdate = ld_16(dp->dir + DIR_CrtTime + 2);	/* Created date #endif } #endif /* FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >=

### pattern_match `static int pattern_match (	/* 0:mismatched, 1:matched */
	const TCHAR* pat,	/* Matching pattern *...`
- Defined: `FatFs-R0.16/source/ff.c:2836`

### create_name `static FRESULT create_name (	/* FR_OK: successful, FR_INVALID_NAME: could not create */
	DIR* dp,...`
- Defined: `FatFs-R0.16/source/ff.c:2891`
- Doc: } get_achar(&nam);			/* nam++ } while (skip && nchr);		/* Retry until end of name if infinite search is specified return

### follow_path `static FRESULT follow_path (	/* FR_OK(0): successful, !=0: error code */
	DIR* dp,					/* Directo...`
- Defined: `FatFs-R0.16/source/ff.c:3100`
- Doc: if (sfn[0] == DDEM) sfn[0] = RDDEM;	/* If the first character collides with DDEM, replace it with RDDEM sfn[NSFLAG] = (c

### get_ldnumber `static int get_ldnumber (	/* Returns logical drive number (-1:invalid drive number or null pointe...`
- Defined: `FatFs-R0.16/source/ff.c:3219`
- Doc: dp->obj.sclust = ld_clust(fs, fs->win + dp->dptr % SS(fs));	/* Open next directory } } } return res; } /*---------------

### crc32 `static DWORD crc32 (	/* Returns next CRC value */
	DWORD crc,			/* Current CRC value */
	BYTE d		...`
- Defined: `FatFs-R0.16/source/ff.c:3296`
- Doc: return 0;				/* Default drive is 0 #endif } /*----------------------------------------------------------------------- /*

### test_gpt_header `static int test_gpt_header (	/* 0:Invalid, 1:Valid */
	const BYTE* gpth			/* Pointer to the GPT h...`
- Defined: `FatFs-R0.16/source/ff.c:3314`
- Doc: ) { BYTE b; for (b = 1; b; b <<= 1) { crc ^= (d & b) ? 1 : 0; crc = (crc & 1) ? crc >> 1 ^ 0xEDB88320 : crc >> 1; } retu

### make_rand `static DWORD make_rand (	/* Returns a seed value for next */
	DWORD seed,				/* Seed value */
	BY...`
- Defined: `FatFs-R0.16/source/ff.c:3339`
- Doc: if (hlen < 92 || hlen > FF_MIN_SS) return 0; for (i = 0, bcc = 0xFFFFFFFF; i < hlen; i++) {			/* Check header BCC bcc = 

### check_fs `static UINT check_fs (	/* 0:FAT/FAT32 VBR, 1:exFAT VBR, 2:Not FAT and valid BS, 3:Not FAT and inv...`
- Defined: `FatFs-R0.16/source/ff.c:3366`
- Doc: } while (--n); return seed; } #endif #endif /*----------------------------------------------------------------------- /*

### find_volume `static UINT find_volume (	/* Returns BS status found in the hosting drive */
	FATFS* fs,		/* File...`
- Defined: `FatFs-R0.16/source/ff.c:3406`
- Doc: && ld_16(fs->win + BPB_RsvdSecCnt) != 0		/* Properness of number of reserved sectors (MNBZ) && (UINT)fs->win[BPB_NumFATs

### mount_volume `static FRESULT mount_volume (	/* FR_OK(0): successful, !=0: an error occurred */
	const TCHAR** p...`
- Defined: `FatFs-R0.16/source/ff.c:3460`
- Doc: } i = part ? part - 1 : 0;		/* Table index to find first do {							/* Find an FAT volume fmt = mbr_pt[i] ? check_fs(fs,

### validate `static FRESULT validate (	/* Returns FR_OK or FR_INVALID_OBJECT */
	FFOBJID* obj,			/* Pointer to...`
- Defined: `FatFs-R0.16/source/ff.c:3694`
- Doc: #if FF_FS_LOCK				/* Clear file lock semaphores clear_share(fs); #endif return FR_OK; } /*------------------------------

### f_open `FRESULT f_open (
	FIL* fp,			/* Pointer to the blank file object */
	const TCHAR* path,	/* Pointe...`
- Defined: `FatFs-R0.16/source/ff.c:3798`
- Doc: } if (opt == 0) return FR_OK;	/* Do not mount now, it will be mounted in subsequent file functions res = mount_volume(&p

### f_read `FRESULT f_read (
	FIL* fp, 	/* Open file to be read */
	void* buff,	/* Data buffer to store the r...`
- Defined: `FatFs-R0.16/source/ff.c:3995`
- Doc: FREE_NAMEBUFF(); } if (res != FR_OK) fp->obj.fs = 0;	/* Invalidate file object on error LEAVE_FF(fs, res); } /*---------

### f_write `FRESULT f_write (
	FIL* fp,			/* Open file to be written */
	const void* buff,	/* Data to be writ...`
- Defined: `FatFs-R0.16/source/ff.c:4096`
- Doc: memcpy(rbuff, fp->buf + fp->fptr % SS(fs), rcnt);	/* Extract partial sector #endif } LEAVE_FF(fs, FR_OK); } #if !FF_FS_R

### f_sync `FRESULT f_sync (
	FIL* fp		/* Open file to be synced */
)`
- Defined: `FatFs-R0.16/source/ff.c:4217`
- Doc: #endif } fp->flag |= FA_MODIFIED;				/* Set file change flag LEAVE_FF(fs, FR_OK); } /*----------------------------------

### f_close `FRESULT f_close (
	FIL* fp		/* Open file to be closed */
)`
- Defined: `FatFs-R0.16/source/ff.c:4298`
- Doc: } } LEAVE_FF(fs, res); } #endif /* !FF_FS_READONLY /*-------------------------------------------------------------------

### f_chdrive `FRESULT f_chdrive (
	const TCHAR* path		/* Drive number to set */
)`
- Defined: `FatFs-R0.16/source/ff.c:4334`
- Doc: unlock_volume(fs, FR_OK);		/* Unlock volume #endif } } return res; } #if FF_FS_RPATH >= 1 /*----------------------------

### f_chdir `FRESULT f_chdir (
	const TCHAR* path	/* Pointer to the directory path */
)`
- Defined: `FatFs-R0.16/source/ff.c:4356`
- Doc: /* Get logical drive number vol = get_ldnumber(&path); if (vol < 0) return FR_INVALID_DRIVE; CurrVol = (BYTE)vol;	/* Set

### f_getcwd `FRESULT f_getcwd (
	TCHAR* buff,	/* Pointer to the buffer to store the current direcotry path */
...`
- Defined: `FatFs-R0.16/source/ff.c:4418`
- Doc: } #endif } LEAVE_FF(fs, res); } #if FF_FS_RPATH >= 2 /*-----------------------------------------------------------------

### f_lseek `FRESULT f_lseek (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t ofs		/* File pointer from ...`
- Defined: `FatFs-R0.16/source/ff.c:4554`
- Doc: } LEAVE_FF(fs, res); } #endif /* FF_FS_RPATH >= 2 #endif /* FF_FS_RPATH >= 1 #if FF_FS_MINIMIZE <= 2 /*-----------------

### f_opendir `FRESULT f_opendir (
	DIR* dp,			/* Pointer to directory object to create */
	const TCHAR* path	/*...`
- Defined: `FatFs-R0.16/source/ff.c:4718`
- Doc: #endif fp->sect = nsect; } } LEAVE_FF(fs, res); } #if FF_FS_MINIMIZE <= 1 /*--------------------------------------------

### f_closedir `FRESULT f_closedir (
	DIR *dp		/* Pointer to the directory object to be closed */
)`
- Defined: `FatFs-R0.16/source/ff.c:4780`
- Doc: FREE_NAMEBUFF(); if (res == FR_NO_FILE) res = FR_NO_PATH; } if (res != FR_OK) dp->obj.fs = 0;		/* Invalidate the directo

### f_readdir `FRESULT f_readdir (
	DIR* dp,			/* Pointer to the open directory object */
	FILINFO* fno		/* Poin...`
- Defined: `FatFs-R0.16/source/ff.c:4810`
- Doc: #endif #if FF_FS_REENTRANT unlock_volume(fs, FR_OK);	/* Unlock volume #endif } return res; } /*-------------------------

### f_findnext `FRESULT f_findnext (
	DIR* dp,		/* Pointer to the open directory object */
	FILINFO* fno	/* Point...`
- Defined: `FatFs-R0.16/source/ff.c:4849`
- Doc: FREE_NAMEBUFF(); } } if (fno && res != FR_OK) fno->fname[0] = 0;	/* Clear the file information if any error occured LEAV

### f_findfirst `FRESULT f_findfirst (
	DIR* dp,				/* Pointer to the blank directory object */
	FILINFO* fno,			/...`
- Defined: `FatFs-R0.16/source/ff.c:4874`
- Doc: if (res != FR_OK || !fno || !fno->fname[0]) break;	/* Terminate if any error or end of directory if (pattern_match(dp->p

### f_stat `FRESULT f_stat (
	const TCHAR* path,	/* Pointer to the file path */
	FILINFO* fno		/* Pointer to ...`
- Defined: `FatFs-R0.16/source/ff.c:4901`
- Doc: if (res == FR_OK) { res = f_findnext(dp, fno);	/* Find the first item } return res; } #endif	/* FF_USE_FIND #if FF_FS_MI

### f_getfree `FRESULT f_getfree (
	const TCHAR* path,	/* Logical drive number */
	DWORD* nclst,		/* Pointer to ...`
- Defined: `FatFs-R0.16/source/ff.c:4938`
- Doc: } FREE_NAMEBUFF(); } if (fno && res != FR_OK) fno->fname[0] = 0;	/* Invalidate the file information if an error occured 

### f_truncate `FRESULT f_truncate (
	FIL* fp		/* Pointer to the file object */
)`
- Defined: `FatFs-R0.16/source/ff.c:5035`
- Doc: fs->fsi_flag |= 1;		/* FAT32/exfAT : Allocation information is to be updated } } } LEAVE_FF(fs, res); } /*--------------

### f_unlink `FRESULT f_unlink (
	const TCHAR* path		/* Pointer to the file or directory path */
)`
- Defined: `FatFs-R0.16/source/ff.c:5086`
- Doc: } #endif if (res != FR_OK) ABORT(fs, res); } LEAVE_FF(fs, res); } /*----------------------------------------------------

### f_mkdir `FRESULT f_mkdir (
	const TCHAR* path		/* Pointer to the directory path */
)`
- Defined: `FatFs-R0.16/source/ff.c:5175`
- Doc: if (res == FR_OK) res = sync_fs(fs); } FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } /*---------------------------------------

### f_rename `FRESULT f_rename (
	const TCHAR* path_old,	/* Pointer to the object name to be renamed */
	const ...`
- Defined: `FatFs-R0.16/source/ff.c:5260`
- Doc: } } FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } /*----------------------------------------------------------------------- /*

### f_chmod `FRESULT f_chmod (
	const TCHAR* path,	/* Pointer to the file path */
	BYTE attr,			/* Attribute b...`
- Defined: `FatFs-R0.16/source/ff.c:5384`
- Doc: LEAVE_FF(fs, res); } #endif /* !FF_FS_READONLY #endif /* FF_FS_MINIMIZE == 0 #endif /* FF_FS_MINIMIZE <= 1 #endif /* FF_

### f_utime `FRESULT f_utime (
	const TCHAR* path,	/* Pointer to the file/directory name */
	const FILINFO* fn...`
- Defined: `FatFs-R0.16/source/ff.c:5433`
- Doc: } } FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } /*----------------------------------------------------------------------- /*

### f_getlabel `FRESULT f_getlabel (
	const TCHAR* path,	/* Logical drive number */
	TCHAR* label,		/* Buffer to ...`
- Defined: `FatFs-R0.16/source/ff.c:5501`
- Doc: FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } #endif	/* FF_USE_CHMOD && !FF_FS_READONLY #if FF_USE_LABEL /*-------------------

### f_setlabel `FRESULT f_setlabel (
	const TCHAR* label	/* Volume label to set with heading logical drive number...`
- Defined: `FatFs-R0.16/source/ff.c:5602`
- Doc: } *vsn = di ? ld_32(fs->win + di) : 0;	/* Get VSN in the VBR } } LEAVE_FF(fs, res); } #if !FF_FS_READONLY /*------------

### f_expand `FRESULT f_expand (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t fsz,	/* File size to be e...`
- Defined: `FatFs-R0.16/source/ff.c:5725`
- Doc: } LEAVE_FF(fs, res); } #endif /* !FF_FS_READONLY #endif /* FF_USE_LABEL #if FF_USE_EXPAND && !FF_FS_READONLY /*---------

### f_forward `FRESULT f_forward (
	FIL* fp, 						/* Pointer to the file object */
	UINT (*func)(const BYTE*,UI...`
- Defined: `FatFs-R0.16/source/ff.c:5821`
- Doc: } } LEAVE_FF(fs, res); } #endif /* FF_USE_EXPAND && !FF_FS_READONLY #if FF_USE_FORWARD /*-------------------------------

### create_partition `static FRESULT create_partition (
	BYTE drv,			/* Physical drive number */
	const LBA_t plst[],	/...`
- Defined: `FatFs-R0.16/source/ff.c:5899`
- Doc: #if !FF_FS_READONLY && FF_USE_MKFS /*----------------------------------------------------------------------- /* API: Cre

### f_mkfs `FRESULT f_mkfs (
	const TCHAR* path,		/* Logical drive number */
	const MKFS_PARM* opt,	/* Format...`
- Defined: `FatFs-R0.16/source/ff.c:6040`

### f_fdisk `FRESULT f_fdisk (
	BYTE pdrv,			/* Physical drive number */
	const LBA_t ptbl[],	/* Pointer to th...`
- Defined: `FatFs-R0.16/source/ff.c:6547`
- Doc: } if (disk_ioctl(pdrv, CTRL_SYNC, 0) != RES_OK) LEAVE_MKFS(FR_DISK_ERR); LEAVE_MKFS(FR_OK); } #if FF_MULTI_PARTITION /*-

### f_gets `TCHAR* f_gets (
	TCHAR* buff,	/* Pointer to the buffer to store read string */
	int len,		/* Size...`
- Defined: `FatFs-R0.16/source/ff.c:6587`
- Doc: #endif /* FF_MULTI_PARTITION #endif /* !FF_FS_READONLY && FF_USE_MKFS #if FF_USE_STRFUNC #if FF_USE_LFN && FF_LFN_UNICOD

### putc_bfd `static void putc_bfd (putbuff* pb, TCHAR c)`
- Defined: `FatFs-R0.16/source/ff.c:6739`
- Doc: typedef struct { FIL *fp;		/* Pointer to the writing file int idx, nchr;	/* Write index of buf[] (-1:error), number of w

### putc_flush `static int putc_flush (putbuff* pb)`
- Defined: `FatFs-R0.16/source/ff.c:6870`
- Doc: #else							/* ANSI/OEM input (without re-encoding) pb->buf[i++] = (BYTE)c; #endif if (i >= (int)(sizeof pb->buf) - 4) {

### putc_init `static void putc_init (putbuff* pb, FIL* fp)`
- Defined: `FatFs-R0.16/source/ff.c:6885`
- Doc: static int putc_flush (putbuff* pb) { UINT nw; if (   pb->idx >= 0	/* Flush buffered characters to the file && f_write(p

### f_putc `int f_putc (
	TCHAR c,	/* A character to be output */
	FIL* fp		/* Pointer to the file object */
)`
- Defined: `FatFs-R0.16/source/ff.c:6891`

### f_puts `int f_puts (
	const TCHAR* str,	/* Pointer to the string to be output */
	FIL* fp				/* Pointer t...`
- Defined: `FatFs-R0.16/source/ff.c:6913`
- Doc: putbuff pb; putc_init(&pb, fp); putc_bfd(&pb, c);	/* Put the character return putc_flush(&pb); } /*---------------------

### ftoa `static void ftoa (
	char* buf,	/* Buffer to output the floating point string */
	double val,	/* V...`
- Defined: `FatFs-R0.16/source/ff.c:6978`

### f_printf `int f_printf (
	FIL* fp,			/* Pointer to the file object */
	const TCHAR* fmt,	/* Pointer to the ...`
- Defined: `FatFs-R0.16/source/ff.c:7054`
- Doc: buf++ = (char)('0' + exp / 10); buf++ = (char)('0' + exp % 10); } } } if (er) {	/* Error condition if (sign) *buf++ = si

### f_setcp `FRESULT f_setcp (
	WORD cp		/* Value to be set as active code page */
)`
- Defined: `FatFs-R0.16/source/ff.c:7225`
- Doc: va_end(arp); return putc_flush(&pb); } #endif /* !FF_FS_READONLY #endif /* FF_USE_STRFUNC #if FF_CODE_PAGE == 0 /*------

## FatFs-R0.16/source/ffsystem.c

### ff_memalloc `void* ff_memalloc (	/* Returns pointer to the allocated memory block (null if not enough core) */...`
- Defined: `FatFs-R0.16/source/ffsystem.c:15`
- Doc: /*------------------------------------------------------------------------ /* A Sample Code of User Provided OS Dependen

### ff_memfree `void ff_memfree (
	void* mblock	/* Pointer to the memory block to free (no effect if null) */
)`
- Defined: `FatFs-R0.16/source/ffsystem.c:23`

### ff_mutex_create `int ff_mutex_create (	/* Returns 1:Function succeeded or 0:Could not create the mutex */
	int vol...`
- Defined: `FatFs-R0.16/source/ffsystem.c:78`
- Doc: This function is called in f_mount function to create a new mutex or semaphore for the volume. When a 0 is returned, the

### ff_mutex_delete `void ff_mutex_delete (	/* Returns 1:Function succeeded or 0:Could not delete due to an error */
	...`
- Defined: `FatFs-R0.16/source/ffsystem.c:119`
- Doc: This function is called in f_mount function to delete a mutex or semaphore of the volume created with ff_mutex_create fu

### ff_mutex_take `int ff_mutex_take (	/* Returns 1:Succeeded or 0:Timeout */
	int vol			/* Mutex ID: Volume mutex (...`
- Defined: `FatFs-R0.16/source/ffsystem.c:151`
- Doc: This function is called on enter file functions to lock the volume. When a 0 is returned, the file function fails with F

### ff_mutex_give `void ff_mutex_give (
	int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (...`
- Defined: `FatFs-R0.16/source/ffsystem.c:184`
- Doc: This function is called on leave file functions to unlock the volume.

## FatFs-R0.16/source/ffunicode.c

### ff_uni2oem `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15222`
- Doc: if FF_CODE_PAGE != 0 && FF_CODE_PAGE < 900

### ff_oem2uni `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15243`

### ff_uni2oem `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15275`
- Doc: if FF_CODE_PAGE >= 900

### ff_oem2uni `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15309`

### ff_uni2oem `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15356`

### ff_oem2uni `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15408`

### ff_wtoupper `DWORD ff_wtoupper (	/* Returns up-converted code point */
	DWORD uni		/* Unicode code point to be...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15463`
- Doc: if (n != 0) c = p[i * 2 + 1]; } } } return c; } #endif /*---------------------------------------------------------------

## esp32-qemu-test/app/main/fatfs_vuln_test.c

### __attribute__ `__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const struct dirent *entry)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:54`

### legitimate_update_callback `static void legitimate_update_callback(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:66`

### run_lfn_copy_probe `static bool run_lfn_copy_probe(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:71`

### get_firmware_size `static long get_firmware_size(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:120`

### read_firmware_image `static bool read_firmware_image(int fd, size_t firmware_size)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:133`

### run_update_flow `static void run_update_flow(long attacker_fsize)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:151`

### app_main `void app_main(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:170`

## esp32-qemu-test/run.sh

### usage
- Defined: `esp32-qemu-test/run.sh:25`

### image_exists
- Defined: `esp32-qemu-test/run.sh:35`

### ensure_image
- Defined: `esp32-qemu-test/run.sh:39`

### do_build
- Defined: `esp32-qemu-test/run.sh:46`

### do_run
- Defined: `esp32-qemu-test/run.sh:53`

### do_shell
- Defined: `esp32-qemu-test/run.sh:63`

## esp32-qemu-test/scripts/gen_exploit_image.py

### lfn_checksum `def lfn_checksum(short_name_11)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:67`
- Doc: Calculate VFAT LFN checksum for an 8.3 short name (11 bytes).

### build_lfn_entries `def build_lfn_entries(long_name, short_name_11)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:76`
- Doc: Build VFAT LFN entries followed by the 8.3 entry for the same file.

### resolve_symbol_address `def resolve_symbol_address(elf_path, symbol_name)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:115`
- Doc: Resolve a symbol address from an ELF using nm.

### build_xtensa_uart_shellcode `def build_xtensa_uart_shellcode()`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:149`
- Doc: Assemble raw Xtensa bytes that write a marker directly to UART0 and return.

### build_payload_sector `def build_payload_sector(shellcode, callback_target_addr)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:271`
- Doc: Build sector-8 payload bytes. The file starts as a normal firmware header

### generate_bug1_espidf_image `def generate_bug1_espidf_image(shellcode, callback_target_addr)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:282`
- Doc: Generate a crafted FAT32 image for the ESP32 PoC.

### inject_into_flash `def inject_into_flash(flash_path, output_path, shellcode, callback_target_addr)`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:389`
- Doc: Read the merged ESP32 flash image, inject the exploit FatFs partition

### main `def main()`
- Defined: `esp32-qemu-test/scripts/gen_exploit_image.py:456`

## fuzzer/fat_image.go

### le16 `func le16(`
- Defined: `fuzzer/fat_image.go:19`

### le32 `func le32(`
- Defined: `fuzzer/fat_image.go:20`

### le64 `func le64(`
- Defined: `fuzzer/fat_image.go:21`

### newDisk `func newDisk(`
- Defined: `fuzzer/fat_image.go:29`
- Doc: newDisk returns a zeroed byte slice of min(totalSectors, maxDiskSectors) * 512 bytes.  Callers should still write the in

### DefaultFAT16Config `func DefaultFAT16Config(`
- Defined: `fuzzer/fat_image.go:52`
- Doc: DefaultFAT16Config returns a valid, minimal 1 MiB FAT16 configuration.

### BuildFAT16 `func BuildFAT16(`
- Defined: `fuzzer/fat_image.go:65`
- Doc: BuildFAT16 constructs a minimal FAT16 disk image from the given config.

### FAT16DataSector `func FAT16DataSector(`
- Defined: `fuzzer/fat_image.go:107`
- Doc: FAT16DataSector returns the first sector of cluster c (c >= 2).

### DefaultFAT32Config `func DefaultFAT32Config(`
- Defined: `fuzzer/fat_image.go:131`
- Doc: DefaultFAT32Config returns a valid FAT32 configuration sized to fit in the test harness RAM disk (4096 sectors = 2 MiB).

### BuildFAT32 `func BuildFAT32(`
- Defined: `fuzzer/fat_image.go:144`
- Doc: BuildFAT32 constructs a minimal FAT32 disk image.

### BuildGPTImage `func BuildGPTImage(`
- Defined: `fuzzer/fat_image.go:214`
- Doc: BuildGPTImage constructs a disk image with a GPT-protective MBR, a GPT header at sector 1 declaring nPartitions entries,

### BuildExFATImage `func BuildExFATImage(`
- Defined: `fuzzer/fat_image.go:262`
- Doc: BuildExFATImage creates a minimal exFAT VBR. When numClusters == 0, n_fatent becomes 2 in FatFs, which is the divide-by-

### MutateFAT32BPB `func MutateFAT32BPB(`
- Defined: `fuzzer/fat_image.go:303`
- Doc: MutateFAT32BPB returns a copy of a FAT32 disk image with the named BPB field set to value.

### RandomMutate `func RandomMutate(`
- Defined: `fuzzer/fat_image.go:324`
- Doc: RandomMutate applies a single random byte-flip to a copy of disk.

### BuildExFATWithLargeLabel `func BuildExFATWithLargeLabel(`
- Defined: `fuzzer/fat_image.go:354`
- Doc: volume-label directory entry has XDIR_NumLabel set to numLabel.  The exFAT spec limits XDIR_NumLabel to 11 characters.  

### sfnChecksum `func sfnChecksum(`
- Defined: `fuzzer/fat_image.go:430`
- Doc: sfnChecksum computes the LFN checksum of an 11-byte FAT SFN (matching sum_sfn() in ff.c).

### BuildFAT16WithLFNFile `func BuildFAT16WithLFNFile(`
- Defined: `fuzzer/fat_image.go:451`
- Doc: BuildFAT16WithLFNFile returns a FAT16 image identical to BuildFAT16(cfg) but with one file in the root directory whose L

## fuzzer/main.go

### main `func main(`
- Defined: `fuzzer/main.go:51`

### buildAllSeeds `func buildAllSeeds(`
- Defined: `fuzzer/main.go:76`

### BuildFAT12Minimal `func BuildFAT12Minimal(`
- Defined: `fuzzer/main.go:290`

### FuzzFAT32BPB `func FuzzFAT32BPB(`
- Defined: `fuzzer/main.go:343`
- Doc: FuzzFAT32BPB mutates individual BPB fields and checks structural consistency of the generated images.  The corpus is see

### FuzzGPTNEnt `func FuzzGPTNEnt(`
- Defined: `fuzzer/main.go:398`
- Doc: FuzzGPTNEnt mutates GPTH_PtNum to explore the loop bound behaviour.

### FuzzExFATNumLabel `func FuzzExFATNumLabel(`
- Defined: `fuzzer/main.go:449`
- Doc: FuzzExFATNumLabel mutates the XDIR_NumLabel byte in an exFAT volume label entry and checks structural invariants of the 

### FuzzFAT16LFNLength `func FuzzFAT16LFNLength(`
- Defined: `fuzzer/main.go:507`
- Doc: FuzzFAT16LFNLength mutates the length of the LFN filename.

## harness/diskio_ramdisk.c

### ramdisk_reset_stats `void ramdisk_reset_stats(void)`
- Defined: `harness/diskio_ramdisk.c:34`

### ramdisk_load `void ramdisk_load(const BYTE *image, UINT size)`
- Defined: `harness/diskio_ramdisk.c:46`
- Doc: Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.  Any sector beyond the image is left zeroed. 

### ramdisk_eject `void ramdisk_eject(void)`
- Defined: `harness/diskio_ramdisk.c:55`
- Doc: Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image data.  Any sector beyond the image is left zeroed. 

### disk_status `DSTATUS disk_status(BYTE pdrv)`
- Defined: `harness/diskio_ramdisk.c:61`
- Doc: { UINT bytes = (size < sizeof(ramdisk)) ? size : (UINT)sizeof(ramdisk); memset(ramdisk, 0, sizeof(ramdisk)); memcpy(ramd

### disk_initialize `DSTATUS disk_initialize(BYTE pdrv)`
- Defined: `harness/diskio_ramdisk.c:67`

### disk_read `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)`
- Defined: `harness/diskio_ramdisk.c:74`

### disk_write `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)`
- Defined: `harness/diskio_ramdisk.c:94`

### disk_ioctl `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)`
- Defined: `harness/diskio_ramdisk.c:113`

### get_fattime `DWORD get_fattime(void)`
- Defined: `harness/diskio_ramdisk.c:136`
- Doc: return RES_OK; case GET_SECTOR_SIZE: (WORD *)buff = RAMDISK_SECTOR_SIZE; return RES_OK; case GET_BLOCK_SIZE: (DWORD *)bu

## harness/exploit_disks.c

### exploit_disks `*   make exploit_disks            (see Makefile target)
 *
 * Expected output:
 *   Generating 14...`
- Defined: `harness/exploit_disks.c:49`

### st32le `static inline void st32le(uint8_t *p, uint32_t v)`
- Defined: `harness/exploit_disks.c:99`

### st64le `static inline void st64le(uint8_t *p, uint64_t v)`
- Defined: `harness/exploit_disks.c:102`

### save_image `static int save_image(const char *name, const uint8_t *buf, size_t sz)`
- Defined: `harness/exploit_disks.c:116`
- Doc: -------------------------------------------------------------------------- I/O helpers *--------------------------------

### load_ramdisk `static void load_ramdisk(const uint8_t *buf, size_t sz)`
- Defined: `harness/exploit_disks.c:128`

### bug1_write_vbr `static void bug1_write_vbr(uint8_t *disk)`
- Defined: `harness/exploit_disks.c:156`
- Doc: clst2sect(2) = 6 → attacker plants root-dir entry at sector 6 clst2sect(4) = 8 → attacker plants file payload at sector 

### bug1_fill_payload `static void bug1_fill_payload(uint8_t *disk,
                               const uint8_t *payloa...`
- Defined: `harness/exploit_disks.c:227`
- Doc: bug1_fill_payload  —  write exploit bytes into sector 8 (cluster 4).  The first payload_sz bytes of sector 8 are filled 

### bug1_build `static uint8_t *bug1_build(uint32_t file_size,
                            const uint8_t *payload...`
- Defined: `harness/exploit_disks.c:241`
- Doc: Allocate and build a complete CVE-2026-6682 image for a given file_size / payload. * Returns pointer to RAMDISK_SIZE_BYT

### bug1_verify `static int bug1_verify(uint8_t *disk, const char *filename)`
- Defined: `harness/exploit_disks.c:255`
- Doc: static uint8_t *bug1_build(uint32_t file_size, const uint8_t *payload, uint32_t payload_sz, uint8_t fill, const char *fn

### Payload `*   Payload (sector 8): placeholder address 0xDEADBEEFCAFEBABE
 *   Simulates: embedded OTA reade...`
- Defined: `harness/exploit_disks.c:293`

### gen_bug1_espidf `static void gen_bug1_espidf(void)`
- Defined: `harness/exploit_disks.c:317`
- Doc: -------------------------------------------------------------------------- CVE-2026-6682  image 2:  ESP-IDF stat/malloc/

### gen_bug1_stm32 `static void gen_bug1_stm32(void)`
- Defined: `harness/exploit_disks.c:338`
- Doc: -------------------------------------------------------------------------- CVE-2026-6682  image 3:  STM32 CubeMX firmwar

### gen_bug1_keystone3 `static void gen_bug1_keystone3(void)`
- Defined: `harness/exploit_disks.c:359`
- Doc: -------------------------------------------------------------------------- CVE-2026-6682  image 4:  Keystone3 hardware w

### gen_bug1_ardupilot `static void gen_bug1_ardupilot(void)`
- Defined: `harness/exploit_disks.c:382`
- Doc: -------------------------------------------------------------------------- CVE-2026-6682  image 5:  ArduPilot / Mbed OS 

### gen_bug2_exfat `static void gen_bug2_exfat(void)`
- Defined: `harness/exploit_disks.c:455`

### MicroPython `*                            MicroPython (if the port enables FF_LBA64)
 *
 * R0.16 fix:  test_gp...`
- Defined: `harness/exploit_disks.c:498`

### chain `*   An application writes 64 bytes to the END of cluster chain (fp->sect = X,
 *   FA_DIRTY set),...`
- Defined: `harness/exploit_disks.c:576`

### bug4_set_fat16_entry `static void bug4_set_fat16_entry(uint8_t *disk, uint16_t cluster, uint16_t value)`
- Defined: `harness/exploit_disks.c:637`

### gen_bug4_fragmented `static void gen_bug4_fragmented(void)`
- Defined: `harness/exploit_disks.c:647`

### Zephyr `*                     Zephyr (R0.16), ArduPilot (R0.14b),
 *                     RIOT-OS (R0.15),...`
- Defined: `harness/exploit_disks.c:836`

### bug6_verify_overflow `static int bug6_verify_overflow(uint8_t *disk, const char *imgname,
                             ...`
- Defined: `harness/exploit_disks.c:892`

### gen_bug6_stm32 `static void gen_bug6_stm32(void)`
- Defined: `harness/exploit_disks.c:932`

### gen_bug6_zephyr `static void gen_bug6_zephyr(void)`
- Defined: `harness/exploit_disks.c:947`

### layout `*
 * Directory layout (FAT16):
 *   Entries in order: LFN entries (N × 32 bytes) then 8.3 SFN ent...`
- Defined: `harness/exploit_disks.c:989`

### bug7_build `static void bug7_build(uint8_t *disk, int lfn_len, uint16_t dirent_name_size)`
- Defined: `harness/exploit_disks.c:1006`

### bug7_verify `static int bug7_verify(uint8_t *disk, const char *imgname, int expected_lfn_len)`
- Defined: `harness/exploit_disks.c:1059`

### gen_bug7_max255 `static void gen_bug7_max255(void)`
- Defined: `harness/exploit_disks.c:1095`

### gen_bug7_zephyr `static void gen_bug7_zephyr(void)`
- Defined: `harness/exploit_disks.c:1111`

### main `int main(void)`
- Defined: `harness/exploit_disks.c:1273`
- Doc: =========================================================================== main *======================================

## harness/ffunicode_stub.c

### ff_uni2oem `* ff_uni2oem() and ff_wtoupper() which normally come from ffunicode.c.
 * These stubs are suffici...`
- Defined: `harness/ffunicode_stub.c:5`

### ff_uni2oem `WCHAR ff_uni2oem(DWORD uni, WORD cp)`
- Defined: `harness/ffunicode_stub.c:17`

### ff_wtoupper `DWORD ff_wtoupper(DWORD chr)`
- Defined: `harness/ffunicode_stub.c:25`
- Doc: WCHAR ff_oem2uni(WCHAR oem, WORD cp) { (void)cp; return (oem < 0x80) ? oem : 0; } WCHAR ff_uni2oem(DWORD uni, WORD cp) {

## harness/libfuzzer_harness.c

### Usage `*
 * Usage (libFuzzer):
 *   ./fuzz_fatfs -max_len=2097152 corpus/
 *
 * Usage (AFL++):
 *   afl-...`
- Defined: `harness/libfuzzer_harness.c:9`

### main `int main(int argc, char **argv)`
- Defined: `harness/libfuzzer_harness.c:128`
- Doc: f_close(&fp); break; /* process at most one file per fuzz iteration } f_closedir(&dj); } done: f_mount(NULL, "0:", 0); r

## harness/rce_demo.c

### Build `*
 * Build (without sanitisers, without stack protector — lets the overflow
 * reach the function...`
- Defined: `harness/rce_demo.c:45`

### st32le `static inline void st32le(uint8_t *p, uint32_t v)`
- Defined: `harness/rce_demo.c:73`

### st64le `static inline void st64le(uint8_t *p, uint64_t v)`
- Defined: `harness/rce_demo.c:76`

### safe_update_complete `static void safe_update_complete(void)`
- Defined: `harness/rce_demo.c:123`

### __attribute__ `__attribute__((noinline))
static void rce_win(void)`
- Defined: `harness/rce_demo.c:131`

### vulnerable_ota_check `static void vulnerable_ota_check(void)`
- Defined: `harness/rce_demo.c:155`
- Doc: This function is the VICTIM.  It contains no deliberately insecure code except for one extremely common mistake:  f_read

### build_exploit_image `static void build_exploit_image(uint8_t *disk, size_t disk_bytes,
                               ...`
- Defined: `harness/rce_demo.c:232`
- Doc: → database = sector 6   (inside FAT area [4, ∞)) → clst2sect(2) = 6  (root dir reads from sector 6) → clst2sect(4) = 8  

### save_image `static int save_image(const char *path, const uint8_t *disk, size_t sz)`
- Defined: `harness/rce_demo.c:348`
- Doc: printf("             version    [%u..%u)  = 0x00010000\n", FW_HDR_SIZE + 4, FW_HDR_SIZE + 8); printf("             on_ap

### load_image `static int load_image(const char *path)`
- Defined: `harness/rce_demo.c:363`
- Doc: { FILE *f = fopen(path, "wb"); if (!f) { perror(path); return -1; } size_t written = fwrite(disk, 1, sz, f); fclose(f); 

### main `int main(void)`
- Defined: `harness/rce_demo.c:380`
- Doc: =========================================================================== main *======================================

## harness/test_harness.c

### buffers `*         buffers (e.g. char path[16]) and unchecked string copies
 *         (sprintf, strcat) o...`
- Defined: `harness/test_harness.c:36`

### st32le `static inline void st32le(BYTE *p, uint32_t v)`
- Defined: `harness/test_harness.c:65`

### st64le `static inline void st64le(BYTE *p, uint64_t v)`
- Defined: `harness/test_harness.c:70`

### rce_proof_of_execution `static void rce_proof_of_execution(void)`
- Defined: `harness/test_harness.c:119`

### build_fat32_bug1 `static void build_fat32_bug1(BYTE *disk, size_t disk_bytes)`
- Defined: `harness/test_harness.c:120`

### MCUs `*    common on embedded MCUs (STM32, RP2040, ESP32, …).  The resulting call
 *    invokes rce_pro...`
- Defined: `harness/test_harness.c:261`

### test_bug1_rce_exploit `static int test_bug1_rce_exploit(void)`
- Defined: `harness/test_harness.c:338`

### build_gpt_image `static void build_gpt_image(BYTE *disk, size_t disk_bytes, uint32_t n_ent)`
- Defined: `harness/test_harness.c:459`
- Doc: Minimal protective-MBR + GPT header disk image builder.  Only as much structure as find_volume needs to enter the loop: 

### releases `*
 * Historical note: older FatFs releases (before test_gpt_header was
 * introduced) had no such...`
- Defined: `harness/test_harness.c:509`

### test_bug4_stale_cache_skip `static int test_bug4_stale_cache_skip(void)`
- Defined: `harness/test_harness.c:601`
- Doc: through a range that includes X. 4. The bulk disk_read() returns stale (pre-write) data for sector X; the cache copy tha

### layout `*
 * Disk layout (FAT16, 4 sectors/cluster):
 *   Sectors  0           VBR
 *   Sectors  1-4     ...`
- Defined: `harness/test_harness.c:693`

### build_fat16_base `static void build_fat16_base(BYTE *disk, size_t disk_bytes)`
- Defined: `harness/test_harness.c:725`

### __attribute__ `__attribute__((unused))
static void fat16_set_chain(BYTE *disk, uint16_t cluster, uint16_t next)`
- Defined: `harness/test_harness.c:763`

### test_bug5_infoleak_lseek `static int test_bug5_infoleak_lseek(void)`
- Defined: `harness/test_harness.c:781`
- Doc: Write exactly one full cluster so fp->buf is never used (direct sector writes) and the cluster-2 content is fully under 

### pass `*      or pass (sizeof_label - di) instead of the hard-coded 4.
 *===============================...`
- Defined: `harness/test_harness.c:927`

### test_bug6_getlabel_exfat_overflow `static int test_bug6_getlabel_exfat_overflow(void)`
- Defined: `harness/test_harness.c:998`

### sfn_checksum_b7 `static BYTE sfn_checksum_b7(const BYTE sfn[11])`
- Defined: `harness/test_harness.c:1090`
- Doc: char fname[13];                     // SFN-sized buffer strcpy(fname, fno.fname);           // overflows if LFN > 12 cha

### build_fat16_with_lfn `static void build_fat16_with_lfn(BYTE *disk, size_t disk_bytes)`
- Defined: `harness/test_harness.c:1104`
- Doc: static BYTE sfn_checksum_b7(const BYTE sfn[11]) { BYTE sum = 0; for (int i = 0; i < 11; i++) sum = (BYTE)(((sum & 1) ? 0

### test_bug7_lfn_path_overflow `static int test_bug7_lfn_path_overflow(void)`
- Defined: `harness/test_harness.c:1156`

### main `int main(void)`
- Defined: `harness/test_harness.c:1257`
- Doc: =========================================================================== main *======================================
