#ifndef ANCHOR_H
#define ANCHOR_H

namespace RayEngine::Renderable {

    enum class Anchor {
        TOP_LEFT = 0, TOP_CENTER, TOP_RIGHT,
        MIDDLE_LEFT, CENTER, MIDDLE_RIGHT,
        BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT
    };

}

#endif //ANCHOR_H
