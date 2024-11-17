#include "quantum.h"
#include "minimi.h"
#include "minwhee.h"

// bool process_record_minimi(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT(0, KC_NO):
//             if (record->tap.count && !record->event.pressed) {
//                 tap_code(KC_BSPC);
//             } else if (record->tap.count == 1 && record->event.pressed) {
//                 layer_on(_FN);
//             } else if (record->tap.count == 2 && record->event.pressed) {
//                 layer_on(_FN);
//                 register_mods(MOD_BIT(KC_LSFT));
//             } else if (record->tap.count == 2 && !record->event.pressed) {
//                 unregister_mods(MOD_BIT(KC_LSFT));
//                 layer_off(_FN);
//             } else if (record->tap.count == 1 && !record->event.pressed) {
//                 layer_off(_FN);
//             }
//             return false;
//             break;
//     }
//     return true;
// }

// bool rgb_matrix_indicators_user(void) {
//     uint8_t current_layer = get_highest_layer(layer_state);
//     switch (current_layer) {
//         case _LAYER1:
//             rgb_matrix_set_color_all(0x00, 0x00, 0x00); // RGB blank
//             rgb_matrix_set_color(0, 0x00, 0x00, 0xFF);  // esc
//             rgb_matrix_set_color(1, 0x00, 0x00, 0xFF);  // 1
//             rgb_matrix_set_color(2, 0x00, 0x00, 0xFF);  // 2
//             rgb_matrix_set_color(3, 0x00, 0x00, 0xFF);  // 3
//             rgb_matrix_set_color(4, 0x00, 0x00, 0xFF);  // 4
//             rgb_matrix_set_color(5, 0x00, 0x00, 0xFF);  // 5
//             rgb_matrix_set_color(6, 0x00, 0x00, 0xFF);  // 6
//             rgb_matrix_set_color(7, 0x00, 0x00, 0xFF);  // 7
//             rgb_matrix_set_color(8, 0x00, 0x00, 0xFF);  // 8
//             rgb_matrix_set_color(9, 0x00, 0x00, 0xFF);  // 9
//             rgb_matrix_set_color(10, 0x00, 0x00, 0xFF); // 0
//             rgb_matrix_set_color(11, 0x00, 0x00, 0xFF); // -/_
//             rgb_matrix_set_color(12, 0x00, 0x00, 0xFF); // =/+

//             rgb_matrix_set_color(13, 0x00, 0x00, 0xFF); // backspace

//             rgb_matrix_set_color(15, 0x00, 0x00, 0xFF); // tab

//             rgb_matrix_set_color(22, 0x00, 0x00, 0xFF); // u
//             rgb_matrix_set_color(23, 0xFF, 0x00, 0x00); // i
//             rgb_matrix_set_color(24, 0x00, 0x00, 0xFF); // o
//             rgb_matrix_set_color(25, 0x00, 0x00, 0xFF); // p

//             rgb_matrix_set_color(28, 0x00, 0x00, 0xFF); // \/|

//             rgb_matrix_set_color(29, 0xFF, 0x00, 0x00); // del

//             rgb_matrix_set_color(30, 0x00, 0x00, 0xFF); // capslock

//             rgb_matrix_set_color(37, 0xFF, 0x00, 0x00); // j
//             rgb_matrix_set_color(38, 0xFF, 0x00, 0x00); // k
//             rgb_matrix_set_color(39, 0xFF, 0x00, 0x00); // l
//             rgb_matrix_set_color(40, 0x00, 0x00, 0xFF); // ;/:
//             rgb_matrix_set_color(41, 0x00, 0x00, 0xFF); // '/"

//             rgb_matrix_set_color(52, 0x00, 0x00, 0xFF); // m
//             rgb_matrix_set_color(53, 0xFF, 0x00, 0x00); // ,/<
//             rgb_matrix_set_color(54, 0x00, 0x00, 0xFF); // ./>
//             break;

//         case _LAYER2:
//             rgb_matrix_set_color_all(0x00, 0x00, 0x00); // RGB blank

//             rgb_matrix_set_color(7, 0xFF, 0xFF, 0x00);  // 7
//             rgb_matrix_set_color(8, 0xFF, 0xFF, 0x00);  // 8
//             rgb_matrix_set_color(9, 0xFF, 0xFF, 0x00);  // 9
//             rgb_matrix_set_color(10, 0xFF, 0xFF, 0x00); // 0

//             rgb_matrix_set_color(15, 0x00, 0x00, 0xFF); // tab

//             rgb_matrix_set_color(22, 0xFF, 0xFF, 0x00); // u
//             rgb_matrix_set_color(23, 0xFF, 0xFF, 0x00); // i
//             rgb_matrix_set_color(24, 0xFF, 0xFF, 0x00); // o
//             rgb_matrix_set_color(25, 0xFF, 0xFF, 0x00); // p

//             rgb_matrix_set_color(37, 0xFF, 0xFF, 0x00); // j
//             rgb_matrix_set_color(38, 0xFF, 0xFF, 0x00); // k
//             rgb_matrix_set_color(39, 0xFF, 0xFF, 0x00); // l
//             rgb_matrix_set_color(40, 0xFF, 0xFF, 0x00); // ;/:

//             rgb_matrix_set_color(43, 0x00, 0x00, 0xFF); // home

//             rgb_matrix_set_color(52, 0xFF, 0xFF, 0x00); // m
//             rgb_matrix_set_color(53, 0xFF, 0xFF, 0x00); // ,/<
//             rgb_matrix_set_color(54, 0xFF, 0xFF, 0x00); // ./>
//             rgb_matrix_set_color(55, 0xFF, 0xFF, 0x00); // //?

//             rgb_matrix_set_color(64, 0xFF, 0xFF, 0x00); // rightspace
//             rgb_matrix_set_color(65, 0xFF, 0xFF, 0x00); // rightalt
//             break;

//         case _LAYER3:
//             rgb_matrix_set_color_all(0x00, 0x00, 0x00); // RGB blank
//             rgb_matrix_set_color(17, 0xFF, 0x00, 0x00); // w
//             rgb_matrix_set_color(31, 0xFF, 0x00, 0x00); // a
//             rgb_matrix_set_color(32, 0xFF, 0x00, 0x00); // s
//             rgb_matrix_set_color(33, 0xFF, 0x00, 0x00); // d
//             rgb_matrix_set_color(43, 0x00, 0x00, 0xFF); // home
//             break;

//         default:
//             rgb_matrix_set_color_all(0x00, 0xFF, 0x00); // RGB green
//             break;
//     }
//     if (host_keyboard_led_state().caps_lock) {
//         rgb_matrix_set_color_all(0x8b, 0x00, 0x00); // RGB dark red --- capslock color
//     }
//     return false;
// }

// 2. 모디 따로
// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     HSV hsv = {0, 255, 255};

//     if (layer_state_is(layer_state, 2)) {
//         hsv = {130, 255, 255};
//     } else {
//         hsv = {30, 255, 255};
//     }

//     if (hsv.v > rgb_matrix_get_val()) {
//         hsv.v = rgb_matrix_get_val();
//     }
//     RGB rgb = hsv_to_rgb(hsv);

//     for (uint8_t i = led_min; i < led_max; i++) {
//         if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 == LED_FLAG_MODIFIER
//             rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//         }
//     }
//     return false;
// }

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     if (host_keyboard_led_state().caps_lock) {
//         RGB_MATRIX_INDICATOR_SET_COLOR(5, 255, 255, 255); // assuming caps lock is at led #5
//     } else {
//         RGB_MATRIX_INDICATOR_SET_COLOR(5, 0, 0, 0);
//     }
//     return false;
// }

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     for (uint8_t i = led_min; i < led_max; i++) {
//         switch (get_highest_layer(layer_state | default_layer_state)) {
//             case _LAYER1:
//                 rgb_matrix_set_color(i, RGB_BLUE);
//                 break;
//             case _LAYER2:
//                 rgb_matrix_set_color(i, RGB_YELLOW);
//                 break;
//             case _LAYER3:
//                 rgb_matrix_set_color(i, RGB_RED);
//                 break;
//             default:
//                 rgb_matrix_set_color(i, RGB_WHITE);
//                 break;
//         }
//     }
//     return false;
// }
