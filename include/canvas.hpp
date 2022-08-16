#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <vector>

#include "widgets/widget.hpp"

namespace miniGUI{
    class Canvas{
    public:
        Canvas();

        void addWidget(Widget* widget);
        bool removeWidget(Widget* widget);

        void clear();

        void __update(__InputState_t* inputState);
        void __draw(SDL_Renderer* renderer);
    private:
        std::vector<Widget*> widgets;
    };
}

#endif