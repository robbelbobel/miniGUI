#include "../../../include/widgets/buttons/imageButtonWidget.hpp"

miniGUI::ImageButtonWidget::ImageButtonWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::ImageElement* ImageElement) : miniGUI::ButtonWidget::ButtonWidget(position, size){
    miniGUI::ImageButtonWidget::imageElement = ImageElement;
}

miniGUI::ImageElement* miniGUI::ImageButtonWidget::getImageElement(){
    return miniGUI::ImageButtonWidget::imageElement;
}

void miniGUI::ImageButtonWidget::setImageElement(miniGUI::ImageElement* imageElement){
    miniGUI::ImageButtonWidget::imageElement = imageElement;
}

void miniGUI::ImageButtonWidget::__draw(SDL_Renderer* renderer){
    miniGUI::ImageButtonWidget::imageElement -> __draw(renderer, miniGUI::ImageButtonWidget::rect);
}