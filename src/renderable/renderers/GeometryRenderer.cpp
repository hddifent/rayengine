#include "GeometryRenderer.h"

namespace RayEngine::Renderable {
    GeometryRenderer::GeometryRenderMode GeometryRenderer::getMode() const {
        return mode;
    }

    GeometryRenderer::GeometryRenderer(
        const AnchorTranslator *translator,
        const GeometryRenderMode &mode) : Renderer(translator), mode(mode) {}

    void GeometryRenderer::setRenderMode(const GeometryRenderMode &mode) {
        this->mode = mode;
    }
}
