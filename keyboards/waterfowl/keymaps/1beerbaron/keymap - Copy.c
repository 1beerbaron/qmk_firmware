/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUM,
    _SYM,
    _NAV,
    _COMBO,
    _FUNC,
};

// Tap Dance declarations
enum {
    TD_PAREN,
    TD_CURLY_BRACE,
    TD_BRACKET,
    TD_TAB_BACKTAB
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for open parenthesis, twice for close parenthesis
    [TD_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    // Tap once for open curly brace, twice for close curly brace
    [TD_CURLY_BRACE] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    // Tap once for open bracket, twice for close bracket
    [TD_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    // Tap once for open bracket, twice for close bracket
    [TD_TAB_BACKTAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, BACK_TAB),
};

const uint16_t PROGMEM LAYER_COMBO[] = {MT(MOD_LSFT, KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM LAYER_NUM[] = {MT(MOD_LCTL, KC_H), KC_D, COMBO_END};
const uint16_t PROGMEM LAYER_SYM[] = {MT(MOD_RSFT, KC_A), KC_DOT, COMBO_END};
const uint16_t PROGMEM LAYER_NAV[] = {MT(MOD_LCTL, KC_N), KC_M, COMBO_END};
const uint16_t PROGMEM LAYER_FUNC[] = {MT(MOD_LSFT, KC_T), KC_Y, COMBO_END};
combo_t key_combos[] = {
    COMBO(LAYER_COMBO, MO(_COMBO)),
    COMBO(LAYER_NUM, MO(_NUM)), // keycodes with modifiers are possible too!
    COMBO(LAYER_SYM, MO(_SYM)),
    COMBO(LAYER_NAV, MO(_NAV)),
	COMBO(LAYER_FUNC, MO(_FUNC)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |CAPS |    |NUMLK|  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_BASE] = LAYOUT(
	    KC_J,               KC_C,               KC_Y,				KC_F,				KC_K,                               KC_Z,       KC_L,				KC_COMMA,			KC_U,				KC_Q,
	    MT(MOD_LGUI, KC_R), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_T),	MT(MOD_LCTL, KC_H),	KC_P,                               KC_W,       MT(MOD_LCTL, KC_N), MT(MOD_RSFT, KC_A), MT(MOD_LALT, KC_I),	MT(MOD_LGUI, KC_O),
	    KC_QUESTION,        KC_V,				KC_G,				KC_D,				KC_B,                               KC_X,	    KC_M,				KC_DOT,			    KC_SEMICOLON,		KC_QUOTE,
	KC_NO,                                      KC_BACKSPACE,		KC_E,               KC_TAB, MO(_FUNC),  KC_AUDIO_MUTE,  KC_ENTER,   KC_SPACE,			KC_DELETE,		                                            KC_NO
),

/* NUM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      | PgUp |  UP  | PgDn |      |                      |   /  |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | Home | Left | Down | Right| End  |                      |   =  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |  INS |      |      |  |CAPS |    |NUMLK|  |   0  |   1  |   2  |   3  |   *  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_NUM] = LAYOUT(
	        KC_NO,	    KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_EQL,     KC_7,   KC_8,   KC_9,   KC_TRNS,
	        KC_NO,	    KC_NO,      KC_NO,      KC_TRNS,      KC_NO,                      KC_ASTR,    KC_4,   KC_5,   KC_6,   KC_PLUS,
	        KC_NO,	    KC_NO,      KC_NO,      KC_TRNS,      KC_NO,				        KC_SLSH,    KC_1,   KC_2,   KC_3,   KC_MINS,
	KC_NO,	                        KC_NO,      KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_ENTER,	KC_0,   KC_DOT,                     KC_NO
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   %  |   @  |   [  |   ]  |   \  |                      |      |      |   ^  |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   #  |   !  |   (  |   )  |   |  |                      |   _  |   '  |   "  |   ~  |   `  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   $  |   £  |   {  |   }  |   &  |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_SYM] = LAYOUT(
	        KC_CIRCUMFLEX,  KC_GRAVE,   KC_TILDE,       KC_EXCLAIM,     KC_NO,                              KC_NO,      KC_NO,      KC_NO,  KC_NO,  KC_NO,
	        KC_UNDERSCORE,  KC_DOLLAR,  KC_PIPE,        KC_HASH,        KC_BACKSLASH,                       KC_NO,      KC_NO,      KC_TRNS,  KC_NO,  KC_NO,
	        KC_AT,          KC_PERCENT, KC_EQUAL,       KC_AMPERSAND,   KC_SLASH,                           KC_NO,      KC_NO,      KC_TRNS,  KC_NO,  KC_NO,
	KC_NO,                               TD(TD_BRACKET), TD(TD_PAREN),   TD(TD_CURLY_BRACE), KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,                  KC_NO
),

/* NAV
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      | PgUp |  UP  | PgDn |      |                      |   /  |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | Home | Left | Down | Right| End  |                      |   =  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |  INS |      |      |  |CAPS |    |NUMLK|  |   0  |   1  |   2  |   3  |   *  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_NAV] = LAYOUT(
	        KC_HOME,    KC_PAGE_DOWN,   KC_PAGE_UP, KC_END,     KC_NO,                  KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,
	        KC_LEFT,	KC_DOWN,        KC_UP,      KC_RGHT,    KC_NO,                  KC_NO,  KC_TRNS,    KC_LSFT,    KC_LALT,    KC_LGUI,
	        KC_NO,		KC_NO,          KC_NO,      KC_ESCAPE,      KC_NO,                  KC_NO,  KC_TRNS,      KC_NO,      KC_NO,      KC_NO,
	KC_NO,                              KC_NO,      KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,                        KC_NO
),

/* COMBO
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      | PgUp |  UP  | PgDn |      |                      |   /  |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | Home | Left | Down | Right| End  |                      |   =  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |  INS |      |      |  |CAPS |    |NUMLK|  |   0  |   1  |   2  |   3  |   *  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_COMBO] = LAYOUT(
	        KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,                  KC_NO,          QK_CAPS_WORD_TOGGLE,    KC_CAPS_LOCK,   KC_SCROLL_LOCK, KC_PAUSE,
	        KC_NO,  KC_NO,  KC_TRNS,      KC_NO,      KC_NO,                  KC_NO,          LCTL(KC_A),             LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),
	        KC_NO,  KC_NO,  KC_TRNS,      KC_NO,      KC_NO,                  KC_NO,          LCTL(KC_Z),             LCTL(KC_Y),     KC_INSERT,      RCS(KC_ESC),
	KC_NO,                  KC_NO,    KC_NO,	KC_NO,  KC_NO,  KC_NO,  RCS(KC_ENTER),  KC_PRINT_SCREEN,        LGUI(KC_R),                                   KC_NO
),

/* FUNC
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |      |  F7  |  F8  |  F9  |  F11 |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      |      |      |      |      |                      |      |  F4  |  F5  |  F6  |  F12 |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * | Reset|      |      |      |      |  |CAPS |    |NUMLK|  |  F10 |  F1  |  F2  |  F3  |  F13 |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_FUNC] =  LAYOUT(
	        KC_NO,      KC_NO,      KC_TRNS,      KC_NO,      KC_NO,                      KC_NO,	KC_F9,  KC_F10, KC_F11, KC_F12,
	        KC_LGUI,    KC_LALT,    KC_TRNS,    KC_LCTL,    KC_NO,                      KC_NO,	KC_F5,  KC_F6,  KC_F7,  KC_F8,
	        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_NO,	KC_F1,  KC_F2,  KC_F3,  KC_F4,
	KC_NO,                          KC_NO,      KC_NO,      KC_NO,  KC_NO,    KC_NO,  KC_NO,	KC_NO,  KC_NO,                  KC_NO
),
};
