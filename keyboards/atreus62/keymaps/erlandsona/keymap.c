// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE 0
#define FUNC 2
#define SPEC 1

// Some quick aliases, just to make it look pretty
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = KEYMAP( /* Qwerty */
    KC_GRV , KC_1,     KC_2,     KC_3,    KC_4,    KC_5,                    KC_6,   KC_7,     KC_8,     KC_9,    KC_0,    KC_EQL,
    KC_TAB , KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,                    KC_Y,   KC_U,     KC_I,     KC_O,    KC_P,    KC_MINS,
    KC_LALT, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,                    KC_H,   KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,                    KC_N,   KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_LBRC,
    KC_LSFT, MO(FUNC), KC_LALT,  KC_LALT, KC_LGUI, KC_BSPC, KC_ESC, KC_ENT, KC_SPC, KC_RSFT,  MO(SPEC), KC_RALT, KC_BSLS, KC_RBRC),

[FUNC] = KEYMAP( /* Arrows / FKeys */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______,                   _______,  _______, _______, _______,  KC_PWR,  KC_F12,
    _______, _______, _______, _______, _______, _______,                   KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______,  _______, _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______,  _______, _______, _______,  _______, _______),

[SPEC] = KEYMAP( /* Page / Special Keys */
    _______, KC_SLCK, KC_PAUSE,  KC_F11,  KC_F10, KC_MPRV,                   KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_F11,
    _______, _______, _______,  _______, _______, _______,                   _______, _______, _______, _______, _______, KC_F12,
    _______, _______, _______,  _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    _______, _______, _______,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
	case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
	}
	return MACRO_NONE;
};
