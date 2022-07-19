#include "widget.hpp"

miniGUI::Widget::Widget(Vector2i position, Vector2i size){
    /** INITIALIZE CLASS VARIABLES **/
    // Enabling
    miniGUI::Widget::enabled = true;

    miniGUI::Widget::rect.x = position.x;
    miniGUI::Widget::rect.y = position.y;
    miniGUI::Widget::rect.w = size.x;
    miniGUI::Widget::rect.h = size.y;
}

void miniGUI::Widget::setPosition(miniGUI::Vector2i position){
    miniGUI::Widget::rect.x = position.x;
    miniGUI::Widget::rect.y = position.y;
}

void miniGUI::Widget::setSize(miniGUI::Vector2i size){
    miniGUI::Widget::rect.w = size.x;
    miniGUI::Widget::rect.h = size.y;
}

void miniGUI::Widget::__update(__InputState_t* inputState){
    return;
}

void miniGUI::Widget::__draw(SDL_Renderer* renderer){
    return;
}