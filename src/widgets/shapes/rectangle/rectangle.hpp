#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../../../vector/vector.hpp"
#include "../shape.hpp"

namespace miniGUI{
    class Rectangle : public miniGUI::Shape{
    public:
        Rectangle(miniGUI::Vector2i position, miniGUI::Vector2i size, uint32_t color);

        virtual void __draw(SDL_Renderer* renderer);
    };
}

#endif