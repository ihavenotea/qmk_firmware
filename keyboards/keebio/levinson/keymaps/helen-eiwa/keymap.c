#include QMK_KEYBOARD_H
#include "thumbshift.h"

#define _BASE 0

#define _NIHON 1
#define _RED 2
#define _BLUE 3

#define _LOWER 5
#define _RAISE 6

#define _ADJUST 16

enum custom_keycodes {
  QWERTY = THUMBSHIFT_SAFE_RANGE,
  NIHON,
  LOWER,
  RAISE,
  ADJUST,
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ct/Es|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sh/En |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust|  JP  | Super| Alt  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_4x12( \
  KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  MT(MOD_LCTL,KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT,KC_ENT) , \
  ADJUST,       NIHON, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* NIHON
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Space |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | EN   |      |      |      | RED  | BLUE |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NIHON] = LAYOUT_ortho_4x12( \
  _______, JP_DOT,  JP_KA, JP_TA, JP_KO, JP_SA, JP_RA, JP_TI, JP_KU, JP_TU, JP_COMM, _______, \
  _______, JP_U,    JP_SI, JP_TE, JP_KE, JP_SE, JP_HA, JP_TO, JP_KI, JP_I,  JP_NN,   KC_SPC, \
  _______, _______, JP_HI, JP_SU, JP_HU, JP_HE, JP_ME, JP_SO, JP_NE, JP_HO, JP_BLT,  _______, \
  _______, QWERTY, _______, _______, _______, MO(_RED), MO(_BLUE), _______, _______, _______, _______, _______ \
),

/* RED
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |AltGrv|      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RED] = LAYOUT_ortho_4x12( \
  _______, JP_XA,  JP_E,  JP_RI,  JP_XYA, JP_RE, JP_PA, JP_DI, JP_GU, JP_DU, JP_PI,   _______, \
  _______, JP_WO,  JP_A,  JP_NA,  JP_XYU, JP_MO, JP_BA, JP_DO, JP_GI, JP_PO, _______, _______, \
  _______, JP_XU,  _______, JP_RO, JP_YA, JP_XI, JP_PU, JP_ZO, JP_PE, JP_BO, _______, _______, \
  _______, LALT(KC_GRAVE), _______, _______, _______, _______,_______, _______, _______, _______, _______, _______ \
),

/* BLUE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |AltGrv|      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BLUE] = LAYOUT_ortho_4x12( \
  _______, _______, JP_GA, JP_DA, JP_GO, JP_ZA, JP_YO, JP_NI, JP_RU, JP_MA,  JP_XE,   _______, \
  _______, _______, JP_ZI, JP_DE, JP_GE, JP_ZE, JP_MI, JP_O,  JP_NO, JP_XYO, _______, _______, \
  _______, _______, JP_BI, JP_ZU, JP_BU, JP_BI, JP_NU, JP_YU, JP_MU, JP_WA,  _______, _______, \
  _______, LALT(KC_GRAVE), _______, _______, _______, _______,_______, _______, _______, _______, _______, _______ \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  BL_STEP, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,_______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 | F12  | F13  | F14  | F15  |      | Jp/En|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | BASE |      |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  KC_ESC,  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, TG(_NIHON), DF(_BASE), DF(_BASE),  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, TO(_BASE), _______, _______, _______, _______, _______, _______, KC_HOME,  KC_PGDN, KC_PGUP, KC_END \
)

};

void keyboard_post_init_user(void) {
  debug_enable=false;
  user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) { 
  user_config.raw = 0;
  user_config.romaji_mode = true; 
  eeconfig_update_user(user_config.raw);
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
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
    case QWERTY:
      if (record->event.pressed) {
	register_code(KC_LALT);
	register_code(KC_LSHIFT);
      } else {
	unregister_code(KC_LSHIFT);
	unregister_code(KC_LALT);
	layer_off(_RED);
	layer_off(_BLUE);
	layer_off(_NIHON);
      }
      break;
    case NIHON:
      if (record->event.pressed) {
	register_code(KC_LALT);
	register_code(KC_LSHIFT);
      } else {
	unregister_code(KC_LSHIFT);
	unregister_code(KC_LALT);
	layer_on(_NIHON);
      }
      break;
    }
  }
  return true;
}
