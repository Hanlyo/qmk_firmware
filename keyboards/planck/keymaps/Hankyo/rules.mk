# based on not quiet neo



TAP_DANCE_ENABLE    = no   # Enable TapDance functionality (+100)
BOOTMAGIC_ENABLE    = no    # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE     = no    # Mouse keys(+4700)
EXTRAKEY_ENABLE     = yes    # Audio control and System control(+450)
CONSOLE_ENABLE      = no    # Console for debug(+400)
COMMAND_ENABLE      = no    # Commands for debug and configuration
NKRO_ENABLE         = yes   # Nkey Rollover (+300) - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE    = no    # Enable keyboard backlight functionality
MIDI_ENABLE         = no    # MIDI controls
AUDIO_ENABLE        = yes    # Audio output on port C6 (+9400)
#VARIABLE_TRACE      = no    # Debug changes to variable values
UNICODE_ENABLE      = no    # Unicode (can't be used with unicodemap)
UNICODEMAP_ENABLE   = no   # Enable extended unicode
BLUETOOTH_ENABLE    = no    # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE     = no    # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE    = no    # Breathing sleep LED during USB suspend


MOUSEKEY_ENABLE = no	 # (+1700)

AUTO_SHIFT_ENABLE = yes
AUTO_SHIFT_MODIFIERS = yes
