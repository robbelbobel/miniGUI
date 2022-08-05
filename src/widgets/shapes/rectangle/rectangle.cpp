#include "rectangle.hpp"

miniGUI::Rectangle::Rectangle(miniGUI::Vector2i position, miniGUI::Vector2i size, uint32_t color) : miniGUI::Shape(position, size, color){

}

void miniGUI::Rectangle::__draw(SDL_Renderer* renderer){
    SDL_Rect rect = miniGUI::Widget::rect;

    SDL_SetRenderDrawColor(renderer, miniGUI::Shape::color.r, miniGUI::Shape::color.g, miniGUI::Shape::color.b, miniGUI::Shape::color.a);
    SDL_RenderFillRect(renderer, &rect);
}