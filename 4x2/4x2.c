#include "4x2.h"

#ifdef RGB_MATRIX_ENABLE
// LED Identification
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED },
  {      0,      1,      2,      3 }
}, {
  // LED Index to Physical Position
  { 19,  11 }, { 25,  11 }, { 38,  11 }, { 75,  11 }
  //{ 0,  64}, { 75,  64 }, { 149,  64 }, { 224,  64 }	//How it should actually be
}, {
  // LED Index to Flag
  4, 4, 4, 4
} };


void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif