#include "layer.h"
#include "keymap_german.h"


enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};


//Tap dance enums
enum {
  ARROW = 0,
  SYMBOL,
  FUNCTION,
  LBRC,
  RBRC,
  ESC
};



int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}



void changeSymbolLayerFin (qk_tap_dance_state_t *state, void *user_data) {

  switch (cur_dance(state)) {
    case SINGLE_TAP:
        set_oneshot_layer(_SYMBOL, ONESHOT_START);
    break;
    case SINGLE_HOLD:
        layer_on(_SYMBOL);
    break;
    case DOUBLE_TAP:
        layer_invert(_SYMBOL);
    break;
  }
}

void changeSymbolLayerRes (qk_tap_dance_state_t *state, void *user_data) {

  switch (cur_dance(state)) {
    case SINGLE_TAP:
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    break;
    case SINGLE_HOLD:
        layer_off(_SYMBOL);
    break;
    case DOUBLE_TAP:
    break;
  }
}

void changeFunctionLayerFin (qk_tap_dance_state_t *state, void *user_data) {

  switch (cur_dance(state)) {
    case SINGLE_TAP:
        set_oneshot_layer(_SYMBOL, ONESHOT_START);
    break;
    case SINGLE_HOLD:
        layer_on(_FUNCTION);
    break;
    case DOUBLE_TAP:
        layer_invert(_FUNCTION);
    break;
  }
}

void changeFunctionLayerRes (qk_tap_dance_state_t *state, void *user_data) {

  switch (cur_dance(state)) {
    case SINGLE_TAP:
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    break;
    case SINGLE_HOLD:
        layer_off(_FUNCTION);
    break;
    case DOUBLE_TAP:
    break;
  }
}


void LBRCFunction (qk_tap_dance_state_t *state, void *user_data) {

  switch (cur_dance(state)) {
    case SINGLE_TAP:
        register_code(KC_D);
    break;
    case DOUBLE_TAP:
        register_code16(DE_LCBR);
    break;
  }
}

void RBRCFunction (qk_tap_dance_state_t *state, void *user_data) {

  switch (cur_dance(state)) {
    case SINGLE_TAP:
        register_code(KC_F);
    break;
    case DOUBLE_TAP:
        register_code16(DE_RCBR);
    break;
  }
}


void ESCFunction (qk_tap_dance_state_t *state, void *user_data) {

  switch (cur_dance(state)) {
    case SINGLE_TAP:
        register_code(KC_ESC);
    break;
    case DOUBLE_TAP:
        layer_clear();
    break;
  }
}



qk_tap_dance_action_t tap_dance_actions[] = {
  [SYMBOL]     = ACTION_TAP_DANCE_FN_ADVANCED     (NULL, changeSymbolLayerFin, changeSymbolLayerRes),
  [FUNCTION]     = ACTION_TAP_DANCE_FN_ADVANCED     (NULL, changeFunctionLayerFin, changeFunctionLayerRes),
  [LBRC]     = ACTION_TAP_DANCE_FN     (LBRCFunction),
  [RBRC]     = ACTION_TAP_DANCE_FN     (RBRCFunction),
  [ESC]     = ACTION_TAP_DANCE_FN     (ESCFunction)
  //,
  //[TD_COPY_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_copy_paste_finished, NULL)
};
