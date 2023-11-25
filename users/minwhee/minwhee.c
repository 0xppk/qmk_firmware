#include "minwhee.h"
#include "quantum.h"

// Keymap-specific process_record_user()
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

//! 오버라이드
const key_override_t up_key= ko_make_basic(MOD_MASK_CTRL, KC_W, KC_UP);
const key_override_t down_key= ko_make_basic(MOD_MASK_CTRL, KC_S, KC_DOWN);
const key_override_t left_key= ko_make_basic(MOD_MASK_CTRL, KC_A, KC_LEFT);
const key_override_t right_key= ko_make_basic(MOD_MASK_CTRL, KC_D, KC_RIGHT);
const key_override_t drag_up_key= ko_make_basic(MOD_MASK_CTRL, KC_W, LSFT(KC_UP));
const key_override_t drag_down_key= ko_make_basic(MOD_MASK_CTRL, KC_S, LSFT(KC_DOWN));
const key_override_t drag_left_key= ko_make_basic(MOD_MASK_CTRL, KC_A, LSFT(KC_LEFT));
const key_override_t drag_right_key= ko_make_basic(MOD_MASK_CTRL, KC_D, LSFT(KC_RIGHT));
const key_override_t delete_line_key= ko_make_basic(MOD_MASK_CTRL, KC_X, SGUI(KC_K));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
  &up_key,
  &down_key,
  &left_key,
  &right_key,
  &drag_up_key,
  &drag_down_key,
  &drag_left_key,
  &drag_right_key,
  &delete_line_key,
  NULL
};

//! 탭댄스
td_state_t cur_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
  } else if (state->count == 2) {
    if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
    else if (state->pressed) return TD_DOUBLE_HOLD;
    else return TD_DOUBLE_TAP;
  }
  else return TD_UNKNOWN;
}

static td_tap_t LCMD_TD = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t LOPT_TD = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t LCTRL_TD = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t BS_TD = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t ESC_TD = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t FN_TD = {
  .is_press_action = true,
  .state = TD_NONE
};
static td_tap_t ENT_TD = {
  .is_press_action = true,
  .state = TD_NONE
};

void lcmd_finished(tap_dance_state_t *state, void *user_data) {
  LCMD_TD.state = cur_dance(state);
  switch (LCMD_TD.state) {
    case TD_SINGLE_TAP: register_code(KC_TAB); break;
    case TD_SINGLE_HOLD: register_code(KC_LCMD); break;
    case TD_DOUBLE_TAP: tap_code(KC_LCMD); register_code(KC_LCMD); break;
    case TD_DOUBLE_HOLD: register_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: tap_code(KC_LCMD); register_code(KC_LCMD); break;
    default: break;
  }
}

void lcmd_reset(tap_dance_state_t *state, void *user_data) {
  switch (LCMD_TD.state) {
    case TD_SINGLE_TAP: unregister_code(KC_TAB); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LCMD); break;
    case TD_DOUBLE_TAP: unregister_code(KC_LCMD); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_LCMD); break;
    default: break;
  }
  LCMD_TD.state = TD_NONE;
}

void lopt_finished(tap_dance_state_t *state, void *user_data) {
  LOPT_TD.state = cur_dance(state);
  switch (LOPT_TD.state) {
    case TD_SINGLE_TAP: register_code(KC_DEL); break;
    case TD_SINGLE_HOLD: register_code(KC_LOPT); break;
    case TD_DOUBLE_TAP: tap_code(KC_LOPT); register_code(KC_LOPT); break;
    case TD_DOUBLE_HOLD: register_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: tap_code(KC_LOPT); register_code(KC_LOPT); break;
    default: break;
  }
}

void lopt_reset(tap_dance_state_t *state, void *user_data) {
  switch (LOPT_TD.state) {
    case TD_SINGLE_TAP: unregister_code(KC_DEL); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LOPT); break;
    case TD_DOUBLE_TAP: unregister_code(KC_LOPT); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_LOPT); break;
    default: break;
  }
  LOPT_TD.state = TD_NONE;
}

void lctrl_finished(tap_dance_state_t *state, void *user_data) {
  LCTRL_TD.state = cur_dance(state);
  switch (LCTRL_TD.state) {
    case TD_SINGLE_TAP: register_code(KC_LCTL); break;
    case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
    case TD_DOUBLE_TAP: register_code16(OSM(MOD_HYPR)); break;
    case TD_DOUBLE_HOLD: register_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_LCTL); break;
    default: break;
  }
}

void lctrl_reset(tap_dance_state_t *state, void *user_data) {
  switch (LCTRL_TD.state) {
    case TD_SINGLE_TAP: unregister_code(KC_LCTL); break;
    case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
    case TD_DOUBLE_TAP: unregister_code16(OSM(MOD_HYPR));
    case TD_DOUBLE_HOLD: unregister_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_LCTL); break;
    default: break;
  }
  LCTRL_TD.state = TD_NONE;
}

void bs_finished(tap_dance_state_t *state, void *user_data) {
  BS_TD.state = cur_dance(state);
  switch (BS_TD.state) {
    case TD_SINGLE_TAP: register_code16(LOPT(KC_BSPC)); break;
    case TD_SINGLE_HOLD: register_code16(LOPT(KC_BSPC)); break;
    case TD_DOUBLE_TAP: tap_code16(LOPT(KC_BSPC)); register_code16(LOPT(KC_BSPC)); break;
    case TD_DOUBLE_HOLD: register_code16(KC_F13); break;
    case TD_DOUBLE_SINGLE_TAP: tap_code16(LOPT(KC_BSPC)); register_code16(LOPT(KC_BSPC)); break;
    default: break;
  }
}

void bs_reset(tap_dance_state_t *state, void *user_data) {
  switch (BS_TD.state) {
    case TD_SINGLE_TAP: unregister_code16(LOPT(KC_BSPC)); break;
    case TD_SINGLE_HOLD: unregister_code16(LOPT(KC_BSPC)); break;
    case TD_DOUBLE_TAP: unregister_code16(LOPT(KC_BSPC)); break;
    case TD_DOUBLE_HOLD: unregister_code16(KC_F13); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code16(LOPT(KC_BSPC)); break;
    default: break;
  }
  BS_TD.state = TD_NONE;
}

void esc_finished(tap_dance_state_t *state, void *user_data) {
  ESC_TD.state = cur_dance(state);
  switch (ESC_TD.state) {
    case TD_SINGLE_TAP: register_code(KC_ESC); break;
    case TD_SINGLE_HOLD: register_code16(LSA(KC_O)); break;
    case TD_DOUBLE_TAP: register_code16(LGUI(KC_DOT)); break;
    case TD_DOUBLE_HOLD: register_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: tap_code(KC_ESC); register_code(KC_ESC); break;
    default: break;
  }
}

void esc_reset(tap_dance_state_t *state, void *user_data) {
  switch (ESC_TD.state) {
    case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
    case TD_SINGLE_HOLD: unregister_code16(LSA(KC_O)); break;
    case TD_DOUBLE_TAP: unregister_code16(LGUI(KC_DOT)); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_ESC); break;
    default: break;
  }
  ESC_TD.state = TD_NONE;
}

void fn_finished(tap_dance_state_t *state, void *user_data) {
  FN_TD.state = cur_dance(state);
  switch (FN_TD.state) {
    case TD_SINGLE_TAP: register_code(KC_INS); break;
    case TD_SINGLE_HOLD: register_code(KC_EJCT); break;
    case TD_DOUBLE_TAP: tap_code(KC_ROPT); register_code(KC_ROPT); break;
    case TD_DOUBLE_HOLD: register_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: tap_code(KC_INS); register_code(KC_INS); break;
    default: break;
  }
}

void fn_reset(tap_dance_state_t *state, void *user_data) {
  switch (FN_TD.state) {
    case TD_SINGLE_TAP: unregister_code(KC_INS); break;
    case TD_SINGLE_HOLD: unregister_code(KC_EJCT); break;
    case TD_DOUBLE_TAP: unregister_code(KC_ROPT); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_INS); break;
    default: break;
  }
  FN_TD.state = TD_NONE;
}

void ent_finished(tap_dance_state_t *state, void *user_data) {
  ENT_TD.state = cur_dance(state);
  switch (ENT_TD.state) {
    case TD_SINGLE_TAP: register_code(KC_MPLY); break;
    case TD_SINGLE_HOLD: register_code(KC_F19); break;
    case TD_DOUBLE_TAP: register_code(KC_TRNS); break;
    case TD_DOUBLE_HOLD: register_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_TRNS); break;
    default: break;
  }
}

void ent_reset(tap_dance_state_t *state, void *user_data) {
  switch (ENT_TD.state) {
    case TD_SINGLE_TAP: unregister_code(KC_MPLY); break;
    case TD_SINGLE_HOLD: unregister_code(KC_F19); break;
    case TD_DOUBLE_TAP: unregister_code(KC_TRNS); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_TRNS); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_TRNS); break;
    default: break;
  }
  ENT_TD.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_LCMD_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lcmd_finished, lcmd_reset),
  [TD_LOPT_DEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lopt_finished, lopt_reset),
  [TD_CTRL_UTIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lctrl_finished, lctrl_reset),
  [TD_BS_UTIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bs_finished, bs_reset),
  [TD_ESC_UTIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset),
  [TD_ENT_UTIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_finished, ent_reset),
  [TD_FN_UTIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
};


//! 방향키 오버라이드
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_keymap(keycode, record)) return false;

  switch (keycode) {
    case KC_I:
      if (get_mods() == MOD_BIT(KC_LALT) || get_mods() == MOD_BIT(KC_LGUI)) {
        if (record->event.pressed) {
          register_code(KC_UP);
        } else {
          unregister_code(KC_UP);  
        }
        return false;
      } 

    case KC_K:
      if (get_mods() == MOD_BIT(KC_LALT) || get_mods() == MOD_BIT(KC_LGUI)) {
        if (record->event.pressed) {
          register_code(KC_DOWN);
        } else {
          unregister_code(KC_DOWN);  
        }
        return false;
      }

    case KC_J:
      if (get_mods() == MOD_BIT(KC_LALT) || get_mods() == MOD_BIT(KC_LGUI)) {
        if (record->event.pressed) {
          register_code(KC_LEFT);
        } else {
          unregister_code(KC_LEFT);  
        }
        return false;
      }

    case KC_L:
      if (get_mods() == MOD_BIT(KC_LALT) || get_mods() == MOD_BIT(KC_LGUI)) {
        if (record->event.pressed) {
          register_code(KC_RIGHT);
        } else {
          unregister_code(KC_RIGHT);  
        }
        return false;
      }

    return true;  
  }

  return true;
}
