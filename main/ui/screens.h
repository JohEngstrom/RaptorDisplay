#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *home_basic;
    lv_obj_t *home_advanced;
    lv_obj_t *settings_screen;
    lv_obj_t *root_panel_lock;
    lv_obj_t *padlock_panel;
    lv_obj_t *lock_status;
    lv_obj_t *lock_status_locked;
    lv_obj_t *lock_status_unlocked;
    lv_obj_t *panel_unlock_instructions;
    lv_obj_t *obj0;
    lv_obj_t *unlock_indicator_panel_lock;
    lv_obj_t *unlock_indicator_lock;
    lv_obj_t *root_panel_basic;
    lv_obj_t *top_bar_panel_basic;
    lv_obj_t *battery_panel_basic;
    lv_obj_t *battery_icon_panel_basic;
    lv_obj_t *battery_slider_panel_basic;
    lv_obj_t *battery_slider_basic;
    lv_obj_t *battery_value_panel_basic;
    lv_obj_t *battery_value_basic;
    lv_obj_t *vesc_connection_panel_basic;
    lv_obj_t *vesc_connected_icon_basic;
    lv_obj_t *vesc_disconnected_icon_basic;
    lv_obj_t *indicator_panel_basic;
    lv_obj_t *indicator_left_basic;
    lv_obj_t *indicator_right_basic;
    lv_obj_t *head_light_panel_basic;
    lv_obj_t *light_half_icon_basic;
    lv_obj_t *light_full_icon_basic;
    lv_obj_t *speed_gauge_panel_basic;
    lv_obj_t *speed_arc_basic;
    lv_obj_t *speed_value_label_basic;
    lv_obj_t *speed_unit_label_basic;
    lv_obj_t *bottom_bar_panel_basic;
    lv_obj_t *odometer_panel_basic;
    lv_obj_t *trip_panel_basic;
    lv_obj_t *trip_label_basic;
    lv_obj_t *trip_value_basic;
    lv_obj_t *odo_panel_basic;
    lv_obj_t *odo_label_basic;
    lv_obj_t *odo_value_basic;
    lv_obj_t *unlock_indicator_panel_basic;
    lv_obj_t *unlock_indicator_basic;
    lv_obj_t *panel_template;
    lv_obj_t *root_panel_advanced;
    lv_obj_t *top_bar_panel_advanced;
    lv_obj_t *battery_panel_advanced;
    lv_obj_t *battery_icon_panel_advanced;
    lv_obj_t *battery_slider_panel_advanced;
    lv_obj_t *battery_slider_advanced;
    lv_obj_t *battery_value_panel_advanced;
    lv_obj_t *battery_value_advanced;
    lv_obj_t *vesc_connection_panel_advanced;
    lv_obj_t *vesc_connected_icon_advanced;
    lv_obj_t *vesc_disconnected_icon_advanced;
    lv_obj_t *indicator_panel_advanced;
    lv_obj_t *head_light_panel_advanced;
    lv_obj_t *light_half_icon_advanced;
    lv_obj_t *light_full_icon_advanced;
    lv_obj_t *speed_gauge_panel_advanced;
    lv_obj_t *speed_arc_advanced;
    lv_obj_t *speed_value_label_advanced;
    lv_obj_t *speed_unit_label_advanced;
    lv_obj_t *power_gauge_panel_advanced;
    lv_obj_t *power_arc_advanced;
    lv_obj_t *power_value_label_advanced;
    lv_obj_t *power_unit_label_advanced;
    lv_obj_t *bottom_bar_panel_advanced;
    lv_obj_t *odometer_panel_advanced;
    lv_obj_t *trip_panel_advanced;
    lv_obj_t *trip_label_advanced;
    lv_obj_t *trip_value_advanced;
    lv_obj_t *odo_panel_advanced;
    lv_obj_t *odo_label_advanced;
    lv_obj_t *odo_value_advanced;
    lv_obj_t *settings_panel;
    lv_obj_t *root_panel_settings;
    lv_obj_t *tabview_settings;
    lv_obj_t *mode_buttons;
    lv_obj_t *mode_btn_walk;
    lv_obj_t *mode_btn_tractor;
    lv_obj_t *mode_btn_cycle;
    lv_obj_t *mode_btn_unlocked;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_HOME_BASIC = 2,
    SCREEN_ID_HOME_ADVANCED = 3,
    SCREEN_ID_SETTINGS_SCREEN = 4,
};

void create_screen_main();
void tick_screen_main();

void create_screen_home_basic();
void tick_screen_home_basic();

void create_screen_home_advanced();
void tick_screen_home_advanced();

void create_screen_settings_screen();
void tick_screen_settings_screen();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/