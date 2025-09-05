#ifndef GEOMETRYRENDERER_H
#define GEOMETRYRENDERER_H
#include "Renderer.h"

namespace RayEngine::Renderable {

    class GeometryRenderer : public Renderer {
    public:
        enum class GeometryRenderMode {
            FILLED,
            LINE
        };

    private:
        GeometryRenderMode mode;

    protected:
        [[nodiscard]] GeometryRenderMode getMode() const;

        GeometryRenderer(const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> &translatorFunction, const GeometryRenderMode &mode);
        GeometryRenderer(const std::function<Vector2(const Vector2&, const Vector2&, const Anchor&)> &translatorFunction, const GeometryRenderMode &mode, const Color &color);

    public:

        void setRenderMode(const GeometryRenderMode &mode);
    };
}

#endif //GEOMETRYRENDERER_H
