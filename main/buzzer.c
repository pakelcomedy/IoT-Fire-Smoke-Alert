// buzzer.c
#include "buzzer.h"
#include "esp_log.h"

static const char *TAG = "buzzer";
static gpio_num_t buzzer_gpio = GPIO_NUM_MAX;

esp_err_t buzzer_init(gpio_num_t gpio_num)
{
    buzzer_gpio = gpio_num;
    esp_err_t err = gpio_reset_pin(buzzer_gpio);
    if (err != ESP_OK) return err;
    err = gpio_set_direction(buzzer_gpio, GPIO_MODE_OUTPUT);
    if (err != ESP_OK) return err;
    gpio_set_level(buzzer_gpio, 0);
    ESP_LOGI(TAG, "Buzzer initialized on GPIO %d", buzzer_gpio);
    return ESP_OK;
}

void buzzer_set(bool on)
{
    if (buzzer_gpio == GPIO_NUM_MAX) {
        ESP_LOGW(TAG, "buzzer_set called before init");
        return;
    }
    gpio_set_level(buzzer_gpio, on ? 1 : 0);
    ESP_LOGI(TAG, "Buzzer %s", on ? "ON" : "OFF");
}
