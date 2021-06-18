### QMK keymap for split 3x5_3 layouts

Currently supports Crkbd, and the Planck.

```
make keyboard=crkbd/rev1/common
make keyboard=planck/rev6

# use the below to flash
make flash keyboard=...
```

#### Features

1. Colemak DH(m) Base layer
2. Home Row Mods on both hands in the Base layer, left hand in Navigation layers
3. Symbols layer are arranged using the Colemak DH heatmap (guesstimated)
4. Combined Navigation cluster and Numpad layer for Vim motions
5. Numpad layer layout optimized for doing maths
6. Combined Mouse navigation and Function layer
7. Tap Dance keys for Capslock, Double Quotes and Backslash
8. Nav/Num and Mouse/Fun layer locking

#### Extras

- Valorant and Apex Legends alternate sweat-lord base layer
- OLED, RGB, and Audio support

### About

Heavily based on the keymaps and code from [manna-harbour/miryoku](https://github.com/rstacruz/my_qmk_keymaps) and [rstacruz/my_qmk_keymaps](https://github.com/rstacruz/my_qmk_keymaps).

Homerow mods implementation based off of [A guide to home row mods](https://precondition.github.io/home-row-mods).
