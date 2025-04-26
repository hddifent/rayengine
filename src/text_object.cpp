#include "text_object.h"

namespace RayEngine::Renderable {

    TextObject::TextObject() : Object(), text(""), fontSize(20), color(RAYWHITE) {}

    TextObject::TextObject(Vector2 position) : Object(position), text(""), fontSize(20), color(RAYWHITE) {}

    TextObject::TextObject(std::string text) : Object(), text(text), fontSize(20), color(RAYWHITE) {}

    TextObject::TextObject(std::string text, int fontSize) : Object(), text(text), fontSize(fontSize), color(RAYWHITE) {}

    TextObject::TextObject(std::string text, int fontSize, Color color) : Object(), text(text), fontSize(fontSize), color(color) {}

    TextObject::TextObject(const char *text) : Object(), text(text), fontSize(20), color(RAYWHITE) {}

    TextObject::TextObject(const char *text, int fontSize) : Object(), text(text), fontSize(fontSize), color(RAYWHITE) {}

    TextObject::TextObject(const char *text, int fontSize, Color color) : Object(), text(text), fontSize(fontSize), color(color) {}

    void TextObject::initSelf() {}

    void TextObject::updateSelf() {}

    void TextObject::drawSelf(const Vector2 &anchor) {
        DrawText(text.c_str(), (int)(anchor.x), (int)(anchor.y), fontSize, color);
    }

    void TextObject::setText(std::string newText) {
        text = newText;
    }

    void TextObject::setText(const char *newText) {
        text = newText;
    }

    void TextObject::setColor(Color newColor) {
        color = newColor;
    }

    void TextObject::setFontSize(int newFontSize) {
        fontSize = newFontSize;
    }

    std::string TextObject::getText() const {
        return text;
    }

    Color TextObject::getColor() const {
        return color;
    }

    int TextObject::getFontSize() const {
        return fontSize;
    }

}