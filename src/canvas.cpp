#include "../include/canvas.hpp"

miniGUI::Canvas::Canvas(){
    return;
}

void miniGUI::Canvas::addWidget(Widget* widget){
    if(widget == nullptr) return;

    miniGUI::Canvas::widgets.push_back(widget);
}

bool miniGUI::Canvas::removeWidget(Widget* widget){
    for(uint8_t i = 0; i < miniGUI::Canvas::widgets.size(); i++){
        if(miniGUI::Canvas::widgets.at(i) == widget){
            miniGUI::Canvas::widgets.erase(miniGUI::Canvas::widgets.begin() + i);
            return true;
        }
    }

    return false;
}

void miniGUI::Canvas::clear(){
    miniGUI::Canvas::widgets.clear();
}

void miniGUI::Canvas::__update(__InputState_t* inputState){
    // Update Every Widget
    for(size_t i = 0; i < miniGUI::Canvas::widgets.size(); i++) miniGUI::Canvas::widgets.at(i) -> __update(inputState);
}

void miniGUI::Canvas::__draw(SDL_Renderer* renderer){
    // Draw Every Widget
    for(size_t i = 0; i < miniGUI::Canvas::widgets.size(); i++) miniGUI::Canvas::widgets.at(i) -> __draw(renderer);
}