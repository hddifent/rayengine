#include "object.h"

#include <algorithm>
#include <stdexcept>

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

    Object* Object::addChild(Object *child) {
        if (child == nullptr) { return nullptr; }
        if (std::find(children.begin(), children.end(), child) != children.end()) { return child; }
        
        children.push_back(child);
        
        return child;
    }

    void Object::removeChild(Object *child) {
        auto it = std::find(children.begin(), children.end(), child);
        if (it != children.end()) {
            delete *it;
            children.erase(it);
        }
        else {
            throw std::runtime_error("Child not found in the list of children.");
        }
    }

    void Object::clearChildren() {
        for (Object *child : children) {
            if (child != nullptr) { delete child; }
        }
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