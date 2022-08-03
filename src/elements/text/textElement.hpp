#ifndef TEXT_HPP
#define TEXT_HPP

#include <SDL_ttf.h>

#include "../element.hpp"
#include "../../vector/vector.hpp"

namespace miniGUI{
    class TextElement : public miniGUI::Element{
    public:
        TextElement(std::string text, std::string fontPath, int fontSize, uint32_t color = 0x000000FF);
        ~TextElement();
        
        void setText(std::string text);
        void setFont(std::string fontPath);
        void setSize(int size);
        void setColor(uint32_t color);

        virtual int getWidth();
        virtual int getHeight();

        virtual void __draw(SDL_Renderer* renderer, SDL_Rect rect);

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