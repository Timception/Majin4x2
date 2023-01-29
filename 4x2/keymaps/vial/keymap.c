/* Copyright 2022 Timception
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
#include "raw_hid.h"
#include "quantum.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_all(
  LCTL(KC_C), LCTL(KC_X), SGUI(KC_S), TO(1),
  LCTL(KC_V), LCTL(KC_Z),      KC_F5, TO(3),
LGUI(KC_TAB)
    ),
	
	[1] = LAYOUT_all(
	 KC_BTN1, KC_MS_U, KC_BTN2, TO(2),
	 KC_MS_L, KC_MS_D, KC_MS_R, TO(0),
	 KC_BTN3
    ),
	
	[2] = LAYOUT_all(
	 RGB_MOD, RGB_VAI, RGB_SPI, TO(3),
    RGB_RMOD, RGB_VAD, RGB_SPD, TO(1),
	 RGB_MOD
    ),
	
	[3] = LAYOUT_all(
	 KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
     KC_TRNS, KC_TRNS, KC_TRNS, TO(2),
LGUI(KC_TAB)
    )

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [3] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) }
};
#endif



//Tim's rgb code
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)) {
        case 0:
			rgb_matrix_enable();
            rgb_matrix_set_color(1, 0, 0, 0);
            rgb_matrix_set_color(2, 0, 0, 0);
            rgb_matrix_set_color(3, 0, 0, 0);
            break;
        case 1:
			rgb_matrix_enable();
            rgb_matrix_set_color(2, 0, 0, 0);
            rgb_matrix_set_color(3, 0, 0, 0);
            break;
        case 2:
			rgb_matrix_enable();
            rgb_matrix_set_color(3, 0, 0, 0);
            break;
        case 3:
			rgb_matrix_enable();
            break;
        default:
            break;
    }
}



// Electrical Matrix to LED index lookup table
// What the physical position of each LED is on the board
// What type of key or usage the LED if the LED represents
void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    if(data[0] == 0xFC){
        switch (data[1]) {
            case 0x01:{
                // move to layer
                data[1] = 0xFD;
                layer_move(data[2]);
                break;
            }
            case 0x02:{
                // turn on layer
                data[1] = 0xFD;
                layer_on(data[2]);
                break;
            }
            case 0x03:{
                // turn off layer
                data[1] = 0xFD;
                layer_off(data[2]);
                break;
            }
        }
    }
    raw_hid_send(data, length);
}



