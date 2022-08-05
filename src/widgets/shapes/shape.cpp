#include "../../../include/widgets/shapes/shapeWidget.hpp"

miniGUI::ShapeWidget::ShapeWidget(Vector2i position, Vector2i size, uint32_t color) : Widget(position, size){
    miniGUI::ShapeWidget::color.r = (color & 0xFF000000)  >> 24;
    miniGUI::ShapeWidget::color.g = (color & 0xFF0000)    >> 16;
    miniGUI::ShapeWidget::color.b = (color & 0xFF00)      >> 8;
    miniGUI::ShapeWidget::color.a =  color & 0xFF;
}

void miniGUI::ShapeWidget::__draw(SDL_Renderer* renderer){
    return;
}