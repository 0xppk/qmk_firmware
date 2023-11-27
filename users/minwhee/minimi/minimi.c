#include "quantum.h"
#include "minimi.h"
#include "minwhee.h"

bool process_record_minimi(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_NO):
            if (record->tap.count && !record->event.pressed) {
                tap_code(KC_BSPC);
            } else if (record->tap.count == 1 && record->event.pressed) {
                layer_on(_FN);
            } else if (record->tap.count == 2 && record->event.pressed) {
                layer_on(_FN);
                register_mods(MOD_BIT(KC_LSFT));
            } else if (record->tap.count == 2 && !record->event.pressed) {
                unregister_mods(MOD_BIT(KC_LSFT));
                layer_off(_FN);
            } else if (record->tap.count == 1 && !record->event.pressed) {
                layer_off(_FN);
            }
            return false;
            break;
        }
    return true;
}
