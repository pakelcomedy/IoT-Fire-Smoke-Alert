// wifi.h
#pragma once
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize Wi‑Fi in station mode.
 *        Connects to SSID/PASS defined in sdkconfig or defaults.
 * @return ESP_OK on success, otherwise error code.
 */
esp_err_t wifi_init_sta(void);

#ifdef __cplusplus
}
#endif
