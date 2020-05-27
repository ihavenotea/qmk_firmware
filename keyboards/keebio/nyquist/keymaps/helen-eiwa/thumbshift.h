/* Mapping to emulate Thumbshift Kana.
 * 
 * JIS direct (prefixed with "JP") and Romaji (prefixed with "RJ")
 * conversion variants.
 *
 */

enum thumbshift_macro_keycodes {
  JISTHUMBMACROS = SAFE_RANGE,
  FHK_JISMODE,
  FHK_ENMODE,
  FHK_RJ_TOGGLE,
  FHK_ZKHK,
  FHK_JISCAPS,
  FHK_MACRO_END
};



/* Romaji Expansion
 * 
 * Provides for simple macro driven expansion keystrokes into their
 * Kunrei-shiki romanization. An IME will then convert them into
 * kana. This can be used with a US keyboard; either for thumbshift,
 * or to emulate a JIS style layout (though for the later, there are
 * better options).
 *
 */

// Simple Romaji Mappings
#define RJ_A KC_A
#define RJ_I KC_I
#define RJ_U KC_U
#define RJ_E KC_E
#define RJ_O KC_O
#define RJ_COMM KC_COMM
#define RJ_DOT KC_DOT
#define RJ_BLT KC_SLSH

// Macro Romaji Keycodes
enum romaji_thumbshift_keycodes {
  RJ_RANGE_START = FHK_MACRO_END,
  RJ_KA, RJ_KI, RJ_KU, RJ_KE, RJ_KO,
  RJ_GA, RJ_GI, RJ_GU, RJ_GE, RJ_GO,
  RJ_SA, RJ_SI, RJ_SU, RJ_SE, RJ_SO,
  RJ_ZA, RJ_ZI, RJ_ZU, RJ_ZE, RJ_ZO,
  RJ_TA, RJ_TI, RJ_TU, RJ_TE, RJ_TO,
  RJ_DA, RJ_DI, RJ_DU, RJ_DE, RJ_DO,
  RJ_NA, RJ_NI, RJ_NU, RJ_NE, RJ_NO,
  RJ_HA, RJ_HI, RJ_HU, RJ_HE, RJ_HO,
  RJ_BA, RJ_BI, RJ_BU, RJ_BE, RJ_BO,
  RJ_PA, RJ_PI, RJ_PU, RJ_PE, RJ_PO,
  RJ_MA, RJ_MI, RJ_MU, RJ_ME, RJ_MO,
  RJ_YA,        RJ_YU,        RJ_YO,
  RJ_RA, RJ_RI, RJ_RU, RJ_RE, RJ_RO,
  RJ_WA,                      RJ_WO,
  RJ_NN,
  RJ_XA, RJ_XI, RJ_XU, RJ_XE, RJ_XO,
  RJ_XTU,
  RJ_XYA,       RJ_XYU,       RJ_XYO,
  RJ_RANGE_END
};



/* JIS Mappings
 * 
 * These mappings allow for single keycodes to represent characters
 * with dakuten. This is handled with macros. There are further macros
 * to wrap the HKEN and CAPS keys in order to force QWERTY layout when
 * quickly switching between kana and romaji. _There are some subtle
 * issues with this. Use care._
 *
 */

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

#define JP_COMM KC_LABK
#define JP_DOT KC_RABK
#define JP_BLT KC_QUES

#define JP_ITER SAFE_RANGE

// Macro JIS Keycodes
enum jis_thumbshift_keycodes {
  JP_RANGE_START = RJ_RANGE_END,

  JP_GA, JP_GI, JP_GU, JP_GE, JP_GO,
  JP_ZA, JP_ZI, JP_ZU, JP_ZE, JP_ZO,
  JP_DA, JP_DI, JP_DU, JP_DE, JP_DO,
  JP_BA, JP_BI, JP_BU, JP_BE, JP_BO,
  JP_PA, JP_PI, JP_PU, JP_PE, JP_PO,
  JP_RANGE_END,

  THUMBSHIFT_SAFE_RANGE
};
