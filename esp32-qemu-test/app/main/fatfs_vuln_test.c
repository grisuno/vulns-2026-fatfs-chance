#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdbool.h>

#include "esp_log.h"
#include "esp_system.h"
#include "esp_idf_version.h"
#include "esp_vfs_fat.h"
#include "esp_partition.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "fatfs_vuln";

#define MOUNT_POINT "/storage"


#define FW_HDR_SIZE 128u
#define OTA_READ_SLAB_SIZE 512u

typedef struct ota_update_ctx {
    uint8_t fw_header[FW_HDR_SIZE];
    uint32_t expected_crc;
    uint32_t fw_version;
    void (*on_complete)(void);
} ota_update_ctx_t;

typedef struct ota_exec_region {
    ota_update_ctx_t ctx;
    uint8_t spill[OTA_READ_SLAB_SIZE - sizeof(ota_update_ctx_t)];
} ota_exec_region_t;

ota_exec_region_t IRAM_ATTR g_ota_region __attribute__((used));

#define CANARY_CRC      0xDEADBEEFu
#define CANARY_VERSION  0x00010002u

#define LFN_GUARD_VALUE 0xA5A5C3C3u

typedef struct lfn_overflow_probe {
    char name[32];
    volatile uint32_t guard;
} lfn_overflow_probe_t;

static lfn_overflow_probe_t g_lfn_probe;

__attribute__((noinline)) static void unsafe_copy_dirent_name(char *dst, const struct dirent *entry)
{
    if (entry->d_type == DT_DIR) {
        /* Pattern mirrored from public ESP32 examples using strcat/sprintf-style concatenation. */
        strcpy(dst, "");
        strcat(dst, "/");
        strcat(dst, entry->d_name);
    } else {
        strcpy(dst, entry->d_name);
    }
}

static void legitimate_update_callback(void)
{
    ESP_LOGI(TAG, "update callback completed");
}

static bool run_lfn_copy_probe(void)
{
    /*
     * CVE-2026-6688 caller-side probe:
     * readdir() returns an attacker-controlled long filename, then application
     * code copies it into a fixed 32-byte stack/global buffer without bounds
     * checks, matching public ESP32 code patterns.
     */
    DIR *dir = opendir(MOUNT_POINT);
    if (!dir) {
        ESP_LOGE(TAG, "opendir failed: errno=%d", errno);
        return false;
    }

    bool overflow_detected = false;
    struct dirent *entry = NULL;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        memset((void *)&g_lfn_probe, 0, sizeof(g_lfn_probe));
        g_lfn_probe.guard = LFN_GUARD_VALUE;

        /*
         * Pattern mirrored from public ESP32 examples:
         *   - esp-dev-kits/.../lv_port_fs.c: sprintf(fn, "/%s", entry->d_name)
         *   - esp-dev-kits/.../lv_port_fs.c: strcpy(fn, entry->d_name)
         *   - esp-dev-kits/.../sdcard_fatfs/main.c: strcat(global_path, file->d_name)
         */
        unsafe_copy_dirent_name(g_lfn_probe.name, entry);

        if (g_lfn_probe.guard != LFN_GUARD_VALUE) {
            ESP_LOGE(TAG, "[VULN-BUG7-CONFIRMED] guard corrupted after filename copy");
            ESP_LOGE(TAG,
                     "entry='%s' len=%u guard=0x%08" PRIx32,
                     entry->d_name,
                     (unsigned)strlen(entry->d_name),
                     g_lfn_probe.guard);
            overflow_detected = true;
            break;
        }
    }

    closedir(dir);
    return overflow_detected;
}

static long get_firmware_size(void)
{
    struct stat st;
    if (stat(MOUNT_POINT "/FIRMWARE.BIN", &st) != 0) {
        ESP_LOGE(TAG, "stat failed: errno=%d", errno);
        return 0;
    }
    if ((long)st.st_size > (long)FW_HDR_SIZE) {
        ESP_LOGE(TAG, "firmware size exceeds header size");
    }
    return (long)st.st_size;
}

static bool read_firmware_image(int fd, size_t firmware_size)
{
    ota_update_ctx_t *ctx = &g_ota_region.ctx;

    memset(&g_ota_region, 0, sizeof(g_ota_region));
    ctx->expected_crc = CANARY_CRC;
    ctx->fw_version = CANARY_VERSION;
    ctx->on_complete = legitimate_update_callback;

    ssize_t bytes_read = read(fd, ctx->fw_header, firmware_size);
    if (bytes_read < 0) {
        ESP_LOGE(TAG, "firmware read failed: errno=%d", errno);
        return false;
    }

    return true;
}

static void run_update_flow(long attacker_fsize)
{
    int fd = open(MOUNT_POINT "/FIRMWARE.BIN", O_RDONLY);
    if (fd < 0) {
        ESP_LOGE(TAG, "open failed: errno=%d", errno);
        return;
    }

    if (!read_firmware_image(fd, (size_t)attacker_fsize)) {
        close(fd);
        return;
    }

    close(fd);

    g_ota_region.ctx.on_complete();
    ESP_LOGI(TAG, "callback returned");
}
void app_main(void)
{
    vTaskDelay(pdMS_TO_TICKS(100));

    ESP_LOGI(TAG,
             "startup: idf_version=%s free_heap=%" PRIu32,
             esp_get_idf_version(),
             esp_get_free_heap_size());
    ESP_LOGI(TAG, "PoC: CVE-2026-6688 long-LFN caller overflow probe (ESP32 public-pattern copy path)");

    const esp_vfs_fat_mount_config_t mount_config = {
        .max_files = 4,
        .format_if_mount_failed = false,
        .allocation_unit_size = 0
    };

    esp_err_t err = esp_vfs_fat_spiflash_mount_ro(MOUNT_POINT, "storage", &mount_config);

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "mount failed: %s", esp_err_to_name(err));
        return;
    }

    /* Legacy CVE-2026-6682-style OTA read path retained for context and payload marker output. */
    long attacker_fsize = get_firmware_size();
    if (attacker_fsize > 0) {
        run_update_flow(attacker_fsize);
    }

    run_lfn_copy_probe();

    esp_vfs_fat_spiflash_unmount_ro(MOUNT_POINT, "storage");

    printf("\n");

    fflush(stdout);
    vTaskDelay(pdMS_TO_TICKS(250));
}
