#ifndef DULL_OBJECT_H
#define DULL_OBJECT_H

#include "object.h"

namespace RayEngine::Renderable {

    /**
     * @brief A dull object that does not do anything.
     * 
     * Dull objects do not do anything themselves.
     * It could be used as a container for other objects. (as hierachy or render layer)
     */
    class DullObject : public Object {
    protected:
        void initSelf() override final;
        void updateSelf() override final;
        void drawSelf(const Vector2 &anchor) override final;
    };

}

#endif