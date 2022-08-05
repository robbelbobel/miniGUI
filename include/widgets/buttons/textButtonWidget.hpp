#ifndef TEXTBUTTONWIDGET_HPP
#define TEXTBUTTONWIDGET_HPP

#include "buttonWidget.hpp"
#include "../../elements/textElement.hpp"

namespace miniGUI{
    class TextButtonWidget : public ButtonWidget{
    public:
        TextButtonWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::TextElement* textElement, uint32_t color = 0xFFFFFFFF);

        miniGUI::TextElement* getTextElement();
        void setTextElement(miniGUI::TextElement* textElement);

        virtual void __draw(SDL_Renderer* renderer);

    private:
        miniGUI::TextElement* textElement;

        SDL_Color color;
    };
}
#endif