#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include <string>

#include "object.h"

namespace RayEngine::Renderable {

    /**
     * @brief Wrapper class for text rendering.
     */
    class TextObject : public Object {
    private:
        std::string text;
        int fontSize;
        Color color;
    
    protected:
        void initSelf() override;
        void updateSelf() override;
        void drawSelf(const Vector2 &anchor) override;
    
    public:
        TextObject();
        TextObject(Vector2 position);

        TextObject(std::string text);
        TextObject(std::string text, int fontSize);
        TextObject(std::string text, int fontSize, Color color);

        TextObject(const char *text);
        TextObject(const char *text, int fontSize);
        TextObject(const char *text, int fontSize, Color color);

        void setText(std::string text);
        void setText(const char *text);
        void setColor(Color color);
        void setFontSize(int fontSize);

        std::string getText() const;
        Color getColor() const;
        int getFontSize() const;
    };

}

#endif