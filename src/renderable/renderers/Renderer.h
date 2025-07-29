#ifndef RENDERER_H
#define RENDERER_H
#include <raylib.h>

#include "anchor/Anchor.h"
#include "anchor/AnchorTranslator.h"

namespace RayEngine::Renderable {

    class Renderer {
    private:
        Color color;

        Anchor anchor;
        const AnchorTranslator *anchorTranslator;

    protected:
        [[nodiscard]] Anchor getAnchor() const;
        [[nodiscard]] const AnchorTranslator *getAnchorTranslator() const;

        virtual Vector2 translateWithAnchor(const Vector2 &position) = 0;
        virtual void draw(const Vector2 &position) = 0;

    public:
        explicit Renderer(const AnchorTranslator *anchorTranslator);
        Renderer(const AnchorTranslator *anchorTranslator, const Color &color);
        virtual ~Renderer();

        [[nodiscard]] Color getColor() const;

        void setColor(const Color &color);
        void setAnchor(Anchor anchor);

        void render(const Vector2 &position);
    };

}

#endif //RENDERER_H
