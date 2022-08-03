#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
#include <SDL.h>

namespace miniGUI{
    class Element{
    public:
        virtual int getWidth();
        virtual int getHeight();

        virtual void __draw(SDL_Renderer* renderer, SDL_Rect rect);
    };
}

#endif