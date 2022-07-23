#include QMK_KEYBOARD_H
#include "byungyoonc.h"

enum custom_layers {
    _BASE,
    _ALTSPACE,
    _NUMNAV,
    _SYM,
    _ADJUST
};

#define NUMNAV MO(_NUMNAV)
#define SYM MO(_SYM)
#define ALTSP TG(_ALTSPACE)
#define SH_SPC SH_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_4x6_3(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LALT, NUMNAV,  SH_SPC,  KC_SPC,  SYM,     KC_LGUI
    ),
    [_ALTSPACE] = LAYOUT_split_4x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                                            _______, _______, KC_SPC,  KC_P0,   _______, _______
    ),
    [_NUMNAV] = LAYOUT_split_4x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, KC_HOME, KC_UP,   KC_END,  KC_WH_U, XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, KC_DEL,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_D, XXXXXXX,                   XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
        _______, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PDOT, _______,
                                            _______, _______, _______, KC_0,    _______, _______
    ),
    [_SYM] = LAYOUT_split_4x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_PERC, XXXXXXX,                   XXXXXXX, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_DEL,
        _______, KC_AMPR, KC_ASTR, KC_DLR,  XXXXXXX, XXXXXXX,                   XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUOT, _______,
        _______, XXXXXXX, KC_CIRC, KC_CIRC, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, _______,
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
    state = update_tri_layer_state(state, _NUMNAV, _SYM, _ADJUST);
    return state;
}

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} },
  {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} },
  {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} },
  {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} },
  {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} },
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} },
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} },
  {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} },
  {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} },
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} },
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _NUMNAV:
            oled_write_P(PSTR("NUMNAV\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMBOL\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif