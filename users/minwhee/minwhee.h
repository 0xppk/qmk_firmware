#pragma once

#include "quantum.h"
// clang-format off
#define FN  MO(_FN)
#define RCG_T(kc) (MT(MOD_RCTL | MOD_RGUI, kc))

enum layers {
    _BASE,
    _FN,
};

enum userspace_keycodes {
    RCG_T,
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
