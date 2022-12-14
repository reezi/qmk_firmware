const custom_shift_key_t custom_shift_keys[] = {
  {FR_EXLM, FR_QUES}, // shift ? is !
  {FR_SLSH, FR_BSLS}, // shift / is "\"
  {FR_DLR, FR_EURO}, // shift $ is €
  {FR_EQL, FR_AMPR}, // shift = is &
  {LT(0,C_ANBR), FR_RABK}, // shift < is >
  {FR_COLN, FR_SCLN}, // shift : is ;
  {FR_MINS, FR_UNDS}, // shift - is _
  {FR_DOT, FR_COMM}, // shift . is ,
  {FR_ASTR, FR_PLUS}, // shift * is +
  {LT(0,C_CYBR), FR_RCBR}, // shift { is }
  {LT(0,C_NMBR), FR_RBRC}, // shift [ is ]
  {LT(0,C_PARE), FR_RPRN} // shift ( is )
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
