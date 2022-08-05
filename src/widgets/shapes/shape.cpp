#include "shape.hpp"

miniGUI::Shape::Shape(Vector2i position, Vector2i size, uint32_t color) : Widget(position, size){
    miniGUI::Shape::color.r = (color & 0xFF000000)  >> 24;
    miniGUI::Shape::color.g = (color & 0xFF0000)    >> 16;
    miniGUI::Shape::color.b = (color & 0xFF00)      >> 8;
    miniGUI::Shape::color.a =  color & 0xFF;
}

void miniGUI::Shape::__draw(SDL_Renderer* renderer){
    return;
}