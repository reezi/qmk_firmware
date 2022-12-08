#include QMK_KEYBOARD_H
#include "config.h"

// custom keycodes for qmk macro
enum custom_keycodes {
    C_PRN = SAFE_RANGE,
    C_CBR,
    C_BRC,
};

// custom X(keycodes) for qmk unicode map
enum unicode_names {
    TILDE,
    CEDIL,
    CIRCU,
    DIAER,
    ACUTE,
    GRAVE
};
const uint32_t PROGMEM unicode_map[] = {
    [GRAVE] = 0x0300,
    [ACUTE] = 0x0301,
    [CIRCU] = 0x0302,
    [TILDE] = 0x0303,
    [DIAER] = 0x0308,
    [CEDIL] = 0x0327
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(
      FR_A, FR_Z, FR_E, FR_R, FR_T, FR_Y, FR_U, FR_I, FR_O, FR_P,
      FR_Q , FR_S, FR_D, FR_F, FR_G, FR_H, FR_J, FR_K, FR_L, FR_M,
      FR_W, FR_X, TO(3), FR_C, OSL(1), KC_NO, FR_V, KC_TAB, FR_B, FR_N,
      MEH_T(KC_SPACE), MT(OSM(MOD_LALT), MOD_LCTL), OSM(MOD_LSFT), TO(2)
  ),
	[1] = LAYOUT_split_3x5_2(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      X(TILDE), X(CEDIL), X(CIRCU), X(DIAER), KC_NO, KC_NO, X(ACUTE), X(GRAVE), KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      TO(0), KC_NO, KC_NO, KC_NO
  ),
	[2] = LAYOUT_split_3x5_2(
      FR_AT, C_PRN, C_CBR, C_BRC, FR_EXLM, FR_PERC, FR_SLSH, FR_DLR, FR_CIRC, FR_EQL,
      FR_RABK, FR_TILD, FR_QUOT, FR_DQUO, FR_GRV, FR_HASH, FR_COLN, FR_MINS, FR_DOT, FR_ASTR,
      KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0,
      TO(0), FR_PIPE, KC_LSFT, TO(3)
  ),
	[3] = LAYOUT_split_3x5_2(
      KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, QK_REBOOT, QK_BOOTLOADER,
      KC_NO, KC_ESC, KC_HOME, KC_END, KC_NO, KC_NO, KC_BSPC, KC_ENTER, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_PGUP, KC_PGDN, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
      TO(0), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_NO
  )
};

const custom_shift_key_t custom_shift_keys[] = {
  {FR_EXLM, FR_QUES}, // shift ? is !
  {FR_SLSH, FR_BSLS}, // shift / is "\"
  {FR_DLR, FR_EURO}, // shift $ is €
  {FR_EQL, FR_AMPR}, // shift = is &
  {FR_LABK, FR_RABK}, // shift < is >
  {FR_COLN, FR_SCLN}, // shift : is ;
  {FR_MINS, FR_UNDS}, // shift - is _
  {FR_DOT, FR_COMM}, // shift . is ,
  {FR_ASTR, FR_PLUS}, // shift * is +
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
      // if is on key down
      // else is on key up
      case C_PRN:
        if (record->event.pressed) { SEND_STRING("()"SS_TAP(X_LEFT)); }
        else {}
        break;
      case C_CBR:
        if (record->event.pressed) { SEND_STRING("{}"SS_TAP(X_LEFT)); }
        else {}
        break;
      case C_BRC:
        if (record->event.pressed) { SEND_STRING("[]"SS_TAP(X_LEFT)); }
        else {}
        break;
    }
    return true;
};
