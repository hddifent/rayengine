#include <algorithm>
#include <stdexcept>

#include "headers/scene.h"

void Scene::updateScene() {
    for (Renderable *renderable : renderables) {
        if (renderable != nullptr) { renderable->update(); }
    }
}

void Scene::drawScene() {
    ClearBackground(backgroundColor);
    for (Renderable *renderable : renderables) {
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

void Scene::addRenderable(Renderable *renderable) {
    if (renderable == nullptr) { return; }
    renderables.push_back(renderable);
}

void Scene::removeRenderable(Renderable *renderable) {
    auto it = std::find(renderables.begin(), renderables.end(), renderable);
    if (it != renderables.end()) {
        delete *it;
        renderables.erase(it);
    }
}

void Scene::clearRenderables() {
    for (Renderable *renderable : renderables) { delete renderable; }
    renderables.clear();
}

const std::vector<Renderable*>& Scene::getRenderables() const {
    return renderables;
}

void Scene::replaceScene(Scene *scene) {
    if (scene == nullptr) { return; }
    if (sceneController == nullptr) { throw std::runtime_error("Scene has no attached Scene Controller."); }
    sceneController->setCurrentScene(scene);
}
