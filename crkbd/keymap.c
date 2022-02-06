#include QMK_KEYBOARD_H
#include <stdio.h>

#include "oneshot.h"

enum layers {
  BASE,
  SYM,
  SYM2,
  NAV,
  FUN
};

#define  NLASYM   OSL(SYM)
#define  NLASYM2  OSL(SYM2)
#define  NLANAV   OSL(NAV)
#define  NLAFUN   OSL(FUN)

#define NLSPC KC_SPC

#define  NSUPER  KC_LEFT_GUI
#define  NCTRL   KC_LEFT_CTRL
#define  NALT    KC_LEFT_ALT
#define  NSHIFT  KC_LEFT_SHIFT

enum keycodes {
  OSSHIFT = SAFE_RANGE,
  OSCTRL,
  OSALT,
  OSSUPER,
};

#define  NHASH         S(KC_3)
#define  NUNDERSCORE   S(KC_MINUS)
#define  NGRAVE        KC_GRAVE
#define  NAT           S(KC_2)

#define  NAND          S(KC_7)
#define  NCARET        S(KC_6)
#define  NBACKSLASH    KC_BACKSLASH
#define  NSEMICOLON    KC_SEMICOLON
#define  NLANGLED      S(KC_COMMA)
#define  NRANGLED      S(KC_DOT)
#define  NSLASH        KC_SLASH
#define  NCOMMA        KC_COMMA
#define  NDOT          KC_DOT

#define  NDQUOTES      S(KC_QUOTE)
#define  NLCURLY       S(KC_LEFT_BRACKET)
#define  NRCURLY       S(KC_RIGHT_BRACKET)
#define  NTILDE        S(KC_GRAVE)
#define  NQUESTION     S(KC_SLASH)
#define  NDOLLAR       S(KC_4)
#define  NPERCENT      S(KC_5)
#define  NASTERISK     S(KC_8)
#define  NLPAREN       S(KC_9)
#define  NRPAREN       S(KC_0)
#define  NCOLON        S(KC_SEMICOLON)
#define  NMIN          KC_MINUS
#define  NPLUS         S(KC_EQUAL)
#define  NPIPE         S(KC_BACKSLASH)
#define  NLBRACKET     KC_LEFT_BRACKET
#define  NRBRACKET     KC_RIGHT_BRACKET
#define  NQUOTE        KC_QUOTE
#define  NEQUAL        KC_EQUAL
#define  NEXCLAMATION  S(KC_1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_3(
      KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  /*|*/  KC_Y,  KC_U,    KC_I,     KC_O,     KC_P,
      KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  /*|*/  KC_H,  KC_J,  KC_K,  KC_L,  KC_SEMICOLON,
      KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  /*|*/  KC_N,  KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,
               XXXXXXX,  OSM(MOD_LSFT),  NLANAV,  /*|*/  NLASYM,  NLSPC,  XXXXXXX                                             
  ),

  [SYM] = LAYOUT_split_3x5_3(
      NASTERISK,  KC_7,  KC_8,  KC_9,  NTILDE,   /*|*/  NQUOTE,  NDQUOTES,  NLBRACKET,  NRBRACKET,  NEQUAL,
      NPERCENT,   KC_4,  KC_5,  KC_6,  NPIPE,    /*|*/  NPLUS,   NCOLON,    NLPAREN,    NRPAREN,    NEXCLAMATION,
      KC_0,       KC_1,  KC_2,  KC_3,  NDOLLAR,  /*|*/  NMIN,    NUNDERSCORE,   NLCURLY,    NRCURLY,    NQUESTION,
                          XXXXXXX,  _______,  NLASYM2,  /*|*/  _______,  _______,  XXXXXXX
  ),

  [SYM2] = LAYOUT_split_3x5_3(
      XXXXXXX,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  /*|*/  XXXXXXX,  NAND,        NHASH,     NGRAVE,    XXXXXXX,
      XXXXXXX,  KC_F4,  KC_F5,  KC_F6,  KC_F11,  /*|*/  NCARET,   NAT,         NLANGLED,  NRANGLED,  NSEMICOLON,
      XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F12,  /*|*/  XXXXXXX,  NBACKSLASH,  NCOMMA,    NDOT,      NSLASH,
                            XXXXXXX,  _______,  NLASYM,  /*|*/  _______,  _______,  XXXXXXX
  ),

  [NAV] = LAYOUT_split_3x5_3(
      KC_NO,      KC_NO,         KC_NO,   KC_NO,     KC_NO,  /*|*/  KC_TAB,    KC_DOWN,    KC_UP,  KC_BACKSPACE,    KC_DELETE,
      KC_NO,  KC_HOME,  KC_PAGE_UP,  KC_PAGE_DOWN,  KC_END,  /*|*/  KC_ESC,  OSCTRL,       OSSHIFT,    OSSUPER,  OSALT,
      KC_NO,      KC_NO,         KC_NO,   KC_NO,     KC_NO,  /*|*/  KC_ENTER,    KC_LEFT,  KC_RIGHT,    KC_NO,     KC_NO,
                                  XXXXXXX,  _______,  _______,  /*|*/  NLAFUN,  _______,  XXXXXXX
  ),
  [FUN] = LAYOUT_split_3x5_3(
      KC_NO,  RGB_VAI,  RGB_SAI,  RGB_HUI,  RGB_TOG,  /*|*/  KC_NO,                KC_NO,              KC_NO,            KC_NO,                KC_NO,
      KC_NO,  RGB_VAD,  RGB_SAD,  RGB_HUD,  RGB_MOD,   /*|*/  KC_MEDIA_PREV_TRACK,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  KC_MEDIA_NEXT_TRACK,  KC_NO,
      KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,     /*|*/  KC_MEDIA_PLAY_PAUSE,  KC_AUDIO_MUTE,      KC_NO,            KC_NO,                KC_NO,
                                  XXXXXXX,  _______,  _______,  /*|*/  NLANAV,  _______,  XXXXXXX
  ),
};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
    case NLASYM:
    case NLASYM2:
    case NLANAV:
    case NLAFUN:
    case OSSHIFT:
    case OSCTRL:
    case OSALT:
    case OSSUPER:
      return true;
    default:
      return false;
  }
}

oneshot_state os_shift_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_super_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  update_oneshot(
      &os_shift_state, KC_LSFT, OSSHIFT,
      keycode, record
  );
  update_oneshot(
      &os_ctrl_state, KC_LCTL, OSCTRL,
      keycode, record
  );
  update_oneshot(
      &os_alt_state, KC_LALT, OSALT,
      keycode, record
  );
  update_oneshot(
      &os_super_state, KC_LCMD, OSSUPER,
      keycode, record
  );

  return true;
}
