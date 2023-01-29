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

    [0] = LAYOUT_65_ansi(
       	          RGB_TOG , KC_F15 , KC_F16 , KC_F19 ,
                  TO(1)   , KC_F21 , KC_F22 , KC_F23  ,
				  KC_MUTE
    ),
	
	[1] = LAYOUT_65_ansi(
       	          RGB_TOG , KC_F15 , KC_F16 , KC_F19  ,
			      TO(2)   , KC_F21 , KC_F22 , KC_F23  ,
				  KC_MUTE
    ),
	
	[2] = LAYOUT_65_ansi(
       	          RGB_TOG , KC_F15 , KC_F16 , KC_F19  ,
			      TO(3)   , KC_F21 , KC_F22 , KC_F23  ,
				  KC_MUTE
    ),
	
	[3] = LAYOUT_65_ansi(
       	          RGB_TOG , RGB_MOD  , RGB_HUI , RGB_VAI ,
			      TO(0)   , RGB_RMOD , RGB_HUD , RGB_VAD ,
				  KC_MUTE
    )

};



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



