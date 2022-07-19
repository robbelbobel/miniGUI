#ifndef TEXTBUTTONWIDGET_HPP
#define TEXTBUTTONWIDGET_HPP

#include "buttonWidget.hpp"
#include "../../text/text.hpp"

namespace miniGUI{
    class TextButtonWidget : public ButtonWidget{
    public:
        TextButtonWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::Text* text);

        Text* getText();

        virtual void __draw(SDL_Renderer* renderer);

    private:
        Text* text;
    };
}
#endif