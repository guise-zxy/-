#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "SHT31.h"

static const char *TAG = "app";


#define I2C_MASTER_SDA_IO       8
#define I2C_MASTER_SCL_IO       9
#define I2C_MASTER_NUM          I2C_NUM_0
#define I2C_MASTER_FREQ_HZ      100000
#define I2C_MASTER_TIMEOUT_MS   1000

static esp_err_t app_i2c_master_init(i2c_master_bus_handle_t *bus_handle)
{
    i2c_master_bus_config_t bus_config = {
        .i2c_port = I2C_MASTER_NUM,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    return i2c_new_master_bus(&bus_config, bus_handle);
}

void app_main(void)
{
    i2c_master_bus_handle_t bus_handle = NULL;
    sht31_t sht31;
    uint8_t addr = 0;
    float temperature = 0.0f;
    float humidity = 0.0f;

    //1.初始化I2C主机总线
    ESP_ERROR_CHECK(app_i2c_master_init(&bus_handle));
    ESP_LOGI(TAG, "I2C bus init ok");

    //2.查找SHT31设备，SHT31有两个地址，0x44和0x45，取决于ADDR引脚的连接方式
    if (sht31_probe(bus_handle, SHT31_ADDR_LOW, I2C_MASTER_TIMEOUT_MS) == ESP_OK) {
        addr = SHT31_ADDR_LOW;
    } else if (sht31_probe(bus_handle, SHT31_ADDR_HIGH, I2C_MASTER_TIMEOUT_MS) == ESP_OK) {
        addr = SHT31_ADDR_HIGH;
    } else {
        ESP_LOGE(TAG, "SHT31 not found");
        return;
    }

    ESP_LOGI(TAG, "SHT31 found at 0x%02X", addr);
   //3.初始化SHT31设备
    ESP_ERROR_CHECK(sht31_init(&sht31, bus_handle, addr, I2C_MASTER_FREQ_HZ));

  //4.循环读取温湿度数据，每2秒读取一次
    while (1) {
       esp_err_t ret = ESP_FAIL;
for (int i = 0; i < 3; i++) {
    ret = sht31_read_temp_humi(&sht31, &temperature, &humidity);
    if (ret == ESP_OK) {
        break;
    }
    vTaskDelay(pdMS_TO_TICKS(50));
}

        if (ret == ESP_OK) {
        ESP_LOGI(TAG, "Temperature: %.2f C, Humidity: %.2f %%RH",
                temperature, humidity);
        } else {
                ESP_LOGE(TAG, "read failed after retry: %s", esp_err_to_name(ret));
        }

  //每2秒读取一次数据
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}