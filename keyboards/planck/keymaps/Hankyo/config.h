#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#define ENCODER_RESOLUTION 4



// my custom configurations


// Autoshift stuff

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_SPECIAL


// Mouse stuff
/*
#define MOUSEKEY_DELAY             170
#define MOUSEKEY_INTERVAL          50
#define MOUSEKEY_MAX_SPEED         5
#define MOUSEKEY_TIME_TO_MAX       8
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
*/


// Taptoggle stuff

#define TAPPING_TOGGLE 2





#endif
