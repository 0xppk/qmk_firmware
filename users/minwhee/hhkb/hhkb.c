#include "quantum.h"
#include "hhkb.h"
#include "minwhee.h"

__attribute__((weak)) bool dip_switch_update_mask_keymap(uint32_t state) {
    return true;
}

//! 캡스워드 LED
void caps_word_set_user(bool active) {
    writePin(A8, active);
}

//! 딥스위치
bool dip_switch_update_mask_user(uint32_t state) {
    keymap_config.raw = eeconfig_read_keymap();

    hhkb_dip_switch_config.layout = state & (3UL << 0);
    hhkb_dip_switch_config.sw3    = state & (1UL << 2);
    hhkb_dip_switch_config.sw4    = state & (1UL << 3);
    hhkb_dip_switch_config.sw5    = state & (1UL << 4);
    hhkb_dip_switch_config.sw6    = state & (1UL << 5);

    if (hhkb_dip_switch_config.layout == INVALID) {
        hhkb_dip_switch_config.layout = HHKB;
    }

    keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = hhkb_dip_switch_config.sw5;
    // if (hhkb_dip_switch_config.layout == WINDOWS) {
    //     keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = true;
    // }

    eeconfig_update_keymap(keymap_config.raw);
    clear_keyboard();

    return dip_switch_update_mask_keymap(state);
}

// bool process_record_hhkb(uint16_t keycode, keyrecord_t *record) {}
