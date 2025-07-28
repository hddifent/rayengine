#include "TextRenderer.h"

#include <utility>

#include "anchor/CornerAnchorTranslator.h"

namespace RayEngine::Renderable {
    Vector2 TextRenderer::translateWithAnchor(const Vector2 &position) {
        const int textLength = MeasureText(text.c_str(), fontSize);
        const Vector2 size = Vector2{static_cast<float>(textLength), static_cast<float>(fontSize)};
        return getAnchorTranslator()->translateWithAnchor(position, size, getAnchor());
    }

    void TextRenderer::draw(const Vector2 &position) {
        DrawText(text.c_str(), position.x, position.y, fontSize, color);
    }

    TextRenderer::TextRenderer() :
        Renderer(new CornerAnchorTranslator()),
        fontSize(16),
        color(WHITE) {}

    TextRenderer::TextRenderer(std::string text) :
        Renderer(new CornerAnchorTranslator()),
        text(std::move(text)),
        fontSize(16),
        color(WHITE) {}

    TextRenderer::TextRenderer(std::string text, const int fontSize, const Color color) :
        Renderer(new CornerAnchorTranslator()),
        text(std::move(text)),
        fontSize(fontSize),
        color(color) {}

    std::string TextRenderer::getText() const {
        return text;
    }

    int TextRenderer::getFontSize() const {
        return fontSize;
    }

    Color TextRenderer::getColor() const {
        return color;
    }

    void TextRenderer::setText(const std::string &text) {
        this->text = text;
    }

    void TextRenderer::setFontSize(const int fontSize) {
        this->fontSize = fontSize;
    }

    void TextRenderer::setColor(const Color &color) {
        this->color = color;
    }
}
