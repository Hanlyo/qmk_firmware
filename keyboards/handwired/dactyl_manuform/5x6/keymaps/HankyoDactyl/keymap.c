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


// one shot modifierer
#define OS_ALT  OSM (MOD_LALT)
#define OS_CTL  OSM (MOD_LCTL)
#define OS_GUI  OSM (MOD_LGUI)
#define OS_SFT  OSM (MOD_LSFT)


// tapDance
#define TD_ARW  TD(ARROW)
#define TD_SYMB  TD(SYMBOL)
#define TD_FNC  TD(FUNCTION)


// layer
#define OSL_ARW  OSL(_ARROW)
#define OSL_ARW  OSL(_ARROW)
#define OSL_SYM  OSL(_SYMBOL)
#define OSL_FUN  OSL(_FUNCTION)
//#define RAISE MO(_RAISE)
//#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_DEL,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,_______,
     OS_SFT , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,DE_QUES,OS_SFT ,
     OS_CTL , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,OS_CTL ,
                     _______,KC_LALT,                                                       KC_LGUI, _______,
                                      KC_DEL, KC_SPC,                        KC_ENT ,KC_BSPC,
                                     OSL_SYM,OSL_ARW,                        OSL_FUN ,OSL_SYM,
                                     _______,_______,                        _______,_______
  ),

  [_DVORAK] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_DEL,
     KC_TAB ,DE_QUES,KC_COMM,KC_DOT , KC_P  , KC_Y  ,                         KC_F  , KC_G  , KC_C  , KC_T  , KC_Z  ,_______,
     OS_SFT , KC_A  , KC_O  , KC_E  , KC_I  , KC_U  ,                         KC_H  , KC_D  , KC_R  , KC_N  , KC_S  ,OS_SFT ,
     OS_CTL ,KC_SLSH, KC_Q  , KC_J  , KC_K  , KC_X  ,                         KC_B  , KC_M  , KC_W  , KC_V  , KC_L  ,OS_CTL ,
                     _______,_______,                                                       _______, _______,
                                      KC_DEL,KC_SPC ,                        KC_ENT ,KC_BSPC,
                                     OSL_SYM,OSL_ARW,                        OSL_FUN ,OSL_SYM,
                                     _______,_______,                        _______,_______
  ),

  [_ARROW] = LAYOUT_5x6(
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,KC_PGUP, KC_UP ,KC_PGDN,XXXXXXX,XXXXXXX,
     _______,XXXXXXX, CUT   , COPY  , PASTE ,XXXXXXX,                        KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,XXXXXXX,
     _______,XXXXXXX,XXXXXXX, UNDO  , REDO  ,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_VOLU,KC_MNXT,
                     _______,_______,                                                        KC_MPLY,KC_VOLD,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),

  [_SYMBOL] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,DE_TILD,DE_PIPE,DE_LBRC,DE_RBRC,DE_QUOT,                        DE_ASTR,DE_LABK,DE_RABK,DE_AMPR,DE_UDIA,XXXXXXX,
     _______,DE_HASH,DE_EQL ,DE_LCBR,DE_RCBR,DE_SLSH,                        DE_BSLS,DE_LPRN,DE_RPRN,DE_PLUS,DE_ODIA,DE_ADIA,
     _______,DE_EURO,XXXXXXX, DE_AT ,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                     _______,_______,                                                        _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),

/*
  [_MEDIA] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,KC_VOLD,KC_MNXT,
                     _______,_______,                                                        KC_MPLY,KC_VOLU,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),
*/
  [_FUNCTION] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______, KC_F9 , KC_F10, KC_F11, KC_F12,XXXXXXX,                        XXXXXXX, KC_F9 , KC_F10, KC_F11, KC_F12,_______,
     _______, KC_F5 , KC_F6 , KC_F7 , KC_F8 ,XXXXXXX,                        XXXXXXX, KC_F5 , KC_F6 , KC_F7 , KC_F8 ,_______,
     _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 ,XXXXXXX,                        XXXXXXX, KC_F1 , KC_F2 , KC_F3 , KC_F4 ,_______,
                     _______,_______,                                                        _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),

  [_SETTINGS] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
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

/*
  [_LOWER] = LAYOUT_5x6(
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                             _______,KC_PSCR,            _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
  ),
  [_RAISE] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                                               _______,_______,            KC_EQL ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),
*/
};

