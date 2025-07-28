#include "CornerAnchorTranslator.h"

namespace RayEngine::Renderable {
    Vector2 CornerAnchorTranslator::translateWithAnchor(
        const Vector2 &position,
        const Vector2 &size,
        const Anchor &anchor) const {
        if (anchor == Anchor::TOP_LEFT) { return position; }

        const Vector2 halfSize = Vector2{size.x / 2, size.y / 2};
        const int iAnchor = static_cast<int>(anchor);

        const int xOffMult = iAnchor % 3;
        const int yOffMult = iAnchor / 3;

        const float offX = xOffMult == 1 ? halfSize.x : xOffMult == 2 ? size.x : 0;
        const float offY = yOffMult == 1 ? halfSize.y : xOffMult == 2 ? size.y : 0;

        return Vector2{position.x - offX, position.y - offY};
    }
}
