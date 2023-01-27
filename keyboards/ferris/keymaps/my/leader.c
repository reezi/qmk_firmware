LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(FR_W) { SS(SS_C(SS_S(SS_A(SS_LGUI("w"))))); } // web
    SEQ_ONE_KEY(FR_C) { SS(SS_C(SS_S(SS_A(SS_LGUI("c"))))); } // chat
    SEQ_ONE_KEY(FR_E) { SS(SS_C(SS_S(SS_A(SS_LGUI("e"))))); } // editor
    SEQ_ONE_KEY(FR_T) { SS(SS_C(SS_S(SS_A(SS_LGUI("t"))))); } // terminal
    SEQ_ONE_KEY(FR_G) { SS(SS_C(SS_S(SS_A(SS_LGUI("g"))))); } // game

    SEQ_TWO_KEYS(FR_W, FR_W) {
      SS(SS_C(SS_S(SS_A(SS_LGUI("w")))));
      SS(SS_C("t"));
      SS(SS_A("d"));
    } // web search

    SEQ_THREE_KEYS(FR_W, FR_O, FR_W) { layer_move(_WST); } // wow layer

  }
}
