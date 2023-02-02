#include <iostream>
#include <string>

#include "../../include/miniGUI.hpp"

int main(){
	// Create Window
	miniGUI::Window window(miniGUI::Vector2i(500, 300), "Basic Example");

	// Create Layer
	miniGUI::Layer layer;

	// Create Canvas
	miniGUI::Canvas canvas;
	canvas.addLayer(&layer);

	// Create Background
	miniGUI::ImageElement imageElement(std::string(SOURCE_DIR) + std::string("assets/background.jpg"));
	// Create Background Image Widget
	miniGUI::ImageWidget iWidget(miniGUI::Vector2i(0, 0), miniGUI::Vector2i(window.getWidth(), window.getHeight()), &imageElement);

	// Create Text
	miniGUI::TextElement textElement("text", std::string(SOURCE_DIR) + std::string("assets/roboto-black.ttf"), 64, 0xFFFFFFFF);
	// Create TextButtonWidget
	miniGUI::TextButtonWidget tbWidget(miniGUI::Vector2i(200, 50), miniGUI::Vector2i(300, 100), &textElement, 0x00FFFFFF);

	// Create Image
	miniGUI::ImageElement imageElement2(std::string(SOURCE_DIR) + std::string("assets/image1.jpg"));
	// Create ImageButtonWidget
	miniGUI::ImageButtonWidget ibWidget(miniGUI::Vector2i(0, 0), miniGUI::Vector2i(200, 200), &imageElement2);

	// Create Title
	miniGUI::TextElement title("title", std::string(SOURCE_DIR) + std::string("assets/roboto-black.ttf"), 64, 0xFFFFFFFF);
	// Create Text Widget
	miniGUI::TextWidget tWidget(miniGUI::Vector2i((window.getWidth() / 2) - (title.getWidth() / 2), 0), miniGUI::Vector2i(title.getWidth(), title.getHeight()), &title);

	// Create Rectangle Widget
	miniGUI::RectangleShapeWidget rectangle(miniGUI::Vector2i(20, 20), miniGUI::Vector2i(100, 100), 0xFF00FFFF);

	// Add Widgets to Layer
	layer.addWidget(&iWidget);
	layer.addWidget(&tbWidget);
	layer.addWidget(&ibWidget);
	layer.addWidget(&tWidget);
	layer.addWidget(&rectangle);

	// Set Active Canvas
	window.setCanvas(&canvas);

	while(!window.shouldClose()){
		window.update();
		window.draw();

		if(tbWidget.isHovering()) layer.removeWidget(&tbWidget);

		if(ibWidget.isHovering()) ibWidget.getImageElement() -> setImage(std::string(SOURCE_DIR) + std::string("assets/image2.jpg"));
		else ibWidget.getImageElement() -> setImage(std::string(SOURCE_DIR) + std::string("assets/image1.jpg"));
	}
	
	return 0;
}