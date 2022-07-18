#include "widget.hpp"

miniGUI::Widget::Widget(){
    /** INITIALIZE CLASS VARIABLES **/
    // Enabling
    miniGUI::Widget::enabled = true;

    miniGUI::Widget::position   = Vector2i(0, 0);
    miniGUI::Widget::size       = Vector2i(0, 0);
}

void miniGUI::Widget::setPosition(miniGUI::Vector2i position){
    miniGUI::Widget::position = position;
}

void miniGUI::Widget::setSize(miniGUI::Vector2i size){
    miniGUI::Widget::size = size;
}

void miniGUI::Widget::__update(__InputState_t* inputState){
    return;
}

void miniGUI::Widget::__draw(){
    return;
}