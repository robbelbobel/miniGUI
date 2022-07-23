#include "imageButtonWidget.hpp"

miniGUI::ImageButtonWidget::ImageButtonWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::Image* image) : miniGUI::ButtonWidget::ButtonWidget(position, size){
    miniGUI::ImageButtonWidget::image = image;
}

miniGUI::Image* miniGUI::ImageButtonWidget::getImage(){
    return miniGUI::ImageButtonWidget::image;
}

void miniGUI::ImageButtonWidget::setImage(miniGUI::Image* image){
    miniGUI::ImageButtonWidget::image = image;
}

void miniGUI::ImageButtonWidget::__draw(SDL_Renderer* renderer){
    miniGUI::ImageButtonWidget::image -> __draw(renderer, miniGUI::ImageButtonWidget::rect);
}