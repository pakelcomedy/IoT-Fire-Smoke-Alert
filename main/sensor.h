// sensor.h
#pragma once
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize ADC for MQ-2 smoke sensor.
 */
void sensor_init(void);

/**
 * @brief Read raw ADC value from MQ-2 sensor.
 * @return 12‑bit ADC reading (0–4095)
 */
int sensor_read(void);

#ifdef __cplusplus
}
#endif
