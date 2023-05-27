/* Copyright 2021 Choi Byungyoon <byungyoonc@gmail.com>
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
* along with this program.  If not, see &lt;http://www.gnu.org/licenses/&gt;.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┌───┬───┬───┬───┐
     * │ ` │ [ │Tab│ ] │Del│
     * ├───┼───┼───┼───┼───┤
     * │Esc│Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │Bsp│ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┤ + │
     * │Sft│ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┤
     * │Ctr│ 1 │ 2 │ 3 │   │
     * ├───┼───┴───┼───┤Ent│
     * │MO1│ 0     │ . │   │
     * └───┴───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_6x5(
        KC_GRAVE,  KC_LBRC, KC_TAB,  KC_RBRC, KC_DEL,
        KC_ESC,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_BSPC,   KC_P7,   KC_P8,   KC_P9,
        KC_LSFT,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LCTRL,  KC_P1,   KC_P2,   KC_P3,
        MO(1),     KC_P0,            KC_PDOT, KC_PENT
    ),

    /*
     * ┌───┌───┐───┬───┬───┐
     * │Rst│ ( │Tab│ ) │Del│
     * ├───┼───┘───┼───┼───┤
     * │Esc│Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │Bsp│BLT│   │Hom│   │
     * ├───┼───┼───┼───┤ + │
     * │Sft│   │ ↑ │End│   │
     * ├───┼───┼───┼───┤───┤
     * │Ctr│ ← │ ↓ │ → │   │
     * ├───┼───┴───┼───┤Ent│
     * │MO1│Insert │Del│   │
     * └───┴───────┴───┘───┘
     */
    [1] = LAYOUT_numpad_6x5(
        RESET,   KC_LPRN, _______, KC_RPRN, _______,
        _______, _______, _______, _______, _______,
        _______, BL_TOGG, XXXXXXX, KC_HOME,
        _______, XXXXXXX, KC_UP,   KC_END,  _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT,
        _______, KC_INS,           KC_DEL,  _______
    )
};
