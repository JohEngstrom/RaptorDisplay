#include <stdio.h>
#include "vesc_manager.h"
#include "ui/ui.h"
#include "ui/screens.h"

void update_ui_from_vesc(lv_timer_t * timer)
{
    vesc_data_t data;
    bool connected = vesc_manager_get_latest_data(&data);

    // Battery
    lv_slider_set_value(objects.battery_slider_basic, data.battery_percentage, LV_ANIM_OFF);
    lv_slider_set_value(objects.battery_slider_advanced, data.battery_percentage, LV_ANIM_OFF);

    char buf[16];

    snprintf(buf, sizeof(buf), "%.0f%%", data.battery_percentage);
    lv_label_set_text(objects.battery_value_basic, buf);
    lv_label_set_text(objects.battery_value_advanced, buf);

    // Speed
    snprintf(buf, sizeof(buf), "%.1f", data.speed_kmh);
    lv_label_set_text(objects.speed_value_label_basic, buf);
    lv_label_set_text(objects.speed_value_label_advanced, buf);

    // Speed arc (0-100)
    lv_arc_set_value(objects.speed_arc_basic, (int)data.speed_kmh);         // You may want to clamp to 0-100
    lv_arc_set_value(objects.speed_arc_advanced, (int)data.speed_kmh);

    // Power (Watts)
    snprintf(buf, sizeof(buf), "%.0f W", data.watts);
    lv_label_set_text(objects.power_value_label_advanced, buf);

    // Power arc (0=0W, 100=6000W)
    int power_pct = (int)(data.watts / 6000.0f * 100.0f);
    if (power_pct > 100) power_pct = 100;
    if (power_pct < 0) power_pct = 0;
    lv_arc_set_value(objects.power_arc_advanced, power_pct);

    // Trip and odometer
    snprintf(buf, sizeof(buf), "%.1f km", data.distance_session_km);
    lv_label_set_text(objects.trip_value_basic, buf);
    lv_label_set_text(objects.trip_value_advanced, buf);

    snprintf(buf, sizeof(buf), "%.1f km", data.distance_total_km);
    lv_label_set_text(objects.odo_value_basic, buf);
    lv_label_set_text(objects.odo_value_advanced, buf);

    // Connection indicators
    if (connected) {
        lv_obj_add_flag(objects.vesc_disconnected_icon_basic, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(objects.vesc_connected_icon_basic, LV_OBJ_FLAG_HIDDEN);

        lv_obj_add_flag(objects.vesc_disconnected_icon_advanced, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(objects.vesc_connected_icon_advanced, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(objects.vesc_connected_icon_basic, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(objects.vesc_disconnected_icon_basic, LV_OBJ_FLAG_HIDDEN);

        lv_obj_add_flag(objects.vesc_connected_icon_advanced, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(objects.vesc_disconnected_icon_advanced, LV_OBJ_FLAG_HIDDEN);
    }
}
