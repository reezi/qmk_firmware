enum combo_events {
  // left hand
  COMBO_Q,
  COMBO_TAB,
  COMBO_ESC,
  // right hand
  COMBO_Z,
  COMBO_EEE,
  COMBO_BSPC,
  COMBO_BSPCW,
  COMBO_ENTER,
  // auto count
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// left hand
const uint16_t PROGMEM combo_q[] = {FR_Y, FR_U, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {FR_I, FR_A, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {FR_X, FR_K, COMBO_END};
// right hand
const uint16_t PROGMEM combo_z[] = {FR_L, FR_W, COMBO_END};
const uint16_t PROGMEM combo_eee[] = {FR_T, FR_N, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {FR_H, FR_S, COMBO_END};
const uint16_t PROGMEM combo_bspcw[] = {FR_H, FR_T, FR_S, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {FR_M, FR_P, COMBO_END};

// COMBO_ACTION(x) is same as COMBO(x, KC_NO)
combo_t key_combos[] = {
  // left hand
  [COMBO_Q] = COMBO_ACTION(combo_q),
  [COMBO_TAB] = COMBO_ACTION(combo_tab),
  [COMBO_ESC] = COMBO_ACTION(combo_esc),
  // right hand
  [COMBO_Z] = COMBO_ACTION(combo_z),
  [COMBO_EEE] = COMBO_ACTION(combo_eee),
  [COMBO_BSPC] = COMBO_ACTION(combo_bspc),
  [COMBO_BSPCW] = COMBO_ACTION(combo_bspcw),
  [COMBO_ENTER] = COMBO_ACTION(combo_enter),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    // left hand
    case COMBO_Q:
      if (pressed) { tap_code16(FR_Q); } break;
    case COMBO_TAB:
      if (pressed) { tap_code16(KC_TAB); } break;
    case COMBO_ESC:
      if (pressed) { tap_code16(KC_ESC); } break;
    // right hand
    case COMBO_Z:
      if (pressed) { tap_code16(FR_Z); } break;
    case COMBO_EEE:
      if (pressed) { tap_code16(OSL(_EEE)); } break;
    case COMBO_BSPC:
      if (pressed) { tap_code16(KC_BSPC); } break;
    case COMBO_BSPCW:
      if (pressed) { tap_code16(LCTL(KC_BSPC)); } break;
    case COMBO_ENTER:
      if (pressed) { tap_code16(KC_ENTER); } break;
  }
}
