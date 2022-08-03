#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <SDL_image.h>

#include "../element.hpp"

namespace miniGUI{
    class ImageElement : public miniGUI::Element{
    public:
        ImageElement(std::string path);
        ~ImageElement();

        void setImage(std::string path);

        virtual int getWidth();
        virtual int getHeight();

        virtual void __draw(SDL_Renderer* renderer, SDL_Rect rect);

    private:
        SDL_Surface* surface;
        SDL_Texture* texture;
    };
}

#endif