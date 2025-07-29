#ifndef CIRCLERENDERER_H
#define CIRCLERENDERER_H
#include "GeometryRenderer.h"

namespace RayEngine::Renderable {

    class CircleRenderer : public GeometryRenderer {
    private:
        float radius;

    protected:
        Vector2 translateWithAnchor(const Vector2 &position) override;
        void draw(const Vector2 &position) override;

    public:
        explicit CircleRenderer(float radius);
        CircleRenderer(float radius, const Color &color);

        [[nodiscard]] float getRadius() const;

        void setRadius(float radius);
    };

}

#endif //CIRCLERENDERER_H
