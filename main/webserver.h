// webserver.h
#pragma once

#include "esp_err.h"
#include "esp_http_server.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Start HTTP server on port 80, mounting static UI and API endpoints.
 * 
 * @return Handle to the started server, or NULL on failure.
 */
esp_err_t webserver_start(void);

#ifdef __cplusplus
}
#endif
