#ifndef RENDERABLE_H
#define RENDERABLE_H

namespace RayEngine::Renderable {

class Renderable {
public:
    Renderable();
    virtual ~Renderable();

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};

}

#endif
