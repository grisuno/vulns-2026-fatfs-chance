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

## FatFs-R0.16/documents/res/app2.c
- Layer: utility
- Doc: ------------------------------------------------------------
- Language: c
- Symbols:
  - `delete_node` (function, line 7) `FRESULT delete_node (
    TCHAR* path,    /* Path name buffer with the sub-directory to delete */...`

## FatFs-R0.16/documents/res/app3.c
- Layer: utility
- Doc: ----------------------------------------------------------------------
- Language: c
- Symbols:
  - `allocate_contiguous_clusters` (function, line 18) `DWORD allocate_contiguous_clusters (    /* Returns the first sector in LBA (0:error or not contig...`
  - `main` (function, line 76) `int main (void)`

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
