
#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum niu_layers {
  _BA,           // Base layout (Balance Twelve mirror variant)
  _NP,           // Numeric/Punctuation
  _FC,           // Function/Cursor
  _ST            // Stenography
};

// Abbreviations
#define KZ_CTL  MT( MOD_LCTL, KC_Z )
#define KJ_ALT  MT( MOD_LALT, KC_J )
#define KDT_ALT MT( MOD_LALT, KC_DOT )
#define KX_CTL  MT( MOD_LCTL, KC_X )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base
     .---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.
     | P       | L       | C       | D       | W       |         |         | U       | O       | Y       | K       | Q       |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     | N       | R       | S       | T       | M       |         | BS      | A       | E       | I       | H       | V       |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     | Z Ctl   | J Alt   | F       | G       | B       |         | Ent     | ' @     | , <     | . > Alt | X Ctl   |         |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     |         |         |         | NP      | Spc     | FC      | Sft     |         | Sup     |         |         |         |
     '---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'
  */
  [_BA] = LAYOUT(
      KC_P,     KC_L,     KC_C,     KC_D,     KC_W,     XXXXXXX,  XXXXXXX,  KC_U,     KC_O,     KC_Y,     KC_K,     KC_Q,
      KC_N,     KC_R,     KC_S,     KC_T,     KC_M,     XXXXXXX,  KC_BSPC,  KC_A,     KC_E,     KC_I,     KC_H,     KC_V,
      KZ_CTL,   KJ_ALT,   KC_F,     KC_G,     KC_B,     XXXXXXX,  KC_ENT,   KC_QUOT,  KC_COMM,  KDT_ALT,  KX_CTL,   XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  MO(_NP),  KC_SPC,   MO(_FC),  KC_LSFT,  XXXXXXX,  KC_LGUI,  XXXXXXX,  XXXXXXX,  XXXXXXX 
  ),

  /* Numeric/Punctuation (NP)
     .---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.
     | 1 !     | 2 "     | 3 £     | 4 $     | 5 %     |         |         | 6 ^     | 7 &     | 8 *     | 9 (     | 0 )     |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     | Tab     | Ctl-X   | Ctl-C   | Ctl-V   | Ctl-Z   |         | # ~     | [ {     | ] }     | - _     | ; :     | \ |     |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     | Ctl     | Alt     | Esc     | Del     | Ins     |         | `       | / ?     | = +     | Alt     | Ctl     |         |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     |         |         |         | NP      | Spc     |         | Sft     |         | Sup     |         |         |         |
     '---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'
  */                                           
  [_NP] = LAYOUT(
      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     XXXXXXX,  XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
      KC_TAB,   C(KC_X),  C(KC_C),  C(KC_V),  C(KC_Z),  XXXXXXX,  KC_NUHS,  KC_LBRC,  KC_RBRC,  KC_MINS,  KC_SCLN,  KC_NUBS,
      _______,  _______,  KC_ESC,   KC_DEL,   KC_INS,   XXXXXXX,  KC_GRV,   KC_SLSH,  KC_EQL,   _______,  _______,  XXXXXXX, 
      XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  _______,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  /* Function/Cursor (FC)
     .---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.
     | F1      | F2      | F3      | F4      | F5      |         |         | Home    | Up      | End     | PgUp    |         |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     | F6      | F7      | F8      | F9      | F10     |         | Caps    | Left    | Down    | Right   | PgDn    |         |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     | Ctl     | Alt     |         | F11     | F12     |         | PScr    | Break   | ScLk    | Alt     | Ctl     |         |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     |         |         |         | ST      | Spc     |         | Sft     |         | Sup     |         |         |         |
     '---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'
  */
  [_FC] = LAYOUT(
      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,  XXXXXXX,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  XXXXXXX,
      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   XXXXXXX,  KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  XXXXXXX,
      _______,  _______,  XXXXXXX,  KC_F11,   KC_F12,   XXXXXXX,  KC_PSCR,  KC_BRK,   KC_SLCK,  _______,  _______,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  TO(_ST),  _______,  _______,  _______,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  /* Stenography (ST)
     .---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.---------.
     | #       | #       | #       | #       | #       |         | #       | #       | #       | #       | #       | #       |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     | S       | T       | P       | H       | *       |         | *       | F       | P       | L       | T       | D       |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     | S       | K       | W       | R       | *       |         | *       | R       | B       | G       | S       | Z       |
     |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
     |         |         |         | A       | O       | BA      | E       | U       |         |         |         |         |
     '---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'---------'
  */
  [_ST] = LAYOUT(
      STN_NUM,  STN_NUM,  STN_NUM,  STN_NUM,  STN_NUM,  XXXXXXX,  STN_NUM,  STN_NUM,  STN_NUM,  STN_NUM,  STN_NUM,  STN_NUM,
      STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,  XXXXXXX,  STN_ST1,  STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR,
      STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,  XXXXXXX,  STN_ST2,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  STN_A,    STN_O,    TO(_BA),  STN_E,    STN_U,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  )

};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}