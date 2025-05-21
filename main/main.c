#define LV_MEM_CUSTOM 1
#define LV_MEMCPY_MEMSET_STD 1
#define LV_ATTRIBUTE_FAST_MEM IRAM_ATTR

#include "vesc_manager.h"
#include "waveshare_rgb_lcd_port.h"
#include "ui/ui.h"
#include "ui_update.h"

#define VESC_TX 43
#define VESC_RX 44

void app_main()
{
    vesc_manager_init(VESC_TX, VESC_RX);

    lv_init();
    
    waveshare_esp32_s3_rgb_lcd_init();
    waveshare_rgb_lcd_bl_on();

    ui_init();

    // Register LVGL timer to update UI from VESC data
    lv_timer_create(update_ui_from_vesc, 100, NULL);
}
