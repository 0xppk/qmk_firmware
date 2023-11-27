#pragma once

#include "quantum.h"

bool process_record_hhkb(uint16_t keycode, keyrecord_t *record);
bool dip_switch_update_mask_keymap(uint32_t state);

typedef union {
    struct {
        // This layout `uint8_t` is actually a 2-bit unsigned int which combines sw1 and sw2.
        // See the layouts enum for further details
        // Layouts:
        // [SW1: 0, SW2: 0] - HHKB
        // [SW1: 0, SW2: 1] - WINDOWS
        // [SW1: 1, SW2: 0] - MAC
        // [SW1: 1, SW2: 1] - INVALID (gets set back to HHKB)
        uint8_t layout : 2;
        // SW3: Swap Backspace and Delete.
        // On: Delete = 'BS'
        // Off: Delete = 'DEL'
        bool sw3 : 1;
        // SW4: Make Left ◇ a Fn key.
        // On: Left ◇ = 'Fn'
        // Off: Left ◇ = '◇'
        bool sw4 : 1;
        // SW5: Swap Alt and Gui keys.
        // On: ◇ = 'Alt', Alt = '◇'
        // Off: ◇ = '◇', Alt = 'Alt'
        bool sw5 : 1;
        // If possible, avoid using SW6 as it is used by dapboot for entering the bootloader on boot.
        bool sw6 : 1;
    };
} hhkb_dip_switch_config_t;

hhkb_dip_switch_config_t hhkb_dip_switch_config;

enum layouts { HHKB = 0, WINDOWS = 1, MAC = 2, INVALID = 3 };
