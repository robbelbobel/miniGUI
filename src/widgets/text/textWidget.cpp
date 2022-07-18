#include "textWidget.hpp"

miniGUI::TextWidget::TextWidget(){
    ;
}

void miniGUI::TextWidget::setText(std::string &text){
    miniGUI::TextWidget::text = text;
}