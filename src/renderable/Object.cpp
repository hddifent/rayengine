#include "Object.h"

#include <algorithm>
#include <stdexcept>

#include "../exceptions/exceptions.h"

namespace RayEngine::Renderable {
    void Object::draw(const Vector2 &offset) {
        drawSelf(Vector2{position.x + offset.x, position.y + offset.y});
        for (const std::unique_ptr<Object> &obj : children) {
            if (obj != nullptr) { obj->draw(Vector2{position.x + offset.x, position.y + offset.y}); }
        }
    }

    void Object::drawSelf(const Vector2 &offset) {
        renderer->render(offset);
    }

    Object::Object(const std::shared_ptr<Renderer> &renderer) : position(Vector2{0, 0}), renderer(renderer) {}

    Object::Object(const std::shared_ptr<Renderer> &renderer, const Vector2 &position) : position(position), renderer(renderer) {}

    Object::~Object() {
        clearChildren();
    }

    Vector2 Object::getPosition() const {
        return position;
    }

    const std::vector<std::unique_ptr<Object>> &Object::getChildren() const {
        return children;
    }

    void Object::setPosition(const Vector2 &position) {
        this->position = position;
    }

    Object* Object::addChild(std::unique_ptr<Object> child) {
        if (!child) { return nullptr; }

        Object *rawPtr = child.get();
        children.push_back(std::move(child));

        return rawPtr;
    }

    void Object::removeChild(const Object *child) {
        const auto it = std::find_if(
            children.begin(),
            children.end(),
            [child](const std::unique_ptr<Object>& ptr) {
                return ptr.get() == child;
        });

        if (it != children.end()) {
            children.erase(it);
        }
        else {
            throw std::runtime_error("Child does not exist in list.");
        }
    }

    void Object::removeChild(const unsigned int index) {
        if (index < children.size()) {
            children.erase(children.begin() + index);
        }
        else {
            throw index_out_of_range_exception();
        }
    }

    void Object::clearChildren() {
        children.clear();
    }

    void Object::move(const Vector2 &offset) {
        position = Vector2{position.x + offset.x, position.y + offset.y};
    }

    void Object::init() {
        initSelf();
        for (const std::unique_ptr<Object> &obj : children) {
            if (obj) { obj->init(); }
        }
    }

    void Object::update() {
        updateSelf();
        for (const std::unique_ptr<Object> &obj : children) {
            if (obj) { obj->update(); }
        }
    }

    void Object::draw() {
        drawSelf(position);
        for (const std::unique_ptr<Object> &obj : children) {
            if (obj) { obj->draw(position); }
        }
    }
}
