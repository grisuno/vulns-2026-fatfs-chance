/*---------------------------------------------------------------------------
 * diskio_ramdisk.h — public interface for the RAM disk layer
 *---------------------------------------------------------------------------*/

#ifndef DISKIO_RAMDISK_H
#define DISKIO_RAMDISK_H

#include "ff.h"
#include <stdint.h>

/* ── sizing ─────────────────────────────────────────────────────────────── */

#define RAMDISK_SECTOR_SIZE   512U
#define RAMDISK_SECTOR_COUNT  4096U          /* 2 MiB backing store          */
#define RAMDISK_SIZE_BYTES    (RAMDISK_SECTOR_COUNT * RAMDISK_SECTOR_SIZE)

/* ── backing store (accessible for direct inspection in tests) ──────────── */

extern BYTE ramdisk[RAMDISK_SECTOR_COUNT * RAMDISK_SECTOR_SIZE];

/* ── instrumentation ────────────────────────────────────────────────────── */

extern volatile uint32_t ramdisk_read_count;
extern volatile uint32_t ramdisk_write_count;

void ramdisk_reset_stats(void);

/* ── initialisation helpers ─────────────────────────────────────────────── */

/* Load a raw disk image (zeroes the rest of the backing store). */
void ramdisk_load(const BYTE *image, UINT size);

/* Invalidate the disk (triggers STA_NOINIT on next disk_status call). */
void ramdisk_eject(void);

#endif /* DISKIO_RAMDISK_H */
