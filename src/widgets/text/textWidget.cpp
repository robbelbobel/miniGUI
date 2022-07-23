#include "textWidget.hpp"

miniGUI::TextWidget::TextWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::Text* text) : miniGUI::Widget::Widget(position, size){
    miniGUI::TextWidget::setText(text);
}

miniGUI::TextWidget::~TextWidget(){
    ;
}

void miniGUI::TextWidget::setText(miniGUI::Text*text){
    miniGUI::TextWidget::text = text;
}

void miniGUI::TextWidget::__draw(SDL_Renderer* renderer){
    
}