// webserver.c
#include "webserver.h"
#include "esp_log.h"
#include "esp_http_server.h"
#include "sensor.h"
#include "buzzer.h"
#include <string.h>

static const char *TAG = "webserver";

/* Embedded static files */
extern const unsigned char index_html_start[] asm("_binary_index_html_start");
extern const unsigned char index_html_end[]   asm("_binary_index_html_end");

/* Handler for GET / */
static esp_err_t index_get_handler(httpd_req_t *req)
{
    size_t len = index_html_end - index_html_start;
    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, (const char *)index_html_start, len);
    return ESP_OK;
}

/* Handler for GET /status */
static esp_err_t status_get_handler(httpd_req_t *req)
{
    int raw = sensor_read();
    bool alert = raw > SMOKE_THRESHOLD;
    char buf[128];
    int len = snprintf(buf, sizeof(buf),
        "{ \"smoke_raw\": %d, \"alert\": %s }",
        raw, alert ? "true" : "false");
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, buf, len);
    return ESP_OK;
}

/* Handler for POST /buzzer */
static esp_err_t buzzer_post_handler(httpd_req_t *req)
{
    char buf[32];
    int ret = httpd_req_recv(req, buf, req->content_len);
    if (ret <= 0) {
        httpd_resp_send_500(req);
        return ESP_FAIL;
    }
    buf[ret] = '\0';
    bool on = strstr(buf, "\"on\"") != NULL;
    buzzer_set(on);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_sendstr(req, "{\"result\":\"ok\"}");
    return ESP_OK;
}

esp_err_t webserver_start(void)
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    ESP_LOGI(TAG, "Starting HTTP server");
    if (httpd_start(&server, &config) != ESP_OK) {
        ESP_LOGE(TAG, "Failed to start HTTP server");
        return ESP_FAIL;
    }

    /* URI: GET / */
    httpd_uri_t index_uri = {
        .uri       = "/",
        .method    = HTTP_GET,
        .handler   = index_get_handler,
        .user_ctx  = NULL
    };
    httpd_register_uri_handler(server, &index_uri);

    /* URI: GET /status */
    httpd_uri_t status_uri = {
        .uri       = "/status",
        .method    = HTTP_GET,
        .handler   = status_get_handler,
        .user_ctx  = NULL
    };
    httpd_register_uri_handler(server, &status_uri);

    /* URI: POST /buzzer */
    httpd_uri_t buzzer_uri = {
        .uri       = "/buzzer",
        .method    = HTTP_POST,
        .handler   = buzzer_post_handler,
        .user_ctx  = NULL
    };
    httpd_register_uri_handler(server, &buzzer_uri);

    return ESP_OK;
}
