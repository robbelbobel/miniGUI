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

miniGUI::Text* miniGUI::TextWidget::getText(){
    return miniGUI::TextWidget::text;
}

void miniGUI::TextWidget::__draw(SDL_Renderer* renderer){
    miniGUI::TextWidget::text -> __draw(renderer, miniGUI::Widget::rect);
}