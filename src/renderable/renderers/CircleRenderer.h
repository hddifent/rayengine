#ifndef CIRCLERENDERER_H
#define CIRCLERENDERER_H
#include "GeometryRenderer.h"

namespace RayEngine::Renderable {

    class CircleRenderer : public GeometryRenderer {
    private:
        float radius;
        Color color;

    protected:
        Vector2 translateWithAnchor(const Vector2 &position) override;
        void draw(const Vector2 &position) override;

    public:
        explicit CircleRenderer(float radius);
        CircleRenderer(float radius, const Color &color);

        [[nodiscard]] float getRadius() const;
        [[nodiscard]] Color getColor() const;

        void setRadius(float radius);
        void setColor(const Color &color);
    };

}

#endif //CIRCLERENDERER_H
