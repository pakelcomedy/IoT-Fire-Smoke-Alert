// sensor.c
#include "sensor.h"
#include "driver/adc.h"
#include "esp_log.h"

static const char *TAG = "sensor";

// ADC channel for GPIO34 on ADC1_CHANNEL_6
#define MQ2_ADC_CHANNEL   ADC1_CHANNEL_6
#define ADC_ATTEN         ADC_ATTEN_DB_11
#define ADC_BITWIDTH      ADC_WIDTH_BIT_12

void sensor_init(void)
{
    // Configure ADC
    adc1_config_width(ADC_BITWIDTH);
    adc1_config_channel_atten(MQ2_ADC_CHANNEL, ADC_ATTEN);
    ESP_LOGI(TAG, "ADC configured: channel %d, atten %d dB", MQ2_ADC_CHANNEL, ADC_ATTEN);
}

int sensor_read(void)
{
    int raw = adc1_get_raw(MQ2_ADC_CHANNEL);
    ESP_LOGI(TAG, "ADC raw read: %d", raw);
    return raw;
}
