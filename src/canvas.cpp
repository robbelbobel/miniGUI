#include "../include/canvas.hpp"

miniGUI::Canvas::Canvas(){
    return;
}

void miniGUI::Canvas::addLayer(miniGUI::Layer* layer){
    if(layer == nullptr) return;

    miniGUI::Canvas::layers.push_back(layer);
}

bool miniGUI::Canvas::removeLayer(miniGUI::Layer* layer){
    for(uint8_t i = 0; i < miniGUI::Canvas::layers.size(); i++){
        if(miniGUI::Canvas::layers.at(i) == layer){
            miniGUI::Canvas::layers.erase(miniGUI::Canvas::layers.begin() + i);
            return true;
        }
    }

    return false;
}

void miniGUI::Canvas::clear(){
    miniGUI::Canvas::layers.clear();
}

void miniGUI::Canvas::__update(__InputState_t* inputState){
    // Only Update Top Layer
    miniGUI::Canvas::layers.back() -> __update(inputState);
}

void miniGUI::Canvas::__draw(SDL_Renderer* renderer){
    // Draw Every Layer
    for(size_t i = 0; i < miniGUI::Canvas::layers.size(); i++) miniGUI::Canvas::layers.at(i) -> __draw(renderer);
}