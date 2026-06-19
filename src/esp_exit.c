#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

// Intercepte exit() avant qu'il n'appelle _exit() -> abort()
void __wrap_exit(int status) {
    ESP_LOGW("nut", "exit(%d) called - restarting in 3s...", status);
    vTaskDelay(pdMS_TO_TICKS(3000));
    esp_restart();
    while(1) {}
}