#include "Object.h"

#include <algorithm>
#include <stdexcept>

#include "../exceptions/exceptions.h"

namespace RayEngine::Renderable {
    void Object::draw(const Vector2 &offset) {
        drawSelf(Vector2{position.x + offset.x, position.y + offset.y});
        for (Object *obj : children) {
            if (obj != nullptr) { obj->draw(Vector2{position.x + offset.x, position.y + offset.y}); }
        }
    }

    void Object::drawSelf(const Vector2 &offset) {
        renderer->render(offset);
    }

    Object::Object(Renderer *renderer) : position(Vector2{0, 0}), renderer(renderer) {}

    Object::Object(Renderer *renderer, const Vector2 &position) : position(position), renderer(renderer) {}

    Object::~Object() {
        delete renderer;
        clearChildren();
    }

    Vector2 Object::getPosition() const {
        return position;
    }

    const std::vector<Object*> &Object::getChildren() const {
        return children;
    }

    void Object::setPosition(const Vector2 &position) {
        this->position = position;
    }

    Object* Object::addChild(Object *child) {
        if (child == nullptr) { return nullptr; }
        if (std::find(children.begin(), children.end(), child) != children.end()) {
            return child;
        }

        children.push_back(child);
        return child;
    }

    void Object::removeChild(const Object *child) {
        if (const auto it = std::find(children.begin(), children.end(), child); it != children.end()) {
            delete *it;
            children.erase(it);
        }
        else {
            throw std::runtime_error("Child does not exist in list.");
        }
    }

    void Object::removeChild(const unsigned int index) {
        if (index < children.size()) {
            const auto it = children.begin() + index;
            delete *it;
            children.erase(it);
        }
        else {
            throw index_out_of_range_exception();
        }
    }

    void Object::clearChildren() {
        for (const Object *obj : children) {
            delete obj;
        }
        children.clear();
    }

    void Object::move(const Vector2 &offset) {
        position = Vector2{position.x + offset.x, position.y + offset.y};
    }

    void Object::init() {
        initSelf();
        for (Object *obj : children) {
            if (obj != nullptr) { obj->init(); }
        }
    }

    void Object::update() {
        updateSelf();
        for (Object *obj : children) {
            if (obj != nullptr) { obj->update(); }
        }
    }

    void Object::draw() {
        drawSelf(position);
        for (Object *obj : children) {
            if (obj != nullptr) { obj->draw(position); }
        }
    }
}
