#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include <raylib.h>
#include "renderable.h"

namespace RayEngine::Renderable {

    /**
     * @brief Abstract renderable object with position and children.
     * 
     * This class is used to define the interface of all renderable objects that have a position
     * on the screen. Its children are anchored to the position of the parent object.
     * 
     */
    class Object : public Renderable {
    private:
        Vector2 position;
        std::vector<Object*> children;

        /// @brief Draws the object and its children with an offset.
        /// @param offset The offset to draw the object and its children at.
        void draw(const Vector2 &offset);

    protected:
        /// @brief Initializes the object itself.
        virtual void initSelf() = 0;
        /// @brief Updates the object itself.
        virtual void updateSelf() = 0;
        /// @brief Draws the object itself.
        virtual void drawSelf(const Vector2 &anchor) = 0;

    public:
        Object();
        Object(Vector2 position);
        
        virtual ~Object() override;
        
        void setPosition(const Vector2 &position);
        Vector2 getPosition() const;

        void addChild(Object *child);
        void removeChild(Object *child);
        void clearChildren();
        const std::vector<Object*> &getChildren() const;

        /// @brief Moves the object by the given offset.
        /// @param offset The offset to move the object by.
        void move(const Vector2 &offset);

        /// @brief Initializes the object and its children.
        void init() override;
        /// @brief Updates the object and its children.
        void update() override;
        /// @brief Draws the object and its children.
        void draw() override;
    };

}

#endif
