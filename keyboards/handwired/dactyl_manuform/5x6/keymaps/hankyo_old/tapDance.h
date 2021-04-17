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
  CP = 0
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


void CopyPasteFunctionFinished (qk_tap_dance_state_t *state, void *user_data) {

    bool is_shift = false;
    uint8_t one_shot_mods = get_oneshot_mods();

    uint8_t saved_mods = 0;

    if (get_mods() & MOD_MASK_CTRL) {
        saved_mods = get_mods() & MOD_MASK_CTRL; // Mask off anything that isn't Shift
        del_mods(saved_mods); // Remove any Shifts present
        is_shift = true;
    } else if (one_shot_mods & MOD_MASK_CTRL) {
        saved_mods = 0; // Clear saved mods so the add_mods() below doesn't add Shifts back when it shouldn't
        set_oneshot_mods(one_shot_mods & ~MOD_MASK_CTRL);
        //is_shift = true;
    }

    switch (cur_dance(state)) {
        case DOUBLE_TAP:
            if (is_shift) {
                SEND_STRING(SS_LCTRL("x"));
            } else {
                SEND_STRING(SS_LCTRL("c"));
            }
        break;
        default:
            if (is_shift) {
                SEND_STRING(SS_LCTRL("x"));
            } else {
                SEND_STRING(SS_LCTRL("v"));
            }
        break;
    }

    add_mods(saved_mods);
}




qk_tap_dance_action_t tap_dance_actions[] = {
    [CP]       = ACTION_TAP_DANCE_FN_ADVANCED (NULL, CopyPasteFunctionFinished, NULL)
};
