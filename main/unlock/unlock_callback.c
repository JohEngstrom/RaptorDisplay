#include "unlock/unlock_manager.h"
#include "vesc_manager.h"
#include "ui/ui.h"
#include "ui/screens.h"

// This function overrides the weak one in unlock_manager.c
void unlock_manager_on_state_change(lock_state_t state)
{
    if (state == LOCK_STATE_BASIC) {
        vesc_manager_set_profile(1);               // Set VESC profile to WALK
        loadScreen(SCREEN_ID_HOME_BASIC);               // Show home_basic screen
    } else if (state == LOCK_STATE_ADVANCED) {
        // vesc_manager_set_profile(4);               // Set VESC profile to UNLOCKED or ADVANCED
        loadScreen(SCREEN_ID_HOME_ADVANCED);            // Show advanced screen (if you have this function)
    } else { // LOCK_STATE_PARKED
        vesc_manager_set_profile(0);               // Back to PARK
        loadScreen(SCREEN_ID_MAIN);                     // Show lock screen
    }
}
