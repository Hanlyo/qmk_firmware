
#include "planck.h"
#include "action_layer.h"
#include "Hankyo.h"
#include "keymap_german.h"


#define N_LT KC_NONUS_BSLASH
#define N_HS KC_NONUS_HASH
#define N_DOTS RALT(KC_DOT) // …
#define N_USC LSFT(KC_SLASH) // _
#define N_LSQBR RALT(KC_8) // [
#define N_RSQBR RALT(KC_9) // ]
#define N_CIRC KC_GRAVE // ^
#define N_EXKL LSFT(KC_1) // !
#define N_GT LSFT(KC_NONUS_BSLASH) // >
#define N_EQ LSFT(KC_0) // =
#define N_AMP LSFT(KC_6) // &
#define N_BSLS RALT(KC_MINS) // \ backslash
#define N_SLSH LSFT(KC_7) // /
#define N_LCUBR RALT(KC_7) // {
#define N_RCUBR RALT(KC_0) // }
#define N_ASTR LSFT(KC_RBRC) // *
#define N_QUES LSFT(KC_MINS) // ?
#define N_LPARN LSFT(KC_8) // (
#define N_RPARN LSFT(KC_9) // )
#define N_MINS KC_SLASH // -
#define N_COLN LSFT(KC_DOT) // :
#define N_ABRL KC_BSLASH // <
#define N_DLR LSFT(KC_4) // $
#define N_PIPE RALT(KC_NONUS_BSLASH) // |
#define N_TILD RALT(KC_RBRC) // ~
#define N_GRAVE LSFT(KC_EQUAL) // `
#define N_PLUS KC_RBRC // +
#define N_PERC LSFT(KC_5) // %
#define N_QUOT LSFT(KC_2) // "
#define N_ABRR LSFT(KC_BSLASH) // >
#define N_SEMI LSFT(KC_COMM) // ;
#define N_EURO RALT(KC_E) // €
#define N_AT RALT(KC_Q) // @
#define N_Z KC_Y
#define N_Y KC_Z
#define N_AE KC_QUOTE // ä
#define N_OE KC_SCOLON // ö
#define N_UE KC_LBRACKET // ü
#define N_MU RALT(KC_M) // µ
#define N_SS KC_MINS // ß
#define N_DEGRE LSFT(KC_GRAVE) // °
#define N_PASTE LCTL(KC_V) // CTRL+V
#define N_COPY LCTL(KC_C) // CTRL+C
#define N_CUT LCTL(KC_X) // CTRL+X
#define N_UNDO LCTL(N_Z) // CTRL+Z


extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _GAME,
  _NEO,
  _LOWER,
  _RAISE,
//  _MOUSE,
//  _PLOVER,
  _ADJUST,
  _FN,
  _SPACE_FN
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  NEO,
  RAISE,
  LOWER//,
//  PLOVER,
//  BACKLIT//,
//  EXT_PLV
};


#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)
//#define MOUSE TG(_MOUSE)
#define FN MO(_FN)
#define SPACE_FN LT(_SPACE_FN, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ?  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter+Shift|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |  Fn  |Lower |Space+fn| Bksp |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL },
  {KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    N_QUES , N_SLSH },
  {TD(X_CTL),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_LSFT, KC_ENT)},
  {KC_LCTL,  KC_LALT, KC_LGUI, FN,      LOWER,   SPACE_FN,KC_BSPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},



/* Game
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ?  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |  Fn  |Lower |Space | Bksp |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = {
  {KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL },
  {KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    N_QUES , N_SLSH },
  {KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL,  KC_LALT, KC_LGUI, FN,      LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},



/* Neo
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   x  |   v  |   l  |   c  |   w  |   k  |   h  |   g  |   f  |   q  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   u  |   i  |   a  |   e  |   o  |   s  |   n  |   r  |   t  |   d  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   y  |   <  |   #  |   p  |   z  |   b  |   m  |   ,  |   .  |   j  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NEO] = {
  {KC_ESC,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    KC_BSPC},
  {KC_TAB,  KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    KC_SLSH},
  {KC_LSFT, N_Y,     N_LT,    N_HS,    KC_P,    N_Z,     KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,    KC_ENT },
  {KC_LCTL, KC_LALT, KC_LGUI, FN,      LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},



/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6   |   7 |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   *  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   /  |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |   ,  |   =  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, KC_0,    _______},
  {_______, KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_ASTR, KC_4,    KC_5,    KC_6, N_MINS,  _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, N_SLSH,  KC_1,    KC_2,    KC_3, N_PLUS,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_COMM, DE_EQL,  _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   "  |   §  |   $  |   %  |   &  |   ü  |   @  |   ö  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ä  |   ß  |   {  |   (  |   [  |   ]  |   )  |   }  |      |   ’  |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   °  |   ~  |      |   /  |   <  |   >  |   \  |      |   #  |   €  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
 {_______, DE_EXLM, DE_DQOT, DE_PARA, DE_DLR,  DE_PERC, DE_AMPR, N_UE,    DE_AT,   N_OE,    XXXXXXX, _______},
 {_______, N_AE,    N_SS,    N_LCUBR, N_LPARN, N_LSQBR, N_RSQBR, N_RPARN, N_RCUBR, XXXXXXX, DE_QUOT, N_PIPE },
 {_______, DE_RING, DE_TILD, XXXXXXX, DE_SLSH, DE_LESS, DE_MORE, N_BSLS,  XXXXXXX, DE_HASH, DE_EURO, _______},
 {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},


/* fn
 * ,-----------------------------------------------------------------------------------.
 * |DelWrd|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = {
    {LALT(KC_BSPC), KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL },
    {XXXXXXX,       KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {XXXXXXX,       XXXXXXX, XXXXXXX, _______, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},


/* Space fn
 * ,-----------------------------------------------------------------------------------.
 * |       | Pg Up| Bksp |  Up  |  Del | Pg Dn|      |      |      |      |      |      |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|
 * |       | Home | Left | Down | Right| End  |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|------+------+------+------+------+------|
 * |       |      |      |      |Return|      |      |      |      |      |      |      |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|
 * |       |      |      |      |      |             |      | Next |VOLDWN|VOL UP| Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SPACE_FN] = {
    {XXXXXXX,  KC_PGUP, KC_BSPC,  KC_UP,     KC_DEL,   KC_PGDN,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,    XXXXXXX},
    {XXXXXXX,  KC_HOME, KC_LEFT,  KC_DOWN,   KC_RGHT,  KC_END,   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,    XXXXXXX},
    {XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   KC_ENT,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,    XXXXXXX},
    {XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  _______,  XXXXXXX,  XXXXXXX, KC_MNXT,  KC__VOLDOWN, KC__VOLUP,  KC_MPLY}
},


/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  up  |      |      |      |      |  mwu |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | left | down | right|      |      |  mwl |  mwd |  mwr |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | mbtn3|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | mbtn1| mbtn2|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 /*
[_MOUSE] = {
  {_______, _______, _______, KC_MS_U, _______, _______, _______, _______, KC_WH_U, _______, _______, _______},
  {_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______},
  {_______, _______, _______, _______, _______, _______, KC_BTN3, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},
*/





/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/*[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},*/

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Qwerty|  Neo |Plover|      | Game |      |      |      |Aud on|Audoff|TGAutoshift|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |AGnorm|AGswap|      |      |Mus on|Musoff|MusMode|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |Voice+|Voice-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {RESET,   QWERTY,  XXXXXXX, NEO,     XXXXXXX, GAME,    GAME,    XXXXXXX, XXXXXXX, AU_ON,   AU_OFF,  KC_ASTG},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, MU_ON,   MU_OFF,  MU_MOD },
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MUV_DE,  MUV_IN,  XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
}


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}




/*
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _RAISE:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _LOWER:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}
*/




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

/*
    case LOWER:
      if (record->event.pressed) {
        layer_off(_RAISE);
      }
      return false;
      break;
      case RAISE:
        if (record->event.pressed) {
          layer_off(_LOWER);
        }
        return false;
        break;
*/


    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
/*    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;*/
      case NEO:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_NEO);
        }
        return false;
        break;

      case GAME:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_GAME);
        }
        return false;
        break;
    /*case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;*/
/*    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        //layer_off(_MOUSE);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;*/
/*    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;*/
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
