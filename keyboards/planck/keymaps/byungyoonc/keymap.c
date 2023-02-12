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

enum planck_layers {
  _QWERTY,
  _GAME_1,
  _NUM,
  _NUMPAD,
  _SYMBOL,
  _ADJUST,
  _ADJUST2
};

#define NUM MO(_NUM)
#define NPAD MO(_NUMPAD)
#define SYMBOL MO(_SYMBOL)
#define ADJUST MO(_ADJUST2)
#define QWERTY DF(_QWERTY)
#define GAME_1 DF(_GAME_1)
#define AGRGUI LGUI_T(KC_RALT)

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
[_QWERTY] = LAYOUT_planck_grid(
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
 * |      |      |      | LAlt |   F  |    Space    |   J  |ADJUST|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME_1] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_F,    _______, _______, KC_J,    ADJUST,  _______, _______, _______
),

/* Num/Nav
 * ,-----------------------------------------------------------------------------------.
 * |  F1  | Home |  Up  | End  | PgUp |Caplck|Numlck|   7  |   8  |   9  | P-,/ | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Rght | PgDn |      |      |   4  |   5  |   6  | P+,* |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Esc  |      |      | NPAD |      |      |   1  |   2  |   3  |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      0      |      |   .  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    KC_F1,   KC_HOME, KC_UP  , KC_END,  KC_PGUP, KC_CAPS, KC_NUM,  KC_7   , KC_8   , KC_9   , KC_PMNS, KC_DEL,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, KC_4   , KC_5   , KC_6   , KC_PPLS, _______,
    _______, KC_ESC,  XXXXXXX, XXXXXXX, NPAD,    XXXXXXX, XXXXXXX, KC_1   , KC_2   , KC_3   , KC_PDOT, _______,
    _______, _______, _______, _______, _______, KC_0   , KC_0   , _______, _______, _______, _______, _______
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  P7  |  P8  |  P9  | P-,/ | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  P4  |  P5  |  P6  | P+,* | PEnt |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  P1  |  P2  |  P3  |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |     P_0     |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P4  , KC_P5  , KC_P6  , _______, KC_PENT,
    _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P2  , KC_P3  , _______, _______,
    _______, _______, _______, _______, _______, KC_P0  , KC_P0  , _______, _______, _______, _______, _______
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   %  |      |      |   (  |   )  |   -  |   =  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   &  |   *  |   $  |      |      |      |   [  |   ]  |   \  |   '  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   ^  |      |      |      |      |      |      |      |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_PERC, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_DEL,
    _______, KC_AMPR, KC_ASTR, KC_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, _______,
    _______, XXXXXXX, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | SEC1 | SEC2 |RGBTOG| Hue+ | Sat+ | Brt+ | Spd+ | Pat- |  XX  |NK_TOG| Pscr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |QWERTY|GMNG1 |      | Vol- | Vol+ | Rwnd | Ffwd |  XX  |  XX  |Debug |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Mute |      |    Reset    |      | Play |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_SEC1, KC_SEC2, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, XXXXXXX, NK_TOGG, KC_PSCR,
    _______, QWERTY,  GAME_1,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, KC_MPLY, XXXXXXX, DB_TOGG, _______,
    _______, _______, _______, _______, _______, RESET,   RESET,   _______, _______, _______, _______, _______
),

[_ADJUST2] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_SEC1, KC_SEC2, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, XXXXXXX, NK_TOGG, KC_PSCR,
    _______, QWERTY,  GAME_1,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, KC_MPLY, XXXXXXX, DB_TOGG, _______,
    _______, _______, _______, _______, _______, RESET,   RESET,   _______, ADJUST, _______, _______, _______
)

};

const key_override_t pmns_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PMNS, KC_PSLS);
const key_override_t ppls_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PAST);
const key_override_t up_key_override = ko_make_with_layers(MOD_BIT(KC_RSFT), KC_UP, KC_QUES, (1 << _QWERTY));
const key_override_t tab_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_TAB, KC_ESC, (1 << _GAME_1));

const key_override_t **key_overrides = (const key_override_t *[]){
    &pmns_key_override,
    &ppls_key_override,
    &up_key_override,
    &tab_key_override,
    NULL
};

#if defined(RGBLIGHT_ENABLE)
// RGB LIGHT LAYER ADJUSTMENTS
const rgblight_segment_t PROGMEM my_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {4, 2, 0, 255, 255}
);

const rgblight_segment_t PROGMEM my_g1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {2, 2, 128, 196, 255},
        {6, 2, 128, 196, 255}
);

const rgblight_segment_t PROGMEM my_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {8, 1, 171, 196, 255}
);

const rgblight_segment_t PROGMEM my_symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {1, 1, 26, 223, 255}
);

const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {8, 1, 85, 196, 255},
        {1, 1, 85, 196, 255}
);

const rgblight_segment_t PROGMEM my_adjust2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {2, 1, 85, 196, 255}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_caps_layer,
    my_g1_layer,
    my_num_layer,
    my_symbol_layer,
    my_adjust_layer,
    my_adjust2_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAME_1));
    return state;
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM, _SYMBOL, _ADJUST);
#if defined(RGBLIGHT_ENABLE)
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST2));
#endif
    return state;
}
