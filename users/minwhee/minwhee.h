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
  _FN,
  _UTILS,
};

enum tap_dance_keycodes {
  ESC_UTIL,
  FN_UTIL,
  ENT_UTIL,
  LCMD_CWTG,
  LOPT_DEL,
  COMM_DOT_SLSH,
};

typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD,
  TD_DOUBLE_SINGLE_TAP,
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

