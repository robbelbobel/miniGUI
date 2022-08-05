#ifndef TEXTWIDGET_HPP
#define TEXTWIDGET_HPP

#include <string>

#include "widget.hpp"
#include "../elements/textElement.hpp"

namespace miniGUI{
    class TextWidget : public Widget{
    public:
        TextWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::TextElement* text);
        ~TextWidget();

        void setTextElement(miniGUI::TextElement* textElement);
        miniGUI::TextElement* getTextElement();

        virtual void __draw(SDL_Renderer* renderer);

    private:
        miniGUI::TextElement* textElement;
    };
}

#endif