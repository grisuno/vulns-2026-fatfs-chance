# ELM FatFs Vulnerability Research

This repository documents seven confirmed security vulnerabilities in
[FatFs](https://elm-chan.org/fsw/ff/) along with a test harness, fuzzer,
and standalone exploit disk-image generator. 

The original FatFs source code can be found in the [FatFs-R0.16](FatFs-R0.16) directory.

This project is a return to a security assessment from 2017, when a manual audit
and multi-day fuzzing effort identified some basic, but not interesting bugs in the
FatFs driver. Nine years later, in March of 2026, we revisited this project using
Visual Studio Code, GitHub Copilot in "auto" mode, and some basic prompts, without
any specific loops, harnesses, or skills. The results were surprising - bugs that 
were overlooked during the manual audit became trivial to find, by using the LLM
to automatically build a fuzzer with novel inputs. Not only did this effort find
interesting bugs, it also automated the process of validating exploitable across
different embedded developent scenarios.

Please see the following files for detailed notes:

* [00_INITIAL.md](00_INITIAL.md): Initial investigation and findings
* [01_PROJECTS.md](01_PROJECTS.md): Project enumeration and FatFs version survey
* [02_CRITICAL.md](02_CRITICAL.md): Analysis of highest-impact projects

## What is FatFs?

FatFs is a portable, royalty-free FAT/exFAT filesystem library written in C by
ChaN (elm-chan.org).  It is designed for resource-constrained embedded systems
with no OS dependency and is typically compiled directly into firmware.  It
supports FAT12, FAT16, FAT32, and exFAT, as well as optional LFN (Long File
Name) and GPT partition support.

Because FatFs is small, self-contained, and permissively licensed, it has
become the de-facto standard FAT implementation for microcontroller firmware.
The library is vendored verbatim into official SDKs, RTOSes, bootloaders, and
application frameworks - meaning a single upstream vulnerability propagates to
every downstream project that copied `ff.c`.

## Major Projects

The following projects have been confirmed to bundle a vulnerable version of
FatFs.  See [02_CRITICAL.md](02_CRITICAL.md) for the complete analysis, per-project
propagation paths, and security contact information.

| Project | Stars | FatFs Version | Bugs |
|---------|-------|--------------|------|
| [espressif/esp-idf](https://github.com/espressif/esp-idf) | 17,655 | R0.16 | CVE-2026-6682, CVE-2026-6685 |
| [STMicroelectronics/stm32-mw-fatfs](https://github.com/STMicroelectronics/stm32-mw-fatfs) | all STM32Cube | R0.15 w/p2 | CVE-2026-6682, CVE-2026-6683, CVE-2026-6685, CVE-2026-6686, CVE-2026-6687 |
| [zephyrproject-rtos/zephyr](https://github.com/zephyrproject-rtos/zephyr) | 14,820 | R0.16 | CVE-2026-6683, CVE-2026-6685, CVE-2026-6687, CVE-2026-6688 |
| [micropython/micropython](https://github.com/micropython/micropython) | 21,583 | R0.13c (2019) | CVE-2026-6682 through CVE-2026-6687 |
| [ArduPilot/ardupilot](https://github.com/ArduPilot/ardupilot) | 14,743 | R0.14b | CVE-2026-6682, CVE-2026-6683, CVE-2026-6685, CVE-2026-6686, CVE-2026-6687 |
| [RT-Thread/rt-thread](https://github.com/RT-Thread/rt-thread) | 11,862 | R0.16 | CVE-2026-6683, CVE-2026-6685, CVE-2026-6686 |
| [nodemcu/nodemcu-firmware](https://github.com/nodemcu/nodemcu-firmware) | 7,903 | varies | CVE-2026-6688 |
| [RIOT-OS/RIOT](https://github.com/RIOT-OS/RIOT) | 5,701 | R0.15 | CVE-2026-6682, CVE-2026-6683, CVE-2026-6685, CVE-2026-6686, CVE-2026-6687 |
| [ARMmbed/mbed-os](https://github.com/ARMmbed/mbed-os) | 4,837 | R0.14b | CVE-2026-6682, CVE-2026-6683, CVE-2026-6685, CVE-2026-6686 |
| [sbabic/swupdate](https://github.com/sbabic/swupdate) | 1,780 | R0.16 | CVE-2026-6683 |
| [rsta2/circle](https://github.com/rsta2/circle) | 2,222 | tbd | CVE-2026-6684 |
| [hugen79/NanoVNA-H](https://github.com/hugen79/NanoVNA-H) | 695 | R0.15 | CVE-2026-6683 |
| [ChibiOS/ChibiOS](https://github.com/ChibiOS/ChibiOS) | 833 | varies | CVE-2026-6688 |
| [Samsung/TizenRT](https://github.com/Samsung/TizenRT) | 643 | R0.16 | CVE-2026-6683, CVE-2026-6688 |
| [adafruit/tinyuf2](https://github.com/adafruit/tinyuf2) | 447 | tbd | CVE-2026-6684, CVE-2026-6686 |
| [grblHAL/Plugin_SD_card](https://github.com/grblHAL/Plugin_SD_card) | 475 | R0.16 | CVE-2026-6685, CVE-2026-6688 |
| [JcZou/StarryPilot](https://github.com/JcZou/StarryPilot) | 315 | R0.16 | CVE-2026-6688 |
| [KeystoneHQ/keystone3-firmware](https://github.com/KeystoneHQ/keystone3-firmware) | 199 | R0.16 | CVE-2026-6682 |
| [flysight/flysight](https://github.com/flysight/flysight) | 44 | varies | CVE-2026-6682, CVE-2026-6688 |
| [eugene-tarassov/vivado-risc-v](https://github.com/eugene-tarassov/vivado-risc-v) | 1,061 | tbd | CVE-2026-6684 |


## CVE Summary

| CVE ID | Short Title | CWE |
|--------|-------------|-----|
| CVE-2026-6682 | Integer Overflow in FAT32 Volume Mount | [CWE-190: Integer Overflow or Wraparound](https://cwe.mitre.org/data/definitions/190.html) |
| CVE-2026-6683 | Divide-by-Zero in exFAT Sync | [CWE-369: Divide By Zero](https://cwe.mitre.org/data/definitions/369.html) |
| CVE-2026-6684 | Infinite Loop in GPT Partition Scan | [CWE-835: Loop with Unreachable Exit Condition](https://cwe.mitre.org/data/definitions/835.html) |
| CVE-2026-6685 | Integer Underflow in Dirty-Sector Cache Flush | [CWE-191: Integer Underflow](https://cwe.mitre.org/data/definitions/191.html) |
| CVE-2026-6686 | Use of Uninitialized Clusters After Seek Past EOF | [CWE-908: Use of Uninitialized Resource](https://cwe.mitre.org/data/definitions/908.html) |
| CVE-2026-6687 | Stack Buffer Overflow via Uncapped exFAT Label Length | [CWE-121: Stack-based Buffer Overflow](https://cwe.mitre.org/data/definitions/121.html) |
| CVE-2026-6688 | Buffer Overflow via Unbounded LFN Filename Copy | [CWE-120: Buffer Copy without Checking Size of Input](https://cwe.mitre.org/data/definitions/120.html) |

## Attacker Value

FatFs has no CVE history, no security mailing list, and no patch notification
mechanism.  Every downstream project that vendors `ff.c` must discover, triage,
and patch these vulnerabilities independently, usually without knowing they are
affected.  That means the window between public disclosure and widespread
remediation will be measured in years, not days.  The practical attack surface
is therefore not one software application or serbvice, but tens of millions of
devices across dozens of independent codebases, many of which will never receive
a patch.

The archetypal exploitation scenario is the **evil SD card**: an attacker with a
few seconds of physical access swaps the storage medium in a device, from
consumer cameras to drones, to 3-D printers to a thousand other product
families. Every vulnerability in this set is triggerable by mounting a crafted
FAT image, which nearly always happens automatically on insertion with no user
interaction required. That said, physical access is not the only path.

Devices that ingest FAT-formatted update packages from a network source such as
OTA update frameworks and drag-and-drop bootloader updates, are exploitable by
any attacker who can deliver a malicious image to the update pipeline. Supply
chain compromises, an AitM injection on a cleartext HTTP update feed, or a
malicious image posted to a hobby firmware distribution portal. The OTA path is
fully remote on any device that lacks end-to-end authenticated integrity
verification of its update container *prior* to mounting it with FatFs.

### Attacker Value by CVE

**CVE-2026-6682 - Integer overflow leading to attacker-controlled read length**

By crafting a FAT32 volume with a specific field set to overflow, an attacker can cause
a victim device to read an attacker-chosen number of attacker-chosen bytes into a fixed
buffer - a direct path to code execution. On bare-metal embedded targets the exploit is
deterministic and requires no heap spray, no brute force, and no information leak as a
prerequisite.

The attacker needs control of the FAT volume the target will mount. For most devices
that means physical access to swap an SD card. Devices that accept firmware updates
over a network, or that trust the integrity of an update package only after FatFs has
already parsed it, are exploitable remotely.

**CVE-2026-6683 - Divide-by-zero in exFAT sync**

An attacker who can deliver a crafted exFAT volume to a device running pre-R0.16 FatFs
can guarantee a crash on any subsequent write. FatFs R0.16 added a partial mount-time
guard that may reject the crafted volume before a write occurs, but the underlying
arithmetic defect is not fully fixed. Against devices that apply OTA firmware updates
by writing to a FAT-formatted medium, a successful trigger becomes a one-shot remote
brick: the update process crashes mid-write and the device may be unrecoverable without
physical access to a hardware debugger.

The attacker needs the target to mount an exFAT volume they control and then perform
any write or sync operation. The evil-SD-card scenario covers most embedded devices;
for remote exploitation the target's OTA pipeline must accept and mount an
attacker-supplied image without first verifying its integrity.

**CVE-2026-6684 - Infinite loop in GPT partition scan**

Delivering a GPT disk image with a single field set to its maximum value causes the
target to loop reading disk sectors until power is removed. Against bootloaders and
bare-metal firmware that run without a watchdog, this is a permanent brick: the device
never completes boot again. This vulnerability is fixed in FatFs R0.16, so it only
affects devices that vendor an older release.

The attacker needs the target to mount a GPT-formatted disk they control, and the
target must be running a pre-R0.16 FatFs build with 64-bit LBA support enabled. Note
that bootloaders are the most attractive targets here precisely because they tend to
have no watchdog and no recovery path.

**CVE-2026-6685 - Integer underflow → out-of-bounds write on fragmented volumes**

By formatting a storage medium so that file clusters are not laid out in order, an
attacker can cause an out-of-bounds memory write during normal file I/O. The written
data is attacker-controlled if the attacker also controls the medium. On bare-metal
targets without memory protection this write is silent - no error, no crash, no log
entry - and corruption only surfaces as misbehavior later. On targets with an MMU the
out-of-bounds write may instead trigger a fault, making the bug visible but still
denying service.

The attacker needs to control the layout of a FAT volume the target mounts and then get
the target to perform interleaved reads and writes on a file stored on that volume. On
long-running devices the fragmentation condition can also arise naturally over time,
making this exploitable without any special filesystem preparation.

**CVE-2026-6686 - Stale cluster data readable after seek past EOF**

When a file is extended by seeking past its end, FatFs does not zero the newly
allocated storage. Any data previously written to those sectors by a deleted file is
readable by the next process that opens the extended file. On devices that cycle through
firmware images in an OTA staging area, or that share an SD card between a bootloader
and an application, this can expose previous firmware blobs, keys, or other sensitive
content to a less-privileged reader.

The attacker needs read access to a file on the target's FAT volume that was extended
via a seek operation. This is primarily a local or physical-access scenario.

**CVE-2026-6687 - Stack overflow via exFAT volume label**

Supplying an exFAT volume with an oversized label causes FatFs to overflow the caller's
label buffer when the application calls `f_getlabel()`. ST's STM32CubeMX code generator
emits the vulnerable buffer size in every FatFs-enabled project it produces, which
means this vulnerability exists in an enormous and largely uncatalogued population of
commercial STM32 firmware. On bare-metal Cortex-M devices without stack cookies or
ASLR (the common case) this is a one-shot code execution primitive.

The attacker needs the target to mount an exFAT volume they control and then call
`f_getlabel()`. The FatFs library does not call this internally - the application must
call it explicitly. Most projects do so as part of their own mount-time initialization,
requiring no further attacker interaction in practice for those projects.

**CVE-2026-6688 - Buffer overflow via long LFN filename in directory listing**

By placing a file with a long name in a FAT directory, an attacker can overflow the
buffer a calling application uses to store that name when iterating the directory. The
overflow is proportional to the filename length, up to 255 bytes. This vulnerability
is in calling code, not in FatFs itself, so impact varies by target - but any
application that iterates a directory and copies filenames into a fixed-size buffer
without checking the length is affected.

The attacker needs the target to traverse a directory on a FAT volume they control. No
exFAT required; this works on FAT12, FAT16, and FAT32. Long filename support must be
enabled in the FatFs config, which is the default and recommended setting in every
major distribution.

## Vulnerability Details

Seven distinct bugs were identified in FatFs R0.16 and earlier versions.

### CVE-2026-6682 - FAT32 integer overflow in `mount_volume()` → attacker-controlled `finfo.fsize`

**Location:** `ff.c` `mount_volume()` - `fasize *= fs->n_fats`

A DWORD multiply overflow occurs when `BPB_FATSz32` is crafted to produce a
large value.  With `BPB_FATSz32 = 0x80000001` and `NumFATs = 2`:

```c
fasize = 0x80000001;
fasize *= 2;          // DWORD overflow → 0x00000002
```

The truncated `fasize` causes `fs->database` (the start of the data area) to
land inside the FAT region.  An attacker who controls the disk image can place
a fake directory entry at the overlapping sector, causing `f_stat()` to return
an attacker-controlled `finfo.fsize`.  Any application that then calls
`f_read(fp, buf, finfo.fsize, &br)` without bounding the count against
`sizeof(buf)` overflows the destination buffer with fully attacker-controlled
bytes - a direct path to RCE.

**Worst-case impact:** Remote code execution (heap or stack overflow) on any
embedded device that reads a file size from FatFs and uses it as a read length.

---

### CVE-2026-6683 - Division-by-zero in `sync_fs()` (exFAT)

**Location:** `ff.c` `sync_fs()` - `(n_fatent - 2 - free_clst) * 100 / (n_fatent - 2)`

When `BPB_NumClusEx = 0`, `n_fatent = 2`, making the divisor `(n_fatent - 2) = 0`.
This is reached on any write or sync operation to a crafted exFAT volume,
producing a SIGFPE / hard-fault and crashing the target.

FatFs R0.16 partially guards against this at mount time (bitmap-cluster
validation fails when `NumClusEx = 0`).  Older versions - R0.14b (ArduPilot,
Mbed OS), R0.15 (RIOT OS, STM32), R0.13c (MicroPython) - have no such guard
and crash unconditionally.

**Worst-case impact:** Denial of service / system crash on any write to a
crafted exFAT volume.  During an OTA update this can brick the device.

---

### CVE-2026-6684 - Unbounded GPT partition scan loop in `find_volume()` (pre-R0.16)

**Location:** `ff.c` `find_volume()` - `for (i = 0; i < n_ent; i++) disk_read()`

When `FF_LBA64 = 1`, `find_volume()` iterates over every GPT partition entry
to search for an FAT partition.  In pre-R0.16 builds the loop count is taken
directly from the on-disk `GPTH_PtNum` field (0–0xFFFFFFFF) with no upper
bound.  A crafted GPT image with `GPTH_PtNum = 0xFFFFFFFF` causes approximately
one billion disk reads before the function returns "not found", hanging the
system permanently.

R0.16 introduced `test_gpt_header()` which validates the CRC32 and enforces
`PtNum ≤ 128` before entering the loop.

**Worst-case impact:** Permanent mount-time denial of service.  On devices
without a watchdog (bootloaders, bare-metal FPGA bootrom) this permanently
bricks the system.

---

### CVE-2026-6685 - Stale dirty-cache skip via unsigned-subtraction wrap in `f_read()` / `f_write()`

**Location:** `ff.c` lines ~4055, ~4171:

```c
if ((fp->flag & FA_DIRTY) && fp->sect - sect < cc) {
    memcpy(rbuff + ((fp->sect - sect) * SS(fs)), fp->buf, SS(fs));
}
```

When `fp->sect < sect` (the cached sector is numerically before the current
read window, which occurs on fragmented volumes where cluster N+1 maps to a
lower-numbered sector than cluster N), the subtraction wraps to a value near
`2^32`.  The huge value may still satisfy `< cc` when `cc` is large, causing
the `memcpy` to fire at an out-of-bounds offset and writing stale cached data
far outside `rbuff`.

**Worst-case impact:** Silent data corruption on fragmented FAT volumes with
interleaved reads and writes; out-of-bounds heap/stack write.

---

### CVE-2026-6686 - Uninitialized cluster data via `f_lseek()` beyond EOF

**Location:** `ff.c` `f_lseek()`:

```c
if (!FF_FS_READONLY && fp->fptr > fp->obj.objsize) {
    fp->obj.objsize = fp->fptr;   // extend, but never zero-fill
    fp->flag |= FA_MODIFIED;
}
```

Seeking past EOF calls `create_chain()` to allocate new clusters but never
zeroes their sectors.  Any subsequent read of the extended region returns raw
stale data - content from previously deleted files remaining in the recycled
cluster.

**Worst-case impact:** Information disclosure of deleted file content (old
firmware images, private keys, sensor data) to a less-privileged reader or
over a connected interface.

---

### CVE-2026-6687 - Stack buffer overflow in `f_getlabel()` via exFAT `XDIR_NumLabel`

**Location:** `ff.c` `f_getlabel()`:

```c
for (si = di = hs = 0; si < dj.dir[XDIR_NumLabel]; si++) {
    wc = ld_16(dj.dir + XDIR_Label + si * 2);
    nw = put_utf((DWORD)hs << 16 | wc, &label[di], 4);
    di += nw;
}
```

The exFAT specification limits `XDIR_NumLabel` to 11 characters.  FatFs reads
this as a raw `BYTE` (0–255) with no validation.  A crafted volume with
`XDIR_NumLabel = 128` causes `f_getlabel` to write 128 characters into the
caller's buffer - typically `char label[12]` or `char label[24]` as generated
by STM32CubeMX - overflowing the stack by up to 244 bytes.

**Worst-case impact:** Stack buffer overflow in any caller of `f_getlabel()` on
an exFAT volume.  The canonical vulnerable pattern (`char label[12]`) appears
in every project generated by STM32CubeMX, AN3224, and UM1721.

---

### CVE-2026-6688 - Caller stack/heap overflow via long LFN filename

**Root cause:** With `FF_USE_LFN` enabled, `f_readdir()` fills `fno.fname` with
the full Long File Name - up to `FF_LFN_BUF` (255) characters.  Callers
written for SFN-only operation use fixed-size path or name buffers (e.g.,
`char path[16]`, `char name[14]`) and copy `fno.fname` without bounds
checking.

Common vulnerable patterns found across multiple projects:

```c
strcpy(entry->name, fno.fname);          // Zephyr: entry->name[14]
sprintf(path, "0:/%s", fno.fname);       // NodeMCU, ChibiOS demo, StarryPilot
sprintf(&cur_path[n], "/%s", fn);        // Samsung TizenRT
```

**Worst-case impact:** Stack or heap overflow proportional to the LFN length
(up to 255 bytes) on any directory traversal over a crafted FAT volume.  A
crafted SD card that overflows `entry->name[14]` by 241 bytes reliably corrupts
the Zephyr scheduler stack frame.

---

## Repository Layout

```
├── harness/                 Security test harness and exploit tools
│   ├── Makefile             Build system (see targets below)
│   ├── test_ffconf.h        FatFs config for the harness (LFN+exFAT+LBA64)
│   ├── diskio_ramdisk.c/h   In-memory block device (2 MiB RAM disk)
│   ├── ffunicode_stub.c     Minimal Unicode stub (CP437 pass-through)
│   ├── test_harness.c       Deterministic per-bug test suite (CVE-2026-6682 through CVE-2026-6688)
│   ├── rce_demo.c           Standalone CVE-2026-6682 RCE demo: OTA struct-pointer overwrite
│   ├── libfuzzer_harness.c  libFuzzer / AFL++ entry point
│   ├── exploit_disks.c      Standalone disk-image generator (see below)
│   ├── build/               Compiled binaries
│   └── img/                 Generated exploit disk images (*.img)
│
├── fuzzer/                  Go corpus generator and structural fuzzer
│   ├── main.go              Corpus builder + Go native fuzz targets
│   ├── fat_image.go         FAT12/16/32/exFAT/GPT image construction helpers
│   └── corpus/              Seed corpus written by `make corpus`
```

---

## Harness Build Targets

All targets are run from the `harness/` directory.  Requires `clang` (or set `CC=gcc`).

To build the `afl` target on macOS, use `brew install afl++` and then `sudo afl-system-config` to prepare your system.

| Target | Description |
|--------|-------------|
| `make` / `make test` | Build and run the deterministic test suite with ASan + UBSan |
| `make rce_demo` | Build and run the CVE-2026-6682 RCE demo (no sanitisers, no stack-protector) |
| `make exploit_disks` | Build and generate all 14 exploit disk images into `harness/img/` |
| `make fuzz_asan` | Build the libFuzzer binary (`build/fuzz_fatfs`) |
| `make afl` | Build the AFL++ target (requires `afl-clang-fast` in `PATH`) |
| `make corpus` | Generate seed corpus via the Go generator into `harness/corpus/` |
| `make clean` | Remove `build/` and `img/` |

### Quick start

```sh
# Run the full deterministic test suite
cd harness && make

# Run the CVE-2026-6682 RCE demo
make rce_demo

# Generate all exploit disk images
make exploit_disks

# Fuzz with libFuzzer (requires clang)
make fuzz_asan
build/fuzz_fatfs -max_len=2097152 corpus/

# Fuzz with AFL++
make corpus afl
afl-fuzz -i corpus/ -o findings/ -- build/afl_fatfs @@
```

---

## Exploit Disk Images

`make exploit_disks` produces 14 raw disk images in `harness/img/`, one per
project/vulnerability combination.  Each image is self-tested at generation
time by mounting it with the bundled FatFs.  Images can be written to a
physical SD card:

```sh
dd if=harness/img/exploit_bug1_espidf.img of=/dev/sdX bs=512
```

| Image | Bug | Target project(s) | Effect |
|-------|-----|------------------|--------|
| `exploit_bug1_fat32.img` | CVE-2026-6682 | Generic | Delivers pointer-sized payload via `f_read` |
| `exploit_bug1_espidf.img` | CVE-2026-6682 | espressif/esp-idf | `finfo.fsize=16 MB` → `malloc`/`fread` heap overflow |
| `exploit_bug1_stm32.img` | CVE-2026-6682 | STMicro stm32-mw-fatfs | `finfo.fsize=1 MB` → 1 KB firmware buffer overflow |
| `exploit_bug1_keystone3.img` | CVE-2026-6682 | KeystoneHQ wallet | `finfo.fsize=512 KB` → OTA buffer overflow |
| `exploit_bug1_ardupilot.img` | CVE-2026-6682 | ArduPilot / Mbed OS / RIOT / MicroPython | `finfo.fsize=2 MB` → log-read buffer overflow |
| `exploit_bug2_exfat.img` | CVE-2026-6683 | ArduPilot / Mbed OS / MicroPython / RIOT | `BPB_NumClusEx=0` → `sync_fs` divide-by-zero (SIGFPE on pre-R0.16) |
| `exploit_bug3_gpt.img` | CVE-2026-6684 | vivado-risc-v / tinyuf2 / circle | `GPTH_PtNum=0xFFFFFFFF` → infinite loop at boot (pre-R0.16) |
| `exploit_bug4_fragmented.img` | CVE-2026-6685 | esp-idf / ArduPilot / Zephyr / RT-Thread / grblHAL | Reversed FAT chain triggers dirty-cache underflow |
| `exploit_bug5_stale.img` | CVE-2026-6686 | RT-Thread / tinyuf2 / ArduPilot / RIOT | `f_lseek` extension exposes `0xAA`-seeded deleted-cluster data |
| `exploit_bug6_stm32.img` | CVE-2026-6687 | STMicro stm32-mw-fatfs | `XDIR_NumLabel=128` → 117-byte overflow of CubeMX `label[12]` |
| `exploit_bug6_zephyr.img` | CVE-2026-6687 | Zephyr / ArduPilot / RIOT / MicroPython | `XDIR_NumLabel=255` → 216-byte overflow of `label[24]` |
| `exploit_bug7_max255.img` | CVE-2026-6688 | NodeMCU / ChibiOS / StarryPilot / TizenRT | 255-char LFN overflows any fixed buf < 255 bytes |
| `exploit_bug7_zephyr.img` | CVE-2026-6688 | Zephyr | 14-char LFN → 1-byte NUL overflow of `entry->name[14]` |
| `exploit_bug7_grblhal.img` | CVE-2026-6688 | grblHAL | Off-by-one: guard checks previous entry; 11-char LFN overflows `dirent.name[12]` by 1 NUL byte |

---

## Deterministic Test Suite (`test_harness.c`)

The test harness exercises all seven bugs with hand-crafted disk images built
in memory, then confirms the vulnerable code path was reached:

- **CVE-2026-6682** - builds a `BPB_FATSz32=0x80000001` FAT32 image, mounts it, and
  confirms `fs.database` falls inside the FAT region; then executes the full
  RCE chain (fake directory entry → `f_read` of planted function pointer →
  `rce_proof_of_execution()` called).
- **CVE-2026-6683** - documents the `(n_fatent-2)` divisor and confirms the arithmetic
  path; checks that R0.16 rejects the image at mount time.
- **CVE-2026-6684** - builds a `GPTH_PtNum=0xFFFFFFFF` GPT image and confirms that
  R0.16 rejects it within ≤ 3 disk reads via `test_gpt_header()`.
- **CVE-2026-6685** - evaluates the unsigned-subtract arithmetic with a concrete
  `(fp_sect=50, sect=200, cc=0xFFFFFFDF)` triple and demonstrates the guard
  evaluates `TRUE` (wrong) for an out-of-range cached sector.
- **CVE-2026-6686** - pre-seeds all data clusters with `0xAA`, writes a short file,
  extends it via `f_lseek`, and reads back to confirm stale bytes are visible.
- **CVE-2026-6687** - builds an exFAT image with `XDIR_NumLabel=128`, calls
  `f_getlabel` into a probe buffer, and counts the overflow past byte 24.
- **CVE-2026-6688** - constructs a FAT16 directory with a 50-char LFN, reads it via
  `f_readdir`, and confirms `fno.fname` length exceeds typical caller buffers.

---

## CVE-2026-6682 RCE Demo (`rce_demo.c`)

A self-contained, realistic demonstration of the CVE-2026-6682 exploitation chain
modelled on embedded OTA firmware-update code.  A struct is declared with a
fixed-size header buffer followed immediately by a function-pointer callback:

```c
typedef struct {
    uint8_t  fw_header[128];   // buffer the developer reads into
    uint32_t crc32;
    uint32_t version;
    void   (*on_apply)(void);  // callback - attacker target
} ota_ctx_t;
```

The demo builds a crafted disk image where `DIR_FileSize = sizeof(ota_ctx_t)`,
plants the address of `rce_win()` at the correct byte offset in the payload
sector, then runs the OTA checker.  `f_read` writes past `fw_header` into
`on_apply`, and the subsequent `ctx.on_apply()` call invokes `rce_win()`,
setting `rce_canary = 0xDEAD`.

Build and run: `cd harness && make rce_demo`

---

## Fuzzer (`fuzzer/`)

The Go fuzzer has two modes:

1. **Corpus generator** (`go run . -out ./corpus` or `make corpus`): writes 18
   structured seed images covering all seven bug classes, all three FAT
   variants, normal and malformed GPT, and 50 random single-byte mutations of a
   valid FAT32 image.

2. **Go native fuzzer** (`go test -fuzz=FuzzFAT32BPB`): structural fuzzing of
   BPB field values with Go's built-in fuzzer; validates that field
   relationships hold without calling into C.

The seed corpus feeds both the libFuzzer binary (`build/fuzz_fatfs`) and the
AFL++ target (`build/afl_fatfs`).

## ESP-IDF via QEMU

This repo includes a self-contained Docker test case that demonstrates an
ESP32-relevant CVE-2026-6688 caller overflow pattern using FatFs directory
traversal on ESP-IDF firmware inside the Espressif QEMU ESP32 emulator.

The current PoC image is intentionally hybrid:

- It keeps the CVE-2026-6682-style crafted FAT32 geometry so the forged root
  directory is reliably controlled.
- It embeds a long VFAT filename that is returned by `readdir()`.
- The application then mirrors public ESP32 code patterns (`strcpy` / `strcat`
  path assembly) and copies the long filename into a fixed 32-byte buffer.

That final copy is the CVE-2026-6688-style condition: caller-side overflow via
unbounded use of long filenames.

```
cd esp32-qemu-test
./run.sh
```

Or alternatively:
```
docker build -t fatfs-esp32-vuln-test esp32-qemu-test/
docker run --rm fatfs-esp32-vuln-test
```

### Why this maps to CVE-2026-6688

`f_readdir()` can return long names (LFN) up to 255 characters. Many real
embedded callers still copy names into smaller fixed buffers. Public ESP32
examples include patterns equivalent to:

```
strcpy(fn, entry->d_name);
strcat(path, "/");
strcat(path, entry->d_name);
```

With a crafted FAT image containing a long filename, these copies overflow the
caller buffer.

### PoC chain in this repo

| Step | Description | Marker |
|------|-------------|--------|
| 1 | Crafted storage image mounts and returns attacker-controlled directory entries | (mount succeeds) |
| 2 | Long filename is copied into `char name[32]` via public-pattern unsafe copy path | `[VULN-BUG7-CONFIRMED]` |
| 3 | Guard corruption is logged, followed by control-data crash in QEMU | `guard=0x61616161`, `Guru Meditation Error` |

The PoC still retains a legacy CVE-2026-6682-style OTA callback overwrite path
for context and marker output (`PWNED-UART`), but the bug-specific proof here
is the long-filename caller overflow marker above.

Representative output:

```
I (...) fatfs_vuln: PoC: CVE-2026-6688 long-LFN caller overflow probe (ESP32 public-pattern copy path)
...
PWNED-UART
E (...) fatfs_vuln: [VULN-BUG7-CONFIRMED] guard corrupted after filename copy
E (...) fatfs_vuln: entry='esp32_lfn_trigger_aaaa...aaaa.bin' len=78 guard=0x61616161
Guru Meditation Error: Core  0 panic'ed (...)
```
