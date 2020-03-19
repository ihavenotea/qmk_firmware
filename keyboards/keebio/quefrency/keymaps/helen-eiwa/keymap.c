#include QMK_KEYBOARD_H
#include "thumbshift.h"

// TODO:

// Then:
//   - Add Punctuation
//   - Determine how to implement Numbers

//   - Make the Game Layer good enough for Gaming

//   - Set up the FN layer: Media Keys, Navigation.
//   - Determine a reasonable modifier layout.


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _BASE 0
#define _GAME 1 // Eliminates all dual function keys.

#define _RJBASE 2
#define _RJRED 3
#define _RJBLUE 4

#define _JBASE 5    // QWERTY for JIS Input
#define _JISTHUMB 6 // Thumbshift Base Layer
#define _JISRED 7   // Thumbshift Red (left thumb)
#define _JISBLUE 8  // Thumbshift Blue (right thumb)

#define _FN1 9

// Custom keykodes are needed for macro driven characters.
enum custom_keycodes {
  QWERTY = THUMBSHIFT_SAFE_RANGE,
};

#define JM(X) (X - JP_RANGE_START)
#define RJM(X) (X - RJ_RANGE_START)



const uint16_t dakumap[][2] =
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


const char romajimap[][4] =
  {
   [RJM(RJ_KA)] = "ka",
   [RJM(RJ_KI)] = "ki",
   [RJM(RJ_KU)] = "ku",
   [RJM(RJ_KE)] = "ke",
   [RJM(RJ_KO)] = "ko",
   
   [RJM(RJ_GA)] = "ga",
   [RJM(RJ_GI)] = "gi",
   [RJM(RJ_GU)] = "gu",
   [RJM(RJ_GE)] = "ge",
   [RJM(RJ_GO)] = "go",
   
   [RJM(RJ_SA)] = "sa",
   [RJM(RJ_SI)] = "si",
   [RJM(RJ_SU)] = "su",
   [RJM(RJ_SE)] = "se",
   [RJM(RJ_SO)] = "so",
   
   [RJM(RJ_ZA)] = "za",
   [RJM(RJ_ZI)] = "zi",
   [RJM(RJ_ZU)] = "zu",
   [RJM(RJ_ZE)] = "ze",
   [RJM(RJ_ZO)] = "zo",
   
   [RJM(RJ_TA)] = "ta",
   [RJM(RJ_TI)] = "ti",
   [RJM(RJ_TU)] = "tu",
   [RJM(RJ_TE)] = "te",
   [RJM(RJ_TO)] = "to",
   
   [RJM(RJ_DA)] = "da",
   [RJM(RJ_DI)] = "di",
   [RJM(RJ_DU)] = "du",
   [RJM(RJ_DE)] = "de",
   [RJM(RJ_DO)] = "do",

   [RJM(RJ_NA)] = "na",
   [RJM(RJ_NI)] = "ni",
   [RJM(RJ_NU)] = "nu",
   [RJM(RJ_NE)] = "ne",
   [RJM(RJ_NO)] = "no",
   
   [RJM(RJ_HA)] = "ha",
   [RJM(RJ_HI)] = "hi",
   [RJM(RJ_HU)] = "hu",
   [RJM(RJ_HE)] = "he",
   [RJM(RJ_HO)] = "ho",
   
   [RJM(RJ_BA)] = "ba",
   [RJM(RJ_BI)] = "bi",
   [RJM(RJ_BU)] = "bu",
   [RJM(RJ_BE)] = "be",
   [RJM(RJ_BO)] = "bo",
   
   [RJM(RJ_PA)] = "pa",
   [RJM(RJ_PI)] = "pi",
   [RJM(RJ_PU)] = "pu",
   [RJM(RJ_PE)] = "pe",
   [RJM(RJ_PO)] = "po",
   
   [RJM(RJ_MA)] = "ma",
   [RJM(RJ_MI)] = "mi",
   [RJM(RJ_MU)] = "mu",
   [RJM(RJ_ME)] = "me",
   [RJM(RJ_MO)] = "mo",
   
   [RJM(RJ_YA)] = "ya",
   [RJM(RJ_YU)] = "yu",
   [RJM(RJ_YO)] = "yo",
   
   [RJM(RJ_RA)] = "ra",
   [RJM(RJ_RI)] = "ri",
   [RJM(RJ_RU)] = "ru",
   [RJM(RJ_RE)] = "re",
   [RJM(RJ_RO)] = "ro",
   
   [RJM(RJ_WA)] = "wa",
   [RJM(RJ_WO)] = "wo",
   
   [RJM(RJ_NN)] = "nn",
   
   [RJM(RJ_XA)] = "xa",
   [RJM(RJ_XI)] = "xi",
   [RJM(RJ_XU)] = "xu",
   [RJM(RJ_XE)] = "xe",
   [RJM(RJ_XO)] = "xo",
   
   [RJM(RJ_XTU)] = "xtu",
   
   [RJM(RJ_XYA)] = "xya",
   [RJM(RJ_XYU)] = "xyu",
   [RJM(RJ_XYO)] = "xyo",

  };


typedef union {
  uint32_t raw;
  struct {
    bool     romaji_mode :1;
  };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
  debug_enable=false;
  user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) { 
  user_config.raw = 0;
  user_config.romaji_mode = true; 
  eeconfig_update_user(user_config.raw);
}


static inline bool process_record_romaji(uint16_t keycode, keyrecord_t *record) {
  if (keycode > RJ_RANGE_START && keycode < RJ_RANGE_END) {
    if (record->event.pressed) {
      uint16_t k = RJM(keycode);
      send_string(romajimap[k]);
    }
  }
  return true;
}


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

  } else if (keycode > RJ_RANGE_START && keycode < RJ_RANGE_END) {
    process_record_romaji(keycode, record);
    /* uint16_t k = RJM(keycode); */

    /* if (record->event.pressed) { */
    /*   send_string(romajimap[k]); */
    /* } */

  } else {
  
    switch (keycode) {
    case FHK_RJ_TOGGLE:
      if (record->event.pressed) {
	// Toggle Romaji and JIS modes
	user_config.romaji_mode ^= 1;	
	// Persist this setting
	eeconfig_update_user(user_config.raw);
      }
      // Fall through and update the active japanese mode to ensure consistency
      
    case FHK_JISMODE:
      if (record->event.pressed) {
	if (user_config.romaji_mode) {
	  layer_on(_RJBASE);
	  layer_off(_JBASE);
	  layer_off(_JISTHUMB);
	} else {
	  layer_off(_RJBASE);
	  layer_on(_JBASE);
	  layer_on(_JISTHUMB);
	}
      }
      break;

    case FHK_ENMODE:
      if (record->event.pressed) {
	layer_off(_RJBASE);
	layer_off(_JBASE);
	layer_off(_JISTHUMB);
	layer_off(_JISRED);
	layer_off(_JISBLUE);
      }
      break;
      
    case FHK_JISCAPS:
      if (record->event.pressed) {
        tap_code(KC_CAPS);
	layer_invert(_JISTHUMB);
      }
      break;
      
    case FHK_ZKHK:
      if (record->event.pressed) {
        tap_code(KC_ZKHK);
	layer_invert(_JISTHUMB);
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
    MO(_FN1),  KC_LGUI, KC_LALT, KC_LALT, KC_SPC,           KC_SPC,  KC_RALT, KC_HAEN, FHK_ENMODE, _______, FHK_JISMODE, MO(_FN1)
  ),

   [_GAME] = LAYOUT(
 KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 MOD_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),


    [_RJBASE] = LAYOUT
  (
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,_______,_______, \
   LT(_RJBLUE, KC_TAB), RJ_DOT, RJ_KA, RJ_TA, RJ_KO, RJ_SA, RJ_RA, RJ_TI, RJ_KU, RJ_TU, RJ_COMM, _______, _______, LT(_RJRED,KC_BSLS), \
   _______, RJ_U,   RJ_SI, RJ_TE, RJ_KE, RJ_SE, RJ_HA, RJ_TO, RJ_KI, RJ_I, RJ_NN, _______, _______, \
   _______, _______, RJ_HI, RJ_SU, RJ_HU, RJ_HE, RJ_ME, RJ_SO, RJ_NE, RJ_HO, RJ_BLT, _______, _______, \
   _______, _______, _______, KC_ENT, MO(_RJRED),  MO(_RJBLUE), KC_SPC, _______, _______, _______, FHK_ENMODE, _______
   ),

  [_RJRED] = LAYOUT
  (
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______, RJ_XA,  RJ_E,  RJ_RI,  RJ_XYA, RJ_RE, RJ_PA, RJ_DI, RJ_GU, RJ_DU, RJ_PI, _______, _______, _______, \
   _______, RJ_WO,  RJ_A,  RJ_NA,  RJ_XYU, RJ_MO, RJ_BA, RJ_DO, RJ_GI, RJ_PO, _______, _______, _______, \
   _______, RJ_XU,  _______, RJ_RO, RJ_YA, RJ_XI, RJ_PU, RJ_ZO, RJ_PE, RJ_BO, _______, _______, _______, \
   _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______
   ),

  [_RJBLUE] = LAYOUT
  (
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______,_______, RJ_GA, RJ_DA, RJ_GO, RJ_ZA, RJ_YO, RJ_NI, RJ_RU, RJ_MA, RJ_XE, _______, _______, _______, \
   _______,_______, RJ_ZI,  RJ_DE,  RJ_GE, RJ_ZE, RJ_MI, RJ_O, RJ_NO, RJ_XYO, _______, _______, _______, \
   _______,_______,  RJ_BI, RJ_ZU, RJ_BU, RJ_BI, RJ_NU, RJ_YU, RJ_MU, RJ_WA, _______, _______, _______, \
   _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
   ),


  [_JBASE] = LAYOUT
  (
   FHK_ZKHK,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______, _______, _______, KC_MHEN, _______,  _______, KC_HENK, FHK_JISCAPS, _______, _______, FHK_ENMODE, _______
   ),  

  [_JISTHUMB] = LAYOUT
  (
   _______, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, _______,_______,_______,_______, \
   _______, JP_DOT, JP_KA, JP_TA, JP_KO, JP_SA, JP_RA, JP_TI, JP_KU, JP_TU, JP_COMM, _______, _______, _______, \
   _______, JP_U,   JP_SI, JP_TE, JP_KE, JP_SE, JP_HA, JP_TO, JP_KI, JP_I, JP_NN, _______, _______, \
   _______, _______, JP_HI, JP_SU, JP_HU, JP_HE, JP_ME, JP_SO, JP_NE, JP_HO, JP_BLT, _______, _______, \
   _______, _______, _______, KC_MHEN, MO(_JISRED),  MO(_JISBLUE), KC_HENK, _______, _______, _______, _______, _______
   ),  

  [_JISRED] = LAYOUT
  (
   KC_ZKHK,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______, JP_XA,  JP_E,  JP_RI,  JP_XYA, JP_RE, JP_PA, JP_DI, JP_GU, JP_DU, JP_PI, _______, _______, _______, \
   _______, JP_WO,  JP_A,  JP_NA,  JP_XYU, JP_MO, JP_BA, JP_DO, JP_GI, JP_PO, _______, _______, _______, \
   _______, JP_XU,  _______, JP_RO, JP_YA, JP_XI, JP_PU, JP_ZO, JP_PE, JP_BO, _______, _______, _______, \
   _______, _______, _______, _______, _______,               _______, _______, KC_CAPS, _______, _______, _______, _______
   ),

  [_JISBLUE] = LAYOUT
  (
   KC_ZKHK,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
   _______,_______, JP_GA, JP_DA, JP_GO, JP_ZA, JP_YO, JP_NI, JP_RU, JP_MA, JP_XE, _______, _______, _______, \
   _______,_______, JP_ZI,  JP_DE,  JP_KE, JP_SE, JP_MI, JP_O, JP_NO, JP_XYO, _______, _______, _______, \
   _______,_______,  JP_BI, JP_ZU, JP_BU, JP_BI, JP_NU, JP_YU, JP_MU, JP_WA, _______, _______, _______, \
   _______, _______, _______, _______, _______,          _______, _______, KC_CAPS, _______, _______, _______, _______
   ),

  

  
  [_FN1] = LAYOUT(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, \
    _______, _______, _______, KC_UP,   _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______, FHK_RJ_TOGGLE, _______, \
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______,_______,TG(_GAME), _______
  ),

};
