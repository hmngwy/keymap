#include QMK_KEYBOARD_H

/* Layout */
#define LAYOUT_36( \
  a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, \
  b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, \
  c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, \
  d1, d2, d3, d4, d5, d6 \
) \
  LAYOUT_planck_grid( \
    a1,  a2,  a3, a4, a5,  ___, ___, a6,  a7, a8, a9,  a10, \
    b1,  b2,  b3, b4, b5,  ___, ___, b6,  b7, b8, b9,  b10, \
    c1,  c2,  c3, c4, c5,  ___, ___, c6,  c7, c8, c9,  c10, \
    ___, ___, d1, d2, d3,  ___, ___, d4,  d5, d6, ___, ___  \
  )

#define _v_  KC_TRNS
#define ___  KC_NO

// Left-hand home row mods
#define HR_A LGUI_T(KC_A)
#define HR_R LALT_T(KC_R)
#define HR_S LCTL_T(KC_S)
#define HR_T LSFT_T(KC_T)

// Right-hand home row mods
#define HR_N RSFT_T(KC_N)
#define HR_E RCTL_T(KC_E)
#define HR_I LALT_T(KC_I)
#define HR_O RGUI_T(KC_O)

/* Thumb Row */
#define LT_OUT KC_ESC
#define LT_HOM LT(_SYM, KC_SPC)
#define LT_INN LT(_PAD, KC_TAB)

#define RT_INN LT(_FUN, KC_ENT)
#define RT_HOM LT(_NAV, KC_BSPC)
#define RT_OUT KC_DEL

enum {
    TD_QUOT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
};


/* Layers */
enum layers { _BASE = 0, _SYM, _NAV, _FUN, _PAD, _GAM, _GMX, _LOC };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_36(
    KC_Q, KC_W, KC_F,    KC_P,    KC_B,    /**/  KC_J,   KC_L,   KC_U,    KC_Y,   TD(TD_QUOT),
    HR_A, HR_R, HR_S,    HR_T,    KC_G,    /**/  KC_M,   HR_N,   HR_E,    HR_I,   HR_O,
    KC_Z, KC_X, KC_C,    KC_D,    KC_V,    /**/  KC_K,   KC_H,   KC_COMM, KC_DOT, KC_SLASH,
    /**/  /**/  LT_OUT,  LT_HOM,  LT_INN,  /**/  RT_INN, RT_HOM, RT_OUT   /**/    /**/
  ),

  // LT_HOM
  [_SYM] = LAYOUT_36(
    KC_CIRC, KC_GRV,  KC_TILD, KC_DLR,  KC_PERC,  /**/  KC_LBRC,  KC_LT,    KC_EQL,  KC_GT,   KC_RBRC,
    KC_AT,   KC_HASH, KC_EXLM, KC_QUES, KC_AMPR,  /**/  KC_LCBR,  KC_LPRN,  KC_COLN, KC_RPRN, KC_RCBR,
    KC_CAPS, ___,     KC_BSLS, KC_SCLN, KC_PIPE,  /**/  KC_PSLS,  KC_PAST,  KC_PMNS, KC_PPLS, KC_UNDS,
    /**/     /**/     _v_,     _v_,     _v_,      /**/  _v_,      _v_,      _v_      /**/     /**/
  ),

  // RT_HOM
  [_NAV] = LAYOUT_36(
    KC_PERC, KC_7,    KC_8,     KC_9,     KC_0,     /**/ KC_PGUP,  KC_HOME,  KC_UP,    KC_END,  KC_PSCR,
    KC_PMNS, KC_4,    KC_5,     KC_6,     KC_DOT,   /**/ KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_INS,
    KC_PPLS, KC_1,    KC_2,     KC_3,     KC_COMM,  /**/ KC_CUT,   KC_COPY,  KC_PASTE, KC_FIND, KC_UNDO,
    /**/     /**/     DF(_NAV), _v_,      _v_,      /**/ _v_,      _v_,      DF(0)    /**/     /**/
  ),

  // RT_INN
  [_FUN] = LAYOUT_36(
    KC_BRIU, KC_BRID, ___,        KC_F11,     KC_F12,     /**/ KC_WH_U,  KC_MS_BTN1, KC_MS_U, KC_MS_BTN2, RESET,
    KC_F1,   KC_F2,   KC_F3,      KC_F4,      KC_F5,      /**/ KC_WH_D,  KC_MS_L,    KC_MS_D, KC_MS_R,    ___,
    KC_F6,   KC_F7,   KC_F8,      KC_F9,      KC_F10,     /**/ KC_VOLD,  KC_VOLU,    KC_MPLY, KC_MPRV,    KC_MNXT,
    /**/    /**/      DF(_FUN),   KC_MS_BTN1, KC_MS_BTN2, /**/ _v_,      _v_,   DF(0)      /**/     /**/
  ),

  // LT_INN
  [_PAD] = LAYOUT_36(
    ___,      ___,     ___, ___,     ___,     /**/ RGB_SAI, RGB_HUI, RGB_VAI, ___, ___,
    DF(_GAM), ___,     ___, ___,     ___,     /**/ RGB_SAD, RGB_HUD, RGB_VAD, ___, KC_SYSTEM_WAKE,
    DF(_LOC), ___,     ___, ___,     ___,     /**/ RGB_TOG, CK_TOGG, ___,     ___, KC_SYSTEM_SLEEP,
    /**/      /**/     _v_, _v_,     _v_,     /**/ _v_, _v_, _v_  /**/ /**/
  ),

  [_GAM] = LAYOUT_36(
    KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,   /**/ KC_T,    KC_Y,      KC_F1,   KC_F2,   KC_ESC,
    KC_CAPS, KC_A, KC_S, KC_D,    KC_F,   /**/ KC_G,    KC_H,      KC_F3,   KC_F4,   KC_LGUI,
    KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,   /**/ KC_B,    KC_N,      KC_F5,   KC_F6,   ___,
    /**/     /**/  KC_4, KC_LALT, KC_SPC, /**/ KC_ENT,  OSL(_GMX), DF(0)    /**/     /**/
  ),

  [_GMX] = LAYOUT_36(
    _v_, _v_,  _v_,  _v_,  _v_,  /**/ _v_, _v_,  _v_,  _v_,  _v_,
    _v_, _v_,  _v_,  _v_,  _v_,  /**/ _v_, _v_,  _v_,  _v_,  _v_,
    _v_, _v_,  _v_,  _v_,  _v_,  /**/ _v_, _v_,  _v_,  _v_,  _v_,
    /**/ /**/  _v_,  _v_,  _v_,  /**/ _v_,  _v_,  _v_      /**/    /**/
  ),

  [_LOC] = LAYOUT_planck_grid(
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,   ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,   ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,   ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, DF(0), ___, ___
  )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_A:
            return TAPPING_TERM + 100;
        case HR_O:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_HOM:
        case RT_HOM:
            return false;
        default:
            return true;
    }
}
