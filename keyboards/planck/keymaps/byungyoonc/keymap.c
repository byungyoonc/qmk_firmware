/* Copyright 2015-2021 Jack Humbert
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


enum planck_layers {
  _QWERTY,
  _GAME_SPC,
  _GAME_WASD,
  _NUMNAV,
  _SHIFTED,
  _FUNCTION,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  GAME_SPC,
  GAME_WASD,
  SEC_1,
  SEC_2,
  BACKLIT,
  EXT_PLV
};

#define NUMNAV MO(_NUMNAV)
#define SHIFTED MO(_SHIFTED)
#define NUMNAV_SPC LT(_NUMNAV, KC_SPC)
#define SHIFTED_SPC LT(_SHIFTED, KC_SPC)
#define ADJUST_SPC LT(_ADJUST, KC_SPC)
#define FUNCTION MO(_FUNCTION)
#define ADJUST MO(_ADJUST)
#define QWERTY DF(_QWERTY)
#define GAME_SPC DF(_GAME_SPC)
#define GAME_WASD DF(_GAME_WASD)
#define LSFTCAP LT(_QWERTY, KC_LSFT)
#define RSFTCAP LT(_QWERTY, KC_RSFT)
#define NMNVLK TG(_NUMNAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtl | LGUI | LAlt |      | NMNV/Space  | SFTD/Space  | RAlt |      |  Fn  | ADJS |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_2x2u(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, NMNVLK,     NUMNAV_SPC,    SHIFTED_SPC,      KC_RALT, XXXXXXX, FUNCTION,ADJUST
),

/* GAMING WITH SPLIT SPACE FUNCTIONS DIFFERENTLY
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtl |      | LAlt |      |    Num_1    |    Num_3    | RAlt |      |  Fn  | ADJS |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME_SPC] = LAYOUT_planck_2x2u(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, XXXXXXX, KC_LALT, XXXXXXX,          KC_P1,   KC_P3,            KC_RALT, XXXXXXX, FUNCTION,ADJUST
),

/* GAMING WITH WASD, NUMROW
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |  Up  |   I  |   O  |   P  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |   A  |   S  |   D  |   F  |   G  | Left | Down |Right |   L  |   ;  | ATAB |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtl |   Z  |   X  |   C  |    Space    |      V      |   M  |   .  |   /  | ADJS |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME_WASD] = LAYOUT_planck_2x2u(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_UP,   KC_I,    KC_O,    KC_P,    KC_ENT,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LEFT, KC_DOWN, KC_RGHT, KC_L,    KC_SCLN, A(KC_TAB),
    KC_LCTL, KC_Z,    KC_X,    KC_C,           KC_SPC,    KC_V,             KC_M,    KC_DOT,  KC_SLSH, ADJUST
),

/* Num/Nav
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |Caplck|Numlck|   7  |   8  |   9  | N-,/ | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   5  |   6  |   7  |   8  |      |      |   4  |   5  |   6  | N+,* | Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |   9  |   0  |      |      |      |      |   1  |   2  |   3  |  Up  | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtl | LGUI | LAlt |      |   NUMNAV    |      0      | Num. | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMNAV] = LAYOUT_planck_2x2u(
    KC_TAB , KC_1   , KC_2   , KC_3   , KC_4   , KC_CAPS, KC_NLCK, KC_7   , KC_8   , KC_9   , KC_PMNS, KC_BSPC,
    KC_ESC , KC_5   , KC_6   , KC_7   , KC_8   , KC_NO  , KC_NO  , KC_4   , KC_5   , KC_6   , KC_PPLS, KC_HOME,
    KC_LSFT, KC_9   , KC_0   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_1   , KC_2   , KC_3   , KC_UP  , KC_END ,
    KC_LCTL, KC_LGUI, KC_LALT, NMNVLK ,           NUMNAV , KC_0            , KC_PDOT, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Shifted
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   %  |   *  |      |   (  |   )  |   -  |   =  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   &  |   *  |   $  |      |      |      |   [  |   ]  |   \  |   '  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |      |   ^  |   ^  |      |      |      |      |      |      |      | RSft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtl | LGUI | LAlt |      |    Space    |   SHIFTED   | RAlt |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SHIFTED] = LAYOUT_planck_2x2u(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_PERC, KC_ASTR, KC_NO,   KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_BSPC,
    KC_ESC,  KC_AMPR, KC_ASTR, KC_DLR,  KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, KC_ENT,
    KC_LSFT, KC_NO,   KC_CIRC, KC_CIRC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO,            KC_SPC,  SHIFTED,          KC_RALT, KC_NO,   KC_NO,   KC_NO
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |      |      |      | Brt- | Brt+ |      |      |      |      |      | Pscr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |      |      |      | Vol- | Vol+ | Rwnd | Ffwd |      |      |      | Task |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtl | LGUI | LAlt |      |    Mute     |    Play     |      |      |  Fn  | CAD  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_planck_2x2u(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_ESC,  XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, KC_PSCR,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, XXXXXXX, XXXXXXX, XXXXXXX, C(S(KC_ESC)),
    KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,          KC_MUTE, KC_MPLY,          XXXXXXX, XXXXXXX, FUNCTION,LCA(KC_DEL)
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |NK_TOG|      |      |      |      |      |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SEC1 | SEC2 |      |      |      |      |      |      |      |      |      |Debug |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|GMNG1 |GMNG2 |      |             |             |      |      |      | ADJS |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_2x2u(
    NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
    SEC_1,   SEC_2,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEBUG,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QWERTY,  GAME_SPC,GAME_WASD,XXXXXXX,         XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, ADJUST
)

};

const key_override_t pmns_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PMNS, KC_PSLS);
const key_override_t ppls_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_PAST);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t one_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, KC_F1, (1 << _GAME_WASD));
const key_override_t tab_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_TAB, KC_ESC, (1 << _GAME_SPC));

const key_override_t **key_overrides = (const key_override_t *[]){
    &pmns_key_override,
    &ppls_key_override,
    &delete_key_override,
    &one_key_override,
    &tab_key_override,
    NULL
};

bool led_update_user(led_t led_state) {
    static uint8_t caps_state = 0;
    static uint8_t numl_state = 0;
    if (caps_state != led_state.caps_lock) {
        if (led_state.caps_lock) {
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(0, 212, 255);
        }
        else {
            rgblight_reload_from_eeprom();
        }
        caps_state = led_state.caps_lock;
    }
    if (numl_state != led_state.num_lock) {
        if (!led_state.num_lock) {
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(128, 212, 255);
        }
        else {
            rgblight_reload_from_eeprom();
        }
        numl_state = led_state.num_lock;
    }
    return true;
}

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#    include "secrets.h"
#else
static const char *const secrets[] = {"test1", "test2"};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SEC_1 ... SEC_2:
            if (!record->event.pressed) {
                send_string_with_delay(secrets[keycode - SEC_1], 20);
            }
            return false;
            break;
    }
    return true;
}
