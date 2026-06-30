#!/bin/bash
#===========================================================================
# run.sh — Build and run the ESP32 QEMU FatFs vulnerability demonstration
#
# This is the single-command entry point.  It builds the Docker image
# (which compiles the ESP32 application) and then runs the container
# (which injects the exploit and launches QEMU).
#
# Usage:
#   ./run.sh              Build and run the test
#   ./run.sh --build      Build the Docker image only
#   ./run.sh --run        Run the container only (image must exist)
#   ./run.sh --shell      Open a shell in the container for debugging
#
# Requirements:
#   - Docker (19.03+ recommended)
#   - ~6 GB disk space (ESP-IDF Docker image + build artifacts)
#   - ~15 minutes for first build (subsequent runs use Docker cache)
#===========================================================================
set -euo pipefail

IMAGE_NAME="fatfs-esp32-vuln-test"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

usage() {
    echo "Usage: $0 [--build|--run|--shell]"
    echo ""
    echo "  (default)   Build Docker image and run the vulnerability test"
    echo "  --build     Build the Docker image only"
    echo "  --run       Run the test (image must exist)"
    echo "  --shell     Open a shell inside the container for debugging"
    echo ""
}

image_exists() {
    docker image inspect "$IMAGE_NAME" >/dev/null 2>&1
}

ensure_image() {
    if image_exists; then
        return
    fi
    do_build
}

do_build() {
    echo "Building Docker image '${IMAGE_NAME}'..."
    echo "  (This takes ~15 minutes on first build; Docker caches subsequent runs)"
    echo ""
    docker build -t "$IMAGE_NAME" "$SCRIPT_DIR"
}

do_run() {
    echo "Running ESP32 QEMU FatFs vulnerability test..."
    echo ""
    ensure_image
    docker run --rm \
        -v "$SCRIPT_DIR/app:/opt/fatfs-test/app" \
        -v "$SCRIPT_DIR/scripts:/opt/fatfs-test/scripts" \
        "$IMAGE_NAME"
}

do_shell() {
    echo "Opening shell in container..."
    echo "  Useful commands:"
    echo "    . \$IDF_PATH/export.sh"
    echo "    cd /opt/fatfs-test/app && idf.py build"
    echo "    bash /opt/fatfs-test/scripts/run_test.sh"
    echo ""
    ensure_image
    docker run --rm -it \
        -v "$SCRIPT_DIR/app:/opt/fatfs-test/app" \
        -v "$SCRIPT_DIR/scripts:/opt/fatfs-test/scripts" \
        "$IMAGE_NAME" bash
}

case "${1:-}" in
    --build)
        do_build
        ;;
    --run)
        do_run
        ;;
    --shell)
        do_shell
        ;;
    --help|-h)
        usage
        ;;
    "")
        do_run
        ;;
    *)
        echo "Unknown option: $1"
        usage
        exit 1
        ;;
esac
