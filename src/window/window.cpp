#include "window.h"

miniGUI::Window::Window(Vector2i size, uint8_t parameters){
	miniGUI::Window::size = size;
	miniGUI::Window::parameters = parameters;
}

void miniGUI::Window::setCanvas(Canvas* canvas){
	miniGUI::Window::canvas = canvas;
}