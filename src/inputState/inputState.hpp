#ifndef INPUTSTATE_HPP
#define INPUTSTATE_HPP

#include "../vector/vector.hpp"

namespace miniGUI{
    struct __InputState_s{
        miniGUI::Vector2i mousePosition;
        bool clicked;
        __InputState_s() : clicked(0), mousePosition(0, 0){}
    } typedef __InputState_t;
}
#endif