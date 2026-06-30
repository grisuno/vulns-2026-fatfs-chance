#---------------------------------------------------------------------------
# Makefile — FatFs R0.16 Security Test Harness
#
# Targets
# -------
#   make              Build and run the deterministic test harness (all bugs)
#   make test         Same as default
#   make extended     Rebuild with FF_LBA64=1 (enables CVE-2026-6684 GPT DoS test)
#   make fuzz_asan    Build libFuzzer binary with ASan + UBSan
#   make afl          Build AFL++ target (requires afl-clang-fast in PATH)
#   make corpus       Write seed corpus files via the Go generator
#   make clean        Remove all build artefacts
#
# Sanitiser notes
# ---------------
#   ASan  (-fsanitize=address)  — detects heap/stack OOB, use-after-free
#   UBSan (-fsanitize=undefined) — detects integer overflow, OOB shifts, etc.
#   Enable both by default for maximum coverage.  Disable individually if
#   the target platform toolchain does not support them.
#---------------------------------------------------------------------------

SRC_DIR  := ../FatFs-R0.16/source
HAR_DIR  := .
BUILD    := build

CC       ?= clang
CFLAGS   := -std=c11 \
            -Wall -Wextra -Wno-unused-parameter \
            -I$(SRC_DIR) -I$(HAR_DIR) \
            -include $(HAR_DIR)/test_ffconf.h

# Sanitisers — append to CFLAGS where needed
SAN_FLAGS := -fsanitize=address,undefined \
             -fno-omit-frame-pointer \
             -g

FATFS_SRC := $(SRC_DIR)/ff.c
HARNESS_SRC := $(HAR_DIR)/diskio_ramdisk.c \
               $(HAR_DIR)/ffunicode_stub.c

# ── default: deterministic test harness ─────────────────────────────────── #
.PHONY: all test
all: test

test: $(BUILD)/test_harness
	@echo "-------------------------------------------------------------------"
	@echo "Running deterministic harness…"
	@echo "-------------------------------------------------------------------"
	$(BUILD)/test_harness; true

$(BUILD)/test_harness: $(FATFS_SRC) $(HARNESS_SRC) $(HAR_DIR)/test_harness.c \
                       | $(BUILD)
	$(CC) $(CFLAGS) $(SAN_FLAGS) $^ -o $@

# ── deprecated fat32-only build (no extended features) ──────────────────── #
# Kept for reference; the main test binary is always the extended build.

# ── libFuzzer binary ─────────────────────────────────────────────────────── #
.PHONY: fuzz_asan
fuzz_asan: $(BUILD)/fuzz_fatfs

$(BUILD)/fuzz_fatfs: $(FATFS_SRC) $(HARNESS_SRC) $(HAR_DIR)/libfuzzer_harness.c \
                     | $(BUILD)
	$(CC) $(CFLAGS) $(SAN_FLAGS) \
	    -fsanitize=fuzzer \
	    $^ -o $@
	@echo ""
	@echo "Usage:  $(BUILD)/fuzz_fatfs -max_len=2097152 corpus/"

# ── AFL++ target ─────────────────────────────────────────────────────────── #
.PHONY: afl
afl: $(BUILD)/afl_fatfs

$(BUILD)/afl_fatfs: $(FATFS_SRC) $(HARNESS_SRC) $(HAR_DIR)/libfuzzer_harness.c \
                    | $(BUILD)
	afl-clang-fast $(CFLAGS) $(SAN_FLAGS) -DAFL_SHIM \
	    $^ -o $@
	@echo ""
	@echo "Usage:  afl-fuzz -i corpus/ -o findings/ -- $(BUILD)/afl_fatfs @@"

# ── corpus generation (requires Go 1.21+) ────────────────────────────────── #
.PHONY: corpus
corpus:
	@mkdir -p corpus
	cd ../fuzzer && go run . -out ../harness/corpus
	@echo "Corpus written to harness/corpus/"
	@ls -lh corpus/

# ── CVE-2026-6682 RCE standalone demo ─────────────────────────────────────────────── #
# Compiled WITHOUT -fsanitize and WITHOUT -fstack-protector so that the
# f_read() struct-overflow reaches ctx.on_apply without being caught by
# ASan or a stack canary mid-flight.  This mirrors the real embedded target
# where neither defensive hardening is present.
.PHONY: rce_demo
rce_demo: $(BUILD)/rce_demo
	@echo "------------------------------------------------------------------"
	@echo "Running CVE-2026-6682 RCE demo (no ASan, no stack-protector)..."
	@echo "------------------------------------------------------------------"
	cd $(BUILD) && ./rce_demo; true

$(BUILD)/rce_demo: $(FATFS_SRC) $(HARNESS_SRC) $(HAR_DIR)/rce_demo.c | $(BUILD)
	$(CC) $(CFLAGS) \
	    -O0 \
	    -fno-stack-protector \
	    $^ -o $@
	@echo "Built rce_demo  (no -fsanitize, no -fstack-protector)"

# ── exploit disk-image generator ──────────────────────────────────────────── #
#
# Generates 14 standalone .img files in harness/img/ — one per project /
# vulnerability combination.  Built WITHOUT sanitisers so that the FatFs
# code paths exercise exactly as they would on real embedded hardware.
# Each image is self-tested by mounting it with the bundled FatFs.
#
#   make exploit_disks          Build and run the generator
#   make exploit_disks_build    Build only (do not run yet)
#
.PHONY: exploit_disks exploit_disks_build
exploit_disks: $(BUILD)/exploit_disks
	@echo "-------------------------------------------------------------------"
	@echo "Generating exploit disk images in $(HAR_DIR)/img/ ..."
	@echo "-------------------------------------------------------------------"
	@mkdir -p $(HAR_DIR)/img
	cd $(HAR_DIR) && $(BUILD)/exploit_disks

exploit_disks_build: $(BUILD)/exploit_disks

$(BUILD)/exploit_disks: $(FATFS_SRC) $(HARNESS_SRC) $(HAR_DIR)/exploit_disks.c \
                         | $(BUILD)
	$(CC) $(CFLAGS) \
	    -O0 \
	    -fno-stack-protector \
	    $^ -o $@
	@echo "Built exploit_disks  (no -fsanitize, no -fstack-protector)"

# ── helpers ──────────────────────────────────────────────────────────────── #
$(BUILD):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(BUILD) $(HAR_DIR)/img
