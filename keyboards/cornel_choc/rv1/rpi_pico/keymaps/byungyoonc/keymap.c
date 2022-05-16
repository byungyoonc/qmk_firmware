#include QMK_KEYBOARD_H
#include "byungyoonc.h"
#include "print.h"

enum custom_layers {
    _BASE,
    _ALTSPACE,
    _NUM,
    _SYM,
    _NAV,
    _MOUSEKEY,
    _ADJUST
};

#define NUM MO(_NUM)
#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define ALTSP TG(_ALTSPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_4x6_3(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            NAV,     NUM,     KC_SPC,  KC_SPC,  SYM,     KC_LALT
    ),
    [_ALTSPACE] = LAYOUT_split_4x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, KC_P0,   _______, _______
    ),
    [_NUM] = LAYOUT_split_4x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, KC_ESC,  _______, _______, _______, _______,                   _______, KC_1,    KC_2,    KC_3,    KC_PDOT, _______,
                                            _______, _______, _______, KC_0,    _______, _______
    ),
    [_SYM] = LAYOUT_split_4x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_PERC, _______,                   _______, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  _______,
        _______, KC_AMPR, KC_ASTR, KC_DLR,  _______, _______,                   _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, _______,
        _______, _______, KC_CIRC, KC_CIRC, _______, _______,                   _______, _______, KC_RALT, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT_split_4x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_LGUI, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_HOME, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_WH_U, _______, KC_UP,   KC_END,  _______, _______,
        _______, KC_ESC,  _______, _______, _______, _______,                   KC_WH_D, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    ),
    [_MOUSEKEY] = LAYOUT_split_4x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______,                   KC_WH_U, _______, KC_MS_U, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_split_4x6_3(
        QK_BOOT, DEBUG,   _______, NK_TOGG, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_SEC1, KC_SEC2, RGB_TOG, RGB_MOD, RGB_VAI,                   RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______,
        _______, ALTSP,   _______, KC_MUTE, KC_VOLD, KC_VOLU,                   KC_MRWD, KC_MFFD, KC_MPLY, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______
    )
};

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    waitInputPinDelay();
    waitInputPinDelay();
    waitInputPinDelay();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUM, _SYM, _ADJUST);
    state = update_tri_layer_state(state, _NAV, _SYM, _MOUSEKEY);
    return state;
}
