# FatFs: Affected Projects

This document describes some of the open-source projects found via GitHub code search that contain 
potentially vulnerable code patterns.

All searches were performed with `gh search code` against public repositories in March 2026.

---

## CVE-2026-6682 — FAT32 Integer Overflow in `mount_volume()` (`finfo.fsize` trusted as read length)

The dangerous pattern is:

```c
FILINFO finfo;
f_stat("0:/something", &finfo);
f_read(&fp, buffer, finfo.fsize, &br);   // ← finfo.fsize attacker-controlled under CVE-2026-6682
```

Under CVE-2026-6682, `finfo.fsize` is read from the FAT area (not the directory entry), making
it fully attacker-controlled.  Any caller that passes `finfo.fsize` / `fno.fsize`
directly as the count to `f_read` into a fixed-size or heap buffer is vulnerable
to a heap/stack overwrite and potential code execution.

---

### CVE-2026-6682-W1 — EU1KY Antenna Analyzer H745 port (STM32H745I)

| Field | Value |
|-------|-------|
| **Repository** | [EU1KY/eu1ky_aa_v3_h745](https://github.com/EU1KY/eu1ky_aa_v3_h745) |
| **Vulnerable file** | [src/cm7/src/analyzer/window/screenshot.c](https://github.com/EU1KY/eu1ky_aa_v3_h745/blob/master/src/cm7/src/analyzer/window/screenshot.c) |
| **Maintainer** | EU1KY (Yury K.) |
| **Contact** | kuchura@gmail.com (from GitHub profile) |
| **Last pushed** | 2023-12-19 |

**Description:** Reads a PNG logo from SD card directly into a heap buffer whose size
is bounded only by `finfo.fsize`.  Under CVE-2026-6682, `finfo.fsize` can be set arbitrarily
large by a crafted SD card.

```c
f_read(&flogo, pngbuf, finfo.fsize, &br);   // ← finfo.fsize not bounded
```

---

### CVE-2026-6682-W2 — phdlee Antenna Analyzer (STM32 port of EU1KY)

| Field | Value |
|-------|-------|
| **Repository** | [phdlee/antennaanalyzer](https://github.com/phdlee/antennaanalyzer) |
| **Vulnerable file** | [Src/analyzer/config/config.c](https://github.com/phdlee/antennaanalyzer/blob/master/Src/analyzer/config/config.c) |
| **Maintainer** | phdlee |
| **Contact** | GitHub issues (no public email) |
| **Last pushed** | active |

**Description:** Same EU1KY codebase re-homed.  `f_read(&fo, g_cfg_array, finfo.fsize, &br)` with
a guard that is bypassable — attacker sets `finfo.fsize = sizeof(g_cfg_array) - 1`.

---

### CVE-2026-6682-W3 — FDS Key (Famicom Disk System emulator, STM32)

| Field | Value |
|-------|-------|
| **Repository** | [ClusterM/fdskey](https://github.com/ClusterM/fdskey) |
| **Vulnerable file** | [FdsKey/Core/Src/blupdater.c](https://github.com/ClusterM/fdskey/blob/master/FdsKey/Core/Src/blupdater.c) |
| **Maintainer** | Alexey "Cluster" Diatchenko |
| **Contact** | cluster@cluster.wtf · https://cluster.wtf |
| **Last pushed** | 2024-12-11 |

**Description:** Bootloader updater reads firmware from SD card with `malloc(fno.fsize + FLASH_PAGE_SIZE)`
then writes into the allocation via repeated `f_read` calls.  If `fno.fsize` is spoofed
to a very large value by CVE-2026-6682, the `malloc` returns or the subsequent read overflows the
allocated region.

```c
bootloader_data = malloc(fno.fsize + FLASH_PAGE_SIZE);
fr = f_read(&fp, bootloader_data + pos, FLASH_PAGE_SIZE, &br);
```

---

### CVE-2026-6682-W4 — Keystone 3 Hardware Wallet Firmware

| Field | Value |
|-------|-------|
| **Repository** | [KeystoneHQ/keystone3-firmware](https://github.com/KeystoneHQ/keystone3-firmware) |
| **Vulnerable file** | [src/user_fatfs.c](https://github.com/KeystoneHQ/keystone3-firmware/blob/main/src/user_fatfs.c) |
| **Maintainer** | KeystoneHQ (hardware wallet company) |
| **Contact** | eng@keyst.one · https://keyst.one/ |
| **Last pushed** | 2026-03-27 (active) |

**Description:** FatFs is used in a hardware cryptocurrency wallet to read firmware
updates from SD card.  `Finfo.fsize` is accumulated and used to size read operations.
Under CVE-2026-6682, an attacker with physical access who can swap the SD card can corrupt
the update buffer and potentially overwrite security-critical memory.

---

### CVE-2026-6682-W5 — Sipeed M1s BL808 SDK

| Field | Value |
|-------|-------|
| **Repository** | [sipeed/M1s_BL808_SDK](https://github.com/sipeed/M1s_BL808_SDK) |
| **Vulnerable file** | [components/sipeed/e907/m1s_msc/src/m1s_msc.c](https://github.com/sipeed/M1s_BL808_SDK/blob/main/components/sipeed/e907/m1s_msc/src/m1s_msc.c) |
| **Maintainer** | Sipeed |
| **Contact** | support@sipeed.com · sipeed.com |
| **Last pushed** | 2023-02-18 |

**Description:** Reads C906 firmware blob directly using `fno.fsize` as the read length:

```c
if (FR_OK != (res = f_read(&fil, private.cache_d0fw_buff, fno.fsize, &br))) goto _exit;
```

A crafted FAT32 image with CVE-2026-6682 causes `fno.fsize` to reflect attacker-controlled data,
overflowing `cache_d0fw_buff` and potentially overwriting runtime firmware on the BL808 SoC.

---

### CVE-2026-6682-W6 — ExistOS for HP-39GII (ARM calculator OS)

| Field | Value |
|-------|-------|
| **Repository** | [ExistOS-Team/ExistOS-For-HP39GII](https://github.com/ExistOS-Team/ExistOS-For-HP39GII) |
| **Vulnerable file** | [System/gb/rom.c](https://github.com/ExistOS-Team/ExistOS-For-HP39GII/blob/master/System/gb/rom.c) |
| **Maintainer** | ExistOS-Team |
| **Contact** | GitHub org (no public email) |
| **Last pushed** | 2025-10-28 |

**Description:** Game Boy ROM loader reads an entire file into a heap buffer using
`finfo.fsize` as size:

```c
rom_size = finfo.fsize;
fres = f_read(fil, bytes, rom_size, &br);
```

With CVE-2026-6682, `finfo.fsize` / `rom_size` is fully attacker-controlled.

---

### CVE-2026-6682-W7 — mcHF SDR Transceiver Auto-Run Feature

| Field | Value |
|-------|-------|
| **Repository** | [m0nka/mcHF](https://github.com/m0nka/mcHF) |
| **Vulnerable file** | [firmware/app_proc/proc/sdcard/misc/auto_run.c](https://github.com/m0nka/mcHF/blob/master/firmware/app_proc/proc/sdcard/misc/auto_run.c) |
| **Maintainer** | Krassi Atanassov (m0nka) |
| **Contact** | GitHub issues (no public email) |
| **Last pushed** | 2026-03-22 (active) |

**Description:** Auto-run script reader passes `fno.fsize` directly to `f_read` into a
path buffer:

```c
res = f_read(&file, auto_path, fno.fsize, (void *)&read);
```

Under CVE-2026-6682 `fno.fsize` overflows the `auto_path` stack buffer, overwriting the return
address.

---

### CVE-2026-6682-W8 — Pico Peanut GB (Game Boy emulator on RP2040)

| Field | Value |
|-------|-------|
| **Repository** | [fhoedemakers/pico-peanutGB](https://github.com/fhoedemakers/pico-peanutGB) |
| **Vulnerable file** | [gb.c](https://github.com/fhoedemakers/pico-peanutGB/blob/master/gb.c) |
| **Maintainer** | Frank Hoedemakers |
| **Contact** | frank.hoedemakers@gmail.com |
| **Last pushed** | active |

**Description:** Cart RAM is loaded from SD card using `fno.fsize` as the read length with
no upper bound:

```c
if (f_read(&file, priv.cart_ram, fno.fsize, &bytesread) != FR_OK)
```

Under CVE-2026-6682, this overflows the `cart_ram` heap allocation.

---

### CVE-2026-6682-W9 — GenesisOS RISC-V OS

| Field | Value |
|-------|-------|
| **Repository** | [0xbigshaq/GenesisOS](https://github.com/0xbigshaq/GenesisOS) |
| **Vulnerable files** | [genesis/drivers/fat32.c](https://github.com/0xbigshaq/GenesisOS/blob/main/genesis/drivers/fat32.c), [genesis/drivers/gfx/bmp.c](https://github.com/0xbigshaq/GenesisOS/blob/main/genesis/drivers/gfx/bmp.c) |
| **Maintainer** | 0xbigshaq |
| **Contact** | GitHub issues |
| **Last pushed** | active |

**Description:** Two separate read sites pass `fno.fsize` directly to `f_read`, one for
general file loading and one for the BMP font loader:

```c
rc = f_read(&init_fp, init_data, fno.fsize, &br);   // fat32.c
rc = f_read(&font_fp, bmp_data, fno.fsize, &br);    // bmp.c
```

---

### CVE-2026-6682-W10 — Agon MOS (Z80 retro computer firmware)

| Field | Value |
|-------|-------|
| **Repository** | [breakintoprogram/agon-mos](https://github.com/breakintoprogram/agon-mos) |
| **Vulnerable file** | [src/mos.c](https://github.com/breakintoprogram/agon-mos/blob/main/src/mos.c) |
| **Maintainer** | Dean Belfield |
| **Contact** | http://www.breakintoprogram.co.uk/ (contact form) |
| **Last pushed** | active |

**Description:** The MOS loader reads files at a user-supplied load address with no
size limit beyond `fSize` (which comes from `fno.fsize`):

```c
fr = f_read(&fil, (void *)address, fSize, &br);
```

Under CVE-2026-6682, `fSize` can be made arbitrarily large, writing attacker data anywhere in
the Z80 SBC address space from the load address forward.

---

### CVE-2026-6682-W11 — VerilogBoy FPGA Game Boy

| Field | Value |
|-------|-------|
| **Repository** | [zephray/VerilogBoy](https://github.com/zephray/VerilogBoy) |
| **Vulnerable file** | [target/panog1/fw/firmware/firmware.c](https://github.com/zephray/VerilogBoy/blob/master/target/panog1/fw/firmware/firmware.c) |
| **Maintainer** | zephray |
| **Contact** | GitHub issues |
| **Last pushed** | 2022 |

**Description:** ROM file size is captured as `Finfo.fsize` and used directly as the
source-of-truth for how many bytes to read.

---

### CVE-2026-6682-W12 — FlySight GPS Logger

| Field | Value |
|-------|-------|
| **Repository** | [flysight/flysight](https://github.com/flysight/flysight) |
| **Vulnerable file** | [src/Main.c](https://github.com/flysight/flysight/blob/master/src/Main.c) |
| **Maintainer** | FlySight |
| **Contact** | support@flysight.ca · http://flysight.ca |
| **Last pushed** | active |

**Description:** FlySight iterates directory entries via `f_readdir`, then opens and
reads files.  All file I/O relies on FatFs `fno.fsize` for sizing decisions, making it
vulnerable to CVE-2026-6682 if a crafted SD card is inserted.

---

## CVE-2026-6683 — Division-by-Zero in `sync_fs()` (exFAT, `BPB_NumClusEx = 0`)

Any project that (a) enables `FF_FS_EXFAT = 1` in `ffconf.h` and (b) mounts a
user-supplied volume and performs any write, sync, or close is affected.
The crash is triggered by `f_close()` / `f_sync()` calling `sync_fs()` on a crafted
exFAT volume where `n_fatent - 2 == 0`.

---

### CVE-2026-6683-W1 — libdragon (Nintendo 64 SDK)

| Field | Value |
|-------|-------|
| **Repository** | [DragonMinded/libdragon](https://github.com/DragonMinded/libdragon) |
| **Vulnerable file** | [src/fatfs/ffconf.h](https://github.com/DragonMinded/libdragon/blob/trunk/src/fatfs/ffconf.h) |
| **Maintainer** | Jennifer Taylor (DragonMinded) |
| **Contact** | dragonminded@dragonminded.com · https://www.dragonminded.com |
| **Last pushed** | 2026-03-26 (active) |

**Description:** `FF_FS_EXFAT = 1` and `FF_LBA64 = 1` are both set.  libdragon is used
in thousands of homebrew N64 cartridges; a crafted SD card inserted into an ED64 or
SummerCart64 flashcart running libdragon firmware can trigger the division-by-zero DoS.

---

### CVE-2026-6683-W2 — NanoVNA-H Firmware

| Field | Value |
|-------|-------|
| **Repository** | [hugen79/NanoVNA-H](https://github.com/hugen79/NanoVNA-H) |
| **Vulnerable file** | [FatFs/ffconf_303.h](https://github.com/hugen79/NanoVNA-H/blob/master/FatFs/ffconf_303.h) |
| **Maintainer** | hugen79 |
| **Contact** | http://nanovna.com/ (forum contact) |
| **Last pushed** | 2025-05-26 |

**Description:** `FF_FS_EXFAT = 1`.  NanoVNA-H is a popular open-source RF vector
network analyser.  Calibration data and S-parameter files are saved to SD card.  A
crafted exFAT SD card triggers the divide-by-zero on any save operation.

---

### CVE-2026-6683-W3 — EZ-FLASH Omega DS Flashcart Kernel

| Field | Value |
|-------|-------|
| **Repository** | [ez-flash/omega-kernel](https://github.com/ez-flash/omega-kernel) |
| **Vulnerable files** | [source/ff13b/ffconf.h](https://github.com/ez-flash/omega-kernel/blob/master/source/ff13b/ffconf.h) (R0.13b — also vulnerable to CVE-2026-6684) |
| **Maintainer** | ez-flash |
| **Contact** | GitHub issues (no public email listed) |
| **Last pushed** | 2024-09-06 |

**Description:** The omega-kernel vendors FatFs at **R0.13b** — well before the CVE-2026-6683
fix — with `FF_FS_EXFAT = 1`.  It is doubly vulnerable: CVE-2026-6683 and CVE-2026-6684.
A crafted SD card or ROM image triggers the crash when SDHC card data is flushed on writes.

---

### CVE-2026-6683-W4 — ua1arn/hftrx Ham Radio Transceiver Firmware

| Field | Value |
|-------|-------|
| **Repository** | [ua1arn/hftrx](https://github.com/ua1arn/hftrx) |
| **Vulnerable file** | [src/fatfs/ffconf.h](https://github.com/ua1arn/hftrx/blob/master/src/fatfs/ffconf.h) |
| **Maintainer** | Genadi V. Zawidowski (ua1arn) |
| **Contact** | GitHub issues |
| **Last pushed** | 2026-03-27 (active) |

**Description:** `FF_FS_EXFAT = 1`.  Used to record IQ samples to large exFAT-formatted
SD cards.  Any sync or close on a crafted exFAT volume triggers CVE-2026-6683.

---

### CVE-2026-6683-W5 — arduino-fatfs (Arduino / embedded FatFs wrapper)

| Field | Value |
|-------|-------|
| **Repository** | [pschatzmann/arduino-fatfs](https://github.com/pschatzmann/arduino-fatfs) |
| **Vulnerable file** | [src/ff/ffconf.h](https://github.com/pschatzmann/arduino-fatfs/blob/main/src/ff/ffconf.h) |
| **Maintainer** | Phil Schatzmann |
| **Contact** | www.pschatzmann.ch (contact form) |
| **Last pushed** | 2025-11-27 |

**Description:** `FF_FS_EXFAT = 1`.  This library is a drop-in FatFs wrapper used in
many Arduino and ESP32 projects; the transitive exposure is broad.

---

### CVE-2026-6683-W6 — picostation (PS1 optical drive emulator on RP2040)

| Field | Value |
|-------|-------|
| **Repository** | [picostation/picostation](https://github.com/picostation/picostation) |
| **Vulnerable file** | [include/ffconf.h](https://github.com/picostation/picostation/blob/main/include/ffconf.h) |
| **Maintainer** | picostation |
| **Contact** | GitHub issues (no public email) |
| **Last pushed** | 2025-05-18 |

**Description:** `FF_LBA64 = 1` and `FF_FS_EXFAT = 1`.  A crafted SD card image
inserted into a PicoStation-modded PS1 can trigger CVE-2026-6683 on write operations used
during game loading.

---

### CVE-2026-6683-W7 — Zephyr RTOS (upstream, all users)

| Field | Value |
|-------|-------|
| **Repository** | [zephyrproject-rtos/zephyr](https://github.com/zephyrproject-rtos/zephyr) |
| **Vulnerable file** | [subsys/fs/fat_fs.c](https://github.com/zephyrproject-rtos/zephyr/blob/main/subsys/fs/fat_fs.c) |
| **Maintainer** | Zephyr Project (Linux Foundation) |
| **Contact** | info@zephyrproject.org · https://www.zephyrproject.org |
| **Security contact** | security@zephyrproject.org |
| **Last pushed** | 2026-03-27 (active) |

**Description:** Zephyr's FatFs VFS wraps `f_write`, `f_sync`, and `f_close` directly;
projects with `CONFIG_FAT_FILESYSTEM_ELM=y` and exFAT support enabled are vulnerable.
Downstream users include products on nRF52840, STM32, ESP32, and i.MX RT SoCs.

---

### CVE-2026-6683-W8 — RT-Thread RTOS (upstream, all users)

| Field | Value |
|-------|-------|
| **Repository** | [RT-Thread/rt-thread](https://github.com/RT-Thread/rt-thread) |
| **Vulnerable file** | [components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c](https://github.com/RT-Thread/rt-thread/blob/master/components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c) |
| **Maintainer** | RT-Thread Development Team |
| **Contact** | https://www.rt-thread.io (community forum) |
| **Security contact** | Use GitHub Security Advisories |
| **Last pushed** | 2026-03-24 (active) |

**Description:** `dfs_elm_write()` and `dfs_elm_flush()` call `f_write` / `f_sync`
with no guard on cluster count.  exFAT-enabled RT-Thread builds on microcontrollers
are exposed to CVE-2026-6683 on any write to a crafted exFAT volume.

---

### CVE-2026-6683-W9 — swupdate (OTA update framework)

| Field | Value |
|-------|-------|
| **Repository** | [sbabic/swupdate](https://github.com/sbabic/swupdate) |
| **Vulnerable file** | [fs/ff.c](https://github.com/sbabic/swupdate/blob/master/fs/ff.c) (bundled FatFs) |
| **Maintainer** | Stefano Babic |
| **Contact** | stefano.babic@swupdate.org · nabladev.com |
| **Last pushed** | 2026-03-27 (active) |

**Description:** swupdate bundles a copy of FatFs used to read update packages from
external storage.  If exFAT is enabled and the update medium is attacker-controlled,
CVE-2026-6683 triggers on the first write during update application.

---

### CVE-2026-6683-W10 — Samsung TizenRT IoT RTOS

| Field | Value |
|-------|-------|
| **Repository** | [Samsung/TizenRT](https://github.com/Samsung/TizenRT) |
| **Vulnerable files** | [os/board/rtl8730e/src/component/file_system/vfs2.0/vfs_fatfs.c](https://github.com/Samsung/TizenRT/blob/master/os/board/rtl8730e/src/component/file_system/vfs2.0/vfs_fatfs.c) (and others under `rtl8730e`) |
| **Maintainer** | Samsung Open Source Group |
| **Contact** | GitHub issues on `Samsung/TizenRT` |
| **Security contact** | https://security.samsungmobile.com/securityReportForm.smsb |
| **Last pushed** | 2026-03-27 (active) |

**Description:** TizenRT's RTL8730E board port wraps FatFs; exFAT builds are exposed
to CVE-2026-6683 via the VFS write path.

---

## CVE-2026-6684 — GPT Partition-Scan Loop DoS in `find_volume()` (pre-R0.16 with `FF_LBA64=1`)

**Status reminder:** Fixed in FatFs R0.16 by `test_gpt_header()`.  Projects that vendor
FatFs older than R0.16 (i.e., R0.15b or earlier) with `FF_LBA64 = 1` are still vulnerable.

---

### CVE-2026-6684-W1 — libdragon (Nintendo 64 SDK) — see also CVE-2026-6683-W1

| Field | Value |
|-------|-------|
| **Repository** | [DragonMinded/libdragon](https://github.com/DragonMinded/libdragon) |
| **Vulnerable file** | [src/fatfs/ffconf.h](https://github.com/DragonMinded/libdragon/blob/trunk/src/fatfs/ffconf.h) |
| **Maintainer** | Jennifer Taylor (DragonMinded) |
| **Contact** | dragonminded@dragonminded.com |
| **Last pushed** | 2026-03-26 (active) |

**Description:** `FF_LBA64 = 1`.  The libdragon FatFs snapshot must be verified to
include the R0.16 `test_gpt_header()` fix.  Until then, a crafted SD card with
`GPTH_PtNum = 0xFFFFFFFF` will loop the mount for billions of iterations.

---

### CVE-2026-6684-W2 — vivado-risc-v FPGA SoC Bootrom

| Field | Value |
|-------|-------|
| **Repository** | [eugene-tarassov/vivado-risc-v](https://github.com/eugene-tarassov/vivado-risc-v) |
| **Vulnerable file** | [bootrom/ffconf.h](https://github.com/eugene-tarassov/vivado-risc-v/blob/master/bootrom/ffconf.h) |
| **Maintainer** | eugene-tarassov |
| **Contact** | GitHub issues (no public email) |
| **Last pushed** | 2026-02-14 |

**Description:** `FF_LBA64 = 1` in the **bootrom** FatFs config.  A crafted GPT disk
image provided to the FPGA RISC-V SoC during boot will cause the bootloader to loop
infinitely attempting disk reads, preventing the system from ever booting.

---

### CVE-2026-6684-W3 — picostation (PS1 ODE) — see also CVE-2026-6683-W6

| Field | Value |
|-------|-------|
| **Repository** | [picostation/picostation](https://github.com/picostation/picostation) |
| **Vulnerable file** | [include/ffconf.h](https://github.com/picostation/picostation/blob/main/include/ffconf.h) |
| **Contact** | GitHub issues |
| **Last pushed** | 2025-05-18 |

**Description:** `FF_LBA64 = 1`.  A crafted GPT SD card prevents the ODE from mounting
the game image folder, bricking game loading.

---

### CVE-2026-6684-W4 — dosfs (FAT disk image tools)

| Field | Value |
|-------|-------|
| **Repository** | [lb3361/dosfs](https://github.com/lb3361/dosfs) |
| **Vulnerable file** | [ffconf.h](https://github.com/lb3361/dosfs/blob/main/ffconf.h) |
| **Maintainer** | lb3361 |
| **Contact** | GitHub issues |
| **Last pushed** | 2021-10-07 |

**Description:** `FF_LBA64 = 1`.  Host-side tool used to manipulate FAT disk images; a
maliciously crafted image passed as argument causes the loop DoS on the developer's
machine.

---

### CVE-2026-6684-W5 — EZ-FLASH Omega DS Flashcart Kernel — see also CVE-2026-6683-W3

| Field | Value |
|-------|-------|
| **Repository** | [ez-flash/omega-kernel](https://github.com/ez-flash/omega-kernel) |
| **Note** | Vendors FatFs R0.13b — the oldest affected version; predates both the CVE-2026-6683 and CVE-2026-6684 fixes |
| **Contact** | GitHub issues |

---

### CVE-2026-6684-W6 — circle (C++ bare-metal Raspberry Pi framework)

| Field | Value |
|-------|-------|
| **Repository** | [rsta2/circle](https://github.com/rsta2/circle) |
| **Vulnerable file** | [addon/fatfs/ff.c](https://github.com/rsta2/circle/blob/master/addon/fatfs/ff.c) |
| **Maintainer** | Rene Stange |
| **Contact** | rsta2@gmx.net |
| **Last pushed** | 2026-03-27 (active) |

**Description:** circle bundles a copy of FatFs in `addon/fatfs/`.  The version of that
bundled copy should be verified to be R0.16 with the `test_gpt_header` fix.  Bare-metal
RPi projects using `FF_LBA64 = 1` are exposed to CVE-2026-6684 until the bundle is updated.

---

### CVE-2026-6684-W7 — tinyuf2 (Adafruit UF2 bootloader)

| Field | Value |
|-------|-------|
| **Repository** | [adafruit/tinyuf2](https://github.com/adafruit/tinyuf2) |
| **Vulnerable file** | [lib/fatfs/source/ff.c](https://github.com/adafruit/tinyuf2/blob/master/lib/fatfs/source/ff.c) |
| **Maintainer** | Adafruit Industries |
| **Contact** | https://adafruit.com (support) |
| **Security contact** | security@adafruit.com |
| **Last pushed** | 2026-02-05 |

**Description:** tinyuf2 is the UF2 bootloader used on Adafruit ESP32-S2, STM32F4, and
i.MX RT10xx boards.  A crafted UF2/FAT volume fed over USB-MSC can trigger CVE-2026-6684 at
bootloader mount time if the bundled FatFs predates R0.16.

---

### CVE-2026-6684-W8 — z80ctrl (Z80 SBC SD card controller)

| Field | Value |
|-------|-------|
| **Repository** | [jblang/z80ctrl](https://github.com/jblang/z80ctrl) |
| **Vulnerable file** | [firmware/fatfs/ff.c](https://github.com/jblang/z80ctrl/blob/master/firmware/fatfs/ff.c) |
| **Maintainer** | J.B. Langston |
| **Contact** | GitHub profile (no public email) |
| **Last pushed** | active |

**Description:** `FF_LBA64` macro used; CVE-2026-6684 manifests with a crafted GPT SD card
passed to a Z80 retro-computer single-board computer.

---

## CVE-2026-6685 — Unsigned Subtraction Stale-Cache in `f_read()` / `f_write()`

CVE-2026-6685 lives entirely inside FatFs itself.  The trigger condition is an interleaved
read/write on a fragmented FAT file whose clusters are not in monotonically increasing
LBA order.  Any caller that does this is affected; the most exposed are circular log
writers and wear-levelling code.

---

### CVE-2026-6685-W1 — grblHAL SD Card Plugin

| Field | Value |
|-------|-------|
| **Repository** | [grblHAL/Plugin_SD_card](https://github.com/grblHAL/Plugin_SD_card) |
| **Vulnerable file** | [fs_fatfs.c](https://github.com/grblHAL/Plugin_SD_card/blob/master/fs_fatfs.c) |
| **Maintainer** | grblHAL org |
| **Contact** | GitHub issues on `grblHAL/Plugin_SD_card` |
| **Last pushed** | 2026-03-20 (active) |

**Description:** SD card plugin for grblHAL CNC motion controller; opens job files
with `FA_READ | FA_WRITE` and also mentioned in CVE-2026-6688 below.  Fragmented job cards are
common in industrial use, making the stale-cache condition reachable.

---

### CVE-2026-6685-W2 — RT-Thread RTOS (upstream)

| Field | Value |
|-------|-------|
| **Repository** | [RT-Thread/rt-thread](https://github.com/RT-Thread/rt-thread) |
| **Vulnerable file** | [components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c](https://github.com/RT-Thread/rt-thread/blob/master/components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c) |
| **Contact** | https://www.rt-thread.io |

**Description:** Long-running RT-Thread IoT devices accumulate FAT fragmentation.
Any device performing interleaved reads/writes (e.g., ring-buffer log files, OTA
staging) will silently return stale data under CVE-2026-6685.

---

### CVE-2026-6685-W3 — Zephyr RTOS (upstream)

| Field | Value |
|-------|-------|
| **Repository** | [zephyrproject-rtos/zephyr](https://github.com/zephyrproject-rtos/zephyr) |
| **Vulnerable file** | [subsys/fs/fat_fs.c](https://github.com/zephyrproject-rtos/zephyr/blob/main/subsys/fs/fat_fs.c) |
| **Contact** | security@zephyrproject.org |

**Description:** Same exposure as CVE-2026-6683; products writing circular log files on FAT
media that fragment over time can corrupt log data silently.

---

## CVE-2026-6686 — Uninitialized Cluster Data via `f_lseek()` Beyond EOF

Projects that pre-allocate file space by seeking past EOF (a common pattern for
data loggers and swap files) and then allow untrusted or unintended readers to
access the unwritten region are exposed to information disclosure.

---

### CVE-2026-6686-W1 — RT-Thread RTOS `ftruncate` path (canonical example)

| Field | Value |
|-------|-------|
| **Repository** | [RT-Thread/rt-thread](https://github.com/RT-Thread/rt-thread) |
| **Vulnerable file** | [components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c](https://github.com/RT-Thread/rt-thread/blob/master/components/dfs/dfs_v1/filesystems/elmfat/dfs_elm.c) — `RT_FIOFTRUNCATE` handler |
| **Maintainer** | RT-Thread Development Team |
| **Contact** | https://www.rt-thread.io |

**Description:** (Full description in `examples.md`.)  `f_lseek(fd, length)` when
`length > objsize` extends the file without zeroing new clusters.  POSIX requires
zero-fill; RT-Thread omits it.

---

### CVE-2026-6686-W2 — frank-os (RP2040 bare-metal OS)

| Field | Value |
|-------|-------|
| **Repository** | [rh1tech/frank-os](https://github.com/rh1tech/frank-os) |
| **Vulnerable file** | [src/ram_page.c](https://github.com/rh1tech/frank-os/blob/main/src/ram_page.c) |
| **Maintainer** | rh1tech |
| **Contact** | GitHub issues |
| **Last pushed** | active |

**Description:** Swap space is pre-allocated by seeking to `_swap_size - 1` without
zeroing.  A subsequent read of the swap area before it is written reveals previously
deleted file content:

```c
FRESULT result = f_open(&file, path, FA_WRITE | FA_CREATE_ALWAYS);
result = f_lseek(&file, _swap_size - 1);   // ← extends without zero-fill
```

---

### CVE-2026-6686-W3 — tinyuf2 (Adafruit UF2 bootloader) — see also CVE-2026-6684-W7

| Field | Value |
|-------|-------|
| **Repository** | [adafruit/tinyuf2](https://github.com/adafruit/tinyuf2) |
| **Contact** | security@adafruit.com |

**Description:** During UF2 flash writes, tinyuf2 creates and extends files on the
virtual FAT volume.  Unzeroed clusters may expose previous firmware content if the
device is inspected over USB-MSC between writes.

---

## CVE-2026-6687 — Stack Buffer Overflow in `f_getlabel()` via `XDIR_NumLabel`

Any call to `f_getlabel()` with a stack buffer of fewer than 256 bytes on a
potentially attacker-supplied exFAT volume overflows that buffer.  The canonical
unsafe declaration is `char label[12]`, matching the FAT spec maximum.

---

### CVE-2026-6687-W1 — PicoRuby (MRuby-c Ruby for microcontrollers)

| Field | Value |
|-------|-------|
| **Repository** | [picoruby/picoruby](https://github.com/picoruby/picoruby) |
| **Vulnerable file** | [mrbgems/picoruby-filesystem-fat/src/mrubyc/fat.c](https://github.com/picoruby/picoruby/blob/master/mrbgems/picoruby-filesystem-fat/src/mrubyc/fat.c) |
| **Maintainer** | PicoRuby Project |
| **Contact** | GitHub issues |
| **Last pushed** | 2026-03-27 (active) |

**Description:** `TCHAR label[12]` on the stack; `f_getlabel(path, label, NULL)` with
no exFAT guard.

```c
TCHAR label[12];
FRESULT res = f_getlabel(path, label, NULL);
```

On an exFAT volume with `XDIR_NumLabel = 255`, this overflows by 243 bytes.

---

### CVE-2026-6687-W2 — MCJack123 CraftOS-PC for ESP32

| Field | Value |
|-------|-------|
| **Repository** | [MCJack123/craftos-esp](https://github.com/MCJack123/craftos-esp) |
| **Vulnerable file** | [main/peripheral/drive.c](https://github.com/MCJack123/craftos-esp/blob/master/main/peripheral/drive.c) |
| **Maintainer** | JackMacWindows |
| **Contact** | jackmacwindowslinux@gmail.com · https://www.craftos-pc.cc |
| **Last pushed** | 2023-12-29 |

**Description:** `char label[12] = {0}` on the stack; `f_getlabel("0:", label, NULL)`.

---

### CVE-2026-6687-W3 — Dektronics Printalyzer Timer (darkroom enlarger timer, STM32)

| Field | Value |
|-------|-------|
| **Repository** | [dektronics/printalyzer-timer](https://github.com/dektronics/printalyzer-timer) |
| **Vulnerable files** | [software/bootloader/src/usb_msc_fatfs.c](https://github.com/dektronics/printalyzer-timer/blob/master/software/bootloader/src/usb_msc_fatfs.c), [software/firmware/src/usb/usb_msc_fatfs.c](https://github.com/dektronics/printalyzer-timer/blob/master/software/firmware/src/usb/usb_msc_fatfs.c) |
| **Maintainer** | Dektronics, Inc. |
| **Contact** | https://www.dektronics.com/ (contact form) |
| **Last pushed** | 2026-03-26 (active) |

**Description:** `char label[12]` declared in both bootloader and firmware USB MSC
handlers; `f_getlabel` is called when a USB MSC host mounts the device.

---

### CVE-2026-6687-W4 — VexUF Horus Firmware (STM32 + USB)

| Field | Value |
|-------|-------|
| **Repository** | [VexUF/VexUF_Horus_fw](https://github.com/VexUF/VexUF_Horus_fw) |
| **Vulnerable file** | [VexUF/Src/vexuf_sdcard.c](https://github.com/VexUF/VexUF_Horus_fw/blob/master/VexUF/Src/vexuf_sdcard.c) |
| **Maintainer** | VexUF |
| **Contact** | info@vexuf.com · https://vexuf.com |
| **Last pushed** | 2024-10-11 |

**Description:** `char cardLabel[12]` on the stack; returned via `f_getlabel`.  Also
mirrored in `VexUF/Vexuf-MCU` (another active repository for the same device):
[horus_fw/fw_src/Core/vexuf/vexuf_sd_card.c](https://github.com/VexUF/Vexuf-MCU/blob/main/horus_fw/fw_src/Core/vexuf/vexuf_sd_card.c).

---

### CVE-2026-6687-W5 — STM32 Nucleo H743ZI SDMMC example

| Field | Value |
|-------|-------|
| **Repository** | [bkht/Nucleo-H743ZI_SDMMC](https://github.com/bkht/Nucleo-H743ZI_SDMMC) |
| **Vulnerable file** | [Src/main.c](https://github.com/bkht/Nucleo-H743ZI_SDMMC/blob/master/Src/main.c) |
| **Maintainer** | bkht |
| **Contact** | GitHub issues |
| **Last pushed** | 2020-03-06 |

**Description:** `char label[12]` on the stack.  This is a reference design example
widely copy-pasted into STM32 projects.

---

### CVE-2026-6687-W6 — Mini8086 PC BIOS (x86 SBC project)

| Field | Value |
|-------|-------|
| **Repository** | [svpetry/Mini8086](https://github.com/svpetry/Mini8086) |
| **Vulnerable file** | [Apps/BIOS/src/debug.c](https://github.com/svpetry/Mini8086/blob/master/Apps/BIOS/src/debug.c) |
| **Maintainer** | svpetry |
| **Contact** | GitHub issues |
| **Last pushed** | active |

**Description:** `char label[12]` declared on the stack alongside `char str[12]`;
`f_getlabel("", label, 0)` overflows `label` and into `str`.

---

### CVE-2026-6687-W7 — tecnovel frida (STM32 Ethernet-over-USB)

| Field | Value |
|-------|-------|
| **Repository** | [tecnovel/frida](https://github.com/tecnovel/frida) |
| **Vulnerable file** | [frida/CM7/Core/frida/cli/mod_file.c](https://github.com/tecnovel/frida/blob/main/frida/CM7/Core/frida/cli/mod_file.c) |
| **Maintainer** | Noah Piqué (tecnovel) |
| **Contact** | GitHub issues |
| **Last pushed** | 2024-06-19 |

**Description:** `char label[12]` passed to `f_getlabel` from a CLI command handler.

---

### CVE-2026-6687-W8 — xmega_synth (AVR XMEGA synthesizer)

| Field | Value |
|-------|-------|
| **Repository** | [bagnaram/xmega_synth](https://github.com/bagnaram/xmega_synth) |
| **Vulnerable file** | [main.c](https://github.com/bagnaram/xmega_synth/blob/master/main.c) |
| **Maintainer** | bagnaram |
| **Contact** | GitHub issues |
| **Last pushed** | 2015-03-28 |

**Description:** `char szCardLabel[12]` on the stack.

---

### CVE-2026-6687-W9 — HermesOS (hobby 32-bit OS)

| Field | Value |
|-------|-------|
| **Repository** | [koen1711/HermesOS](https://github.com/koen1711/HermesOS) |
| **Vulnerable file** | [kernel/hardware/drives/fat/fatfs.c](https://github.com/koen1711/HermesOS/blob/main/kernel/hardware/drives/fat/fatfs.c) |
| **Maintainer** | koen1711 |
| **Contact** | GitHub issues |
| **Last pushed** | 2025-03-18 |

**Description:** `char volume_label[12]` passed to `f_getlabel("", volume_label, 0)`.

---

### CVE-2026-6687-W10 — u-boot (shinyquagsire23 fork and ajb042487 fork)

| Field | Value |
|-------|-------|
| **Repositories** | [shinyquagsire23/u-boot](https://github.com/shinyquagsire23/u-boot/blob/master/fs/fat/ff-uboot.c), [ajb042487/raspi-u-boot](https://github.com/ajb042487/raspi-u-boot/blob/master/fs/fat/ff-uboot.c) |
| **Maintainers** | Fork maintainers; upstream u-boot maintainers should also be notified |
| **Upstream contact** | u-boot mailing list: u-boot@lists.denx.de |

**Description:** `TCHAR label[12]` in both forks' `ff-uboot.c`, called via
`f_getlabel("0:", label, &vsn)`.

---

### CVE-2026-6687-W11 — Nintendont (Wii GameCube game loader)

| Field | Value |
|-------|-------|
| **Repository** | [FIX94/Nintendont](https://github.com/FIX94/Nintendont) |
| **Vulnerable file** | [fatfs/ff.c](https://github.com/FIX94/Nintendont/blob/master/fatfs/ff.c) (the `f_getlabel` implementation itself; callers in the main code use it) |
| **Maintainer** | FIX94 |
| **Contact** | fix94.1@gmail.com · https://gbatemp.net/blog/fix94.232444/ |
| **Last pushed** | active |

**Description:** Nintendont bundles a FatFs copy.  Any Wii application using
Nintendont's bundled `f_getlabel` with a 12-byte buffer is exposed.

---

## CVE-2026-6688 — Stack / Heap Buffer Overflow via Long LFN in `FILINFO.fname`

The dangerous pattern is `strcpy(dest, fno.fname)` or `sprintf(buf, "0:/%s", fno.fname)`
into a buffer shorter than `FF_LFN_BUF` (255 bytes) when `FF_USE_LFN != 0`.

---

### CVE-2026-6688-W1 — Zephyr RTOS `fat_fs.c` (canonical example)

| Field | Value |
|-------|-------|
| **Repository** | [zephyrproject-rtos/zephyr](https://github.com/zephyrproject-rtos/zephyr) |
| **Vulnerable file** | [subsys/fs/fat_fs.c](https://github.com/zephyrproject-rtos/zephyr/blob/main/subsys/fs/fat_fs.c) |
| **Maintainer** | Zephyr Project |
| **Security contact** | security@zephyrproject.org |
| **Last pushed** | 2026-03-27 (active) |

**Description:** `strcpy(entry->name, fno.fname)` into a `char name[14]` buffer.
(Full description in `examples.md`.)  Downstream exposure is enormous — Zephyr runs on
hundreds of commercial IoT products.

Mirror confirmed in older mirror:
[fractalclone/zephyr-riscv](https://github.com/fractalclone/zephyr-riscv/blob/master/subsys/fs/fat_fs.c)

---

### CVE-2026-6688-W2 — grblHAL SD Card Plugin (canonical example)

| Field | Value |
|-------|-------|
| **Repository** | [grblHAL/Plugin_SD_card](https://github.com/grblHAL/Plugin_SD_card) |
| **Vulnerable file** | [fs_fatfs.c](https://github.com/grblHAL/Plugin_SD_card/blob/master/fs_fatfs.c) |
| **Maintainer** | grblHAL org |
| **Contact** | GitHub issues |
| **Last pushed** | 2026-03-20 (active) |

**Description:** Off-by-one in the loop guard allows exactly `sizeof(dirent.name)-1`
length LFN entries to pass the check and overflow `dirent.name`.
(Full description in `examples.md`.)

---

### CVE-2026-6688-W3 — Hekate Nintendo Switch Bootloader

| Field | Value |
|-------|-------|
| **Repository** | [CTCaer/hekate](https://github.com/CTCaer/hekate) |
| **Vulnerable file** | [bdk/utils/dirlist.c](https://github.com/CTCaer/hekate/blob/master/bdk/utils/dirlist.c) |
| **Maintainer** | CTCaer |
| **Contact** | GitHub issues (no public email) |
| **Last pushed** | 2026-03-20 (active) |

**Description:** `strcpy(&dir_entries->data[k * 256], fno.fname)` — each slot in the
directory entry array is 256 bytes, and `fno.fname` can be 255 bytes + NUL = 256,
which exactly fills the slot.  However, if the entry does not start at a 256-byte
boundary, or if an LFN exceeds 255 chars in a non-standard configuration, this
overflows.  More critically, no bounds check is performed before the `strcpy`.

---

### CVE-2026-6688-W4 — GodMode9 (Nintendo 3DS file Explorer)

| Field | Value |
|-------|-------|
| **Repository** | [d0k3/GodMode9](https://github.com/d0k3/GodMode9) |
| **Vulnerable file** | [arm9/source/filesys/vff.c](https://github.com/d0k3/GodMode9/blob/master/arm9/source/filesys/vff.c) |
| **Maintainer** | d0k3 |
| **Contact** | http://d0k3.secretalgorithm.com/ |
| **Last pushed** | 2026-03-25 (active) |

**Description:** `strcpy(fname, fno.fname)` where `fname` is a fixed-size path buffer.
The caller assumes 8.3 or bounded LFN lengths; a crafted FAT volume with max-length LFN
entries overflows the destination.

---

### CVE-2026-6688-W5 — TTGO TWatch Library (LittleVGL FatFs port)

| Field | Value |
|-------|-------|
| **Repository** | [Xinyuan-LilyGO/TTGO_TWatch_Library](https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library) |
| **Vulnerable file** | [src/libraries/lv_fs_if/lv_fs_fatfs.c](https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library/blob/master/src/libraries/lv_fs_if/lv_fs_fatfs.c) |
| **Maintainer** | Xinyuan-LilyGO (LilyGO) |
| **Contact** | GitHub issues |
| **Last pushed** | 2026-01-08 |

**Description:** `strcpy(&fn[1], fno.fname)` into a small fixed-size buffer exposed via
LVGL's filesystem driver.

---

### CVE-2026-6688-W6 — RGBtoHDMI (Retro RGB → HDMI Converter, Bare-metal RPi)

| Field | Value |
|-------|-------|
| **Repository** | [hoglet67/RGBtoHDMI](https://github.com/hoglet67/RGBtoHDMI) |
| **Vulnerable file** | [src/filesystem.c](https://github.com/hoglet67/RGBtoHDMI/blob/master/src/filesystem.c) |
| **Maintainer** | David Banks (hoglet67) |
| **Contact** | GitHub issues |
| **Last pushed** | 2026-03-01 (active) |

**Description:** `sprintf(profile_names[*count], "%s%s/%s", prefix, manufacturer_names[i], fno.fname)` writes into a fixed-size `profile_names` array.  `fno.fname` is bounded with
`fno.fname[MAX_PROFILE_WIDTH - 1] = 0` just before, but the `sprintf` target size is
not checked.  Under LFN a crafted volume pushes the combined string past the buffer.

---

### CVE-2026-6688-W7 — ChibiOS LWIP+FATFS+USB Demo

| Field | Value |
|-------|-------|
| **Repository** | [ChibiOS/ChibiOS](https://github.com/ChibiOS/ChibiOS) |
| **Vulnerable file** | [demos/STM32/RT-STM32-LWIP-FATFS-USB/main.c](https://github.com/ChibiOS/ChibiOS/blob/master/demos/STM32/RT-STM32-LWIP-FATFS-USB/main.c) |
| **Maintainer** | ChibiOS Project |
| **Contact** | http://www.chibios.org (forum) |
| **Last pushed** | 2026-03-27 (active) |

**Description:** `strcpy(path + i + 1, fn)` where `fn = fno.fname`.  Path buffer is
fixed at compile time; a crafted long LFN overflows it.

---

### CVE-2026-6688-W8 — OSSC (Open Source Scan Converter)

| Field | Value |
|-------|-------|
| **Repository** | [marqs85/ossc](https://github.com/marqs85/ossc) |
| **Vulnerable file** | [software/sys_controller/src/file.c](https://github.com/marqs85/ossc/blob/master/software/sys_controller/src/file.c) |
| **Maintainer** | marqs85 |
| **Contact** | http://junkerhq.net/xrgb/index.php/OSSC |
| **Last pushed** | 2026-03-14 (active) |

**Description:** `sprintf(&path[i], "/%s", fno.fname)` where `path` is a fixed-size
buffer.  A crafted SD card with a 255-character LFN profile filename overflows `path`.
OSSC is a popular retro-gaming accessory with an SD card profile system.

---

### CVE-2026-6688-W9 — PikaPython (Python for microcontrollers — LittleVGL FatFs)

| Field | Value |
|-------|-------|
| **Repository** | [pikasTech/PikaPython](https://github.com/pikasTech/PikaPython) |
| **Vulnerable file** | [bsp/swm320/APP/lv_port/lv_port_fs.c](https://github.com/pikasTech/PikaPython/blob/master/bsp/swm320/APP/lv_port/lv_port_fs.c) |
| **Maintainer** | Lyon (pikasTech) |
| **Contact** | GitHub issues |
| **Last pushed** | active |

**Description:** `strcpy(fn, fno.fname)` into LVGL's filesystem buffer without bounds
checking.

---

### CVE-2026-6688-W10 — Tilen Majerle STM32 FatFs Libraries

| Field | Value |
|-------|-------|
| **Repositories** | [MaJerle/stm32fxxx-hal-libraries](https://github.com/MaJerle/stm32fxxx-hal-libraries), [MaJerle/stm32f429](https://github.com/MaJerle/stm32f429) |
| **Vulnerable files** | `00-STM32_LIBRARIES/tm_stm32_fatfs.c`, `00-STM32F429_LIBRARIES/tm_stm32f4_fatfs.c` |
| **Maintainer** | Tilen Majerle |
| **Contact** | tilen.majerle@gmail.com · tilen@majerle.eu · https://majerle.eu |
| **Last pushed** | 2022-07-15 |

**Description:** `fn = fno.fname; sprintf(&path[i], "/%s", fn)` into a fixed-size path
array.  These widely-used STM32 FatFs helper libraries are copy-pasted extensively in
STM32 community projects, multiplying the reach significantly.

---

### CVE-2026-6688-W11 — StarryPilot UAV Flight Controller

| Field | Value |
|-------|-------|
| **Repository** | [JcZou/StarryPilot](https://github.com/JcZou/StarryPilot) |
| **Vulnerable file** | [starry_fmu/Framework/source/FileManager/file_manager.c](https://github.com/JcZou/StarryPilot/blob/master/starry_fmu/Framework/source/FileManager/file_manager.c) |
| **Maintainer** | JcZou |
| **Contact** | GitHub issues |

**Description:** `sprintf((char*)file, "%s/%s", path, (*fno.lfname) ? fno.lfname : fno.fname)`
into a fixed-size file path buffer.  A crafted SD card in a UAV causes overflow of the
file path in the flight controller.

---

### CVE-2026-6688-W12 — FlySight GPS Logger — see also CVE-2026-6682-W12

| Field | Value |
|-------|-------|
| **Repository** | [flysight/flysight](https://github.com/flysight/flysight) |
| **Contact** | support@flysight.ca |

**Description:** FlySight iterates `f_readdir` and copies filenames into fixed-size
buffers.  Both CVE-2026-6682 (trusted fsize) and CVE-2026-6688 (unchecked LFN) are present.

---

### CVE-2026-6688-W13 — SamsungTizenRT FAT SD card API

| Field | Value |
|-------|-------|
| **Repository** | [Samsung/TizenRT](https://github.com/Samsung/TizenRT) |
| **Vulnerable file** | [os/board/rtl8730e/src/component/file_system/fatfs/fatfs_sdcard_api.c](https://github.com/Samsung/TizenRT/blob/master/os/board/rtl8730e/src/component/file_system/fatfs/fatfs_sdcard_api.c) |
| **Contact** | https://security.samsungmobile.com/securityReportForm.smsb |

**Description:** `sprintf(&cur_path[strlen(path)], "/%s", fn)` where `fn = fno.fname`.
The combined `path + "/" + fname` is not bounds-checked against the buffer size.

---

### CVE-2026-6688-W14 — dekuNukem duckyPad Firmware

| Field | Value |
|-------|-------|
| **Repository** | [dekuNukem/duckyPad](https://github.com/dekuNukem/duckyPad) |
| **Vulnerable file** | [firmware/evo/Src/profiles.c](https://github.com/dekuNukem/duckyPad/blob/master/firmware/evo/Src/profiles.c) |
| **Maintainer** | dekuNukem |
| **Contact** | dekunukem&gmail.com (@ implied from GitHub profile obfuscation) |
| **Last pushed** | active |

**Description:** `strcpy(keymap_filename, file_name)` where `file_name = fno.lfname[0] ? fno.lfname : fno.fname`.  With `FF_USE_LFN = 1`, `fno.lfname` can be 255 bytes; `keymap_filename` is a fixed-size buffer.

---

### CVE-2026-6688-W15 — nodemcu-firmware (NodeMCU Lua firmware for ESP8266/ESP32)

| Field | Value |
|-------|-------|
| **Repository** | [nodemcu/nodemcu-firmware](https://github.com/nodemcu/nodemcu-firmware) |
| **Vulnerable file** | [app/fatfs/myfatfs.c](https://github.com/nodemcu/nodemcu-firmware/blob/dev-esp32/app/fatfs/myfatfs.c) |
| **Maintainer** | NodeMCU Project |
| **Contact** | http://www.nodemcu.com ; GitHub issues |
| **Last pushed** | active |

**Description:** Filename copying path in the FatFS VFS layer; absence of LFN length
validation before copy.

---

### CVE-2026-6688-W16 — furrtek/NeoCDSDLoader (NeoGeo CD SD loader)

| Field | Value |
|-------|-------|
| **Repository** | [furrtek/NeoCDSDLoader](https://github.com/furrtek/NeoCDSDLoader) |
| **Vulnerable file** | [FW/ProdApp009/Src/files.c](https://github.com/furrtek/NeoCDSDLoader/blob/master/FW/ProdApp009/Src/files.c) |
| **Maintainer** | Furrtek |
| **Contact** | http://www.furrtek.org |
| **Last pushed** | active |

**Description:** `sprintf(buffer_temp, "Found %s", fno.fname)` and `f_open(&fil_data, fno.fname, FA_READ)` with fixed-size `buffer_temp`.
