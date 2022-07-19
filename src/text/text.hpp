#ifndef TEXT_HPP
#define TEXT_HPP

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

namespace miniGUI{
    class Text{
    public:
        Text(std::string text, std::string fontPath, int size, uint32_t color);
        ~Text();
        
        void setText(std::string &text);
        void setFont(std::string &fontPath);
        void setSize(int size);
        void setColor(uint32_t color);

        SDL_Surface* __getSurface();

    private:
        void createSurface();

        std::string text;
        std::string fontPath;
        int size;
        uint32_t color;

        SDL_Surface* surface;
    };
}

#endif