#ifndef OBJECT_H
#define OBJECT_H

#include <memory>

#include "Renderable.h"
#include <raylib.h>
#include <vector>

#include "renderers/Renderer.h"

namespace RayEngine::Renderable {

	class Object : public Renderable {
	private:
		Vector2 position;
		std::vector<Object*> children;

		std::shared_ptr<Renderer> renderer;

		void draw(const Vector2 &offset);

	protected:
		virtual void initSelf() = 0;
		virtual void updateSelf() = 0;
		virtual void drawSelf(const Vector2 &offset);

	public:
		explicit Object(const std::shared_ptr<Renderer> &renderer);
		Object(const std::shared_ptr<Renderer> &renderer, const Vector2 &position);

		~Object() override;

		// Getters / Setters
		[[nodiscard]] Vector2 getPosition() const;
		[[nodiscard]] const std::vector<Object*> &getChildren() const;

		void setPosition(const Vector2 &position);

		// Class Methods
		Object *addChild(Object *child);
		void removeChild(const Object *child);
		void removeChild(unsigned int index);
		void clearChildren();

		void move(const Vector2 &offset);

		void init() final;
		void update() final;
		void draw() final;
	};

}

#endif //OBJECT_H
