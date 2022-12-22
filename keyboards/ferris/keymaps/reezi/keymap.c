// some headers are included here due to https://github.com/qmk/qmk_firmware/issues/10005
#include QMK_KEYBOARD_H
#include "sendstring_french.h"
#include "features/custom_shift_keys.h"

enum custom_keycodes {
    C_FLASH = SAFE_RANGE,
    C_U,
    C_ESC,
    C_TILD, C_CIRC,
    C_SQUO, C_DQUO, C_BQUO,
    C_ANBR, C_CYBR, C_NMBR, C_PARE,
};
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define _ABC 0
#define _EEE 1
#define _SYS 2
#define _SYM 3

#include "g/keymap_combo.h" 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_ABC] = LAYOUT_split_3x5_2(
      FR_B, FR_Y, FR_O, LT(0,C_U), FR_MINS, FR_UNDS, FR_L, FR_D, FR_W, FR_V,
      FR_C, FR_I, FR_E, FR_A,      FR_COMM, FR_DOT,  FR_H, FR_T, FR_S, FR_N,
      FR_G, FR_X, FR_J, FR_K,      FR_Z,    FR_Q,    FR_R, FR_M, FR_F, FR_P,
      MEH_T(KC_SPACE), _______, OS_LSFT, TO(_SYM)
  ),
	[_EEE] = LAYOUT_split_3x5_2(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, LT(0,C_FLASH),
      FR_CCED, FR_EACU, FR_EGRV, FR_AGRV, _______, _______, FR_DIAE, FR_CIRC, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      TO(_ABC), _______, _______, _______
  ),
	[_SYS] = LAYOUT_split_3x5_2(
      _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______,
      KC_BRID, KC_VOLD, KC_PGDN, KC_END,  _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
      _______, OS_LALT, KC_ESC,  KC_TAB,  _______, _______, KC_BSPC, KC_ENTER, _______, KC_DEL,
      TO(_ABC), OS_LCTL, OS_LSFT, TO(_SYM)
  ),
	[_SYM] = LAYOUT_split_3x5_2(
      _______, FR_PERC, FR_ASTR, FR_PLUS, FR_MINS, FR_UNDS, FR_AMPR, FR_DLR, FR_BSLS, C_BQUO,
      C_ANBR,  FR_QUES, FR_HASH, FR_EXLM, FR_COMM, FR_DOT,  FR_PIPE, FR_EQL, FR_SLSH, FR_AT,
      KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,  KC_P9,   KC_P0,
      TO(_ABC), _______, OS_LSFT, TO(_SYS)
  )
};

#include "shift.c"
#include "logic.c"
