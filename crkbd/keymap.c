#include QMK_KEYBOARD_H
#include <stdio.h>

#define _v_  KC_TRNS
#define ___  KC_NO

#define LAYOUT_crkbd_3x5( \
  a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, \
  b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, \
  c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, \
  d1, d2, d3, d4, d5, d6 \
) \
  LAYOUT_split_3x6_3( \
    ___, a1, a2, a3, a4, a5,     a6, a7, a8, a9, a10, ___, \
    ___, b1, b2, b3, b4, b5,     b6, b7, b8, b9, b10, ___, \
    ___, c1, c2, c3, c4, c5,     c6, c7, c8, c9, c10, ___, \
                 d1, d2, d3,     d4, d5, d6 \
  )

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
enum layers { _BASE = 0, _SYM, _NAV, _FUN, _PAD, _GAM, _LOC };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_crkbd_3x5(
    KC_Q, KC_W, KC_F,    KC_P,    KC_B,    /**/  KC_J,   KC_L,   KC_U,    KC_Y,   TD(TD_QUOT),
    HR_A, HR_R, HR_S,    HR_T,    KC_G,    /**/  KC_M,   HR_N,   HR_E,    HR_I,   HR_O,
    KC_Z, KC_X, KC_C,    KC_D,    KC_V,    /**/  KC_K,   KC_H,   KC_COMM, KC_DOT, KC_SLASH,
    /**/  /**/  LT_OUT,  LT_HOM,  LT_INN,  /**/  RT_INN, RT_HOM, RT_OUT   /**/    /**/
  ),

  // LT_HOM
  [_SYM] = LAYOUT_crkbd_3x5(
    KC_CIRC, KC_GRV,  KC_TILD, KC_DLR,  KC_PERC,  /**/  KC_LBRC,  KC_LT,    KC_EQL,  KC_GT,   KC_RBRC,
    KC_AT,   KC_HASH, KC_EXLM, KC_QUES, KC_AMPR,  /**/  KC_LCBR,  KC_LPRN,  KC_COLN, KC_RPRN, KC_RCBR,
    KC_CAPS, ___,     KC_BSLS, KC_SCLN, KC_PIPE,  /**/  KC_PSLS,  KC_PAST,  KC_PMNS, KC_PPLS, KC_UNDS,
    /**/     /**/     _v_,     _v_,     _v_,      /**/  _v_,      _v_,      _v_      /**/     /**/
  ),

  // RT_HOM
  [_NAV] = LAYOUT_crkbd_3x5(
    KC_PERC, KC_7,    KC_8,     KC_9,     KC_0,     /**/ KC_PGUP,  KC_HOME,  KC_UP,    KC_END,  KC_PSCR,
    KC_PMNS, KC_4,    KC_5,     KC_6,     KC_DOT,   /**/ KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_INS,
    KC_PPLS, KC_1,    KC_2,     KC_3,     KC_COMM,  /**/ KC_CUT,   KC_COPY,  KC_PASTE, KC_FIND, KC_UNDO,
    /**/     /**/     DF(_NAV), _v_,      _v_,      /**/ _v_,      _v_,      DF(0)    /**/     /**/
  ),

  // RT_INN
  [_FUN] = LAYOUT_crkbd_3x5(
    KC_BRIU, KC_BRID, ___,        KC_F11,     KC_F12,     /**/ KC_WH_U,  KC_MS_BTN1, KC_MS_U, KC_MS_BTN2, RESET,
    KC_F1,   KC_F2,   KC_F3,      KC_F4,      KC_F5,      /**/ KC_WH_D,  KC_MS_L,    KC_MS_D, KC_MS_R,    ___,
    KC_F6,   KC_F7,   KC_F8,      KC_F9,      KC_F10,     /**/ KC_VOLD,  KC_VOLU,    KC_MPLY, KC_MPRV,    KC_MNXT,
    /**/    /**/      DF(_FUN),   KC_MS_BTN1, KC_MS_BTN2, /**/ _v_,      _v_,   DF(0)      /**/     /**/
  ),

  // LT_INN
  [_PAD] = LAYOUT_crkbd_3x5(
    ___,      ___,     ___, ___,     ___,     /**/ RGB_SAI, RGB_HUI, RGB_VAI, ___, ___,
    DF(_GAM), ___,     ___, ___,     ___,     /**/ RGB_SAD, RGB_HUD, RGB_VAD, ___, KC_SYSTEM_WAKE,
    DF(_LOC), ___,     ___, ___,     ___,     /**/ RGB_TOG, CK_TOGG, ___,     ___, KC_SYSTEM_SLEEP,
    /**/      /**/     _v_, _v_,     _v_,     /**/ _v_, _v_, _v_  /**/ /**/
  ),

  [_VAL] = LAYOUT_crkbd_3x5(
    KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,   /**/ KC_T,    KC_Y,      KC_F1,   KC_F2,   KC_ESC,
    KC_CAPS, KC_A, KC_S, KC_D,    KC_F,   /**/ KC_G,    KC_H,      KC_F3,   KC_F4,   KC_LGUI,
    KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,   /**/ KC_B,    KC_N,      KC_F5,   KC_F6,   ___,
    /**/     /**/  KC_4, KC_LALT, KC_SPC, /**/ KC_ENT,  KC_SLASH,  DF(0)    /**/     /**/
  ),

  [_LOC] = LAYOUT_split_3x6_3(
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, DF(0)
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


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {

    oled_write_P(PSTR("Layer: "), false);

    switch (layer_state) {

        case L_BASE:

            oled_write_ln_P(PSTR("Default"), false);

            break;

        case L_LOWER:

            oled_write_ln_P(PSTR("Lower"), false);

            break;

        case L_RAISE:

            oled_write_ln_P(PSTR("Raise"), false);

            break;

        case L_ADJUST:

        case L_ADJUST|L_LOWER:

        case L_ADJUST|L_RAISE:

        case L_ADJUST|L_LOWER|L_RAISE:

            oled_write_ln_P(PSTR("Adjust"), false);

            break;

    }

}





char keylog_str[24] = {};



const char code_to_name[60] = {

    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',

    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',

    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',

    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',

    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',

    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};



void set_keylog(uint16_t keycode, keyrecord_t *record) {

  char name = ' ';

    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||

        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }

  if (keycode < 60) {

    name = code_to_name[keycode];

  }



  // update keylog

  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",

           record->event.key.row, record->event.key.col,

           keycode, name);

}



void oled_render_keylog(void) {

    oled_write(keylog_str, false);

}



void render_bootmagic_status(bool status) {

    /* Show Ctrl-Gui Swap options */

    static const char PROGMEM logo[][2][3] = {

        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},

        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},

    };

    if (status) {

        oled_write_ln_P(logo[0][0], false);

        oled_write_ln_P(logo[0][1], false);

    } else {

        oled_write_ln_P(logo[1][0], false);

        oled_write_ln_P(logo[1][1], false);

    }

}



void oled_render_logo(void) {

    static const char PROGMEM crkbd_logo[] = {

        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,

        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,

        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,

        0};

    oled_write_P(crkbd_logo, false);

}



void oled_task_user(void) {

    if (is_keyboard_master()) {

        oled_render_layer_state();

        oled_render_keylog();

    } else {

        oled_render_logo();

    }

}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (record->event.pressed) {

    set_keylog(keycode, record);

  }

  return true;

}

#endif // OLED_DRIVER_ENABLE
