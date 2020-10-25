/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "keymap_german.h"


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)





typedef enum {
    SINGLE_TAP, SINGLE_HOLD, DOUBLE
} tap_dance_state_enum;

static tap_dance_state_enum tap_dance_state;
static bool tap_dance_active = false;


void tap_dance_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data) {
    bool is_paste = state->count == 2;
    // If either the one-shot shift is set, or if shift is being held, count as shift being held.
    // We'll clear the one-shot shift if it was held
    uint8_t one_shot_mods = get_oneshot_mods();
    bool is_shift = false;

    if (get_mods() & MOD_MASK_SHIFT) {
        is_shift = true;
    } else if (one_shot_mods & MOD_MASK_SHIFT) {
        set_oneshot_mods(one_shot_mods & ~MOD_MASK_SHIFT);
        is_shift = true;
    }

    if (is_paste) {
        if (is_shift) {
            SEND_STRING(SS_LSFT(SS_TAP(X_INSERT)));
        } else {
            SEND_STRING(SS_LCTRL("v"));
        }
    } else {
        if (is_shift) {
            SEND_STRING(SS_LCTRL(SS_TAP(X_INSERT)));
        } else {
            SEND_STRING(SS_LCTRL("c"));
        }
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_COPY_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_copy_paste_finished, NULL)
};

void tap_dance_process_keycode(uint16_t keycode) {
    if (tap_dance_state == SINGLE_TAP) {
        tap_dance_active = false;
    }
}













const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_DEL,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,DE_QUES,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,_______,KC_ENT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RCTL,
                     _______,_______,                                                       _______, _______,
                                     RAISE ,KC_SPC ,                          KC_ENT, LOWER ,
                                    KC_BSPC,TD(TD_COPY_PASTE),                          KC_END, KC_DEL,
                                    _______,_______,                         KC_LGUI, KC_LALT
  ),

  [_LOWER] = LAYOUT_5x6(

     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                     _______,KC_PSCR,                                                         _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_RAISE] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                       _______,_______,                                                        KC_EQL ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),
};
