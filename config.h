#pragma once
#define FORCE_NKRO

// For hold-tap mods
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 150

// Extra settings
//#define RETRO_TAPPING

// Mouse
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_WHEEL_DELAY    0
#define MOUSEKEY_MAX_SPEED      6
#define MOUSEKEY_TIME_TO_MAX    32


// layouts supported
// https://beta.docs.qmk.fm/developing-qmk/qmk-reference/feature_layouts#tips-for-making-layouts-keyboard-agnostic
#ifdef KEYBOARD_planck
  #define LAYOUT_3x5( \
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
#endif

#ifdef KEYBOARD_crkbd
  // crkbd defaults
  #define MASTER_LEFT

  #define USE_SERIAL_PD2

  #ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
  #endif

  #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

  #define LAYOUT_3x5( \
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, \
    b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, \
    c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, \
    d1, d2, d3, d4, d5, d6 \
  ) \
    LAYOUT_split_3x5_3( \
      a1, a2, a3, a4, a5,     a6, a7, a8, a9, a10, \
      b1, b2, b3, b4, b5,     b6, b7, b8, b9, b10, \
      c1, c2, c3, c4, c5,     c6, c7, c8, c9, c10, \
	      d1, d2, d3,     d4, d5, d6 \
    )
#endif
