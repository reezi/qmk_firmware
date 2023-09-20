#define TAP record->event.pressed && record->tap.count
#define HOLD record->event.pressed
#define RELEASE !record->event.pressed

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
      case C_FLASH:
        SS(SS_C("uk"));
        SS("qmk flash" SS_TAP(X_ENTER));
        reset_keyboard(); // QK_BOOTLOADER
      case LT(0,C_ZOOMD):
        if (TAP) {
          register_mods(MOD_BIT(KC_LCTL));
          tap_code16(KC_KP_MINUS);
          unregister_mods(MOD_BIT(KC_LCTL));
        }
        return false;
      case LT(0,C_ZOOMU):
        if (TAP) {
          register_mods(MOD_BIT(KC_LCTL));
          tap_code16(KC_KP_PLUS);
          unregister_mods(MOD_BIT(KC_LCTL));
        }
        return false;
      case LT(0,C_U):
        if (TAP) { SS("u"); }
        else if (HOLD) { SS("qu"); }
        return false;
      case LT(0,C_SPCL):
        if (TAP) { tap_code16(KC_SPC); }
        else if (HOLD) { register_mods(MOD_BIT(KC_LCTL)); }
        else if (RELEASE) { unregister_mods(MOD_BIT(KC_LCTL)); }
        return false;
      case LT(0,C_ESC):
        if (TAP) { SS(SS_TAP(X_ESC)); }
        else if (HOLD) { SS(SS_TAP(X_ESC) ":"); }
        return false;
      case LT(0,C_ANBR):
        if (TAP) { SS(">"); }
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
      case LT(0,C_PS0):
        if (TAP) { SS(SS_G( SS_DOWN(X_PSCR) "0" SS_UP(X_PSCR) )); }
        return false;
      case LT(0,C_PS1):
        if (TAP) { SS(SS_G( SS_DOWN(X_PSCR) "4" SS_UP(X_PSCR) )); }
        return false;
      // top row
      case LT(0,C_AB): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_B)) : tap_code16(A(FR_B)); } return false;
      case LT(0,C_AY): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_Y)) : tap_code16(A(FR_Y)); } return false;
      case LT(0,C_AO): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_O)) : tap_code16(A(FR_O)); } return false;
      case LT(0,C_AU): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_U)) : tap_code16(A(FR_U)); } return false;
      case LT(0,C_ACOMM): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_COMM)) : tap_code16(A(FR_COMM)); } return false;
      // middle row
      case LT(0,C_AMINS): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_MINS)) : tap_code16(A(FR_MINS)); } return false;
      // bottom row
      case LT(0,C_AG): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_G)) : tap_code16(A(FR_G)); } return false;
      case LT(0,C_AX): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_X)) : tap_code16(A(FR_X)); } return false;
      case LT(0,C_AK): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_K)) : tap_code16(A(FR_K)); } return false;
      case LT(0,C_AZ): if (TAP) { (get_mods() & MOD_BIT(KC_LCTL)) ? tap_code16(C(FR_Z)) : tap_code16(A(FR_Z)); } return false;
    }
    return true;
};
