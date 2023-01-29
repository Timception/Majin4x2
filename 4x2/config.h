/*
Copyright 2022 Timception

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

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 4


/* key matrix pins */

/* Top to Bottom */
#define MATRIX_ROW_PINS { F5, F6, F4 }

/* Left to Right */
#define MATRIX_COL_PINS { F7, B1, B3, B2 }

#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { D4 }
#define ENCODER_DEFAULT_POS 0x3

//#define VIAL_ENCODER_DEFAULT { RGB_RMOD, RGB_MOD, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU }


// 4 LED Layer Indicator
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define VIAL_KEYBOARD_UID {0xCA, 0x24, 0xDC, 0x4A, 0x52, 0x73, 0x0A, 0x56}
//#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
//#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

