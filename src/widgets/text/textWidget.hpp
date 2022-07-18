#ifndef TEXTWIDGET_HPP
#define TEXTWIDGET_HPP

#include <string>

#include "../widget.hpp"

namespace miniGUI{
    class TextWidget : public Widget{
    public:
        TextWidget();

        void setText(std::string &text);

    private:
        std::string text;
    };
}

#endif