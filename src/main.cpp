#include <string>

#include "window/window.hpp"
#include "widgets/buttons/textButtonWidget.hpp"

int main(){
	miniGUI::Vector2i size(500, 300);

	// Create Window
	miniGUI::Window window(size, "Title");

	// Create Canvas
	miniGUI::Canvas canvas;

	// Create Text
	miniGUI::Text text("text", "/Users/robbetiteca/Downloads/Roboto/Roboto-Black.ttf", 64, 0xFFFFFFFF);

	// Create TextButtonWidget
	miniGUI::TextButtonWidget tbWidget(miniGUI::Vector2i(200, 20), miniGUI::Vector2i(200, 100), &text, 0x00FFFFFF);

	canvas.addWidget(&tbWidget);

	window.setCanvas(&canvas);

	unsigned int i = 0;

	while(!window.shouldClose()){
		window.update();
		window.draw();

		text.setText(std::to_string(i));

		i++;
	}
	
	return 0;
}