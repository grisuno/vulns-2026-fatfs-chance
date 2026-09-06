# Subsystem: fuzzer

## fuzzer/fat_image.go
- Layer: utility
- Language: go
- Symbols:
  - `le16` (function, line 19) `func le16(`
  - `le32` (function, line 20) `func le32(`
  - `le64` (function, line 21) `func le64(`
  - `newDisk` (function, line 29) `func newDisk(`
  - `DefaultFAT16Config` (function, line 52) `func DefaultFAT16Config(`
  - `BuildFAT16` (function, line 65) `func BuildFAT16(`
  - `FAT16DataSector` (function, line 107) `func FAT16DataSector(`
  - `DefaultFAT32Config` (function, line 131) `func DefaultFAT32Config(`
  - `BuildFAT32` (function, line 144) `func BuildFAT32(`
  - `BuildGPTImage` (function, line 214) `func BuildGPTImage(`
  - `BuildExFATImage` (function, line 262) `func BuildExFATImage(`
  - `MutateFAT32BPB` (function, line 303) `func MutateFAT32BPB(`
  - `RandomMutate` (function, line 324) `func RandomMutate(`
  - `BuildExFATWithLargeLabel` (function, line 354) `func BuildExFATWithLargeLabel(`
  - `sfnChecksum` (function, line 430) `func sfnChecksum(`
  - `BuildFAT16WithLFNFile` (function, line 451) `func BuildFAT16WithLFNFile(`
  - `FAT16Config` (struct, line 41)
  - `FAT32Config` (struct, line 118)

## fuzzer/main.go
- Layer: utility
- Doc: main.go — FatFs corpus generator and native Go fuzzer  Modes of operation ────────────────── 1. Corpus generator (defaul
- Language: go
- Symbols:
  - `main` (function, line 51) `func main(`
  - `buildAllSeeds` (function, line 76) `func buildAllSeeds(`
  - `BuildFAT12Minimal` (function, line 290) `func BuildFAT12Minimal(`
  - `FuzzFAT32BPB` (function, line 343) `func FuzzFAT32BPB(`
  - `FuzzGPTNEnt` (function, line 398) `func FuzzGPTNEnt(`
  - `FuzzExFATNumLabel` (function, line 449) `func FuzzExFATNumLabel(`
  - `FuzzFAT16LFNLength` (function, line 507) `func FuzzFAT16LFNLength(`
