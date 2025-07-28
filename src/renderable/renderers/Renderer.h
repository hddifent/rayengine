#ifndef RENDERER_H
#define RENDERER_H
#include <raylib.h>

#include "anchor/Anchor.h"
#include "anchor/AnchorTranslator.h"

namespace RayEngine::Renderable {

    class Renderer {
    private:
        Anchor anchor;
        const AnchorTranslator *anchorTranslator;

    protected:
        [[nodiscard]] Anchor getAnchor() const;
        [[nodiscard]] const AnchorTranslator *getAnchorTranslator() const;

        virtual Vector2 translateWithAnchor(const Vector2 &position) = 0;
        virtual void draw(const Vector2 &position) = 0;

    public:
        explicit Renderer(const AnchorTranslator *anchorTranslator);
        virtual ~Renderer();

        void setAnchor(Anchor anchor);

        void render(const Vector2 &position);
    };

}

#endif //RENDERER_H
