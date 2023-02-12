/* Copyright 2015-2021 Jack Humbert
 * Copyright 2021 Choi Byungyoon
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
#include "byungyoonc.h"

enum layers {
  _QWERTY,
  _GAME_1,
  _GAME_2,
  _NUM,
  _SYMBOL,
  _ADJUST,
  _ADJUST2
};

#define NUM MO(_NUM)
#define SYMBOL MO(_SYMBOL)
#define ADJUST MO(_ADJUST2)
#define QWERTY DF(_QWERTY)
#define GAME_1 DF(_GAME_1)
#define GAME_2 DF(_GAME_2)
#define AGRGUI LGUI_T(KC_RALT)

const uint8_t ledflags[][48] = {
[_QWERTY] = {
    2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
    2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
    2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2,
    2, 2, 2, 2, 2, 0, 1, 2, 2, 3, 3, 3
},
[_GAME_1] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 1, 0, 0, 0, 0, 1, 2, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 4
},
[_GAME_2] = {
    2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2,
    2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
    2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3,
    2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 4
},
[_NUM] = {
    2, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 2,
    2, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 3,
    2, 1, 1, 0, 0, 0, 0, 1, 1, 1, 3, 3,
    2, 2, 2, 2, 8, 0, 1, 2, 1, 3, 3, 3
},
[_SYMBOL] = {
    1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 2,
    2, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 2,
    2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 2,
    2, 2, 2, 2, 2, 0, 1, 8, 2, 0, 0, 0
},
[_ADJUST] = {
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2,
    2, 5, 6, 7, 1, 1, 1, 1, 0, 0, 0, 0,
    2, 2, 2, 1, 8, 0, 1, 8, 1, 4, 4, 0
},
[_ADJUST2] = {
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    2, 4, 4, 1, 1, 1, 1, 1, 1, 0, 0, 2,
    2, 5, 6, 7, 1, 1, 1, 1, 0, 0, 0, 0,
    2, 2, 2, 1, 2, 0, 1, 2, 1, 4, 4, 8
}
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Return|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | Up/? | RSft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Home | End  | LAlt | NUM  |    Space    |SYMBOL| RAlt | Left | Down | Rght |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
    KC_ESC,  KC_HOME, KC_END,  KC_LALT, NUM,   KC_SPC,  KC_SPC,    SYMBOL,  AGRGUI,  KC_LEFT, KC_DOWN, KC_RGHT
),

/* GAMING WITH SPLIT SPACE FUNCTIONS DIFFERENTLY
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Return|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Space|      | LGUI | LAlt | NUM  |   G  |   H  |SYMBOL| RAlt | RGUI |      |ADJUST|
 * `-----------------------------------------------------------------------------------'
 */
[_GAME_1] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_SPC,  _______, _______, _______, _______, KC_G,    KC_H,    _______, _______, _______, _______, ADJUST
),

/* GAMING WITH WASD, NUMROW
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Return|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | ATAB |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtl |   Z  |   X  |   C  |   V  |    Space    |   M  |   ,  |   .  |   /  | ADJS |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME_2] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, A(KC_TAB),
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_SPC,  KC_SPC,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ADJUST
),

/* Num
 * ,-----------------------------------------------------------------------------------.
 * |      | Home |  Up  | End  | PgUp |Caplck|Numlck|   7  |   8  |   9  | N-,/ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right| PgDn |  XX  |  XX  |   4  |   5  |   6  | N+,* |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Esc  |  XX  |  XX  |  XX  |  XX  |   0  |   1  |   2  |   3  |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Spc |   0  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_ortho_4x12(
    KC_F1,   KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_CAPS, KC_NUM,  KC_7   , KC_8   , KC_9   , KC_PMNS, KC_DEL,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, KC_4   , KC_5   , KC_6   , KC_PPLS, _______,
    _______, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1   , KC_2   , KC_3   , KC_PDOT, _______,
    _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______, _______, _______
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   %  |   *  |  XX  |   (  |   )  |   -  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   &  |   *  |   $  |  XX  |  XX  |  XX  |   [  |   ]  |   \  |   '  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  XX  |   ^  |   ^  |  XX  |  XX  |  XX  |  XX  |  XX  |  XX  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_PERC, KC_ASTR, XXXXXXX, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_DEL,
    _______, KC_AMPR, KC_ASTR, KC_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, _______,
    _______, XXXXXXX, KC_CIRC, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | SEC1 | SEC2 |RGBTOG| Hue+ | Sat+ | Brt+ | Spd+ | Pat- |  XX  |  XX  | Pscr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |QWERTY|GMNG1 |GMNG2 | Vol- | Vol+ | Rwnd | Ffwd |  XX  |  XX  |  XX  |  XX  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Mute |      |    Reset    |      | Play |NK_TOG|Debug |  XX  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_SEC1, KC_SEC2, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, XXXXXXX, XXXXXXX, KC_PSCR,
    _______, QWERTY,  GAME_1,  GAME_2,  KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, KC_MUTE, _______, QK_BOOT, QK_BOOT, _______, KC_MPLY, NK_TOGG, DB_TOGG, XXXXXXX
),

[_ADJUST2] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_SEC1, KC_SEC2, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, XXXXXXX, XXXXXXX, KC_PSCR,
    _______, QWERTY,  GAME_1,  GAME_2,  KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, KC_MUTE, _______, QK_BOOT, QK_BOOT, _______, KC_MPLY, NK_TOGG, DB_TOGG, ADJUST
)

};

const key_override_t pmns_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PMNS, KC_PSLS);
const key_override_t ppls_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PAST);
const key_override_t up_key_override = ko_make_with_layers(MOD_BIT(KC_RSFT), KC_UP, KC_QUES, (1 << _QWERTY));
const key_override_t one_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, KC_F1, (1 << _GAME_2));
const key_override_t tab_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_TAB, KC_ESC, (1 << _GAME_1));

const key_override_t **key_overrides = (const key_override_t *[]){
    &pmns_key_override,
    &ppls_key_override,
    &up_key_override,
    &one_key_override,
    &tab_key_override,
    NULL
};

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    return;
}

/*
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t color_index;
    RGB rgb;
    RGB palette[] = {
        {0, 0, 0},
        {204, 204, 204},
        {51, 51, 204},
        {204, 51, 51},
        {204, 204, 51},
        {204, 204, 204},
        {204, 204, 204},
        {204, 204, 204},
        {51, 204, 51},
    };
    int layer = get_highest_layer(layer_state | default_layer_state);
    for (uint8_t i = 10; i <= 57; i++) {
        color_index = ledflags[layer][i-10];
        rgb = palette[color_index];
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    if (layer == _ADJUST || layer == _ADJUST2) {
        rgb = palette[2];
        uint8_t led_index = 35 + get_highest_layer(default_layer_state);
        rgb_matrix_set_color(led_index, rgb.r, rgb.g, rgb.b);
    }
}
*/

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM, _SYMBOL, _ADJUST);
    return state;
}
