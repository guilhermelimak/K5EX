#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
// #include "keymap_german.h"
// #include "keymap_nordic.h"
// #include "keymap_french.h"
// #include "keymap_spanish.h"
// #include "keymap_hungarian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

enum custom_keycodes
{
  PLACEHOLDER = SAFE_RANGE, // can always be here
  M_ARROW_FUN,
  M_SELECTCOPY,
  EPRM,
  RGB_SLD,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ergodox(
        // Left hand
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LBRACKET,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LCBR,
        LT(3, KC_ESCAPE), KC_A, KC_S, KC_D, KC_F, KC_G,
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LPRN,
        OSM(MOD_LCTL), TT(1), TT(2), KC_LALT, KC_RGUI,
        KC_LEFT, KC_RIGHT, KC_UP, LT(2, KC_SPACE), LCTL_T(KC_BSPACE), KC_DOWN,

        // Right hand
        KC_RBRACKET, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,
        KC_RCBR, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
        KC_H, KC_J, KC_K, KC_L, LT(3, KC_SCOLON), LT(4, KC_QUOTE),
        KC_RPRN, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, M_ARROW_FUN,
        KC_RGUI, KC_RALT, TT(3), TT(4), KC_PIPE,
        KC_PGDOWN, KC_PGUP, KC_HOME, KC_END, RSFT_T(KC_DELETE), LT(2, KC_ENTER)),

    [1] = LAYOUT_ergodox(
        // Left hand
        LT(2, KC_GRAVE), KC_1, KC_2, KC_3, KC_4, KC_5, KC_LBRACKET,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LCBR,
        KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LPRN,
        KC_LCTRL, TO(0), KC_TRNS, KC_LALT, KC_LGUI,
        KC_LEFT, KC_RIGHT, KC_UP, KC_SPACE, KC_BSPACE, KC_DOWN,

        // Right hand
        KC_RBRACKET, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,
        KC_RCBR, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
        KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
        KC_RPRN, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
        KC_RGUI, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
        KC_PGDOWN, KC_PGUP, KC_HOME, KC_END, KC_DELETE, KC_ENTER),

    [2] = LAYOUT_ergodox(
        // Left hand
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
        KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, LCTL(LSFT(KC_TAB)),
        KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRAVE,
        KC_TRNS, KC_PERC, KC_CIRC, KC_LBRACKET, KC_RBRACKET, KC_TILD, LCTL(KC_TAB),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_C), KC_TRNS,

        // Right hand
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_TRNS, KC_ASTR, KC_F12,
        KC_KP_4, KC_KP_5, KC_KP_6, KC_TRNS, KC_AMPR, KC_0,
        KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_TRNS, KC_BSLASH, KC_TRNS,
        KC_0, KC_DOT, KC_0, KC_EQUAL, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_V), KC_TRNS),

    [3] = LAYOUT_ergodox(
        // Left hand
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
        KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_AUDIO_VOL_UP, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        DYN_REC_START1, KC_TRNS, KC_TRNS, DYN_MACRO_PLAY1, DYN_REC_STOP, KC_TRNS,

        // Right hand
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, DYN_REC_START2, KC_TRNS, KC_TRNS, DYN_REC_STOP, DYN_MACRO_PLAY2),

    [4] = LAYOUT_ergodox(
        // Left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MS_ACCEL0, KC_TRNS, KC_TRNS, KC_MS_UP, KC_TRNS, KC_TRNS, KC_MS_WH_UP,
        KC_MS_ACCEL1, KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS,
        KC_MS_ACCEL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_WH_DOWN,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN2, KC_MS_BTN1,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN1, KC_MS_BTN3, KC_TRNS,

        // Right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_BTN3, KC_MS_BTN2),

};

bool suspended = false;

const uint16_t PROGMEM fn_actions[] = {[1] = ACTION_LAYER_TAP_TOGGLE(1)};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (!process_record_dynamic_macro(keycode, record))
  {
    return false;
  }

  switch (keycode)
  {
  case EPRM:
    if (record->event.pressed)
    {
      eeconfig_init();
    }
    return false;
    break;

  case M_ARROW_FUN:
    if (record->event.pressed)
    {
      SEND_STRING("=>");
    }
    break;

  case M_SELECTCOPY:
    if (record->event.pressed)
    {
      SEND_STRING(SS_LCTRL("ac")); // selects all and copies
    }
    break;
  }

  return true;
}

uint32_t layer_state_set_user(uint32_t state)
{

  uint8_t layer = biton32(state);

  // ergodox_board_led_off();
  switch (layer)
  {
  case 1:
    ergodox_led_all_off();
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_led_all_off();
    ergodox_right_led_2_on();
    break;
  case 3:
    ergodox_led_all_off();
    ergodox_right_led_3_on();
    break;
  case 4:
    ergodox_led_all_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    break;
  case 5:
    ergodox_led_all_off();
    ergodox_right_led_1_on();
    ergodox_right_led_3_on();
    break;
  case 6:
    ergodox_led_all_off();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    break;
  case 7:
    ergodox_led_all_on();
    break;
  default:
    break;
  }
  return state;
};
