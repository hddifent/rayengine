#include "CenterAnchorTranslator.h"

namespace RayEngine::Renderable {
    Vector2 CenterAnchorTranslator::translateWithAnchor(
        const Vector2 &position,
        const Vector2 &size,
        const Anchor &anchor) const {
        if (anchor == Anchor::CENTER) { return position; }

        const Vector2 halfSize = Vector2{size.x / 2, size.y / 2};
        const int iAnchor = static_cast<int>(anchor);

        const int xOffMult = iAnchor % 3 - 1;
        const int yOffMult = iAnchor / 3 - 1;

        return Vector2{position.x + halfSize.x * xOffMult, position.y + halfSize.y * yOffMult};
    }
}
