#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "esp_err.h"
#include "unlock/unlock_protocol.h"

// I2C address of the NFC ESP32
#define NFC_UNLOCK_I2C_ADDR 0x28

// Public API
esp_err_t i2c_unlock_init(void);
bool i2c_unlock_poll(unlock_msg_t *msg);

