#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "../widget.hpp"

namespace miniGUI{
    class Shape : public miniGUI::Widget{
    public:
        virtual void __draw(SDL_Renderer* renderer);
    
    protected:
        Shape(Vector2i position, Vector2i size, uint32_t color);

        SDL_Color color;
    };
}

#endif