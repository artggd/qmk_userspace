/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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
#include "keymap_french_mac_iso.h"

// Fix buggy Mac AZERTY keycodes in keymap_french_mac_iso.h
// Observed: KC_GRV produces <, KC_NUBS produces @
#undef FR_LABK
#undef FR_RABK
#undef FR_HASH
#undef FR_AT

#define FR_LABK KC_GRV      // < (was KC_NUBS producing @)
#define FR_RABK S(KC_GRV)   // > (was S(KC_NUBS) producing #)
#define FR_HASH S(KC_NUBS)  // # (was S(KC_GRV) producing >)
#define FR_AT   KC_NUBS     // @ (was KC_GRV producing <)

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_SYM,
    LAYER_FUN,
    LAYER_SFT_SYM,
    LAYER_POINTER,
    // Diacritics layers (accessed via layer-tap on base layer)
    LAYER_DIAC_ACUTE,   // Hold F → é
    LAYER_DIAC_RGRAVE,  // Hold P → è, ù
    LAYER_DIAC_LGRAVE,  // Hold O → à
    LAYER_DIAC_RCIRC,   // Hold W → ô, ê, î, û
    LAYER_DIAC_LCIRC,   // Hold Y → â
    LAYER_DIAC_TREMA,   // Hold G → ë, ï, ü, ÿ
};

enum custom_keycodes {
    MC_PAREN = SAFE_RANGE,  // Types () and moves cursor inside
    MC_BRACK,               // Types [] and moves cursor inside
    MC_CURLY,               // Types {} and moves cursor inside
    MC_BTICK,               // Types `` and moves cursor inside
    MC_SQTDQ,               // ' normally, " when shifted (mod morph)
    // Circumflex characters (dead key + letter)
    MC_ACIR,                // â
    MC_ECIR,                // ê
    MC_ICIR,                // î
    MC_OCIR,                // ô
    MC_UCIR,                // û
    // Trema/diaeresis characters (dead key + letter)
    MC_EDIA,                // ë
    MC_IDIA,                // ï
    MC_UDIA,                // ü
    MC_YDIA,                // ÿ
    // Direct accented keys with shift support (for uppercase via CapsLock)
    MC_EACU,                // é/É
    MC_EGRV,                // è/È
    MC_AGRV,                // à/À
    MC_UGRV,                // ù/Ù
    MC_CCED,                // ç/Ç (direct key)
    C_CCED_HT,              // tap=c, hold=ç/Ç (hold-tap)
    BS_DEL_SYM,             // tap=backspace, rshift+tap=delete, hold=sym layer
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

// Layer-tap defines (ZMK thumb layout: ESC, Space/Nav, Tab/Shift | Enter/Fun, Backspace/Sym, Shift/Num)
#define SPC_NAV LT(LAYER_NAV, KC_SPC)
#define TAB_SFT MT(MOD_LSFT, KC_TAB)
#define ENT_FUN LT(LAYER_FUN, KC_ENT)
#define SFT_NUM LT(LAYER_NUM, KC_LSFT)
#define PT_Z    LT(LAYER_POINTER, FR_Z)
#define PT_COLN LT(LAYER_POINTER, FR_COLN)

// Diacritics layer-taps (matching ZMK layout)
#define W_RCIRC LT(LAYER_DIAC_RCIRC, FR_W)   // Hold W → circumflex layer (right: ô, ê, î, û)
#define F_ACUTE LT(LAYER_DIAC_ACUTE, FR_F)   // Hold F → acute layer (é)
#define P_RGRAV LT(LAYER_DIAC_RGRAVE, FR_P)  // Hold P → grave layer (right: è, ù)
#define G_TREMA LT(LAYER_DIAC_TREMA, FR_G)   // Hold G → trema layer (ë, ï, ü, ÿ)
#define O_LGRAV LT(LAYER_DIAC_LGRAVE, FR_O)  // Hold O → grave layer (left: à)
#define Y_LCIRC LT(LAYER_DIAC_LCIRC, FR_Y)   // Hold Y → circumflex layer (left: â)

// Combos
// O + Y -> !
const uint16_t PROGMEM combo_exlm[] = {O_LGRAV, Y_LCIRC, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_exlm, FR_EXLM),
};


#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// Chordal Hold layout for opposite-hands rule (required for CHORDAL_HOLD)
// 'L' = left hand, 'R' = right hand, '*' = thumb (bilateral)
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_3(
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                  '*', '*', '*',  '*', '*', '*'
    );

// clang-format off
/** \brief COLEMAK-DH layout adapted from ZMK config (3 rows, 10 columns). */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE Layer - Colemak-DH with home row mods
   * ZMK thumb layout: ESC/Media, Space/Nav, Tab/Shift | Enter/Fun, Backspace/Sym, Shift/Num
   */
  [LAYER_BASE] = LAYOUT_split_3x5_3(
       FR_Q,         W_RCIRC,      F_ACUTE,      P_RGRAV,      G_TREMA,     FR_J,    FR_L,         O_LGRAV,      Y_LCIRC,      MC_SQTDQ,
       LCTL_T(FR_A), LALT_T(FR_R), LGUI_T(FR_S), LSFT_T(FR_T), FR_D,        FR_H,    RSFT_T(FR_N), RGUI_T(FR_E), LALT_T(FR_I), RCTL_T(FR_U),
       PT_Z,         RALT_T(FR_X), C_CCED_HT,    FR_V,         FR_B,        FR_K,    FR_M,         FR_COMM,      FR_SCLN,      PT_COLN,
                                   KC_ESC,       SPC_NAV,      TAB_SFT,     ENT_FUN, BS_DEL_SYM,   SFT_NUM
  ),

  /* NAV Layer - Navigation and clipboard (from ZMK)
   * Left: Undo, Cut, Copy, Paste, Redo + modifiers
   * Right: Arrows, Home/End, PgUp/PgDn
   */
  [LAYER_NAV] = LAYOUT_split_3x5_3(
    G(FR_Z),  G(FR_X), G(FR_C), G(FR_V), G(S(FR_Z)),   XXXXXXX, G(KC_LEFT), KC_UP,   G(KC_RGHT), KC_BRIU,
    KC_LCTL,  KC_LALT, KC_LGUI, KC_LSFT, G(KC_D),      KC_CAPS, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_BRID,
    XXXXXXX,  KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_MPRV,    KC_VOLD, KC_VOLU,    KC_MNXT,
                       XXXXXXX, _______, XXXXXXX,      KC_MSTP, KC_MPLY, KC_MUTE
  ),

  /* NUM Layer - Numpad layout (from ZMK)
   * Uses keypad codes (KC_Px) for layout-independent numbers
   */
  [LAYER_NUM] = LAYOUT_split_3x5_3(
    MC_BTICK, KC_P7,   KC_P8,   KC_P9,   FR_BSLS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    FR_PLUS,  KC_P4,   KC_P5,   KC_P6,   FR_ASTR,    XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL,
    FR_MINS,  KC_P1,   KC_P2,   KC_P3,   FR_SLSH,    XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
                       KC_PDOT, KC_P0,   FR_EQL,     XXXXXXX, XXXXXXX, _______
  ),

  /* SYM Layer - Symbols with auto-pair brackets (from ZMK)
   * Uses FR_ keycodes for AZERTY layout
   */
  [LAYER_SYM] = LAYOUT_split_3x5_3(
    FR_TILD,            FR_PERC, FR_CIRC, FR_UNDS, MC_BRACK,   XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
    MT(MOD_LSFT,FR_BSLS), FR_AT, FR_DLR,  FR_MINS, MC_PAREN,   XXXXXXX, MO(LAYER_SFT_SYM), KC_RGUI, KC_LALT, KC_RCTL,
    FR_HASH,            FR_AMPR, FR_EURO, FR_EQL,  MC_CURLY,   XXXXXXX, XXXXXXX,          XXXXXXX, KC_RALT, XXXXXXX,
                        FR_LABK, MO(LAYER_NAV), FR_RABK,       _______, XXXXXXX,          XXXXXXX
  ),

  /* FUN Layer - Function keys (from ZMK)
   * F keys arranged: F7-F9/F12 (top), F4-F6/F11 (mid), F1-F3/F10 (bottom)
   */
  [LAYER_FUN] = LAYOUT_split_3x5_3(
    XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,     XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL,
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,     XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
                      XXXXXXX, XXXXXXX, G(S(KC_4)), _______, XXXXXXX, XXXXXXX
  ),

  /* SFT_SYM Layer - Individual bracket keys (accessed from SYM layer)
   * Provides single brackets without auto-pairing
   */
  [LAYER_SFT_SYM] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, FR_LBRC, FR_RBRC,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, FR_LPRN, FR_RPRN,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, FR_LCBR, FR_RCBR,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* POINTER Layer - Mouse emulation and pointer functions (kept from original) */
  [LAYER_POINTER] = LAYOUT_split_3x5_3(
    QK_BOOT,  EE_CLR, XXXXXXX, DPI_MOD, S_D_MOD, S_D_MOD, DPI_MOD, XXXXXXX,  EE_CLR, QK_BOOT,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    _______, DRGSCRL, SNIPING, MS_BTN3, XXXXXXX, XXXXXXX, MS_BTN3, SNIPING, DRGSCRL, _______,
                      MS_BTN3, MS_BTN2, MS_BTN1, MS_BTN1, MS_BTN2, MS_BTN3
  ),

  /* DIAC_ACUTE Layer - Hold F to access é/É (shift-aware) */
  [LAYER_DIAC_ACUTE] = LAYOUT_split_3x5_3(
    _______, _______, _______, XXXXXXX, _______,   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, MC_EACU, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,
                      _______, _______, _______,   _______, _______, _______
  ),

  /* DIAC_RGRAVE Layer - Hold P to access è/È, ù/Ù (shift-aware) */
  [LAYER_DIAC_RGRAVE] = LAYOUT_split_3x5_3(
    _______, _______, XXXXXXX, _______, _______,   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, MC_EGRV, _______, MC_UGRV,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,
                      _______, _______, _______,   _______, _______, _______
  ),

  /* DIAC_LGRAVE Layer - Hold O to access à/À (shift-aware) */
  [LAYER_DIAC_LGRAVE] = LAYOUT_split_3x5_3(
    _______, _______, _______, _______, _______,   _______, _______, XXXXXXX, _______, _______,
    MC_AGRV, _______, _______, _______, _______,   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,
                      _______, _______, _______,   _______, _______, _______
  ),

  /* DIAC_RCIRC Layer - Hold W to access ô/Ô, ê/Ê, î/Î, û/Û (shift-aware) */
  [LAYER_DIAC_RCIRC] = LAYOUT_split_3x5_3(
    _______, XXXXXXX, _______, _______, _______,   _______, _______, MC_OCIR, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, MC_ECIR, MC_ICIR, MC_UCIR,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,
                      _______, _______, _______,   _______, _______, _______
  ),

  /* DIAC_LCIRC Layer - Hold Y to access â/Â (shift-aware) */
  [LAYER_DIAC_LCIRC] = LAYOUT_split_3x5_3(
    _______, _______, _______, _______, _______,   _______, _______, _______, XXXXXXX, _______,
    MC_ACIR, _______, _______, _______, _______,   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,
                      _______, _______, _______,   _______, _______, _______
  ),

  /* DIAC_TREMA Layer - Hold G to access ë/Ë, ï/Ï, ü/Ü, ÿ/Ÿ (shift-aware) */
  [LAYER_DIAC_TREMA] = LAYOUT_split_3x5_3(
    _______, _______, _______, _______, XXXXXXX,   _______, _______, _______, MC_YDIA, _______,
    _______, _______, _______, _______, _______,   _______, _______, MC_EDIA, MC_IDIA, MC_UDIA,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,
                      _______, _______, _______,   _______, _______, _______
  ),
};
// clang-format on

// Disable Flow Tap for home row mods so they work after thumb keys
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t flow_tap_term) {
    switch (keycode) {
        // Left hand HRMs
        case LCTL_T(FR_A):
        case LALT_T(FR_R):
        case LGUI_T(FR_S):
        case LSFT_T(FR_T):
        // Right hand HRMs
        case RSFT_T(FR_N):
        case RGUI_T(FR_E):
        case LALT_T(FR_I):
        case RCTL_T(FR_U):
        // AltGr on bottom row
        case RALT_T(FR_X):
        // Thumb keys
        case LT(LAYER_NAV, KC_SPC):     // SPC_NAV
        case LSFT_T(KC_TAB):            // TAB_SFT
        case LT(LAYER_FUN, KC_ENT):     // ENT_FUN
        case BS_DEL_SYM:                // BS_DEL_SYM
        case LT(LAYER_NUM, KC_LSFT):    // SFT_NUM
        // Diacritics layer-taps
        case LT(LAYER_DIAC_RCIRC, FR_W):   // W_RCIRC
        case LT(LAYER_DIAC_ACUTE, FR_F):   // F_ACUTE
        case LT(LAYER_DIAC_RGRAVE, FR_P):  // P_RGRAV
        case LT(LAYER_DIAC_TREMA, FR_G):   // G_TREMA
        case LT(LAYER_DIAC_LGRAVE, FR_O):  // O_LGRAV
        case LT(LAYER_DIAC_LCIRC, FR_Y):   // Y_LCIRC
        case C_CCED_HT:                    // C with ç hold-tap
            return 0;  // Disable Flow Tap for HRMs, thumb keys, and diacritics
        default:
            return flow_tap_term;  // Use default for other keys
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Diacritics layer-taps - disable auto-repeat so tap-then-hold works
        case LT(LAYER_DIAC_RCIRC, FR_W):   // W_RCIRC
        case LT(LAYER_DIAC_ACUTE, FR_F):   // F_ACUTE
        case LT(LAYER_DIAC_RGRAVE, FR_P):  // P_RGRAV
        case LT(LAYER_DIAC_TREMA, FR_G):   // G_TREMA
        case LT(LAYER_DIAC_LGRAVE, FR_O):  // O_LGRAV
        case LT(LAYER_DIAC_LCIRC, FR_Y):   // Y_LCIRC
        // Left hand HRMs
        case LCTL_T(FR_A):
        case LALT_T(FR_R):
        case LGUI_T(FR_S):
        case LSFT_T(FR_T):
        // Right hand HRMs
        case RSFT_T(FR_N):
        case RGUI_T(FR_E):
        case LALT_T(FR_I):
        case RCTL_T(FR_U):
        // Thumb keys - disable auto-repeat so tap-then-hold activates layer
        case SPC_NAV:
        case TAB_SFT:
        case ENT_FUN:
        case BS_DEL_SYM:
        case SFT_NUM:
            return 0;  // Disable auto-repeat for diacritics, HRMs, and thumb keys
        default:
            return QUICK_TAP_TERM;  // Use default for others
    }
}

// State for C_CCED_HT hold-tap (tap=c, hold=ç)
static uint16_t c_cced_timer = 0;
static bool c_cced_held = false;
static bool c_cced_fired = false;  // Track if hold action already fired
static bool c_cced_interrupted = false;  // Track if another key was pressed

// State for BS_DEL_SYM (tap=backspace/delete, hold=sym layer)
static uint16_t bs_del_timer = 0;
static bool bs_del_held = false;
static bool bs_del_fired = false;  // Track if hold action (layer) already fired
static bool bs_del_interrupted = false;  // Track if another key was pressed

// Helper for shift-aware accented characters (uses CapsLock for uppercase on Mac)
static void send_accented_char(uint16_t dead_key, uint16_t letter) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    if (mods & MOD_MASK_SHIFT) {
        // Clear shift, enable caps, send char, disable caps, restore shift
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        tap_code(KC_CAPS);
        if (dead_key) tap_code16(dead_key);
        tap_code(letter);
        tap_code(KC_CAPS);
        set_mods(mods);
    } else {
        if (dead_key) tap_code16(dead_key);
        tap_code(letter);
    }
}

// Auto-pair bracket macros (Mac AZERTY key sequences)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_PAREN:
            if (record->event.pressed) {
                // () on Mac AZERTY: KC_5 = (, KC_MINS = )
                tap_code(KC_5);
                tap_code(KC_MINS);
                tap_code(KC_LEFT);
            }
            return false;
        case MC_BRACK:
            if (record->event.pressed) {
                // [] on Mac AZERTY: Shift+Option+5, Shift+Option+)
                register_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT));
                tap_code(KC_5);
                tap_code(KC_MINS);
                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT));
                tap_code(KC_LEFT);
            }
            return false;
        case MC_CURLY:
            if (record->event.pressed) {
                // {} on Mac AZERTY: Option+5, Option+)
                register_mods(MOD_BIT(KC_LALT));
                tap_code(KC_5);
                tap_code(KC_MINS);
                unregister_mods(MOD_BIT(KC_LALT));
                tap_code(KC_LEFT);
            }
            return false;
        case MC_BTICK:
            if (record->event.pressed) {
                // `` on Mac AZERTY: FR_GRV = KC_NUHS (direct key, not dead)
                tap_code(KC_NUHS);
                tap_code(KC_NUHS);
                tap_code(KC_LEFT);
            }
            return false;
        case MC_SQTDQ:
            // Mod morph: ' normally, " when shift is held
            if (record->event.pressed) {
                uint8_t mods = get_mods() | get_oneshot_mods();
                if (mods & MOD_MASK_SHIFT) {
                    // Clear shift, send ", restore shift
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    tap_code16(FR_DQUO);
                    set_mods(mods);
                } else {
                    tap_code(FR_QUOT);
                }
            }
            return false;
        // Circumflex characters: dead key (^) + letter (shift-aware)
        case MC_ACIR:
            if (record->event.pressed) send_accented_char(FR_CIRC, FR_A);
            return false;
        case MC_ECIR:
            if (record->event.pressed) send_accented_char(FR_CIRC, FR_E);
            return false;
        case MC_ICIR:
            if (record->event.pressed) send_accented_char(FR_CIRC, FR_I);
            return false;
        case MC_OCIR:
            if (record->event.pressed) send_accented_char(FR_CIRC, FR_O);
            return false;
        case MC_UCIR:
            if (record->event.pressed) send_accented_char(FR_CIRC, FR_U);
            return false;
        // Trema/diaeresis characters: dead key (¨) + letter (shift-aware)
        case MC_EDIA:
            if (record->event.pressed) send_accented_char(FR_DIAE, FR_E);
            return false;
        case MC_IDIA:
            if (record->event.pressed) send_accented_char(FR_DIAE, FR_I);
            return false;
        case MC_UDIA:
            if (record->event.pressed) send_accented_char(FR_DIAE, FR_U);
            return false;
        case MC_YDIA:
            if (record->event.pressed) send_accented_char(FR_DIAE, FR_Y);
            return false;
        // Direct accented keys with shift support (shift-aware)
        case MC_EACU:
            if (record->event.pressed) send_accented_char(0, FR_LEAC);
            return false;
        case MC_EGRV:
            if (record->event.pressed) send_accented_char(0, FR_LEGR);
            return false;
        case MC_AGRV:
            if (record->event.pressed) send_accented_char(0, FR_LAGR);
            return false;
        case MC_UGRV:
            if (record->event.pressed) send_accented_char(0, FR_LUGR);
            return false;
        case MC_CCED:
            if (record->event.pressed) send_accented_char(0, FR_LCCE);
            return false;
        case BS_DEL_SYM:
            // Mod-morph layer-tap: tap=backspace (rshift+tap=delete), hold=sym layer
            if (record->event.pressed) {
                bs_del_timer = timer_read();
                bs_del_held = true;
                bs_del_fired = false;
                bs_del_interrupted = false;
            } else {
                if (bs_del_fired || bs_del_interrupted) {
                    // Was held long enough or interrupted, deactivate layer
                    layer_off(LAYER_SYM);
                } else {
                    // Tap: check for right shift modifier
                    uint8_t mods = get_mods() | get_oneshot_mods();
                    if (mods & MOD_BIT(KC_RSFT)) {
                        // Clear right shift, send delete, restore mods
                        del_mods(MOD_BIT(KC_RSFT));
                        del_oneshot_mods(MOD_BIT(KC_RSFT));
                        tap_code(KC_DEL);
                        set_mods(mods);
                    } else {
                        tap_code(KC_BSPC);
                    }
                }
                bs_del_held = false;
                bs_del_fired = false;
                bs_del_interrupted = false;
            }
            return false;
        case C_CCED_HT:
            // Hold-tap: tap=c, hold=ç/Ç (shift-aware, fires on timer or interrupt)
            if (record->event.pressed) {
                c_cced_timer = timer_read();
                c_cced_held = true;
                c_cced_fired = false;
                c_cced_interrupted = false;
            } else {
                if (c_cced_held && !c_cced_fired && !c_cced_interrupted) {
                    // Released before timer and no interrupt: send c
                    tap_code(FR_C);
                }
                c_cced_held = false;
                c_cced_fired = false;
                c_cced_interrupted = false;
            }
            return false;
        default:
            // HOLD_ON_OTHER_KEY_PRESS behavior for custom hold-taps
            if (record->event.pressed) {
                // BS_DEL_SYM: immediately activate layer when another key is pressed
                if (bs_del_held && !bs_del_fired && !bs_del_interrupted) {
                    layer_on(LAYER_SYM);
                    bs_del_interrupted = true;
                }
                // C_CCED_HT: immediately send 'c' when another key is pressed
                if (c_cced_held && !c_cced_fired && !c_cced_interrupted) {
                    tap_code(FR_C);
                    c_cced_interrupted = true;
                }
            }
            return true;
    }
    return true;
}

// Check timers and fire hold actions immediately when reached
void matrix_scan_user(void) {
    if (c_cced_held && !c_cced_fired && timer_elapsed(c_cced_timer) >= TAPPING_TERM) {
        send_accented_char(0, FR_LCCE);
        c_cced_fired = true;
    }
    if (bs_del_held && !bs_del_fired && timer_elapsed(bs_del_timer) >= TAPPING_TERM) {
        layer_on(LAYER_SYM);
        bs_del_fired = true;
    }
}

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Invert scroll direction (natural scrolling)
    mouse_report.v = -mouse_report.v;
    return mouse_report;
}
#endif     // POINTING_DEVICE_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_NAV]        = {ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_NUM]        = {ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_SPDD, RM_SPDU)},
    [LAYER_SYM]        = {ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_FUN]        = {ENCODER_CCW_CW(KC_DOWN, KC_UP),   ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_SFT_SYM]    = {ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU)},
    // Diacritics layers inherit from base (volume/scroll)
    [LAYER_DIAC_ACUTE]  = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_DIAC_RGRAVE] = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_DIAC_LGRAVE] = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_DIAC_RCIRC]  = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_DIAC_LCIRC]  = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_DIAC_TREMA]  = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
