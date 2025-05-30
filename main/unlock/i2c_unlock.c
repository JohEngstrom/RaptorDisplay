#include "unlock/i2c_unlock.h"
#include "driver/i2c.h"
#include <string.h>

#define I2C_MASTER_NUM I2C_NUM_0
#define I2C_MASTER_SDA_IO 8
#define I2C_MASTER_SCL_IO 9
#define I2C_MASTER_FREQ_HZ 400000

esp_err_t i2c_unlock_init(void) {
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };
    esp_err_t ret = i2c_param_config(I2C_MASTER_NUM, &conf);
    if (ret != ESP_OK) return ret;
    return i2c_driver_install(I2C_MASTER_NUM, conf.mode, 0, 0, 0);
}

bool i2c_unlock_poll(unlock_msg_t *msg) {
    uint8_t buf[sizeof(unlock_msg_t)] = {0};
    esp_err_t ret = i2c_master_read_from_device(
        I2C_MASTER_NUM,
        NFC_UNLOCK_I2C_ADDR,
        buf,
        sizeof(unlock_msg_t),
        50 / portTICK_PERIOD_MS
    );
    if (ret == ESP_OK && buf[0] != UNLOCK_NONE) {
        memcpy(msg, buf, sizeof(unlock_msg_t));
        return true;
    }
    return false;
}
