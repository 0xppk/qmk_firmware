#pragma once

#include "quantum.h"

#if defined(HHKB_ENABLE)
#    include "hhkb/hhkb.h"
#endif

#if defined(MINIMI_ENABLE)
#    include "minimi/minimi.h"
#endif

enum layers {
    _BASE,
    _LAYER1,
    _LAYER2,
    _LAYER3,
};

enum tap_dance_keycodes {
    FN_UTIL,
    ENT_UTIL,
    LCTRL_UTIL,
    LSFT_CWTG,
    LOPT_DEL,
    LCMD_KOR,
};

#define KC_SOMETHING LGUI(KC_TAB)

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);
void       x_finished(tap_dance_state_t *state, void *user_data);
void       x_reset(tap_dance_state_t *state, void *user_data);
bool       process_record_keymap(uint16_t keycode, keyrecord_t *record);
