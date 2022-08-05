#include "../../../include/widgets/shapes/rectangleShapeWidget.hpp"

miniGUI::RectangleShapeWidget::RectangleShapeWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, uint32_t color) : miniGUI::ShapeWidget(position, size, color){
    return;
}

void miniGUI::RectangleShapeWidget::__draw(SDL_Renderer* renderer){
    SDL_Rect rect = miniGUI::Widget::rect;

    SDL_SetRenderDrawColor(renderer, miniGUI::ShapeWidget::color.r, miniGUI::ShapeWidget::color.g, miniGUI::ShapeWidget::color.b, miniGUI::ShapeWidget::color.a);
    SDL_RenderFillRect(renderer, &rect);
}