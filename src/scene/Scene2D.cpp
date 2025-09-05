#include "Scene2D.h"

#include <stdexcept>

namespace RayEngine::Scene {
    void Scene2D::calcBaseZoom() {
        const float scaleX = static_cast<float>(GetScreenWidth()) / baseWidth;
        const float scaleY = static_cast<float>(GetScreenHeight()) / baseHeight;

        switch (fitMode) {
            case FIT_MODE::SHRINK:
                baseZoom = std::min(scaleX, scaleY);
                break;
            case FIT_MODE::EXPAND:
                baseZoom = std::max(scaleX, scaleY);
                break;
        }

        setCameraZoom(zoomMult);
    }

    Scene2D::Scene2D(const int baseHeight, const int baseWidth) : Scene2D(baseHeight, baseWidth, BLACK) {}

    Scene2D::Scene2D(const int baseHeight, const int baseWidth, const Color &color) :
        Scene(color),
        camera(Camera2D{Vector2{0, 0}, Vector2{0, 0}, 0, 1}),
        fitMode(FIT_MODE::SHRINK),
        baseHeight(baseHeight),
        baseWidth(baseWidth),
        baseZoom(1),
        zoomMult(1) {
        calcBaseZoom();
    }

    void Scene2D::setCameraPosition(const Vector2 &position) {
        camera.offset = position;
        camera.target = position;
    }

    void Scene2D::setCameraRotation(const float rotation) {
        camera.rotation = rotation;
    }

    void Scene2D::setCameraZoom(const float zoom) {
        if (zoom < 0) {
            throw std::invalid_argument("Invalid argument: zoom cannot be lower than 0");
        }
        zoomMult = zoom;
        camera.zoom = baseZoom * zoomMult;
    }

    void Scene2D::setFitMode(const FIT_MODE fitMode) {
        this->fitMode = fitMode;
    }

    void Scene2D::moveCamera(const Vector2 &offset) {
        setCameraPosition(Vector2{camera.offset.x + offset.x, camera.offset.y + offset.y });
    }

    void Scene2D::rotateCamera(float rotation) {
        setCameraRotation(camera.rotation + rotation);
    }

    void Scene2D::updateScene() {
        if (IsWindowResized()) { calcBaseZoom(); }
        Scene::updateScene();
    }

    void Scene2D::drawScene() const {
        BeginMode2D(camera);
        Scene::drawScene();
        EndMode2D();
    }
}
