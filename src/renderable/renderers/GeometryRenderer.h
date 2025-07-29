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

    public:
        GeometryRenderer(const AnchorTranslator *translator, const GeometryRenderMode &mode);
        GeometryRenderer(const AnchorTranslator *translator, const GeometryRenderMode &mode, const Color &color);

        void setRenderMode(const GeometryRenderMode &mode);
    };
}

#endif //GEOMETRYRENDERER_H
