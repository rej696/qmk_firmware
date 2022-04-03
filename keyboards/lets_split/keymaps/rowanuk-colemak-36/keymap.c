#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _COLEMAK = 0,
  _MOUSE = 2,
  _LOWER = 3,
  _RAISE = 4,
  _ADJUST = 16
};

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  MOUSE,
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
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |      |      |   J  |   L  |   U  |   Y  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |      |      |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |      |      |   K  |   H  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Ctrl | Lower| Shift| Ctrl | Ctrl | Space| Upper| Ctrl |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12 ( \
  KC_Q, KC_W, KC_F, KC_P, KC_B, XXXXXXX, XXXXXXX, KC_J, KC_L, KC_U, KC_Y, KC_BSPC, \
  MOD_LGUI(KC_A), MOD_LALT(KC_R), MOD_LCTL(KC_S), MOD_LSFT(KC_T), KC_G, XXXXXXX, XXXXXXX, KC_M, MOD_LSFT(KC_N), MOD_LCTL(KC_E), MOD_LALT(KC_I), MOD_LGUI(KC_O), \
  LT(MOUSE, KC_Z), KC_X, KC_C, KC_D, KC_V, XXXXXXX, XXXXXXX, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, \
  XXXXXXX,  XXXXXXX, KC_LCTL, LOWER, KC_LSFT, KC_LCTL, KC_LCTL, KC_SPC, RAISE, KC_LCTL, XXXXXXX, XXXXXXX \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MS_BT1|MS_BT3|MS_BT2|ScrllU|      |      |MS_LFT|MS_DN |MS_UP |MS_RGT|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  C-X | C-C  |ScrllD| C-V  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Ctrl |      | Shift| Ctrl | Ctrl | Space|      | CTRL |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12 ( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, KC_WH_U, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, \
  XXXXXXX, LCTL(KC_X), LCTL(KC_C), KC_WH_D, LCTL(KC_V), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,  XXXXXXX, KC_LCTRL, XXXXXXX, KC_LSFT, KC_LCTRL, KC_LCTRL, KC_SPC, XXXXXXX, KC_LCTRL, XXXXXXX, XXXXXXX \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | TAB  | Home | Up   | End  | LSHFT|      |      |   7  |   8  |   9  |      | BkSp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  | Left | Down | Right| LALT |      |      |   4  |   5  |   6  |   ,  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LGUI |PageUp|  INS |PageDn| DEL  |      |      |   1  |   2  |   3  |   .  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Ctrl | Lower| LSHFT| SPACE|  0   | Raise| Alt  | GUI  |ADJUST| CTRL |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TAB, KC_HOME, KC_UP,   KC_END,  KC_LSFT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_7, KC_8, KC_9, KC_DEL, \
  KC_ESC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6, KC_ENT, \
  KC_LGUI, KC_PGUP, KC_INS,  KC_PGDN, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, KC_DOT, \
  _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______, _______ \
),

/* Raise: punctuation layer
 * ,-----------------------------------------------------------------------------------.
 * |   !  |  {   |  }   | @(") |  $   |             | #(£) | -    |  %   | &    | BKSP |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | "(@) |  (   |  )   |  '   |  #/~ |             | _    | =    |  :   |  ;   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \   |  [   |  ]   |  `   |  ^   |             | *    | +    | ,    | .    |  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | CTRL | LOWER| SHIFT| CTRL | CTRL | SPACE| RAISE| CTRL |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_EXLM, KC_LCBR, KC_RCBR,  KC_AT,    KC_DLR, XXXXXXX, XXXXXXX, KC_HASH, KC_MINS, KC_PERC, KC_AMPR, KC_BSPC, \
  KC_DQT,  KC_LPRN,  KC_RPRN, KC_QUOT, KC_NUHS, XXXXXXX, XXXXXXX, KC_UNDS, KC_EQL,  KC_CLN,  KC_SCLN, KC_ENT,  \
  KC_NUBS, KC_LBRC,  KC_RBRC, KC_GRV,  KC_CIRC, XXXXXXX, XXXXXXX, KC_ASTR, KC_PLUS, KC_LABK, KC_RABK, KC_QUES, \
  _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______  \
),



/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | RESET|WH_UP | MS_UP|WH_DN | Acc2 |             | F1   | F2   |  F3  | F4   |  F5  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MS_LFT| MS_DN|MS_RGT| Acc1 |             | F6   |MS_BT1|MS_BT3|MS_BT2|  F7  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |WH_LFT|      |WH_RGT| Acc0 |             | F8   | F9   | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET  , KC_WH_U, KC_MS_U, KC_WH_D, KC_ACL2, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,  KC_F4,    KC_F5,  \
  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, XXXXXXX, XXXXXXX, KC_F6,   KC_BTN1, KC_BTN3, KC_BTN2, KC_F7,  \
  XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, KC_ACL0, XXXXXXX, XXXXXXX, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  set_single_persistent_default_layer(_COLEMAK);
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
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
      break;
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
