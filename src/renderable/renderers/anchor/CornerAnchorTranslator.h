#ifndef CORNERANCHORTRANSLATOR_H
#define CORNERANCHORTRANSLATOR_H
#include "AnchorTranslator.h"

namespace RayEngine::Renderable {

    class CornerAnchorTranslator final : public AnchorTranslator {
    public:
        [[nodiscard]] Vector2 translateWithAnchor(
            const Vector2 &position,
            const Vector2 &size,
            const Anchor &anchor) const override;
    };

}

#endif //CORNERANCHORTRANSLATOR_H
