#include "buttonWidget.hpp"

miniGUI::ButtonWidget::ButtonWidget(Vector2i position, Vector2i size, uint32_t color) : miniGUI::Widget(position, size){
    miniGUI::ButtonWidget::clicked  = false;
    miniGUI::ButtonWidget::hovering = false;

    miniGUI::ButtonWidget::color.r = (color  & 0xFF000000)  >> 24;
    miniGUI::ButtonWidget::color.g = (color & 0xFF0000)     >> 16;
    miniGUI::ButtonWidget::color.b = (color & 0xFF00)       >> 8;
    miniGUI::ButtonWidget::color.a =  color & 0xFF;
}

bool miniGUI::ButtonWidget::isClicked(){
    bool clicked = miniGUI::ButtonWidget::clicked;
    miniGUI::ButtonWidget::clicked = false;
    return clicked;
}

bool miniGUI::ButtonWidget::isHovering(){
    return miniGUI::ButtonWidget::hovering;
}

void miniGUI::ButtonWidget::__update(__InputState_t* inputState){
    if( inputState -> mousePosition.x > miniGUI::Widget::rect.x && inputState -> mousePosition.x < miniGUI::Widget::rect.x + miniGUI::Widget::rect.w &&
        inputState -> mousePosition.y > miniGUI::Widget::rect.y && inputState -> mousePosition.y < miniGUI::Widget::rect.y + miniGUI::Widget::rect.h){
            miniGUI::ButtonWidget::hovering = true;

            miniGUI::ButtonWidget::clicked = miniGUI::ButtonWidget::clicked ? true : inputState -> clicked;
    }else{
        miniGUI::ButtonWidget::hovering = false;
    }
}

void miniGUI::ButtonWidget::__draw(SDL_Renderer* renderer){
    // Render Button
    SDL_Rect rect = miniGUI::Widget::rect;

    SDL_SetRenderDrawColor(renderer, miniGUI::ButtonWidget::color.r, miniGUI::ButtonWidget::color.g, miniGUI::ButtonWidget::color.b, miniGUI::ButtonWidget::color.a);
    SDL_RenderFillRect(renderer, &rect);
}