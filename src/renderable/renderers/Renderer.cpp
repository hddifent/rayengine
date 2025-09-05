#include "Renderer.h"

namespace RayEngine::Renderable {
    Anchor Renderer::getAnchor() const {
        return anchor;
    }

    const std::function<Vector2(const Vector2 &, const Vector2 &, const Anchor &)>& Renderer::getTranslatorFunction() const {
        return translatorFunction;
    }

    Renderer::Renderer(const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> &translatorFunction) :
        color(WHITE), anchor(Anchor::CENTER), translatorFunction(translatorFunction) {}

    Renderer::Renderer(const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> &translatorFunction, const Color &color) :
        color(color), anchor(Anchor::CENTER), translatorFunction(translatorFunction) {}

    Renderer::~Renderer() = default;

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
