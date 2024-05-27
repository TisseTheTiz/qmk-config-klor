#ifndef HRM_H_
#define HRM_H_

// QWERTY

// Bound the home row keys to the modifiers by default
#ifdef POS_HRM_GUI
    #if POS_HRM_GUI == 1
        #ifdef ENABLE_HRM_GUI
            #define A_HRM MT(MOD_LGUI, KC_A)
            #define COLON_HRM MT(MOD_RGUI, KC_COLN)
        #else
            #define A_HRM KC_A
            #define COLON_HRM KC_COLN
        #endif
    #elif POS_HRM_GUI == 2
        #ifdef ENABLE_HRM_GUI
            #define S_HRM MT(MOD_LGUI, KC_S)
            #define L_HRM MT(MOD_RGUI, KC_L)
        #else
            #define S_HRM KC_S
            #define L_HRM KC_L
        #endif
    #elif POS_HRM_GUI == 3
        #ifdef ENABLE_HRM_GUI
            #define D_HRM MT(MOD_LGUI, KC_D)
            #define K_HRM MT(MOD_RGUI, KC_K)
        #else
            #define D_HRM KC_D
            #define K_HRM KC_K
        #endif
    #elif POS_HRM_GUI == 4
        #ifdef ENABLE_HRM_GUI
            #define F_HRM MT(MOD_LGUI, KC_F)
            #define J_HRM MT(MOD_RGUI, KC_J)
        #else
            #define F_HRM KC_F
            #define J_HRM KC_J
        #endif
    #endif
#endif
#ifdef POS_HRM_ALT
    #if POS_HRM_ALT == 1
        #ifdef ENABLE_HRM_ALT
            #define A_HRM MT(MOD_LALT, KC_A)
            #define COLON_HRM MT(MOD_RALT, KC_COLN)
        #else
            #define A_HRM KC_A
            #define COLON_HRM KC_COLN
        #endif
    #elif POS_HRM_ALT == 2
        #ifdef ENABLE_HRM_ALT
            #define S_HRM MT(MOD_LALT, KC_S)
            #define L_HRM MT(MOD_RALT, KC_L)
        #else
            #define S_HRM KC_S
            #define L_HRM KC_L
        #endif
    #elif POS_HRM_ALT == 3
        #ifdef ENABLE_HRM_ALT
            #define D_HRM MT(MOD_LALT, KC_D)
            #define K_HRM MT(MOD_RALT, KC_K)
        #else
            #define D_HRM KC_D
            #define K_HRM KC_K
        #endif
    #elif POS_HRM_ALT == 4
        #ifdef ENABLE_HRM_ALT
            #define F_HRM MT(MOD_LALT, KC_F)
            #define J_HRM MT(MOD_RALT, KC_J)
        #else
            #define F_HRM KC_F
            #define J_HRM KC_J
        #endif
    #endif
#endif
#ifdef POS_HRM_CTL
    #if POS_HRM_CTL == 1
        #ifdef ENABLE_HRM_CTL
            #define A_HRM MT(MOD_LCTL, KC_A)
            #define COLON_HRM MT(MOD_RCTL, KC_COLN)
        #else
            #define A_HRM KC_A
            #define COLON_HRM KC_COLN
        #endif
    #elif POS_HRM_CTL == 2
        #ifdef ENABLE_HRM_CTL
            #define S_HRM MT(MOD_LCTL, KC_S)
            #define L_HRM MT(MOD_RCTL, KC_L)
        #else
            #define S_HRM KC_S
            #define L_HRM KC_L
        #endif
    #elif POS_HRM_CTL == 3
        #ifdef ENABLE_HRM_CTL
            #define D_HRM MT(MOD_LCTL, KC_D)
            #define K_HRM MT(MOD_RCTL, KC_K)
        #else
            #define D_HRM KC_D
            #define K_HRM KC_K
        #endif
    #elif POS_HRM_CTL == 4
        #ifdef ENABLE_HRM_CTL
            #define F_HRM MT(MOD_LCTL, KC_F)
            #define J_HRM MT(MOD_RCTL, KC_J)
        #else
            #define F_HRM KC_F
            #define J_HRM KC_J
        #endif
    #endif
#endif
#ifdef POS_HRM_SFT
    #if POS_HRM_SFT == 1
        #ifdef ENABLE_HRM_SFT
            #define A_HRM MT(MOD_LSFT, KC_A)
            #define COLON_HRM MT(MOD_RSFT, KC_COLN)
        #else
            #define A_HRM KC_A
            #define COLON_HRM KC_COLN
        #endif
    #elif POS_HRM_SFT == 2
        #ifdef ENABLE_HRM_SFT
            #define S_HRM MT(MOD_LSFT, KC_S)
            #define L_HRM MT(MOD_RSFT, KC_L)
        #else
            #define S_HRM KC_S
            #define L_HRM KC_L
        #endif
    #elif POS_HRM_SFT == 3
        #ifdef ENABLE_HRM_SFT
            #define D_HRM MT(MOD_LSFT, KC_D)
            #define K_HRM MT(MOD_RSFT, KC_K)
        #else
            #define D_HRM KC_D
            #define K_HRM KC_K
        #endif
    #elif POS_HRM_SFT == 4
        #ifdef ENABLE_HRM_SFT
            #define F_HRM MT(MOD_LSFT, KC_F)
            #define J_HRM MT(MOD_RSFT, KC_J)
        #else
            #define J_HRM KC_J
            #define F_HRM KC_F
        #endif
    #endif
#endif

/* COLEMAK TBC */

#endif // HRM_H_
