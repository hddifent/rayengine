#include "TextureRenderer.h"

#include "anchor/AnchorTranslatorFunction.h"

namespace RayEngine::Renderable {
    Vector2 TextureRenderer::translateWithAnchor(const Vector2 &position) {
        const Vector2 size = Vector2{static_cast<float>(texture.width), static_cast<float>(texture.height)};
        return getTranslatorFunction()(position, size, getAnchor());
    }

    void TextureRenderer::draw(const Vector2 &position) {
        DrawTextureV(texture, position, getColor());
    }

    TextureRenderer::TextureRenderer(Texture2D &texture) :
        Renderer(getRectTranslator()),
        texture(texture) {}

    TextureRenderer::TextureRenderer(Texture2D &texture, const Color &color) :
        Renderer(getRectTranslator(), color),
        texture(texture) {}

    const Texture2D & TextureRenderer::getTexture() const {
        return texture;
    }

    void TextureRenderer::setTexture(const Texture2D &texture) const {
        this->texture = texture;
    }
}
