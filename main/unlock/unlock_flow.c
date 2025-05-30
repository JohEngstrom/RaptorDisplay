#include "unlock_flow.h"
#include "unlock/unlock_manager.h"
#include "vesc_manager.h"
#include "ui/ui.h"
#include "ui/screens.h"
#include "lvgl.h"

// UI indicator color definitions
#define COLOR_ORANGE 0xFF9400
#define COLOR_GREEN  0x00FF00
#define COLOR_RED    0xFF0000

// State for handling the unlock transition
typedef enum {
    UF_WAITING,
    UF_NFC_PRESENTED,
    UF_UNLOCK_SUCCESS,
    UF_UNLOCK_FAILED,
    UF_UNLOCKED
} unlock_flow_state_t;

static unlock_flow_state_t state = UF_WAITING;
static uint32_t state_timestamp = 0; // milliseconds
static bool is_unlocked = false;

static void show_unlock_indicator(uint32_t color) {
    lv_obj_clear_flag(objects.unlock_indicator_lock, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_bg_color(objects.unlock_indicator_lock, lv_color_hex(color), LV_PART_MAIN);
}

static void hide_unlock_indicator(void) {
    lv_obj_add_flag(objects.unlock_indicator_lock, LV_OBJ_FLAG_HIDDEN);
}

void unlock_flow_init(void) {
    state = UF_WAITING;
    is_unlocked = false;
    lv_obj_clear_flag(objects.lock_status_locked, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.lock_status_unlocked, LV_OBJ_FLAG_HIDDEN);
    hide_unlock_indicator();
    // Show lock screen (if not already shown)
    lv_scr_load(objects.main);
    vesc_manager_set_profile(0); // PARK profile
}

bool unlock_flow_is_unlocked(void) {
    return is_unlocked;
}

// Call this periodically (every 100 ms or so)
void unlock_flow_poll(void) {
    static lock_state_t last_state = LOCK_STATE_PARKED;
    lock_state_t lock_state = unlock_manager_get_state();

    switch (state) {
        case UF_WAITING:
            // Waiting for tag presentation
            if (lock_state == LOCK_STATE_BASIC && last_state == LOCK_STATE_PARKED) {
                // Tag detected, valid BASIC unlock
                show_unlock_indicator(COLOR_GREEN);
                lv_obj_add_flag(objects.lock_status_locked, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(objects.lock_status_unlocked, LV_OBJ_FLAG_HIDDEN);
                state = UF_UNLOCK_SUCCESS;
                state_timestamp = lv_tick_get();
                vesc_manager_set_profile(1); // WALK profile
                is_unlocked = true;
            } else if (lock_state == LOCK_STATE_PARKED && last_state == LOCK_STATE_PARKED) {
                // Still waiting, no action
                hide_unlock_indicator();
            } else if (lock_state == LOCK_STATE_PARKED && last_state != LOCK_STATE_PARKED) {
                // Invalid tag was presented
                show_unlock_indicator(COLOR_RED);
                state = UF_UNLOCK_FAILED;
                state_timestamp = lv_tick_get();
            }
            break;

        case UF_UNLOCK_SUCCESS:
            // Show unlock indicator (green) and unlocked symbol for 2 seconds, then go to home_basic
            if (lv_tick_elaps(state_timestamp) > 2000) {
                lv_obj_add_flag(objects.lock_status_unlocked, LV_OBJ_FLAG_HIDDEN);
                hide_unlock_indicator();
                lv_scr_load(objects.home_basic);
                state = UF_UNLOCKED;
            }
            break;

        case UF_UNLOCK_FAILED:
            // Show red indicator for 1 second
            if (lv_tick_elaps(state_timestamp) > 1000) {
                hide_unlock_indicator();
                state = UF_WAITING;
            }
            break;

        case UF_UNLOCKED:
            // Do nothing, remain on home_basic
            break;

        case UF_NFC_PRESENTED:
        default:
            state = UF_WAITING;
            break;
    }

    last_state = lock_state;
}
