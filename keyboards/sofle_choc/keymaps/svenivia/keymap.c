/* Copyright 2023 Brian Low
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

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { KC_PRVWD = QK_USER, KC_NXTWD, KC_LSTRT, KC_LEND, KC_DLINE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL | LOPT | LCMD |LOWER | /Enter  /       \Space \  |RAISE | RCMD | ROPT | RCTL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_QWERTY] = LAYOUT(
        KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,   KC_MPLY,  KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC,
                        KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_ENT,    KC_SPC,   TL_UPPR,  KC_NUBS,  KC_NUHS, KC_RGUI
    ),
    /* LOWER
    * ,----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  | LAt  | LCtl |LShift| Btn2 | Caps |-------.    ,-------|      | Left | Down | Right|  Del | Bspc |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |Shift | Undo |  Cut | Copy | Paste| Exit |-------|    |-------|      | LStr |      | LEnd |      | Shift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, _______,  _______,                         _______, _______,   _______, _______,   _______,  _______,
        _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX,  XXXXXXX,                         KC_PGUP, KC_PRVWD,  KC_UP,   KC_NXTWD,  KC_DLINE, KC_BSPC,
        _______, KC_LALT, KC_LCTL, KC_LSFT, KC_BTN3,  KC_CAPS,                         KC_PGDN, KC_LEFT,   KC_DOWN, KC_RGHT,   KC_DEL,   KC_BSPC,
        _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, C(KC_H), _______,       _______, XXXXXXX, KC_LSTRT,  XXXXXXX, KC_LEND,   XXXXXXX,  KC_DEL,
                          _______, _______, _______,  _______, _______,       _______, _______,  _______,   _______, _______
    ),
    /* RAISE
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_RAISE] = LAYOUT(
        _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
        _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                        _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______
    ),
    /* ADJUST
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | BOOT | Spd+ | Val+ | Sat+ | Hue+ |Mode+ |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      | Spd- | Val- | Sat- | Hue- |Mode- |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |KoyNrm|      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MODE_FORWARD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MODE_REVERSE,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
        CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    )
    // clang-format on
};

static bool mod3_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            return false;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            return false;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            return false;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            return false;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            return false;
        case KC_COPY:
            if (record->event.pressed) {
                // CMD-c on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                /* register_code(KC_C); */
                register_code(KC_I); // KOY
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                /* unregister_code(KC_C); */
                unregister_code(KC_I); // KOY
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                // CMD-v on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                /* register_code(KC_V); */
                register_code(KC_Y); // KOY
            } else {
                unregister_code(KC_Y); // KOY
                unregister_mods(mod_config(MOD_LCTL));
                /* unregister_code(KC_V); */
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                // CMD-x on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                /* register_code(KC_X); */
                register_code(KC_Z); // KOY
            } else {
                unregister_code(KC_Z); // KOY
                unregister_mods(mod_config(MOD_LCTL));
                /* unregister_code(KC_X); */
            }
            return false;
        case KC_UNDO:
            if (record->event.pressed) {
                // CMD-z on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_B);
            } else {
                unregister_code(KC_B);
                unregister_mods(mod_config(MOD_LCTL));
            }
            return false;
        case KC_CAPS:
        case KC_NUHS:
            if (record->event.pressed) {
                mod3_active = true;
            } else {
                mod3_active = false;
            }
            return true;
        default:
            return true;
    }
}

static bool caps_word_active = false;

void caps_word_set_user(bool active) {
    caps_word_active = active;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        // Skip comma and dot in KOY layout
        case KC_A ... KC_Q:
        case KC_S ... KC_V:
        case KC_X ... KC_Z:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
        case KC_SCLN:
        case KC_QUOT:
            if (!mod3_active) {
                add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
                return true;
            } else {
                return false;
            }
        case KC_W:
            return mod3_active; // If MOD3 is pressed, don't leave caps word, is the _

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_CAPS:
        case KC_MINS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_LOWER]  = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [_RAISE]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
    [_ADJUST] = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)},
};
#endif

#ifdef OLED_ENABLE
/* #include "animations/animations/demon.c" */

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

void write_int_ln(const char* prefix, uint8_t value) {
    oled_write_P(prefix, false);
    oled_write(get_u8_str(value, ' '), false);
}

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("SveniChoc _____"), false);

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Alpha"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Sym  "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        default:
            oled_write_P(PSTR("???  "), false);
    }

    if (get_highest_layer(layer_state) == _ADJUST) {
        /* uint8_t mode  = rgb_matrix_get_mode(); */
        /* HSV     hsv   = rgb_matrix_get_hsv(); */
        /* uint8_t speed = rgb_matrix_get_speed(); */

        if (keymap_config.swap_lctl_lgui) {
            oled_write_ln_P(PSTR("MAC\n"), false);
        } else {
            oled_write_ln_P(PSTR("WIN\n"), false);
        }

        /* oled_write_ln("RGB", false); */
        /* write_int_ln(PSTR("Mo"), mode); */
        /* write_int_ln(PSTR("H "), hsv.h); */
        /* write_int_ln(PSTR("S "), hsv.s); */
        /* write_int_ln(PSTR("V "), hsv.v); */
        /* write_int_ln(PSTR("Sp"), speed); */
        /* oled_write_P(PSTR("\n\n\n"), false); */
    } else {
        /* oled_write_P(PSTR("\n\n\n\n\n\n\n\n\n"), false); */
        led_t led_usb_state = host_keyboard_led_state();
        if (led_usb_state.caps_lock) {
            oled_write_ln_P(PSTR(" CAP "), true);
        } else if (caps_word_active) {
            oled_write_ln_P(PSTR("CAPWD"), true);
        } else {
            oled_write_ln_P(PSTR("     "), false);
        }
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

#    include "luna.c"

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        /* oled_render_anim(); */
        print_status_narrow();
        /* #ifdef LUNA_ENABLE */
        led_usb_state = host_keyboard_led_state();
        render_luna(0, 13);
        /* #endif */
    } else {
        render_logo();
    }

    return false;
}

#endif
