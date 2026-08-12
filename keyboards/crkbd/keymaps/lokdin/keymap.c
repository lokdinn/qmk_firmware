/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

// Defines the keycodes used by our macros in process_record_user
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _NUMPAD,
    _ADJUST
};

// Tap Dance Declarations
enum {
    TD_ALT,
    TD_OMA_MENU
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _QWERTY: Base Layer (Default Layer) */
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(_NUMPAD,KC_TAB),KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  TD(TD_OMA_MENU),MO(_LOWER),KC_SPC,     KC_ENT,MO(_RAISE),TD(TD_ALT)
                                      //`--------------------------'  `--------------------------'

   ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                      KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX,  KC_PSCR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, KC_KB_VOLUME_UP,              KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_BRIU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_KB_VOLUME_DOWN,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,MO(_ADJUST), _______
                                      //`--------------------------'  `--------------------------' 
    ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM, RALT(KC_SLSH),KC_LPRN,KC_RPRN,XXXXXXX,                    KC_EQL, KC_PLUS, KC_ASTR, KC_SLSH,KC_BACKSLASH,_______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_AT, KC_LCBR, KC_RCBR, XXXXXXX,                      KC_PERC, KC_HASH, KC_CIRC, KC_LABK, KC_RABK,  KC_DLR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                      KC_MINS, KC_UNDS, KC_PIPE,  KC_GRV, KC_AMPR, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
      ),

  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_PPLS,    KC_7,    KC_8,    KC_9, KC_PAST, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_PMNS,    KC_4,    KC_5,    KC_6, KC_PSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_0, KC_CALC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
      ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      DM_REC1, DM_PLY1, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX,                      DM_REC2, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX,                      DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
      )
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_OMA_MENU] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LAG(KC_SPC)), // Tap once for left GUI(super key), twice for GUI+Alt+Space
    [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT) // Tap once for Right Alt, twice for Left Alt 
};  

//

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}
return rotation;
}

// This function renders the current keyboard state (layer, lock keys, etc) to the OLED display
void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        oled_write_ln_P(PSTR("Qwerty"), false);
        break;
        case _LOWER:
        oled_write_ln_P(PSTR("Lower"), false);
        break;
        case _RAISE:
        oled_write_ln_P(PSTR("Raise"), false);
        break;
        case _NUMPAD:
        oled_write_ln_P(PSTR("Numpad"), false);
        break;
        case _ADJUST:
        oled_write_ln_P(PSTR("Adjust"), false);
        break;
    }
}

// This function is called by the RGB Matrix code to determine what colors to set for each LED
bool rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  bool caps_lock_enabled = host_keyboard_led_state().caps_lock;
  switch (get_highest_layer(layer_state)) {
    case _LOWER:
                for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            rgb_matrix_set_color(i, 0, 0, 255); // Blue color for the LOWER layer
        }
    break;

    case _RAISE:
        for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            rgb_matrix_set_color(i, 0, 255, 0); // Green color for the RAISE layer
        }
    break;

    case _NUMPAD:
        for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            rgb_matrix_set_color(i, 255, 255, 0); // Yellow color for the NUMPAD layer
        }
    break;

    case _ADJUST:
        for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            rgb_matrix_set_color(i, 94, 53, 168); // Purple color for the ADJUST layer
        }
    break;

    default:
        if (caps_lock_enabled) {
            for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
                rgb_matrix_set_color(i, 255, 0, 0); // Red color for Caps Lock
            }
        }
    break;
    }
  #endif

    return false;
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

    void set_keylog(uint16_t keycode, keyrecord_t *record) {
      char name = ' ';
      // If the keycode is a modifier or layer tap key, we need to mask it to get the actual keycode
      if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
          if (keycode < 60) {
            name = code_to_name[keycode];
        }

        // Update the keylog string with the keycode and its corresponding name
        snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
    }

    // This function renders the keylog to the OLED display
    void oled_render_keylog(void) {
        oled_write(keylog_str, false);
    }

    // This function renders the keyboard logo to the OLED display
    void oled_render_logo(void) {
        static const char PROGMEM crkbd_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
            0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
            0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
            0};
            oled_write_P(crkbd_logo, false);
        }

        bool oled_task_user(void) {
            if (is_keyboard_master()) {
                oled_render_layer_state();
                oled_render_keylog();
            } else {
                oled_render_logo();
            }
            return false;
        }

        bool process_record_user(uint16_t keycode, keyrecord_t *record) {
          if (record->event.pressed) {
            set_keylog(keycode, record);
        }
        return true;
    }

#ifdef RGB_MATRIX_ENABLE

    void suspend_power_down_user(void) {
        rgb_matrix_set_suspend_state(true);
    }

    void suspend_wakeup_init_user(void) {
        rgb_matrix_set_suspend_state(false);
    }
#endif

#endif // OLED_ENABLE