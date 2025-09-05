#include "RectangleRenderer.h"

#include "anchor/AnchorTranslatorFunction.h"

namespace RayEngine::Renderable {
    RectangleRenderer::RectangleRenderer(const Vector2 &size) :
        GeometryRenderer(getRectTranslator(), GeometryRenderMode::FILLED),
        size(size) {}

    RectangleRenderer::RectangleRenderer(const Vector2 &size, const Color &color) :
        GeometryRenderer(getRectTranslator(), GeometryRenderMode::FILLED, color),
        size(size) {}

    Vector2 RectangleRenderer::getSize() const {
        return size;
    }

    void RectangleRenderer::setSize(const Vector2 &size) {
        this->size = size;
    }

    Vector2 RectangleRenderer::translateWithAnchor(const Vector2 &position) {
        return getTranslatorFunction()(position, size, getAnchor());
    }

    void RectangleRenderer::draw(const Vector2 &position) {
        switch (getMode()) {
            case GeometryRenderMode::FILLED:
                DrawRectangleV(position, size, getColor());
                break;
            case GeometryRenderMode::LINE:
                DrawRectangleLines(position.x, position.y, size.x, size.y, getColor());
                break;
        }
    }
}
