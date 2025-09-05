#ifndef ANCHORTRANSLATORFUNCTION_H
#define ANCHORTRANSLATORFUNCTION_H
#include <functional>
#include <raylib.h>

#include "Anchor.h"

namespace RayEngine::Renderable {
    inline const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> getCircleTranslator() {
        return [](const Vector2 &position, const Vector2 &size, const Anchor &anchor) {
            if (anchor == Anchor::CENTER) { return position; }

            const Vector2 halfSize = Vector2{size.x / 2, size.y / 2};
            const int iAnchor = static_cast<int>(anchor);

            const int xOffMult = iAnchor % 3 - 1;
            const int yOffMult = iAnchor / 3 - 1;

            return Vector2{position.x + halfSize.x * xOffMult, position.y + halfSize.y * yOffMult};
        };
    }

    inline const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> getRectTranslator() {
        return [](const Vector2 &position, const Vector2 &size, const Anchor &anchor) {
            if (anchor == Anchor::TOP_LEFT) { return position; }

            const Vector2 halfSize = Vector2{size.x / 2, size.y / 2};
            const int iAnchor = static_cast<int>(anchor);

            const int xOffMult = iAnchor % 3;
            const int yOffMult = iAnchor / 3;

            const float offX = xOffMult == 1 ? halfSize.x : xOffMult == 2 ? size.x : 0;
            const float offY = yOffMult == 1 ? halfSize.y : xOffMult == 2 ? size.y : 0;

            return Vector2{position.x - offX, position.y - offY};
        };
    }

}

#endif //ANCHORTRANSLATORFUNCTION_H
