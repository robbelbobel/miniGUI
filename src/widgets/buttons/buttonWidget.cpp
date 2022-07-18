#include "buttonWidget.hpp"

miniGUI::ButtonWidget::ButtonWidget(Vector2i size){
    miniGUI::ButtonWidget::clicked  = false;
    miniGUI::ButtonWidget::hovering = false;

    miniGUI::ButtonWidget::size = size;
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
    if( inputState -> mousePosition.x > miniGUI::ButtonWidget::position.x && inputState -> mousePosition.x < miniGUI::ButtonWidget::position.x + miniGUI::ButtonWidget::size.x &&
        inputState -> mousePosition.y > miniGUI::ButtonWidget::position.y && inputState -> mousePosition.y < miniGUI::ButtonWidget::position.y + miniGUI::ButtonWidget::size.y){
            miniGUI::ButtonWidget::hovering = true;

            miniGUI::ButtonWidget::clicked = miniGUI::ButtonWidget::clicked ? true : inputState -> clicked;
    }else{
        miniGUI::ButtonWidget::hovering = false;
    }
}