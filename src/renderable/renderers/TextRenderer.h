#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H
#include <string>

#include "Renderer.h"

namespace RayEngine::Renderable {

    class TextRenderer : public Renderer {
    private:
        std::string text;
        int fontSize;

    protected:
        Vector2 translateWithAnchor(const Vector2 &position) override;
        void draw(const Vector2 &position) override;

    public:
        TextRenderer();
        explicit TextRenderer(std::string text);
        TextRenderer(std::string text, int fontSize, const Color &color);

        [[nodiscard]] std::string getText() const;
        [[nodiscard]] int getFontSize() const;

        void setText(const std::string &text);
        void setFontSize(int fontSize);
    };

}

#endif //TEXTRENDERER_H
