#include QMK_KEYBOARD_H
#include "minwhee.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_60_hhkb(
    TD(TD_ESC_UTIL),  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,  KC_MINS,  KC_EQL,  KC_GRV,  KC_BSPC,
     LT(2, KC_TAB)  ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,  KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,  KC_LBRC, KC_RBRC,  TD(TD_BS_UTIL) ,
    TD(TD_CTRL_UTIL) ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,  KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN,  KC_QUOT,         KC_ENT          ,
          KC_LSFT     ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,  KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH,  RSFT_T(KC_BSLS) , TD(TD_FN_UTIL),
                       TD(TD_LOPT_DEL),  TD(TD_LCMD_TAB),                KC_SPC,               RCAG_T(KC_PENT),    LT(1, KC_CAPS)
    ),
    [_FN] = LAYOUT_60_hhkb(
        KC_ESC,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_SLEP,
        KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F10,  KC_F11, KC_BRIU, KC_F12 , KC_F13 ,     KC_F14     ,
        KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_BRID, KC_MNXT,     TD(TD_ENT_UTIL)    ,
        KC_TRNS,   KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F16 ,        KC_F15       ,  KC_F18  ,
                                  KC_TRNS, KC_TRNS,                   KC_TRNS,                  KC_TRNS, KC_TRNS
    ),

    [_UTILS] = LAYOUT_60_hhkb(
        KC_TRNS, LCAG(KC_1), LCAG(KC_2), LCAG(KC_3), LCAG(KC_4), LCAG(KC_5),  KC_TRNS  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  LCAG(KC_Q), LCAG(KC_W), LCAG(KC_E), LCAG(KC_R), LCAG(KC_T), LCAG(KC_Y), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS    ,
        KC_TRNS,   LCAG(KC_A), LCAG(KC_S), LCAG(KC_D), LCAG(KC_F), LCAG(KC_G),   KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS         ,
        KC_TRNS,    LCAG(KC_Z), LCAG(KC_X), LCAG(KC_C), LCAG(KC_V), LCAG(KC_B), LCAG(KC_N), KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS      ,  KC_TRNS  ,
                                  KC_TRNS, KC_TRNS,                   LCAG(KC_SPC),                  KC_TRNS, KC_TRNS
    ),
};