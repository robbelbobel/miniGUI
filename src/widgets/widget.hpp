#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <SDL.h>

#include "../vector/vector.hpp"
#include "../inputState/inputState.hpp"

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
        virtual void __draw();

    protected:
        /** PROTECTED CLASS FUNCTIONS **/
        Widget();

        /** PROTECTED CLASS VARIABLES **/
        bool enabled;

        miniGUI::Vector2i position;
        miniGUI::Vector2i size;
    };
}

#endif