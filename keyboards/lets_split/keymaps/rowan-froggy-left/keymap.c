#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _ALPHA1 = 0,
  _ALPHA2 = 1,
  _LOWER = 2,
  _RAISE = 3,
  _PUNC = 4
};

enum custom_keycodes {
  ALPHA1 = SAFE_RANGE,
  ALPHA2,
  LOWER,
  RAISE,
  PUNC,
};

// Fillers to make layering more clear

// keys in multiple locations:
//  - parenteses in both raise and lower
//  - asterix in raise and twice on lower (normal and numpad)
//  - minus/plus twice on lower (normal and numpad)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ALPHA1] = LAYOUT_ortho_4x12 ( \
  KC_BSPC, KC_P, KC_W, KC_R, KC_A, KC_F, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  ALPHA2, GUI_T(KC_D), ALT_T(KC_T), CTL_T(KC_H), SFT_T(KC_E), KC_O, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  PUNC, KC_Y, KC_S, KC_N, KC_I, KC_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_LCTL, KC_LGUI,  KC_LALT, LOWER, RAISE, SFT_T(KC_SPC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
),

[_ALPHA2] = LAYOUT_ortho_4x12( \
  _______, KC_J, KC_M, KC_B, KC_MINS, KC_HASH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_V, KC_C, KC_L, KC_Z, KC_Q,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_X, KC_G, KC_K, KC_UNDS, KC_ASTR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______, _______, _______ \
),

[_LOWER] = LAYOUT_ortho_4x12( \
  KC_DEL,   KC_7, KC_8, KC_9, KC_SLSH, KC_ASTR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_ESC,   KC_4, KC_5, KC_6, KC_EQL,  KC_MINS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_LSFT, KC_1, KC_2, KC_3, KC_0,    KC_PLUS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______, _______, _______ \
),

[_RAISE] = LAYOUT_ortho_4x12( \
  KC_INS, KC_TAB, KC_HOME, KC_PGUP, KC_PGDN, KC_END, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_ESC, KC_ENT, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
  KC_LSFT, KC_SLSH, KC_DOT, KC_COMM, KC_COLN,  KC_SCLN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______  \
),

[_PUNC] = LAYOUT_ortho_4x12( \
  _______, KC_EXLM, KC_PERC, KC_AMPR,  KC_AT,    KC_DLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_DQT,  KC_LPRN,  KC_RPRN, KC_QUOT, KC_NUHS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KC_NUBS, KC_LBRC,  KC_RBRC, KC_GRV,  KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ \
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  set_single_persistent_default_layer(_ALPHA1);
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case ALPHA2:
      if (record->event.pressed) {
        layer_on(_ALPHA2);
      } else {
        layer_off(_ALPHA2);
      }
      return false;
      break;
    case PUNC:
      if (record->event.pressed) {
        layer_on(_PUNC);
      } else {
        layer_off(_PUNC);
      }
      return false;
      break;
  }
  return true;
}
