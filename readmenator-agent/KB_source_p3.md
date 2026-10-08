# Subsystem: source (page 3 of 3)
Previous: [KB_source_p2.md](KB_source_p2.md)

## FatFs-R0.16/source/ff.h
- Doc: PARTITION: #define _TEXT(x) U ## x #elif FF_USE_LFN && (FF_LFN_UNICODE < 0 || FF_LFN_UNICODE >...
- Layer: utility
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
  - `QWORD` (variable, line 26) `extern "C" { #endif #if !defined(FFCONF_DEF) #include "ffconf.h" /* FatFs configuration options */ #endif #if...`
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
- Doc: ff_uni2oem: if FF_CODE_PAGE != 0 && FF_CODE_PAGE < 900
- Layer: utility
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

