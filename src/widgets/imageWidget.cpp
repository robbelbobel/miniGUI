#include "../../include/widgets/imageWidget.hpp"

miniGUI::ImageWidget::ImageWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::ImageElement* imageElement) : miniGUI::Widget::Widget(position, size){
    miniGUI::ImageWidget::setImageElement(imageElement);
}

miniGUI::ImageWidget::~ImageWidget(){
    return;
}

void miniGUI::ImageWidget::setImageElement(miniGUI::ImageElement* imageElement){
    miniGUI::ImageWidget::imageElement = imageElement;
}

miniGUI::ImageElement* miniGUI::ImageWidget::getImageElement(){
    return miniGUI::ImageWidget::imageElement;
}

void miniGUI::ImageWidget::__draw(SDL_Renderer* renderer){
    miniGUI::ImageWidget::imageElement -> __draw(renderer, miniGUI::Widget::rect);
}