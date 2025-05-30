#ifndef UNLOCK_MANAGER_H
#define UNLOCK_MANAGER_H

#include "unlock_protocol.h"

// Initializes the unlock manager (call at startup)
void unlock_manager_init(void);

// Poll for unlock events (call regularly, e.g., in main loop or LVGL timer)
void unlock_manager_poll(void);

// Returns current lock state
lock_state_t unlock_manager_get_state(void);

#endif // UNLOCK_MANAGER_H
