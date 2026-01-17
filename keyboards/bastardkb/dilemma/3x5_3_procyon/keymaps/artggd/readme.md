# artggd Keymap for Dilemma 3x5_3 Procyon

A Colemak layout with home row mods, French AZERTY support, and extensive diacritical character access via hold-tap layers.

## Features

- **Colemak** base layout optimized for ergonomics
- **Home row modifiers** (Ctrl, Alt, Gui, Shift) on both hands
- **French diacritics** via hold-tap layers (é, è, à, ê, ë, ç, etc.)
- **Auto-pair brackets** that position cursor inside: `()`, `[]`, `{}`, ``` `` ```
- **Miryoku-inspired** navigation, symbol, and number layers
- **Chordal hold** for reliable modifier activation

## Layer Summary

| Layer | # | Activation | Purpose |
|-------|---|------------|---------|
| BASE | 0 | Default | Colemak with home row mods |
| NAV | 1 | Hold Tab | Navigation, arrows, clipboard, media |
| NUM | 2 | Hold Del | Numpad with operators |
| SYM | 3 | Hold Space | Symbols and auto-pair brackets |
| FUN | 4 | Hold Enter | Function keys F1-F12 |
| SFT_SYM | 5 | From SYM | Individual brackets (no auto-pair) |
| POINTER | 6 | Hold Z or : | Mouse/trackpad controls |
| DIAC_ACUTE | 7 | Hold F | Acute accent (é) |
| DIAC_RGRAVE | 8 | Hold P | Right grave (è, ù) |
| DIAC_LGRAVE | 9 | Hold O | Left grave (à) |
| DIAC_RCIRC | 10 | Hold W | Right circumflex (ê, ô, î, û) |
| DIAC_LCIRC | 11 | Hold Y | Left circumflex (â) |
| DIAC_TREMA | 12 | Hold G | Diaeresis (ë, ï, ü, ÿ) |


## Layer 0: BASE (Colemak)

Home row mods: tap for letter, hold for modifier. Diacritics: hold W/F/P/G/O/Y for accent layers.

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│   Q   │  W/ˆ  │  F/´  │  P/`  │  G/¨  │   │   J   │   L   │  O/`  │  Y/ˆ  │ '/"   │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│  A/⌃  │  R/⌥  │  S/⌘  │  T/⇧  │   D   │   │   H   │  N/⇧  │  E/⌘  │  I/⌥  │  U/⌃  │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│  Z/Ptr│ X/RAlt│  C/ç  │   V   │   B   │   │   K   │   M   │   ,   │   ;   │ :/Ptr │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │   ⌫   │ ↹/Nav │Esc/⇧  │   │ ↵/Fun │Spc/Sym│ ⌦/Num │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

**Combo:** O + Y = !

---

## Layer 1: NAV (Navigation & Clipboard)

Activation: Hold Tab

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│ ⌘+Z   │ ⌘+X   │ ⌘+C   │ ⌘+V   │⌘+⇧+Z  │   │xxxxxx │ ⌘+←   │   ↑   │ ⌘+→   │Bright↑│
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│  ⌃    │  ⌥    │  ⌘    │  ⇧    │ ⌘+D   │   │ Caps  │   ←   │   ↓   │   →   │Bright↓│
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│xxxxxx │ RAlt  │xxxxxx │xxxxxx │xxxxxx │   │xxxxxx │  ⏮   │ Vol-  │ Vol+  │  ⏭   │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │xxxxxx │  ▼▼▼  │xxxxxx │   │  ⏹   │  ⏯   │ Mute  │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

---

## Layer 2: NUM (Numpad)

Activation: Hold Delete

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│  ``   │   7   │   8   │   9   │   \   │   │xxxxxx │xxxxxx │xxxxxx │xxxxxx │xxxxxx │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│   +   │   4   │   5   │   6   │   *   │   │xxxxxx │  ⇧    │  ⌘    │  ⌥    │  ⌃    │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│   -   │   1   │   2   │   3   │   /   │   │xxxxxx │xxxxxx │xxxxxx │ RAlt  │xxxxxx │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │   .   │   0   │   =   │   │xxxxxx │xxxxxx │  ▼▼▼  │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

---

## Layer 3: SYM (Symbols)

Activation: Hold Space. Auto-pair brackets type both and position cursor inside.

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│   ~   │   %   │   ^   │   _   │  []   │   │xxxxxx │xxxxxx │xxxxxx │xxxxxx │xxxxxx │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│ .\|   │   @   │   $   │   -   │  ()   │   │xxxxxx │SftSym │  ⌘    │  ⌥    │  ⌃    │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│   #   │   &   │   €   │   =   │  {}   │   │xxxxxx │xxxxxx │xxxxxx │ RAlt  │xxxxxx │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │   <   │  Nav  │   >   │   │xxxxxx │  ▼▼▼  │xxxxxx │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

**Note:** `.\|` = Tap for `\`, Hold for `|`

---

## Layer 4: FUN (Function Keys)

Activation: Hold Enter

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│xxxxxx │  F7   │  F8   │  F9   │  F12  │   │xxxxxx │xxxxxx │xxxxxx │xxxxxx │xxxxxx │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│xxxxxx │  F4   │  F5   │  F6   │  F11  │   │xxxxxx │  ⇧    │  ⌘    │  ⌥    │  ⌃    │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│xxxxxx │  F1   │  F2   │  F3   │  F10  │   │xxxxxx │xxxxxx │xxxxxx │ RAlt  │xxxxxx │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │xxxxxx │ ⌘⇧5   │ ⌘⇧4   │   │  ▼▼▼  │xxxxxx │xxxxxx │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

**Note:** `⌘⇧4` = Mac screenshot shortcut

---

## Layer 5: SFT_SYM (Individual Brackets)

Activation: Hold SftSym from SYM layer. Provides single brackets without auto-pairing.

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│xxxxxx │xxxxxx │xxxxxx │   [   │   ]   │   │xxxxxx │xxxxxx │xxxxxx │xxxxxx │xxxxxx │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│xxxxxx │xxxxxx │xxxxxx │   (   │   )   │   │xxxxxx │  ▼▼▼  │xxxxxx │xxxxxx │xxxxxx │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│xxxxxx │xxxxxx │xxxxxx │   {   │   }   │   │xxxxxx │xxxxxx │xxxxxx │xxxxxx │xxxxxx │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │xxxxxx │xxxxxx │xxxxxx │   │xxxxxx │  ▼▼▼  │xxxxxx │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

---

## Layer 6: POINTER (Mouse & Trackpad)

Activation: Hold Z or : (colon)

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│ Boot  │EE_CLR │xxxxxx │ DPI+  │Snipe+ │   │Snipe+ │ DPI+  │xxxxxx │EE_CLR │ Boot  │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│  ⌘    │  ⌥    │  ⌃    │  ⇧    │xxxxxx │   │xxxxxx │  ⇧    │  ⌃    │  ⌥    │  ⌘    │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│  ▼▼▼  │DrgScrl│ Snipe │ Btn3  │xxxxxx │   │xxxxxx │ Btn3  │ Snipe │DrgScrl│  ▼▼▼  │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │ Btn3  │ Btn2  │ Btn1  │   │ Btn1  │ Btn2  │ Btn3  │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

**Notes:**
- `Boot` = Enter bootloader for firmware flashing
- `EE_CLR` = Clear EEPROM settings
- `DPI+` = Increase pointer sensitivity
- `Snipe+` = Increase sniping mode sensitivity
- `Snipe` = Enable precision/sniping mode
- `DrgScrl` = Enable drag-scroll mode

---

## Layer 7: DIAC_ACUTE (Hold F)

Produces acute accents. Press E position for é/É.

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│______ │______ │______ │xxxxxx │______ │   │______ │______ │______ │______ │______ │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │   é   │______ │______ │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │______ │______ │______ │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │______ │______ │______ │   │______ │______ │______ │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

---

## Layer 8: DIAC_RGRAVE (Hold P)

Produces grave accents on right hand. Press E for è/È, U for ù/Ù.

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│______ │______ │xxxxxx │______ │______ │   │______ │______ │______ │______ │______ │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │   è   │______ │   ù   │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │______ │______ │______ │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │______ │______ │______ │   │______ │______ │______ │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

---

## Layer 9: DIAC_LGRAVE (Hold O)

Produces grave accents on left hand. Press A for à/À.

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│______ │______ │______ │______ │______ │   │______ │______ │xxxxxx │______ │______ │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│   à   │______ │______ │______ │______ │   │______ │______ │______ │______ │______ │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │______ │______ │______ │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │______ │______ │______ │   │______ │______ │______ │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

---

## Layer 10: DIAC_RCIRC (Hold W)

Produces circumflex accents on right hand. Press O for ô/Ô, E for ê/Ê, I for î/Î, U for û/Û.

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│______ │xxxxxx │______ │______ │______ │   │______ │______ │   ô   │______ │______ │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │   ê   │   î   │   û   │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │______ │______ │______ │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │______ │______ │______ │   │______ │______ │______ │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

---

## Layer 11: DIAC_LCIRC (Hold Y)

Produces circumflex accents on left hand. Press A for â/Â.

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│______ │______ │______ │______ │______ │   │______ │______ │______ │xxxxxx │______ │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│   â   │______ │______ │______ │______ │   │______ │______ │______ │______ │______ │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │______ │______ │______ │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │______ │______ │______ │   │______ │______ │______ │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

---

## Layer 12: DIAC_TREMA (Hold G)

Produces diaeresis/trema accents. Press E for ë/Ë, I for ï/Ï, U for ü/Ü, Y for ÿ/Ÿ.

```
╭───────┬───────┬───────┬───────┬───────╮   ╭───────┬───────┬───────┬───────┬───────╮
│______ │______ │______ │______ │xxxxxx │   │______ │______ │______ │   ÿ   │______ │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │   ë   │   ï   │   ü   │
├───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┤
│______ │______ │______ │______ │______ │   │______ │______ │______ │______ │______ │
╰───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────╯
                │______ │______ │______ │   │______ │______ │______ │
                ╰───────┴───────┴───────╯   ╰───────┴───────┴───────╯
```

---

## Special Features

### Cedilla (ç)

The C key has a hold-tap behavior:
- **Tap C** = c
- **Hold C** = ç/Ç (shift-aware for uppercase)

### Auto-Pair Brackets

From the SYM layer, these keys type both brackets and position the cursor inside:
- `[]` = Types `[]` with cursor between
- `()` = Types `()` with cursor between
- `{}` = Types `{}` with cursor between
- ``` `` ``` = Types backticks with cursor between

For individual brackets without auto-pairing, hold SftSym to access layer 5.

### Shift-Aware Diacritics

All accented characters support uppercase via CapsLock:
- Normal tap = lowercase (é, è, ê, etc.)
- With Shift held = uppercase (É, È, Ê, etc.)

### Trackpad Features

- **Sniping mode**: Precision pointing for fine control
- **Drag-scroll**: Move trackpad to scroll instead of move cursor
- **Natural scrolling**: Scroll direction is inverted for natural feel

## Customizing

### DPI Settings

Use these keycodes from the POINTER layer:
- `DPI_MOD`: Increase default pointer DPI
- `S_D_MOD`: Increase sniping mode DPI

### Firmware Flashing

1. Enter bootloader: Press `Boot` on POINTER layer (top corners)
2. Flash using: `qmk flash -kb bastardkb/dilemma/3x5_3_procyon -km artggd`
