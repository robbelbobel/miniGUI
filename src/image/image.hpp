#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <SDL_image.h>

namespace miniGUI{
    class Image{
    public:
        Image(std::string path);
        ~Image();

        void setImage(std::string path);

        int getWidth();
        int getHeight();

        SDL_Surface* __getSurface();

    private:
        SDL_Surface* surface;
    };
}

#endif