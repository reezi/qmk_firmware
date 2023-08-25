// some headers are included here due to https://github.com/qmk/qmk_firmware/issues/10005
#include QMK_KEYBOARD_H
#include "sendstring_french.h"
#include "features/custom_shift_keys.h"

enum custom_keycodes {
    C_FLASH = SAFE_RANGE,
    C_U,
    C_SPCL, C_ESC,
    C_TILD, C_CIRC,
    C_SQUO, C_DQUO, C_BQUO,
    C_ANBR, C_CYBR, C_NMBR, C_PARE,
    C_ZOOMD, C_ZOOMU,
    C_AB, C_AY, C_AO, C_AU, C_ACOMM, C_AMINS, C_AG, C_AX, C_AK, C_AZ,
};
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LCTL OSM(MOD_LCTL)
#define _ABC 0
#define _EEE 1
#define _SYM 2
#define _SYS 3
#define _FPS 9
#define _WST 10
#define _WMT 11
#define _POE 12

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_ABC] = LAYOUT_split_3x5_2(
      FR_B, FR_Y, FR_O, LT(0,C_U), FR_COMM, FR_DOT,  FR_L, FR_D, FR_W, FR_V,
      FR_C, FR_I, FR_E, FR_A,      FR_MINS, FR_COLN, FR_H, FR_T, FR_S, FR_N,
      FR_G, FR_X, FR_J, FR_K,      FR_Z,    FR_Q,    FR_R, FR_M, FR_F, FR_P,
      LT(0,C_SPCL), QK_LEAD, OS_LSFT, TO(_SYM)
  ),
	[_EEE] = LAYOUT_split_3x5_2(
      _______, _______, _______, FR_UGRV, _______, _______, _______, _______, _______, C_FLASH,
      FR_CCED, FR_EACU, FR_EGRV, FR_AGRV, _______, _______, FR_DIAE, FR_CIRC, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      TO(_ABC), _______, _______, _______
  ),
	[_SYM] = LAYOUT_split_3x5_2(
      _______, FR_PERC,      FR_ASTR, FR_PLUS, FR_COMM, FR_DOT,  FR_AMPR, FR_DLR, FR_BSLS, LT(0,C_BQUO),
      FR_QUES, LT(0,C_ANBR), FR_HASH, FR_EXLM, FR_MINS, FR_COLN, FR_PIPE, FR_EQL, FR_SLSH, FR_AT,
      FR_1,    FR_2,         FR_3,    FR_4,    FR_5,    FR_6,    FR_7,    FR_8,   FR_9,    FR_0,
      TO(_ABC), _______, OS_LSFT, TO(_SYS)
  ),
	[_SYS] = LAYOUT_split_3x5_2(
      KC_PSCR, KC_BRIU, KC_VOLU, LT(0,C_ZOOMU), _______, _______, _______, _______, _______, KC_NUM_LOCK,
      _______, KC_BRID, KC_VOLD, LT(0,C_ZOOMD), _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
      _______, _______, _______, _______,       _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
      TO(_ABC), OS_LALT, OS_LSFT, _______
  ),
	[_FPS] = LAYOUT_split_3x5_2(
      FR_B, FR_Y, FR_O, FR_U, FR_COMM, FR_DOT,  FR_L, FR_D, FR_W, FR_V,
      FR_C, FR_I, FR_E, FR_A, FR_MINS, FR_COLN, FR_H, FR_T, FR_S, FR_N,
      FR_G, FR_X, FR_J, FR_K, FR_Z,    FR_Q,    FR_R, FR_M, FR_F, FR_P,
      KC_SPC, KC_LALT, KC_LCTL, TO(_SYS)
  ),
	[_WST] = LAYOUT_split_3x5_2(
      FR_B,     FR_Y, FR_O, FR_U, FR_COMM, FR_DOT,  FR_L, FR_D, FR_W, FR_V,
      TO(_WMT), FR_I, FR_E, FR_A, FR_MINS, FR_COLN, FR_H, FR_T, FR_S, FR_N,
      FR_G,     FR_X, FR_J, FR_K, FR_Z,    FR_Q,    FR_R, FR_M, FR_F, FR_P,
      KC_SPC, KC_LSFT, _______, TO(_SYS)
  ),
	[_WMT] = LAYOUT_split_3x5_2(
      LT(0,C_AB), LT(0,C_AY), LT(0,C_AO), LT(0,C_AU), LT(0,C_ACOMM), FR_DOT,  FR_L, FR_D, FR_W, FR_V,
      TO(_WST),   FR_I,       FR_E,       FR_A,       LT(0,C_AMINS), FR_COLN, FR_H, FR_T, FR_S, FR_N,
      LT(0,C_AG), LT(0,C_AX), FR_J,       LT(0,C_AK), LT(0,C_AZ),    FR_Q,    FR_R, FR_M, FR_F, FR_P,
      KC_SPC, KC_LCTL, _______, TO(_SYS)
  ),
	[_POE] = LAYOUT_split_3x5_2(
      FR_B, FR_Y, FR_O, FR_U, FR_COMM, FR_DOT,  FR_L, FR_D, FR_W, FR_V,
      FR_C, FR_I, FR_E, FR_A, FR_MINS, FR_COLN, FR_H, FR_T, FR_S, FR_N,
      FR_G, FR_X, FR_J, FR_K, KC_LALT, FR_Q,    FR_R, FR_M, FR_F, FR_P,
      KC_SPC, KC_LCTL, KC_LSFT, TO(_SYS)
  ),
};


// sendstring helpers
#define SS SEND_STRING
#define SS_C SS_LCTL
#define SS_S SS_LSFT
#define SS_A SS_LALT
#define SS_G SS_LGUI
#define SS_CA(string) SS_C(SS_A(string))
#define SS_CG(string) SS_C(SS_G(string))
#define SS_MEH(string) SS_C(SS_S(SS_A(string)))
#define SS_HYPER(string) SS_C(SS_S(SS_A(SS_G(string))))

#include "tap.c"
#include "combo.c"
#include "leader.c"

#include "shift.c"
