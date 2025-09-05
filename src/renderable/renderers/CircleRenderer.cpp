#include "CircleRenderer.h"

#include "anchor/AnchorTranslatorFunction.h"

namespace RayEngine::Renderable {
    CircleRenderer::CircleRenderer(const float radius) :
        GeometryRenderer(getCircleTranslator(), GeometryRenderMode::FILLED),
        radius(radius) {}

    CircleRenderer::CircleRenderer(const float radius, const Color &color) :
        GeometryRenderer(getCircleTranslator(), GeometryRenderMode::FILLED, color),
        radius(radius) {}

    float CircleRenderer::getRadius() const {
        return radius;
    }

    void CircleRenderer::setRadius(const float radius) {
        this->radius = radius;
    }

    Vector2 CircleRenderer::translateWithAnchor(const Vector2 &position) {
        return getTranslatorFunction()(position, Vector2{radius, radius}, getAnchor());
    }

    void CircleRenderer::draw(const Vector2 &position) {
        switch (getMode()) {
            case GeometryRenderMode::FILLED:
                DrawCircleV(position, radius, getColor());
                break;
            case GeometryRenderMode::LINE:
                DrawCircleLines(position.x, position.y, radius, getColor());
                break;
        }
    }
}
