#ifndef SCREEN_UTIL_H
#define SCREEN_UTIL_H

#include "raylib.h"

typedef struct ScalingInfo {
    Vector2 offset;
    Vector2 size;

    float scale;
} ScalingInfo;

ScalingInfo getScalingInfo(int refWidth, int refHeight, int renWidth, int renHeight);

Vector2 getScaledScreenPos(Vector2 refPos, ScalingInfo scalingInfo);

bool positionInBound(Vector2 refPos, ScalingInfo scalingInfo, int refWidth, int refHeight);

#endif