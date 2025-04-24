#ifndef SCENE_CONTROLLER_H
#define SCENE_CONTROLLER_H

#include "headers/scene.h"

class SceneController {
private:
    Scene* currentScene;

public:
    SceneController();
    SceneController(const SceneController &other) = delete; // Disable copy constructor

    virtual ~SceneController();

    void setCurrentScene(Scene *scene);
    Scene* getCurrentScene() const;

    void updateScene();
    void drawScene();
};

#endif