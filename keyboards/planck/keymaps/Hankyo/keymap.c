
#include "planck.h"
#include "action_layer.h"


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
#define N_HASH KC_BSLASH // #
#define N_DLR LSFT(KC_4) // $
#define N_PIPE RALT(KC_NONUS_BSLASH) // |
#define N_TILD RALT(KC_RBRC) // ~
#define N_GRAVE LSFT(KC_EQUAL) // `
#define N_PLUS KC_RBRC // +
#define N_PERC LSFT(KC_5) // %
#define N_QUOT LSFT(KC_2) // "
#define N_SING LSFT(KC_BSLASH) // '
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
  _NEO,
  _LOWER,
  _RAISE,
  _MOUSE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  NEO,
  RAISE,
  LOWER,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)
#define MOUSE TG(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ?  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Mouse |Lower |Space | Bksp |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL },
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    N_QUES , N_SLSH },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LALT, KC_LGUI, MOUSE,   LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},



/* Neo
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   x  |   v  |   l  |   c  |   w  |   k  |   h  |   g  |   f  |   q  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   u  |   i  |   a  |   e  |   o  |   s  |   n  |   r  |   t  |   d  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   y  |   <  |   #  |   p  |   z  |   b  |   m  |   ,  |   .  |   j  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NEO] = {
  {KC_TAB,  KC_X,    KC_V,    KC_L,    KC_C,    KC_W,    KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,    KC_BSPC},
  {KC_ESC,  KC_U,    KC_I,    KC_A,    KC_E,    KC_O,    KC_S,    KC_N,    KC_R,    KC_T,    KC_D,    KC_SLSH},
  {KC_LSFT, N_Y,     N_LT,    N_HS,    KC_P,    N_Z,     KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_J,    KC_ENT },
  {KC_LCTL, KC_LALT, KC_LGUI, MOUSE,   LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},





/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      | Pg up| Bksp |  Up  | Del  | Pg dn|      |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Home | Left | Down | Right|  End |      |   4  |   5  |   6  |   +  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |  Tab |      | Enter|      |      |   1  |  2   |   3  |   -  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   0  |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL, KC_PGDN, _______, KC_7,       KC_8,       KC_9,    N_ASTR,  _______},
  {_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, KC_4,       KC_5,       KC_6,    N_PLUS,  N_SLSH },
  {_______, _______, KC_TAB,  _______, KC_ENT,  _______, _______, KC_1,       KC_2,       KC_3,    N_MINS,  N_EQ   },
  {_______, _______, _______, _______, _______, _______, KC_0,    _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   ö  |   |  |   (  |   )  |      |      |   F9 |  F10 |  F11 |  F12 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ä  |      |   {  |   }  |   [  |   ]  |   F5 |  F6  |  F7  |  F8  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   ü  |  ss  |   <  |   >  |   /  |   \  |   F1 |  F2  |  F3  |  F4  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, N_OE,    N_PIPE,  N_LPARN, N_RPARN, _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______},
  {_______, N_AE,    _______, N_LCUBR, N_RCUBR, N_LSQBR, N_RSQBR, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______},
  {_______, N_UE,    N_SS,    KC_LT,   KC_GT,   N_SLSH,  N_BSLS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
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
[_MOUSE] = {
  {_______, _______, _______, KC_MS_U, _______, _______, _______, _______, KC_WH_U, _______, _______, _______},
  {_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______},
  {_______, _______, _______, _______, _______, _______, KC_BTN3, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},





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

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |  Neo |Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP,  QWERTY,   NEO  , _______,  PLOVER, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  KC_ASDN, KC_ASUP, KC_ASTG, KC_ASRP, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
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
    case BACKLIT:
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
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_MOUSE);
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
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
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
