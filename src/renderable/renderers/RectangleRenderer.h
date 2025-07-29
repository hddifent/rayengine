#ifndef RECTANGLERENDERER_H
#define RECTANGLERENDERER_H
#include "GeometryRenderer.h"

namespace RayEngine::Renderable {

    class RectangleRenderer : public GeometryRenderer {
    private:
        Vector2 size;

    protected:
        Vector2 translateWithAnchor(const Vector2 &position) override;
        void draw(const Vector2 &position) override;

    public:
        explicit RectangleRenderer(const Vector2 &size);
        RectangleRenderer(const Vector2 &size, const Color &color);

        [[nodiscard]] Vector2 getSize() const;

        void setSize(const Vector2 &size);
    };

}

#endif //RECTANGLERENDERER_H
