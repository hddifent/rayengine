#include "Renderer.h"

namespace RayEngine::Renderable {
    Anchor Renderer::getAnchor() const {
        return anchor;
    }

    const AnchorTranslator *Renderer::getAnchorTranslator() const {
        return anchorTranslator;
    }

    Renderer::Renderer(const AnchorTranslator *anchorTranslator) :
        anchor(Anchor::CENTER), anchorTranslator(anchorTranslator) {}

    Renderer::~Renderer() {
        delete anchorTranslator;
    }

    void Renderer::setAnchor(const Anchor anchor) {
        this->anchor = anchor;
    }

    void Renderer::render(const Vector2 &position) {
        const Vector2 drawPos = translateWithAnchor(position);
        draw(drawPos);
    }
}
