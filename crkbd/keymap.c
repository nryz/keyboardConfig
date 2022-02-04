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

#define  OSCTRL_KEY   KC_J
#define  OSHIFT_KEY   KC_K
#define  OSSUPER_KEY  KC_L
#define  OSALT_KEY    KC_SEMICOLON

enum keycodes {
  OSSHIFT = SAFE_RANGE,
  OSCTRL,
  OSALT,
  OSSUPER,
  COSM,
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
      KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  /*|*/  KC_H,  OSCTRL,  OSSHIFT,  OSSUPER,  OSALT,
      KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  /*|*/  KC_N,  KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,
               XXXXXXX,  COSM,  NLANAV,  /*|*/  NLASYM,  NLSPC,  XXXXXXX                                             
  ),

  [SYM] = LAYOUT_split_3x5_3(
      NASTERISK,  KC_7,  KC_8,  KC_9,  NTILDE,   /*|*/  NQUOTE,  NDQUOTES,  NLBRACKET,  NRBRACKET,  NEQUAL,
      NPERCENT,   KC_4,  KC_5,  KC_6,  NPIPE,    /*|*/  NPLUS,   NCOLON,    NLPAREN,    NRPAREN,    NEXCLAMATION,
      KC_0,       KC_1,  KC_2,  KC_3,  NDOLLAR,  /*|*/  NMIN,    NDOLLAR,   NLCURLY,    NRCURLY,    NQUESTION,
                          XXXXXXX,  NLASYM2,  _______,  /*|*/  _______,  _______,  XXXXXXX
  ),

  [SYM2] = LAYOUT_split_3x5_3(
      XXXXXXX,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  /*|*/  NCARET,   NAND,         NHASH,     NGRAVE,    XXXXXXX,
      XXXXXXX,  KC_F4,  KC_F5,  KC_F6,  KC_F11,  /*|*/  NAT,      NUNDERSCORE,  NLANGLED,  NRANGLED,  NSEMICOLON,
      XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F12,  /*|*/  XXXXXXX,  NBACKSLASH,   NCOMMA,    NDOT,      NSLASH,
                            XXXXXXX,  NLASYM,  _______,  /*|*/  _______,  _______,  XXXXXXX
  ),

  [NAV] = LAYOUT_split_3x5_3(
      KC_NO,      KC_NO,         KC_NO,   KC_NO,     KC_NO,  /*|*/  KC_NO,    KC_PAGE_UP,    KC_HOME,  KC_END,    KC_NO,
      KC_DELETE,  KC_BACKSPACE,  KC_TAB,  KC_ENTER,  KC_NO,  /*|*/  KC_LEFT,  KC_DOWN,       KC_UP,    KC_RIGHT,  KC_NO,
      KC_NO,      KC_NO,         KC_NO,   KC_NO,     KC_NO,  /*|*/  KC_NO,    KC_PAGE_DOWN,  KC_NO,    KC_NO,     KC_NO,
                                  XXXXXXX,  NLAFUN,  _______,  /*|*/  _______,  _______,  XXXXXXX
  ),
  [FUN] = LAYOUT_split_3x5_3(
      KC_NO,  RGB_VAI,  RGB_SAI,  RGB_HUI,  RGB_TOG,  /*|*/  KC_NO,                KC_NO,              KC_NO,            KC_NO,                KC_NO,
      KC_NO,  RGB_VAD,  RGB_SAD,  RGB_HUD,  RGB_MOD,   /*|*/  KC_MEDIA_PREV_TRACK,  KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,  KC_MEDIA_NEXT_TRACK,  KC_NO,
      KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,     /*|*/  KC_MEDIA_PLAY_PAUSE,  KC_AUDIO_MUTE,      KC_NO,            KC_NO,                KC_NO,
                                  XXXXXXX,  _______,  _______,  /*|*/  _______,  _______,  XXXXXXX
  ),
};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode, cosm_state *cosm_state) {
  switch (keycode) {
    case NLASYM:
    case NLASYM2:
    case NLANAV:
    case NLAFUN:
    case COSM:
      return true;
    case OSSHIFT:
    case OSCTRL:
    case OSALT:
    case OSSUPER:
      return *cosm_state == cosm_down;
    default:
      return false;
  }
}

oneshot_state os_shift_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_super_state = os_up_unqueued;

cosm_state cosm_state_main = cosm_up;
uint16_t key_pressed_timer;

bool sym2_oneshot_active = false;
bool fun_oneshot_active = false;


void reset_oneshots(void) {
  os_shift_state = os_up_unqueued;
  unregister_code(KC_LSFT);
  os_ctrl_state = os_up_unqueued;
  unregister_code(KC_LCTL);
  os_alt_state = os_up_unqueued;
  unregister_code(KC_LALT);
  os_super_state = os_up_unqueued;
  unregister_code(KC_LCMD);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if( !update_cosm( &cosm_state_main, &key_pressed_timer, KC_LSFT, COSM, keycode, record)) {
    return false;
  }

  if( !update_oneshot( &os_shift_state, &cosm_state_main, KC_LSFT, OSSHIFT, OSHIFT_KEY, keycode, record)) {
    return false;
  }
  if( !update_oneshot( &os_ctrl_state, &cosm_state_main, KC_LCTL, OSCTRL, OSCTRL_KEY, keycode, record)) {
    return false;
  }
  if( !update_oneshot( &os_alt_state, &cosm_state_main, KC_LALT, OSALT, OSALT_KEY, keycode, record)) {
    return false;
  }
  if( !update_oneshot( &os_super_state, &cosm_state_main, KC_LCMD, OSSUPER, OSSUPER_KEY, keycode, record)) {
    return false;
  }

  if (get_oneshot_mods() & MOD_MASK_SHIFT) {
    if (record->event.pressed) {
      switch (keycode) {
        case NLSPC:
          register_code16(KC_ESCAPE);
          del_oneshot_mods(MOD_MASK_SHIFT);
          return false;
      }
    }
  }

  return true;
}
