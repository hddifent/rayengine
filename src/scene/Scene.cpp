#include "Scene.h"

#include <algorithm>
#include <stdexcept>

#include "../exceptions/exceptions.h"

namespace RayEngine::Scene {
    Scene::Scene() : backgroundColor(BLACK) {}

    Scene::Scene(const Color &color) : backgroundColor(color) {}

    Color Scene::getBackgroundColor() const {
        return backgroundColor;
    }

    const std::vector<std::unique_ptr<Renderable::Renderable>> & Scene::getRenderables() const {
        return renderables;
    }

    void Scene::setColor(const Color &color) {
        this->backgroundColor = color;
    }

    Renderable::Renderable *Scene::addRenderable(std::unique_ptr<Renderable::Renderable> renderable) {
        if (!renderable) { return nullptr; }

        Renderable::Renderable *rawPtr = renderable.get();
        renderables.push_back(std::move(renderable));

        return rawPtr;
    }

    void Scene::removeRenderable(const Renderable::Renderable *child) {
        const auto it = std::find_if(
            renderables.begin(),
            renderables.end(),
            [child](const std::unique_ptr<Renderable::Renderable>& ptr) {
                return ptr.get() == child;
        });

        if (it != renderables.end()) {
            renderables.erase(it);
        }
        else {
            throw std::runtime_error("Child does not exist in list.");
        }
    }

    void Scene::removeRenderable(unsigned int index) {
        if (index < renderables.size()) {
            renderables.erase(renderables.begin() + index);
        }
        else {
            throw index_out_of_range_exception();
        }
    }

    void Scene::clearRenderables() {
        renderables.clear();
    }

    void Scene::initScene() const {
        for (const std::unique_ptr<Renderable::Renderable> &renderable : renderables) {
            if (renderable) { renderable->init(); }
        }
    }

    void Scene::updateScene() const {
        for (const std::unique_ptr<Renderable::Renderable> &renderable : renderables) {
            if (renderable) { renderable->update(); }
        }
    }

    void Scene::drawScene() const {
        for (const std::unique_ptr<Renderable::Renderable> &renderable : renderables) {
            if (renderable) { renderable->draw(); }
        }
    }
}
