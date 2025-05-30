#ifndef VESC_MANAGER_H
#define VESC_MANAGER_H

#include <stdbool.h>
#include "vesc_uart.h"

void vesc_manager_init(int tx_pin, int rx_pin);
bool vesc_manager_is_connected(void);
bool vesc_manager_get_latest_data(vesc_data_t* out);
void vesc_manager_set_profile(int profile_id);

#endif // VESC_MANAGER_H
