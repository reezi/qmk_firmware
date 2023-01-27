// https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
const custom_shift_key_t custom_shift_keys[] = {
  {FR_COMM, FR_SCLN}, // shift , is ;
  {FR_DOT, FR_COLN}, // shift . is :
  {LT(0,C_ANBR), FR_RABK}, // shift < is >
  {LT(0,C_CYBR), FR_RCBR}, // shift { is }
  {LT(0,C_NMBR), FR_RBRC}, // shift [ is ]
  {LT(0,C_PARE), FR_RPRN}, // shift ( is )
  {FR_DLR, FR_EURO}, // shift $ is €
  {KC_BRID, KC_BRIU}, // shift bri-- is bri++
  {KC_VOLD, KC_VOLU}, // shift vol-- is vol++
  {C_ZOOMD, C_ZOOMU}, // shift zoom-- is zoom++
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
