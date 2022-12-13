enum combo_events {
  TN_EEE,
  IA_ENTER, HS_BSPC, HTS_BSPCW,
  YU_Q, LW_Z,
  COMBO_LENGTH // auto count
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_eee[] = {FR_T, FR_N, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {FR_I, FR_A, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {FR_H, FR_S, COMBO_END};
const uint16_t PROGMEM combo_bspcw[] = {FR_H, FR_T, FR_S, COMBO_END};
const uint16_t PROGMEM combo_q[] = {FR_Y, FR_U, COMBO_END};
const uint16_t PROGMEM combo_z[] = {FR_L, FR_W, COMBO_END};

// COMBO_ACTION(x) is same as COMBO(x, KC_NO)
combo_t key_combos[] = {
  [TN_EEE] = COMBO_ACTION(combo_eee),
  [IA_ENTER] = COMBO_ACTION(combo_enter),
  [HS_BSPC] = COMBO_ACTION(combo_bspc),
  [HTS_BSPCW] = COMBO_ACTION(combo_bspcw),
  [YU_Q] = COMBO_ACTION(combo_q),
  [LW_Z] = COMBO_ACTION(combo_z),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case IA_ENTER:
      if (pressed) { tap_code16(KC_ENTER); } break;
    case TN_EEE:
      if (pressed) { tap_code16(OSL(_EEE)); } break;
    case HS_BSPC:
      if (pressed) { tap_code16(KC_BSPC); } break;
    case HTS_BSPCW:
      if (pressed) { tap_code16(LCTL(KC_BSPC)); } break;
    case YU_Q:
      if (pressed) { tap_code16(FR_Q); } break;
    case LW_Z:
      if (pressed) { tap_code16(FR_Z); } break;
  }
}
