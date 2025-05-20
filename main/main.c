#define LV_MEM_CUSTOM 1
#define LV_MEMCPY_MEMSET_STD 1
#define LV_ATTRIBUTE_FAST_MEM IRAM_ATTR


#include "waveshare_rgb_lcd_port.h"
#include "ui/ui.h"

void app_main()
{
    waveshare_esp32_s3_rgb_lcd_init(); // Initializes the Waveshare ESP32-S3 RGB LCD & Touch Controller
    wavesahre_rgb_lcd_bl_on();  // Turn on the backlight through the IO Expander
}
