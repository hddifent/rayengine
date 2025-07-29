#include "Renderer.h"

namespace RayEngine::Renderable {
    Anchor Renderer::getAnchor() const {
        return anchor;
    }

    const AnchorTranslator *Renderer::getAnchorTranslator() const {
        return anchorTranslator;
    }

    Renderer::Renderer(const AnchorTranslator *anchorTranslator) :
        color(WHITE), anchor(Anchor::CENTER), anchorTranslator(anchorTranslator) {}

    Renderer::Renderer(const AnchorTranslator *anchorTranslator, const Color &color) :
        color(color), anchor(Anchor::CENTER), anchorTranslator(anchorTranslator) {}

    Renderer::~Renderer() {
        delete anchorTranslator;
    }

    Color Renderer::getColor() const {
        return color;
    }

    void Renderer::setColor(const Color &color) {
        this->color = color;
    }

    void Renderer::setAnchor(const Anchor anchor) {
        this->anchor = anchor;
    }

    void Renderer::render(const Vector2 &position) {
        const Vector2 drawPos = translateWithAnchor(position);
        draw(drawPos);
    }
}
