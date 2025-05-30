#pragma once

#include <stdbool.h>

// Call once at app startup
void unlock_flow_init(void);

// Call regularly from your main loop or LVGL timer (e.g. every 100 ms)
void unlock_flow_poll(void);

// Returns true if currently unlocked (i.e. in WALK/basic mode)
bool unlock_flow_is_unlocked(void);
