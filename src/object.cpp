#include "object.h"
#include <algorithm>

namespace RayEngine::Renderable {

    Object::Object() : position({0, 0}), children() {}

    Object::Object(Vector2 position) : position(position), children() {}

    Object::~Object() {
        clearChildren();
    }

    void Object::setPosition(const Vector2 &position) {
        this->position = position;
    }

    Vector2 Object::getPosition() const {
        return position;
    }

    void Object::addChild(Object *child) {
        if (
            child == nullptr ||
            std::find(children.begin(), children.end(), child) != children.end()
        ) { return; }
        
        children.push_back(child);
    }

    void Object::removeChild(Object *child) {
        auto it = std::find(children.begin(), children.end(), child);
        if (it != children.end()) {
            delete *it;
            children.erase(it);
        }
    }

    void Object::clearChildren() {
        for (Object *child : children) { delete child; }
        children.clear();
    }

    const std::vector<Object*>& Object::getChildren() const {
        return children;
    }

    void Object::move(const Vector2 &offset) {
        setPosition({position.x + offset.x, position.y + offset.y});
    }

    void Object::init() {
        initSelf();
        for (Object *child : children) {
            if (child != nullptr) { child->init(); }
        }
    }

    void Object::update() {
        updateSelf();
        for (Object *child : children) {
            if (child != nullptr) { child->update(); }
        }
    }

    void Object::draw() {
        drawSelf(position);
        for (Object *child : children) {
            if (child != nullptr) { child->draw(position); }
        }
    }

    void Object::draw(const Vector2 &offset) {
        drawSelf({position.x + offset.x, position.y + offset.y});
        for (Object *child : children) {
            if (child != nullptr) { child->draw({position.x + offset.x, position.y + offset.y}); }
        }
    }
    
}