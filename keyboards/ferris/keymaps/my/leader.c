LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(FR_S) { add_oneshot_mods(MOD_BIT(KC_LGUI)); } // sway mod key
    SEQ_ONE_KEY(FR_M) { SS(SS_CG("m")); } // menu
    SEQ_ONE_KEY(FR_F) { SS(SS_CG("f")); } // free
    SEQ_ONE_KEY(FR_O) { SS(SS_CG("o")); } // obsi
    SEQ_ONE_KEY(FR_T) { SS(SS_CG("t")); } // term
    SEQ_ONE_KEY(FR_W) { SS(SS_CG("w")); } // web
    SEQ_ONE_KEY(FR_D) { SS(SS_CG("d")); } // didi
    SEQ_ONE_KEY(FR_G) { SS(SS_CG("g")); } // game

    SEQ_TWO_KEYS(FR_T, FR_H) { SS(SS_CA(SS_TAP(X_F1))); } // tty 1
    SEQ_TWO_KEYS(FR_T, FR_S) { SS(SS_CA(SS_TAP(X_F2))); } // tty 2
    SEQ_TWO_KEYS(FR_T, FR_T) { SS(SS_CG( SS_DOWN(X_T) SS_DOWN(X_N) SS_UP(X_N) SS_UP(X_T) )); } // new terminal
    SEQ_TWO_KEYS(FR_O, FR_W) { layer_move(_FPS); } // overwatch is fps layer

    SEQ_THREE_KEYS(FR_W, FR_O, FR_W) { layer_move(_WST); } // wow layer
    SEQ_THREE_KEYS(FR_S, FR_S, FR_R) { SS(SS_CG( SS_DOWN(X_S) SS_DOWN(X_R) SS_UP(X_R) SS_UP(X_S) )); } // sway reload
    SEQ_THREE_KEYS(FR_S, FR_S, FR_K) { SS(SS_CG( SS_DOWN(X_S) SS_DOWN(X_K) SS_UP(X_K) SS_UP(X_S) )); } // sway kill
    SEQ_THREE_KEYS(FR_H, FR_U, FR_D) { SS(SS_C(SS_RSFT(SS_TAP(X_F12)))); } // mango toggle

    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_B) { SS(SS_CA(SS_TAP(X_F1))); } // tty 1
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_Y) { SS(SS_CA(SS_TAP(X_F2))); } // tty 2
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_O) { SS(SS_CA(SS_TAP(X_F3))); } // tty 3
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_U) { SS(SS_CA(SS_TAP(X_F4))); } // tty 4
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_L) { SS(SS_CA(SS_TAP(X_F5))); } // tty 5
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_D) { SS(SS_CA(SS_TAP(X_F6))); } // tty 6
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_W) { SS(SS_CA(SS_TAP(X_F7))); } // tty 7

  }
}
