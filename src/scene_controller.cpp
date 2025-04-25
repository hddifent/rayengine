#include "scene_controller.h"

namespace RayEngine::Scene {

    SceneController::SceneController() : currentScene(nullptr) {}

    SceneController::~SceneController() {
        if (currentScene != nullptr) { delete currentScene; }
    }

    void SceneController::setCurrentScene(Scene *scene) {
        if (scene == nullptr) { return; }
        if (currentScene != nullptr) { delete currentScene; }
        currentScene = scene;
        currentScene->loadScene();
        currentScene->initScene();
    }

    Scene* SceneController::getCurrentScene() const {
        return currentScene;
    }

    void SceneController::updateScene() {
        if (currentScene != nullptr) { currentScene->updateScene(); }
    }

    void SceneController::drawScene() {
        if (currentScene != nullptr) { currentScene->drawScene(); }
    }

}
