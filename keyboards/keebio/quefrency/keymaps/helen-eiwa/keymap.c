#include QMK_KEYBOARD_H

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=false;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

#define JM(X) (X - JP_RANGE_START)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _GAME 1
#define _JPBASE 2
#define _JPRED 3
#define _JPBLUE 4
#define _FN1 5

// Simple JIS Keymappings
#define JP_A KC_3
#define JP_I KC_E
#define JP_U KC_4
#define JP_E KC_5
#define JP_O KC_6

#define JP_KA KC_T
#define JP_KI KC_G
#define JP_KU KC_H
#define JP_KE KC_QUOT
#define JP_KO KC_B

#define JP_SA KC_X
#define JP_SI KC_D
#define JP_SU KC_R
#define JP_SE KC_P
#define JP_SO KC_C

#define JP_TA KC_Q
#define JP_TI KC_A
#define JP_TU KC_Z
#define JP_TE KC_W
#define JP_TO KC_S

#define JP_NA KC_U
#define JP_NI KC_I
#define JP_NU KC_1
#define JP_NE KC_COMM
#define JP_NO KC_K

#define JP_HA KC_F
#define JP_HI KC_V
#define JP_HU KC_2
#define JP_HE KC_EQL
#define JP_HO KC_MINS

#define JP_MA KC_J
#define JP_MI KC_N
#define JP_MU KC_BSLS
#define JP_ME KC_SLSH
#define JP_MO KC_M

#define JP_YA KC_7
#define JP_YU KC_8
#define JP_YO KC_9

#define JP_RA KC_O
#define JP_RI KC_L
#define JP_RU KC_DOT
#define JP_RE KC_SCLN
#define JP_RO KC_NUBS

#define JP_WA KC_0
#define JP_WO (QK_LSFT | (JP_WA))
// #define JP_WI SAFE_RANGE
// #define JP_WE SAFE_RANGE

#define JP_NN KC_Y

#define JP_XA (QK_LSFT | (JP_A))
#define JP_XI (QK_LSFT | (JP_I))
#define JP_XU (QK_LSFT | (JP_U))
#define JP_XE (QK_LSFT | (JP_E))
#define JP_XO (QK_LSFT | (JP_O))

#define JP_XTU (QK_LSFT | (JP_TU))

#define JP_XYA (QK_LSFT | (JP_YA))
#define JP_XYU (QK_LSFT | (JP_YU))
#define JP_XYO (QK_LSFT | (JP_YO))

#define JP_DAKU KC_LBRC
#define JP_HDAKU KC_RBRC

#define JP_COMMA KC_LABK
#define JP_DOT KC_RABK
#define JP_BLT KC_QUES

#define JP_ITER SAFE_RANGE

// Custom keykodes are needed for macro driven characters.
enum custom_keycodes {
  QWERTY = SAFE_RANGE,

  JP_RANGE_START,
  JP_GA, JP_GI, JP_GU, JP_GE, JP_GO,
  JP_ZA, JP_ZI, JP_ZU, JP_ZE, JP_ZO,
  JP_DA, JP_DI, JP_DU, JP_DE, JP_DO,
  JP_BA, JP_BI, JP_BU, JP_BE, JP_BO,
  JP_PA, JP_PI, JP_PU, JP_PE, JP_PO,
  JP_RANGE_END,

  FHK_JPMODE,
  FHK_ENMODE,
};


const uint16_t dakumap[JP_RANGE_END - JP_RANGE_START][2] =
  {
   [JM(JP_GA)] = {JP_KA,JP_DAKU},
   [JM(JP_GI)] = {JP_KI,JP_DAKU},
   [JM(JP_GU)] = {JP_KU,JP_DAKU},
   [JM(JP_GE)] = {JP_KE,JP_DAKU},
   [JM(JP_GO)] = {JP_KO,JP_DAKU},

   [JM(JP_ZA)] = {JP_SA,JP_DAKU},
   [JM(JP_ZI)] = {JP_SI,JP_DAKU},
   [JM(JP_ZU)] = {JP_SU,JP_DAKU},
   [JM(JP_ZE)] = {JP_SE,JP_DAKU},
   [JM(JP_ZO)] = {JP_SO,JP_DAKU},

   [JM(JP_DA)] = {JP_TA,JP_DAKU},
   [JM(JP_DI)] = {JP_TI,JP_DAKU},
   [JM(JP_DU)] = {JP_TU,JP_DAKU},
   [JM(JP_DE)] = {JP_TE,JP_DAKU},
   [JM(JP_DO)] = {JP_TO,JP_DAKU},

   [JM(JP_BA)] = {JP_HA,JP_DAKU},
   [JM(JP_BI)] = {JP_HI,JP_DAKU},
   [JM(JP_BU)] = {JP_HU,JP_DAKU},
   [JM(JP_BE)] = {JP_HE,JP_DAKU},
   [JM(JP_BO)] = {JP_HO,JP_DAKU},

   [JM(JP_PA)] = {JP_HA,JP_HDAKU},
   [JM(JP_PI)] = {JP_HI,JP_HDAKU},
   [JM(JP_PU)] = {JP_HU,JP_HDAKU},
   [JM(JP_PE)] = {JP_HE,JP_HDAKU},
   [JM(JP_PO)] = {JP_HO,JP_HDAKU},
  };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode > JP_RANGE_START && keycode < JP_RANGE_END) {
    uint16_t k = JM(keycode);

    if (record->event.pressed) {
      register_code(dakumap[k][0]);
      register_code(dakumap[k][1]);
    } else {
      unregister_code(dakumap[k][1]);
      unregister_code(dakumap[k][0]);
    }

  } else {
    switch (keycode) {
    case FHK_JPMODE:
      if (!record->event.pressed) { // Execute macro on release
	set_single_persistent_default_layer(_JPBASE);
	register_code(KC_LALT);
	tap_code(KC_RSHIFT);
	unregister_code(KC_LALT);
      }
      break;
    case FHK_ENMODE:
      if (!record->event.pressed) { // Execute macro on release
	set_single_persistent_default_layer(_BASE);
	register_code(KC_LALT);
	tap_code(KC_RSHIFT);
	unregister_code(KC_LALT);
      }
      break;
    }
  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
  {
  [_BASE] = LAYOUT(
    KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    MT(MOD_LCTL,
       KC_ESC),
              KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP, \
    MO(_FN1), KC_LALT, KC_LGUI, KC_MHEN, KC_SPC,           KC_SPC,  KC_HENK, KC_HAEN, KC_LANG3, KC_LANG4, DF(_JPBASE), MO(_FN1)
  ),

   [_GAME] = LAYOUT(
    KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    MOD_LCTL,
              KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP, \
    MO(_FN1), KC_LALT, KC_LGUI, KC_MHEN, KC_SPC,           KC_SPC,  KC_HENK, KC_HAEN, KC_LANG3, KC_LANG4, DF(_BASE), MO(_FN1)
  ),


  [_JPBASE] = LAYOUT
  (
   _______, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, _______,_______,_______,_______, \
   _______, JP_DOT, JP_KA, JP_TA, JP_KO, JP_SA, JP_RA, JP_TI, JP_KU, JP_TU, JP_COMMA, _______, _______, _______, \
   _______, JP_U,   JP_SI, JP_TE, JP_KE, JP_SE, JP_HA, JP_TO, JP_KI, JP_I, JP_NN, _______, _______, \
   _______, _______, JP_HI, JP_SU, JP_HU, JP_HE, JP_ME, JP_SO, JP_NE, JP_HO, JP_BLT, _______, _______, \
   _______, _______, _______, KC_MHEN, MO(_JPRED),  MO(_JPBLUE), KC_HENK, _______, _______, _______, DF(_BASE), _______
   ),

  [_JPRED] = LAYOUT
  (
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______, JP_XA,  JP_E,  JP_RI,  JP_XYA, JP_RE, JP_PA, JP_DI, JP_GU, JP_DU, JP_PI, _______, _______, _______, \
   _______, JP_WO,  JP_A,  JP_NA,  JP_XYU, JP_MO, JP_BA, JP_DO, JP_GI, JP_PO, _______, _______, _______, \
   _______, JP_XU,  _______, JP_RO, JP_YA, JP_XI, JP_PU, JP_ZO, JP_PE, JP_BO, _______, _______, _______, \
   _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______
   ),

  [_JPBLUE] = LAYOUT
  (
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______,_______, JP_GA, JP_DA, JP_GO, JP_ZA, JP_YO, JP_NI, JP_RU, JP_MA, JP_XE, _______, _______, _______, \
   _______,_______, JP_ZI,  JP_DE,  JP_KE, JP_SE, JP_MI, JP_O, JP_NO, JP_XYO, _______, _______, _______, \
   _______,_______,  JP_BI, JP_ZU, JP_BU, JP_BI, JP_NU, JP_YU, JP_MU, JP_WA, _______, _______, _______, \
   _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
   ),

     [_FN1] = LAYOUT(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, \
    _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_TILD, _______, _______, _______, _______,          _______, _______, _______, DF(_GAME), DF(_BASE), DF(_JPBASE), _______
  ),

};
