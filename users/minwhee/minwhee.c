#include "minwhee.h"
#include "quantum.h"

// Keymap-specific process_record_user()
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

//! 오버라이드
const key_override_t up_key             = ko_make_basic(MOD_MASK_CTRL, KC_W, KC_UP);
const key_override_t down_key           = ko_make_basic(MOD_MASK_CTRL, KC_S, KC_DOWN);
const key_override_t left_key           = ko_make_basic(MOD_MASK_CTRL, KC_A, KC_LEFT);
const key_override_t right_key          = ko_make_basic(MOD_MASK_CTRL, KC_D, KC_RIGHT);
const key_override_t drag_up_key        = ko_make_basic(MOD_MASK_CTRL, KC_I, LSFT(KC_UP));
const key_override_t drag_down_key      = ko_make_basic(MOD_MASK_CTRL, KC_K, LSFT(KC_DOWN));
const key_override_t drag_left_key      = ko_make_basic(MOD_MASK_CTRL, KC_J, LSFT(KC_LEFT));
const key_override_t drag_right_key     = ko_make_basic(MOD_MASK_CTRL, KC_L, LSFT(KC_RIGHT));
const key_override_t opt_up_key         = ko_make_basic(MOD_MASK_ALT, KC_I, LOPT(KC_UP));
const key_override_t opt_down_key       = ko_make_basic(MOD_MASK_ALT, KC_K, LOPT(KC_DOWN));
const key_override_t opt_left_key       = ko_make_basic(MOD_MASK_ALT, KC_J, LOPT(KC_LEFT));
const key_override_t opt_right_key      = ko_make_basic(MOD_MASK_ALT, KC_L, LOPT(KC_RIGHT));
const key_override_t drag_opt_up_key    = ko_make_basic(MOD_MASK_SHIFT | MOD_MASK_ALT, KC_I, LSA(KC_UP));
const key_override_t drag_opt_down_key  = ko_make_basic(MOD_MASK_SHIFT | MOD_MASK_ALT, KC_K, LSA(KC_DOWN));
const key_override_t drag_opt_left_key  = ko_make_basic(MOD_MASK_SHIFT | MOD_MASK_ALT, KC_J, LSA(KC_LEFT));
const key_override_t drag_opt_right_key = ko_make_basic(MOD_MASK_SHIFT | MOD_MASK_ALT, KC_L, LSA(KC_RIGHT));
// const key_override_t cmd_up_key         = ko_make_basic(MOD_MASK_GUI, KC_I, LCMD(KC_UP));
// const key_override_t cmd_down_key       = ko_make_basic(MOD_MASK_GUI, KC_K, LCMD(KC_DOWN));
const key_override_t cmd_left_key       = ko_make_basic(MOD_MASK_GUI, KC_J, LCMD(KC_LEFT));
const key_override_t cmd_right_key      = ko_make_basic(MOD_MASK_GUI, KC_L, LCMD(KC_RIGHT));
const key_override_t drag_cmd_up_key    = ko_make_basic(MOD_MASK_SHIFT | MOD_MASK_GUI, KC_I, LSG(KC_UP));
const key_override_t drag_cmd_down_key  = ko_make_basic(MOD_MASK_SHIFT | MOD_MASK_GUI, KC_K, LSG(KC_DOWN));
const key_override_t drag_cmd_left_key  = ko_make_basic(MOD_MASK_SHIFT | MOD_MASK_GUI, KC_J, LSG(KC_LEFT));
const key_override_t drag_cmd_right_key = ko_make_basic(MOD_MASK_SHIFT | MOD_MASK_GUI, KC_L, LSG(KC_RIGHT));
const key_override_t delete_line_key    = ko_make_basic(MOD_MASK_CTRL, KC_X, SGUI(KC_K));

// clang-format off
const key_override_t **key_overrides = (const key_override_t *[]){
    &up_key,
    &down_key,
    &left_key,
    &right_key,
    &drag_up_key,
    &drag_down_key,
    &drag_left_key,
    &drag_right_key,
    &opt_up_key,
    &opt_down_key,
    &opt_left_key,
    &opt_right_key,
    &drag_opt_up_key,
    &drag_opt_down_key,
    &drag_opt_left_key,
    &drag_opt_right_key,
    // &cmd_up_key,
    // &cmd_down_key,
    &cmd_left_key,
    &cmd_right_key,
    &drag_cmd_up_key,
    &drag_cmd_down_key,
    &drag_cmd_left_key,
    &drag_cmd_right_key,
    &delete_line_key,
    NULL
};

//! 탭댄스
// clang-format on
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}

static td_tap_t LOPT_TD  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t ESC_TD   = {.is_press_action = true, .state = TD_NONE};
static td_tap_t FN_TD    = {.is_press_action = true, .state = TD_NONE};
static td_tap_t ENT_TD   = {.is_press_action = true, .state = TD_NONE};
static td_tap_t LSFT_TD  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t LCTRL_TD = {.is_press_action = true, .state = TD_NONE};
static td_tap_t LCMD_TD  = {.is_press_action = true, .state = TD_NONE};

void lopt_finished(tap_dance_state_t *state, void *user_data) {
    LOPT_TD.state = cur_dance(state);
    switch (LOPT_TD.state) {
        case TD_SINGLE_TAP:
            register_code(KC_DEL);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LOPT);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_LOPT);
            tap_code(KC_LOPT);
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_DEL);
            tap_code(KC_DEL);
            break;
        default:
            break;
    }
}

void lopt_reset(tap_dance_state_t *state, void *user_data) {
    switch (LOPT_TD.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_DEL);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LOPT);
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        default:
            break;
    }
    LOPT_TD.state = TD_NONE;
}

void lsft_finished(tap_dance_state_t *state, void *user_data) {
    LSFT_TD.state = cur_dance(state);
    switch (LSFT_TD.state) {
        case TD_SINGLE_TAP:
            caps_word_toggle();
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        case TD_TRIPLE_TAP:
            break;
        default:
            break;
    }
}

void lsft_reset(tap_dance_state_t *state, void *user_data) {
    switch (LSFT_TD.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        case TD_TRIPLE_TAP:
            break;
        default:
            break;
    }
    LSFT_TD.state = TD_NONE;
}

void lcmd_finished(tap_dance_state_t *state, void *user_data) {
    LCMD_TD.state = cur_dance(state);
    switch (LCMD_TD.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_PENT);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LCMD);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_LCMD);
            tap_code(KC_LCMD);
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_PENT);
            tap_code(KC_PENT);
            break;
        default:
            break;
    }
}

void lcmd_reset(tap_dance_state_t *state, void *user_data) {
    switch (LCMD_TD.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LCMD);
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        default:
            break;
    }
    LCMD_TD.state = TD_NONE;
}

void esc_finished(tap_dance_state_t *state, void *user_data) {
    ESC_TD.state = cur_dance(state);
    switch (ESC_TD.state) {
        case TD_SINGLE_TAP:
            register_code16(LSA(KC_O));
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_CAPS);
            break;
        case TD_DOUBLE_TAP:
            register_code16(LGUI(KC_DOT));
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        default:
            break;
    }
}

void esc_reset(tap_dance_state_t *state, void *user_data) {
    switch (ESC_TD.state) {
        case TD_SINGLE_TAP:
            unregister_code16(LSA(KC_O));
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_CAPS);
            break;
        case TD_DOUBLE_TAP:
            unregister_code16(LGUI(KC_DOT));
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        default:
            break;
    }
    ESC_TD.state = TD_NONE;
}

void fn_finished(tap_dance_state_t *state, void *user_data) {
    FN_TD.state = cur_dance(state);
    switch (FN_TD.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_LCTL);
            tap_code(KC_LCMD);
            tap_code(KC_SPC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(3);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(S(KC_INS));
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_CAPS);
            break;
        case TD_TRIPLE_TAP:
            tap_code16(S(KC_EJCT));
            break;
        default:
            break;
    }
}

void fn_reset(tap_dance_state_t *state, void *user_data) {
    switch (FN_TD.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            layer_off(3);
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_CAPS);
            break;
        case TD_TRIPLE_TAP:
            break;
        default:
            break;
    }
    FN_TD.state = TD_NONE;
}

void ent_finished(tap_dance_state_t *state, void *user_data) {
    ENT_TD.state = cur_dance(state);
    switch (ENT_TD.state) {
        case TD_SINGLE_TAP:
            tap_code16(LCMD(KC_I));
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_MPLY);
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        default:
            break;
    }
}

void ent_reset(tap_dance_state_t *state, void *user_data) {
    switch (ENT_TD.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        default:
            break;
    }
    ENT_TD.state = TD_NONE;
}

void lctrl_finished(tap_dance_state_t *state, void *user_data) {
    LCTRL_TD.state = cur_dance(state);
    switch (LCTRL_TD.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_TAB);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LCTL);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_TAB);
            tap_code(KC_TAB);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_ROPT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_TAB);
            tap_code(KC_TAB);
            break;
        case TD_TRIPLE_TAP:
            set_oneshot_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI));
            break;
        default:
            break;
    }
}

void lctrl_reset(tap_dance_state_t *state, void *user_data) {
    switch (LCTRL_TD.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_ROPT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        case TD_TRIPLE_TAP:
            break;
        default:
            break;
    }
    LCTRL_TD.state = TD_NONE;
}

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [LSFT_CWTG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_finished, lsft_reset),
    [LOPT_DEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lopt_finished, lopt_reset),
    [ESC_UTIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset),
    [ENT_UTIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_finished, ent_reset),
    [FN_UTIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
    [LCTRL_UTIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lctrl_finished, lctrl_reset),
    [LCMD_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lcmd_finished, lcmd_reset),
};

// clang-format on
//! 유저 인터페이스
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) return false;

    // switch (keycode) {
    //   case LT(0, KC_LSFT):
    //     if (record->tap.count && !record->event.pressed) {
    //       tap_code16(S(KC_LBRC));
    //     } else if (record->event.pressed) {
    //       register_code(KC_LSFT);
    //     } else {
    //       unregister_code(KC_LSFT);
    //     }
    //     break;
    // }

    return true;
}

//! 개별맞춤 탭 타임
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSG_T(KC_F18):
            return 100;
        default:
            return TAPPING_TERM;
    }
}
