#include QMK_KEYBOARD_H
#include <rgblight.h>
#include "thumbshift.h"

#define RJDELAY 5

#define _BASE 0

#define _GAME 2 
#define _NUMPAD 3

#define _PRACTICE 4

#define _NIHON 5
#define _RED 6
#define _BLUE 7

#define _LOWER 8
#define _RAISE 9

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
[_BASE] = LAYOUT( \
              KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
              KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  MT(MOD_LCTL,KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
              KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT,KC_ENT) , \
              ADJUST, NIHON, KC_LGUI, KC_LALT,   LOWER,  KC_SPC,  KC_SPC,   RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),


/* GAME
 * ,-----------------------------------------------------------------------------------.
 * | F20  |      |      |      |      |      |      |      |      |      |      | Esc  |
 * |------+------+------+------+------+-------------+------+------+------+------+------| 
 * | Tab  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Sh/F21|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F22  | F23   | Alt  |Space |Shift |Space | NUMP |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_GAME] =  LAYOUT( \
              KC_F20,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ESC, \
              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
              KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  MT(MOD_LSFT,KC_F21), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
              _______,  KC_F22,  KC_F23, KC_LALT, KC_SPC, KC_LSFT,  _______, _______, _______, _______, _______, _______ \
),
//TT(_NUMPAD)



/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | NumL | /    | *    | -    | PrSc | ScLk |
 * |------+------+------+------+------+-------------+------+------+------+------+------| 
 * |      |      |      |      |      |      | 7    | 8    | 9    | +    | Home | PgUp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | 4    | 5    | 6    | +    | End  | PgDn |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | 1    | 2    | 3    | ENT  | Ins  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | 0    | GAME | .    | ENT  | Pause|Adjust|
 * `-----------------------------------------------------------------------------------'
 */





[_PRACTICE] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_PSCR, KC_SLCK, \
  _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_HOME, KC_PGUP, \
  _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_END,  KC_PGDN, \
  _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_INS,  KC_DEL, \
  _______, _______, _______, _______, _______, KC_LALT, KC_P0, _______,   KC_PDOT, KC_PENT, KC_PAUS, ADJUST \
),

// KC_MHEN


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
[_NIHON] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, RJ_DOT,  RJ_KA, RJ_TA, RJ_KO, RJ_SA, RJ_RA, RJ_TI, RJ_KU, RJ_TU, RJ_COMM, _______, \
  _______, RJ_U,    RJ_SI, RJ_TE, RJ_KE, RJ_SE, RJ_HA, RJ_TO, RJ_KI, RJ_I,  RJ_NN,   KC_SPC, \
  _______, _______, RJ_HI, RJ_SU, RJ_HU, RJ_HE, RJ_ME, RJ_SO, RJ_NE, RJ_HO, RJ_BLT,  _______, \
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
[_RED] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, RJ_XA,  RJ_E,  RJ_RI,  RJ_XYA, RJ_RE, RJ_PA, RJ_DI, RJ_GU, RJ_DU, RJ_PI,   _______, \
  _______, RJ_WO,  RJ_A,  RJ_NA,  RJ_XYU, RJ_MO, RJ_BA, RJ_DO, RJ_GI, RJ_PO, _______, _______, \
  _______, RJ_XU,  KC_MINS, RJ_RO, RJ_YA, RJ_XI, RJ_PU, RJ_ZO, RJ_PE, RJ_BO, _______, _______, \
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
[_BLUE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, RJ_GA, RJ_DA, RJ_GO, RJ_ZA, RJ_YO, RJ_NI, RJ_RU, RJ_MA,  RJ_XE,   _______, \
  _______, _______, RJ_ZI, RJ_DE, RJ_GE, RJ_ZE, RJ_MI, RJ_O,  RJ_NO, RJ_XYO, RJ_XTU, _______, \
  _______, _______, RJ_BI, RJ_ZU, RJ_BU, RJ_BE, RJ_NU, RJ_YU, RJ_MU, RJ_WA,  _______, _______,			\
  _______, LALT(KC_GRAVE), _______, _______, _______, _______,_______, _______, _______, _______, _______, _______ \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   §  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | rAlt |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_RALT, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 | F12  | F13  | F14  | F15  |      | Jp/En| PRCT |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Hue  | Sat  | Val  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | BASE |      |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_ESC,  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  TO(_GAME), TO(_NIHON), TO(_PRACTICE), TO(_BASE),  _______, _______, \
  _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, RGB_M_T, RGB_MOD, RGB_RMOD, RGB_TOG, _______, \
  _______, TO(_BASE), _______, _______, _______, _______, _______, _______, KC_HOME,  KC_PGDN, KC_PGUP, KC_END \
)

};

#define HSV_FAINTPINK 234, 128, 64
#define HSV_FAINTCORAL 11, 176, 128
#define HSV_FAINTGOLDENROD 30, 218, 64
#define HSV_FAINTORANGE 28, 255, 128
#define HSV_FAINTCHARTREUSE 64, 255, 128
#define HSV_FAINTCYAN 128, 255, 128
#define HSV_FAINTPURPLE 191, 255, 128
#define HSV_FAINTMAGENTA 213, 255, 128

const rgblight_segment_t PROGMEM base_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_FAINTPINK}
);
const rgblight_segment_t PROGMEM game_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_SPRINGGREEN}
);
const rgblight_segment_t PROGMEM numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 6, HSV_AZURE}
);
const rgblight_segment_t PROGMEM practice_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_GOLD}
);
const rgblight_segment_t PROGMEM nihon_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_FAINTPURPLE}
);
const rgblight_segment_t PROGMEM redshift_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_CORAL}
);
const rgblight_segment_t PROGMEM blueshift_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_CYAN}
);
const rgblight_segment_t PROGMEM lower_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 4, HSV_MAGENTA} 
);
const rgblight_segment_t PROGMEM raise_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 4, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM adjust_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 4, HSV_FAINTORANGE}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_lights,
    game_lights,
    practice_lights,
    nihon_lights,
    lower_lights,
    raise_lights,
    adjust_lights
);

void keyboard_post_init_user(void) {
  debug_enable=false;
  user_config.raw = eeconfig_read_user();


  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv(HSV_FAINTPINK);
  rgblight_layers = my_rgb_layers;
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


layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
  rgblight_set_layer_state(1, layer_state_cmp(state, _GAME));
  rgblight_set_layer_state(2, layer_state_cmp(state, _PRACTICE));
  rgblight_set_layer_state(3, layer_state_cmp(state, _NIHON));
  rgblight_set_layer_state(4, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(5, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(6, layer_state_cmp(state, _ADJUST));
  return state;
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
	//register_code(KC_LALT);
	//register_code(KC_LSHIFT);
      } else {
	//unregister_code(KC_LSHIFT);
	//unregister_code(KC_LALT);
	layer_off(_RED);
	layer_off(_BLUE);
	layer_off(_NIHON);
      }
      break;
    case NIHON:
      if (record->event.pressed) {
	//register_code(KC_LALT);
	//register_code(KC_LSHIFT);
      } else {
	//unregister_code(KC_LSHIFT);
	//unregister_code(KC_LALT);
	layer_on(_NIHON);
      }
      break;
    }
  }
  return true;
}

