// buzzer.h
#pragma once

#include "esp_err.h"
#include "driver/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the buzzer GPIO.
 * 
 * @param gpio_num GPIO number connected to buzzer (active HIGH)
 * @return ESP_OK on success
 */
esp_err_t buzzer_init(gpio_num_t gpio_num);

/**
 * @brief Turn the buzzer on or off.
 * 
 * @param on true to turn on, false to turn off
 */
void buzzer_set(bool on);

#ifdef __cplusplus
}
#endif
