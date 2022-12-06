#include QMK_KEYBOARD_H
//#include "keymap_french.h"
#include "custom-shift-keys.h"

enum custom_keycodes {
    C_PRN = SAFE_RANGE,
    C_CBR,
    C_BRC,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case C_PRN:
        if (record->event.pressed) { SEND_STRING("()"SS_TAP(X_LEFT)); } // when pressed
        else {} // when released
        break;
      case C_CBR:
        if (record->event.pressed) { SEND_STRING("{}"SS_TAP(X_LEFT)); } // when pressed
        else {} // when released
        break;
      case C_BRC:
        if (record->event.pressed) { SEND_STRING("[]"SS_TAP(X_LEFT)); } // when pressed
        else {} // when released
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(
      KC_A, KC_Z, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
      KC_Q , KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_M,
      KC_W, KC_X, TG(3), KC_C, OSL(1), KC_NO, KC_V, KC_TAB, KC_B, KC_N,
      MEH_T(KC_SPACE), MT(OSM(MOD_LALT), MOD_LCTL), OSM(MOD_LSFT), TG(2)
  ),
	[1] = LAYOUT_split_3x5_2(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      UC(0xCC83), UC(0xCCA7), UC(0xCC82), UC(0xCC88), KC_NO, KC_NO, UC(0xCC81), UC(0xCC80), KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      TG(0), KC_NO, KC_NO, KC_NO
  ),
	[2] = LAYOUT_split_3x5_2(
      KC_AT, C_PRN, C_CBR, C_BRC, KC_QUESTION, KC_PERCENT, KC_SLASH, KC_DOLLAR, KC_CIRC, KC_EQUAL,
      KC_GT, KC_TILDE, KC_QUOTE, KC_DQUO, KC_GRAVE, KC_HASH, KC_COLON, KC_MINUS, KC_DOT, KC_ASTR,
      KC_P0, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9,
      TG(0), KC_PIPE, KC_LSFT, TG(3)
  ),
	[3] = LAYOUT_split_3x5_2(
      KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_DOLLAR, KC_PERCENT, QK_REBOOT, QK_BOOTLOADER,
      KC_NO, KC_ESC, KC_HOME, KC_END, KC_NO, KC_NO, KC_BSPC, KC_ENTER, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
      TG(0), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_NO
  )
};

const custom_shift_key_t custom_shift_keys[] = {
  {KC_QUESTION, KC_EXCLAIM}, // shift ? is !
  {KC_SLASH, KC_BACKSLASH}, // shift / is "\"
  {KC_DOLLAR, RALT(KC_E)}, // shift $ is €
  {KC_EQUAL, KC_AMPERSAND}, // shift = is &
  {KC_RIGHT_ANGLE_BRACKET, KC_LEFT_ANGLE_BRACKET}, // shift < is >
  {KC_COLON, KC_SEMICOLON}, // shift : is ;
  {KC_MINUS, KC_UNDERSCORE}, // shift - is _
  {KC_DOT, KC_COMMA}, // shift . is ,
  {KC_ASTERISK, KC_PLUS}, // shift * is +
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
