#include QMK_KEYBOARD_H
#include "minwhee.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = MINIMI40(
       LT(2, KC_TAB) ,    KC_Q    ,    KC_W    ,    KC_E    ,    KC_R    ,    KC_T    ,    KC_Y    ,    KC_U    ,    KC_I    ,    KC_O   ,    KC_P    ,  LOPT(KC_BSPC),
          SC_LCPO     ,    KC_A    ,    KC_S    ,    KC_D    ,    KC_F    ,    KC_G    ,    KC_H    ,    KC_J    ,    KC_K    ,    KC_L   ,           KC_ENT          ,
       LT(0,KC_LSFT)   ,    KC_Z    ,    KC_X    ,    KC_C    ,    KC_V    ,    KC_B    ,    KC_N    ,    KC_M    , TD(COMM_DOT_SLSH), LM(_FN, MOD_LSFT), RSFT_T(KC_BSLS), 
        TD(ESC_UTIL) ,  TD(LOPT_DEL),  TD(LCMD_CWTG),         KC_SPC       ,         LT(1, KC_BSPC)        ,   RSG_T(KC_PENT)   , LT(3, KC_CAPS) ,   TD(FN_UTIL)
    ),

    [_FN] = MINIMI40(
        KC_TRNS , KC_1,  KC_2,  KC_3,  KC_4,  KC_TRNS,  KC_TRNS,  KC_MINS,  KC_EQL,  KC_LBRC,  KC_RBRC,  KC_GRV,
        KC_TRNS  , KC_5,  KC_6,  KC_7,  KC_8,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_SCLN,  KC_QUOT,     KC_SLEP    ,
        KC_TRNS   , KC_9,  KC_0, KC_COMM, KC_DOT,  KC_SLSH,  KC_TRNS,  KC_TRNS,  KC_BSLS,  KC_TRNS,    KC_TRNS ,
        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS   ,           KC_TRNS          ,   KC_TRNS,  KC_TRNS,    KC_TRNS   
    ),

    [_UTILS] = MINIMI40(
        KC_TRNS , LCAG(KC_Q), LCAG(KC_W), LCAG(KC_E), LCAG(KC_R), LCAG(KC_T), LCAG(KC_Y) ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS  , LCAG(KC_A), LCAG(KC_S), LCAG(KC_D), LCAG(KC_F), LCAG(KC_G), LCAG(KC_H), KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS    ,
        KC_TRNS   , LCAG(KC_Z), LCAG(KC_X), LCAG(KC_C), LCAG(KC_V), LCAG(KC_B), LCAG(KC_N), KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS    ,
        KC_TRNS , KC_TRNS,    KC_TRNS    ,      LCAG(KC_SPC)      ,           KC_TRNS         ,   KC_TRNS   , KC_TRNS,    KC_TRNS   
    ),

    [_MEDIA] = MINIMI40(
        KC_TRNS , KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BRIU,  KC_MUTE,  KC_VOLD,  KC_VOLU,
        KC_TRNS  , KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_BRID,  KC_MPRV,   TD(ENT_UTIL)   ,
        KC_TRNS   , KC_F9, KC_F10, KC_F11, KC_F12,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_F15,   KC_F16,      KC_F18     ,
        KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS      ,           KC_TRNS          ,   KC_TRNS,  KC_TRNS,   KC_TRNS   
    ),

};