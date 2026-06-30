/*---------------------------------------------------------------------------
 * diskio_ramdisk.c — RAM-backed disk I/O for FatFs test harness
 *
 * Replaces the skeleton diskio.c from the FatFs distribution.
 * Provides a flat byte-array RAM disk with configurable behaviour:
 *
 *  - ramdisk_load()        : load a raw image into the RAM buffer
 *  - ramdisk_reset_stats() : zero the read/write counters
 *  - ramdisk_read_count    : number of disk_read() calls made (DoS probe)
 *  - ramdisk_write_count   : number of disk_write() calls made
 *
 * Out-of-range sector reads return a full sector of 0x00 bytes with
 * RES_OK (simulates a large backing device).  This is intentional: it
 * allows the GPT n_ent loop-DoS test to measure iteration count rather
 * than exiting on the first out-of-range access.
 *---------------------------------------------------------------------------*/

#include "ff.h"
#include "diskio.h"
#include "diskio_ramdisk.h"

#include <string.h>

/* ── backing store ─────────────────────────────────────────────────────── */

BYTE ramdisk[RAMDISK_SECTOR_COUNT * RAMDISK_SECTOR_SIZE];

static DSTATUS disk_stat = STA_NOINIT;

/* ── instrumentation ────────────────────────────────────────────────────── */

volatile uint32_t ramdisk_read_count  = 0;
volatile uint32_t ramdisk_write_count = 0;

void ramdisk_reset_stats(void)
{
    ramdisk_read_count  = 0;
    ramdisk_write_count = 0;
}

/* ── public helpers ─────────────────────────────────────────────────────── */

/* Load up to RAMDISK_SECTOR_COUNT × RAMDISK_SECTOR_SIZE bytes of image
 * data.  Any sector beyond the image is left zeroed.  Call this before
 * mounting a volume.                                                       */
void ramdisk_load(const BYTE *image, UINT size)
{
    UINT bytes = (size < sizeof(ramdisk)) ? size : (UINT)sizeof(ramdisk);
    memset(ramdisk, 0, sizeof(ramdisk));
    memcpy(ramdisk, image, bytes);
    disk_stat = 0;    /* initialised, not write-protected */
}

/* Force the disk state back to "uninitialised". */
void ramdisk_eject(void)
{
    disk_stat = STA_NOINIT;
}

/* ── diskio interface ───────────────────────────────────────────────────── */

DSTATUS disk_status(BYTE pdrv)
{
    if (pdrv != 0) return STA_NOINIT;
    return disk_stat;
}

DSTATUS disk_initialize(BYTE pdrv)
{
    if (pdrv != 0) return STA_NOINIT;
    disk_stat = 0;
    return 0;
}

DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)
{
    if (pdrv != 0) return RES_PARERR;
    if (count == 0) return RES_PARERR;

    ramdisk_read_count += count;

    for (UINT i = 0; i < count; i++) {
        LBA_t s = sector + i;
        BYTE *dst = buff + (i * RAMDISK_SECTOR_SIZE);
        if (s < RAMDISK_SECTOR_COUNT) {
            memcpy(dst, ramdisk + s * RAMDISK_SECTOR_SIZE, RAMDISK_SECTOR_SIZE);
        } else {
            /* out-of-range: return a zero sector (simulates large disk) */
            memset(dst, 0, RAMDISK_SECTOR_SIZE);
        }
    }
    return RES_OK;
}

DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)
{
    if (pdrv != 0) return RES_PARERR;
    if (count == 0) return RES_PARERR;

    ramdisk_write_count += count;

    for (UINT i = 0; i < count; i++) {
        LBA_t s = sector + i;
        if (s < RAMDISK_SECTOR_COUNT) {
            memcpy(ramdisk + s * RAMDISK_SECTOR_SIZE,
                   buff + (i * RAMDISK_SECTOR_SIZE),
                   RAMDISK_SECTOR_SIZE);
        }
        /* silently discard writes beyond the backing store */
    }
    return RES_OK;
}

DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)
{
    if (pdrv != 0) return RES_PARERR;
    switch (cmd) {
    case CTRL_SYNC:
        return RES_OK;
    case GET_SECTOR_COUNT:
        *(DWORD *)buff = RAMDISK_SECTOR_COUNT;
        return RES_OK;
    case GET_SECTOR_SIZE:
        *(WORD *)buff = RAMDISK_SECTOR_SIZE;
        return RES_OK;
    case GET_BLOCK_SIZE:
        *(DWORD *)buff = 1;
        return RES_OK;
    default:
        return RES_PARERR;
    }
}

/* ── timestamp stub ─────────────────────────────────────────────────────── */
/* Required when FF_FS_NORTC == 0  (the default).                           */

DWORD get_fattime(void)
{
    /* 2025-01-01 00:00:00 in FAT timestamp encoding */
    return ((DWORD)(2025 - 1980) << 25)
         | ((DWORD)1  << 21)
         | ((DWORD)1  << 16);
}
