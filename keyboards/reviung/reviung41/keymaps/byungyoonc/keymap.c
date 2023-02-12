/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _ALTFN,
    _LOWER,
    _NUMPAD,
    _RAISE,
    _ADJUST,
    _ADJUST2
};

#define LOWER  MO(_LOWER)
#define NUMPAD MO(_NUMPAD)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST2)
#define ALTFN  TG(_ALTFN)
#define AGRGUI LGUI_T(KC_RALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                        KC_LALT, LOWER,   KC_SPC,  RAISE,   AGRGUI
  ),

  [_ALTFN] = LAYOUT_reviung41(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
                                        _______, KC_G,    _______, KC_H,    ADJUST
  ),

  [_LOWER] = LAYOUT_reviung41(
    KC_F1,   KC_HOME, KC_UP,   KC_END,  KC_WH_U, KC_CAPS,          KC_NUM,  KC_7,    KC_8,    KC_9,    KC_PMNS, KC_DEL,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_D, XXXXXXX,          XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
    _______, KC_ESC,  XXXXXXX, XXXXXXX, NUMPAD,  XXXXXXX,          XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PDOT, _______,
                                        _______, _______, KC_0,    _______, _______
  ),

  [_NUMPAD] = LAYOUT_reviung41(
    _______, _______, _______, _______, _______, _______,          _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
                                        _______, _______, KC_P0,   _______, _______
  ),

  [_RAISE] = LAYOUT_reviung41(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_PERC, XXXXXXX,          XXXXXXX, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_DEL,
    _______, KC_AMPR, KC_ASTR, KC_DLR,  XXXXXXX, XXXXXXX,          XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, _______,
    _______, XXXXXXX, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, _______,
                                        _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_reviung41(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_SEC1, KC_SEC2, RGB_TOG, RGB_MOD, RGB_VAI,          RGB_HUI, RGB_SAI, RGB_SPI, _______, NK_TOGG, KC_PSCR,
    _______, ALTFN,   _______, KC_MUTE, KC_VOLD, KC_VOLU,          KC_MRWD, KC_MFFD, KC_MPLY, _______, DB_TOGG, _______,
                                        _______, _______, QK_BOOT, _______, _______
  ),

  [_ADJUST2] = LAYOUT_reviung41(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_SEC1, KC_SEC2, RGB_TOG, RGB_MOD, RGB_VAI,          RGB_HUI, RGB_SAI, RGB_SPI, _______, NK_TOGG, KC_PSCR,
    _______, ALTFN,   _______, KC_MUTE, KC_VOLD, KC_VOLU,          KC_MRWD, KC_MFFD, KC_MPLY, _______, DB_TOGG, _______,
                                        _______, _______, QK_BOOT, _______, _______
  ),
};

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    for (int i = 0; i < 5; i++) {
        waitInputPinDelay();
    }
}

const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 0, 0, 0}
);
const rgblight_segment_t PROGMEM altfn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 190, 255, 255}
);
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 169, 255, 255}
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 21, 255, 255}
);
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 64, 255, 255}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    altfn_layer,
    lower_layer,
    raise_layer,
    adjust_layer,
    adjust_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _ALTFN));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST2));
    return state;
}

#ifdef COMBO_ENABLE
const uint16_t PROGMEM as[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sd[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM fg[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lsc[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM asd[] = {KC_A, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM adf[] = {KC_A, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM afg[] = {KC_A, KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM sdf[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sfg[] = {KC_S, KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM dfg[] = {KC_D, KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hjk[] = {KC_H, KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM hjl[] = {KC_H, KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM hjsc[] = {KC_H, KC_J, KC_SCLN, COMBO_END};
const uint16_t PROGMEM jkl[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jksc[] = {KC_J, KC_K, KC_SCLN, COMBO_END};
const uint16_t PROGMEM klsc[] = {KC_K, KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM op[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM yu[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM dotslash[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM qw[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
    COMBO(as, KC_LALT),
    COMBO(sd, KC_LCTL),
    COMBO(df, KC_LSFT),
    COMBO(fg, KC_LGUI),
    COMBO(hj, KC_LGUI),
    COMBO(jk, KC_LSFT),
    COMBO(kl, KC_LCTL),
    COMBO(lsc, KC_LALT),
    COMBO(asd, LALT(KC_LCTL)),
    COMBO(adf, LALT(KC_LSFT)),
    COMBO(afg, LALT(KC_LGUI)),
    COMBO(sdf, LCTL(KC_LSFT)),
    COMBO(sfg, LCTL(KC_LGUI)),
    COMBO(dfg, LSFT(KC_LGUI)),
    COMBO(klsc, LALT(KC_LCTL)),
    COMBO(jksc, LALT(KC_LSFT)),
    COMBO(hjsc, LALT(KC_LGUI)),
    COMBO(jkl, LCTL(KC_LSFT)),
    COMBO(hjl, LCTL(KC_LGUI)),
    COMBO(hjk, LSFT(KC_LGUI)),
    COMBO(op, KC_BSPC),
    COMBO(io, KC_DEL),
    COMBO(zx, KC_ESC),
    COMBO(yu, KC_CAPS),
    COMBO(dotslash, KC_ENT),
    COMBO(qw, KC_TAB),
};
#endif
