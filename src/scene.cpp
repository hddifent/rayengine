#include <algorithm>
#include <stdexcept>

#include "scene.h"

namespace RayEngine::Scene {

    void Scene::initScene() {
        for (RayEngine::Renderable::Renderable *renderable : renderables) {
            if (renderable != nullptr) { renderable->init(); }
        }
    }

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
    
    Scene::Scene(SceneController *sceneController, RayEngine::Audio::AudioController *audioController) :
        sceneController(sceneController),
        audioController(audioController),
        backgroundColor(BLACK) {}

    Scene::~Scene() {
        unloadScene();
    }

    SceneController* Scene::getSceneController() const {
        return sceneController;
    }

    RayEngine::Audio::AudioController* Scene::getAudioController() const {
        return audioController;
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