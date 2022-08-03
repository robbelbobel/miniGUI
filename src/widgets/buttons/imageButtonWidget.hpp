#ifndef IMAGEBUTTONWIDGET_HPP
#define IMAGEBUTTONWIDGET_HPP

#include "buttonWidget.hpp"
#include "../../elements/image/imageElement.hpp"

namespace miniGUI {
    class ImageButtonWidget : public ButtonWidget {
    public:
        ImageButtonWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::ImageElement* ImageElement);

        miniGUI::ImageElement* getImageElement();
        void setImageElement(miniGUI::ImageElement* image);

        virtual void __draw(SDL_Renderer* renderer);

    private:
        miniGUI::ImageElement* imageElement;
    };
}

#endif