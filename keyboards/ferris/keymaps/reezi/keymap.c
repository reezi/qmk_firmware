// includes are done here due to https://github.com/qmk/qmk_firmware/issues/10005
#include QMK_KEYBOARD_H
#include "sendstring_french.h" // https://docs.qmk.fm/#/feature_macros?id=alternative-keymaps
#include "features/custom_shift_keys.h" // https://getreuer.info/posts/keyboards/custom-shift-keys/index.html

# define C_SWEET KC_F24

// custom C_ keycodes for qmk macro
enum custom_keycodes {
    C_FLASH = SAFE_RANGE,
    C_CYBR,
    C_NMBR,
    C_PARE,
    C_TILD,
    C_BQUO,
    C_CIRC
};

// custom X(keycodes) for qmk unicode map
//enum unicode_names {
//    TILDE,
//    CEDIL,
//    CIRCU,
//    DIAER,
//    ACUTE,
//    GRAVE
//};
//const uint32_t PROGMEM unicode_map[] = {
//    [GRAVE] = 0x0300,
//    [ACUTE] = 0x0301,
//    [CIRCU] = 0x0302,
//    [TILDE] = 0x0303,
//    [DIAER] = 0x0308,
//    [CEDIL] = 0x0327
//};

#define _ABC 0
#define _EEE 1
#define _SYM 2
#define _SYS 3
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_ABC] = LAYOUT_split_3x5_2(
      FR_A, FR_Z, FR_E, FR_R, FR_T, FR_Y, FR_U, FR_I, FR_O, FR_P,
      FR_Q , FR_S, FR_D, FR_F, FR_G, FR_H, FR_J, FR_K, FR_L, FR_M,
      FR_W, FR_X, _______, FR_C, _______, _______, FR_V, _______, FR_B, FR_N,
      MEH_T(KC_SPACE), OSL(_EEE), OSM(MOD_LSFT), TO(_SYS)
  ),
	[_EEE] = LAYOUT_split_3x5_2(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, FR_AGRV, FR_EACU, FR_EGRV, _______, _______, FR_CIRC, FR_DIAE, FR_CCED, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      TO(_ABC), _______, _______, _______
  )
,
	[_SYS] = LAYOUT_split_3x5_2(
      KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, _______, _______, KC_PGUP, KC_PGDN, C_FLASH, QK_BOOTLOADER,
      _______, KC_ESC, KC_HOME, KC_END, _______, KC_DEL, KC_BSPC, KC_ENTER, C_SWEET, _______,
      _______, OSM(MOD_LALT), KC_TAB, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
      TO(_ABC), OSM(MOD_LCTL), KC_LSFT, TO(_SYM)
  ),
	[_SYM] = LAYOUT_split_3x5_2(
      FR_AT, C_PARE, C_CYBR, C_NMBR, FR_EXLM, FR_PERC, FR_SLSH, FR_DLR, C_CIRC, FR_EQL,
      FR_RABK, C_TILD, FR_QUOT, FR_DQUO, C_BQUO, FR_HASH, FR_COLN, FR_MINS, FR_DOT, FR_ASTR,
      KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0,
      TO(_ABC), FR_PIPE, OSM(MOD_LSFt), TO(_SYS)
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
      // if is on key down -- else is on key up
      case C_FLASH:
        if (record->event.pressed) { SEND_STRING("qmk flash" SS_TAP(X_ENTER)); }
        break;
      case C_CYBR:
        if (record->event.pressed) { SEND_STRING("{}" SS_TAP(X_LEFT)); }
        break;
      case C_NMBR:
        if (record->event.pressed) { SEND_STRING("[]" SS_TAP(X_LEFT)); }
        break;
      case C_PARE:
        if (record->event.pressed) { SEND_STRING("()" SS_TAP(X_LEFT)); }
        break;
      case C_TILD:
        if (record->event.pressed) { SEND_STRING("~"); }
        break;
      case C_BQUO:
        if (record->event.pressed) { SEND_STRING("`"); }
        break;
      case C_CIRC:
        if (record->event.pressed) { SEND_STRING("^"); }
        break;
    }
    return true;
};
