#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_load_settings_screen_handler(lv_event_t * e);
extern void action_load_home_advanced_screen_handler(lv_event_t * e);
extern void action_load_home_basic_screen_handler(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/