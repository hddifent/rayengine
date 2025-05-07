#include "keybind.h"

bool holdingTriggers(Keybind bind) {
    return (
        (bind.ctrl && (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL))) ||
        !bind.ctrl
    ) &&
    (
        (bind.alt && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT))) ||
        !bind.alt
    ) &&
    (
        (bind.shift && (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))) ||
        !bind.shift
    );
}

bool isKeybindPressed(Keybind bind) {
    return IsKeyPressed(bind.key) && holdingTriggers(bind);
}

bool isKeybindReleased(Keybind bind) {
    return IsKeyReleased(bind.key) && holdingTriggers(bind);
}

bool isKeybindDown(Keybind bind) {
    return IsKeyDown(bind.key) && holdingTriggers(bind);
}

bool isKeybindUp(Keybind bind) {
    return IsKeyUp(bind.key) && holdingTriggers(bind);
}
