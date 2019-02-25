#include "daktil.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------.              ,-----------------------------------------.
 * |   =  |   Q  |   W  |   E  |   R  |   T  |              |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | LSft |   A  |   S  |   D  |   F  |   G  |              |   H  |   J  |   K  |   L  |; / L2| RSft |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |  L1  |Z/Ctrl|   X  |   C  |   V  |   B  |              |   N  |   M  |   ,  |   .  |//Ctrl|  L1  |
 * `------+------+------+------+------+------'              `------+------+------+------+------+------'
 *               |  <-  |  ->  |                                          |   [  |   ]  |
 *               `-------------'                                          `-------------'
 *                           ,------,------.                   ,------------.
 *                           |      |      |                   |      |     |
 *                           |  Spc | Bksp |-----.       ,-----+  Tab |Enter|
 *                           |      |      |Esc/m|       |Esc/m|      |     |
 *                           |------+------+-----|       |-----+------+-----|
 *                           | Lalt |  End |Home |       | PgUp| PgDn | Ralt|
 *                           `------+------+-----'       `-----+------+-----'
 */
[BASE] = LAYOUT_dactyl(  // layer 0 : default
        // left hand
          KC_DELT,        KC_1,           KC_2,     KC_3,     KC_4,  KC_5,  // this line is missing
          KC_EQL,         KC_Q,           KC_W,     KC_E,     KC_R,  KC_T,
          KC_LSPO,        CTL_T(KC_A),    KC_S,     KC_D,     KC_F,  KC_G,
          LT(SYMB,KC_GRV), ALT_T(KC_Z),   KC_X,     KC_C,     KC_V,  KC_B,
          KC_TRNS,        KC_TRNS,        KC_LEFT,  KC_RGHT,  KC_TRNS,

                                                            KC_BSPC,
                                                   KC_SPC,
                                                                    LGUI_T(KC_ESC),
                                                          KC_HOME,  RALT_T(KC_APP),
                                                                           KC_END,
        // right hand
                             KC_6,   KC_7,     KC_8,     KC_9,               KC_0,         KC_MINS,  // this line is missing
                             KC_Y,   KC_U,     KC_I,     KC_O,     LT(MDIA, KC_P),         KC_BSLS,
                             KC_H,   KC_J,     KC_K,     KC_L,     CTL_T(KC_SCLN),         KC_RSPC,
                             KC_N,   KC_M,  KC_COMM,   KC_DOT,     ALT_T(KC_SLSH),LT(SYMB,KC_QUOT),
                                  KC_TRNS,  KC_LBRC,  KC_RBRC,            KC_TRNS,         KC_TRNS,

                                   KC_ENT,
                          KC_TAB,
          LGUI_T(KC_ESC),
                               RALT_T(KC_APP),
                         KC_PGDN,
                 KC_PGUP
    ),
/* Keymap 1: Symbol Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | VRSN |   !  |   @  |   {  |   }  |   |  |                    |  Up  |   7  |   8  |   9  |   *  |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LShft|   #  |   $  |   (  |   )  |   `  |                    | Down |   4  |   5  |   6  |   +  | RShft|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|   %  |   ^  |   [  |   ]  |   ~  |                    |   &  |   1  |   2  |   3  |   -  |  L0  |
 * `------+------+------+------+------+------'                    `------+------+------+------+------+------'
 *               |   <  |   >  |                                                |   .  |   0  |
 *               `-------------'                                                `-------------'
 *                              ,------,------.                   ,------------.
 *                              |      |      |                   |      |     |
 *                              | Enter| Bksp |-----.       ,-----+  Tab | Spc |
 *                              |      |      |Esc/m|       |Esc/m|      |     |
 *                              |------+------+-----|       |-----+------+-----|
 *                              | Lalt |  End |Home |       | PgUp| PgDn | Ralt|
 *                              `------+------+-----'       `-----+------+-----'
 */
// SYMBOLS
[SYMB] = LAYOUT_dactyl(
       // left hand
          VRSN,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
          VRSN,  KC_EXLM,    KC_AT,  KC_LCBR,  KC_RCBR,  KC_PIPE,
       KC_TRNS,  KC_HASH,   KC_DLR,  KC_LPRN,  KC_RPRN,   KC_GRV,
         RESET,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,
         RESET,  KC_TRNS,    KC_LT,    KC_GT,  KC_TRNS,
                                                         KC_TRNS,  KC_ENT,
                                                                   KC_TRNS,
                                               KC_EQL,  KC_TRNS,  KC_PLUS,
       // right hand
                KC_F6,      KC_F7,   KC_F8, KC_F9,  KC_F10,   KC_F11,
                KC_UP,       KC_7,    KC_8,  KC_9, KC_ASTR,   KC_QUOT,
                KC_DOWN,     KC_4,    KC_5,  KC_6, KC_PLUS,  KC_TRNS,
                KC_AMPR,     KC_1,    KC_2,  KC_3, KC_MINS,  KC_TRNS,
                          KC_TRNS,  KC_DOT,  KC_0,  KC_EQL,  KC_TRNS,
      KC_SPC,  KC_TRNS,
      KC_TRNS,
          KC_TRNS,  KC_UNDS,  KC_MINS
),
/* Keymap 2: Media and mouse keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | VolU |      | MsUp |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | VolD |MsLeft|MsDown|MsRght|      |                    |      |      |      |      |      | Play |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | MUTE |      |      |      |      |                    |      |      | Prev | Next |      |      |
 * `------+------+------+------+------+------'                    `------+------+------+------+------+------|
 *               |      | Lclk |                                                | VolUp| VolDn|
 *               `-------------'                                                `-------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |Brwser|
 *                               | Lclk | Rclk |------|  |------|      |Back  |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 *
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_dactyl(
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_VOLU,  KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_TRNS,
       KC_TRNS,  KC_VOLD,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,
       KC_TRNS,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                         KC_TRNS,  KC_BTN2,
                                                                   KC_BTN1,
                                               KC_WH_U,  KC_TRNS,  KC_WH_D,
    // right hand
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,
                KC_LEFT,  KC_DOWN,    KC_UP,  KC_RIGHT, KC_TRNS,  KC_MPLY,
                KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_TRNS,  KC_TRNS,
                          KC_VOLU,  KC_VOLD,  KC_MUTE,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,
      KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {};
