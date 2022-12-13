// COMBO_ACTION(x) is same as COMBO(x, KC_NO)

enum combo_events {
  IA_ENTER,
  SH_BSPC,
  COMBO_LENGTH // auto count
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_enter[] = {FR_I, FR_A, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {FR_S, FR_H, COMBO_END};

combo_t key_combos[] = {
  [IA_ENTER] = COMBO_ACTION(combo_enter),
  [SH_BSPC] = COMBO_ACTION(combo_bspc),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case IA_ENTER:
      if (pressed) { tap_code16(KC_ENTER); }
      break;
    case SH_BSPC:
      if (pressed) { tap_code16(KC_BSPC); }
      break;
  }
}
