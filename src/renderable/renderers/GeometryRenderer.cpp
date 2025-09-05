#include "GeometryRenderer.h"

namespace RayEngine::Renderable {
    GeometryRenderer::GeometryRenderMode GeometryRenderer::getMode() const {
        return mode;
    }

    GeometryRenderer::GeometryRenderer(
        const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> &translatorFunction,
        const GeometryRenderMode &mode) : Renderer(translatorFunction), mode(mode) {}

    GeometryRenderer::GeometryRenderer(
        const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> &translatorFunction,
        const GeometryRenderMode &mode,
        const Color &color) : Renderer(translatorFunction, color), mode(mode) {}

    void GeometryRenderer::setRenderMode(const GeometryRenderMode &mode) {
        this->mode = mode;
    }
}
