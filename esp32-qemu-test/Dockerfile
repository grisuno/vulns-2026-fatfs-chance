# ===========================================================================
# Dockerfile — ESP32 QEMU FatFs CVE-2026-6682 Vulnerability Demonstration
#
# Builds an ESP-IDF application that demonstrates the FatFs R0.16
# integer overflow vulnerability (CVE-2026-6682) running on a real ESP32
# firmware image inside the Espressif QEMU emulator.
#
# Base image: espressif/idf (official ESP-IDF Docker image)
#   - Includes ESP-IDF SDK, Xtensa toolchain, esptool.py
#   - QEMU is added on top via idf_tools.py
#
# Build:
#   docker build -t fatfs-esp32-vuln-test .
#
# Run:
#   docker run --rm fatfs-esp32-vuln-test
#
# Expected output shows the ESP32 booting in QEMU, mounting the crafted
# FAT32 partition, and stat() returning an attacker-controlled file size.
# ===========================================================================

FROM espressif/idf:v5.3.2

# ── Install QEMU for ESP32 (Xtensa architecture) ─────────────────────────
# The Espressif fork of QEMU supports ESP32 SPI flash emulation, which is
# required to load the crafted FatFs partition image.
RUN bash -c '. $IDF_PATH/export.sh && \
    python3 $IDF_PATH/tools/idf_tools.py install qemu-xtensa'

# ── Copy application source ──────────────────────────────────────────────
COPY app/ /opt/fatfs-test/app/
COPY scripts/ /opt/fatfs-test/scripts/

RUN chmod +x /opt/fatfs-test/scripts/*.sh && \
    chmod +x /opt/fatfs-test/scripts/*.py

# ── Build the ESP32 application ──────────────────────────────────────────
# This compiles the FatFs vulnerability test application for ESP32.
# The build produces:
#   - bootloader.bin       (second-stage bootloader)
#   - partition-table.bin  (custom partition table with FAT partition)
#   - fatfs_vuln_test.bin  (application binary)
#   - flash_args           (merge recipe for esptool.py)
RUN bash -c '. $IDF_PATH/export.sh && \
    cd /opt/fatfs-test/app && \
    idf.py set-target esp32 && \
    idf.py build'

# ── Entrypoint: merge flash image, inject exploit, run QEMU ─────────────
WORKDIR /opt/fatfs-test
CMD ["bash", "/opt/fatfs-test/scripts/run_test.sh"]
