#ifndef ANCHORTRANSLATOR_H
#define ANCHORTRANSLATOR_H
#include <raylib.h>

#include "Anchor.h"

namespace RayEngine::Renderable {
    class AnchorTranslator {
    protected:
        AnchorTranslator();

    public:
        virtual ~AnchorTranslator() = default;

        [[nodiscard]] virtual Vector2 translateWithAnchor(
            const Vector2 &position,
            const Vector2 &size,
            const Anchor &anchor) const = 0;
    };

}

#endif //ANCHORTRANSLATOR_H
