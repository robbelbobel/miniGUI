#include "../include/layer.hpp"

miniGUI::Layer::Layer(){
    return;
}

void miniGUI::Layer::addWidget(miniGUI::Widget* widget){
    if(widget == nullptr) return;

    miniGUI::Layer::widgets.push_back(widget);
}

bool miniGUI::Layer::removeWidget(miniGUI::Widget* widget){
    for(uint8_t i = 0; i < miniGUI::Layer::widgets.size(); i++){
        if(miniGUI::Layer::widgets.at(i) == widget){
            miniGUI::Layer::widgets.erase(miniGUI::Layer::widgets.begin() + i);
            return true;
        }
    }

    return false;
}

void miniGUI::Layer::clear(){
    miniGUI::Layer::widgets.clear();
}

void miniGUI::Layer::__update(__InputState_t* inputState){
    // Update Every Widget
    for(size_t i = 0; i < miniGUI::Layer::widgets.size(); i++) miniGUI::Layer::widgets.at(i) -> __update(inputState);
}

void miniGUI::Layer::__draw(SDL_Renderer* renderer){
    // Draw Every Widget
    for(size_t i = 0; i < miniGUI::Layer::widgets.size(); i++) miniGUI::Layer::widgets.at(i) -> __draw(renderer);
}