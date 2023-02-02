#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
#include "widgets/widget.hpp"

namespace miniGUI{
    class Layer{
    public:
        Layer();

        void addWidget(miniGUI::Widget* widget);
        bool removeWidget(miniGUI::Widget* widget);

        void clear();

        void __update(__InputState_t* inputState);
        void __draw(SDL_Renderer* renderer);

    private:
        std::vector<miniGUI::Widget*> widgets;
    };
};

#endif