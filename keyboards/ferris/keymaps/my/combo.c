#define STD_LAYER layer_state_is(_ABC) || layer_state_is(_EEE) || layer_state_is(_SYM) || layer_state_is(_SYS)
#define WOW_LAYER layer_state_is(_WST) || layer_state_is(_WMT)

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {

  switch (combo_index) {

    case COMBO_STD_ESC:
    case COMBO_STD_BSPC:
    case COMBO_STD_DEL:
    case COMBO_STD_ENTER:
      return true;

    case COMBO_STD_TAB:
    case COMBO_STD_CYBR:
    case COMBO_STD_PARE:
    case COMBO_STD_NMBR:
    case COMBO_STD_EEE:
    case COMBO_STD_DQUO:
    case COMBO_STD_SQUO:
    case COMBO_STD_TILD:
      if (STD_LAYER) return true;

    case COMBO_WOW_JUMP:
    case COMBO_WOW_GATE:
      if (WOW_LAYER) return true;

  }
  return false;
}
