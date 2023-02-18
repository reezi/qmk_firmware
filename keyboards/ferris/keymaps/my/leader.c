LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(FR_S) { add_oneshot_mods(MOD_BIT(KC_LGUI)); } // sway mod key
    SEQ_ONE_KEY(FR_F) { SS(SS_CG("f")); } // free
    SEQ_ONE_KEY(FR_T) { SS(SS_CG("t")); } // terminal
    SEQ_ONE_KEY(FR_E) { SS(SS_CG("e")); } // editor
    SEQ_ONE_KEY(FR_W) { SS(SS_CG("w")); } // web
    SEQ_ONE_KEY(FR_D) { SS(SS_CG("d")); } // voice (Discord)
    SEQ_ONE_KEY(FR_A) { SS(SS_CG("a")); } // game (Adventure)

    SEQ_TWO_KEYS(FR_T, FR_H) { SS(SS_CA(SS_TAP(X_F1))); } // tty 1
    SEQ_TWO_KEYS(FR_T, FR_S) { SS(SS_CA(SS_TAP(X_F2))); } // tty 2
    SEQ_TWO_KEYS(FR_T, FR_T) { SS(SS_CG( SS_DOWN(X_T) SS_DOWN(X_N) SS_UP(X_N) SS_UP(X_T) )); } // new terminal
    SEQ_TWO_KEYS(FR_W, FR_W) { SS(SS_CG( SS_DOWN(X_W) SS_DOWN(X_N) SS_UP(X_N) SS_UP(X_W) )); } // new web
    SEQ_TWO_KEYS(FR_D, FR_D) { SS(SS_CG( SS_DOWN(X_D) SS_DOWN(X_N) SS_UP(X_N) SS_UP(X_D) )); } // new voice

    SEQ_THREE_KEYS(FR_W, FR_O, FR_W) { layer_move(_WST); } // wow layer
    SEQ_THREE_KEYS(FR_S, FR_S, FR_R) { SS(SS_CG( SS_DOWN(X_S) SS_DOWN(X_R) SS_UP(X_R) SS_UP(X_S) )); } // sway reload
    SEQ_THREE_KEYS(FR_S, FR_S, FR_K) { SS(SS_CG( SS_DOWN(X_S) SS_DOWN(X_K) SS_UP(X_K) SS_UP(X_S) )); } // sway kill

    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_1) { SS(SS_CA(SS_TAP(X_F1))); } // tty 1
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_2) { SS(SS_CA(SS_TAP(X_F2))); } // tty 2
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_3) { SS(SS_CA(SS_TAP(X_F3))); } // tty 3
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_4) { SS(SS_CA(SS_TAP(X_F4))); } // tty 4
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_5) { SS(SS_CA(SS_TAP(X_F5))); } // tty 5
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_6) { SS(SS_CA(SS_TAP(X_F6))); } // tty 6
    SEQ_FOUR_KEYS(FR_T, FR_T, FR_Y, FR_7) { SS(SS_CA(SS_TAP(X_F7))); } // tty 7

  }
}
