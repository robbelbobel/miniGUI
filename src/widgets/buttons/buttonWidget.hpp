#ifndef BUTTONWIDGET_HPP
#define BUTTONWIDGET_HPP

#include "../widget.hpp"

namespace miniGUI{
    class ButtonWidget : public Widget{
    public:
        bool isClicked();
        bool isHovering();

        virtual void __update(__InputState_t* inputState);

    protected:
        ButtonWidget(Vector2i size);

        bool clicked;
        bool hovering;
    };
}

#endif