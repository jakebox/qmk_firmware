#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* ZOOM LAYER
    Mod                 Toggle fullscreen Leave call
    Toggle video        Push to talk      Toggle microphone
    Show windows (C-up) Toggle chat       Toggle participants/speaker view
    */

    [0] = LAYOUT(
        MO(5)         ,  LCMD(S(KC_F)), LCMD(KC_W),
        LCMD(S(KC_V)) ,  KC_SPC       , LCMD(S(KC_X)),
        C(KC_UP)      ,  LCMD(S(KC_H)), LCMD(S(KC_W))
    ),

    /* MOD LAYER
    TRNS     Volume mute  Quit
    XXXXXXX  Volume up    XXXXXXX
    Reset    Volume down  Spotlight
    */

    [5] = LAYOUT(
        KC_TRNS, KC_MUTE, LCMD(KC_Q),
        XXXXXXX, KC_VOLU, XXXXXXX,
        RESET ,  KC_VOLD, LCMD(KC_SPC)
    ),
};
