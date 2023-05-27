// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "byungyoonc.h"

enum layers {
  _QWERTY,
  _NUM,
  _SYMBOL,
  _ADJUST,
};

#define NUM MO(_NUM)
#define SYMBOL MO(_SYMBOL)
#define QWERTY DF(_QWERTY)
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
    [_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
    KC_ESC,  KC_HOME, KC_END,  KC_LALT, NUM,        KC_SPC,        SYMBOL,  AGRGUI,  KC_LEFT, KC_DOWN, KC_RGHT
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
[_NUM] = LAYOUT_planck_mit(
    KC_F1,   KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_CAPS, KC_NUM,  KC_7   , KC_8   , KC_9   , KC_PMNS, KC_DEL,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, KC_4   , KC_5   , KC_6   , KC_PPLS, _______,
    _______, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1   , KC_2   , KC_3   , KC_PDOT, _______,
    _______, _______, _______, _______, _______,       KC_0,       _______, _______, _______, _______, _______
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
[_SYMBOL] = LAYOUT_planck_mit(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_PERC, KC_ASTR, XXXXXXX, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_DEL,
    _______, KC_AMPR, KC_ASTR, KC_DLR,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, _______,
    _______, XXXXXXX, KC_CIRC, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_SLSH, _______,
    _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
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
[_ADJUST] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_SEC1, KC_SEC2, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, XXXXXXX, XXXXXXX, KC_PSCR,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, KC_MUTE, _______,      QK_BOOT,     _______, KC_MPLY, NK_TOGG, DB_TOGG, XXXXXXX
),
};


const key_override_t pmns_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PMNS, KC_PSLS);
const key_override_t ppls_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PAST);
const key_override_t up_key_override = ko_make_with_layers(MOD_BIT(KC_RSFT), KC_UP, KC_QUES, (1 << _QWERTY));

const key_override_t **key_overrides = (const key_override_t *[]){
    &pmns_key_override,
    &ppls_key_override,
    &up_key_override,
    NULL
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM, _SYMBOL, _ADJUST);
    return state;
}
