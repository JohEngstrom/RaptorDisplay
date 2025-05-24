#include "actions.h"
#include "ui/ui.h"
#include "ui/screens.h"

void action_load_settings_screen_handler(lv_event_t *e) {
    // TODO: Check if we're in an unlocked state
    // TODO: Check if we're already in the settings screen
    lv_scr_load(objects.settings_screen);
}

void action_load_home_advanced_screen_handler(lv_event_t *e) {
    // TODO: Check if we're in an unlocked state
    // TODO: Check if we're already in the home advanced screen
    lv_scr_load(objects.home_advanced);
}

void action_load_home_basic_screen_handler(lv_event_t *e) {
    // TODO: Check if we're in an unlocked state
    // TODO: Check if we're already in the home basic screen
    lv_scr_load(objects.home_basic);
}
