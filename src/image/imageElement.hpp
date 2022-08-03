#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <SDL_image.h>

namespace miniGUI{
    class ImageElement{
    public:
        ImageElement(std::string path);
        ~ImageElement();

        void setImage(std::string path);

        int getWidth();
        int getHeight();

        void __draw(SDL_Renderer* renderer, SDL_Rect rect);

    private:
        SDL_Surface* surface;
        SDL_Texture* texture;
    };
}

#endif