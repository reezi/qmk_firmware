LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(FR_W) { SS(SS_HYPER("w")); } // web
    SEQ_ONE_KEY(FR_C) { SS(SS_HYPER("c")); } // chat
    SEQ_ONE_KEY(FR_E) { SS(SS_HYPER("e")); } // editor
    SEQ_ONE_KEY(FR_T) { SS(SS_HYPER("t")); } // terminal
    SEQ_ONE_KEY(FR_G) { SS(SS_HYPER("g")); } // game

    SEQ_TWO_KEYS(FR_W, FR_W) {
      SS(SS_HYPER("w"));
      SS(SS_C("t"));
      SS(SS_A("d"));
    } // web search

    SEQ_THREE_KEYS(FR_W, FR_O, FR_W) { layer_move(_WST); } // wow layer

    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_1) { SS(SS_CA(SS_TAP(X_F1))); } // tty 1
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_2) { SS(SS_CA(SS_TAP(X_F2))); } // tty 2
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_3) { SS(SS_CA(SS_TAP(X_F3))); } // tty 3
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_4) { SS(SS_CA(SS_TAP(X_F4))); } // tty 4
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_5) { SS(SS_CA(SS_TAP(X_F5))); } // tty 5
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_6) { SS(SS_CA(SS_TAP(X_F6))); } // tty 6
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_7) { SS(SS_CA(SS_TAP(X_F7))); } // tty 7

  }
}
