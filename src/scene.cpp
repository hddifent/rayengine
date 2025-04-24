#include <algorithm>
#include <stdexcept>

#include "scene.h"

namespace RayEngine::Scene {

    void Scene::updateScene() {
        for (RayEngine::Renderable::Renderable *renderable : renderables) {
            if (renderable != nullptr) { renderable->update(); }
        }
    }

    void Scene::drawScene() {
        ClearBackground(backgroundColor);
        for (RayEngine::Renderable::Renderable *renderable : renderables) {
            if (renderable != nullptr) { renderable->draw(); }
        }
    }

    void Scene::unloadScene() {
        clearRenderables();
    }

    Scene::Scene(SceneController *sceneController) : sceneController(sceneController), backgroundColor(BLACK) {
        loadScene();
    }

    Scene::~Scene() {
        unloadScene();
    }

    SceneController* Scene::getSceneController() const {
        return sceneController;
    }

    void Scene::setBackgroundColor(Color color) {
        backgroundColor = color;
    }

    Color Scene::getBackgroundColor() const {
        return backgroundColor;
    }

    void Scene::addRenderable(RayEngine::Renderable::Renderable *renderable) {
        if (renderable == nullptr) { return; }
        renderables.push_back(renderable);
    }

    void Scene::removeRenderable(RayEngine::Renderable::Renderable *renderable) {
        auto it = std::find(renderables.begin(), renderables.end(), renderable);
        if (it != renderables.end()) {
            delete *it;
            renderables.erase(it);
        }
    }

    void Scene::clearRenderables() {
        for (RayEngine::Renderable::Renderable *renderable : renderables) { delete renderable; }
        renderables.clear();
    }

    const std::vector<RayEngine::Renderable::Renderable*>& Scene::getRenderables() const {
        return renderables;
    }

    void Scene::replaceScene(Scene *scene) {
        if (scene == nullptr) { return; }
        if (sceneController == nullptr) { throw std::runtime_error("Scene has no attached Scene Controller."); }
        sceneController->setCurrentScene(scene);
    }

}