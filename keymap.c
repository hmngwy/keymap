#include QMK_KEYBOARD_H
#include <stdio.h>

#define _v_  KC_TRNS
#define ___  KC_NO

#define HR_1 LGUI_T
#define HR_2 LALT_T
#define HR_3 LCTL_T
#define HR_4 LSFT_T

/* Thumb Row */
#define LT_OUT LT(_PAD, KC_ESC)
#define LT_HOM LT(_SYM, KC_TAB)
#define LT_INN KC_SPC

#define RT_INN LT(_FUN, KC_ENT)
#define RT_HOM LT(_NAV, KC_BSPC)
#define RT_OUT KC_CIRC

enum {
    TD_QUOT,
    TD_SLASH,
    TD_V,
    TD_K,
    APX_3,
    APX_R,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOT]   = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_SLASH]  = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BSLS),
    [TD_V]      = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_CAPS),
    [TD_K]      = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_CAPS),
    [APX_3]     = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_4),
    [APX_R]     = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_B),
};

/* Layers */
enum layers { _BASE = 0, _SYM, _NAV, _FUN, _PAD, _VAL, _TEST, _LOC };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_3x5(
    KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,          KC_J,     KC_L,       KC_U,       KC_Y,       TD(TD_QUOT),
    HR_1(KC_A), HR_2(KC_R), HR_3(KC_S), HR_4(KC_T), KC_G,          KC_M,     HR_4(KC_N), HR_3(KC_E), HR_2(KC_I), HR_1(KC_O),
    KC_Z,       KC_X,       KC_C,       KC_D,       TD(TD_V),      TD(TD_K), KC_H,       KC_COMM,    KC_DOT,     TD(TD_SLASH),
                            LT_OUT,     LT_HOM,     LT_INN,        RT_INN,   RT_HOM,     RT_OUT
  ),

  [_SYM] = LAYOUT_3x5(
    ___,     KC_CIRC, KC_GRV,  KC_TILD, KC_DLR,           ___,     KC_LT,   KC_GT,   KC_LBRC, KC_RBRC,
    KC_AT,   KC_HASH, KC_EXLM, KC_QUES, KC_AMPR,          KC_EQL,  KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
    ___,     ___,     ___,     KC_SCLN, KC_PIPE,          KC_UNDS, KC_COLN, KC_PMNS, KC_PPLS, ___,
                      _v_,     _v_,     _v_,              _v_,     _v_,     _v_
  ),

  // RT_HOM
  [_NAV] = LAYOUT_3x5(
    KC_PERC,       KC_7,       KC_8,       KC_9,       ___,      KC_PGUP,  KC_HOME,  KC_UP,    KC_END,  KC_PSCR,
    KC_LPRN,       KC_4,       KC_5,       KC_6,       KC_DOT,   KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_INS,
    KC_RPRN,       KC_1,       KC_2,       KC_3,       KC_COMM,  KC_PAST,  KC_SLASH, KC_PPLS,  KC_PMNS, ___,
                               DF(_NAV),   KC_0,       _v_,      _v_,      _v_,      DF(0)
  ),

  // RT_INN
  [_FUN] = LAYOUT_3x5(
    KC_BRIU, KC_BRID, KC_F11,   KC_F12,     ___,            KC_WH_U,   KC_MS_BTN1,  KC_MS_U, KC_MS_BTN2, ___,
    KC_F1,   KC_F2,   KC_F3,    KC_F4,      KC_F5,          KC_WH_D,   KC_MS_L,     KC_MS_D, KC_MS_R,    ___,
    KC_F6,   KC_F7,   KC_F8,    KC_F9,      KC_F10,         KC_VOLU,   KC_VOLD,     KC_MPLY, KC_MPRV,    KC_MNXT,
                      DF(_FUN), KC_MS_BTN2, KC_MS_BTN1,     _v_,       _v_,         DF(0)
  ),

  // LT_INN
  [_PAD] = LAYOUT_3x5(
    DF(_TEST), ___, ___, ___, RESET,    RGB_SAI, RGB_HUI, RGB_VAI, ___, ___,
    DF(_VAL),  ___, ___, ___, ___,      RGB_SAD, RGB_HUD, RGB_VAD, ___, KC_SYSTEM_WAKE,
    DF(_LOC),  ___, ___, ___, ___,      RGB_TOG, CK_TOGG, ___,     ___, KC_SYSTEM_SLEEP,
                    _v_, _v_, _v_,      _v_,     _v_,     _v_
  ),

  [_VAL] = LAYOUT_3x5(
    KC_1,    KC_Q, KC_W, KC_3,    KC_R,      KC_T,    KC_Y,      KC_F1,   KC_F2,   KC_ESC,
    KC_LSFT, KC_A, KC_S, KC_D,    KC_F,      KC_G,    KC_H,      KC_F3,   KC_F4,   KC_LGUI,
    KC_TAB,  KC_Z, KC_X, KC_C,    KC_V,      KC_B,    KC_N,      KC_F5,   KC_F6,   ___,
                   KC_4, KC_LALT, KC_SPC,    KC_ENT,  KC_SLASH,  DF(0)
  ),

  [_TEST] = LAYOUT_3x5(
    _v_, _v_, _v_, _v_, _v_,        _v_, _v_, _v_, _v_, _v_,
    KC_A, KC_R, KC_S, KC_T, KC_G,   KC_M, KC_N, KC_E, KC_I, KC_O,
    _v_, _v_, _v_, _v_, _v_,        _v_, _v_, _v_, _v_, _v_,
              _v_, _v_, _v_,        _v_, _v_, DF(0)
  ),

  [_LOC] = LAYOUT_3x5(
    ___, ___, ___, ___, ___,    ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___,    ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___,    ___, ___, ___, ___, ___,
              ___, ___, ___,    ___, ___, DF(0)
  )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_1(KC_A):
        case HR_1(KC_O):
        case HR_1(KC_AT):
        case HR_1(KC_RCBR):
        case HR_1(KC_PMNS):
        case HR_1(KC_F1):
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

#define L_BASE 0
#define L_SYM 2
#define L_NAV 4
#define L_FUN 8
#define L_PAD 16

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case L_NAV:
            oled_write_ln_P(PSTR("Num/Nav"), false);
            break;
        case L_FUN:
            oled_write_ln_P(PSTR("Func/Mouse"), false);
            break;
        case L_PAD:
            oled_write_ln_P(PSTR("Pad"), false);
            break;
	default:
            oled_write_ln_P(PSTR("?"), false);
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

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,  0,128,  0,128,128,128,128,128,128,192,192,192,192,192, 64,128,128,128,  0,  0,  0,  0,  0,  0,  0,128,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,128,  0,  0,  0,128,128,128,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 14,134, 99,125,126,159,130,129,193,193, 65, 65, 96, 96, 96, 32, 48, 56, 15,  4,  6,  3,129,128,224,224,120, 60, 31, 15,  7,254,255,  0,  0,  4,  4,  4,  4,  6,  6,  6,  6,  6,231,250, 56,255, 24,  3,  3,  3,  3,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,193,249,255,126, 10,  6,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 96,240,120, 28, 31, 15,  6,  0,  2,  3,  3,  3,  3,  3,  3,  3, 30,254,  0,  0,  0,  0,  0,  0,  0,  0,112,254,191,255, 15,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,

    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}


void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}

#endif // OLED_DRIVER_ENABLE
