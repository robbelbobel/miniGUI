#ifndef IMAGEWIDGET_HPP
#define IMAGEWIDGET_HPP

#include "widget.hpp"
#include "../elements/imageElement.hpp"

namespace miniGUI{
    class ImageWidget : public miniGUI::Widget{
    public:
        ImageWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::ImageElement* imageElement);
        ~ImageWidget();

        void setImageElement(miniGUI::ImageElement* imageElement);
        miniGUI::ImageElement* getImageElement();

        virtual void __draw(SDL_Renderer* renderer);

    private:
        miniGUI::ImageElement* imageElement;
    };
}

#endif