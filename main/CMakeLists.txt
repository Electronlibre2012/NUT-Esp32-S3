#nut/main/

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)

idf_component_register(
    SRCS ${app_sources} ../lib/af_unix_socket/af_unix_socket.c ../lib/syslog/syslog.c
    INCLUDE_DIRS ../include ../lib/af_unix_socket ../lib/libusb ../lib/syslog ../src
    PRIV_REQUIRES usb nvs_flash openthread esp_coex esp_event idf::espressif__usb_host_hid
    REQUIRES fatfs vfs esp_wifi lwip)

fatfs_create_spiflash_image(var ../fatfs/var FLASH_IN_PROJECT)
fatfs_create_spiflash_image(usr ../fatfs/usr FLASH_IN_PROJECT)

target_link_options(${COMPONENT_LIB} INTERFACE "-Wl,--wrap=exit")