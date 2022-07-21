#ifndef IMAGEBUTTONWIDGET_HPP
#define IMAGEBUTTONWIDGET_HPP

#include "buttonWidget.hpp"
#include "../../image/image.hpp"

namespace miniGUI {
    class ImageButtonWidget : public ButtonWidget {
    public:
        ImageButtonWidget(miniGUI::Vector2i position, miniGUI::Vector2i size, miniGUI::Image* image);

        miniGUI::Image* getImage();
        void setImage(miniGUI::Image* image);

        virtual void __draw(SDL_Renderer* renderer);

    private:
        miniGUI::Image* image;
    };
}

#endif