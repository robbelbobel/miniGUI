#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../../vector.hpp"
#include "shapeWidget.hpp"

namespace miniGUI{
    class RectangleShapeWidget : public miniGUI::ShapeWidget{
    public:
        RectangleShapeWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, uint32_t color);

        virtual void __draw(SDL_Renderer* renderer);
    };
}

#endif