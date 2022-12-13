// some headers are included here due to https://github.com/qmk/qmk_firmware/issues/10005
#include QMK_KEYBOARD_H
#include "sendstring_french.h" // qmk alternative keymaps
#include "features/custom_shift_keys.h" // https://getreuer.info/posts/keyboards/custom-shift-keys/index.html

// aliases
#define _ABC 0
#define _EEE 1
#define _SYS 2
#define _SYM 3
#define C_SWEET KC_F24
#define SS SEND_STRING

// C_ keycodes for qmk macro
enum custom_keycodes {
    C_FLASH = SAFE_RANGE,
    C_TILD, C_CIRC,
    C_SQUO, C_DQUO, C_BQUO,
    C_ANBR, C_CYBR, C_NMBR, C_PARE
};

#include "combo.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_ABC] = LAYOUT_split_3x5_2(
      FR_B, FR_Y, FR_O, FR_U, FR_Q, _______, FR_L, FR_D, FR_W, FR_V,
      FR_C, FR_I, FR_E, FR_A, FR_Z, _______, FR_H, FR_T, FR_S, FR_N,
      FR_G, FR_X, FR_J, FR_K, OSL(_EEE), _______, FR_R, FR_M, FR_F, FR_P,
      MEH_T(KC_SPACE), _______, OSM(MOD_LSFT), TO(_SYS)
  ),
	[_EEE] = LAYOUT_split_3x5_2(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, FR_AGRV, FR_EACU, FR_EGRV, _______, _______, FR_CIRC, FR_DIAE, FR_CCED, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      TO(_ABC), _______, _______, _______
  ),
	[_SYS] = LAYOUT_split_3x5_2(
      KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, _______, _______, KC_PGUP, KC_PGDN, C_FLASH, QK_BOOTLOADER,
      _______, KC_ESC, KC_HOME, KC_END, _______, KC_DEL, KC_BSPC, KC_ENTER, C_SWEET, _______,
      _______, OSM(MOD_LALT), KC_TAB, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
      TO(_ABC), OSM(MOD_LCTL), KC_LSFT, TO(_SYM)
  ),
	[_SYM] = LAYOUT_split_3x5_2(
      FR_AT, LT(0,C_PARE), LT(0,C_CYBR), LT(0,C_NMBR), FR_EXLM, FR_PERC, FR_SLSH, FR_DLR, C_CIRC, FR_EQL,
      LT(0,C_ANBR), LT(0,C_TILD), LT(0,C_SQUO), LT(0,C_DQUO), LT(0,C_BQUO), FR_HASH, FR_COLN, FR_MINS, FR_DOT, FR_ASTR,
      KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0,
      TO(_ABC), FR_PIPE, OSM(MOD_LSFT), TO(_SYS)
  )
};

const custom_shift_key_t custom_shift_keys[] = {
  {FR_EXLM, FR_QUES}, // shift ? is !
  {FR_SLSH, FR_BSLS}, // shift / is "\"
  {FR_DLR, FR_EURO}, // shift $ is €
  {FR_EQL, FR_AMPR}, // shift = is &
  {LT(0,C_ANBR), FR_RABK}, // shift < is >
  {FR_COLN, FR_SCLN}, // shift : is ;
  {FR_MINS, FR_UNDS}, // shift - is _
  {FR_DOT, FR_COMM}, // shift . is ,
  {FR_ASTR, FR_PLUS}, // shift * is +
  {LT(0,C_CYBR), FR_RCBR}, // shift { is }
  {LT(0,C_NMBR), FR_RBRC}, // shift [ is ]
  {LT(0,C_PARE), FR_RPRN} // shift ( is )
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
      // if is on key down -- else is on key up
      case C_FLASH:
        if (record->event.pressed) { SS("qmk flash" SS_TAP(X_ENTER)); return false; }
        break;
      case LT(0,C_ANBR):
        if (record->event.pressed && record->tap.count) { SS("<"); return false; } // tap
        else if (record->event.pressed) { SS("<>" SS_TAP(X_LEFT)); return false; } // hold
        break;
      case LT(0,C_CYBR):
        if (record->event.pressed && record->tap.count) { SS("{"); return false; } // tap
        else if (record->event.pressed) { SS("{}" SS_TAP(X_LEFT)); return false; } // hold
        break;
      case LT(0,C_NMBR):
        if (record->event.pressed && record->tap.count) { SS("["); return false; } // tap
        else if (record->event.pressed) { SS("[]" SS_TAP(X_LEFT)); return false; } // hold
        break;
      case LT(0,C_PARE):
        if (record->event.pressed && record->tap.count) { SS("("); return false; } // tap
        else if (record->event.pressed) { SS("()" SS_TAP(X_LEFT)); return false; } // hold
        break;
      case LT(0,C_TILD): // dead
        if (record->event.pressed && record->tap.count) { tap_code16(FR_TILD); return false; } // tap
        else if (record->event.pressed) { tap_code16(FR_TILD); tap_code16(FR_SLSH); return false; } // hold
        break;
      case LT(0,C_SQUO):
        if (record->event.pressed && record->tap.count) { SS("'"); return false; } // tap
        else if (record->event.pressed) { SS("''" SS_TAP(X_LEFT)); return false; } // hold
        break;
      case LT(0,C_DQUO):
        if (record->event.pressed && record->tap.count) { SS("\""); return false; } // tap
        else if (record->event.pressed) { SS("\"\"" SS_TAP(X_LEFT)); return false; } // hold
        break;
      case LT(0,C_BQUO): // dead
        if (record->event.pressed && record->tap.count) { tap_code16(FR_GRV); return false; } // tap
        else if (record->event.pressed) { // hold
          tap_code16(FR_GRV);
          tap_code16(FR_GRV);
          tap_code16(FR_GRV);
          tap_code16(KC_ENTER);
          tap_code16(FR_GRV);
          tap_code16(FR_GRV);
          tap_code16(FR_GRV);
          tap_code16(KC_UP);
          tap_code16(KC_END);
          return false;
        }
        break;
      case C_CIRC: // dead
        if (record->event.pressed) { tap_code16(FR_CIRC); tap_code16(KC_SPC); return false; }
        break;
    }
    return true;
};
