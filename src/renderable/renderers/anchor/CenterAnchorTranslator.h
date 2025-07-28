#ifndef CENTERANCHORTRANSLATOR_H
#define CENTERANCHORTRANSLATOR_H
#include "AnchorTranslator.h"

namespace RayEngine::Renderable {

    class CenterAnchorTranslator final : public AnchorTranslator {
    public:
        [[nodiscard]] Vector2 translateWithAnchor(
            const Vector2 &position,
            const Vector2 &size,
            const Anchor &anchor) const override;
    };

}

#endif //CENTERANCHORTRANSLATOR_H
