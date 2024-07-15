/*

                                        █         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
                                        █        █     █          ▄▀            ▀▄      █          █
                                        █       █      █        ▄▀                ▀▄    █          █
                                        █      █       █        █                  █    █          █
                                        █     █        █       █                    █   █          █
                                        █    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
                                        █   █ █        █       █                    █   █      █
                                        █  █   █       █        █                  █    █       █
                                        █ █     █      █        ▀▄                ▄▀    █        █
                                        ██       █     █          ▀▄            ▄▀      █         █
                                        █         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █

                                        ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
                                        D E F A U L T

*/
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "features/achordion.h"
#include "features/hrm.h"


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e c l a r e   l a y e r s                               │
// └───────────────────────────────────────────────────────────┘ 

enum klor_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    /* _COLEMAK, */
    _SYM,
    _NUM,
    _NAV,
    _ADJ,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e c l a r e   k e y c o d e s                           │
// └───────────────────────────────────────────────────────────┘

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    /* COLEMAK, */
    SYM,
    NUM,
    NAV,
    OS_SWAP,
    SHT_T,
    SHT_N,
    MAKE_H,
    VIM_TOP,
    VIM_INC,
    VIM_DEC,
    MACRO_PARENTHESES,
    MACRO_BRACKETS,
    MACRO_CURLYBRACES,
    MACRO_SINGLEQUOTES,
    MACRO_DOUBLEQUOTES,
};
//
// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// MOD-TAP KEYS ├──────────────────────────────────────────────┐

// LAYER-TAP KEYS ├────────────────────────────────────────────┐

#define NUM_ENT LT(_NUM, KC_ENT)
#define SYM_SPC LT(_SYM, KC_SPC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define NAV_BSP LT(_NAV, KC_BSPC)

// TAP-DANCE KEYS ├────────────────────────────────────────────┐

#define TD_AESC TD(A_ESC)

// ONE-SHOT KEYS ├────────────────────────────────────────────┐

#define OSM_SFT OSM(MOD_LSFT)

// German characters - assuming 'setxkbmap de us' is set in linux
#define KC_EURO RALT(KC_E)
#define KC_AE RALT(KC_A)
#define KC_OE RALT(KC_O)
#define KC_UE RALT(KC_U)
#define KC_SZ RALT(KC_S)

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   t a p   d a n c e   f u n c t i o n s       │
// └───────────────────────────────────────────────────────────┘

/* enum { */
/*   A_ESC = 0 */
/* }; */

/* tap_dance_action_t tap_dance_actions[] = { */
/*   //Tap once for Esc, twice for Caps Lock */
/*   [A_ESC]  = ACTION_TAP_DANCE_DOUBLE(A_HRM, KC_ESC) */
/* // Other declarations would go here, separated by commas, if you have them */
/* }; */

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   c o m b o s                                 │
// └───────────────────────────────────────────────────────────┘

// MODS
const uint16_t PROGMEM esc_onehand_combo[] = {S_HRM, D_HRM, COMBO_END};
const uint16_t PROGMEM esc_twohand_combo[] = {F_HRM, J_HRM, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_Q, KC_P, COMBO_END};

// SYMBOLS
const uint16_t PROGMEM plus_combo[] = {J_HRM, K_HRM, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {K_HRM, L_HRM, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {J_HRM, K_HRM, L_HRM, COMBO_END};
const uint16_t PROGMEM asterisk_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM equal_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM singlequote_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM doublequote_combo[] = {KC_I, KC_O, COMBO_END};
/* const uint16_t PROGMEM lparenthesis_combo[] = {J_HRM, K_HRM, COMBO_END}; */
/* const uint16_t PROGMEM rparenthesis_combo[] = {K_HRM, L_HRM, COMBO_END}; */
/* const uint16_t PROGMEM parentheses_combo[] = {J_HRM, L_HRM, COMBO_END}; */
/* const uint16_t PROGMEM lbracket_combo[] = {KC_M, KC_COMMA, COMBO_END}; */
/* const uint16_t PROGMEM rbracket_combo[] = {KC_COMMA, KC_DOT, COMBO_END}; */
/* const uint16_t PROGMEM brackets_combo[] = {KC_M, KC_DOT, COMBO_END}; */
/* const uint16_t PROGMEM lcurlybrace_combo[] = {KC_4, KC_5, COMBO_END}; */
/* const uint16_t PROGMEM rcurlybrace_combo[] = {KC_5, KC_6, COMBO_END}; */
/* const uint16_t PROGMEM curlybraces_combo[] = {KC_4, KC_6, COMBO_END}; */
/* const uint16_t PROGMEM singlequotes_combo[] = {KC_W, KC_R, COMBO_END}; */
/* const uint16_t PROGMEM doublequotes_combo[] = {S_HRM, F_HRM, COMBO_END}; */
combo_t key_combos[] = {
    // MODS
    COMBO(esc_onehand_combo, KC_ESC),
    COMBO(esc_twohand_combo, KC_ESC),
    COMBO(capslock_combo, KC_CAPS),

    // SYMBOLS
    COMBO(plus_combo, KC_PLUS),
    COMBO(minus_combo, KC_MINUS),
    COMBO(underscore_combo, KC_UNDS),
    COMBO(asterisk_combo, KC_ASTERISK),
    COMBO(equal_combo, KC_EQUAL),
    COMBO(singlequote_combo, KC_QUOTE),
    COMBO(doublequote_combo, KC_DOUBLE_QUOTE),
    /* COMBO(lparenthesis_combo, KC_LEFT_PAREN), */
    /* COMBO(rparenthesis_combo, KC_RIGHT_PAREN), */
    /* COMBO(parentheses_combo, MACRO_PARENTHESES), */
    /* COMBO(lbracket_combo, KC_LEFT_BRACKET), */
    /* COMBO(rbracket_combo, KC_RIGHT_BRACKET), */
    /* COMBO(brackets_combo, MACRO_BRACKETS), */
    /* COMBO(lcurlybrace_combo, KC_LEFT_CURLY_BRACE), */
    /* COMBO(rcurlybrace_combo, KC_RIGHT_CURLY_BRACE), */
    /* COMBO(curlybraces_combo, MACRO_CURLYBRACES), */
    /* COMBO(singlequotes_combo, MACRO_SINGLEQUOTES), */
    /* COMBO(doublequotes_combo, MACRO_DOUBLEQUOTES), */
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y   o v e r r i d e s                   │
// └───────────────────────────────────────────────────────────┘

const key_override_t delete_override = ko_make_basic(MOD_MASK_SHIFT, NAV_BSP, KC_DEL);
const key_override_t mplay_override = ko_make_basic(MOD_MASK_SHIFT, KC_MUTE, KC_MPLY);
// This globally defines all key overrides to be used ├────────┐
const key_override_t **key_overrides = (const key_override_t *[]){
  &delete_override,
  &mplay_override,
  NULL // Null terminate the array of overrides!
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   s o u n d s                                 │
// └───────────────────────────────────────────────────────────┘

#ifdef AUDIO_ENABLE
  #define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)
  #define MAC_SOUND S__NOTE(_CS5), B__NOTE(_C5)
 
  float winxp_song[][2] = SONG(WINXP_SOUND);
  float mac_song[][2] = SONG(MAC_SOUND);
#endif // AUDIO_ENABLE

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                               │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ q w e r t y                                               │
   └───────────────────────────────────────────────────────────┘
   ┌───────────┬───────────┬───────────┬───────────┬───────────┐                        ┌───────────┬───────────┬───────────┬───────────┬───────────┐
   │     Q     │     W     │     E     │     R     │     T     │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │     Y     │     U     │     I     │     O     │     P     │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┤
   │   A/HRM   │   S/HRM   │   D/HRM   │   F/HRM   │     G     ├─╯                    ╰─┤     H     │   J/HRM   │   K/HRM   │   L/HRM   │   :/HRM   │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤╭──────────╮╭──────────╮├───────────┼───────────┼───────────┼───────────┼───────────┤
   │     Z     │     X     │     C     │     V     │     B     ││  Ctrl+W  ││   Mute   ││     N     │     M     │     ,     │     .     │     /     │
   └───────────┴───────────┴───────────┼───────────┼───────────┤╰──────────╯╰──────────╯├───────────┼───────────┼───────────┴───────────┴───────────┘
                                       │  TT NAV   │ Tab/Shift │ Enter/NUM ││ Space/SYM │   Shift   │  Esc/NAV  │
                                       └───────────┴───────────┴───────────┘└───────────┴───────────┴───────────┘ */

   [_QWERTY] = LAYOUT_saegewerk(
    KC_Q     ,  KC_W     ,  KC_E     ,  KC_R     ,  KC_T     ,                           KC_Y     ,  KC_U     ,  KC_I     ,  KC_O     ,  KC_P     ,
    A_HRM    ,  S_HRM    ,  D_HRM    ,  F_HRM    ,  KC_G     ,                           KC_H     ,  J_HRM    ,  K_HRM    ,  L_HRM    ,  COLON_HRM,
    KC_Z     ,  KC_X     ,  KC_C     ,  KC_V     ,  KC_B     ,  VIM_TOP  ,   KC_MUTE  ,  KC_N     ,  KC_M     ,  KC_COMM  ,  KC_DOT   ,  KC_SLSH  ,
                                        XXXXXXX  ,  NAV_TAB  ,  NUM_ENT  ,   SYM_SPC  ,  NAV_BSP  ,  XXXXXXX
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ c o l e m a k ( - d h )                                   │
   └───────────────────────────────────────────────────────────┘
   ┌───────────┬───────────┬───────────┬───────────┬───────────┐                        ┌───────────┬───────────┬───────────┬───────────┬───────────┐
   │     Q     │     W     │     F     │     P     │     B     │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │     J     │     L     │     U     │     Y     │     ;     │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┤
   │   A/HRM   │   R/HRM   │   S/HRM   │   T/HRM   │     G     ├─╯                    ╰─┤     M     │   N/HRM   │   E/HRM   │   I/HRM   │   O/HRM   │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤╭──────────╮╭──────────╮├───────────┼───────────┼───────────┼───────────┼───────────┤
   │     Z     │     X     │     C     │     V     │     B     ││Play/Pause││   Mute   ││     K     │     H     │     ,     │     .     │     /     │
   └───────────┴───────────┴───────────┼───────────┼───────────┤╰──────────╯╰──────────╯├───────────┼───────────┼───────────┴───────────┴───────────┘
                                       │Toggle NAV │  Tab/NAV  │ Enter/NUM ││ Space/SYM │ Backspace │           │
                                       └───────────┴───────────┴───────────┘└───────────┴───────────┴───────────┘ */

 /*   [_COLEMAK] = LAYOUT_saegewerk( */
 /* //╷           ╷           ╷           ╷           ╷           ╷           ╷╷           ╷           ╷           ╷           ╷           ╷           ╷ */
 /*    KC_Q     ,  KC_W     ,  KC_E     ,  KC_R     ,  KC_T     ,                           KC_Y     ,  KC_U     ,  KC_I     ,  KC_O     ,  KC_P     , */
 /*    KC_A     ,  KC_S     ,  KC_D     ,  KC_F     ,  KC_G     ,                           KC_H     ,  KC_J     ,  KC_K     ,  KC_L     ,  KC_SCLN  , */
 /*    KC_Z     ,  KC_X     ,  KC_C     ,  KC_V     ,  KC_B     ,  KC_MPLY  ,   KC_MUTE  ,  KC_N     ,  KC_M     ,  KC_COMM  ,  KC_DOT   ,  KC_SLSH  , */
 /*                                        _______  ,  KC_TAB   ,  KC_ENT   ,   KC_SPC   ,  KC_BSPC  ,  _______ */
 /* ), */

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌───────────────────────────────────────────────────────────┐
   │ s y m b o l s                                             │
   └───────────────────────────────────────────────────────────┘
   ┌───────────┬───────────┬───────────┬───────────┬───────────┐                        ┌───────────┬───────────┬───────────┬───────────┬───────────┐
   │     ~     │     `     │           │     ^     │           │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │           │           │           │           │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┤
   │     !     │     @     │     #     │     $     │     %     ├─╯                    ╰─┤           │           │           │           │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤╭──────────╮╭──────────╮├───────────┼───────────┼───────────┼───────────┼───────────┤
   │           │           │     |     │     &     │           ││          ││          ││           │           │           │           │           │
   └───────────┴───────────┴───────────┼───────────┼───────────┤╰──────────╯╰──────────╯├───────────┼───────────┼───────────┴───────────┴───────────┘
                                       │           │           │           ││           │           │           │
                                       └───────────┴───────────┴───────────┘└───────────┴───────────┴───────────┘ */

   [_SYM] = LAYOUT_saegewerk(
 //╷           ╷           ╷           ╷           ╷           ╷           ╷╷           ╷           ╷           ╷           ╷           ╷           ╷
    KC_TILD  ,  KC_GRV   ,  _______  ,  KC_CIRC  ,  _______  ,                           _______  ,  _______  ,  _______  ,  _______  ,  _______  ,
    KC_EXLM  ,  KC_AT    ,  KC_HASH  ,  KC_DOLLAR,  KC_PERC  ,                           _______  ,  _______  ,  _______  ,  _______  ,  _______  ,
    _______  ,  _______  ,  KC_PIPE  ,  KC_AMPR  ,  _______  ,  S(KC_W)  ,   _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,
                                        _______  ,  _______  ,  _______  ,   _______  ,  _______  ,  _______
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   
   ┌───────────────────────────────────────────────────────────┐
   │ n u m b e r s                                             │
   └───────────────────────────────────────────────────────────┘
   ┌───────────┬───────────┬───────────┬───────────┬───────────┐                        ┌───────────┬───────────┬───────────┬───────────┬───────────┐
   │    F1     │    F2     │    F3     │    F4     │    F5     │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │     [     │     7     │     8     │     9     │     ]     │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┤
   │    F6     │    F7     │    F8     │    F9     │    F10    ├─╯                    ╰─┤     (     │     4     │     5     │     6     │     )     │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤╭──────────╮╭──────────╮├───────────┼───────────┼───────────┼───────────┼───────────┤
   │           │           │           │    F11    │    F12    ││          ││Play/Pause││     {     │     1     │     2     │     3     │     }     │
   └───────────┴───────────┴───────────┼───────────┼───────────┤╰──────────╯╰──────────╯├───────────┼───────────┼───────────┴───────────┴───────────┘
                                       │           │           │           ││     \     │     0     │           │
                                       └───────────┴───────────┴───────────┘└───────────┴───────────┴───────────┘ */

   [_NUM] = LAYOUT_saegewerk(
 //╷           ╷           ╷           ╷           ╷           ╷           ╷╷           ╷           ╷           ╷           ╷           ╷           ╷
    KC_F1    ,  KC_F2    ,  KC_F3    ,  KC_F4    ,  KC_F5    ,                           KC_LBRC  ,  KC_7     ,  KC_8     ,  KC_9     ,  KC_RBRC  ,
    KC_F6    ,  KC_F7    ,  KC_F8    ,  KC_F9    ,  KC_F10   ,                           KC_LPRN  ,  KC_4     ,  KC_5     ,  KC_6     ,  KC_RPRN  ,
    _______  ,  _______  ,  _______  ,  KC_F11   ,  KC_F12   ,  _______  ,   _______  ,  KC_LCBR  ,  KC_1     ,  KC_2     ,  KC_3     ,  KC_RCBR  ,
                                        _______  ,  _______  ,  _______  ,   KC_BSLS  ,  KC_0     ,  _______
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ n a v i g a t i o n                                       │
   └───────────────────────────────────────────────────────────┘
   ┌───────────┬───────────┬───────────┬───────────┬───────────┐                        ┌───────────┬───────────┬───────────┬───────────┬───────────┐
   │           │           │     €     │           │           │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │           │     Ü     │           │     Ö     │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┤
   │     Ä     │     ß     │           │  OSM SFT  │           ├─╯                    ╰─┤     ←     │     ↓     │     ↑     │     →     │           │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤╭──────────╮╭──────────╮├───────────┼───────────┼───────────┼───────────┼───────────┤
   │           │           │           │           │           ││Shift + W ││    gg    ││           │           │           │           │           │
   └───────────┴───────────┴───────────┼───────────┼───────────┤╰──────────╯╰──────────╯├───────────┼───────────┼───────────┴───────────┴───────────┘
                                       │           │           │           ││           │           │           │
                                       └───────────┴───────────┴───────────┘└───────────┴───────────┴───────────┘ */
   [_NAV] = LAYOUT_saegewerk(
 //╷           ╷           ╷           ╷           ╷           ╷           ╷╷           ╷           ╷           ╷           ╷           ╷           ╷
    _______  ,  _______  ,  KC_EURO  ,  _______  ,  _______  ,                           _______  ,  KC_UE    ,  _______  ,  KC_OE    ,  _______  ,
    KC_AE    ,  KC_SZ    ,  _______  ,  OSM_SFT  ,  _______  ,                           KC_LEFT  ,  KC_DOWN  ,  KC_UP    ,  KC_RIGHT ,  _______  ,
    _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,   _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,
                                        _______  ,  _______  ,  _______  ,   _______  ,  _______  ,  _______
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

   ┌───────────────────────────────────────────────────────────┐
   │ a d j u s t                                               │
   └───────────────────────────────────────────────────────────┘
   ┌───────────┬───────────┬───────────┬───────────┬───────────┐                        ┌───────────┬───────────┬───────────┬───────────┬───────────┐
   │   Reset   │           │           │Tap. Term ↑│           │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │Cli. freq ↑│           │RGB mode ↑ │           │Mus. mode →│
   ├───────────┼───────────┼───────────┼───────────┼───────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├───────────┼───────────┼───────────┼───────────┼───────────┤
   │Bootloader │           │           │Print TapT.│           ├─╯                    ╰─┤Tog. Clicky│           │RGB toggle │           │Tog. Music │
   ├───────────┼───────────┼───────────┼───────────┼───────────┤╭──────────╮╭──────────╮├───────────┼───────────┼───────────┼───────────┼───────────┤
   │Make Keymap│           │           │Tap. Term ↓│           ││          ││          ││Cli. freq ↓│           │RGB mode ↓ │           │Aud. mode →│
   └───────────┴───────────┴───────────┼───────────┼───────────┤╰──────────╯╰──────────╯├───────────┼───────────┼───────────┴───────────┴───────────┘
                                       │           │           │           ││           │           │           │
                                       └───────────┴───────────┴───────────┘└───────────┴───────────┴───────────┘ */

   [_ADJ] = LAYOUT_saegewerk(
 //╷           ╷           ╷           ╷           ╷           ╷           ╷╷           ╷           ╷           ╷           ╷           ╷           ╷
    QK_REBOOT,  _______  ,  _______  ,  DT_UP    ,  _______  ,                           CK_UP    ,  _______  ,  RGB_MOD  ,  _______  ,  MU_NEXT  ,
    QK_BOOT  ,  _______  ,  _______  ,  DT_PRNT  ,  _______  ,                           CK_TOGG  ,  _______  ,  RGB_TOG  ,  _______  ,  MU_TOGG  ,
    MAKE_H   ,  _______  ,  _______  ,  DT_DOWN  ,  _______  ,  _______  ,   _______  ,  CK_DOWN  ,  _______  ,  RGB_RMOD ,  _______  ,  AU_NEXT  ,
                                        _______  ,  _______  ,  _______  ,   _______  ,  _______  ,  _______
 )
};

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case NUM_ENT:
    case SYM_SPC:
    case NAV_TAB:
    case NAV_BSP:
      return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ H A P T I C   F E E D B A C K                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

void keyboard_post_init_user(void) {
  // Call the post init code.
  #if HAPTIC_ENABLE
    haptic_disable(); // disables per key haptic feedback by default
  #endif //HAPTIC ENABLE

  #if RGB_MATRIX_ENABLE
    rgblight_enable_noeeprom();
    //rgblight_sethsv_noeeprom(35, 255, 255); // set default RGB color to yellow
  #endif //RGB_MATRIX_ENABLE
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O L E D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef OLED_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ d y n a m i c   m a c r o                                 │
// └───────────────────────────────────────────────────────────┘

char layer_state_str[24];
char o_text[24] = "";
int dmacro_num = 0; 

#ifdef DYNAMIC_MACRO_ENABLE
    char dmacro_text[4][24] = { "", "RECORDING", "STOP RECORDING",  "PLAY RECORDING"};
    static uint16_t dmacro_timer;
    const char PROGMEM rec_ico[] = {0xD1, 0xE1, 0};
    const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
    const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};


    // DYNMACRO RECORD ├─────────────────────────────────────────────────────────────┐
    void dynamic_macro_record_start_user(void) {
          dmacro_num = 1;
        return;
    }

    // DYNMACRO STOP RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_record_end_user(int8_t direction) {
          dmacro_num = 2;
          dmacro_timer = timer_read();
        return; 
    }

    // DYNMACRO PLAY RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_play_user(int8_t direction) {
          dmacro_num = 3;
          dmacro_timer = timer_read();
        return; 
    }
#endif //DYNAMIC_MACRO_ENABLE


void matrix_scan_user(void) {
    achordion_task();
  #ifdef DYNAMIC_MACRO_ENABLE
    // DynMacroTimer
    if(dmacro_num > 0){
        if (timer_elapsed(dmacro_timer) < 3000) {
            strcpy ( o_text, dmacro_text[dmacro_num] );
          }    
        else {
            if (dmacro_num == 1) {
                strcpy ( o_text, dmacro_text[1] );
              }
            else {
                strcpy ( o_text, layer_state_str );
                dmacro_num = 0;
              }
          }
      }
   #endif //DYNAMIC_MACRO_ENABLE
}


// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘

void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};  
    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0}; 
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM s_lock[] = {0x8F, 0x90, 0};
    static const char PROGMEM n_lock[] = {0x91, 0x92, 0};
    static const char PROGMEM c_lock[] = {0x93, 0x94, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
    #ifdef AUDIO_ENABLE  
      static const char PROGMEM aud_en[] = {0xAF, 0xB0, 0};
      static const char PROGMEM aud_di[] = {0xCF, 0xD0, 0};
    #endif
    #ifdef HAPTIC_ENABLE
      static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
    #endif

// os mode status ────────────────────────────────────────┐

    oled_write_ln_P(sep_v, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_1, false); // ──── MAC
    } else {
        oled_write_P(os_w_1, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_1, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_2, false); // ──── MAC
    } else {
        oled_write_P(os_w_2, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_2, false);
    oled_write_ln_P(sep_v, false);

    
// lock key layer status ─────────────────────────────────┐

    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.num_lock) {
        oled_write_P(n_lock, false); // ──── NUMLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.caps_lock) {
        oled_write_P(c_lock, false); // ─── CAPSLOCK
    } else {
        oled_write_P(b_lock, false);
    }
    if (led_usb_state.scroll_lock) { // ─ SCROLLLOCK
        oled_write_P(s_lock, false);
    } else {
        oled_write_P(b_lock, false);
    }

// hardware feature status ──────────────────────────────┐

    oled_write_P(sep_h2, false);

    #ifndef AUDIO_ENABLE 
        oled_write_P(b_lock, false);
    #endif
    #ifndef HAPTIC_ENABLE 
        oled_write_P(b_lock, false);
    #endif

    #ifdef AUDIO_ENABLE // ────────────────── AUDIO
        if (is_audio_on()) { 
          oled_write_P(aud_en, false); 
        } else {
          oled_write_P(aud_di, false);
        }
    #endif // AUDIO ENABLE

     #ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
        oled_write_P(hap_en, false); 
     #endif // HAPTIC ENABLE
}


// layer status ──────────────────────────────────────────┐

int layerstate = 0;

layer_state_t layer_state_set_kb(layer_state_t state) {
      switch (get_highest_layer(layer_state | default_layer_state)) {
            case 0:
                strcpy ( layer_state_str, "BASE QWERTY");
                break;
            /* case 1: */
            /*     strcpy ( layer_state_str, "BASE COLEMAK"); */
            /*     break; */
            case 1:
                strcpy ( layer_state_str, "SYMBOL");
                break;
            case 2:
                strcpy ( layer_state_str, "NUMBERS");
                break;
            case 3:
                strcpy ( layer_state_str, "NAVIGATION");
                break;
            case 4:
                strcpy ( layer_state_str, "ADJUSTMENT");
                break;
            default:
                strcpy ( layer_state_str, "XXXXXX");
        }
      if (dmacro_num < 1) {
          strcpy ( o_text, layer_state_str );
    }
    /* return state; */
    return update_tri_layer_state(state, _NUM, _SYM, _ADJ);
}


// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {  // ────────────────────────── PRIMARY SIDE

        // layer status ──────────────────────────────────────────────────┐
        #ifdef DYNAMIC_MACRO_ENABLE
            if(dmacro_num == 1){ oled_write_P(rec_ico, false); }
            if(dmacro_num == 2){ oled_write_P(stop_ico, false); }
            if(dmacro_num == 3){ oled_write_P(play_ico, false); }
        #endif //DYNAMIC_MACRO_ENABLE

        oled_write_ln(o_text, false);
        render_os_lock_status();

    } else {  // ─────────────────────────────────────────── SECONDARY SIDE

        // KLOR face ─────────────────────────────────────────────────────┐

        static const char PROGMEM klor_face[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
            0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 
            0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(klor_face, sizeof(klor_face));
    }
    return false;
}
#endif // OLED_ENABLE



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHT_T:
            return TAPPING_TERM - 150; 
        case SHT_N:
            return TAPPING_TERM - 150;
        default:
            return TAPPING_TERM;
    }
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
    switch (keycode) {


// ┌───────────────────────────────────────────────────────────┐
// │ p r o g r a m m i n g                                     │
// └───────────────────────────────────────────────────────────┘

        case MACRO_PARENTHESES:
            if (record->event.pressed) {
                tap_code16(KC_LEFT_PAREN);
                tap_code16(KC_RIGHT_PAREN);
                tap_code(KC_LEFT);
            }
            break;
        case MACRO_BRACKETS:
            if (record->event.pressed) {
                tap_code(KC_LEFT_BRACKET);
                tap_code(KC_RIGHT_BRACKET);
                tap_code(KC_LEFT);
            }
            break;
        case MACRO_CURLYBRACES:
            if (record->event.pressed) {
                tap_code16(KC_LEFT_CURLY_BRACE);
                tap_code16(KC_RIGHT_CURLY_BRACE);
                tap_code(KC_LEFT);
            }
            break;
        case MACRO_SINGLEQUOTES:
            if (record->event.pressed) {
                tap_code(KC_QUOTE);
                tap_code(KC_QUOTE);
                tap_code(KC_LEFT);
            }
            break;
        case MACRO_DOUBLEQUOTES:
            if (record->event.pressed) {
                tap_code16(KC_DOUBLE_QUOTE);
                tap_code16(KC_DOUBLE_QUOTE);
                tap_code(KC_LEFT);
            }
            break;

// ┌───────────────────────────────────────────────────────────┐
// │ v i                                                       │
// └───────────────────────────────────────────────────────────┘

        case VIM_TOP:
            if (record->event.pressed) {
                if ( get_mods() & MOD_MASK_SHIFT ) { // Go to the bottom if shift is held
                    tap_code16(S(KC_G));
                } else { // Otherwise go to the top
                    tap_code(KC_G);
                    tap_code(KC_G);
                }
            }
            break;
        case VIM_INC:
            if (record->event.pressed) {
                tap_code(KC_G);
                tap_code(KC_EQUAL); // Increment otherwise
            }
            break;
        case VIM_DEC:
            if (record->event.pressed) {
                tap_code(KC_G);
                tap_code(KC_MINUS);
            }
            break;
        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif // AUDIO_ENABLE        
                }
              #ifdef HAPTIC_ENABLE
                DRV_pulse(pulsing_strong);
              #endif // HAPTIC_ENABLE
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys    
            return false;
          }

// ┌───────────────────────────────────────────────────────────┐
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘

        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        /* case COLEMAK: */
        /*     if (record->event.pressed) { */
        /*         set_single_persistent_default_layer(_COLEMAK); */
        /*         #ifdef HAPTIC_ENABLE */
        /*           DRV_pulse(transition_hum); */
        /*         #endif // HAPTIC_ENABLE */
        /*     } */
        /*     return false; */
        case SYM:
            if (record->event.pressed) {
                layer_on(_SYM);
                update_tri_layer(_SYM, _NUM, _ADJ);
            } else {
                layer_off(_SYM);
                update_tri_layer(_SYM, _NUM, _ADJ);
            }
            return false;
        case NUM:
            if (record->event.pressed) {
                layer_on(_NUM);
                update_tri_layer(_SYM, _NUM, _ADJ);
            } else {
                layer_off(_NUM);
                update_tri_layer(_SYM, _NUM, _ADJ);
            }
            return false;
        case NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
            } else {
                layer_off(_NAV);
            }
            return false;

// ┌───────────────────────────────────────────────────────────┐
// │ q m k                                                     │
// └───────────────────────────────────────────────────────────┘

        case MAKE_H:
          if (record->event.pressed) {
            #ifdef KEYBOARD_klor_kb2040
              SEND_STRING ("qmk compile -kb klor/2040 -km tisse");
            #else 
              SEND_STRING ("qmk compile -kb klor -km tisse");
            #endif
            tap_code(KC_ENTER); 
          } 
          break;

// ┌───────────────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                                   │
// └───────────────────────────────────────────────────────────┘

      case KC_MPLY:
        if (record->event.pressed) {
          #ifdef HAPTIC_ENABLE
                  DRV_pulse(sharp_click);
          #endif // HAPTIC_ENABL
        }
        break;


// ┌───────────────────────────────────────────────────────────┐
// │ w o r k a r o u n d s                                     │
// └───────────────────────────────────────────────────────────┘

      /* If ALT on colon is used as a home row modifier, send out the 16 bit shifted keycode for colon */
      case MT(MOD_RALT, KC_COLON):
        if (record->tap.count && record->event.pressed) {
            uint8_t mod_state = get_mods();
            if ( mod_state & MOD_MASK_SHIFT ) {
                del_mods( MOD_MASK_SHIFT );
                tap_code( KC_SEMICOLON );
                set_mods( mod_state );
            } else {
                tap_code16(KC_COLON); // Send colon if the key is pressed
            }
        } else if (record->event.pressed) {
            tap_code16(KC_RALT); // RALT if key is held
        }
        return false;
    }
    return true;


}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ E N C O D E R                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mod_state = get_mods();
// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  L                                          │
// └───────────────────────────────────────────────────────────┘

    if (index == 0) {
      if(IS_LAYER_ON(_NAV)){
        if (clockwise) { // Page up/down
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
      } else if (IS_LAYER_ON(_SYM)){
        if (clockwise) { // Right/left
            tap_code16(KC_PLUS);
        } else {
            tap_code(KC_MINUS);
        }
      } else {
        if (clockwise) { // Up/down
            if( mod_state & MOD_MASK_SHIFT ) {
                del_mods( MOD_MASK_SHIFT );
                tap_code( KC_RIGHT );
                set_mods( mod_state );
            } else {
                tap_code(KC_DOWN);
            }
        } else {
            if( mod_state & MOD_MASK_SHIFT ) {
                del_mods( MOD_MASK_SHIFT );
                tap_code( KC_LEFT );
                set_mods( mod_state );
            } else {
                tap_code(KC_UP);
            }
        }
      }

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  R                                          │
// └───────────────────────────────────────────────────────────┘

    } else if (index == 1) {
      if(IS_LAYER_ON(_NAV)){
        if (clockwise) { // Next/previous song
            tap_code16(C(KC_PGDN));
        } else {
            tap_code16(C(KC_PGUP));
        }
      } else if(IS_LAYER_ON(_NUM)){
        if (clockwise) { // Vim increment
            tap_code(KC_G);
            tap_code(KC_EQUAL);
        } else {
            tap_code(KC_G); // Vim decrement
            tap_code(KC_MINUS);
        }
      } else {
        if (clockwise) { // Volume up/down
            if( mod_state & MOD_MASK_SHIFT ) {
                del_mods( MOD_MASK_SHIFT );
                tap_code( KC_MNXT );
                set_mods( mod_state );
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if( mod_state & MOD_MASK_SHIFT ) {
                del_mods( MOD_MASK_SHIFT );
                tap_code( KC_MPRV );
                set_mods( mod_state );
            } else {
                tap_code(KC_VOLD);
            }
        }
      }
    }
    return false;
}

#endif // ENCODER_ENABLE




/*

                                                       ▐█    ▟▛ ▐█     ▄▆▀▀▀▀▀▀▆▄  ▐█▀▀▀▀▀█▌
                                                       ▐█   ▟▛  ▐█    ▟▛        ▜▙ ▐█     █▌
                                                       ▐█  ▟▛   ▐█   ▐█          █▋▐█     █▌
                                                       ▐█ ▟█▙   ▐█   ▐█          █▋▐█▀▀▜█▀▀▘
                                                       ▐█▟▛ ▜▙  ▐█    ▜▙        ▟▛ ▐█   ▜▙
                                                       ▐█▛   ▜▙ ▐█▄▄▄▄ ▀▜▆▄▄▄▄▆▛▀  ▐█    ▜▙

                                                                 ▄██████████████▄
                                                                 ████████████████
                                                            ▄██████▀  ▀████▀  ▀██████▄
                                                            ███████▄  ▄████▄  ▄███████
                                                            ███████████▀▀▀▀███████████
                                                            ▀█████████▀ ▄▄ ▀█████████▀
                                                                 ████▀ ▄██▄ ▀████
                                                                 ████▄▄████▄▄████

*/



