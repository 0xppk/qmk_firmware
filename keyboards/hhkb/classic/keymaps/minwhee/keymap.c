#include QMK_KEYBOARD_H
#include "minwhee.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_60_hhkb(
      TD(ESC_UTIL)  , KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRV,  KC_BSPC,
      LT(2, KC_ESC) ,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,  KC_P, KC_LBRC, KC_RBRC, LOPT(KC_BSPC),
      TD(LCTRL_UTIL),   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,  KC_QUOT,       KC_ENT      ,
      TD(LSFT_CWTG) ,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), LM(1, MOD_LSFT), TD(FN_UTIL),
                 TD(LOPT_DEL), TD(LCMD_TAB),              KC_SPC,            RSG_T(KC_F18), LT(1, KC_BSLS)
    ),

    [_SPLIT] = LAYOUT_60_hhkb(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_1  ,  KC_2  ,  KC_3  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,     KC_TRNS    ,
        KC_TRNS,    KC_4  ,  KC_5  ,  KC_6  , KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_GRV, KC_SCLN,  KC_QUOT,          KC_TRNS        ,
        KC_TRNS,     KC_7  ,  KC_8  ,  KC_9  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,        KC_TRNS     ,  KC_TRNS  ,
                    KC_TRNS,    KC_0,                              KC_TRNS,                         KC_TRNS,    KC_TRNS
    ),

    [_UTILS] = LAYOUT_60_hhkb(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_MPRV, KC_MPLY, KC_MNXT, LCAG(KC_R), LCAG(KC_T), LCAG(KC_Y), LCAG(KC_U), LCAG(KC_I), LCAG(KC_O),  S(KC_UP), LCAG(KC_LBRC), LCAG(KC_RBRC), LCAG(KC_0),
        KC_TRNS,   LCAG(KC_A), LCAG(KC_S), LCAG(KC_D), LCAG(KC_F), LCAG(KC_G), LCAG(KC_H), LCAG(KC_J), LCAG(KC_H), S(KC_LEFT), S(KC_DOWN), S(KC_RIGHT), LCAG(KC_9),
        KC_TRNS,    LCAG(KC_Z), LCAG(KC_X), LCAG(KC_C), LCAG(KC_V), LCAG(KC_B), LCAG(KC_N), LCAG(KC_M), LCAG(KC_COMM), LCAG(KC_DOT), LCAG(KC_SLSH), KC_TRNS,  KC_TRNS,
                  KC_TRNS,   KC_TRNS,                                LCAG(KC_SPC),                            LCAG(KC_1),    LCAG(KC_2)
    ),

    [_FN] = LAYOUT_60_hhkb(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLEP,
        KC_TRNS,   KC_F1  ,  KC_F2  ,  KC_F3  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_BRIU, KC_F12 ,   KC_F13,       KC_F14 ,
        KC_TRNS,    KC_F4  ,  KC_F5  ,  KC_F6  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KCBRID, KC_MNXT,          TD(ENT_UTIL),
        KC_TRNS,     KC_F7  ,  KC_F8  ,  KC_F9 , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F15 , KC_F16 ,        KC_F17     ,  KC_F18  ,
                   KC_F10 ,   KC_F11 ,                                    KC_TRNS,                              KC_TRNS,    KC_TRNS
    ),
};

//! 콤보는 아직 유저스페이스 지원이 안됨
const uint16_t PROGMEM cmd_i_combo[] = {KC_LCMD, KC_I, COMBO_END};
const uint16_t PROGMEM cmd_k_combo[] = {KC_LCMD, KC_K, COMBO_END};

combo_t key_combos[] = {
  [CMD_I] = COMBO(cmd_i_combo, LCMD(KC_UP)),
  [CMD_K] = COMBO(cmd_k_combo, LCMD(KC_DOWN)),
};
