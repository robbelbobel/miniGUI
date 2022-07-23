#include "textButtonWidget.hpp"

miniGUI::TextButtonWidget::TextButtonWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::Text* text, uint32_t color) : miniGUI::ButtonWidget::ButtonWidget(position, size){
    miniGUI::TextButtonWidget::text = text;

    miniGUI::TextButtonWidget::color.r = (color  & 0xFF000000)  >> 24;
    miniGUI::TextButtonWidget::color.g = (color & 0xFF0000)     >> 16;
    miniGUI::TextButtonWidget::color.b = (color & 0xFF00)       >> 8;
    miniGUI::TextButtonWidget::color.a =  color & 0xFF;
}

miniGUI::Text* miniGUI::TextButtonWidget::getText(){
    return miniGUI::TextButtonWidget::text;
}

void miniGUI::TextButtonWidget::setText(miniGUI::Text* text){
    miniGUI::TextButtonWidget::text = text;
}

void miniGUI::TextButtonWidget::__draw(SDL_Renderer* renderer){
    // Draw Background
    SDL_Rect rect = miniGUI::Widget::rect;

    SDL_SetRenderDrawColor(renderer, miniGUI::TextButtonWidget::color.r, miniGUI::TextButtonWidget::color.g, miniGUI::TextButtonWidget::color.b, miniGUI::TextButtonWidget::color.a);
    SDL_RenderFillRect(renderer, &rect);

    miniGUI::TextButtonWidget::text -> __draw(renderer, miniGUI::TextButtonWidget::rect);
}