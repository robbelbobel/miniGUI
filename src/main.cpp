#include "window/window.hpp"
#include "widgets/buttons/textButtonWidget.hpp"

int main(){
	miniGUI::Vector2i size(500, 300);

	// Create Window
	miniGUI::Window window(size, "Title");

	// Create Canvas
	miniGUI::Canvas canvas;

	// Create TextButtonWidget
	size.x = 100;
	size.y = 100;
	miniGUI::TextButtonWidget tbWidget(size);

	canvas.addWidget(&tbWidget);

	window.setCanvas(&canvas);

	while(!window.shouldClose()){
		window.update();
		window.draw();
	}
	
	return 0;
}