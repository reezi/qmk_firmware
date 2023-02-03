// https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
const custom_shift_key_t custom_shift_keys[] = {
  {FR_COMM, FR_SCLN}, // shift , is ;
  {FR_DOT, FR_COLN}, // shift . is :
  {LT(0,C_ANBR), FR_RABK}, // shift < is >
  {LT(0,C_CYBR), FR_RCBR}, // shift { is }
  {LT(0,C_NMBR), FR_RBRC}, // shift [ is ]
  {LT(0,C_PARE), FR_RPRN}, // shift ( is )
  {FR_DLR, FR_EURO}, // shift $ is €
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
