#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H
#include <string>

#include "Renderer.h"

namespace RayEngine::Renderable {

    class TextRenderer : public Renderer {
    private:
        std::string text;
        int fontSize;
        Color color;

    protected:
        Vector2 translateWithAnchor(const Vector2 &position) override;
        void draw(const Vector2 &position) override;

    public:
        TextRenderer();
        explicit TextRenderer(std::string text);
        TextRenderer(std::string text, int fontSize, Color color);

        [[nodiscard]] std::string getText() const;
        [[nodiscard]] int getFontSize() const;
        [[nodiscard]] Color getColor() const;

        void setText(const std::string &text);
        void setFontSize(int fontSize);
        void setColor(const Color &color);
    };

}

#endif //TEXTRENDERER_H
