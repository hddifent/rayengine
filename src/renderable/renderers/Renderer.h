#ifndef RENDERER_H
#define RENDERER_H
#include <functional>
#include <raylib.h>

#include "anchor/Anchor.h"

namespace RayEngine::Renderable {

    class Renderer {
    private:
        Color color;

        Anchor anchor;
        const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> translatorFunction;

    protected:
        [[nodiscard]] Anchor getAnchor() const;
        [[nodiscard]] const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> &getTranslatorFunction() const;

        virtual Vector2 translateWithAnchor(const Vector2 &position) = 0;
        virtual void draw(const Vector2 &position) = 0;

        explicit Renderer(const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> &translatorFunction);
        Renderer(const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> &translatorFunction, const Color &color);

    public:
        virtual ~Renderer();

        [[nodiscard]] Color getColor() const;

        void setColor(const Color &color);
        void setAnchor(Anchor anchor);

        void render(const Vector2 &position);
    };

}

#endif //RENDERER_H
