#include "CircleRenderer.h"

#include "anchor/CenterAnchorTranslator.h"

namespace RayEngine::Renderable {
    CircleRenderer::CircleRenderer(const float radius) :
        GeometryRenderer(new CenterAnchorTranslator(), GeometryRenderMode::FILLED),
        radius(radius),
        color(WHITE) {}

    CircleRenderer::CircleRenderer(const float radius, const Color &color) :
        GeometryRenderer(new CenterAnchorTranslator(), GeometryRenderMode::FILLED),
        radius(radius),
        color(color) {}

    float CircleRenderer::getRadius() const {
        return radius;
    }

    Color CircleRenderer::getColor() const {
        return color;
    }

    void CircleRenderer::setRadius(const float radius) {
        this->radius = radius;
    }

    void CircleRenderer::setColor(const Color &color) {
        this->color = color;
    }

    Vector2 CircleRenderer::translateWithAnchor(const Vector2 &position) {
        return getAnchorTranslator()->translateWithAnchor(position, Vector2{radius, radius}, getAnchor());
    }

    void CircleRenderer::draw(const Vector2 &position) {
        switch (getMode()) {
            case GeometryRenderMode::FILLED:
                DrawCircleV(position, radius, color);
                break;
            case GeometryRenderMode::LINE:
                DrawCircleLines(position.x, position.y, radius, color);
                break;
        }
    }
}
