#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_background;
extern const lv_img_dsc_t img_battery_icon_fill;
extern const lv_img_dsc_t img_battery_icon;
extern const lv_img_dsc_t img_connection_icon_disconnected;
extern const lv_img_dsc_t img_connection_icon_connected;
extern const lv_img_dsc_t img_power_bg;
extern const lv_img_dsc_t img_speed_bg;
extern const lv_img_dsc_t img_power_arc;
extern const lv_img_dsc_t img_speed_arc;
extern const lv_img_dsc_t img_indicator_right;
extern const lv_img_dsc_t img_indicator_left;
extern const lv_img_dsc_t img_blank_img;
extern const lv_img_dsc_t img_settings_icon;
extern const lv_img_dsc_t img_light_full_icon;
extern const lv_img_dsc_t img_light_half_icon;
extern const lv_img_dsc_t img_pad_lock_icon;
extern const lv_img_dsc_t img_mode_button_unlocked;
extern const lv_img_dsc_t img_mode_button_cycle;
extern const lv_img_dsc_t img_mode_button_tractor;
extern const lv_img_dsc_t img_mode_button_walk;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[20];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/