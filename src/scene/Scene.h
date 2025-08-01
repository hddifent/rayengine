#ifndef SCENE_H
#define SCENE_H
#include <memory>
#include <raylib.h>
#include <vector>

#include "../renderable/Renderable.h"

namespace RayEngine::Scene {

    class Scene {
    private:
        Color backgroundColor;

        std::vector<std::unique_ptr<Renderable::Renderable>> renderables;

    protected:
        virtual void loadScene() = 0;

    public:
        Scene();
        explicit Scene(const Color &color);

        virtual ~Scene() = default;

        [[nodiscard]] Color getBackgroundColor() const;
        [[nodiscard]] const std::vector<std::unique_ptr<Renderable::Renderable>> &getRenderables() const;

        void setColor(const Color &color);

        Renderable::Renderable *addRenderable(std::unique_ptr<Renderable::Renderable> renderable);
        void removeRenderable(const Renderable::Renderable *child);
        void removeRenderable(unsigned int index);
        void clearRenderables();

        void initScene() const;
        void updateScene() const;
        void drawScene() const;
    };

}

#endif //SCENE_H
