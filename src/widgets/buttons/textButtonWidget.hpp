#ifndef TEXTBUTTONWIDGET_HPP
#define TEXTBUTTONWIDGET_HPP

#include "buttonWidget.hpp"

namespace miniGUI{
    class TextButtonWidget : public ButtonWidget{
    public:
        TextButtonWidget(miniGUI::Vector2i size);
    };
}
#endif