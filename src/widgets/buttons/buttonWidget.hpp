#ifndef BUTTONWIDGET_HPP
#define BUTTONWIDGET_HPP

#include <SDL.h>

#include "../widget.hpp"

namespace miniGUI{
    class ButtonWidget : public Widget{
    public:
        bool isClicked();
        bool isHovering();

        virtual void __update(__InputState_t* inputState);
        virtual void __draw(SDL_Renderer* renderer);

    protected:
        ButtonWidget(Vector2i position, Vector2i size, uint32_t color);

        bool clicked;
        bool hovering;
        SDL_Color color;
    };
}

#endif