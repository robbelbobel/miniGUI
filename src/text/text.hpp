#ifndef TEXT_HPP
#define TEXT_HPP

#include <iostream>
#include <SDL_ttf.h>

#include "../vector/vector.hpp"

namespace miniGUI{
    class Text{
    public:
        Text(std::string text, std::string fontPath, int fontSize, uint32_t color = 0x000000FF);
        ~Text();
        
        void setText(std::string text);
        void setFont(std::string fontPath);
        void setSize(int size);
        void setColor(uint32_t color);

        int getWidth();
        int getHeight();

        void __draw(SDL_Renderer* renderer, SDL_Rect rect);

    private:
        void createSurface();

        std::string text;
        TTF_Font* font;
        int size;
        SDL_Color color;

        SDL_Surface* surface;
        SDL_Texture* texture;
    };
}

#endif