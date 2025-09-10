#ifndef TEXTURERENDERER_H
#define TEXTURERENDERER_H
#include "Renderer.h"

namespace RayEngine::Renderable {

    class TextureRenderer : public Renderer {
    private:
        Texture2D &texture;

    protected:
        Vector2 translateWithAnchor(const Vector2 &position) override;
        void draw(const Vector2 &position) override;

    public:
        explicit TextureRenderer(Texture2D &texture);
        TextureRenderer(Texture2D &texture, const Color &color);

        [[nodiscard]] const Texture2D &getTexture() const;

        void setTexture(const Texture2D &texture) const;
    };

}

#endif //TEXTURERENDERER_H
