#ifndef UNLOCK_PROTOCOL_H
#define UNLOCK_PROTOCOL_H

#include <stdint.h>

// App-level lock states
typedef enum {
    LOCK_STATE_PARKED = 0,   // Locked, VESC in PARK profile, lock screen shown
    LOCK_STATE_BASIC,        // WALK profile, home_basic shown
    LOCK_STATE_ADVANCED      // ADVANCED profile, home_advanced shown
} lock_state_t;

// Unlock types sent from the NFC ESP32 over I2C
typedef enum {
    UNLOCK_NONE = 0,
    UNLOCK_BASIC = 1,
    UNLOCK_ADVANCED = 2
} unlock_type_t;

// Message sent over I2C
typedef struct {
    unlock_type_t unlock_type;
    uint8_t uid[8];       // UID of tag, 8 is max for MIFARE cards; adjust as needed
    uint8_t uid_len;      // Actual UID length
} unlock_msg_t;

#endif // UNLOCK_PROTOCOL_H
