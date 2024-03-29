#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <SDL2/SDL.h>

#include "../vector.hpp"
#include "../inputState.hpp"

namespace miniGUI{
    class Widget{
    public:
        /** PUBLIC CLASS FUNCTIONS **/
        // Enabling
        void enable();
        void disable();
        
        // Position & Size
        void setPosition(miniGUI::Vector2i position);        
        void setSize(miniGUI::Vector2i size);

        // Updating & Drawing
        virtual void __update(__InputState_t* inputState);
        virtual void __draw(SDL_Renderer* renderer);

    protected:
        /** PROTECTED CLASS FUNCTIONS **/
        Widget(miniGUI::Vector2i position, miniGUI::Vector2i size);

        /** PROTECTED CLASS VARIABLES **/
        bool enabled;

        SDL_Rect rect;
    };
}

#endif