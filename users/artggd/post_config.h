#pragma once

// Argos caps VIA at 8 layers in its post_config.h; the artggd keymap has 13
// (6 diacritics layers). This file is included after the modules' post_config.h.
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 13
