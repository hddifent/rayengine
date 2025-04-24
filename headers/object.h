#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include <raylib.h>
#include "headers/renderable.h"

class Object : public Renderable {
private:
    Vector2 position;
    std::vector<Object*> children;

protected:
    virtual void drawSelf() = 0;

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

    void move(const Vector2 &offset);

    void draw() override;
};

#endif
