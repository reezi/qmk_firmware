void leader_end_user(void) {

    if (leader_sequence_one_key(FR_S)) { add_oneshot_mods(MOD_BIT(KC_LGUI)); } // sway mod key
    else if (leader_sequence_one_key(FR_M)) { SS(SS_CG("m")); } // menu
    else if (leader_sequence_one_key(FR_F)) { SS(SS_CG("f")); } // free
    else if (leader_sequence_one_key(FR_O)) { SS(SS_CG("o")); } // obsi
    else if (leader_sequence_one_key(FR_T)) { SS(SS_CG("t")); } // term
    else if (leader_sequence_one_key(FR_W)) { SS(SS_CG("w")); } // web
    else if (leader_sequence_one_key(FR_D)) { SS(SS_CG("d")); } // didi
    else if (leader_sequence_one_key(FR_G)) { SS(SS_CG("g")); } // game
    else if (leader_sequence_one_key(FR_B)) { SS(SS_CG("b")); } // stream

    else if (leader_sequence_two_keys(FR_T, FR_H)) { SS(SS_CA(SS_TAP(X_F1))); } // tty 1
    else if (leader_sequence_two_keys(FR_T, FR_S)) { SS(SS_CA(SS_TAP(X_F2))); } // tty 2
    else if (leader_sequence_two_keys(FR_N, FR_T)) { SS(SS_CG( SS_DOWN(X_T) SS_DOWN(X_N) SS_UP(X_N) SS_UP(X_T) )); } // new terminal
    else if (leader_sequence_two_keys(FR_O, FR_W)) { layer_move(_FPS); } // fps layer
    else if (leader_sequence_two_keys(FR_W, FR_O)) { layer_move(_WST); } // mmo layer
    else if (leader_sequence_two_keys(FR_P, FR_O)) { layer_move(_POE); } // poe layer
    else if (leader_sequence_two_keys(FR_F, FR_F)) { SS(SS_CGS("f")); } // move to free
    else if (leader_sequence_two_keys(FR_O, FR_O)) { SS(SS_CGS("o")); } // move to obsi
    else if (leader_sequence_two_keys(FR_T, FR_T)) { SS(SS_CGS("t")); } // move to term
    else if (leader_sequence_two_keys(FR_W, FR_W)) { SS(SS_CGS("w")); } // move to web
    else if (leader_sequence_two_keys(FR_D, FR_D)) { SS(SS_CGS("d")); } // move to didi
    else if (leader_sequence_two_keys(FR_G, FR_G)) { SS(SS_CGS("g")); } // move to game
    else if (leader_sequence_two_keys(FR_B, FR_B)) { SS(SS_CGS("b")); } // move to stream

    else if (leader_sequence_three_keys(FR_S, FR_S, FR_R)) { SS(SS_CG( SS_DOWN(X_S) SS_DOWN(X_R) SS_UP(X_R) SS_UP(X_S) )); } // sway reload
    else if (leader_sequence_three_keys(FR_S, FR_S, FR_K)) { SS(SS_CG( SS_DOWN(X_S) SS_DOWN(X_K) SS_UP(X_K) SS_UP(X_S) )); } // sway kill
    else if (leader_sequence_three_keys(FR_H, FR_U, FR_D)) { SS(SS_C(SS_RSFT(SS_TAP(X_F12)))); } // mangohud toggle

    else if (leader_sequence_four_keys(FR_T, FR_T, FR_Y, FR_B)) { SS(SS_CA(SS_TAP(X_F1))); } // tty 1
    else if (leader_sequence_four_keys(FR_T, FR_T, FR_Y, FR_Y)) { SS(SS_CA(SS_TAP(X_F2))); } // tty 2
    else if (leader_sequence_four_keys(FR_T, FR_T, FR_Y, FR_O)) { SS(SS_CA(SS_TAP(X_F3))); } // tty 3
    else if (leader_sequence_four_keys(FR_T, FR_T, FR_Y, FR_U)) { SS(SS_CA(SS_TAP(X_F4))); } // tty 4
    else if (leader_sequence_four_keys(FR_T, FR_T, FR_Y, FR_L)) { SS(SS_CA(SS_TAP(X_F5))); } // tty 5
    else if (leader_sequence_four_keys(FR_T, FR_T, FR_Y, FR_D)) { SS(SS_CA(SS_TAP(X_F6))); } // tty 6
    else if (leader_sequence_four_keys(FR_T, FR_T, FR_Y, FR_W)) { SS(SS_CA(SS_TAP(X_F7))); } // tty 7

}
