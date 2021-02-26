#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "tapDance.h"
#include "layer.h"

//
#define CUT     LCTL(KC_X)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
#define UNDO    LCTL(DE_Z)
#define REDO    LCTL(DE_Y)
#define CTL_D   LCTL(KC_D)
#define DEL_WRD LALT(KC_BSPC)
#define SAVE    LCTL(KC_S)
#define CTLT   LCTL(KC_T)
#define CTLA   LCTL(KC_A)
#define CTLD   LCTL(KC_D)
#define CTLW   LCTL(KC_W)
#define WINE   LGUI(KC_E)


// one shot modifierer
#define OS_ALT  OSM (MOD_LALT)
#define OS_CTL  OSM (MOD_LCTL)
#define OS_GUI  OSM (MOD_LGUI)
#define OS_SFT  OSM (MOD_LSFT)


// tapDance
#define TD_CP   TD(CP)  // copy paste
#define TD_BSPC   TD(BSPC)


// one shot layer
#define OSL_ARW  OSL(_ARROW)
#define OSL_SYM  OSL(_SYMBOL)
#define OSL_MED  OSL(_MEDIA)
#define OSL_FUN  OSL(_FUNCTION)

// default layer
#define DF_QWER  DF(_QWERTY)
#define DF_KOY  DF(_KOY)
#define DF_KOY_ALT  DF(_KOY_ALT)

// other
enum my_keycodes {
    KC_BSPCDEL = SAFE_RANGE
};



// test
#define MT_H MT(MOD_LGUI, KC_H)
#define MT_A MT(MOD_LALT, KC_A)
#define MT_E MT(MOD_LSFT, KC_E)
#define MT_I MT(MOD_LCTL, KC_I)

#define MT_T MT(MOD_RCTL, KC_T)
#define MT_R MT(MOD_RSFT, KC_R)
#define MT_N MT(MOD_LALT, KC_N)
#define MT_S MT(MOD_RGUI, KC_S)



//
#define GUI_DOT MT(MOD_LGUI, KC_DOT)
#define ALT_COM MT(MOD_LALT, KC_COMM)

#define ALT_G MT(MOD_LALT, KC_G)
#define GUI_L MT(MOD_RGUI, KC_L)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_DEL,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LEAD,
     OS_SFT , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,DE_QUES,OS_SFT ,
     OS_CTL , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,OS_CTL ,
                     OSL_SYM ,KC_LALT,                                                       KC_LGUI, OSL_SYM ,
                                     KC_BSPC, KC_SPC,                        KC_ENT ,KC_BSPC,
                                     OSL_ARW, OS_SFT,                        OS_SFT, KC_DEL ,
                                     XXXXXXX,OSL_FUN,                        OSL_FUN,OSL_ARW
  ),

  [_KOY] = LAYOUT_5x6(
     XXXXXXX, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_DEL,
     KC_TAB , KC_K  ,KC_DOT , KC_O  ,KC_COMM, DE_Y  ,                         KC_V  , KC_G  , KC_C  , KC_L  , DE_Z  ,KC_LEAD,
      KC_X  , KC_H  , KC_A  , KC_E  , KC_I  , KC_U  ,                         KC_D  , KC_T  , KC_R  , KC_N  , KC_S  , KC_J  ,
     OS_CTL , KC_F  , KC_Q  ,KC_SLSH,XXXXXXX, KC_ESC,                         KC_B  , KC_P  , KC_W  , KC_M  ,XXXXXXX,OS_CTL ,
                     OSL_SYM,KC_LALT,                                                       KC_LGUI, OSL_SYM,
                                     OS_SFT , KC_SPC,                        KC_ENT ,OS_SFT ,
                                     OSL_ARW, KC_BSPC,                       KC_BSPC ,OSL_ARW,
                                     OSL_MED,OSL_FUN,                        OSL_FUN,OSL_MED
  ),

//     XXXXXXX, MT_H  , MT_A  , MT_E  , MT_I  , KC_U  ,                         KC_D  , MT_T  , MT_R  , MT_N  , MT_S  ,XXXXXXX,
  [_KOY_ALT] = LAYOUT_5x6(
     XXXXXXX, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_DEL,
     KC_TAB , KC_K  ,KC_DOT , KC_O  ,KC_COMM, DE_Y  ,                         KC_V  , KC_G  , KC_C  , KC_L  , DE_Z  ,KC_LEAD,
      KC_X  , KC_H  , KC_A  , KC_E  , KC_I  , KC_U  ,                         KC_D  , KC_T  , KC_R  , KC_N  , KC_S  , KC_J  ,
     OS_CTL , KC_F  , KC_Q  ,KC_SLSH,XXXXXXX, KC_ESC,                         KC_B  , KC_P  , KC_W  , KC_M  ,XXXXXXX,OS_CTL ,
                     OSL_SYM,KC_LALT,                                                       KC_LGUI, OSL_SYM,
                                     OS_SFT , KC_SPC,                        KC_ENT ,OS_SFT ,
                                     OSL_ARW, KC_BSPC,                       KC_BSPC ,OSL_ARW,
                                     OSL_MED,OSL_FUN,                        OSL_FUN,OSL_MED
  ),

  [_ARROW] = LAYOUT_5x6(
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
     _______,XXXXXXX, CTLW  , WINE  ,XXXXXXX, CTLT  ,                        XXXXXXX,KC_PGUP, KC_UP ,KC_PGDN,XXXXXXX,XXXXXXX,
     _______, CTLA  , SAVE  , CTLD  ,XXXXXXX, UNDO  ,                        KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,XXXXXXX,
     _______, REDO  , CUT   , COPY  , PASTE ,_______,                        XXXXXXX,KC_BSPC,XXXXXXX,KC_DEL ,XXXXXXX,XXXXXXX,
                     _______,_______,                                                        _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),

  [_MEDIA] = LAYOUT_5x6(
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX, KC_UP ,XXXXXXX,XXXXXXX,_______,
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,_______,
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,                        _______,_______,KC_MPLY,KC_VOLD,KC_VOLU,KC_MNXT,
                     _______,_______,                                                        _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),

  [_SYMBOL] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,DE_TILD,DE_PIPE,DE_LBRC,DE_RBRC,DE_QUOT,                        DE_ASTR,DE_LABK,DE_RABK,DE_AMPR,DE_UDIA, DE_SS ,
     _______,DE_HASH,DE_EQL ,DE_LCBR,DE_RCBR,DE_SLSH,                        DE_BSLS,DE_LPRN,DE_RPRN,DE_PLUS,DE_ODIA,DE_ADIA,
     _______,DE_EURO,XXXXXXX, DE_AT ,XXXXXXX,_______,                        DE_QUES,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     _______,_______,                                                        _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),

  [_FUNCTION] = LAYOUT_5x6(
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        DM_PLY1,DM_PLY2,XXXXXXX,DM_REC1,DM_REC2,XXXXXXX,
     _______, KC_F9 , KC_F10, KC_F11, KC_F12,XXXXXXX,                        XXXXXXX, KC_F9 , KC_F10, KC_F11, KC_F12,_______,
     _______, KC_F5 , KC_F6 , KC_F7 , KC_F8 ,XXXXXXX,                        XXXXXXX, KC_F5 , KC_F6 , KC_F7 , KC_F8 ,_______,
     _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 ,_______,                        XXXXXXX, KC_F1 , KC_F2 , KC_F3 , KC_F4 ,_______,
                     _______,_______,                                                        _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),

  [_SETTINGS] = LAYOUT_5x6(
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, RESET ,                         RESET ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
     _______,DF_QWER,XXXXXXX, DF_KOY,XXXXXXX,XXXXXXX,                        XXXXXXX,DF_KOY_ALT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     _______,_______,                                                        _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),

/*
  [_BLANCK] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                     _______,_______,                                                        _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),
*/

};



uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _FUNCTION, _SYMBOL, _SETTINGS);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /*static uint8_t saved_mods = 0;
    uint8_t one_shot_mods = get_oneshot_mods();*/

    switch (keycode) {
        /*case KC_BSPCDEL:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    saved_mods = get_mods() & MOD_MASK_SHIFT; // Mask off anything that isn't Shift
                    del_mods(saved_mods); // Remove any Shifts present
                    register_code(KC_DEL);
                } else if (one_shot_mods & MOD_MASK_SHIFT) {
                    saved_mods = 0; // Clear saved mods so the add_mods() below doesn't add Shifts back when it shouldn't
                    set_oneshot_mods(one_shot_mods & ~MOD_MASK_SHIFT); // Remove oneshot Shifts
                    register_code(KC_DEL);
                } else {
                    saved_mods = 0; // Clear saved mods so the add_mods() below doesn't add Shifts back when it shouldn't
                    register_code(KC_BSPC);
                }
            } else {
                add_mods(saved_mods);
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
            }
            return false;*/
        case KC_ESC:

            layer_clear();
            reset_oneshot_layer();
            clear_oneshot_mods();
            clear_mods();
            return true;


    /*
 case RCTL_T(KC_N):
        if (record->tap.count > 0) {
            if (get_mods() & MOD_BIT(KC_RSHIFT)) {
                unregister_mods(MOD_BIT(KC_RSHIFT));
                tap_code(KC_E);
                tap_code(KC_N);
                add_mods(MOD_BIT(KC_RSHIFT));
                return false;
            }
        }
        return true;

    case LALT_T(KC_A):
        if (record->tap.count > 0) {
            if (get_mods() & MOD_BIT(KC_LGUI)) {
                unregister_mods(MOD_BIT(KC_LGUI));
                tap_code(KC_H);
                tap_code(KC_A);
                add_mods(MOD_BIT(KC_LGUI));
                return false;
            }
        }
        return true;
    }

*/





        default:
            return true; // Process all other keycodes normally
    }
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_D, KC_D) {
            register_code(KC_LALT);
            register_code(KC_F4);
            unregister_code(KC_F4);
            unregister_code(KC_LALT);
        }
    }
}
