// main.c
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#include "wifi.h"
#include "sensor.h"

#define BUZZER_GPIO    GPIO_NUM_26
#define SMOKE_THRESHOLD 2000  // adjust based on calibration

static const char *TAG = "FIRE_SMOKE";

void app_main(void)
{
    // 1. Init logger
    esp_log_level_set("*", ESP_LOG_INFO);

    // 2. Init Wi‑Fi in station mode
    ESP_ERROR_CHECK(wifi_init_sta());

    // 3. Init MQ-2 sensor (ADC)
    sensor_init();

    // 4. Configure buzzer pin
    gpio_reset_pin(BUZZER_GPIO);
    gpio_set_direction(BUZZER_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(BUZZER_GPIO, 0);

    ESP_LOGI(TAG, "System initialized, starting detection loop");

    while (true) {
        // Read smoke level
        int raw = sensor_read();
        ESP_LOGI(TAG, "MQ-2 raw reading: %d", raw);

        if (raw > SMOKE_THRESHOLD) {
            ESP_LOGW(TAG, "Smoke/Fire detected! raw=%d", raw);
            gpio_set_level(BUZZER_GPIO, 1);
        } else {
            gpio_set_level(BUZZER_GPIO, 0);
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}