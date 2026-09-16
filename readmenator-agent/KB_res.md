# Subsystem: res

## FatFs-R0.16/documents/res/app1.c
- Layer: utility
- Doc: ------------------------------------------------------------
- Language: c
- Symbols:
  - `open_append` (function, line 5) `FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* p...`
  - `main` (function, line 23) `int main (void)`
  - `f_mount` (function, line 32) `f_mount(&fs, "", 0);`
  - `f_printf` (function, line 37) `f_printf(&fil, "%02u/%02u/%u, %2u:%02u\n", Mday, Mon, Year, Hour, Min);`
  - `f_close` (function, line 40) `f_close(&fil);`

## FatFs-R0.16/documents/res/app2.c
- Layer: utility
- Doc: ------------------------------------------------------------
- Language: c
- Symbols:
  - `delete_node` (function, line 7) `FRESULT delete_node (
    TCHAR* path,    /* Path name buffer with the sub-directory to delete */...`
  - `f_closedir` (function, line 45) `f_closedir(&dir);`
  - `f_mount` (function, line 60) `f_mount(&fs, _T("5:"), 0);`
  - `_tcscpy` (function, line 65) `_tcscpy(buff, _T("5:dir"));`
  - `_tprintf` (function, line 72) `_tprintf(_T("Failed to delete the directory. (%u)\n"), fr);`

## FatFs-R0.16/documents/res/app3.c
- Layer: utility
- Doc: ----------------------------------------------------------------------
- Language: c
- Symbols:
  - `allocate_contiguous_clusters` (function, line 18) `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:error or not contig...`
  - `main` (function, line 76) `int main (void)`
  - `clust2sect` (function, line 15) `DWORD clust2sect (FATFS* fs, DWORD clst);`
  - `get_fat` (function, line 16) `DWORD get_fat (FATFS* fs, DWORD clst);`
  - `put_fat` (function, line 17) `FRESULT put_fat (FATFS* fs, DWORD clst, DWORD val);`
  - `f_mount` (function, line 88) `f_mount(&fs, "", 0);`
  - `printf` (function, line 96) `printf("Function failed due to any error or insufficient contiguous area.\n");`
  - `f_close` (function, line 97) `f_close(&fil);`

## FatFs-R0.16/documents/res/app4.c
- Layer: utility
- Doc: ----------------------------------------------------------------------
- Language: c
- Symbols:
  - `pn` (function, line 11) `static DWORD pn (       /* Pseudo random number generator */
    DWORD pns   /* 0:Initialize, !0:...`
  - `test_diskio` (function, line 34) `int test_diskio (
    BYTE pdrv,      /* Physical drive number to be checked (all data on the dri...`
  - `main` (function, line 296) `int main (int argc, char* argv[])`
  - `printf` (function, line 49) `printf("test_diskio(%u, %u, 0x%08X, 0x%08X)\n", pdrv, ncyc, (UINT)buff, sz_buff);`
  - `memset` (function, line 137) `memset(pbuff, 0, sz_sect);`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`

## FatFs-R0.16/documents/res/app5.c
- Layer: utility
- Doc: ----------------------------------------------------------------------
- Language: c
- Symbols:
  - `test_contiguous_file` (function, line 4) `FRESULT test_contiguous_file (
    FIL* fp,    /* [IN]  Open file object to be checked */
    int...`

## FatFs-R0.16/documents/res/app6.c
- Layer: utility
- Doc: ---------------------------------------------------------------------
- Language: c
- Symbols:
  - `test_raw_speed` (function, line 9) `int test_raw_speed (
    BYTE pdrv,      /* Physical drive number */
    DWORD lba,      /* Start...`
  - `printf` (function, line 25) `printf("\ndisk_ioctl() failed.\n");`
- Depends on: `FatFs-R0.16/source/diskio.h`, `FatFs-R0.16/source/ff.h`
