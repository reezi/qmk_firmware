LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // wow layer
    SEQ_THREE_KEYS(FR_W, FR_O, FR_W) {
      layer_move(_WST);
    }

    // web
    SEQ_ONE_KEY(FR_W) {
      SS(SS_C(SS_S(SS_A(SS_LGUI("w")))));
    }

    // web search
    SEQ_TWO_KEYS(FR_W, FR_W) {
      SS(SS_C(SS_S(SS_A(SS_LGUI("w")))));
      SS(SS_C("t"));
      SS(SS_A("d"));
    }

  }
}
