idf_component_register(SRCS "fatfs_vuln_test.c"
                       INCLUDE_DIRS "."
                       REQUIRES fatfs esp_partition vfs)
