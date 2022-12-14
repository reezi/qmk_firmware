#define SS SEND_STRING
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
      // if is on key down -- else is on key up
      case C_FLASH:
        if (record->event.pressed && record->tap.count) { SS("qmk flash" SS_TAP(X_ENTER)); return false; } // tap
        if (record->event.pressed) { tap_code16(QK_BOOTLOADER); return false; } // hold
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
      case C_CIRC: // dead on tap -- alive on hold
        if (record->event.pressed && record->tap.count) { tap_code16(FR_CIRC); return false; } // tap
        else if (record->event.pressed) { tap_code16(FR_CIRC); tap_code16(KC_SPC); return false; } // hold
        break;
    }
    return true;
};
