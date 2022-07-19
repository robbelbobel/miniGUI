#include "textButtonWidget.hpp"

miniGUI::TextButtonWidget::TextButtonWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::Text* text, uint32_t color) : miniGUI::ButtonWidget::ButtonWidget(position, size, color){
    miniGUI::TextButtonWidget::text = text;
}

void miniGUI::TextButtonWidget::__draw(SDL_Renderer* renderer){
    // Draw Base Button
    miniGUI::ButtonWidget::__draw(renderer);

    // Draw Text
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, miniGUI::TextButtonWidget::text -> __getSurface());

    SDL_Rect destRect;
    destRect.w = miniGUI::TextButtonWidget::text -> __getSurface() -> w;
    destRect.h = miniGUI::TextButtonWidget::text -> __getSurface() -> h;
    destRect.x = miniGUI::Widget::rect.x + (miniGUI::Widget::rect.w / 2) - (destRect.w / 2);
    destRect.y = miniGUI::Widget::rect.y + (miniGUI::Widget::rect.h / 2) - (destRect.h / 2);

    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    // Destroy Texture
    SDL_DestroyTexture(texture);
}