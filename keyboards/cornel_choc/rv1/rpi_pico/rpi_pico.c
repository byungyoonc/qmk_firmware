#include "rpi_pico.h"
#include "print.h"

// clang-format off
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {{
    // Left split
    { 5,      4,      3,      2,  1,  0  },
    { 6,      7,      8,      9,  10, 11 },
    { 17,     16,     15,     14, 13, 12 },
    { 18,     19,     20,     21, 22, 23 },
    { NO_LED, NO_LED, NO_LED, 26, 25, 24 },
    // Right split
    { 32,     31,     30,     29, 28, 27 },
    { 33,     34,     35,     36, 37, 38 },
    { 44,     43,     42,     41, 40, 39 },
    { 45,     46,     47,     48, 49, 50 },
    { NO_LED, NO_LED, NO_LED, 53, 52, 51 },
}, {
    { 87,  6}, { 70,  3}, { 52,  0}, { 35,  3}, { 17,  6}, {  0,  6},
    {  0, 19}, { 17, 19}, { 35, 16}, { 52, 13}, { 70, 16}, { 87, 19},
    { 87, 32}, { 70, 29}, { 52, 26}, { 35, 29}, { 17, 32}, {  0, 32},
    {  0, 45}, { 17, 45}, { 35, 42}, { 52, 38}, { 70, 42}, { 87, 45},
                                     {105, 64}, { 83, 61}, { 61, 58},
    {140,  6}, {157,  6}, {175,  3}, {192,  0}, {210,  3}, {227,  6},
    {227, 19}, {210, 16}, {192, 13}, {175, 16}, {157, 19}, {140, 19},
    {140, 32}, {157, 32}, {175, 29}, {192, 26}, {210, 29}, {227, 32},
    {227, 45}, {210, 42}, {192, 38}, {175, 42}, {157, 45}, {140, 45},
    {122, 64}, {162, 61}, {183, 58}
}, {
    4, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
             4, 1, 1,
    4, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
             4, 1, 1
}};
#endif

void board_init(void) {
}

void keyboard_post_init_user(void) {
    debug_enable   = true;
}
