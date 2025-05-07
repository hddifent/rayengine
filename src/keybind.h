#ifndef KEYBIND_H
#define KEYBIND_H

#include "raylib.h"

typedef struct Keybind {
    KeyboardKey key;
    bool ctrl;
    bool alt;
    bool shift;
} Keybind;

bool holdingTriggers(Keybind bind);

bool isKeybindPressed(Keybind bind);
bool isKeybindReleased(Keybind bind);
bool isKeybindDown(Keybind bind);
bool isKeybindUp(Keybind bind);

#endif