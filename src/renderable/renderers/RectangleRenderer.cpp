#include "RectangleRenderer.h"

#include "anchor/CornerAnchorTranslator.h"

namespace RayEngine::Renderable {
    RectangleRenderer::RectangleRenderer(const Vector2 &size) :
        GeometryRenderer(new CornerAnchorTranslator(), GeometryRenderMode::FILLED),
        size(size),
        color(WHITE) {}

    RectangleRenderer::RectangleRenderer(const Vector2 &size, const Color &color) :
        GeometryRenderer(new CornerAnchorTranslator(), GeometryRenderMode::FILLED),
        size(size),
        color(color) {}

    Vector2 RectangleRenderer::getSize() const {
        return size;
    }

    Color RectangleRenderer::getColor() const {
        return color;
    }

    void RectangleRenderer::setSize(const Vector2 &size) {
        this->size = size;
    }

    void RectangleRenderer::setColor(const Color &color) {
        this->color = color;
    }

    Vector2 RectangleRenderer::translateWithAnchor(const Vector2 &position) {
        return getAnchorTranslator()->translateWithAnchor(position, size, getAnchor());
    }

    void RectangleRenderer::draw(const Vector2 &position) {
        switch (getMode()) {
            case GeometryRenderMode::FILLED:
                DrawRectangleV(position, size, color);
                break;
            case GeometryRenderMode::LINE:
                DrawRectangleLines(position.x, position.y, size.x, size.y, color);
                break;
        }
    }
}
