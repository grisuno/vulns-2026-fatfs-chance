# Second Brain

*Last synthesized: 2026-10-07 | 27 files | 4 concept pages | offline, zero tokens*

> Raw sources -> readmenator wiki -> links (Karpathy LLM Wiki Pattern, deterministic).
> Start here, then open one community page. Prefer grep over full reads.

## Vault Overview

The codebase centres on `ff.c`, `ff.h`, `diskio.h`. Architecturally it is 2 layers, dominant utility (20 files) across 4 import-based communities. Recorded risk surface: 0 security findings and 0 dependency cycles.

Surprising tissue lives between FatFs-R0.16/source: ff (community 0), FatFs-R0.16/source: ff (community 1), harness: 3 extracted cross-community imports and 7 inferred bridges. Follow `connections.json` sorted by strength before refactoring.

Open work clusters around documentation (93% file coverage), 0 security findings, 1 taint paths, and 5 suggested exploration questions in `queries.md`.

## Stats

| Metric | Value |
|--------|-------|
| Files | 27 |
| Symbols | 762 |
| Resolved imports | 28 |
| Languages | c, go, h, py, sh |
| Communities | 4 |
| Doc coverage | 93% (25/27 files) |
| Security findings | 0 |
| Estimated read cost | ~12856 tokens (chars/4, offline so $0) |
| Large files (>256KB, maybe generated) | 2: `ff.c`, `ffunicode.c` |

## Reading Order

1. Skim Stats and God Nodes below for blast radius.
2. Open the largest community page first, then follow Connections.
3. Use `queries.md` for the next question; log the answer there.

```
grep -rn '<keyword>' index.md community_*.md
readmenator query "<question>" --target readmenator_vulns-2026-fatfs-chance_hfdynfma
```

## Concept Wiki

- [FatFs-R0.16/source: ff (community 0) (6 files, cohesion 0.33)](./community_0_fatfs_r0_16_source_ff.md)
- [FatFs-R0.16/source: ff (community 1) (5 files, cohesion 0.29)](./community_1_fatfs_r0_16_source_ff.md)
- [harness (5 files, cohesion 0.29)](./community_2_harness.md)
- [orphans (11 files, cohesion 0.00)](./community_3_orphans.md)

## God Nodes

| File | Score |
|------|-------|
| `FatFs-R0.16/source/ff.c` | 37.4 (large, maybe generated) |
| `FatFs-R0.16/source/ff.h` | 36.6 |
| `FatFs-R0.16/source/diskio.h` | 20.6 |
| `harness/diskio_ramdisk.h` | 13.0 |
| `harness/exploit_disks.c` | 11.3 |

## Strongest Connections

- 0 -> 1: depends_on (strength 0.9, EXTRACTED)
- 2 -> 1: depends_on (strength 0.9, EXTRACTED)
- 2 -> 0: depends_on (strength 0.9, EXTRACTED)
- 0 -> 1: bridges (strength 0.7, INFERRED)
- 0 -> 1: bridges (strength 0.7, INFERRED)
- 0 -> 1: bridges (strength 0.7, INFERRED)
- 0 -> 1: bridges (strength 0.7, INFERRED)
- 0 -> 3: shares_context (strength 0.5, INFERRED)
- 1 -> 3: shares_context (strength 0.5, INFERRED)
- 2 -> 3: shares_context (strength 0.5, INFERRED)

## Navigation Tips

- Obsidian Graph View works: every community page links back here.
- `connections.json` is machine-readable for GraphRAG pipelines.
- `REPORT.md` states what was extracted vs inferred and current limits.
- Regenerate offline: `readmenator . --rebuild` (no network, no tokens).
