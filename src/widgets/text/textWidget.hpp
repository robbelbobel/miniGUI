#ifndef TEXTWIDGET_HPP
#define TEXTWIDGET_HPP

#include <string>

#include "../widget.hpp"
#include "../../text/text.hpp"

namespace miniGUI{
    class TextWidget : public Widget{
    public:
        TextWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::Text* text);
        ~TextWidget();

        void setText(miniGUI::Text* text);
        miniGUI::Text* getText();

        virtual void __draw(SDL_Renderer* renderer);

    private:
        miniGUI::Text* text;
    };
}

#endif