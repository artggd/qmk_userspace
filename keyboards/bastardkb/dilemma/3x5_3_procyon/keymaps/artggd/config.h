/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#pragma once

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

#define ENCODER_RESOLUTION 4

// Timeless Home Row Mods Configuration (urob-style)
// https://github.com/urob/zmk-config#timeless-homerow-mods
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// Argos defines its own FLOW_TAP_TERM (150)
#undef FLOW_TAP_TERM
#define FLOW_TAP_TERM 100
#define FLOW_TAP_TERM_PER_KEY
#define CHORDAL_HOLD
#define QUICK_TAP_TERM_PER_KEY
// No auto-repeat on tap-hold keys (was per-key before Argos)
#define QUICK_TAP_TERM 0
//#define SPECULATIVE_HOLD

// Combo settings (matching ZMK COMBO_TERM)
#define COMBO_TERM 50

// Argos and bk_pointing_device settings, from the BastardKB vendor keymap.
// Argos only reads the timings above as initial values after an EEPROM reset;
// afterwards they are configured in the Argos app.
#undef AUTO_MOUSE_DEFAULT_LAYER
#define AUTO_MOUSE_DEFAULT_LAYER 6 // LAYER_POINTER
#undef LED_DPI_INDICATOR_INDEX
#define LED_DPI_INDICATOR_INDEX 7
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 72

// RGB timeout after 5 minutes of inactivity
#define RGB_MATRIX_TIMEOUT 300000
