# Recipe: Reduce File Complexity

Target hotspot: `FatFs-R0.16/source/ff.h`
(complexity 0.3, centrality 1.0)

1. Read dependents: `grep -n 'FatFs-R0.16/source/ff.h' readmenator-agent/ARCHITECTURE*.md`
2. Extract functions/classes into new files in the same subsystem
3. Update imports
4. Regenerate: `readmenator .`
