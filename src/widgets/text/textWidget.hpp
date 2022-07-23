#ifndef TEXTWIDGET_HPP
#define TEXTWIDGET_HPP

#include <string>

#include "../widget.hpp"
#include "../../text/Text.hpp"

namespace miniGUI{
    class TextWidget : public Widget{
    public:
        TextWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::Text* text);
        ~TextWidget();

        void setText(miniGUI::Text* text);

        virtual void __draw(SDL_Renderer* renderer);

    private:
        miniGUI::Text* text;
    };
}

#endif