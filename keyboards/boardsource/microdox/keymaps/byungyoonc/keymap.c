// Copyright 2022 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "byungyoonc.h"

enum layers {
  _QWERTY,
  _EXTEND,
  _SYMBOL,
  _NUMBER,
  _FUNCTION,
};

#define EXT MO(_EXTEND)
#define SYM MO(_SYMBOL)
#define NUM MO(_NUMBER)
#define MKEY MO(_MKEY)
#define OLCTL OSM(MOD_LCTL)
#define OLALT OSM(MOD_LALT)
#define OLSFT OSM(MOD_LSFT)
#define OLGUI OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                      NUM,     EXT,     KC_LSFT,      KC_SPC,  SYM,     KC_RALT
  ),

  [_EXTEND] = LAYOUT_split_3x5_3(
    KC_ESC,  KC_TAB,  KC_OSMC, KC_F1,   KC_CAPS,      KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   XXXXXXX,      KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_LGUI,      KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______,      _______, _______, _______
  ),

  [_SYMBOL] = LAYOUT_split_3x5_3(
    KC_EXLM, KC_AT,   KC_HASH, KC_PERC, KC_GRV,       KC_TILD, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   XXXXXXX,      KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT,
    KC_AMPR, KC_ASTR, KC_CIRC, KC_DLR,  KC_DLR,       KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQT,
                      _______, _______, _______,      _______, _______, _______
  ),

  [_NUMBER] = LAYOUT_split_3x5_3(
    KC_ESC,  KC_TAB,  KC_OSMC, KC_F1,   KC_NUM,       KC_DEL,  KC_7,    KC_8,    KC_9,    KC_PMNS,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   XXXXXXX,      KC_BSPC, KC_4,    KC_5,    KC_6,    KC_PPLS,
    C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_LGUI,      KC_ENT,  KC_1,    KC_2,    KC_3,    KC_PDOT,
                      _______, _______, _______,      KC_0,    _______, _______
  ),

  [_FUNCTION] = LAYOUT_split_3x5_3(
    RGB_TOG, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,      RGB_MOD, KC_F7,   KC_F8,   KC_F9,   KC_F10,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   KC_VOLD,      RGB_HUI, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_SEC1,KC_SEC2,C(S(KC_C)),C(S(KC_V)),KC_MUTE,    RGB_SAI, KC_F1,   KC_F2,   KC_F3,   KC_F12,
                      RGB_VAI, _______, NK_TOGG,      QK_BOOT, _______, RGB_SPI
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _EXTEND, _SYMBOL, _FUNCTION);
    return state;
}
