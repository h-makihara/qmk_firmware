#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

#define JP_ZHTG KC_GRV  // hankaku/zenkaku|kanzi
#define JP_YEN  KC_INT3 // yen, |
#define JP_CIRC KC_EQL  // ^, ~
#define JP_AT   KC_LBRC // @, `
#define JP_LBRC KC_RBRC // [, {
#define JP_COLN KC_QUOT // :, *
#define JP_RBRC KC_NUHS // ], }
#define JP_BSLS KC_INT1 // \, _
#define JP_MHEN KC_INT5 // muhenkan
#define JP_HENK KC_INT4 // henkan
#define JP_KANA KC_INT2 // katakana/hiragana|ro-mazi

#define JP_MKANA KC_LANG1 //kana on MacOSX
#define JP_MEISU KC_LANG2 //eisu on MacOSX


//Aliases for shifted symbols
#define JP_DQT  LSFT(KC_2)    // "
#define JP_AMPR LSFT(KC_6)    // &
#define JP_QUOT LSFT(KC_7)    // '
#define JP_LPRN LSFT(KC_8)    // (
#define JP_RPRN LSFT(KC_9)    // )
#define JP_EQL  LSFT(KC_MINS) // =
#define JP_TILD LSFT(JP_CIRC) // ~
#define JP_PIPE LSFT(JP_YEN)  // |
#define JP_GRV  LSFT(JP_AT)   // `
#define JP_LCBR LSFT(JP_LBRC) // {
#define JP_PLUS LSFT(KC_SCLN) // +
#define JP_ASTR LSFT(JP_COLN) // *
#define JP_RCBR LSFT(JP_RBRC) // }
#define JP_UNDS LSFT(JP_BSLS) // _


// These symbols are correspond to US101-layout.
#define JP_MINS KC_MINS // -
#define JP_SCLN KC_SCLN // ;
#define JP_COMM KC_COMM // ,
#define JP_DOT  KC_DOT  // .
#define JP_SLSH KC_SLSH // /
// shifted
#define JP_EXLM KC_EXLM // !
#define JP_HASH KC_HASH // #
#define JP_DLR  KC_DLR  // $
#define JP_PERC KC_PERC // %
#define JP_LT   KC_LT   // <
#define JP_GT   KC_GT   // >
#define JP_QUES KC_QUES // ?


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust| Esc  |   /  |   *  |   -  |   +  |Space |Space |   [  |   ]  | Left | Down |  Up  |Right |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   *                             |  GUI |Lower |Space |Space |Raise |   '  |
   *                             `-----------------------------------------'
   * 
   */

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     ADJUST,  KC_ESC,  JP_SLSH, JP_ASTR, JP_MINS, JP_PLUS, KC_SPC,           KC_SPC,  JP_LBRC, JP_RBRC, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, LOWER,   KC_SPC,                    KC_SPC,  RAISE,   JP_QUOT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   /  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   *  | BTN1 | BTN2 | BTN3 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |   =  |   -  | WH_D | MS_UP| WH_U |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |  :   |      |PageDn|PageUp|Space |Space |   {  |   }  |   +  | MS_L | MS_D | MS_R | 
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   *                             |      |      |Space |Space |      |   |  |
   *                             `-----------------------------------------'
   */



  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     JP_TILD, KC_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC,                            JP_CIRC, JP_AMPR, JP_SLSH, JP_LPRN, JP_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   JP_UNDS, JP_ASTR, KC_BTN1, KC_BTN2, KC_BTN3,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                             KC_F12,  KC_EQL,  KC_MINS, KC_WH_D, KC_MS_U, KC_WH_U,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, BL_ON,   JP_COLN, _______, KC_PGDN, KC_PGUP, _______,          _______, JP_LCBR, JP_RCBR, JP_PLUS, KC_MS_L, KC_MS_D, KC_MS_R,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_SPC,                    KC_SPC,  JP_COLN, JP_PIPE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |      |      |      |      |      |             |      |   7  |   8  |   9  |   /  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |      |      |      |PageDn|PageUp|             |      |   4  |   5  |   6  |   *  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|      |      |      | Vol- | Vol+ |             |      |   1  |   2  |   3  |   -  | Enter|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |  0   |   .  |   =  |   +  |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   *                             |      |      |Space |Space |      |      |
   *                             `-----------------------------------------'
   */

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TAB,  _______, _______, _______, _______, _______,                            _______,   KC_7,    KC_8,    KC_9,  JP_SLSH, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, _______, _______, _______, KC_PGDN, KC_PGUP,                            _______,   KC_4,    KC_5,    KC_6,  JP_ASTR, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, RGB_VAD, RGB_VAI, _______, KC_VOLD, KC_VOLU,                            _______,   KC_1,    KC_2,    KC_3,  JP_MINS, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_SPC,           KC_SPC,  _______,   KC_0,  KC_DOT,   JP_EQL, JP_PLUS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_SPC,                    KC_SPC,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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
