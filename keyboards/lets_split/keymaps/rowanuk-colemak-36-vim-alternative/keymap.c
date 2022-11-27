#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _COLEMAK = 0,
  _LOWER = 1,
  _RAISE = 2,
  _ADJUST = 3
};

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
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

/* Colemak
 * ,-----------------------------------  -----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |  |   J  |   L  |   U  |   Y  | Bksp |
 * |------+------+------+------+------+  +------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |  |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+  +------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |  |   K  |   H  |   ,  |   .  |   /  |
 * |------+------+------+------+------+  +------+------+------+------+------|
 * |      |      | Ctrl | Lower| Shift|  | Space| Upper| Ralt |      |      |
 * `-----------------------------------  -----------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12 ( \
  XXXXXXX, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_BSPC, XXXXXXX, \
  XXXXXXX, GUI_T(KC_A), ALT_T(KC_R), CTL_T(KC_S), SFT_T(KC_T), KC_G, KC_M, SFT_T(KC_N), CTL_T(KC_E), ALT_T(KC_I), GUI_T(KC_O), XXXXXXX, \
  XXXXXXX, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX, \
  XXXXXXX,  XXXXXXX, XXXXXXX, KC_LCTL, LOWER, KC_LSFT, KC_SPC, RAISE, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX \
),

/* Lower
 * ,-----------------------------------  -----------------------------------.
 * | TAB  |  ¬   |  _   |  -   |  £   |  |      |   7  |   8  |   9  | BkSp |
 * |------+------+------+------+------+  +------+------+------+------+------|
 * | ESC  |  %   |  &   |  =   |  ~   |  |      |   4  |   5  |   6  | Enter|
 * |------+------+------+------+------+  +------+------+------+------+------|
 * |   |  |  ;   |  :   |  +   |  *   |  |  0   |   1  |   2  |   3  |   .  |
 * |------+------+------+------+------+  +------+------+------+------+------|
 * |      |      | Ctrl | Lower| LSHFT|  | Space| Raise| Ralt |      |      |
 * `-----------------------------------  -----------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  XXXXXXX, KC_TAB,   LSFT(KC_GRV), KC_UNDS, KC_MINS,     KC_HASH,  XXXXXXX, KC_7, KC_8, KC_9, KC_DEL, XXXXXXX, \
  XXXXXXX, KC_ESC,        KC_PERC, KC_AMPR, KC_EQL, LSFT(KC_NUHS), XXXXXXX, KC_4, KC_5, KC_6, KC_ENT, XXXXXXX, \
  XXXXXXX, LSFT(KC_NUBS), KC_SCLN, KC_COLN, KC_PLUS,     KC_ASTR,     KC_0, KC_1, KC_2, KC_3, KC_DOT, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Raise: punctuation layer
 * ,-----------------------------------  -----------------------------------.
 * |   !  |  {   |  }   | @(") |  $   |  | HOME | PGDN | PGUP | END  | INS |
 * |------+------+------+------+------+  +------+------+------+------+------|
 * | "(@) |  (   |  )   |  '   |  #/~ |  | LEFT | DOWN | UP   | RIGHT|Enter |
 * |------+------+------+------+------+  +------+------+------+------+------|
 * |  \   |  [   |  ]   |  `   |  ^   |  | ;    | :    | <    | >    |  ?   |
 * |------+------+------+------+------+  +------+------+------+------+------|
 * |      |      | CTRL | LOWER| SHIFT|  | SPACE| RAISE| Ralt |      |      |
 * `-----------------------------------  -----------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  XXXXXXX, KC_EXLM, KC_LCBR, KC_RCBR,  KC_AT,    KC_DLR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_INS, XXXXXXX, \
  XXXXXXX, KC_DQT,  KC_LPRN,  KC_RPRN, KC_QUOT, KC_NUHS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT, XXXXXXX, \
  XXXXXXX, KC_NUBS, KC_LBRC,  KC_RBRC, KC_GRV,  KC_CIRC, KC_SCLN, KC_COLN, KC_LABK, KC_RABK,  KC_QUES,XXXXXXX, \
  _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | RESET|WH_UP | MS_UP|WH_DN | Acc2 |             | F1   | F2   |  F3  | F4   |  F5  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MS_LFT| MS_DN|MS_RGT| Acc1 |             | F6   |MS_BT1|MS_BT3|MS_BT2|  F7  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CPSW |WH_LFT|      |WH_RGT| Acc0 |             | F8   | F9   | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  XXXXXXX, RESET  , KC_WH_U, KC_MS_U, KC_WH_D, KC_ACL2, KC_F1,   KC_F2,   KC_F3,  KC_F4,    KC_F5, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, KC_F6,   KC_BTN1, KC_BTN3, KC_BTN2, KC_F7, XXXXXXX, \
  XXXXXXX, CAPS_WORD, KC_WH_L, XXXXXXX, KC_WH_R, KC_ACL0, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  set_single_persistent_default_layer(_COLEMAK);
  switch (keycode) {
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
