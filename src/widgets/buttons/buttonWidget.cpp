#include "buttonWidget.hpp"

miniGUI::ButtonWidget::ButtonWidget(miniGUI::Vector2i position, miniGUI::Vector2i size) : miniGUI::Widget(position, size){
    miniGUI::ButtonWidget::clicked  = false;
    miniGUI::ButtonWidget::hovering = false;
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
    ;
}