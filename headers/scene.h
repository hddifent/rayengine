#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <raylib.h>
#include "headers/renderable.h"
#include "headers/scene_controller.h"

class Scene {
friend class SceneController;

private:
    SceneController *sceneController;
    std::vector<Renderable*> renderables;

    Color backgroundColor;

protected:
    virtual void loadScene() = 0;
    void updateScene();
    void drawScene();
    void unloadScene();
    
public:
    Scene(SceneController *sceneController);
    Scene(const Scene &other) = delete; // Disable copy constructor
    
    virtual ~Scene();

    SceneController *getSceneController() const;

    void setBackgroundColor(Color color);
    Color getBackgroundColor() const;

    void addRenderable(Renderable *renderable);
    void removeRenderable(Renderable *renderable);
    void clearRenderables();
    const std::vector<Renderable*> &getRenderables() const;

    void replaceScene(Scene *scene);
};

#endif