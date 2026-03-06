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
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define FLOW_TAP_TERM 100
#define FLOW_TAP_TERM_PER_KEY
#define CHORDAL_HOLD
#define QUICK_TAP_TERM_PER_KEY
//#define SPECULATIVE_HOLD

// Significantly reduce trackpad sensitivity (lower DPI = less sensitive)
#define DILEMMA_MINIMUM_DEFAULT_DPI 90
#define DILEMMA_DEFAULT_DPI_CONFIG_STEP 30

// Invert scroll direction (natural scrolling)
#define DILEMMA_DRAGSCROLL_REVERSE_Y

// Mouse acceleration (8.8 fixed-point: 256 = 1.0x, 512 = 2.0x)
#define ACCEL_THRESHOLD_1  3    // Below: no acceleration
#define ACCEL_THRESHOLD_2  7    // Moderate acceleration
#define ACCEL_THRESHOLD_3  15   // High acceleration; above: max
#define ACCEL_MULTIPLIER_0 256  // 1.0x - precise movements
#define ACCEL_MULTIPLIER_1 384  // 1.5x - moderate
#define ACCEL_MULTIPLIER_2 640  // 2.5x - fast
#define ACCEL_MULTIPLIER_3 1024 // 4.0x - flick

// Combo settings (matching ZMK COMBO_TERM)
#define COMBO_TERM 50

// RGB timeout after 5 minutes of inactivity
#define RGB_MATRIX_TIMEOUT 300000
