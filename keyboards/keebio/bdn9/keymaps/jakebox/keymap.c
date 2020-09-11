#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
};
// enum {
//     L_AND_R,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
                        LAYER 0 - General Use
        | Knob 1: Vol Dn/Up     |            | Knob 2: Arrow Dn/Up   |
        | Press: Mute           | To layer 1 | Press: Close window   |
        | Copy/paste            | F15        | Previous webpage/bspc |
        | Left a desktop (Undo) | Mod        | Right a desktop       |
     */
    [0] = LAYOUT(
        KC_MUTE, TO(1) , LCMD(KC_W),
        M(0)   , KC_F15, KC_BSPC,
        A(KC_A), MO(5) , A(KC_D)
    ),

    /*
                LAYER 1 - Discord/Gaming
        | Mute vol   | To layer 2  |      |
        |  F15       | Mute voice  |      |
        |            | Deafen      |      |
     */
    [1] = LAYOUT(
        KC_MUTE, TO(2)  , XXXXXXX,
        KC_F15 , KC_PGUP, XXXXXXX,
        XXXXXXX, KC_PGDN, XXXXXXX
    ),

    /*
                LAYER 2 - Zoom
        | Mute volume    | To layer 0   | Leave meeting |
        | Toggle camera  | Push to talk | Toggle mute   |
        | Left           | Show chat    | Right         |
     */
    [2] = LAYOUT(
        KC_MUTE      , TO(0)        , LCMD(KC_W),
        LCMD(S(KC_V)), KC_SPC      , LCMD(S(KC_A)),
        C(KC_LEFT)   , LCMD(S(KC_H)), C(KC_RIGHT)
    ),

    // MOD LAYER
    [5] = LAYOUT(
        KC_MPLY      , XXXXXXX, XXXXXXX,
        LCMD(S(KC_V)), XXXXXXX, BL_TOGG,
        LCMD(KC_Z)   , KC_TRNS, XXXXXXX
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == _RIGHT) {
            if (clockwise) {
               SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_UP(X_LCTL));
            }
            else {
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LCTL) SS_UP(X_LSFT));
            }
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case 0: {
            if (record->event.pressed) {
                return MACRO( D(LCMD), T(C), U(LCMD), END  );
            } else {
                return MACRO( D(LCMD), T(V), U(LCMD), END  );
            }
            break;
        }
    }
    return MACRO_NONE;
};

// qk_tap_dance_action_t tap_dance_actions[] = {
//     [L_AND_R] = ACTION_TAP_DANCE_DOUBLE(A(KC_D), A(KC_A)),
// };
