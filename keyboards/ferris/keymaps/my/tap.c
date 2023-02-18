#define TAP record->event.pressed && record->tap.count
#define HOLD record->event.pressed
#define RELEASE !record->event.pressed

bool osm_flag_spcl = true; // flag enabling osm

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
      case C_FLASH:
        SS(SS_C("uk"));
        SS("qmk flash" SS_TAP(X_ENTER));
        reset_keyboard(); // QK_BOOTLOADER
      case LT(0,C_ZOOMD):
        if (TAP) { SS(SS_C("-")); }
        else if (HOLD) { SS(SS_C("-")); }
        return false;
      case LT(0,C_ZOOMU):
        if (TAP) { SS(SS_C("+")); }
        else if (HOLD) { SS(SS_C("+")); }
        return false;
      case LT(0,C_U):
        if (TAP) { SS("u"); }
        else if (HOLD) { SS("qu"); }
        return false;
      case LT(0,C_SPCL):
        if (TAP) { tap_code16(KC_SPC); }
        else if (HOLD) {
          register_mods(MOD_BIT(KC_LCTL)); // normal control
          osm_flag_spcl = true;
        }
        else if (RELEASE) {
          unregister_mods(MOD_BIT(KC_LCTL)); // normal control
          if (osm_flag_spcl) { add_oneshot_mods(MOD_BIT(KC_LCTL)); } // one-shot control if was pressed alone
        }
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
        if (TAP) { tap_code16(FR_TILD); SS("/"); }
        else if (HOLD) { tap_code16(FR_TILD); SS("/.config/"); }
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

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(0,C_SPCL):
        break;
      default:
        osm_flag_spcl = false;
        break;
    }
}
