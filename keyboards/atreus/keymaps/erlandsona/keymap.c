// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE 0
#define NUMS 1
#define MOUS 2

// Some quick aliases, just to make it look pretty
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = KEYMAP( /* Qwerty */
  KC_Q       , KC_W   , KC_E   , KC_R   ,  KC_T   ,                 KC_Y  ,  KC_U   , KC_I   , KC_O   , KC_P           ,
  KC_A       , KC_S   , KC_D   , KC_F   ,  KC_G   ,                 KC_H  ,  KC_J   , KC_K   , KC_L   , KC_SCLN        ,
  SFT_T(KC_Z), KC_X   , KC_C   , KC_V   ,  KC_B   ,                 KC_N  ,  KC_M   , KC_COMM, KC_DOT , KC_QUOT        ,
  KC_LCTL    , KC_LALT, KC_LALT, KC_LGUI,  KC_BSPC, KC_ESC, KC_ENT, KC_SPC,  MO(NUMS), KC_RALT, KC_SLSH, SFT_T(KC_BSLS)),

[NUMS] = KEYMAP( /* Numbers / Arrows / Symbols */
  KC_GRV , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,
  KC_TAB , KC_1   , XXXXXXX, XXXXXXX, KC_6   ,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_LBRC,
  _______, XXXXXXX, XXXXXXX, KC_DOT , KC_7   ,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_RBRC,
  _______, _______, _______, _______, KC_DEL , TO(MOUS), _______, _______, _______, _______, _______, _______),

[MOUS] = KEYMAP( /* Mouse and Media Keys */
  KC_SLCK, KC_PAUSE, KC_F11 , KC_F10 , KC_F9  ,                   KC_F8  , KC_F7  , KC_F6  , KC_F5  , KC_F4,
  KC_VOLD, KC_ACL0 , KC_ACL1, KC_ACL2, KC_VOLU,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_F3,
  KC_MUTE, KC_MPRV , KC_MPLY, KC_MNXT, KC_MUTE,                   KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, KC_F2,
  _______, _______ , _______, _______, _______, TO(BASE), _______, KC_BTN1, TO(BASE), RESET  , KC_F12 , KC_F1)
};


const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
