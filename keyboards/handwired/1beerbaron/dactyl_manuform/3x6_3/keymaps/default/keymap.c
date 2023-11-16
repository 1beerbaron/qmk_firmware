// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
enum layers {
  _DEFAULT,
  _NUM,
  _SYM,
  _COMBO,
  _NAV,
  _FUNCTION,
  _RESETLEFT,
  _RESETRIGHT
};

#define BACK_TAB LSFT(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Blank
* ,------------------------------------------          ------------------------------------------.
* |      |      |      |      |      |      |          |      |      |      |      |      |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      |      |      |      |      |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      |      |      |      |      |      |
* `------------------------------------------          ------------------------------------------'
*                      |      |      |      |          |      |      |      |
*                      `---------------------          ---------------------'
*/

/*
*[_Blank] = LAYOUT_dactyl_3x6_3(
* KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
* KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
* KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
*                            KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO
*),
*/
    
    
    
    
/* _DEFAULT
* ,------------------------------------------          ------------------------------------------.
* | (_FUNCTION) |   J  |   C  |   Y  |   F  |   K  |          |   Z  |   L  | , <  |   U  |   Q  | Win+Alt+K (Mute) |
* |------------------------------------------          ------------------------------------------|
* |BackTab|   R  |   S  |   T  |   H  |   P  |          |   W  |   N  |   A  |   I  |   I  | ' "  |
* |------------------------------------------          ------------------------------------------|
* |  Esc | / ? |   V  |   G  |   D  |   B  |          |   X  |   M  | . >  |  ; : |  \ | | Ctrl+Alt+Del |
* `------------------------------------------          ------------------------------------------'
*                      |BackSpace (_COMBO)|   E (_NUM) |  Tab |          | Enter| Space (_SYM) |  Del (_NAV) |
*                      `---------------------          ----------------------'
*/
[_DEFAULT] = LAYOUT_dactyl_3x6_3(
    MO(_FUNCTION), KC_J, KC_C, KC_Y, KC_F, KC_K,          KC_Z, KC_L, KC_COMMA, KC_U, KC_Q, LAG(KC_K),
    BACK_TAB, MT(MOD_LGUI, KC_R), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_T), MT(MOD_LCTL, KC_H), KC_P,          KC_W, MT(MOD_RCTL, KC_N), MT(MOD_RSFT, KC_A), MT(MOD_LALT, KC_I), MT(MOD_RGUI, KC_O), KC_QUOT,
    KC_ESC, KC_SLSH, KC_V, KC_G, KC_D, KC_B,          KC_X, KC_M, KC_DOT, KC_SCLN, KC_BSLS, LCA(KC_DEL),
                               LT(_COMBO, KC_BSPC), LT(_NUM, KC_E), KC_TAB,          KC_ENT, LT(_SYM, KC_SPC), LT(_NAV, KC_DEL)
),

/* _NUM
* ,------------------------------------------          ------------------------------------------.
* |      |      |      |      |      |      |          |      |   7  |   8  |   9  |      |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |   *  |   4  |   5  |   6  |   +  |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |   /  |   1  |   2  |   3  |   -  |      |
* `------------------------------------------          ------------------------------------------'
*                      |      |      |      |          |      |   0  |   .   |
*                      `---------------------          ----------------------'
*/


[_NUM] = LAYOUT_dactyl_3x6_3(
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO,
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_KP_ASTERISK, KC_4, KC_5, KC_6, KC_KP_PLUS, KC_NO,
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_KP_SLASH, KC_1, KC_2, KC_3, KC_KP_MINUS, KC_NO,
                            KC_NO, KC_TRNS, KC_NO,          KC_NO, KC_0, KC_PDOT
),

/* _SYM
* ,------------------------------------------          ------------------------------------------.
* |      |   {  |   }  |   [  |   ]  |      |          |      |      |      |      |      |      |
* |------------------------------------------          ------------------------------------------|
* |      |   !  |   =  |   $  |   _  |   #  |          |      |      |      |      |      |      |
* |------------------------------------------          ------------------------------------------|
* |      |   `  |   @  |   %  |   &  |   ^  |          |      |      |      |      |      |      |
* `------------------------------------------          ------------------------------------------'
*                      |   (  |   )  |   ~  |          |      | TRNS |      |
*                      `---------------------          ---------------------'
*/

[_SYM] = LAYOUT_dactyl_3x6_3(
 KC_NO, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_EXCLAIM, KC_EQUAL, KC_DOLLAR, KC_UNDERSCORE, KC_HASH,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_GRAVE, KC_AT, KC_PERCENT, KC_AMPERSAND, KC_CIRCUMFLEX,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_TILDE,          KC_NO, KC_TRNS, KC_NO
),

/* _COMBO
* ,------------------------------------------          ------------------------------------------.
* |      |      |      |      |      |      |          |      | Caps Word | Caps Lock |      |      | Ctrl+Shift+Enter |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          | Win+R | Ctrl+X | Ctrl+C | Ctrl+V | Menu | Crtl+Shift+Esc (Task Manager) |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      | Ctrl+Z | Ctrl+Y | Insert | Scroll Lock | Pause |
* `------------------------------------------          ------------------------------------------'
*                      | TRNS |      |      |          |      | Ctrl+A | Prnt Scrn |
*                      `---------------------          ---------------------'
*/

[_COMBO] = LAYOUT_dactyl_3x6_3(
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, QK_CAPS_WORD_TOGGLE, KC_CAPS_LOCK, KC_NO, KC_NO, RCS(KC_ENTER),
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          LGUI(KC_R), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_APPLICATION, RCS(KC_ESCAPE),
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, LCTL(KC_Z), LCTL(KC_Y), KC_INSERT, KC_SCROLL_LOCK, KC_PAUSE,
                            KC_TRNS, KC_NO, KC_NO,          KC_NO, LCTL(KC_A), KC_PRINT_SCREEN
),

/* _NAV
* ,------------------------------------------          ------------------------------------------.
* |      | Home |Pg Up |Pg Down| End |      |          |      |      |      |      |      |(_RESETRIGHT)|
* |------------------------------------------          ------------------------------------------|
* |      | Left | Down |  Up  | Right|      |          |      |      | Shift|      |      |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      |      |      |      |      |      |
* `------------------------------------------          ------------------------------------------'
*                      |      |      |      |          |      |      | TRNS |
*                      `---------------------          ---------------------'
*/

[_NAV] = LAYOUT_dactyl_3x6_3(
 KC_NO, KC_HOME, KC_PAGE_UP, KC_PAGE_DOWN, KC_END, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(_RESETRIGHT),
 KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO,          KC_NO, KC_NO, KC_RIGHT_SHIFT, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_TRNS
),

/* _FUNCTION
* ,------------------------------------------          ------------------------------------------.
* | TRNS |      |      |      |      |(_RESETLEFT)|          |      |  F9  |  F10 |  F11 |  F12 |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      |  F5  |  F6  |  F7  |  F8  |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      |  F1  |  F2  |  F3  |  F4  |      |
* `------------------------------------------          ------------------------------------------'
*                      |      |      |      |          |      |      |      |
*                      `---------------------          ---------------------'
*/

[_FUNCTION] = LAYOUT_dactyl_3x6_3(
 KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, MO(_RESETLEFT),          KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO,
                            KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO
),

/* _RESETLEFT
* ,------------------------------------------          ------------------------------------------.
* | TRNS |      |      |      |      | TRNS |          |      |      |      |      |      |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      |      |      |      |      |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      |      |      |      |      |      |
* `------------------------------------------          ------------------------------------------'
*                      |      |      | Reset |          |      |      |      |
*                      `---------------------          ---------------------'
*/

[_RESETLEFT] = LAYOUT_dactyl_3x6_3(
 KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, QK_BOOTLOADER,          KC_NO, KC_NO, KC_NO
),

/* _RESETRIGHT
* ,------------------------------------------          ------------------------------------------.
* |      |      |      |      |      |      |          | Reset |      |      |      |      | TRNS |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      |      |      |      |      |      |
* |------------------------------------------          ------------------------------------------|
* |      |      |      |      |      |      |          |      |      |      |      |      |      |
* `------------------------------------------          ------------------------------------------'
*                      |      |      |      |          |      |      | TRNS |
*                      `---------------------          ---------------------'
*/

[_RESETRIGHT] = LAYOUT_dactyl_3x6_3(
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          QK_BOOTLOADER, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_TRNS
)
};