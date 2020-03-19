#include QMK_KEYBOARD_H
#include "thumbshift.c"

// FHK Where does this need to be?
#define RJM(X) (X - RJ_RANGE_START)


static inline bool process_record_romaji(uint16_t keycode, keyrecord_t *record) {
  if (keycode > RJ_RANGE_START && keycode < RJ_RANGE_END) {
    if (record->event.pressed) {
      uint16_t k = RJM(keycode);
      send_string(romajimap[k]);
    }
  }
  return true;
}

