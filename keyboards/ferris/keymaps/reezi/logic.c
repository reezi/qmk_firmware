#define SS SEND_STRING
#define TAP record->event.pressed && record->tap.count
#define HOLD record->event.pressed

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
      case LT(0,C_FLASH):
        if (TAP) { SS("qmk flash" SS_TAP(X_ENTER)); return false; }
        else if (HOLD) { tap_code16(QK_BOOTLOADER); return false; }
        break;
      case LT(0,C_ANBR):
        if (TAP) { SS("<"); return false; }
        else if (HOLD) { SS("<>" SS_TAP(X_LEFT)); return false; }
        break;
      case LT(0,C_CYBR):
        if (TAP) { SS("{"); return false; }
        else if (HOLD) { SS("{}" SS_TAP(X_LEFT)); return false; }
        break;
      case LT(0,C_NMBR):
        if (TAP) { SS("["); return false; }
        else if (HOLD) { SS("[]" SS_TAP(X_LEFT)); return false; }
        break;
      case LT(0,C_PARE):
        if (TAP) { SS("("); return false; }
        else if (HOLD) { SS("()" SS_TAP(X_LEFT)); return false; }
        break;
      case LT(0,C_TILD): // dead
        if (TAP) { tap_code16(FR_TILD); return false; }
        else if (HOLD) { tap_code16(FR_TILD); tap_code16(FR_SLSH); return false; }
        break;
      case LT(0,C_SQUO):
        if (TAP) { SS("'"); return false; }
        else if (HOLD) { SS("''" SS_TAP(X_LEFT)); return false; }
        break;
      case LT(0,C_DQUO):
        if (TAP) { SS("\""); return false; }
        else if (HOLD) { SS("\"\"" SS_TAP(X_LEFT)); return false; }
        break;
      case LT(0,C_BQUO): // dead
        if (TAP) { tap_code16(FR_GRV); return false; }
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
          return false;
        }
        break;
      case C_CIRC: // dead
        if (TAP) { tap_code16(FR_CIRC); return false; }
        else if (HOLD) { tap_code16(FR_CIRC); tap_code16(KC_SPC); return false; }
        break;
      default:
        if ((KC_A <= keycode) && (keycode <= KC_Z)) { // alpha
          if (TAP) { tap_code16(keycode); return false; }
          else if (HOLD) { tap_code16(LSFT(keycode)); return false; }
        }
        break;
    }
    return true;
};
