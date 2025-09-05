#ifndef SCENE2D_H
#define SCENE2D_H
#include "Scene.h"

namespace RayEngine::Scene {

    class Scene2D : public Scene {
    public:
        enum class FIT_MODE {
            SHRINK, EXPAND
        };

    private:
        Camera2D camera;
        FIT_MODE fitMode;

        const int baseHeight, baseWidth;
        float baseZoom, zoomMult;

        void calcBaseZoom();

    public:
        Scene2D(int baseHeight, int baseWidth);
        explicit Scene2D(int baseHeight, int baseWidth, const Color &color);

        ~Scene2D() override = default;

        void setCameraPosition(const Vector2 &position);
        void setCameraRotation(float rotation);
        void setCameraZoom(float zoom);
        void setFitMode(FIT_MODE fitMode);

        void moveCamera(const Vector2 &offset);
        void rotateCamera(float rotation);

        void updateScene() override;
        void drawScene() const override;
    };

}

#endif //SCENE2D_H
