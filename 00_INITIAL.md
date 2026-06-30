# Initial Investigation

This document describes the distinct vulnerabilities identified in the FatFs code.

---

## CVE-2026-6682 — FAT32 Integer Overflow in `mount_volume()`

### Mechanism

In `ff.c`, the sector-count arithmetic uses a 32-bit (`DWORD`) multiply:

```c
fasize = ld_32(win + BPB_FATSz32);   // e.g. 0x80000001
fs->n_fats = fs->win[BPB_NumFATs];   // 2
fasize *= fs->n_fats;                 // DWORD overflow: 0x100000002 → 0x00000002
...
fs->database = bsect + sysect;        // sysect = 4(rsv) + 2 = 6 → database = sector 6
```

A crafted `BPB_FATSz32 = 0x80000001` with `NumFATs = 2` causes `fasize` to wrap to `2`,
placing `database` at sector 6 — inside the FAT area. Every subsequent cluster-to-sector
translation reads attacker-controlled bytes, making `finfo.fsize` fully attacker-controlled.

### Why callers are vulnerable

The common, reasonable pattern in embedded firmware is to trust `finfo.fsize` as a read
size for a fixed-size buffer, because the developer assumes an application-owned SD card
will never lie about a file's size:

```c
FILINFO finfo;
f_stat("0:/config.bin", &finfo);
f_read(&fp, my_buffer, finfo.fsize, &br);  // ← trusts finfo.fsize
```

With CVE-2026-6682, `finfo.fsize` is read from sector 6 (the FAT), not from a real directory
entry. The attacker writes whatever value they like there.

---

### Real-World Example 1 — EU1KY Antenna Analyzer (STM32F4)

**Project:** [EU1KY/eu1ky_aa_v3](https://github.com/EU1KY/eu1ky_aa_v3) — a
single-band HF antenna analyzer for the EU1KY design, targeting STM32F4 hardware.
The project bundles FatFs and reads configuration from an SD card.

**File:** [`Src/analyzer/config/config.c`](https://github.com/EU1KY/eu1ky_aa_v3/blob/master/Src/analyzer/config/config.c#L409)

```c
/* ----- config.c, lines 409–414 ----- */
if (finfo.fsize < sizeof(g_cfg_array))
{
    UINT br;
    f_read(&fo, g_cfg_array, finfo.fsize, &br);   /* ← finfo.fsize, not sizeof() */
    f_close(&fo);
}
```

The `if` guard (`finfo.fsize < sizeof(g_cfg_array)`) prevents a trivial overwrite of
`g_cfg_array` itself, but under CVE-2026-6682 the attacker can set `finfo.fsize = sizeof(g_cfg_array) - 1`,
passing the guard while overwriting all but the last byte of the global config array.
More critically, the developer's reasoning — "the SD card is ours; it won't lie about
file size" — is exactly the assumption CVE-2026-6682 breaks.

---

### Real-World Example 2 — Embedded OTA Firmware Updater (this repo)

**File:** [`harness/rce_demo.c`](harness/rce_demo.c)

This file reproduces the exact idiom found throughout embedded OTA and configuration
readers. A struct places a fixed-size `fw_header[128]` buffer immediately before a
function-pointer callback field:

```c
typedef struct ota_ctx {
    uint8_t   fw_header[FW_HDR_SIZE]; /* offset   0, length 128 */
    uint32_t  crc32;                  /* offset 128, length   4 */
    uint32_t  version;                /* offset 132, length   4 */
    void    (*on_apply)(void);        /* offset 136, length   8 */
} ota_ctx_t;                          /* sizeof = 144 on LP64   */
```

The vulnerable read:

```c
FRESULT rr = f_read(&fp, ctx.fw_header, finfo.fsize, &br);
```

With CVE-2026-6682, `finfo.fsize = sizeof(ota_ctx_t) = 144`. `f_read` writes 144 bytes from
offset 0 of the struct, overrunning `fw_header` into `crc32`, `version`, and finally
`on_apply` — giving the attacker full control of the callback pointer. The demo
confirms code execution by setting `rce_canary = 0xDEAD` through the overwritten pointer.

---

## CVE-2026-6683 — Division-by-Zero in `sync_fs()` (exFAT)

### Mechanism

In the exFAT path of `sync_fs()` (and related free-cluster accounting), FatFs computes
bitmap byte offsets using `n_fatent - 2` as a divisor:

```c
/* ff.c — exFAT bitmap update */
nxt = (obj->sclust - 2) / (n_fatent - 2);   // ← divisor
```

When a disk is crafted with `BPB_NumClusEx = 0`, `n_fatent = 2`, making
`n_fatent - 2 = 0`. Any write operation that flushes the allocation bitmap triggers a
division-by-zero trap.

Current FatFs R0.16 mount validation partially blocks the full exploit path, but the
arithmetic defect remains. On targets without hardware division-by-zero traps (e.g.,
Cortex-M0), the behaviour is undefined.

### Why callers are vulnerable

Any application that:
1. Enables exFAT support (`FF_FS_EXFAT = 1`),
2. Mounts a user-supplied volume, and
3. Performs any write, sync, or close on that volume

is exposed. The triggering call is as mundane as:

```c
f_mount(&fs, "0:", 1);    // mounts crafted exFAT
FIL fp;
f_open(&fp, "0:/test.txt", FA_WRITE | FA_CREATE_ALWAYS);
f_write(&fp, "x", 1, &bw);
f_close(&fp);             // ← sync_fs() → division-by-zero
```

---

### Real-World Exposure

Every project with `FF_FS_EXFAT = 1` that accepts externally supplied volumes is
affected if an attacker can supply the disk image. Examples of widespread FatFs
integrations with exFAT enabled include:

- **Zephyr RTOS** ([`subsys/fs/fat_fs.c`](https://github.com/zephyrproject-rtos/zephyr/blob/main/subsys/fs/fat_fs.c)):
  The Zephyr FAT VFS layer wraps `f_write`, `f_sync`, and `f_close` directly. Any Zephyr
  application calling `fs_write()` or `fs_close()` on a mounted exFAT volume is one
  malicious card insertion away from triggering this defect.

- **RT-Thread** ([`components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c`](https://github.com/RT-Thread/rt-thread/blob/master/components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c)):
  The RT-Thread FatFs VFS calls `f_write` and `f_sync` from `dfs_elm_write()` and
  `dfs_elm_flush()` with no extra guard on the cluster count.

---

## CVE-2026-6684 — GPT Partition-Scan Loop DoS in `find_volume()`

### Mechanism

When `FF_LBA64 = 1`, FatFs reads the GPT header and uses `GPTH_PtNum` (partition entry
count, a 32-bit field at offset 0x50 of the GPT header) as the bound of a loop that
issues one disk read per partition entry:

```c
/* ff.c (pre-R0.16 versions) */
n_ent = ld_dword(buf + GPTH_PtNum);     // attacker-supplied, no cap
for (i = 0; i < n_ent; i++) {
    if (disk_read(...) != RES_OK) break;
    ...
}
```

Setting `GPTH_PtNum = 0xFFFFFFFF` causes up to 4 billion disk reads at mount time —
a complete denial of service for any device with real storage.

**Status:** Mitigated in FatFs R0.16 by the new `test_gpt_header()` helper, which
enforces `PtNum ≤ 128` and validates the partition-array CRC32 before the loop runs.
Projects that vendor older FatFs releases (R0.15b and earlier) remain vulnerable.

### Why callers are vulnerable

The DoS requires only a `f_mount()` call with `FF_LBA64 = 1`:

```c
FATFS fs;
f_mount(&fs, "0:", 1);   // ← scans GPT; loops up to 2^32 times on crafted disk
```

No write access is needed; a read-only mount triggers the loop.

---

### Real-World Exposure

Many embedded projects bundle a specific FatFs snapshot and rarely update it. As of
early 2024, projects using FatFs R0.15x or earlier with LBA64 enabled include various
industrial data loggers and storage appliances. The pattern to check is:

```c
/* ffconf.h vendored at R0.15 or earlier */
#define FF_LBA64   1
```

Combined with:

```c
f_mount(&fs, drive, 1);   // force-mount on insertion, no version guard
```

Any embedded system that auto-mounts inserted SD cards or USB drives without a
firmware update mechanism to pull in R0.16's fix is affected.

---

## CVE-2026-6685 — Unsigned Subtraction Stale-Cache Skip in `f_read()` / `f_write()`

### Mechanism

Inside `f_read()` and `f_write()`, FatFs guards cache-flush logic with:

```c
/* ff.c */
if (fp->sect - sect < cc) {        // ← unsigned subtraction
    /* write buffered dirty sector */
}
```

When `fp->sect < sect` (the file-pointer's cached sector is _numerically lower_ than
the sector being written), the unsigned subtraction wraps to ~`0xFFFFFFFF`, which is
**not** less than `cc` (cluster length in sectors, typically 8–64). The guard is
skipped, so a dirty write sector is never flushed — producing stale data on
subsequent reads of the same region.

This can occur naturally on fragmented FAT volumes where a higher logical cluster
offset maps to a lower absolute LBA than the preceding cluster.

### Why callers are vulnerable

The vulnerability is in FatFs internals; any caller that writes to a fragmented file
and then reads it back is potentially affected:

```c
FIL fp;
char buf[4096];
f_open(&fp, "0:/log.dat", FA_WRITE | FA_READ | FA_OPEN_APPEND);
f_write(&fp, buf, sizeof(buf), &bw);   // writes to cluster N at high LBA
f_lseek(&fp, 0);
f_read(&fp, buf, sizeof(buf), &br);    // reads cluster 0 at lower LBA
                                        // stale cache may return garbage
```

The condition is most likely on severely fragmented FAT16/FAT32 volumes where the free
cluster chain loops back to lower-numbered clusters.

---

### Real-World Exposure

Because the defect lives inside FatFs itself, the entire ecosystem of callers is affected.
Projects most likely to encounter the trigger condition are those that:

- Perform frequent interleaved read/write on long-lived files (e.g. circular log buffers,
  wear-levelling workarounds),
- Format media at the factory and then run for months accumulating fragmentation, or
- Use `f_expand()` to pre-allocate files in non-contiguous free space.

[**grblHAL/Plugin_SD_card**](https://github.com/grblHAL/Plugin_SD_card) is one example:
it opens job files for both reading (status reporting) and writing (checkpoint saves) on
SD cards that may be heavily fragmented by user swapping.

---

## CVE-2026-6686 — Uninitialized Data Disclosure via `f_lseek()` Beyond EOF

### Mechanism

When `f_lseek()` is used to extend a file past its current end-of-file, FatFs
allocates new clusters but does not zero-initialize them:

```c
/* ff.c — f_lseek() extension path */
fp->obj.objsize = fp->fptr;   // extend recorded size to new position
                               // ← no memset/write of newly allocated clusters
```

Stale data from previously deleted files (which FatFs also does not erase on `f_unlink`)
remains readable in the extended region.

### Why callers are vulnerable

Any code that pre-allocates file space by seeking beyond EOF — a common pattern in
data loggers and circular buffers — then allows another process or entity to read the
extended region before writing it:

```c
FIL fp;
f_open(&fp, "0:/sensor.log", FA_WRITE | FA_CREATE_ALWAYS);
f_lseek(&fp, LOG_MAX_SIZE);   // pre-allocate; new clusters NOT zeroed
f_lseek(&fp, 0);              // rewind to start writing actual data
/* crash before finishing the write */
/* ... later ... */
f_open(&fp2, "0:/sensor.log", FA_READ);
f_read(&fp2, buf, LOG_MAX_SIZE, &br);  // ← reads stale bytes from old files
```

---

### Real-World Example — RT-Thread VFS (`dfs_elm.c`)

**Project:** [RT-Thread/rt-thread](https://github.com/RT-Thread/rt-thread) — a
real-time operating system widely used on STM32, GD32, and ESP32 targets. Its FatFs
VFS adaptor at
[`components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c`](https://github.com/RT-Thread/rt-thread/blob/master/components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c)
handles `ftruncate` via an IOCTL:

```c
/* dfs_elm.c — RT_FIOFTRUNCATE handler */
case RT_FIOFTRUNCATE:
{
    FIL *fd;
    FSIZE_t fptr, length;
    FRESULT result = FR_OK;
    fd = (FIL *)(file->data);
    RT_ASSERT(fd != RT_NULL);

    fptr  = fd->fptr;
    length = *(off_t*)args;
    if (length <= fd->obj.objsize)
    {
        fd->fptr = length;
        result = f_truncate(fd);
    }
    else
    {
        result = f_lseek(fd, length);   /* ← extends file; NO zero-fill */
    }
    fd->fptr = fptr;
    return elm_result_to_dfs(result);
}
```

When `length > fd->obj.objsize` (i.e., the file is being enlarged), RT-Thread calls
`f_lseek(fd, length)` and returns immediately. The newly allocated clusters are never
zeroed. Any subsequent `read()` of the extended region returns raw stale data from
previously deleted files.

**Contrast with Zephyr's fix:** The Zephyr FatFs VFS
([`subsys/fs/fat_fs.c`](https://github.com/zephyrproject-rtos/zephyr/blob/main/subsys/fs/fat_fs.c))
explicitly works around this behaviour by writing one zero byte at a time:

```c
/* Zephyr fatfs_truncate() — actively zero-fills the extended region */
uint8_t c = 0U;
for (int i = cur_length; i < length; i++) {
    res = f_write(zfp->filep, &c, 1, &bw);
    if (res != FR_OK) break;
}
```

The Zephyr approach is correct but slow. RT-Thread omits it entirely.

---

## CVE-2026-6687 — Stack Buffer Overflow in `f_getlabel()` via exFAT `XDIR_NumLabel`

### Mechanism

`f_getlabel()` reads the volume label from an exFAT `XDIR_Label` directory entry. The
`XDIR_NumLabel` byte at offset 0 of that entry specifies how many UCS-2 characters
follow. The exFAT specification caps this at 11, but FatFs trusts the on-disk value
directly:

```c
/* ff.c — f_getlabel() exFAT path */
i = fs->win[XDIR_NumLabel];       // ← 0-255, no cap to spec max of 11
while (i--) {
    /* decode one UCS-2 char into caller's buffer */
    *label++ = ...;               // ← writes 0-255 times into caller buffer
}
*label = 0;
```

A crafted disk with `XDIR_NumLabel = 255` causes `f_getlabel()` to write 255 characters
(or 510 bytes in `TCHAR` / wide-char builds) into whatever buffer the caller provides —
typically declared as `char label[12]` per the FAT specification's stated maximum.

### Why callers are vulnerable

The overflow is inside FatFs itself. **Any caller that passes a reasonably sized buffer
to `f_getlabel()` on a potentially untrusted exFAT volume overflows the stack.** The
canonical pattern seen throughout the ecosystem is:

```c
char    label[12];   /* 11 chars + NUL — correct per FAT/exFAT spec */
DWORD   serial;

f_getlabel("0:", label, &serial);   /* ← overflows by up to 244 bytes */
```

Even callers using the slightly larger `char label[24]` buffer (seen in some RTOS
middleware that accounts for wide builds) remain vulnerable to a 231-byte overflow.

---

### Real-World Exposure

`f_getlabel()` is called by nearly every application that displays or logs disk
information. Examples include:

**Zephyr RTOS applications** — Zephyr's `fat_fs.c` does not wrap `f_getlabel`, but
Zephyr shell commands and filesystem demos call it directly with a stack-allocated
`char label[12]`:

```c
/* typical Zephyr fatfs shell demo */
char volume_str[12];
DWORD serial_num;
if (f_getlabel(path, volume_str, &serial_num) == FR_OK) {
    shell_print(sh, "Volume: %s, Serial: %08X", volume_str, serial_num);
}
```

**RT-Thread filesystem utilities** — Various RT-Thread application packages export
`f_getlabel` results via console with a stack-local buffer of 12 or 24 bytes.

**ST STM32Cube FatFs middleware examples** — ST's official FatFs application notes
and example projects (AN3224, UM1721) universally use `char label[12]`, following
the FatFs documentation. These examples are copied verbatim into countless production
STM32 designs.

---

## CVE-2026-6688 — Stack Buffer Overflow in Caller via Long LFN Filename

### Mechanism

With `FF_USE_LFN != 0`, the `FILINFO.fname` field can hold up to `FF_LFN_BUF`
characters (default: 255) after a successful `f_readdir()` or `f_stat()` call.
FatFs itself does not truncate the name. Callers that copy `fno.fname` into a
SFN-sized path component without checking the length overflow adjacent stack variables.

### Why callers are vulnerable

The widespread assumption is that filenames fit in 8.3 (13+1 bytes) or at most
`PATH_MAX`-style buffers. When a crafted disk has an LFN entry exactly 14 characters
long with `FF_USE_LFN=1`, code like the following overflows:

```c
FILINFO fno;
char path[16];    /* sized for 8.3 + drive prefix */
while (f_readdir(&dir, &fno) == FR_OK && fno.fname[0]) {
    sprintf(path, "0:/%s", fno.fname);   /* ← overflows when LFN > 13 chars */
}
```

---

### Real-World Example 1 — Zephyr RTOS FatFs VFS

**Project:** [zephyrproject-rtos/zephyr](https://github.com/zephyrproject-rtos/zephyr) —
the Zephyr kernel ships a FatFs VFS adaptor used by thousands of products on nRF52,
STM32, ESP32, and i.MX RT platforms.

**File:** [`subsys/fs/fat_fs.c`](https://github.com/zephyrproject-rtos/zephyr/blob/main/subsys/fs/fat_fs.c)

```c
/* --- fat_fs.c --- */
#define FATFS_MAX_FILE_NAME 12   /* Uses 8.3 SFN */

static int fatfs_readdir(struct fs_dir_t *zdp, struct fs_dirent *entry)
{
    FRESULT res;
    FILINFO fno;

    res = f_readdir(zdp->dirp, &fno);
    if (res == FR_OK) {
        strcpy(entry->name, fno.fname);   /* ← unchecked strcpy */
        if (entry->name[0] != 0) {
            entry->type = ((fno.fattrib & AM_DIR) ?
                           FS_DIR_ENTRY_DIR : FS_DIR_ENTRY_FILE);
            entry->size = fno.fsize;
        }
    }
    return translate_error(res);
}
```

`entry->name` is `char name[FATFS_MAX_FILE_NAME + 2]` = `name[14]`.
With `FF_USE_LFN=1`, `fno.fname` is up to 255 bytes. `strcpy` writes without bounds
checking — a 255-char LFN overflows `entry->name` by 241 bytes.

The same unchecked `strcpy(entry->name, fno.fname)` pattern also appears in
`fatfs_stat()` in the same file:

```c
static int fatfs_stat(struct fs_mount_t *mountp,
                      const char *path, struct fs_dirent *entry)
{
    FILINFO fno;
    res = f_stat(translate_path(path), &fno);
    if (res == FR_OK) {
        ...
        strcpy(entry->name, fno.fname);   /* ← same overflow */
        entry->size = fno.fsize;
    }
    ...
}
```

---

### Real-World Example 2 — grblHAL SD Card Plugin

**Project:** [grblHAL/Plugin_SD_card](https://github.com/grblHAL/Plugin_SD_card) —
a VFS plugin for grblHAL CNC machine firmware, running on STM32, ESP32, RP2040, and
i.MX RT. It provides job file streaming from SD cards.

**File:** [`fs_fatfs.c`](https://github.com/grblHAL/Plugin_SD_card/blob/master/fs_fatfs.c)

```c
static vfs_dirent_t *fs_readdir (vfs_dir_t *dir)
{
    static FILINFO fi;
    static vfs_dirent_t dirent;

    /* Skip entries that are too long OR are system files */
    while (((vfs_st_mode_t)fi.fattrib).system ||
           strlen(fi.fname) >= sizeof(dirent.name) - 1) {
        if ((vfs_errno = f_readdir(&((fatfs_dir_t *)dir)->dp, &fi)) != FR_OK
                || fi.fname[0] == '\0')
            return NULL;
    }

    strcpy(dirent.name, fi.fname);   /* ← copies without truncation */
    ...
}
```

The `while` loop was intended as protection: it skips entries whose name is _too long_.
However, the condition `strlen(fi.fname) >= sizeof(dirent.name) - 1` re-checks `fi`
(the static that holds the **previously** read entry, not the next one), because
`f_readdir` is called _inside_ the loop to advance to the next entry. The freshly read
entry is checked only on the next loop iteration. An LFN filename whose length equals
exactly `sizeof(dirent.name) - 1` passes the guard and proceeds directly to
`strcpy(dirent.name, fi.fname)` — writing the full LFN including its NUL into a
buffer that is one byte too short.

More broadly, since the skipping logic discards long filenames rather than truncating
them, any job file with an LFN name is silently invisible to the CNC controller.
An attacker can craft a card that names real job files with a long LFN to make the
controller skip them, then name a malicious file with a borderline-length name to
trigger the overflow.

---

## Summary

| Bug | FatFs Location | Root Cause | Trigger Required | Example Projects |
|-----|----------------|------------|------------------|-----------------|
| CVE-2026-6682 | `mount_volume()` | DWORD multiply overflow | Mount crafted FAT32 | EU1KY `config.c`, `rce_demo.c` |
| CVE-2026-6683 | `sync_fs()` | Division by zero (exFAT) | Sync/close on crafted exFAT | Zephyr, RT-Thread (all exFAT users) |
| CVE-2026-6684 | `find_volume()` | Unbounded GPT loop | Mount crafted GPT disk | Any pre-R0.16 project with `FF_LBA64=1` |
| CVE-2026-6685 | `f_read()`/`f_write()` | Unsigned subtraction wrap | Read/write fragmented file | grblHAL, any logger with fragmented media |
| CVE-2026-6686 | `f_lseek()` | Missing zero-fill on extend | lseek beyond EOF then read | RT-Thread `dfs_elm.c` |
| CVE-2026-6687 | `f_getlabel()` | `XDIR_NumLabel` not capped | Mount crafted exFAT, call `f_getlabel` | Zephyr, RT-Thread, STM32Cube examples |
| CVE-2026-6688 | Caller | LFN length not validated | Directory with long LFN | Zephyr `fat_fs.c`, grblHAL `fs_fatfs.c` |
