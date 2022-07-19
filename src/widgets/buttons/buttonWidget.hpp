#ifndef BUTTONWIDGET_HPP
#define BUTTONWIDGET_HPP

#include <SDL.h>
#include <iostream> // DEBUG

#include "../widget.hpp"

namespace miniGUI{
    class ButtonWidget : public Widget{
    public:
        bool isClicked();
        bool isHovering();

        virtual void __update(__InputState_t* inputState);
        virtual void __draw(SDL_Renderer* renderer);

    protected:
        ButtonWidget(Vector2i position, Vector2i size);

        bool clicked;
        bool hovering;
    };
}

#endif