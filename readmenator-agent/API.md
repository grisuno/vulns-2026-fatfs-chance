# API

## FatFs-R0.16/documents/res/app1.c

### open_append (function) `FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* p...`
- Defined: `FatFs-R0.16/documents/res/app1.c:5`
- Doc: -----------------------------------------------------------/ Open or create a file in append mode (This function was spe

### main (function) `int main (void)`
- Defined: `FatFs-R0.16/documents/res/app1.c:23`

### f_mount (function) `f_mount(&fs, "", 0);`
- Defined: `FatFs-R0.16/documents/res/app1.c:32`
- Doc: if (fr != FR_OK) f_close(fp); } return fr; } int main (void) { FRESULT fr; FATFS fs; FIL fil; /* Open or create a log fi

### f_printf (function) `f_printf(&fil, "%02u/%02u/%u, %2u:%02u\n", Mday, Mon, Year, Hour, Min);`
- Defined: `FatFs-R0.16/documents/res/app1.c:37`
- Doc: int main (void) { FRESULT fr; FATFS fs; FIL fil; /* Open or create a log file and ready to append f_mount(&fs, "", 0); f

### f_close (function) `f_close(&fil);`
- Defined: `FatFs-R0.16/documents/res/app1.c:40`
- Doc: { FRESULT fr; FATFS fs; FIL fil; /* Open or create a log file and ready to append f_mount(&fs, "", 0); fr = open_append(

## FatFs-R0.16/documents/res/app2.c

### delete_node (function) `FRESULT delete_node (
    TCHAR* path,    /* Path name buffer with the sub-directory to delete */...`
- Defined: `FatFs-R0.16/documents/res/app2.c:7`
- Doc: -----------------------------------------------------------/ Delete a sub-directory even if it contains any file -------

### f_closedir (function) `f_closedir(&dir);`
- Defined: `FatFs-R0.16/documents/res/app2.c:45`
- Doc: if (i + j >= sz_buff) { /* Buffer over flow? fr = 100; break;    /* Fails with 100 when buffer overflow } path[i + j] = 

### f_mount (function) `f_mount(&fs, _T("5:"), 0);`
- Defined: `FatFs-R0.16/documents/res/app2.c:60`

### _tcscpy (function) `_tcscpy(buff, _T("5:dir"));`
- Defined: `FatFs-R0.16/documents/res/app2.c:65`
- Doc: int main (void) /* How to use { FRESULT fr; FATFS fs; TCHAR buff[256]; FILINFO fno; f_mount(&fs, _T("5:"), 0); /* Direct

### _tprintf (function) `_tprintf(_T("Failed to delete the directory. (%u)\n"), fr);`
- Defined: `FatFs-R0.16/documents/res/app2.c:72`

## FatFs-R0.16/documents/res/app3.c

### allocate_contiguous_clusters (function) `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:error or not contig...`
- Defined: `FatFs-R0.16/documents/res/app3.c:18`

### main (function) `int main (void)`
- Defined: `FatFs-R0.16/documents/res/app3.c:76`

### clust2sect (function) `DWORD clust2sect (FATFS* fs, DWORD clst);`
- Defined: `FatFs-R0.16/documents/res/app3.c:15`
- Doc: Declarations of FatFs internal functions accessible from applications. /  This is intended to be used for disk checking/

### get_fat (function) `DWORD get_fat (FATFS* fs, DWORD clst);`
- Defined: `FatFs-R0.16/documents/res/app3.c:16`

### put_fat (function) `FRESULT put_fat (FATFS* fs, DWORD clst, DWORD val);`
- Defined: `FatFs-R0.16/documents/res/app3.c:17`

### f_mount (function) `f_mount(&fs, "", 0);`
- Defined: `FatFs-R0.16/documents/res/app3.c:88`
- Doc: #endif } int main (void) { FRESULT fr; DRESULT dr; FATFS fs; FIL fil; DWORD org; /* Open or create a file to write

### printf (function) `printf("Function failed due to any error or insufficient contiguous area.\n");`
- Defined: `FatFs-R0.16/documents/res/app3.c:96`

### f_close (function) `f_close(&fil);`
- Defined: `FatFs-R0.16/documents/res/app3.c:97`

## FatFs-R0.16/documents/res/app4.c

### pn (function) `static DWORD pn (       /* Pseudo random number generator */
    DWORD pns   /* 0:Initialize, !0:...`
- Defined: `FatFs-R0.16/documents/res/app4.c:11`
- Doc: ---------------------------------------------------------------------/ Low level disk I/O module function checker       
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### test_diskio (function) `int test_diskio (
    BYTE pdrv,      /* Physical drive number to be checked (all data on the dri...`
- Defined: `FatFs-R0.16/documents/res/app4.c:34`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### main (function) `int main (int argc, char* argv[])`
- Defined: `FatFs-R0.16/documents/res/app4.c:296`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### printf (function) `printf("test_diskio(%u, %u, 0x%08X, 0x%08X)\n", pdrv, ncyc, (UINT)buff, sz_buff);`
- Defined: `FatFs-R0.16/documents/res/app4.c:49`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### memset (function) `memset(pbuff, 0, sz_sect);`
- Defined: `FatFs-R0.16/documents/res/app4.c:137`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/documents/res/app5.c

### test_contiguous_file (function) `FRESULT test_contiguous_file (
    FIL* fp,    /* [IN]  Open file object to be checked */
    int...`
- Defined: `FatFs-R0.16/documents/res/app5.c:4`
- Doc: ---------------------------------------------------------------------/ Test if the file is contiguous                   

## FatFs-R0.16/documents/res/app6.c

### test_raw_speed (function) `int test_raw_speed (
    BYTE pdrv,      /* Physical drive number */
    DWORD lba,      /* Start...`
- Defined: `FatFs-R0.16/documents/res/app6.c:9`
- Doc: include <stdio.h> include <systimer.h> include "diskio.h" include "ff.h"
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### printf (function) `printf("\ndisk_ioctl() failed.\n");`
- Defined: `FatFs-R0.16/documents/res/app6.c:25`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/diskio.c

### disk_status (function) `DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)`
- Defined: `FatFs-R0.16/source/diskio.c:26`
- Doc: /* Example: Declarations of the platform and disk functions in the project #include "platform.h" #include "storage.h" /*
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_initialize (function) `DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)`
- Defined: `FatFs-R0.16/source/diskio.c:64`
- Doc: result = USB_disk_status(); translate the reslut code here return stat; } return STA_NOINIT; } /*-----------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_read (function) `DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		...`
- Defined: `FatFs-R0.16/source/diskio.c:102`
- Doc: result = USB_disk_initialize(); translate the reslut code here return stat; } return STA_NOINIT; } /*-------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_write (function) `DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE ...`
- Defined: `FatFs-R0.16/source/diskio.c:152`
- Doc: if FF_FS_READONLY == 0
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_ioctl (function) `DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code *...`
- Defined: `FatFs-R0.16/source/diskio.c:201`
- Doc: translate the reslut code here return res; } return RES_PARERR; } #endif /*---------------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/diskio.h

### disk_initialize (function) `DSTATUS disk_initialize (BYTE pdrv);`
- Defined: `FatFs-R0.16/source/diskio.h:27`
- Doc: typedef BYTE	DSTATUS; /* Results of Disk Functions typedef enum { RES_OK = 0,		/* 0: Successful RES_ERROR,		/* 1: R/W Er
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### disk_status (function) `DSTATUS disk_status (BYTE pdrv);`
- Defined: `FatFs-R0.16/source/diskio.h:30`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### disk_read (function) `DRESULT disk_read (BYTE pdrv, BYTE* buff, LBA_t sector, UINT count);`
- Defined: `FatFs-R0.16/source/diskio.h:31`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### disk_write (function) `DRESULT disk_write (BYTE pdrv, const BYTE* buff, LBA_t sector, UINT count);`
- Defined: `FatFs-R0.16/source/diskio.h:32`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### disk_ioctl (function) `DRESULT disk_ioctl (BYTE pdrv, BYTE cmd, void* buff);`
- Defined: `FatFs-R0.16/source/diskio.h:33`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `harness/diskio_ramdisk.c`, `harness/exploit_disks.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

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
- Defined: `FatFs-R0.16/source/ff.c:895`
- Doc: return 2; } if (wc == 0 || szb < 1) return 0;	/* Invalid character or buffer overflow? *buf++ = (TCHAR)wc;					/* Store 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### unlock_volume (function) `static void unlock_volume (
	FATFS* fs,		/* Filesystem object */
	FRESULT res		/* Result code to ...`
- Defined: `FatFs-R0.16/source/ff.c:920`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### chk_share (function) `static FRESULT chk_share (	/* Check if the file can be accessed */
	DIR* dp,		/* Directory object...`
- Defined: `FatFs-R0.16/source/ff.c:946`
- Doc: } #endif ff_mutex_give(fs->ldrv);	/* Unlock the volume } } #endif #if FF_FS_LOCK /*-------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### inc_share (function) `static UINT inc_share (	/* Increment object open counter and returns its index (0:Internal error)...`
- Defined: `FatFs-R0.16/source/ff.c:981`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dec_share (function) `static FRESULT dec_share (	/* Decrement object open counter */
	UINT i			/* Semaphore index (1..)...`
- Defined: `FatFs-R0.16/source/ff.c:1012`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### clear_share (function) `static void clear_share (	/* Clear all lock entries of the volume */
	FATFS* fs
)`
- Defined: `FatFs-R0.16/source/ff.c:1036`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### sync_window (function) `static FRESULT sync_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs			/* Filesystem object...`
- Defined: `FatFs-R0.16/source/ff.c:1057`
- Doc: for (i = 0; i < FF_FS_LOCK; i++) { if (Files[i].fs == fs) Files[i].fs = 0; } } #endif	/* FF_FS_LOCK /*------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### move_window (function) `static FRESULT move_window (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs,		/* Filesystem object...`
- Defined: `FatFs-R0.16/source/ff.c:1077`
- Doc: endif
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### sync_fs (function) `static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS* fs		/* Filesystem object */
)`
- Defined: `FatFs-R0.16/source/ff.c:1109`
- Doc: } fs->winsect = sect; } } return res; } #if !FF_FS_READONLY /*----------------------------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### clst2sect (function) `static LBA_t clst2sect (	/* !=0:Sector number, 0:Failed (invalid cluster#) */
	FATFS* fs,		/* Fil...`
- Defined: `FatFs-R0.16/source/ff.c:1158`
- Doc: /* Make sure that no pending write process in the lower layer if (disk_ioctl(fs->pdrv, CTRL_SYNC, 0) != RES_OK) res = FR
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### get_fat (function) `static DWORD get_fat (		/* 0xFFFFFFFF:Disk error, 1:Internal error, 2..0x7FFFFFFF:Cluster status ...`
- Defined: `FatFs-R0.16/source/ff.c:1175`
- Doc: DWORD clst		/* Cluster# to be converted ) { clst -= 2;		/* Cluster number is origin from 2 if (clst >= fs->n_fatent - 2)
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### put_fat (function) `static FRESULT put_fat (	/* FR_OK(0):succeeded, !=0:error */
	FATFS* fs,		/* Corresponding filesy...`
- Defined: `FatFs-R0.16/source/ff.c:1253`
- Doc: val = 1;	/* Internal error } } return val; } #if !FF_FS_READONLY /*-----------------------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### find_bitmap (function) `static DWORD find_bitmap (	/* 0:Not found, 2..:Cluster block found, 0xFFFFFFFF:Disk error */
	FAT...`
- Defined: `FatFs-R0.16/source/ff.c:1318`
- Doc: #endif /* !FF_FS_READONLY #if FF_FS_EXFAT && !FF_FS_READONLY /*---------------------------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### change_bitmap (function) `static FRESULT change_bitmap (
	FATFS* fs,	/* Filesystem object */
	DWORD clst,	/* Cluster number...`
- Defined: `FatFs-R0.16/source/ff.c:1358`
- Doc: } else { scl = val; ctr = 0;		/* Encountered a cluster in-use, restart to scan } if (val == clst) return 0;	/* All clust
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### fill_first_frag (function) `static FRESULT fill_first_frag (
	FFOBJID* obj	/* Pointer to the corresponding object */
)`
- Defined: `FatFs-R0.16/source/ff.c:1394`
- Doc: fs->win[i] ^= bm;	/* Flip the bit fs->wflag = 1; if (--ncl == 0) return FR_OK;	/* All bits processed? } while (bm <<= 1)
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### fill_last_frag (function) `static FRESULT fill_last_frag (
	FFOBJID* obj,	/* Pointer to the corresponding object */
	DWORD l...`
- Defined: `FatFs-R0.16/source/ff.c:1417`
- Doc: if (obj->stat == 3) {	/* Has the object been changed 'fragmented' in this session? for (cl = obj->sclust, n = obj->n_con
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### remove_chain (function) `static FRESULT remove_chain (	/* FR_OK(0):succeeded, !=0:error */
	FFOBJID* obj,		/* Correspondin...`
- Defined: `FatFs-R0.16/source/ff.c:1443`
- Doc: if (res != FR_OK) return res; obj->n_frag--; } return FR_OK; } #endif	/* FF_FS_EXFAT && !FF_FS_READONLY #if !FF_FS_READO
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### create_chain (function) `static DWORD create_chain (	/* 0:No free cluster, 1:Internal error, 0xFFFFFFFF:Disk error, >=2:Ne...`
- Defined: `FatFs-R0.16/source/ff.c:1538`
- Doc: } } } } #endif return FR_OK; } /*----------------------------------------------------------------------- /* FAT handling
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### clmt_clust (function) `static DWORD clmt_clust (	/* <2:Error, >=2:Cluster number */
	FIL* fp,		/* Pointer to the file ob...`
- Defined: `FatFs-R0.16/source/ff.c:1643`
- Doc: } return ncl;		/* Return new cluster number or error status } #endif /* !FF_FS_READONLY #if FF_USE_FASTSEEK /*----------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_clear (function) `static FRESULT dir_clear (	/* Returns FR_OK or FR_DISK_ERR */
	FATFS *fs,		/* Filesystem object *...`
- Defined: `FatFs-R0.16/source/ff.c:1675`
- Doc: if !FF_FS_READONLY
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_sdi (function) `static FRESULT dir_sdi (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,		/* Pointer to directory o...`
- Defined: `FatFs-R0.16/source/ff.c:1713`
- Doc: { ibuf = fs->win; szb = 1;	/* Use window buffer (many single-sector writes may take a time) for (n = 0; n < fs->csize &&
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_next (function) `static FRESULT dir_next (	/* FR_OK(0):succeeded, FR_NO_FILE:End of table, FR_DENIED:Could not str...`
- Defined: `FatFs-R0.16/source/ff.c:1761`
- Doc: dp->clust = clst;					/* Current cluster# if (dp->sect == 0) return FR_INT_ERR; dp->sect += ofs / SS(fs);			/* Sector# o
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_alloc (function) `static FRESULT dir_alloc (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp,				/* Pointer to the dir...`
- Defined: `FatFs-R0.16/source/ff.c:1822`
- Doc: } dp->dptr = ofs;						/* Current entry dp->dir = fs->win + ofs % SS(fs);	/* Pointer to the entry in the win[] return FR
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### ld_clust (function) `static DWORD ld_clust (	/* Returns the top cluster value of the SFN entry */
	FATFS* fs,			/* Poi...`
- Defined: `FatFs-R0.16/source/ff.c:1864`
- Doc: } if (res == FR_NO_FILE) res = FR_DENIED;	/* No directory entry to allocate return res; } #endif	/* !FF_FS_READONLY /*--
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### st_clust (function) `static void st_clust (
	FATFS* fs,	/* Pointer to the fs object */
	BYTE* dir,	/* Pointer to the k...`
- Defined: `FatFs-R0.16/source/ff.c:1882`
- Doc: if !FF_FS_READONLY
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### cmp_lfn (function) `static int cmp_lfn (		/* 1:matched, 0:not matched */
	const WCHAR* lfnbuf,	/* Pointer to the LFN ...`
- Defined: `FatFs-R0.16/source/ff.c:1901`
- Doc: { st_16(dir + DIR_FstClusLO, (WORD)cl); if (fs->fs_type == FS_FAT32) { st_16(dir + DIR_FstClusHI, (WORD)(cl >> 16)); } }
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### pick_lfn (function) `static int pick_lfn (	/* 1:succeeded, 0:buffer overflow or invalid LFN entry */
	WCHAR* lfnbuf,		...`
- Defined: `FatFs-R0.16/source/ff.c:1937`
- Doc: if (chr != 0xFFFF) return 0;	/* Check filler } } if ((dir[LDIR_Ord] & LLEF) && pchr && lfnbuf[ni]) return 0;	/* Last nam
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### put_lfn (function) `static void put_lfn (
	const WCHAR* lfn,	/* Pointer to the LFN */
	BYTE* dir,			/* Pointer to the...`
- Defined: `FatFs-R0.16/source/ff.c:1975`
- Doc: if (dir[LDIR_Ord] & LLEF && pchr != 0) {	/* Put terminator if it is the last LFN part and not terminated if (ni >= FF_MA
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### gen_numname (function) `static void gen_numname (
	BYTE* dst,			/* Pointer to the buffer to store numbered SFN */
	const ...`
- Defined: `FatFs-R0.16/source/ff.c:2012`
- Doc: } while (++di < 13); if (chr == 0xFFFF || !lfn[ni]) ord |= LLEF;	/* Last LFN part is the start of an enrty set dir[LDIR_
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### sum_sfn (function) `static BYTE sum_sfn (
	const BYTE* dir		/* Pointer to the SFN entry */
)`
- Defined: `FatFs-R0.16/source/ff.c:2069`
- Doc: } } do {	/* Append the suffix dst[j++] = (i < 8) ? ns[i++] : ' '; } while (j < 8); } #endif	/* FF_USE_LFN && !FF_FS_READ
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### xdir_sum (function) `static WORD xdir_sum (	/* Get checksum of the directoly entry block */
	const BYTE* dir		/* Direc...`
- Defined: `FatFs-R0.16/source/ff.c:2091`
- Doc: do { sum = (sum >> 1) + (sum << 7) + *dir++; } while (--n); return sum; } #endif	/* FF_USE_LFN #if FF_FS_EXFAT /*-------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### xname_sum (function) `static WORD xname_sum (	/* Get check sum (to be used as hash) of the file name */
	const WCHAR* n...`
- Defined: `FatFs-R0.16/source/ff.c:2110`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### xsum32 (function) `static DWORD xsum32 (	/* Returns 32-bit checksum */
	BYTE  dat,			/* Byte to be calculated (byte-...`
- Defined: `FatFs-R0.16/source/ff.c:2131`
- Doc: if !FF_FS_READONLY && FF_USE_MKFS
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### load_xdir (function) `static FRESULT load_xdir (	/* FR_INT_ERR: invalid entry block */
	DIR* dp					/* Reading director...`
- Defined: `FatFs-R0.16/source/ff.c:2146`
- Doc: BYTE  dat,			/* Byte to be calculated (byte-by-byte processing) DWORD sum			/* Previous sum value ) { sum = ((sum & 1) ?
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### init_alloc_info (function) `static void init_alloc_info (
	FFOBJID* dobj,	/* Object allocation information to be initialized ...`
- Defined: `FatFs-R0.16/source/ff.c:2198`
- Doc: } while ((i += SZDIRE) < sz_ent); /* Sanity check (do it for only accessible object) if (i <= MAXDIRB(FF_MAX_LFN)) { if 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### load_obj_xdir (function) `static FRESULT load_obj_xdir (
	DIR* dp,			/* Blank directory object to be used to access contain...`
- Defined: `FatFs-R0.16/source/ff.c:2224`
- Doc: dobj->c_ofs = sdir->blk_ofs; } dobj->sclust = ld_32(fs->dirbuf + XDIR_FstClus);	/* Start cluster dobj->objsize = ld_64(f
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### store_xdir (function) `static FRESULT store_xdir (
	DIR* dp				/* Pointer to the directory object */
)`
- Defined: `FatFs-R0.16/source/ff.c:2253`
- Doc: res = dir_sdi(dp, dp->blk_ofs);	/* Goto object's entry block if (res == FR_OK) { res = load_xdir(dp);		/* Load the objec
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### create_xdir (function) `static void create_xdir (
	BYTE* dirb,			/* Pointer to the directory entry block buffer */
	const...`
- Defined: `FatFs-R0.16/source/ff.c:2287`
- Doc: dp->obj.fs->wflag = 1; if (--nent == 0) break;	/* All done? dirb += SZDIRE; res = dir_next(dp, 0);	/* Next entry } retur
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_read (function) `static FRESULT dir_read (
	DIR* dp,		/* Pointer to the directory object */
	int vol			/* Filtered...`
- Defined: `FatFs-R0.16/source/ff.c:2333`
- Doc: define DIR_READ_FILE(dp) dir_read(dp, 0) define DIR_READ_LABEL(dp) dir_read(dp, 1)
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_find (function) `static FRESULT dir_find (	/* FR_OK(0):succeeded, !=0:error */
	DIR* dp					/* Pointer to the dire...`
- Defined: `FatFs-R0.16/source/ff.c:2411`
- Doc: if (res != FR_OK) break; } if (res != FR_OK) dp->sect = 0;		/* Terminate the read operation on error or EOT return res; 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_register (function) `static FRESULT dir_register (	/* FR_OK:succeeded, FR_DENIED:no free entry or too many SFN collisi...`
- Defined: `FatFs-R0.16/source/ff.c:2493`
- Doc: #endif res = dir_next(dp, 0);	/* Next entry } while (res == FR_OK); return res; } #if !FF_FS_READONLY /*----------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### dir_remove (function) `static FRESULT dir_remove (	/* FR_OK:Succeeded, FR_DISK_ERR:A disk error */
	DIR* dp					/* Direc...`
- Defined: `FatFs-R0.16/source/ff.c:2606`
- Doc: } } return res; } #endif /* !FF_FS_READONLY #if !FF_FS_READONLY && FF_FS_MINIMIZE == 0 /*-------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### get_fileinfo (function) `static void get_fileinfo (
	DIR* dp,			/* Pointer to the directory object */
	FILINFO* fno		/* Po...`
- Defined: `FatFs-R0.16/source/ff.c:2652`
- Doc: } #endif return res; } #endif /* !FF_FS_READONLY && FF_FS_MINIMIZE == 0 #if FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >= 2 /*--
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### get_achar (function) `static DWORD get_achar (	/* Get a character and advance ptr */
	const TCHAR** ptr		/* Pointer to ...`
- Defined: `FatFs-R0.16/source/ff.c:2805`
- Doc: fno->crdate = ld_16(dp->dir + DIR_CrtTime + 2);	/* Created date #endif } #endif /* FF_FS_MINIMIZE <= 1 || FF_FS_RPATH >=
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### pattern_match (function) `static int pattern_match (	/* 0:mismatched, 1:matched */
	const TCHAR* pat,	/* Matching pattern *...`
- Defined: `FatFs-R0.16/source/ff.c:2836`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### create_name (function) `static FRESULT create_name (	/* FR_OK: successful, FR_INVALID_NAME: could not create */
	DIR* dp,...`
- Defined: `FatFs-R0.16/source/ff.c:2891`
- Doc: } get_achar(&nam);			/* nam++ } while (skip && nchr);		/* Retry until end of name if infinite search is specified return
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### follow_path (function) `static FRESULT follow_path (	/* FR_OK(0): successful, !=0: error code */
	DIR* dp,					/* Directo...`
- Defined: `FatFs-R0.16/source/ff.c:3100`
- Doc: if (sfn[0] == DDEM) sfn[0] = RDDEM;	/* If the first character collides with DDEM, replace it with RDDEM sfn[NSFLAG] = (c
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### get_ldnumber (function) `static int get_ldnumber (	/* Returns logical drive number (-1:invalid drive number or null pointe...`
- Defined: `FatFs-R0.16/source/ff.c:3219`
- Doc: dp->obj.sclust = ld_clust(fs, fs->win + dp->dptr % SS(fs));	/* Open next directory } } } return res; } /*---------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### crc32 (function) `static DWORD crc32 (	/* Returns next CRC value */
	DWORD crc,			/* Current CRC value */
	BYTE d		...`
- Defined: `FatFs-R0.16/source/ff.c:3296`
- Doc: return 0;				/* Default drive is 0 #endif } /*----------------------------------------------------------------------- /*
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### test_gpt_header (function) `static int test_gpt_header (	/* 0:Invalid, 1:Valid */
	const BYTE* gpth			/* Pointer to the GPT h...`
- Defined: `FatFs-R0.16/source/ff.c:3314`
- Doc: ) { BYTE b; for (b = 1; b; b <<= 1) { crc ^= (d & b) ? 1 : 0; crc = (crc & 1) ? crc >> 1 ^ 0xEDB88320 : crc >> 1; } retu
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### make_rand (function) `static DWORD make_rand (	/* Returns a seed value for next */
	DWORD seed,				/* Seed value */
	BY...`
- Defined: `FatFs-R0.16/source/ff.c:3339`
- Doc: if (hlen < 92 || hlen > FF_MIN_SS) return 0; for (i = 0, bcc = 0xFFFFFFFF; i < hlen; i++) {			/* Check header BCC bcc = 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### check_fs (function) `static UINT check_fs (	/* 0:FAT/FAT32 VBR, 1:exFAT VBR, 2:Not FAT and valid BS, 3:Not FAT and inv...`
- Defined: `FatFs-R0.16/source/ff.c:3366`
- Doc: } while (--n); return seed; } #endif #endif /*----------------------------------------------------------------------- /*
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### find_volume (function) `static UINT find_volume (	/* Returns BS status found in the hosting drive */
	FATFS* fs,		/* File...`
- Defined: `FatFs-R0.16/source/ff.c:3406`
- Doc: && ld_16(fs->win + BPB_RsvdSecCnt) != 0		/* Properness of number of reserved sectors (MNBZ) && (UINT)fs->win[BPB_NumFATs
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### mount_volume (function) `static FRESULT mount_volume (	/* FR_OK(0): successful, !=0: an error occurred */
	const TCHAR** p...`
- Defined: `FatFs-R0.16/source/ff.c:3460`
- Doc: } i = part ? part - 1 : 0;		/* Table index to find first do {							/* Find an FAT volume fmt = mbr_pt[i] ? check_fs(fs,
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### validate (function) `static FRESULT validate (	/* Returns FR_OK or FR_INVALID_OBJECT */
	FFOBJID* obj,			/* Pointer to...`
- Defined: `FatFs-R0.16/source/ff.c:3694`
- Doc: #if FF_FS_LOCK				/* Clear file lock semaphores clear_share(fs); #endif return FR_OK; } /*------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_open (function) `FRESULT f_open (
	FIL* fp,			/* Pointer to the blank file object */
	const TCHAR* path,	/* Pointe...`
- Defined: `FatFs-R0.16/source/ff.c:3798`
- Doc: } if (opt == 0) return FR_OK;	/* Do not mount now, it will be mounted in subsequent file functions res = mount_volume(&p
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_read (function) `FRESULT f_read (
	FIL* fp, 	/* Open file to be read */
	void* buff,	/* Data buffer to store the r...`
- Defined: `FatFs-R0.16/source/ff.c:3995`
- Doc: FREE_NAMEBUFF(); } if (res != FR_OK) fp->obj.fs = 0;	/* Invalidate file object on error LEAVE_FF(fs, res); } /*---------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_write (function) `FRESULT f_write (
	FIL* fp,			/* Open file to be written */
	const void* buff,	/* Data to be writ...`
- Defined: `FatFs-R0.16/source/ff.c:4096`
- Doc: memcpy(rbuff, fp->buf + fp->fptr % SS(fs), rcnt);	/* Extract partial sector #endif } LEAVE_FF(fs, FR_OK); } #if !FF_FS_R
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_sync (function) `FRESULT f_sync (
	FIL* fp		/* Open file to be synced */
)`
- Defined: `FatFs-R0.16/source/ff.c:4217`
- Doc: #endif } fp->flag |= FA_MODIFIED;				/* Set file change flag LEAVE_FF(fs, FR_OK); } /*----------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_close (function) `FRESULT f_close (
	FIL* fp		/* Open file to be closed */
)`
- Defined: `FatFs-R0.16/source/ff.c:4298`
- Doc: } } LEAVE_FF(fs, res); } #endif /* !FF_FS_READONLY /*-------------------------------------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_chdrive (function) `FRESULT f_chdrive (
	const TCHAR* path		/* Drive number to set */
)`
- Defined: `FatFs-R0.16/source/ff.c:4334`
- Doc: unlock_volume(fs, FR_OK);		/* Unlock volume #endif } } return res; } #if FF_FS_RPATH >= 1 /*----------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_chdir (function) `FRESULT f_chdir (
	const TCHAR* path	/* Pointer to the directory path */
)`
- Defined: `FatFs-R0.16/source/ff.c:4356`
- Doc: /* Get logical drive number vol = get_ldnumber(&path); if (vol < 0) return FR_INVALID_DRIVE; CurrVol = (BYTE)vol;	/* Set
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_getcwd (function) `FRESULT f_getcwd (
	TCHAR* buff,	/* Pointer to the buffer to store the current direcotry path */
...`
- Defined: `FatFs-R0.16/source/ff.c:4418`
- Doc: } #endif } LEAVE_FF(fs, res); } #if FF_FS_RPATH >= 2 /*-----------------------------------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_lseek (function) `FRESULT f_lseek (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t ofs		/* File pointer from ...`
- Defined: `FatFs-R0.16/source/ff.c:4554`
- Doc: } LEAVE_FF(fs, res); } #endif /* FF_FS_RPATH >= 2 #endif /* FF_FS_RPATH >= 1 #if FF_FS_MINIMIZE <= 2 /*-----------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_opendir (function) `FRESULT f_opendir (
	DIR* dp,			/* Pointer to directory object to create */
	const TCHAR* path	/*...`
- Defined: `FatFs-R0.16/source/ff.c:4718`
- Doc: #endif fp->sect = nsect; } } LEAVE_FF(fs, res); } #if FF_FS_MINIMIZE <= 1 /*--------------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_closedir (function) `FRESULT f_closedir (
	DIR *dp		/* Pointer to the directory object to be closed */
)`
- Defined: `FatFs-R0.16/source/ff.c:4780`
- Doc: FREE_NAMEBUFF(); if (res == FR_NO_FILE) res = FR_NO_PATH; } if (res != FR_OK) dp->obj.fs = 0;		/* Invalidate the directo
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_readdir (function) `FRESULT f_readdir (
	DIR* dp,			/* Pointer to the open directory object */
	FILINFO* fno		/* Poin...`
- Defined: `FatFs-R0.16/source/ff.c:4810`
- Doc: #endif #if FF_FS_REENTRANT unlock_volume(fs, FR_OK);	/* Unlock volume #endif } return res; } /*-------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_findnext (function) `FRESULT f_findnext (
	DIR* dp,		/* Pointer to the open directory object */
	FILINFO* fno	/* Point...`
- Defined: `FatFs-R0.16/source/ff.c:4849`
- Doc: FREE_NAMEBUFF(); } } if (fno && res != FR_OK) fno->fname[0] = 0;	/* Clear the file information if any error occured LEAV
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_findfirst (function) `FRESULT f_findfirst (
	DIR* dp,				/* Pointer to the blank directory object */
	FILINFO* fno,			/...`
- Defined: `FatFs-R0.16/source/ff.c:4874`
- Doc: if (res != FR_OK || !fno || !fno->fname[0]) break;	/* Terminate if any error or end of directory if (pattern_match(dp->p
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_stat (function) `FRESULT f_stat (
	const TCHAR* path,	/* Pointer to the file path */
	FILINFO* fno		/* Pointer to ...`
- Defined: `FatFs-R0.16/source/ff.c:4901`
- Doc: if (res == FR_OK) { res = f_findnext(dp, fno);	/* Find the first item } return res; } #endif	/* FF_USE_FIND #if FF_FS_MI
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_getfree (function) `FRESULT f_getfree (
	const TCHAR* path,	/* Logical drive number */
	DWORD* nclst,		/* Pointer to ...`
- Defined: `FatFs-R0.16/source/ff.c:4938`
- Doc: } FREE_NAMEBUFF(); } if (fno && res != FR_OK) fno->fname[0] = 0;	/* Invalidate the file information if an error occured 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_truncate (function) `FRESULT f_truncate (
	FIL* fp		/* Pointer to the file object */
)`
- Defined: `FatFs-R0.16/source/ff.c:5035`
- Doc: fs->fsi_flag |= 1;		/* FAT32/exfAT : Allocation information is to be updated } } } LEAVE_FF(fs, res); } /*--------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_unlink (function) `FRESULT f_unlink (
	const TCHAR* path		/* Pointer to the file or directory path */
)`
- Defined: `FatFs-R0.16/source/ff.c:5086`
- Doc: } #endif if (res != FR_OK) ABORT(fs, res); } LEAVE_FF(fs, res); } /*----------------------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_mkdir (function) `FRESULT f_mkdir (
	const TCHAR* path		/* Pointer to the directory path */
)`
- Defined: `FatFs-R0.16/source/ff.c:5175`
- Doc: if (res == FR_OK) res = sync_fs(fs); } FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } /*---------------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_rename (function) `FRESULT f_rename (
	const TCHAR* path_old,	/* Pointer to the object name to be renamed */
	const ...`
- Defined: `FatFs-R0.16/source/ff.c:5260`
- Doc: } } FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } /*----------------------------------------------------------------------- /*
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_chmod (function) `FRESULT f_chmod (
	const TCHAR* path,	/* Pointer to the file path */
	BYTE attr,			/* Attribute b...`
- Defined: `FatFs-R0.16/source/ff.c:5384`
- Doc: LEAVE_FF(fs, res); } #endif /* !FF_FS_READONLY #endif /* FF_FS_MINIMIZE == 0 #endif /* FF_FS_MINIMIZE <= 1 #endif /* FF_
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_utime (function) `FRESULT f_utime (
	const TCHAR* path,	/* Pointer to the file/directory name */
	const FILINFO* fn...`
- Defined: `FatFs-R0.16/source/ff.c:5433`
- Doc: } } FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } /*----------------------------------------------------------------------- /*
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_getlabel (function) `FRESULT f_getlabel (
	const TCHAR* path,	/* Logical drive number */
	TCHAR* label,		/* Buffer to ...`
- Defined: `FatFs-R0.16/source/ff.c:5501`
- Doc: FREE_NAMEBUFF(); } LEAVE_FF(fs, res); } #endif	/* FF_USE_CHMOD && !FF_FS_READONLY #if FF_USE_LABEL /*-------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_setlabel (function) `FRESULT f_setlabel (
	const TCHAR* label	/* Volume label to set with heading logical drive number...`
- Defined: `FatFs-R0.16/source/ff.c:5602`
- Doc: } *vsn = di ? ld_32(fs->win + di) : 0;	/* Get VSN in the VBR } } LEAVE_FF(fs, res); } #if !FF_FS_READONLY /*------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_expand (function) `FRESULT f_expand (
	FIL* fp,		/* Pointer to the file object */
	FSIZE_t fsz,	/* File size to be e...`
- Defined: `FatFs-R0.16/source/ff.c:5725`
- Doc: } LEAVE_FF(fs, res); } #endif /* !FF_FS_READONLY #endif /* FF_USE_LABEL #if FF_USE_EXPAND && !FF_FS_READONLY /*---------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_forward (function) `FRESULT f_forward (
	FIL* fp, 						/* Pointer to the file object */
	UINT (*func)(const BYTE*,UI...`
- Defined: `FatFs-R0.16/source/ff.c:5821`
- Doc: } } LEAVE_FF(fs, res); } #endif /* FF_USE_EXPAND && !FF_FS_READONLY #if FF_USE_FORWARD /*-------------------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### create_partition (function) `static FRESULT create_partition (
	BYTE drv,			/* Physical drive number */
	const LBA_t plst[],	/...`
- Defined: `FatFs-R0.16/source/ff.c:5899`
- Doc: #if !FF_FS_READONLY && FF_USE_MKFS /*----------------------------------------------------------------------- /* API: Cre
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_mkfs (function) `FRESULT f_mkfs (
	const TCHAR* path,		/* Logical drive number */
	const MKFS_PARM* opt,	/* Format...`
- Defined: `FatFs-R0.16/source/ff.c:6040`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_fdisk (function) `FRESULT f_fdisk (
	BYTE pdrv,			/* Physical drive number */
	const LBA_t ptbl[],	/* Pointer to th...`
- Defined: `FatFs-R0.16/source/ff.c:6547`
- Doc: } if (disk_ioctl(pdrv, CTRL_SYNC, 0) != RES_OK) LEAVE_MKFS(FR_DISK_ERR); LEAVE_MKFS(FR_OK); } #if FF_MULTI_PARTITION /*-
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_gets (function) `TCHAR* f_gets (
	TCHAR* buff,	/* Pointer to the buffer to store read string */
	int len,		/* Size...`
- Defined: `FatFs-R0.16/source/ff.c:6587`
- Doc: #endif /* FF_MULTI_PARTITION #endif /* !FF_FS_READONLY && FF_USE_MKFS #if FF_USE_STRFUNC #if FF_USE_LFN && FF_LFN_UNICOD
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### putc_bfd (function) `static void putc_bfd (putbuff* pb, TCHAR c)`
- Defined: `FatFs-R0.16/source/ff.c:6739`
- Doc: typedef struct { FIL *fp;		/* Pointer to the writing file int idx, nchr;	/* Write index of buf[] (-1:error), number of w
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### putc_flush (function) `static int putc_flush (putbuff* pb)`
- Defined: `FatFs-R0.16/source/ff.c:6870`
- Doc: #else							/* ANSI/OEM input (without re-encoding) pb->buf[i++] = (BYTE)c; #endif if (i >= (int)(sizeof pb->buf) - 4) {
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### putc_init (function) `static void putc_init (putbuff* pb, FIL* fp)`
- Defined: `FatFs-R0.16/source/ff.c:6885`
- Doc: static int putc_flush (putbuff* pb) { UINT nw; if (   pb->idx >= 0	/* Flush buffered characters to the file && f_write(p
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_putc (function) `int f_putc (
	TCHAR c,	/* A character to be output */
	FIL* fp		/* Pointer to the file object */
)`
- Defined: `FatFs-R0.16/source/ff.c:6891`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_puts (function) `int f_puts (
	const TCHAR* str,	/* Pointer to the string to be output */
	FIL* fp				/* Pointer t...`
- Defined: `FatFs-R0.16/source/ff.c:6913`
- Doc: putbuff pb; putc_init(&pb, fp); putc_bfd(&pb, c);	/* Put the character return putc_flush(&pb); } /*---------------------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### ftoa (function) `static void ftoa (
	char* buf,	/* Buffer to output the floating point string */
	double val,	/* V...`
- Defined: `FatFs-R0.16/source/ff.c:6978`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_printf (function) `int f_printf (
	FIL* fp,			/* Pointer to the file object */
	const TCHAR* fmt,	/* Pointer to the ...`
- Defined: `FatFs-R0.16/source/ff.c:7054`
- Doc: buf++ = (char)('0' + exp / 10); buf++ = (char)('0' + exp % 10); } } } if (er) {	/* Error condition if (sign) *buf++ = si
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### f_setcp (function) `FRESULT f_setcp (
	WORD cp		/* Value to be set as active code page */
)`
- Defined: `FatFs-R0.16/source/ff.c:7225`
- Doc: va_end(arp); return putc_flush(&pb); } #endif /* !FF_FS_READONLY #endif /* FF_USE_STRFUNC #if FF_CODE_PAGE == 0 /*------
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### ff_mutex_give (function) `ff_mutex_give(fs->ldrv);`
- Defined: `FatFs-R0.16/source/ff.c:912`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### memset (function) `memset(fs->win, 0, sizeof fs->win);`
- Defined: `FatFs-R0.16/source/ff.c:1123`
- Doc: static FRESULT sync_fs (	/* Returns FR_OK or FR_DISK_ERR FATFS* fs		/* Filesystem object ) { FRESULT res; res = sync_win
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### st_32 (function) `st_32(fs->win + FSI_LeadSig, 0x41615252);`
- Defined: `FatFs-R0.16/source/ff.c:1124`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_write (function) `disk_write(fs->pdrv, fs->win, fs->winsect = fs->volbase + 1, 1);`
- Defined: `FatFs-R0.16/source/ff.c:1129`
- Doc: res = sync_window(fs); if (res == FR_OK) { if (fs->fsi_flag == 1) {	/* Allocation changed? fs->fsi_flag = 0; if (fs->fs_
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### st_16 (function) `st_16(fs->win + clst * 2 % SS(fs), (WORD)val);`
- Defined: `FatFs-R0.16/source/ff.c:1284`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### disk_ioctl (function) `disk_ioctl(fs->pdrv, CTRL_TRIM, rt);`
- Defined: `FatFs-R0.16/source/ff.c:1495`
- Doc: } #if FF_FS_EXFAT || FF_USE_TRIM if (ecl + 1 == nxt) {	/* Is next cluster contiguous? ecl = nxt; } else {				/* End of c
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### ff_memfree (function) `ff_memfree(ibuf);`
- Defined: `FatFs-R0.16/source/ff.c:1696`
- Doc: BYTE *ibuf; if (sync_window(fs) != FR_OK) return FR_DISK_ERR;	/* Flush disk access window sect = clst2sect(fs, clst);		/
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### memcpy (function) `memcpy(dst, src, 11);`
- Defined: `FatFs-R0.16/source/ff.c:2022`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### st_64 (function) `st_64(fs->dirbuf + XDIR_FileSize, dp->obj.objsize);`
- Defined: `FatFs-R0.16/source/ff.c:2527`
- Doc: dp->blk_ofs = dp->dptr - SZDIRE * (n_ent - 1);	/* Set the allocated entry block offset if (dp->obj.stat & 4) {			/* Has 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### ff_mutex_delete (function) `ff_mutex_delete(vol);`
- Defined: `FatFs-R0.16/source/ff.c:3762`
- Doc: const TCHAR *rp = path; /* Get volume ID (logical drive number) vol = get_ldnumber(&rp); if (vol < 0) return FR_INVALID_
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### LEAVE_FF (function) `LEAVE_FF(fs, res);`
- Defined: `FatFs-R0.16/source/ff.c:3789`
- Doc: ff_mutex_delete(vol); return FR_INT_ERR; } SysLock = 1;		/* System mutex is ready } #endif #endif fs->fs_type = 0;		/* I
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### INIT_NAMEBUFF (function) `INIT_NAMEBUFF(fs);`
- Defined: `FatFs-R0.16/source/ff.c:3820`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### FREE_NAMEBUFF (function) `FREE_NAMEBUFF();`
- Defined: `FatFs-R0.16/source/ff.c:3980`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### ABORT (function) `ABORT(fs, FR_DISK_ERR);`
- Defined: `FatFs-R0.16/source/ff.c:4189`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### LEAVE_MKFS (function) `LEAVE_MKFS(FR_MKFS_ABORTED);`
- Defined: `FatFs-R0.16/source/ff.c:6397`
- Doc: sz_rsv += n; b_fat += n; } else {					/* FAT: Expand FAT if (n % n_fat) {	/* Adjust fractional error if needed n--; sz_r
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### va_start (function) `va_start(arp, fmt);`
- Defined: `FatFs-R0.16/source/ff.c:7079`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

### va_end (function) `va_end(arp);`
- Defined: `FatFs-R0.16/source/ff.c:7210`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/ff.h

### f_open (function) `FRESULT f_open (FIL* fp, const TCHAR* path, BYTE mode);`
- Defined: `FatFs-R0.16/source/ff.h:322`
- Doc: FR_MKFS_ABORTED,		/* (14) The f_mkfs function aborted due to some problem FR_TIMEOUT,				/* (15) Could not take control 
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_close (function) `FRESULT f_close (FIL* fp);`
- Defined: `FatFs-R0.16/source/ff.h:324`
- Doc: FR_LOCKED,				/* (16) The operation is rejected according to the file sharing policy FR_NOT_ENOUGH_CORE,		/* (17) LFN wo
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_read (function) `FRESULT f_read (FIL* fp, void* buff, UINT btr, UINT* br);`
- Defined: `FatFs-R0.16/source/ff.h:325`
- Doc: FR_NOT_ENOUGH_CORE,		/* (17) LFN working buffer could not be allocated, given buffer size is insufficient or too deep pa
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_write (function) `FRESULT f_write (FIL* fp, const void* buff, UINT btw, UINT* bw);`
- Defined: `FatFs-R0.16/source/ff.h:326`
- Doc: FR_TOO_MANY_OPEN_FILES,	/* (18) Number of open files > FF_FS_LOCK FR_INVALID_PARAMETER	/* (19) Given parameter is invali
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_lseek (function) `FRESULT f_lseek (FIL* fp, FSIZE_t ofs);`
- Defined: `FatFs-R0.16/source/ff.h:327`
- Doc: FR_INVALID_PARAMETER	/* (19) Given parameter is invalid } FRESULT; /*---------------------------------------------------
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_truncate (function) `FRESULT f_truncate (FIL* fp);`
- Defined: `FatFs-R0.16/source/ff.h:328`
- Doc: } FRESULT; /*-------------------------------------------------------------- /* FatFs Module Application Interface /*----
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_sync (function) `FRESULT f_sync (FIL* fp);`
- Defined: `FatFs-R0.16/source/ff.h:329`
- Doc: /*-------------------------------------------------------------- /* FatFs Module Application Interface /*---------------
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_opendir (function) `FRESULT f_opendir (DIR* dp, const TCHAR* path);`
- Defined: `FatFs-R0.16/source/ff.h:330`
- Doc: /*-------------------------------------------------------------- /* FatFs Module Application Interface /*---------------
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_closedir (function) `FRESULT f_closedir (DIR* dp);`
- Defined: `FatFs-R0.16/source/ff.h:331`
- Doc: /*-------------------------------------------------------------- /* FatFs Module Application Interface /*---------------
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_readdir (function) `FRESULT f_readdir (DIR* dp, FILINFO* fno);`
- Defined: `FatFs-R0.16/source/ff.h:332`
- Doc: /*-------------------------------------------------------------- /* FatFs Module Application Interface /*---------------
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_findfirst (function) `FRESULT f_findfirst (DIR* dp, FILINFO* fno, const TCHAR* path, const TCHAR* pattern);`
- Defined: `FatFs-R0.16/source/ff.h:333`
- Doc: /*-------------------------------------------------------------- /* FatFs Module Application Interface /*---------------
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_findnext (function) `FRESULT f_findnext (DIR* dp, FILINFO* fno);`
- Defined: `FatFs-R0.16/source/ff.h:334`
- Doc: /* FatFs Module Application Interface /*-------------------------------------------------------------- FRESULT f_open (F
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_mkdir (function) `FRESULT f_mkdir (const TCHAR* path);`
- Defined: `FatFs-R0.16/source/ff.h:335`
- Doc: /*-------------------------------------------------------------- FRESULT f_open (FIL* fp, const TCHAR* path, BYTE mode);
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_unlink (function) `FRESULT f_unlink (const TCHAR* path);`
- Defined: `FatFs-R0.16/source/ff.h:336`
- Doc: FRESULT f_open (FIL* fp, const TCHAR* path, BYTE mode);				/* Open or create a file FRESULT f_close (FIL* fp);										
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_rename (function) `FRESULT f_rename (const TCHAR* path_old, const TCHAR* path_new);`
- Defined: `FatFs-R0.16/source/ff.h:337`
- Doc: FRESULT f_open (FIL* fp, const TCHAR* path, BYTE mode);				/* Open or create a file FRESULT f_close (FIL* fp);										
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_stat (function) `FRESULT f_stat (const TCHAR* path, FILINFO* fno);`
- Defined: `FatFs-R0.16/source/ff.h:338`
- Doc: FRESULT f_close (FIL* fp);											/* Close an open file object FRESULT f_read (FIL* fp, void* buff, UINT btr, UINT* b
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_chmod (function) `FRESULT f_chmod (const TCHAR* path, BYTE attr, BYTE mask);`
- Defined: `FatFs-R0.16/source/ff.h:339`
- Doc: FRESULT f_read (FIL* fp, void* buff, UINT btr, UINT* br);			/* Read data from the file FRESULT f_write (FIL* fp, const v
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_utime (function) `FRESULT f_utime (const TCHAR* path, const FILINFO* fno);`
- Defined: `FatFs-R0.16/source/ff.h:340`
- Doc: FRESULT f_write (FIL* fp, const void* buff, UINT btw, UINT* bw);	/* Write data to the file FRESULT f_lseek (FIL* fp, FSI
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_chdir (function) `FRESULT f_chdir (const TCHAR* path);`
- Defined: `FatFs-R0.16/source/ff.h:341`
- Doc: FRESULT f_lseek (FIL* fp, FSIZE_t ofs);								/* Move file pointer of the file object FRESULT f_truncate (FIL* fp);				
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_chdrive (function) `FRESULT f_chdrive (const TCHAR* path);`
- Defined: `FatFs-R0.16/source/ff.h:342`
- Doc: FRESULT f_truncate (FIL* fp);										/* Truncate the file FRESULT f_sync (FIL* fp);											/* Flush cached data of 
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_getcwd (function) `FRESULT f_getcwd (TCHAR* buff, UINT len);`
- Defined: `FatFs-R0.16/source/ff.h:343`
- Doc: FRESULT f_sync (FIL* fp);											/* Flush cached data of the writing file FRESULT f_opendir (DIR* dp, const TCHAR* pa
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_getfree (function) `FRESULT f_getfree (const TCHAR* path, DWORD* nclst, FATFS** fatfs);`
- Defined: `FatFs-R0.16/source/ff.h:344`
- Doc: FRESULT f_opendir (DIR* dp, const TCHAR* path);						/* Open a directory FRESULT f_closedir (DIR* dp);										/* Close
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_getlabel (function) `FRESULT f_getlabel (const TCHAR* path, TCHAR* label, DWORD* vsn);`
- Defined: `FatFs-R0.16/source/ff.h:345`
- Doc: FRESULT f_closedir (DIR* dp);										/* Close an open directory FRESULT f_readdir (DIR* dp, FILINFO* fno);							/* Re
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_setlabel (function) `FRESULT f_setlabel (const TCHAR* label);`
- Defined: `FatFs-R0.16/source/ff.h:346`
- Doc: FRESULT f_readdir (DIR* dp, FILINFO* fno);							/* Read a directory item FRESULT f_findfirst (DIR* dp, FILINFO* fno, co
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_forward (function) `FRESULT f_forward (FIL* fp, UINT(*func)(const BYTE*,UINT), UINT btf, UINT* bf);`
- Defined: `FatFs-R0.16/source/ff.h:347`
- Doc: FRESULT f_findfirst (DIR* dp, FILINFO* fno, const TCHAR* path, const TCHAR* pattern);	/* Find first file FRESULT f_findn
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_expand (function) `FRESULT f_expand (FIL* fp, FSIZE_t fsz, BYTE opt);`
- Defined: `FatFs-R0.16/source/ff.h:348`
- Doc: FRESULT f_findnext (DIR* dp, FILINFO* fno);							/* Find next file FRESULT f_mkdir (const TCHAR* path);								/* Creat
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_mount (function) `FRESULT f_mount (FATFS* fs, const TCHAR* path, BYTE opt);`
- Defined: `FatFs-R0.16/source/ff.h:349`
- Doc: FRESULT f_mkdir (const TCHAR* path);								/* Create a sub directory FRESULT f_unlink (const TCHAR* path);								/* De
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_mkfs (function) `FRESULT f_mkfs (const TCHAR* path, const MKFS_PARM* opt, void* work, UINT len);`
- Defined: `FatFs-R0.16/source/ff.h:350`
- Doc: FRESULT f_unlink (const TCHAR* path);								/* Delete an existing file or directory FRESULT f_rename (const TCHAR* path
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_fdisk (function) `FRESULT f_fdisk (BYTE pdrv, const LBA_t ptbl[], void* work);`
- Defined: `FatFs-R0.16/source/ff.h:351`
- Doc: FRESULT f_rename (const TCHAR* path_old, const TCHAR* path_new);	/* Rename/Move a file or directory FRESULT f_stat (cons
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### f_setcp (function) `FRESULT f_setcp (WORD cp);`
- Defined: `FatFs-R0.16/source/ff.h:352`
- Doc: FRESULT f_stat (const TCHAR* path, FILINFO* fno);					/* Get file status FRESULT f_chmod (const TCHAR* path, BYTE attr, 
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

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

### get_fattime (function) `DWORD get_fattime (void);`
- Defined: `FatFs-R0.16/source/ff.h:378`
- Doc: #define f_rewind(fp) f_lseek((fp), 0) #define f_rewinddir(dp) f_readdir((dp), 0) #define f_rmdir(path) f_unlink(path) #d
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ff_oem2uni (function) `WCHAR ff_oem2uni (WCHAR oem, WORD cp);`
- Defined: `FatFs-R0.16/source/ff.h:385`
- Doc: if FF_USE_LFN >= 1
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ff_uni2oem (function) `WCHAR ff_uni2oem (DWORD uni, WORD cp);`
- Defined: `FatFs-R0.16/source/ff.h:386`
- Doc: /*-------------------------------------------------------------- /* Additional Functions /*-----------------------------
- Depends on: `FatFs-R0.16/source/ffconf.h`
- Imported by: `FatFs-R0.16/documents/res/app4.c`, `FatFs-R0.16/documents/res/app6.c`, `FatFs-R0.16/source/diskio.c`, `FatFs-R0.16/source/ff.c`, `FatFs-R0.16/source/ffsystem.c`, `FatFs-R0.16/source/ffunicode.c`, `harness/diskio_ramdisk.c`, `harness/diskio_ramdisk.h`, `harness/exploit_disks.c`, `harness/ffunicode_stub.c`, `harness/libfuzzer_harness.c`, `harness/rce_demo.c`, `harness/test_harness.c`

### ff_wtoupper (function) `DWORD ff_wtoupper (DWORD uni);`
- Defined: `FatFs-R0.16/source/ff.h:387`
- Doc: /* Additional Functions /*-------------------------------------------------------------- /* RTC function (provided by us
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
- Defined: `FatFs-R0.16/source/ffsystem.c:15`
- Doc: /*------------------------------------------------------------------------ /* A Sample Code of User Provided OS Dependen
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_memfree (function) `void ff_memfree (
	void* mblock	/* Pointer to the memory block to free (no effect if null) */
)`
- Defined: `FatFs-R0.16/source/ffsystem.c:23`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_mutex_create (function) `int ff_mutex_create (	/* Returns 1:Function succeeded or 0:Could not create the mutex */
	int vol...`
- Defined: `FatFs-R0.16/source/ffsystem.c:78`
- Doc: This function is called in f_mount function to create a new mutex or semaphore for the volume. When a 0 is returned, the
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_mutex_delete (function) `void ff_mutex_delete (	/* Returns 1:Function succeeded or 0:Could not delete due to an error */
	...`
- Defined: `FatFs-R0.16/source/ffsystem.c:119`
- Doc: This function is called in f_mount function to delete a mutex or semaphore of the volume created with ff_mutex_create fu
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_mutex_take (function) `int ff_mutex_take (	/* Returns 1:Succeeded or 0:Timeout */
	int vol			/* Mutex ID: Volume mutex (...`
- Defined: `FatFs-R0.16/source/ffsystem.c:151`
- Doc: This function is called on enter file functions to lock the volume. When a 0 is returned, the file function fails with F
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_mutex_give (function) `void ff_mutex_give (
	int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (...`
- Defined: `FatFs-R0.16/source/ffsystem.c:184`
- Doc: This function is called on leave file functions to unlock the volume.
- Depends on: `FatFs-R0.16/source/ff.h`

### malloc (function) `return malloc((size_t)msize);`
- Defined: `FatFs-R0.16/source/ffsystem.c:21`
- Depends on: `FatFs-R0.16/source/ff.h`

### free (function) `free(mblock);`
- Defined: `FatFs-R0.16/source/ffsystem.c:29`
- Depends on: `FatFs-R0.16/source/ff.h`

### osMutexDef (function) `osMutexDef(cmsis_os_mutex);`
- Defined: `FatFs-R0.16/source/ffsystem.c:104`
- Doc: Mutex[vol] = acre_mtx(&cmtx); return (int)(Mutex[vol] > 0); #elif OS_TYPE == 2	/* uC/OS-II OS_ERR err; Mutex[vol] = OSMu
- Depends on: `FatFs-R0.16/source/ff.h`

### CloseHandle (function) `CloseHandle(Mutex[vol]);`
- Defined: `FatFs-R0.16/source/ffsystem.c:125`
- Doc: This function is called in f_mount function to delete a mutex or semaphore of the volume created with ff_mutex_create fu
- Depends on: `FatFs-R0.16/source/ff.h`

### del_mtx (function) `del_mtx(Mutex[vol]);`
- Defined: `FatFs-R0.16/source/ffsystem.c:128`
- Doc: This function is called in f_mount function to delete a mutex or semaphore of the volume created with ff_mutex_create fu
- Depends on: `FatFs-R0.16/source/ff.h`

### OSMutexDel (function) `OSMutexDel(Mutex[vol], OS_DEL_ALWAYS, &err);`
- Defined: `FatFs-R0.16/source/ffsystem.c:132`
- Depends on: `FatFs-R0.16/source/ff.h`

### vSemaphoreDelete (function) `vSemaphoreDelete(Mutex[vol]);`
- Defined: `FatFs-R0.16/source/ffsystem.c:136`
- Doc: ) { #if OS_TYPE == 0	/* Win32 CloseHandle(Mutex[vol]); #elif OS_TYPE == 1	/* uITRON del_mtx(Mutex[vol]); #elif OS_TYPE =
- Depends on: `FatFs-R0.16/source/ff.h`

### osMutexDelete (function) `osMutexDelete(Mutex[vol]);`
- Defined: `FatFs-R0.16/source/ffsystem.c:139`
- Doc: CloseHandle(Mutex[vol]); #elif OS_TYPE == 1	/* uITRON del_mtx(Mutex[vol]); #elif OS_TYPE == 2	/* uC/OS-II OS_ERR err; OS
- Depends on: `FatFs-R0.16/source/ff.h`

### OSMutexPend (function) `OSMutexPend(Mutex[vol], FF_FS_TIMEOUT, &err));`
- Defined: `FatFs-R0.16/source/ffsystem.c:164`
- Depends on: `FatFs-R0.16/source/ff.h`

### ReleaseMutex (function) `ReleaseMutex(Mutex[vol]);`
- Defined: `FatFs-R0.16/source/ffsystem.c:190`
- Doc: This function is called on leave file functions to unlock the volume.  void ff_mutex_give ( int vol			/* Mutex ID: Volum
- Depends on: `FatFs-R0.16/source/ff.h`

### unl_mtx (function) `unl_mtx(Mutex[vol]);`
- Defined: `FatFs-R0.16/source/ffsystem.c:193`
- Doc: This function is called on leave file functions to unlock the volume.  void ff_mutex_give ( int vol			/* Mutex ID: Volum
- Depends on: `FatFs-R0.16/source/ff.h`

### OSMutexPost (function) `OSMutexPost(Mutex[vol]);`
- Defined: `FatFs-R0.16/source/ffsystem.c:196`
- Doc: This function is called on leave file functions to unlock the volume.  void ff_mutex_give ( int vol			/* Mutex ID: Volum
- Depends on: `FatFs-R0.16/source/ff.h`

### xSemaphoreGive (function) `xSemaphoreGive(Mutex[vol]);`
- Defined: `FatFs-R0.16/source/ffsystem.c:199`
- Doc: void ff_mutex_give ( int vol			/* Mutex ID: Volume mutex (0 to FF_VOLUMES - 1) or system mutex (FF_VOLUMES) ) { #if OS_T
- Depends on: `FatFs-R0.16/source/ff.h`

### osMutexRelease (function) `osMutexRelease(Mutex[vol]);`
- Defined: `FatFs-R0.16/source/ffsystem.c:202`
- Doc: { #if OS_TYPE == 0	/* Win32 ReleaseMutex(Mutex[vol]); #elif OS_TYPE == 1	/* uITRON unl_mtx(Mutex[vol]); #elif OS_TYPE ==
- Depends on: `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/source/ffunicode.c

### ff_uni2oem (function) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15222`
- Doc: if FF_CODE_PAGE != 0 && FF_CODE_PAGE < 900
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_oem2uni (function) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15243`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_uni2oem (function) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15275`
- Doc: if FF_CODE_PAGE >= 900
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_oem2uni (function) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15309`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_uni2oem (function) `WCHAR ff_uni2oem (	/* Returns OEM code character, zero on error */
	DWORD	uni,	/* UTF-16 encoded ...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15356`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_oem2uni (function) `WCHAR ff_oem2uni (	/* Returns Unicode character in UTF-16, zero on error */
	WCHAR	oem,	/* OEM co...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15408`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_wtoupper (function) `DWORD ff_wtoupper (	/* Returns up-converted code point */
	DWORD uni		/* Unicode code point to be...`
- Defined: `FatFs-R0.16/source/ffunicode.c:15463`
- Doc: if (n != 0) c = p[i * 2 + 1]; } } } return c; } #endif /*---------------------------------------------------------------
- Depends on: `FatFs-R0.16/source/ff.h`

## esp32-qemu-test/app/main/fatfs_vuln_test.c

### __attribute__ (function) `__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const struct dirent *entry)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:54`

### legitimate_update_callback (function) `static void legitimate_update_callback(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:66`

### run_lfn_copy_probe (function) `static bool run_lfn_copy_probe(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:71`

### get_firmware_size (function) `static long get_firmware_size(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:120`

### read_firmware_image (function) `static bool read_firmware_image(int fd, size_t firmware_size)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:133`

### run_update_flow (function) `static void run_update_flow(long attacker_fsize)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:151`

### app_main (function) `void app_main(void)`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:170`

### void (function) `void (*on_complete)(void);`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:33`

### strcpy (function) `strcpy(dst, "");`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:59`
- Doc: #define LFN_GUARD_VALUE 0xA5A5C3C3u typedef struct lfn_overflow_probe { char name[32]; volatile uint32_t guard; } lfn_ov

### strcat (function) `strcat(dst, "/");`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:60`

### ESP_LOGI (function) `ESP_LOGI(TAG, "update callback completed");`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:69`

### readdir (function) `* readdir() returns an attacker-controlled long filename, then application * code copies it into a fixed 32-byte stack/global buffer without bounds * checks, matching public ESP32 code patterns. */ DI`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:76`

### ESP_LOGE (function) `ESP_LOGE(TAG, "opendir failed: errno=%d", errno);`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:82`

### memset (function) `memset((void *)&g_lfn_probe, 0, sizeof(g_lfn_probe));`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:93`

### unsafe_copy_dirent_name (function) `unsafe_copy_dirent_name(g_lfn_probe.name, entry);`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:103`
- Doc: Pattern mirrored from public ESP32 examples: - esp-dev-kits/.../lv_port_fs.c: sprintf(fn, "/%s", entry->d_name) - esp-de

### closedir (function) `closedir(dir);`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:116`

### close (function) `close(fd);`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:161`

### vTaskDelay (function) `vTaskDelay(pdMS_TO_TICKS(100));`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:172`

### esp_vfs_fat_spiflash_unmount_ro (function) `esp_vfs_fat_spiflash_unmount_ro(MOUNT_POINT, "storage");`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:200`

### printf (function) `printf("\n");`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:202`

### fflush (function) `fflush(stdout);`
- Defined: `esp32-qemu-test/app/main/fatfs_vuln_test.c:204`

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
- Defined: `harness/diskio_ramdisk.c:34`
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
- Defined: `harness/diskio_ramdisk.c:61`
- Doc: { UINT bytes = (size < sizeof(ramdisk)) ? size : (UINT)sizeof(ramdisk); memset(ramdisk, 0, sizeof(ramdisk)); memcpy(ramd
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### disk_initialize (function) `DSTATUS disk_initialize(BYTE pdrv)`
- Defined: `harness/diskio_ramdisk.c:67`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### disk_read (function) `DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)`
- Defined: `harness/diskio_ramdisk.c:74`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### disk_write (function) `DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)`
- Defined: `harness/diskio_ramdisk.c:94`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### disk_ioctl (function) `DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)`
- Defined: `harness/diskio_ramdisk.c:113`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### get_fattime (function) `DWORD get_fattime(void)`
- Defined: `harness/diskio_ramdisk.c:136`
- Doc: return RES_OK; case GET_SECTOR_SIZE: (WORD *)buff = RAMDISK_SECTOR_SIZE; return RES_OK; case GET_BLOCK_SIZE: (DWORD *)bu
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memset (function) `memset(ramdisk, 0, sizeof(ramdisk));`
- Defined: `harness/diskio_ramdisk.c:49`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memcpy (function) `memcpy(ramdisk, image, bytes);`
- Defined: `harness/diskio_ramdisk.c:50`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/diskio_ramdisk.h

### ramdisk_reset_stats (function) `void ramdisk_reset_stats(void);`
- Defined: `harness/diskio_ramdisk.h:25`
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
- Defined: `harness/exploit_disks.c:128`
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
- Defined: `harness/exploit_disks.c:455`
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
- Defined: `harness/exploit_disks.c:637`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug4_fragmented (function) `static void gen_bug4_fragmented(void)`
- Defined: `harness/exploit_disks.c:647`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### Zephyr (function) `*                     Zephyr (R0.16), ArduPilot (R0.14b),
 *                     RIOT-OS (R0.15),...`
- Defined: `harness/exploit_disks.c:836`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug6_verify_overflow (function) `static int bug6_verify_overflow(uint8_t *disk, const char *imgname,
                             ...`
- Defined: `harness/exploit_disks.c:892`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug6_stm32 (function) `static void gen_bug6_stm32(void)`
- Defined: `harness/exploit_disks.c:932`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug6_zephyr (function) `static void gen_bug6_zephyr(void)`
- Defined: `harness/exploit_disks.c:947`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### layout (function) `*
 * Directory layout (FAT16):
 *   Entries in order: LFN entries (N × 32 bytes) then 8.3 SFN ent...`
- Defined: `harness/exploit_disks.c:989`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug7_build (function) `static void bug7_build(uint8_t *disk, int lfn_len, uint16_t dirent_name_size)`
- Defined: `harness/exploit_disks.c:1006`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug7_verify (function) `static int bug7_verify(uint8_t *disk, const char *imgname, int expected_lfn_len)`
- Defined: `harness/exploit_disks.c:1059`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug7_max255 (function) `static void gen_bug7_max255(void)`
- Defined: `harness/exploit_disks.c:1095`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug7_zephyr (function) `static void gen_bug7_zephyr(void)`
- Defined: `harness/exploit_disks.c:1111`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### main (function) `int main(void)`
- Defined: `harness/exploit_disks.c:1273`
- Doc: =========================================================================== main *======================================
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### snprintf (function) `snprintf(path, sizeof(path), IMG_DIR "/%s", name);`
- Defined: `harness/exploit_disks.c:119`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### fclose (function) `fclose(f);`
- Defined: `harness/exploit_disks.c:123`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### printf (function) `printf(" [IMG] %s (%zu bytes)\n", path, sz);`
- Defined: `harness/exploit_disks.c:125`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### ramdisk_load (function) `ramdisk_load(buf, (UINT)sz);`
- Defined: `harness/exploit_disks.c:131`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memcpy (function) `memcpy(&vbr[3], "MSDOS5.0", 8);`
- Defined: `harness/exploit_disks.c:160`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### st16le (function) `st16le(&vbr[11], 512);`
- Defined: `harness/exploit_disks.c:161`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memset (function) `memset(dir6, 0, 512);`
- Defined: `harness/exploit_disks.c:211`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug1_plant_dir_entry (function) `bug1_plant_dir_entry(disk, fname8, ext3, file_size, 4);`
- Defined: `harness/exploit_disks.c:249`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### INFO (function) `INFO("f_mount returned %d (expected FR_OK=0)", (int)res);`
- Defined: `harness/exploit_disks.c:261`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### FAIL (function) `FAIL(filename);`
- Defined: `harness/exploit_disks.c:262`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_mount (function) `f_mount(NULL, "0:", 0);`
- Defined: `harness/exploit_disks.c:263`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### PASS (function) `PASS(filename);`
- Defined: `harness/exploit_disks.c:284`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### free (function) `free(disk);`
- Defined: `harness/exploit_disks.c:306`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug2_write_vbr (function) `bug2_write_vbr(disk, 0);`
- Defined: `harness/exploit_disks.c:469`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### ramdisk_reset_stats (function) `ramdisk_reset_stats();`
- Defined: `harness/exploit_disks.c:544`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### code (function) `* * Vulnerable code (ff.c non-tiny path, f_read multi-sector branch): * disk_read(pdrv, rbuff, sect, cc);`
- Defined: `harness/exploit_disks.c:563`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug4_write_fat16_base (function) `bug4_write_fat16_base(disk);`
- Defined: `harness/exploit_disks.c:660`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### cc (function) `* if cc (sectors remaining) is also large, 0xFFFFFFFC < cc → TRUE * → memcpy fires at offset 0xFFFFFFFC * 512 (out of bounds) */ bug4_set_fat16_entry(disk, 2, 4);`
- Defined: `harness/exploit_disks.c:673`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_sync (function) `f_sync(&fp);`
- Defined: `harness/exploit_disks.c:787`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_close (function) `f_close(&fp);`
- Defined: `harness/exploit_disks.c:788`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_read (function) `f_read(&fp, rbuf, lseek_target, &br);`
- Defined: `harness/exploit_disks.c:795`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### bug6_build_exfat_label (function) `bug6_build_exfat_label(disk, 128);`
- Defined: `harness/exploit_disks.c:942`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_closedir (function) `f_closedir(&dj);`
- Defined: `harness/exploit_disks.c:1072`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_opendir (function) `f_opendir(&dj, "0:/");`
- Defined: `harness/exploit_disks.c:1245`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### perror (function) `perror("mkdir " IMG_DIR);`
- Defined: `harness/exploit_disks.c:1277`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug1_fat32 (function) `gen_bug1_fat32();`
- Defined: `harness/exploit_disks.c:1288`
- Doc: { /* Create output directory if (mkdir(IMG_DIR, 0755) != 0 && errno != EEXIST) { perror("mkdir " IMG_DIR); return 1; } p
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug3_gpt (function) `gen_bug3_gpt();`
- Defined: `harness/exploit_disks.c:1298`
- Doc: printf(" See critical.md for project list and vulnerability analysis.\n"); printf("=====================================
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug5_stale (function) `gen_bug5_stale();`
- Defined: `harness/exploit_disks.c:1304`
- Doc: gen_bug1_stm32(); gen_bug1_keystone3(); gen_bug1_ardupilot(); /* CVE-2026-6683: exFAT sync_fs divide-by-zero gen_bug2_ex
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### gen_bug7_grblhal (function) `gen_bug7_grblhal();`
- Defined: `harness/exploit_disks.c:1313`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/ffunicode_stub.c

### ff_uni2oem (function) `* ff_uni2oem() and ff_wtoupper() which normally come from ffunicode.c.
 * These stubs are suffici...`
- Defined: `harness/ffunicode_stub.c:5`
- Depends on: `FatFs-R0.16/source/ff.h`

### ff_uni2oem (function) `WCHAR ff_uni2oem(DWORD uni, WORD cp)`
- Defined: `harness/ffunicode_stub.c:17`
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
- Defined: `harness/libfuzzer_harness.c:9`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### main (function) `int main(int argc, char **argv)`
- Defined: `harness/libfuzzer_harness.c:128`
- Doc: f_close(&fp); break; /* process at most one file per fuzz iteration } f_closedir(&dj); } done: f_mount(NULL, "0:", 0); r
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### ramdisk_load (function) `ramdisk_load((const BYTE *)data, (UINT)size);`
- Defined: `harness/libfuzzer_harness.c:42`
- Doc: #include <stddef.h> #include <string.h> #include <stdlib.h> #include "ff.h" #include "diskio.h" #include "diskio_ramdisk
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memset (function) `memset(&fs, 0, sizeof(fs));`
- Defined: `harness/libfuzzer_harness.c:45`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_getlabel (function) `f_getlabel("0:", label_buf, NULL);`
- Defined: `harness/libfuzzer_harness.c:61`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### free (function) `free(label_buf);`
- Defined: `harness/libfuzzer_harness.c:62`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_closedir (function) `f_closedir(&dj);`
- Defined: `harness/libfuzzer_harness.c:75`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memcpy (function) `memcpy(path, "0:/", 3);`
- Defined: `harness/libfuzzer_harness.c:92`
- Doc: build "0:/filename" path CVE-2026-6688 fix: size the buffer for full LFN (up to FF_LFN_BUF chars) rather than the old SF
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### strncat (function) `strncat(path, fno.fname, sizeof(path) - sizeof("0:/"));`
- Defined: `harness/libfuzzer_harness.c:94`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_read (function) `f_read(&fp, buf, sizeof(buf), &br);`
- Defined: `harness/libfuzzer_harness.c:102`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_lseek (function) `f_lseek(&fp, mid);`
- Defined: `harness/libfuzzer_harness.c:106`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_close (function) `f_close(&fp);`
- Defined: `harness/libfuzzer_harness.c:114`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_mount (function) `done: f_mount(NULL, "0:", 0);`
- Defined: `harness/libfuzzer_harness.c:119`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### fseek (function) `fseek(f, 0, SEEK_END);`
- Defined: `harness/libfuzzer_harness.c:133`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### fread (function) `fread(buf, 1, (size_t)sz, f);`
- Defined: `harness/libfuzzer_harness.c:138`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### fclose (function) `fclose(f);`
- Defined: `harness/libfuzzer_harness.c:139`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### LLVMFuzzerTestOneInput (function) `LLVMFuzzerTestOneInput(buf, (size_t)sz);`
- Defined: `harness/libfuzzer_harness.c:140`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

## harness/rce_demo.c

### Build (function) `*
 * Build (without sanitisers, without stack protector — lets the overflow
 * reach the function...`
- Defined: `harness/rce_demo.c:45`
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
- Defined: `harness/rce_demo.c:131`
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

### void (function) `void (*on_apply)(void);`
- Defined: `harness/rce_demo.c:102`
- Doc: "I read finfo.fsize bytes into fw_header; finfo.fsize will never exceed FW_HDR_SIZE because the SD card is ours."  The a
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### puts (function) `puts(" [on_apply] safe_update_complete() — normal path");`
- Defined: `harness/rce_demo.c:125`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memset (function) `memset(&ctx, 0, sizeof(ctx));`
- Defined: `harness/rce_demo.c:158`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### printf (function) `printf(" [OTA] ctx at %p\n", (void *)&ctx);`
- Defined: `harness/rce_demo.c:160`
- Doc: ^^^^^^^^^^^^^^  ^^^^^^^^^^^^ destination     size = ATTACKER-CONTROLLED  The developer assumed finfo.fsize <= FW_HDR_SIZ
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_close (function) `f_close(&fp);`
- Defined: `harness/rce_demo.c:197`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memcpy (function) `memcpy(&vbr[3], "MSDOS5.0", 8);`
- Defined: `harness/rce_demo.c:241`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### st16le (function) `st16le(&vbr[11], 512);`
- Defined: `harness/rce_demo.c:242`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### fasize (function) `* fasize (DWORD) = 0x80000001 * 2 = 0x100000002 → truncates to 2 * sysect = 4 + 2 + 0 = 6 → database = sector 6 (inside FAT!) */ st32le(&vbr[36], 0x80000001U);`
- Defined: `harness/rce_demo.c:258`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### fclose (function) `fclose(f);`
- Defined: `harness/rce_demo.c:353`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### fprintf (function) `fprintf(stderr, "save_image: short write %zu / %zu\n", written, sz);`
- Defined: `harness/rce_demo.c:355`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### ramdisk_load (function) `ramdisk_load(buf, (UINT)n);`
- Defined: `harness/rce_demo.c:371`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### assert (function) `assert(sizeof(void *) == 8 && "Demo assumes LP64 — adjust FW_HDR_SIZE or struct if needed");`
- Defined: `harness/rce_demo.c:394`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_mount (function) `f_mount(NULL, "0:", 0);`
- Defined: `harness/rce_demo.c:465`
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
- Defined: `harness/test_harness.c:120`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### MCUs (function) `*    common on embedded MCUs (STM32, RP2040, ESP32, …).  The resulting call
 *    invokes rce_pro...`
- Defined: `harness/test_harness.c:261`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug1_rce_exploit (function) `static int test_bug1_rce_exploit(void)`
- Defined: `harness/test_harness.c:338`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_gpt_image (function) `static void build_gpt_image(BYTE *disk, size_t disk_bytes, uint32_t n_ent)`
- Defined: `harness/test_harness.c:459`
- Doc: Minimal protective-MBR + GPT header disk image builder.  Only as much structure as find_volume needs to enter the loop: 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### releases (function) `*
 * Historical note: older FatFs releases (before test_gpt_header was
 * introduced) had no such...`
- Defined: `harness/test_harness.c:509`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug4_stale_cache_skip (function) `static int test_bug4_stale_cache_skip(void)`
- Defined: `harness/test_harness.c:601`
- Doc: through a range that includes X. 4. The bulk disk_read() returns stale (pre-write) data for sector X; the cache copy tha
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### layout (function) `*
 * Disk layout (FAT16, 4 sectors/cluster):
 *   Sectors  0           VBR
 *   Sectors  1-4     ...`
- Defined: `harness/test_harness.c:693`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_fat16_base (function) `static void build_fat16_base(BYTE *disk, size_t disk_bytes)`
- Defined: `harness/test_harness.c:725`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### __attribute__ (function) `__attribute__((unused))
static void fat16_set_chain(BYTE *disk, uint16_t cluster, uint16_t next)`
- Defined: `harness/test_harness.c:763`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug5_infoleak_lseek (function) `static int test_bug5_infoleak_lseek(void)`
- Defined: `harness/test_harness.c:781`
- Doc: Write exactly one full cluster so fp->buf is never used (direct sector writes) and the cluster-2 content is fully under 
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### pass (function) `*      or pass (sizeof_label - di) instead of the hard-coded 4.
 *===============================...`
- Defined: `harness/test_harness.c:927`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug6_getlabel_exfat_overflow (function) `static int test_bug6_getlabel_exfat_overflow(void)`
- Defined: `harness/test_harness.c:998`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### sfn_checksum_b7 (function) `static BYTE sfn_checksum_b7(const BYTE sfn[11])`
- Defined: `harness/test_harness.c:1090`
- Doc: char fname[13];                     // SFN-sized buffer strcpy(fname, fno.fname);           // overflows if LFN > 12 cha
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_fat16_with_lfn (function) `static void build_fat16_with_lfn(BYTE *disk, size_t disk_bytes)`
- Defined: `harness/test_harness.c:1104`
- Doc: static BYTE sfn_checksum_b7(const BYTE sfn[11]) { BYTE sum = 0; for (int i = 0; i < 11; i++) sum = (BYTE)(((sum & 1) ? 0
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### test_bug7_lfn_path_overflow (function) `static int test_bug7_lfn_path_overflow(void)`
- Defined: `harness/test_harness.c:1156`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### main (function) `int main(void)`
- Defined: `harness/test_harness.c:1257`
- Doc: =========================================================================== main *======================================
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### code (function) `* * Vulnerable code (ff.c ~line 3600): * * fasize = ld_16(fs->win + BPB_FATSz16);`
- Defined: `harness/test_harness.c:88`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memset (function) `memset(disk, 0, disk_bytes);`
- Defined: `harness/test_harness.c:123`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### memcpy (function) `memcpy(&vbr[3], "MSDOS5.0", 8);`
- Defined: `harness/test_harness.c:129`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### st16le (function) `st16le(&vbr[11], 512);`
- Defined: `harness/test_harness.c:130`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### truncated (function) `* truncated (DWORD) → 0x00000002 * * sysect = 4 (reserved) + 2 (fake fasize) + 0 (no root) = 6 * * fs->database = bsect(0) + 6 = sector 6 ← within FAT area! */ st32le(&vbr[36], 0x80000001U);`
- Defined: `harness/test_harness.c:146`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### printf (function) `printf("\n[CVE-2026-6682] FAT32 sector-count integer overflow in mount_volume()\n");`
- Defined: `harness/test_harness.c:182`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### ramdisk_load (function) `ramdisk_load(image, sizeof(image));`
- Defined: `harness/test_harness.c:188`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### INFO (function) `INFO("f_mount() returned %d (FR_OK=0, FR_NO_FILESYSTEM=13)", (int)res);`
- Defined: `harness/test_harness.c:193`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### RESULT (function) `RESULT("CVE-2026-6682 FAT32 integer overflow", 0);`
- Defined: `harness/test_harness.c:197`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_mount (function) `f_mount(NULL, "0:", 0);`
- Defined: `harness/test_harness.c:226`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_fat32_rce_image (function) `build_fat32_rce_image(image, sizeof(image), target);`
- Defined: `harness/test_harness.c:355`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_close (function) `f_close(&fp);`
- Defined: `harness/test_harness.c:404`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### fn (function) `fn();`
- Defined: `harness/test_harness.c:418`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### move_window (function) `* move_window(fs, pt_lba + i * SZ_GPTE / SS(fs));`
- Defined: `harness/test_harness.c:435`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### ramdisk_reset_stats (function) `ramdisk_reset_stats();`
- Defined: `harness/test_harness.c:529`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### write_fat16_entry (function) `write_fat16_entry(fat, cluster, next);`
- Defined: `harness/test_harness.c:769`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### free (function) `free(payload);`
- Defined: `harness/test_harness.c:831`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### f_sync (function) `f_sync(&fp);`
- Defined: `harness/test_harness.c:837`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### build_exfat_large_label (function) `build_exfat_large_label(image, sizeof(image), 128);`
- Defined: `harness/test_harness.c:1007`
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

### f_closedir (function) `f_closedir(&dj);`
- Defined: `harness/test_harness.c:1194`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`

### strcat (function) `* strcat(path, fno.fname);`
- Defined: `harness/test_harness.c:1213`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`, `harness/diskio_ramdisk.h`
