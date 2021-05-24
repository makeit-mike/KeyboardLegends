/* Copyright 2020 AAClawson (AlisGraveNil)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
// TAP DANCE
enum {
  TD_INS_L = 0
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_INS_L] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_INS, 2)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
    * ------------------------------------
    * |INS |HOME|PGUP|NUM | /  | *  | -  |
    * ------------------------------------
    * |DEL |END |PGDN| 7  | 8  | 9  | +  |
    * ------------------------------|    |
    * |    |    |    | 4  | 5  | 6  |    |
    * ------------------------------------
    * |    | UP |    | 1  | 2  | 3  |ENT |
    * ------------------------------|    |
    * |LEFT|DOWN|RGHT| 0       | .  |    |
    * ------------------------------------
    */
    // Normal
    [0] = LAYOUT(
 TD(TD_INS_L),  KC_HOME, KC_PGUP,        OSL(3), KC_SLASH,  KC_PAST,   KC_MINS,
        KC_DEL,  KC_END,  KC_PGDN,        KC_7,    KC_8,     KC_9,     KC_PPLS,
                                          KC_4,    KC_5,     KC_6,
                 KC_UP,                   KC_1,    KC_2,     KC_3,    LT(1, KC_PENT),
      LT(1, KC_LEFT)  , KC_DOWN, KC_RGHT,        KC_0,            KC_PDOT
    ),
    // Windows shortcuts
    [1] = LAYOUT(
        KC_ESC,  KC_MYCM, LALT(KC_D),     KC_CALC,    _______,   _______,  _______,
        KC_DEL,  KC_SLEP, KC_PGDN,        _______,    _______,   _______,  KC_EQL,
                                          _______,    _______,   _______,
                 KC_VOLU,                 _______,    _______,   _______,  KC_EQL,
      KC_LEFT  , KC_VOLD, KC_MUTE,        KC_MPLY,            _______
    ),
    // Text manipulation
    [2] = LAYOUT(
        _______,      _______, _______,     _______,    _______,   _______,  _______,
        C(KC_DEL),    _______, _______,     _______,    _______,   _______,  _______,
                                            _______,    _______,   _______,
                    KC_UP,                  _______,    _______,   _______,  _______,
        C(KC_LEFT), KC_DOWN, C(KC_RGHT),    _______,            _______
    ),
    [3] = LAYOUT(
    TG(0),    _______, _______,      OSM(MOD_LSFT),S(KC_SLASH),   KC_PAST, S(KC_MINS),
    KC_F17 ,  _______, _______,            S(KC_7),   S(KC_8),    S(KC_9),    KC_PPLS,
                                           S(KC_4),   S(KC_5),    S(KC_6),
               _______,                    S(KC_1),   S(KC_2),    S(KC_3),    KC_PENT,
    _______  , _______, _______,           S(KC_0),            _______
    ),
};
