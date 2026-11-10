/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

/* Select hand configuration */

#define MASTER_LEFT // This is the master side of the keyboard

#define SPLIT_LAYER_STATE_ENABLE // Sync active layer to the slave half (layer colors on both sides)
#define SPLIT_LED_STATE_ENABLE   // Sync host LED state (Caps Lock) to the slave half

#define AUTO_SHIFT_TIMEOUT 150 // 150 ms to hold a key
#define AUTO_SHIFT_ENTER // Enable auto shift for Enter key
#define NO_AUTO_SHIFT_NUMERIC // Do not auto shift for numeric keys (0-9)
#define NO_AUTO_SHIFT_TAB // Do not auto shift for Tab key

// #define SSD1306OLED
#undef USE_I2C
#undef SSD1306OLED

#define USE_SERIAL_PD2

#define DYNAMIC_MACRO_SIZE 32 

#define TAPPING_TERM 200 // Time in milliseconds tap vs hold

// Select the font size for the OLED display
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_MATRIX_SLEEP // turn off effects when suspended (antes RGB_DISABLE_WHEN_USB_SUSPENDED, nombre obsoleto)
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10

/* Enable only the animations you want (QMK effects are opt-in: ENABLE_RGB_MATRIX_*). *
 * Each one uses flash space, check the firmware size after adding more.               */
#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#   define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#   define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#   define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // only lights up on keypress
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // only lights up on keypress
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // only lights up on keypress
#endif