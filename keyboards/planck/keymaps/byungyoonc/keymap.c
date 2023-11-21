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

//#define SENIPLY
#define ACAI

#if defined(SENIPLY)
enum planck_layers {
  _QWERTY,
  _EXTEND,
  _SYMBOL,
  _NUMBER,
  _MKEY,
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
/* Qwerty
 * ,------------------------------------------------------------------------------------.
 * |    Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |
 * |-------+------+------+------+------+             +------+------+------+------+------|
 * |    A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |
 * |-------+------+------+------+------+             +------+------+------+------+------|
 * |    Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |   NUM |      | LAlt | EXT  |    Shift    |    Space    |SYMBOL| RAlt |      | MKEY |
 * `------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    NUM,     XXXXXXX, KC_LALT, EXT,     KC_LSFT, KC_LSFT, KC_SPC,  KC_SPC,  SYM,     KC_RALT, XXXXXXX, MKEY
),
/* Extend
 * ,------------------------------------------------------------------------------------.
 * |  Esc  | Tab  | OSMC |  F1  | Caps |             | Del  | Home |  Up  | End  | PgUp |
 * |-------+------+------+------+------+             +------+------+------+------+------|
 * |  OGUI | OALT | OCTL | OSFT |      |             | Bspc | Left | Down | Right| PgDn |
 * |-------+------+------+------+------+             +------+------+------+------+------|
 * |  Undo | Cut  | Copy | Paste| GUI  |             | Enter|      |      |      |      |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |              |      |   v  |             |             |      |      |             |
 * `------------------------------------------------------------------------------------'
 */
[_EXTEND] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_TAB,  KC_OSMC, KC_F1,   KC_CAPS, XXXXXXX, XXXXXXX, KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_LGUI, XXXXXXX, XXXXXXX, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Symbol
 * ,------------------------------------------------------------------------------------.
 * |    !  |   @  |   #  |   %  |   `  |             |   ~  |   (  |   )  |   -  |   =  |
 * |-------+------+------+------+------+             +------+------+------+------+------|
 * |  OGUI | OALT | OCTL | OSFT | RALT |             |   +  |   [  |   ]  |   \  |   '  |
 * |-------+------+------+------+------+             +------+------+------+------+------|
 * |    &  |   *  |   ^  |   $  |   $  |             |   _  |   {  |   }  |   |  |   "  |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |              |      |      |             |             |   v  |      |             |
 * `------------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_ortho_4x12(
    KC_EXLM, KC_AT,   KC_HASH, KC_PERC, KC_GRV,  XXXXXXX, XXXXXXX, KC_TILD, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT,
    KC_AMPR, KC_ASTR, KC_CIRC, KC_DLR,  KC_DLR,  XXXXXXX, XXXXXXX, KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Number
 * ,------------------------------------------------------------------------------------.
 * |  Esc  | Tab  | OSMC |  F1  | Nlck |             | Del  |   7  |   8  |   9  |   -  |
 * |-------+------+------+------+------+             +------+------+------+------+------|
 * |  OGUI | OALT | OCTL | OSFT |      |             | Bspc |   4  |   5  |   6  |   +  |
 * |-------+------+------+------+------+             +------+------+------+------+------|
 * |  Undo | Cut  | Copy | Paste| GUI  |             | Enter|   1  |   2  |   3  |   .  |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |              |   v  |      |             |      0      |      |      |             |
 * `------------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_TAB,  KC_OSMC, KC_F1,   KC_NUM,  XXXXXXX, XXXXXXX, KC_DEL,  KC_7,    KC_8,    KC_9,    KC_PMNS,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_4,    KC_5,    KC_6,    KC_PPLS,
    C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_LGUI, XXXXXXX, XXXXXXX, KC_ENT,  KC_1,    KC_2,    KC_3,    KC_PDOT,
    _______, _______, _______, _______, _______, _______, KC_0,    KC_0,    _______, _______, _______, _______
),
/* Mousekey
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  MUp |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |  MC2 |  MC3 |  MC1 |      |      | MLft | MDwn | MRgt |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |             |             |      |      |   v  |
 * `---------------------------------------------------------------------'
 */
[_MKEY] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______,
    _______, KC_BTN2, KC_BTN3, KC_BTN1, _______, XXXXXXX, XXXXXXX, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______,
    _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Function
 * ,-------------------------------------------------------------------------------------.
 * | RGBTOG| Rwnd | Play | Ffwd | VUp  |              |      |  F7  |  F8  |  F9  | F10  |
 * |-------+------+------+------+------+              +------+------+------+------+------|
 * |  OGUI | OALT | OCTL | OSFT | VDn  |              |      |  F4  |  F5  |  F6  | F11  |
 * |-------+------+------+------+------+              +------+------+------+------+------|
 * |  SEC1 | SEC2 | CSC  | CSV  | Mute |              |      |  F1  |  F2  |  F3  | F12  |
 * |-------+------+------+------+------+--------------+------+------+------+------+------|
 * |              |      |   v  |    NKTOGG    |    Reset    |   v  |      |             |
 * `-------------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
    RGB_TOG, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_SEC1,KC_SEC2,C(S(KC_C)),C(S(KC_V)),KC_MUTE,XXXXXXX,XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
    _______, _______, _______, _______, NK_TOGG, NK_TOGG, QK_BOOT, QK_BOOT, _______, _______, _______, _______
)
};
#elif defined(ACAI)
enum planck_layers {
  _QWERTY,
  _EXTEND,
  _SYMBOL,
  _NUMBER,
  _LFN,
  _MKEY,
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
/* Qwerty
 * ,----------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+-------------+------+------+------|
 * | NUM  | LAlt | EXT  |    Shift    |    Space    |SYMBOL| RAlt | MKEY |
 * `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
    XXXXXXX, NUM,     KC_LALT, EXT,     KC_LSFT, KC_LSFT, KC_SPC,  KC_SPC,  SYM,     KC_RALT, MKEY,    XXXXXXX
),
/* Extend
 * ,----------------------------------------------------------------------.
 * |  Esc  | Tab  | OSMC |  F1  | Caps | Del  | Home |  Up  | End  | PgUp |
 * |-------+------+------+------+------+------+------+------+------+------|
 * |  OGUI | OALT | OCTL | OSFT |      | Bspc | Left | Down | Right| PgDn |
 * |-------+------+------+------+------+------+------+------+------+------|
 * |  Undo | Cut  | Copy | Paste| GUI  | Enter|      |      |      |      |
 * |-------+------+------+------+------+-------------+------+------+------|
 * |       |      |   v  |             |             |      |      |      |
 * `----------------------------------------------------------------------'
 */
[_EXTEND] = LAYOUT_ortho_4x12(
    XXXXXXX, KC_ESC,  KC_TAB,  KC_OSMC, KC_F1,   KC_CAPS, KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
    XXXXXXX, OLGUI,   OLALT,   OLCTL,   OLSFT,   XXXXXXX, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
    XXXXXXX, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_LGUI, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
),
/* Symbol
 * ,----------------------------------------------------------------------.
 * |    !  |   @  |   #  |   %  |   `  |   ~  |   (  |   )  |   -  |   =  |
 * |-------+------+------+------+------+------+------+------+------+------|
 * |  OGUI | OALT | OCTL | OSFT | RALT |   +  |   [  |   ]  |   \  |   '  |
 * |-------+------+------+------+------+------+------+------+------+------|
 * |    &  |   *  |   ^  |   $  |   $  |   _  |   {  |   }  |   |  |   "  |
 * |-------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |             |             |   v  |      |      |
 * `----------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_ortho_4x12(
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_PERC, KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  XXXXXXX,
    XXXXXXX, OLGUI,   OLALT,   OLCTL,   OLSFT,   XXXXXXX, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, XXXXXXX,
    XXXXXXX, KC_AMPR, KC_ASTR, KC_CIRC, KC_DLR,  KC_DLR,  KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQT,  XXXXXXX,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
),
/* Number
 * ,---------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   =  | Nlck |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   4  |   5  |   6  |   -  |      |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+------+------+------+------+------|
 * | Shft |   7  |   8  |   9  |   0  |      |   1  |   2  |   3  |   .  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |   v  |      |      |             |      0      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_ortho_4x12(
    XXXXXXX, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_EQL,  KC_NUM,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS, XXXXXXX,
    XXXXXXX, KC_LCTL, KC_4,    KC_5,    KC_6,    KC_MINS, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
    XXXXXXX, KC_LSFT, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX,
    XXXXXXX, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   _______, _______, _______, XXXXXXX
),
/* Left Function
 * ,---------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  | F12  | Nlck |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F4  |  F5  |  F6  | F11  |      |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+------+------+------+------+------|
 * | Shft |  F7  |  F8  |  F9  | F10  |      |   1  |   2  |   3  |   .  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |   v  |      |   v  |             |      0      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_LFN] = LAYOUT_ortho_4x12(
    XXXXXXX, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_NUM,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS, XXXXXXX,
    XXXXXXX, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
    XXXXXXX, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX,
    XXXXXXX, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   _______, _______, _______, XXXXXXX
),
/* Mousekey
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  MUp |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |  MC2 |  MC3 |  MC1 |      |      | MLft | MDwn | MRgt |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |             |             |      |      |   v  |
 * `---------------------------------------------------------------------'
 */
[_MKEY] = LAYOUT_ortho_4x12(
    XXXXXXX, _______, _______, _______, _______, _______, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______, XXXXXXX,
    XXXXXXX, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, XXXXXXX,
    XXXXXXX, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, XXXXXXX,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
),
/* Function
 * ,----------------------------------------------------------------------.
 * | RGBTOG| Rwnd | Play | Ffwd | VUp  |      |  F7  |  F8  |  F9  | F10  |
 * |-------+------+------+------+------+------+------+------+------+------|
 * |  OGUI | OALT | OCTL | OSFT | VDn  |      |  F4  |  F5  |  F6  | F11  |
 * |-------+------+------+------+------+------+------+------+------+------|
 * |  SEC1 | SEC2 | CSC  | CSV  | Mute |      |  F1  |  F2  |  F3  | F12  |
 * |-------+------+------+------+------+-------------+------+------+------|
 * |       |      |   v  |    NKTOGG   |    Reset    |   v  |      |      |
 * `----------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
    XXXXXXX, RGB_TOG, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
    XXXXXXX, OLGUI,   OLALT,   OLCTL,   OLSFT,   KC_VOLD, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,
    XXXXXXX,KC_SEC1,KC_SEC2,C(S(KC_C)),C(S(KC_V)),KC_MUTE,XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  XXXXXXX,
    XXXXXXX, _______, _______, _______, NK_TOGG, NK_TOGG, QK_BOOT, QK_BOOT, _______, _______, _______, XXXXXXX
)
};
#elif defined(SENIPLY_EXT)
enum planck_layers {
  _QWERTY,
  _EXTEND,
  _SYMBOL,
  _NUMBER,
  _NFN,
  _FUNCTION,
};

#define EXT MO(_EXTEND)
#define SYM MO(_SYMBOL)
#define NUM MO(_NUMBER)
#define OLCTL OSM(MOD_LCTL)
#define OLALT OSM(MOD_LALT)
#define OLSFT OSM(MOD_LSFT)
#define OLGUI OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter| Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  Up  |  End |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  NUM | Menu | LAlt |  EXT | Shift| Space|SYMBOL| RAlt | LGUI | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  KC_HOME,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_END,
    NUM,     KC_MENU, KC_LALT, EXT,     KC_LSFT, KC_SPC,  SYM,     KC_RALT, KC_LGUI, KC_LEFT, KC_DOWN, KC_RGHT
),
/* Extend
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | Tab  | OSMC |  F1  | Caps | Del  | Home |  Up  | End  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | OGUI | OALT | OCTL | OSFT | RAlt | Bspc | Left | Down | Right|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Undo | Cut  | Copy | Paste| GUI  | Enter|      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   *  |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXTEND] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_TAB,  KC_OSMC, KC_F1,   KC_CAPS, KC_DEL,  KC_HOME, KC_UP,   KC_END,  XXXXXXX, _______, _______,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   KC_RALT, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______, _______,
    C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_LGUI, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Number
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   =  | Nlck |   7  |   8  |   9  |   -  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   4  |   5  |   6  |   -  |      |   4  |   5  |   6  |   +  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shft |   7  |   8  |   9  |   0  |      |   1  |   2  |   3  |   .  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   *  |      |      |      |      |   0  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_EQL,  KC_NUM,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, _______,
    KC_LCTL, KC_4,    KC_5,    KC_6,    KC_MINS, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______,
    KC_LSFT, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______, _______,
    _______, _______, _______, _______, _______, KC_P0,   _______, _______, _______, _______, _______, _______
),
/* Left Function
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F4  |  F5  |  F6  |  F11 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   *  |      |      |   *  |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NFN] = LAYOUT_ortho_4x12(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   %  |   `  |   ~  |   (  |   )  |   -  |   =  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | OGUI | OALT | OCTL | OSFT | RALT |   +  |   [  |   ]  |   \  |   '  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   &  |   *  |   ^  |      |   $  |   _  |   {  |   }  |   |  |   "  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   *  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_ortho_4x12(
    KC_EXLM, KC_AT,   KC_HASH, KC_PERC, KC_GRV,  KC_TILD, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  _______, _______,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   KC_RALT, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, _______, _______,
    KC_AMPR, KC_ASTR, KC_CIRC, XXXXXXX, KC_DLR,  KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQT,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Function
 * ,-----------------------------------------------------------------------------------.
 * |RGBTOG| Rwnd | Play | Ffwd | VUp  |      |  F7  |  F8  |  F9  | F10  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | OGUI | OALT | OCTL | OSFT | VDn  |      |  F4  |  F5  |  F6  | F11  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SEC1 | SEC2 | CSC  | CSV  | Mute |      |  F1  |  F2  |  F3  | F12  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   *  |NKTOGG| Reset|   *  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
    RGB_TOG, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______,
    OLGUI,   OLALT,   OLCTL,   OLSFT,   KC_VOLD, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, _______,
    KC_SEC1,KC_SEC2,C(S(KC_C)),C(S(KC_V)),KC_MUTE,XXXXXXX,KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, _______,
    _______, _______, _______, _______, NK_TOGG, QK_BOOT, _______, _______, _______, _______, _______, _______
)
};
#else
enum planck_layers {
  _QWERTY,
  _GAME_1,
  _NUM,
  _LNUM,
  _LFUN,
  _NUMPAD,
  _SYMBOL,
  _ADJUST,
  _ADJUST2
};

#define NUM MO(_NUM)
#define LNUM MO(_LNUM)
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
 * | WNUM | Home | End  | LAlt | NUM  |    Space    |SYMBOL| RAlt | Left | Down | Rght |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
    LNUM,    KC_HOME, KC_END,  KC_LALT, NUM,   KC_SPC,  KC_SPC,    SYMBOL,  AGRGUI,  KC_LEFT, KC_DOWN, KC_RGHT
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

/* Left Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |  1   |  2   |  3   |  =   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  4   |  5   |  6   |  -   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  7   |  8   |  9   |  0   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LNUM] = LAYOUT_planck_grid(
    _______, KC_1   , KC_2   , KC_3   , KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
    _______, KC_4   , KC_5   , KC_6   , KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_7   , KC_8   , KC_9   , KC_0,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Left Function
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  | F12  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F4  |  F5  |  F6  | F11  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LFUN] = LAYOUT_planck_grid(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
    _______, KC_F4  , KC_F5  , KC_F6  , KC_F11,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_F7  , KC_F8  , KC_F9  , KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
    _______, XXXXXXX, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_SLSH, _______,
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
    _______, _______, _______, _______, _______, QK_BOOT, QK_BOOT, _______, _______, _______, _______, _______
),

[_ADJUST2] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_SEC1, KC_SEC2, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, XXXXXXX, NK_TOGG, KC_PSCR,
    _______, QWERTY,  GAME_1,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, KC_MPLY, XXXXXXX, DB_TOGG, _______,
    _______, _______, _______, _______, _______, QK_BOOT, QK_BOOT, _______, ADJUST, _______, _______, _______
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
#endif

#if defined(RGBLIGHT_ENABLE) && !defined(SENIPLY) && !defined(SENIPLY_EXT) && !defined(ACAI)
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
#if defined(SENIPLY)
    state = update_tri_layer_state(state, _EXTEND, _SYMBOL, _FUNCTION);
#elif defined(SENIPLY_EXT)
    state = update_tri_layer_state(state, _EXTEND, _SYMBOL, _FUNCTION);
    state = update_tri_layer_state(state, _EXTEND, _NUMBER, _NFN);
#elif defined(ACAI)
    state = update_tri_layer_state(state, _EXTEND, _SYMBOL, _FUNCTION);
    state = update_tri_layer_state(state, _EXTEND, _NUMBER, _LFN);
#else
    state = update_tri_layer_state(state, _NUM, _SYMBOL, _ADJUST);
    state = update_tri_layer_state(state, _NUM, _LNUM, _LFUN);
#endif
#if defined(RGBLIGHT_ENABLE) && !defined(SENIPLY) && !defined(SENIPLY_EXT) && !defined(ACAI)
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST2));
#endif
    return state;
}
