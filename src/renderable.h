#ifndef RENDERABLE_H
#define RENDERABLE_H

namespace RayEngine {

    /**
     * @brief Namespace for all renderable objects in the engine.
     * 
     */
    namespace Renderable {
        /**
         * @brief Abstract class of a renderable object.
         * 
         * This class is used to define the interface of all renderable objects used in the engine.
         * The init, update, and draw methods are pure virtual and must be implemented by the derived classes.
         * 
         */
        class Renderable {
        public:
            Renderable() = default;
            virtual ~Renderable() = default;

            /// @brief Initializes the renderable object. Should be called once before the first update.
            virtual void init() = 0;
            /// @brief Updates the renderable object. Called every frame.
            virtual void update() = 0;
            /// @brief Draws the renderable object. Called every frame after update().
            virtual void draw() = 0;
        };

    }

}

#endif
