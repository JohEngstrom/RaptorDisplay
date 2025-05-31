#include <esp_log.h>
#include "unlock/unlock_manager.h"
#include "unlock/i2c_unlock.h"
#include <string.h>

static lock_state_t lock_state = LOCK_STATE_PARKED;

void unlock_manager_init(void) {
    i2c_unlock_init();
    lock_state = LOCK_STATE_PARKED;
}

void unlock_manager_poll(void) {
    unlock_msg_t msg;
    if (i2c_unlock_poll(&msg)) {
        if (msg.unlock_type == UNLOCK_BASIC) {
            lock_state = LOCK_STATE_BASIC;
        } else if (msg.unlock_type == UNLOCK_ADVANCED) {
            lock_state = LOCK_STATE_ADVANCED;
        } else {
            lock_state = LOCK_STATE_PARKED;
        }
    }
}

lock_state_t unlock_manager_get_state(void) {
    return lock_state;
}
