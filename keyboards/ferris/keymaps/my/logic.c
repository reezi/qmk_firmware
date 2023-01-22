#define SS SEND_STRING
#define SS_C SS_LCTL
#define SS_S SS_LSFT
#define SS_A SS_LALT



#define STD_LAYER layer_state_is(_ABC) || layer_state_is(_EEE) || layer_state_is(_SYM) || layer_state_is(_SYS)
#define WOW_LAYER layer_state_is(_WST) || layer_state_is(_WMT)

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {

  switch (combo_index) {

    case COMBO_STD_TAB:
    case COMBO_STD_ESC:
    case COMBO_STD_BSPC:
    case COMBO_STD_DEL:
    case COMBO_STD_ENTER:
      return true;

    case COMBO_STD_CYBR:
    case COMBO_STD_PARE:
    case COMBO_STD_NMBR:
    case COMBO_STD_EEE:
    case COMBO_STD_DQUO:
    case COMBO_STD_SQUO:
    case COMBO_STD_TILD:
      if (STD_LAYER) return true;

    case COMBO_WOW_GATE:
      if (WOW_LAYER) return true;
      break;

  }
  return false;
}



LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // wow layer
    SEQ_THREE_KEYS(FR_W, FR_O, FR_W) {
      layer_move(_WST);
    }

    // web
    SEQ_ONE_KEY(FR_W) {
      SS(SS_C(SS_S(SS_A(SS_LGUI("w")))));
    }

    // web search
    SEQ_TWO_KEYS(FR_W, FR_W) {
      SS(SS_C(SS_S(SS_A(SS_LGUI("w")))));
      SS(SS_C("t"));
      SS(SS_A("d"));
    }

  }
}



#define TAP record->event.pressed && record->tap.count
#define HOLD record->event.pressed

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
      case LT(0,C_FLASH):
        if (TAP) {
          SS(SS_C("uk"));
          SS("qmk flash" SS_TAP(X_ENTER));
          reset_keyboard(); // QK_BOOTLOADER
        }
        return false;
      case LT(0,C_U):
        if (TAP) { SS("u"); }
        else if (HOLD) { SS("qu"); }
        return false;
      case LT(0,C_ESC):
        if (TAP) { SS(SS_TAP(X_ESC)); }
        else if (HOLD) { SS(SS_TAP(X_ESC) ":"); }
        return false;
      case LT(0,C_ANBR):
        if (TAP) { SS("<"); }
        else if (HOLD) { SS("<>" SS_TAP(X_LEFT)); }
        return false;
      case LT(0,C_CYBR):
        if (TAP) { SS("{"); }
        else if (HOLD) { SS("{}" SS_TAP(X_LEFT)); }
        return false;
      case LT(0,C_NMBR):
        if (TAP) { SS("["); }
        else if (HOLD) { SS("[]" SS_TAP(X_LEFT)); }
        return false;
      case LT(0,C_PARE):
        if (TAP) { SS("("); }
        else if (HOLD) { SS("()" SS_TAP(X_LEFT)); }
        return false;
      case LT(0,C_TILD): // dead
        if (TAP) { tap_code16(FR_TILD); tap_code16(FR_SLSH); }
        else if (HOLD) { tap_code16(FR_TILD); }
        return false;
      case LT(0,C_SQUO):
        if (TAP) { SS("'"); }
        else if (HOLD) { SS("''" SS_TAP(X_LEFT)); }
        return false;
      case LT(0,C_DQUO):
        if (TAP) { SS("\""); }
        else if (HOLD) { SS("\"\"" SS_TAP(X_LEFT)); }
        return false;
      case LT(0,C_BQUO): // dead
        if (TAP) { tap_code16(FR_GRV); }
        else if (HOLD) {
          tap_code16(FR_GRV);
          tap_code16(FR_GRV);
          tap_code16(FR_GRV);
          tap_code16(KC_ENTER);
          tap_code16(FR_GRV);
          tap_code16(FR_GRV);
          tap_code16(FR_GRV);
          tap_code16(KC_UP);
          tap_code16(KC_END);
        }
        return false;
      case C_CIRC: // dead
        if (TAP) { tap_code16(FR_CIRC); }
        else if (HOLD) { tap_code16(FR_CIRC); tap_code16(KC_SPC); }
        return false;
    }
    return true;
};
