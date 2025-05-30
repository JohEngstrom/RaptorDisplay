#include "vesc_manager.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "vesc_uart_write.h"

static vesc_data_t g_vesc_data = {0};
static bool g_vesc_connected = false;

static void vesc_poll_task(void *pvParameter)
{
    while (1) {
        g_vesc_connected = vesc_uart_poll(&g_vesc_data);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void vesc_manager_init(int tx_pin, int rx_pin)
{
    vesc_uart_init(tx_pin, rx_pin);
    xTaskCreatePinnedToCore(vesc_poll_task, "vesc_poll_task", 4096, NULL, 5, NULL, 1);
}

bool vesc_manager_is_connected(void)
{
    return g_vesc_connected;
}

bool vesc_manager_get_latest_data(vesc_data_t* out)
{
    if (!g_vesc_connected) return false;
    if (out) *out = g_vesc_data;
    return true;
}

void vesc_manager_set_profile(int profile_id)
{
    printf("Switching VESC profile to %d\n", profile_id);
    vesc_set_profile((uint8_t)profile_id);
}
