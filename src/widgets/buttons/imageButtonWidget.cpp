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
    // Draw Image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, miniGUI::ImageButtonWidget::image -> __getSurface());

    SDL_Rect destRect = miniGUI::ButtonWidget::rect;

    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    // Destroy Texture
    SDL_DestroyTexture(texture);
}