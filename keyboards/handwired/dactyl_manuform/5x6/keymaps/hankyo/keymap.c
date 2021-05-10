#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "hankyo.h"
#include "print.h"

//
#define CUT     LCTL(KC_X)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
#define UNDO    LCTL(DE_Z)
#define REDO    LCTL(DE_Y)
#define CTL_D   LCTL(KC_D)
#define BKSP_WRD LCTL(KC_BSPC)
#define DEL_WRD LCTL(KC_DEL)
#define SAVE    LCTL(KC_S)
#define CTLT   LCTL(KC_T)
#define CTLA   LCTL(KC_A)
#define CTLD   LCTL(KC_D)
#define CTLW   LCTL(KC_W)
#define WINE   LGUI(KC_E)

#define WRD_LEFT   LCTL(KC_LEFT)
#define WRD_RGHT   LCTL(KC_RGHT)

// one shot modifierer
#define OS_ALT  OSM (MOD_LALT)
#define OS_CTL  OSM (MOD_LCTL)
#define OS_GUI  OSM (MOD_LGUI)
#define OS_SFT  OSM (MOD_LSFT)


// one shot layer
#define OSL_ARW  OSL(_ARROW)
#define OSL_SYM  OSL(_SYMBOL)
#define OSL_MED  OSL(_MEDIA)
#define OSL_FUN  OSL(_FUNCTION)
#define OSL_MSE  OSL(_MOUSE)


// default layer
#define DF_QWER  DF(_QWERTY)
#define DF_KOY  DF(_KOY)

// other
enum my_keycodes {
    KC_BSPCDEL = SAFE_RANGE,
    LOG_ENABLE,
    LOG_DISABLE
};

bool logEnable = true;

// home row mods
#define HR_H LGUI_T(KC_H)
#define HR_A LALT_T(KC_A)
#define HR_E LSFT_T(KC_E)
#define HR_I LCTL_T(KC_I)

#define HR_T LCTL_T(KC_T)
#define HR_R LSFT_T(KC_R)
#define HR_N LALT_T(KC_N)
#define HR_S LGUI_T(KC_S)


//
#define GUI_DOT MT(MOD_LGUI, KC_DOT)
#define ALT_COM MT(MOD_LALT, KC_COMM)

#define ALT_G MT(MOD_LALT, KC_G)
#define GUI_L MT(MOD_RGUI, KC_L)


// mod tap
#define MT_SPC MT(MOD_LSFT, KC_SPC)
#define MT_ENT MT(MOD_LSFT, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_DEL,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LEAD,
     OS_SFT , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,DE_QUES,OS_SFT ,
     OS_CTL , KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,OS_CTL ,
                     OSL_SYM,KC_LALT,                                                        KC_LGUI,OSL_SYM,
                                     KC_BSPC, KC_SPC,                        KC_ENT ,KC_BSPC,
                                     OSL_ARW, OS_SFT,                        OS_SFT, KC_DEL ,
                                     XXXXXXX,OSL_FUN,                        OSL_FUN,OSL_ARW
  ),

  [_KOY] = LAYOUT_5x6(
     XXXXXXX, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                          KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,XXXXXXX,
     XXXXXXX, KC_K  ,KC_DOT , KC_O  ,KC_COMM, DE_Y  ,                          KC_V  , KC_G  , KC_C  , KC_L  , DE_Z  ,XXXXXXX,
    //   KC_X  , HR_H  , HR_A  , HR_E  , HR_I  , KC_U  ,                          KC_D  , HR_T  , HR_R  , HR_N  , HR_S  , KC_J  ,
      KC_X  , KC_H  , KC_A  , KC_E  , KC_I  , KC_U  ,                          KC_D  , KC_T  , KC_R  , KC_N  , KC_S  , KC_J  ,
     OS_CTL , KC_F  , KC_Q  ,KC_SLSH,KC_TAB, KC_ESC,                           KC_B  , KC_P  , KC_W  , KC_M  ,DE_SCLN,OS_CTL ,
                     OSL_SYM,KC_LALT,                                                       KC_LGUI, OSL_SYM,
                                     OS_SFT , KC_SPC,                        KC_ENT ,OS_SFT ,
                                     OSL_ARW, KC_BSPC,                       KC_BSPC ,OSL_ARW,
                                     OSL_MSE,OSL_FUN,                        OSL_FUN,OSL_MED
  ),

  [_ARROW] = LAYOUT_5x6(
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
     _______,XXXXXXX,XXXXXXX, SAVE  ,XXXXXXX,XXXXXXX,                        XXXXXXX,KC_PGUP, KC_UP ,KC_PGDN,XXXXXXX,XXXXXXX,
     _______,XXXXXXX,KC_LGUI,KC_LSFT,KC_LCTL, UNDO  ,                        KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,XXXXXXX,
     _______, REDO  , CUT   , COPY  , PASTE ,_______,                        XXXXXXX,KC_BSPC,XXXXXXX,KC_DEL ,XXXXXXX,XXXXXXX,
                     _______,_______,                                                        _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______,
                                        _______,_______,                  _______,_______
  ),

  [_MOUSE] = LAYOUT_5x6(
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,KC_WH_D,KC_MS_U,KC_WH_U,XXXXXXX,XXXXXXX,
     _______,XXXXXXX,KC_LGUI,KC_LSFT,KC_LCTL,XXXXXXX,                        KC_WH_L,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_R,XXXXXXX,
     _______,XXXXXXX,KC_BTN1,KC_BTN3,KC_BTN2,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
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
     _______,DF_QWER,XXXXXXX, DF_KOY,XXXXXXX,XXXXXXX,                        XXXXXXX,LOG_ENABLE,XXXXXXX,LOG_DISABLE,XXXXXXX,XXXXXXX,
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

    if (logEnable) {
        if (record->event.pressed) {
            xprintf ("<start>c=%02d, r=%02d, k=%d, l=%d<end>\n",
                record->event.key.col, record->event.key.row, keycode, get_highest_layer(layer_state));
        }
    }

    // if (logEnable) {
    //     if (record->event.pressed) {
    //             uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state));
    //     }
    // }


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

        case LOG_ENABLE:
            logEnable = true;
        return false;

        case LOG_DISABLE:
            logEnable = false;
        return false;

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

const uint16_t PROGMEM c_copy[] =       {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM c_paste[] =      {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM c_cut[] =        {KC_A, KC_E, COMBO_END};

const uint16_t PROGMEM c_del[] =        {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM c_del_wrd[] =    {KC_A, KC_I, COMBO_END};
const uint16_t PROGMEM c_bksp[] =       {KC_T, KC_R, COMBO_END};
const uint16_t PROGMEM c_bksp_wrd[] =   {KC_T, KC_N, COMBO_END};

const uint16_t PROGMEM c_undo[] =       {KC_DOT, KC_O, COMBO_END};
const uint16_t PROGMEM c_redo[] =       {KC_O, KC_COMM, COMBO_END};

const uint16_t PROGMEM c_save[] =       {KC_O, KC_E, COMBO_END};

const uint16_t PROGMEM c_left[] =       {KC_P, KC_W, COMBO_END};
const uint16_t PROGMEM c_right[] =      {KC_W, KC_M, COMBO_END};
const uint16_t PROGMEM c_up[] =         {KC_P, KC_R, COMBO_END};
const uint16_t PROGMEM c_down[] =       {KC_M, KC_R, COMBO_END};

const uint16_t PROGMEM c_d[] =          {KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM c_enter[] =      {KC_Q, KC_SLSH, COMBO_END};

// const uint16_t PROGMEM c_home[] =       {KC_P, KC_R, COMBO_END};
// const uint16_t PROGMEM c_end[] =        {KC_M, KC_R, COMBO_END};

const uint16_t PROGMEM c_wrd_left[] =   {KC_P, KC_M, COMBO_END};
const uint16_t PROGMEM c_wrd_rght[] =   {KC_W, DE_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(c_copy,       COPY),
    COMBO(c_paste,      PASTE),
    COMBO(c_cut,        CUT),

    COMBO(c_del,        KC_DEL),
    COMBO(c_del_wrd,    DEL_WRD),
    COMBO(c_bksp,       KC_BSPC),
    COMBO(c_bksp_wrd,   BKSP_WRD),

    COMBO(c_undo,       UNDO),
    COMBO(c_redo,       REDO),

    COMBO(c_save,       SAVE),

    COMBO(c_left,       KC_LEFT),
    COMBO(c_right,      KC_RGHT),
    COMBO(c_up,         KC_UP),
    COMBO(c_down,       KC_DOWN),

    COMBO(c_d,          CTL_D),
    COMBO(c_enter,      KC_ENT),

    // COMBO(c_home,       KC_HOME),
    // COMBO(c_end,        KC_END),

    COMBO(c_wrd_rght,   WRD_RGHT),
    COMBO(c_wrd_left,   WRD_LEFT)

};



// TODO

/*
combos vom baselayer entfernen

ctlt a auf linker seite

CTLT
ctl shift t

CTLW
WINE

home
end
pgup
pgdn

enter zusätzlich auf die linke seite

ausprobieren:
- und f tauschen
- ctrl und ; ctrl je auf eine taste

*/
