#include "../../include/widgets/textWidget.hpp"

miniGUI::TextWidget::TextWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::TextElement* text) : miniGUI::Widget::Widget(position, size){
    miniGUI::TextWidget::setTextElement(text);
}

miniGUI::TextWidget::~TextWidget(){
    return;
}

void miniGUI::TextWidget::setTextElement(miniGUI::TextElement* textElement){
    miniGUI::TextWidget::textElement = textElement;
}

miniGUI::TextElement* miniGUI::TextWidget::getTextElement(){
    return miniGUI::TextWidget::textElement;
}

void miniGUI::TextWidget::__draw(SDL_Renderer* renderer){
    miniGUI::TextWidget::textElement -> __draw(renderer, miniGUI::Widget::rect);
}