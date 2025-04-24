#ifndef RENDERABLE_H
#define RENDERABLE_H

class Renderable {
public:
    Renderable() = default;
    virtual ~Renderable() = default;

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif
