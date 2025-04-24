#ifndef SCENE_CONTROLLER_H
#define SCENE_CONTROLLER_H

#include "headers/scene.h"

namespace RayEngine::Scene {

    /**
     * @brief A controller class for managing scenes.
     * 
     * This class is used to control a given scene.
     * Must have a Scene object before calling the update and draw methods.
     * Practically, you should only have one instance of this class at any given time.
     * 
     */
    class SceneController {
    private:
        Scene* currentScene;

    public:
        SceneController();
        SceneController(const SceneController &other) = delete; // Disable copy constructor

        virtual ~SceneController();

        /// @brief Sets the current scene to the given scene.
        void setCurrentScene(Scene *scene);
        /// @brief Gets the current scene.
        Scene* getCurrentScene() const;

        /// @brief Updates the current scene. Should only be used in the main loop.
        void updateScene();
        /// @brief Draws the current scene. Should only be used in the main loop.
        void drawScene();
    };

}

#endif