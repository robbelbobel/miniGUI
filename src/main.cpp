#include <string>

#include "window/window.hpp"
#include "widgets/buttons/textButtonWidget.hpp"
#include "widgets/buttons/imageButtonWidget.hpp"

int main(){
	miniGUI::Vector2i size(500, 300);

	// Create Window
	miniGUI::Window window(size, "Title");

	// Create Canvas
	miniGUI::Canvas canvas;

	// Create Text
	miniGUI::Text text("text", "/Users/robbetiteca/Downloads/Roboto/Roboto-Black.ttf", 64, 0xFFFFFFFF);
	// Create TextButtonWidget
	miniGUI::TextButtonWidget tbWidget(miniGUI::Vector2i(200, 20), miniGUI::Vector2i(300, 100), &text, 0x00FFFFFF);

	// Create Image
	miniGUI::Image image("/Users/robbetiteca/Downloads/image.jpg");
	// Create ImageButtonWidget
	miniGUI::ImageButtonWidget ibWidget(miniGUI::Vector2i(0, 0), miniGUI::Vector2i(200, 200), &image);

	// Add Widgets to Canvas
	canvas.addWidget(&tbWidget);
	canvas.addWidget(&ibWidget);

	// Set Active Canvas
	window.setCanvas(&canvas);

	while(!window.shouldClose()){
		window.update();
		window.draw();

		if(tbWidget.isHovering()){
			tbWidget.getText() -> setText("Hovering");
			tbWidget.getText() -> setSize(32);
		} 
		else{
			tbWidget.getText() -> setText("Text");
			tbWidget.getText() -> setSize(64);
		}


		if(ibWidget.isHovering()) ibWidget.getImage() -> setImage("/Users/robbetiteca/Downloads/image2.png");
		else ibWidget.getImage() -> setImage("/Users/robbetiteca/Downloads/image.jpg");
		
	}
	
	return 0;
}