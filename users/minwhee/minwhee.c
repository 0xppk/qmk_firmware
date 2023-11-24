#include "minwhee.h"
#include "quantum.h"

// Keymap-specific process_record_user()
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_RCG_T(uint16_t keycode, keyrecord_t *record) {
    switch (record->event.pressed) {
        case true:
            register_code(MOD_RCTL);
            register_code(MOD_RGUI);
            break;
        case false:
            unregister_code(MOD_RCTL);
            unregister_code(MOD_RGUI);
            break;
    }
    return true;
}

//! 컨트롤러
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) return false;
    
    switch (keycode) {
        case RCG_T(KC_KP_ENTER):
            return process_RCG_T(KC_KP_ENTER, record);
            break;

        // case KC_ESCAPE:
        //     if (record->event.pressed) {
        //         uint8_t temp_mod = get_mods();
        //         uint8_t temp_osm = get_oneshot_mods();
        //         clear_mods();
        //         clear_oneshot_mods();
        //         if ((temp_mod | temp_osm) & (MOD_BIT(KC_LEFT_SHIFT) & MOD_BIT(KC_RIGHT_SHIFT))) {
        //             tap_code16(QK_BOOT);
        //         }
        //         set_mods(temp_mod);
        //     }
        //     break;
    }

    return true;
}
