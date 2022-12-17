#define SS SEND_STRING
#define TAP record->event.pressed && record->tap.count
#define HOLD record->event.pressed

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
      case LT(0,C_FLASH):
        if (TAP) { SS("qmk flash" SS_TAP(X_ENTER)); }
        else if (HOLD) { tap_code16(QK_BOOTLOADER); }
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
        if (TAP) { tap_code16(FR_TILD); }
        else if (HOLD) { tap_code16(FR_TILD); tap_code16(FR_SLSH); }
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
//      default:
//        if ((FR_A <= keycode) && (keycode <= FR_Z)) { // alpha
//          if (TAP) { tap_code16(keycode); }
//          else if (HOLD) { tap_code16(LSFT(keycode)); }
//        }
//        return false;
    }
    return true;
};
