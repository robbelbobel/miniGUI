#include <iostream>
#include <string>

#include "../../include/miniGUI.hpp"

int main(){
	miniGUI::Vector2i size(500, 300);

	// Create Window
	miniGUI::Window window(size, "Title");

	// Create Canvas
	miniGUI::Canvas canvas;

	// Create Background
	miniGUI::ImageElement imageElement("/Users/robbetiteca/Downloads/image.jpg");
	// Create Background Image Widget
	miniGUI::ImageWidget iWidget(miniGUI::Vector2i(0, 0), size, &imageElement);

	// Create Text
	miniGUI::TextElement textElement("text", "/Users/robbetiteca/Downloads/Roboto/Roboto-Black.ttf", 64, 0xFFFFFFFF);
	// Create TextButtonWidget
	miniGUI::TextButtonWidget tbWidget(miniGUI::Vector2i(200, 20), miniGUI::Vector2i(300, 100), &textElement, 0x00FFFFFF);

	// Create Image
	miniGUI::ImageElement imageElement2("/Users/robbetiteca/Downloads/image.jpg");
	// Create ImageButtonWidget
	miniGUI::ImageButtonWidget ibWidget(miniGUI::Vector2i(0, 0), miniGUI::Vector2i(200, 200), &imageElement2);

	// Create Title
	miniGUI::TextElement title("title", "/Users/robbetiteca/Downloads/Roboto/Roboto-Black.ttf", 64, 0xFFFFFFFF);
	// Create Text Widget
	miniGUI::TextWidget tWidget(miniGUI::Vector2i(0, 0), miniGUI::Vector2i(500, 50), &title);

	// Create Rectangle Widget
	miniGUI::RectangleShapeWidget rectangle(miniGUI::Vector2i(20, 20), miniGUI::Vector2i(100, 100), 0xFF00FFFF);

	// Add Widgets to Canvas
	canvas.addWidget(&iWidget);
	canvas.addWidget(&tbWidget);
	canvas.addWidget(&ibWidget);
	canvas.addWidget(&tWidget);
	canvas.addWidget(&rectangle);

	// Set Active Canvas
	window.setCanvas(&canvas);

	while(!window.shouldClose()){
		window.update();
		window.draw();

		if(tbWidget.isHovering()){
			tbWidget.getTextElement() -> setText("Hovering");
			tbWidget.getTextElement() -> setSize(32);
		} 
		else{
			tbWidget.getTextElement() -> setText("Text");
			tbWidget.getTextElement() -> setSize(64);
		}

		if(ibWidget.isHovering()) ibWidget.getImageElement() -> setImage("/Users/robbetiteca/Downloads/image2.png");
		else ibWidget.getImageElement() -> setImage("/Users/robbetiteca/Downloads/image.jpg");
	}
	
	return 0;
}