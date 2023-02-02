#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <vector>

#include "layer.hpp"

namespace miniGUI{
    class Canvas{
    public:
        Canvas();

        void addLayer(miniGUI::Layer* layer);
        bool removeLayer(miniGUI::Layer* layer);

        void clear();

        void __update(__InputState_t* inputState);
        void __draw(SDL_Renderer* renderer);
        
    private:
        std::vector<miniGUI::Layer*> layers;
    };
}

#endif