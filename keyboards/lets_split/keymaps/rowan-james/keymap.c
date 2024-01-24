#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _QWERTY = 0,
  _LOWER = 3,
  _RAISE = 4,
  _ADJUST = 16
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear

// keys in multiple locations:
//  - parenteses in both raise and lower
//  - asterix in raise and twice on lower (normal and numpad)
//  - minus/plus twice on lower (normal and numpad)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | GUI  | Alt  |Lower | Space|Space |Raise | Alt  | GUI  |ADJUST| CTRL |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12 ( \
  KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTRL,XXXXXXX,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RALT,   KC_RGUI, ADJUST,  KC_RCTRL  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | TAB  | Home | Up   | End  |      |      |      |   7  |   8  |   9  |      | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  | Left | Down | Right|      |      |      |   4  |   5  |   6  |   ,  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|PageUp|  INS |PageDn|      |      |  0   |   1  |   2  |   3  |   .  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |      | GUI  | Alt  | Lower| SPACE|SPACE | Raise| Alt  | GUI  |ADJUST| CTRL |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  _______, KC_HOME, KC_UP,   KC_END,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, KC_DEL, \
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,  XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6, KC_COMM, _______, \
  _______, KC_PGUP, KC_INS,  KC_PGDN, XXXXXXX,  XXXXXXX, KC_0,    KC_1, KC_2, KC_3, KC_DOT,  _______, \
  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Raise: punctuation layer
 * ,-----------------------------------------------------------------------------------.
 * | TAB  |   !  |  {   |  }   | @(") |  \   | /    | -    |  %   | &    | #(£) | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC  | "(@) |  (   |  )   |  '   |  #/~ | _    | =    |  <   | >    |  :   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHFT |  $   |  [   |  ]   |  `   |  ^   | *    | +    | ,    | .    |  ?   | SHFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |      | GUI  | ALT  | LOWER| SPACE|SPACE | RAISE| ALT  | GUI  |      | CTRL |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, KC_EXLM, KC_LCBR,  KC_RCBR, KC_AT,   KC_NUBS, KC_SLSH, KC_MINS, KC_PERC, KC_AMPR,  KC_HASH, KC_DEL,  \
  _______,  KC_DQT,  KC_LPRN,  KC_RPRN, KC_QUOT, KC_NUHS, KC_UNDS, KC_EQL,  KC_LABK,  KC_RABK, KC_CLN,  _______, \
  _______, KC_DLR,  KC_LBRC,  KC_RBRC, KC_GRV,  KC_CIRC, KC_ASTR, KC_PLUS, KC_COMM, KC_DOT,   KC_QUES, _______, \
  _______, _______,  _______,  _______, _______, _______, _______, _______,  _______, _______, _______, _______  \
),



/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | RESET|WH_UP | MS_UP|WH_DN | Acc2 |      | F1   | F2   |  F3  | F4   |  F5  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MS_LFT| MS_DN|MS_RGT| Acc1 |      | F6   |MS_BT1|MS_BT3|MS_BT2|  F7  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |WH_LFT|      |WH_RGT| Acc0 |      | F8   | F9   | F10  | F11  | F12  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET  , KC_WH_U, KC_MS_U, KC_WH_D, KC_ACL2, XXXXXXX, KC_F1,   KC_F2,   KC_F3,  KC_F4,    KC_F5,   _______,  \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, XXXXXXX, KC_F6,   KC_BTN1, KC_BTN3, KC_BTN2, KC_F7,   _______, \
  _______, KC_WH_L, _______, KC_WH_R, KC_ACL0, XXXXXXX, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  set_single_persistent_default_layer(_QWERTY);
  switch (keycode) {
//    case QWERTY:
//      if (record->event.pressed) {
//        set_single_persistent_default_layer(_QWERTY);
//      }
//      return false;
//      break;
//    case COLEMAK:
//      if (record->event.pressed) {
//        set_single_persistent_default_layer(_COLEMAK);
//      }
//      return false;
//      break;
//    case DVORAK:
//      if (record->event.pressed) {
//        set_single_persistent_default_layer(_DVORAK);
//      }
//      return false;
//      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
