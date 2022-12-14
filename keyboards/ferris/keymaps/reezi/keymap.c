// some headers are included here due to https://github.com/qmk/qmk_firmware/issues/10005
#include QMK_KEYBOARD_H
#include "sendstring_french.h"
#include "features/custom_shift_keys.h" // https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
#include "g/keymap_combo.h" 

enum custom_keycodes {
    C_FLASH = SAFE_RANGE,
    C_TILD, C_CIRC,
    C_SQUO, C_DQUO, C_BQUO,
    C_ANBR, C_CYBR, C_NMBR, C_PARE,
};

#define _ABC 0
#define _EEE 1
#define _SYS 2
#define _SYM 3
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_ABC] = LAYOUT_split_3x5_2(
      FR_B, FR_Y, FR_O, FR_U, _______, _______, FR_L, FR_D, FR_W, FR_V,
      FR_C, FR_I, FR_E, FR_A, _______, _______, FR_H, FR_T, FR_S, FR_N,
      FR_G, FR_X, FR_J, FR_K, _______, _______, FR_R, FR_M, FR_F, FR_P,
      MEH_T(KC_SPACE), _______, _______, TO(_SYS)
  ),
	[_EEE] = LAYOUT_split_3x5_2(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      FR_CCED, FR_EGRV, FR_EACU, FR_AGRV, _______, _______, FR_DIAE, C_CIRC, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      TO(_ABC), _______, _______, _______
  ),
	[_SYS] = LAYOUT_split_3x5_2(
      _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, LT(0,C_FLASH),
      KC_BRID, KC_VOLD, KC_PGDN, KC_END, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
      _______, OSM(MOD_LALT), KC_ESC, KC_TAB, _______, _______, KC_BSPC, KC_ENTER, KC_DEL, _______,
      TO(_ABC), OSM(MOD_LCTL), OSM(MOD_LSFT), TO(_SYM)
  ),
	[_SYM] = LAYOUT_split_3x5_2(
      FR_AT, LT(0,C_PARE), LT(0,C_CYBR), LT(0,C_NMBR), FR_EXLM, FR_PERC, FR_SLSH, FR_DLR, FR_PIPE, FR_EQL,
      LT(0,C_ANBR), LT(0,C_TILD), LT(0,C_SQUO), LT(0,C_DQUO), LT(0,C_BQUO), FR_HASH, FR_COLN, FR_MINS, FR_DOT, FR_ASTR,
      KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0,
      TO(_ABC), _______, OSM(MOD_LSFT), TO(_SYS)
  )
};

#include "shift.c"
#include "logic.c"
