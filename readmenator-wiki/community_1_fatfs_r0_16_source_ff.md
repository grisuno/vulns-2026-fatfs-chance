# FatFs-R0.16/source: ff

*Community 1 | 5 files | cohesion 0.29*

## Definition

This community groups 5 file(s) rooted at `FatFs-R0.16/source` with dominant language c (cohesion 0.29). Central symbols: `AM_ARC`, `AM_DIR`, `AM_HID`, `AM_RDO`, `AM_SYS`, `BYTE`, `CREATE_LINKMAP`, `CVTBL`. Core file: `FatFs-R0.16/source/ff.h` (86 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `FatFs-R0.16/source/ff.h` | h | utility | 86 | yes |
| `FatFs-R0.16/source/ffconf.h` | h | utility | 42 | yes |
| `FatFs-R0.16/source/ffsystem.c` | c | utility | 7 | yes |
| `FatFs-R0.16/source/ffunicode.c` | c | utility | 9 | yes |
| `harness/ffunicode_stub.c` | c | testing | 3 | yes |

## Key Symbols

- `FF_DEFINED` (macro, `FatFs-R0.16/source/ff.h:23`) `#define FF_DEFINED`
- `QWORD` (variable, `FatFs-R0.16/source/ff.h:26`) `extern "C" { #endif #if !defined(FFCONF_DEF) #include "ffconf.h" /* FatFs config` - ifdef __cplusplus
- `FF_INTDEF` (macro, `FatFs-R0.16/source/ff.h:40`) `#define FF_INTDEF`
- `QWORD` (type_alias, `FatFs-R0.16/source/ff.h:42`) `typedef unsigned __int64 QWORD;` - #if !defined(FFCONF_DEF) #include "ffconf.h"		/* FatFs configuration options #endif #if FF_DEFINED !
- `isnan` (macro, `FatFs-R0.16/source/ff.h:44`) `#define isnan(v)`
- `isinf` (macro, `FatFs-R0.16/source/ff.h:45`) `#define isinf(v)`
- `FF_INTDEF` (macro, `FatFs-R0.16/source/ff.h:48`) `#define FF_INTDEF`
- `UINT` (type_alias, `FatFs-R0.16/source/ff.h:50`) `typedef unsigned int UINT;` - /* Integer types used for FatFs API #if defined(_WIN32)		/* Windows VC++ (for development only) #def
- `BYTE` (type_alias, `FatFs-R0.16/source/ff.h:51`) `typedef unsigned char BYTE;` - /* Integer types used for FatFs API #if defined(_WIN32)		/* Windows VC++ (for development only) #def
- `WORD` (type_alias, `FatFs-R0.16/source/ff.h:52`) `typedef uint16_t WORD;` - #if defined(_WIN32)		/* Windows VC++ (for development only) #define FF_INTDEF 2 #include <windows.h>
- `DWORD` (type_alias, `FatFs-R0.16/source/ff.h:53`) `typedef uint32_t DWORD;` - #if defined(_WIN32)		/* Windows VC++ (for development only) #define FF_INTDEF 2 #include <windows.h>
- `QWORD` (type_alias, `FatFs-R0.16/source/ff.h:54`) `typedef uint64_t QWORD;` - #define FF_INTDEF 2 #include <windows.h> typedef unsigned __int64 QWORD; #include <float.h> #define
- `WCHAR` (type_alias, `FatFs-R0.16/source/ff.h:55`) `typedef WORD WCHAR;` - #include <windows.h> typedef unsigned __int64 QWORD; #include <float.h> #define isnan(v) _isnan(v) #
- `FF_INTDEF` (macro, `FatFs-R0.16/source/ff.h:58`) `#define FF_INTDEF`
- `UINT` (type_alias, `FatFs-R0.16/source/ff.h:59`) `typedef unsigned int UINT;` - #define isinf(v) (!_finite(v)) #elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \|\| d
- `BYTE` (type_alias, `FatFs-R0.16/source/ff.h:60`) `typedef unsigned char BYTE;` - #elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \|\| defined(__cplusplus)	/* C99 or l
- `WORD` (type_alias, `FatFs-R0.16/source/ff.h:61`) `typedef unsigned short WORD;` - #elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \|\| defined(__cplusplus)	/* C99 or l
- `DWORD` (type_alias, `FatFs-R0.16/source/ff.h:62`) `typedef unsigned long DWORD;` - #define FF_INTDEF 2 #include <stdint.h> typedef unsigned int	UINT;	/* int must be 16-bit or 32-bit t
- `WCHAR` (type_alias, `FatFs-R0.16/source/ff.h:63`) `typedef WORD WCHAR;` - #include <stdint.h> typedef unsigned int	UINT;	/* int must be 16-bit or 32-bit typedef unsigned char
- `FSIZE_t` (type_alias, `FatFs-R0.16/source/ff.h:73`) `typedef QWORD FSIZE_t;` - if FF_FS_EXFAT if FF_INTDEF != 2 error exFAT feature wants C99 or later endif
- `LBA_t` (type_alias, `FatFs-R0.16/source/ff.h:75`) `typedef QWORD LBA_t;` - if FF_LBA64
- `LBA_t` (type_alias, `FatFs-R0.16/source/ff.h:77`) `typedef DWORD LBA_t;` - else
- `FSIZE_t` (type_alias, `FatFs-R0.16/source/ff.h:83`) `typedef DWORD FSIZE_t;` - endif else if FF_LBA64 error exFAT needs to be enabled when enable 64-bit LBA endif
- `LBA_t` (type_alias, `FatFs-R0.16/source/ff.h:84`) `typedef DWORD LBA_t;`
- `TCHAR` (type_alias, `FatFs-R0.16/source/ff.h:92`) `typedef WCHAR TCHAR;` - #endif #else #if FF_LBA64 #error exFAT needs to be enabled when enable 64-bit LBA #endif typedef DWO
- `_T` (macro, `FatFs-R0.16/source/ff.h:93`) `#define _T(x)`
- `_TEXT` (macro, `FatFs-R0.16/source/ff.h:94`) `#define _TEXT(x)`
- `TCHAR` (type_alias, `FatFs-R0.16/source/ff.h:96`) `typedef char TCHAR;` - #endif typedef DWORD FSIZE_t; typedef DWORD LBA_t; #endif /* Type of path name strings on FatFs API
- `_T` (macro, `FatFs-R0.16/source/ff.h:97`) `#define _T(x)`
- `_TEXT` (macro, `FatFs-R0.16/source/ff.h:98`) `#define _TEXT(x)`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 4
- Cross-boundary resolved imports (EXTRACTED): 10

## Connections

- [EXTRACTED] depends_on community 0 <-> 1 (strength 0.9): Extracted import edge crosses communities: FatFs-R0.16/documents/res/app4.c imports FatFs-R0.16/source/ff.h.
- [EXTRACTED] depends_on community 2 <-> 1 (strength 0.9): Extracted import edge crosses communities: harness/diskio_ramdisk.c imports FatFs-R0.16/source/ff.h.
- [INFERRED] bridges community 0 <-> 1 (strength 0.7): Inferred cross-community bridge: FatFs-R0.16/source/diskio.h reaches FatFs-R0.16/source/ffconf.h in 3 hops.
- [INFERRED] bridges community 0 <-> 1 (strength 0.7): Inferred cross-community bridge: FatFs-R0.16/source/diskio.h reaches FatFs-R0.16/source/ffsystem.c in 3 hops.
- [INFERRED] bridges community 0 <-> 1 (strength 0.7): Inferred cross-community bridge: FatFs-R0.16/source/diskio.h reaches FatFs-R0.16/source/ffunicode.c in 3 hops.
- [INFERRED] bridges community 0 <-> 1 (strength 0.7): Inferred cross-community bridge: FatFs-R0.16/source/diskio.h reaches harness/ffunicode_stub.c in 3 hops.
- [INFERRED] shares_context community 1 <-> 3 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 1 (FatFs-R0.16/source: ff) and community 3 (orphans).

## Risks

- No scoped security, taint, cycle, or layer risks.

## Open Questions

- What would break if the most connected file in FatFs-R0.16/source: ff changed?
- Should FatFs-R0.16/source: ff be split, given cohesion 0.29?

## Sources

- `FatFs-R0.16/source/ff.h`
- `FatFs-R0.16/source/ffconf.h`
- `FatFs-R0.16/source/ffsystem.c`
- `FatFs-R0.16/source/ffunicode.c`
- `harness/ffunicode_stub.c`
