#include "screen_util.h"

#include "cmath"

ScalingInfo getScalingInfo(int refWidth, int refHeight, int renWidth, int renHeight) {
    float widthScale = (float)renWidth / refWidth;
    float heightScale = (float)renHeight / refHeight;

    if (std::fabs(widthScale - heightScale) < 1e-6) {
        return ScalingInfo{
            Vector2{ 0, 0 },
            Vector2{ (float)refWidth, (float)renHeight },
            widthScale
        };
    }

    float scaling = widthScale < heightScale ? widthScale : heightScale;

    if (widthScale < heightScale) {
        return ScalingInfo{
            Vector2{ 0, -(renHeight - (refHeight * scaling)) / 2 },
            Vector2{ (float)renWidth, refHeight * scaling },
            scaling
        };
    }
    else {
        return ScalingInfo{
            Vector2{ -(renWidth - (refWidth * scaling)) / 2, 0 },
            Vector2{ refWidth * scaling, (float)renHeight },
            scaling
        };
    }
}

Vector2 getScaledScreenPos(Vector2 refPos, ScalingInfo scalingInfo) {
    return Vector2{
        (refPos.x + scalingInfo.offset.x) / scalingInfo.scale,
        (refPos.y + scalingInfo.offset.y) / scalingInfo.scale,
    };
}

bool positionInBound(Vector2 refPos, ScalingInfo scalingInfo, int refWidth, int refHeight) {
    Vector2 scrPos = getScaledScreenPos(refPos, scalingInfo);
    return (
        scrPos.x >= 0 && scrPos.x <= (float)refWidth &&
        scrPos.y >= 0 && scrPos.y <= (float)refHeight
    );
}