#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <raylib.h>
#include "renderable.h"
#include "scene_controller.h"

namespace RayEngine {

    /** 
     * @brief Namespace for all scene related classes and functions.
     * 
     */
    namespace Scene {
        class SceneController;
        
        /**
         * @brief Abstract class of a scene. (Collection of Renderable objects)
         * 
         * This class is used to define the interface of all scenes used in the engine.
         * The load method is pure virtual and must be implemented by the derived classes.
         * 
         */
        class Scene {
        friend class SceneController;

        private:
            SceneController *sceneController;
            std::vector<RayEngine::Renderable::Renderable*> renderables;

            Color backgroundColor;

        protected:
            /// @brief Loads the scene. Called once by SceneController when Scene is created.
            virtual void loadScene() = 0;
            void initScene();
            void updateScene();
            void drawScene();
            void unloadScene();
            
        public:
            Scene(SceneController *sceneController);
            Scene(const Scene &other) = delete; // Disable copy constructor
            
            virtual ~Scene();

            /// @brief Get the SceneController this scene is attached to.
            SceneController *getSceneController() const;

            /// @brief Set the background color of the scene.
            void setBackgroundColor(Color color);
            /// @brief Get the background color of the scene.
            Color getBackgroundColor() const;

            /// @brief Adds a renderable object to the scene.
            void addRenderable(RayEngine::Renderable::Renderable *renderable);
            /// @brief Removes a renderable object from the scene.
            void removeRenderable(RayEngine::Renderable::Renderable *renderable);
            /// @brief Clears all renderable objects from the scene.
            void clearRenderables();
            /// @brief Get the list of renderable objects in the scene.
            const std::vector<RayEngine::Renderable::Renderable*> &getRenderables() const;

            /// @brief Replace, destroy, and replace the current scene.
            /// @param scene The new scene to replace the current scene with.
            void replaceScene(Scene *scene);
        };

    }
    
}

#endif