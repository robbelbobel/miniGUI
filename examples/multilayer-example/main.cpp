#include "../../include/miniGUI.hpp"

int main(){
    // Create Window
    miniGUI::Window window(miniGUI::Vector2i(500, 300), "Multilayer Example");

    // Create Layers
    miniGUI::Layer firstLayer;
    miniGUI::Layer secondLayer;

    // Create Canvas
    window.setCanvas(new miniGUI::Canvas);
    window.getCanvas() -> addLayer(&firstLayer);

    // Create Background
    firstLayer.addWidget(new miniGUI::ImageWidget(miniGUI::Vector2i(0, 0), miniGUI::Vector2i(500, 300), new miniGUI::ImageElement(std::string(SOURCE_DIR) + std::string("assets/background.jpg"))));

    // Create Enable Layer Button
    miniGUI::TextButtonWidget enableLayerButton(miniGUI::Vector2i(0, 0), miniGUI::Vector2i(200, 50), new miniGUI::TextElement("Enable Layer", std::string(SOURCE_DIR) + std::string("assets/roboto-black.ttf"), 64, 0x000000FF), 0xFFFFFFFF);
    firstLayer.addWidget(&enableLayerButton);

    // Create Hover Button
    miniGUI::TextButtonWidget hoverButton(miniGUI::Vector2i(0, 200), miniGUI::Vector2i(200, 50), new miniGUI::TextElement("Not Hovering", std::string(SOURCE_DIR) + std::string("assets/roboto-black.ttf"), 64, 0x000000FF), 0xFFFFFFFF);
    firstLayer.addWidget(&hoverButton);
    
    // Create Disable Layer Button
    miniGUI::TextButtonWidget disableLayerButton(miniGUI::Vector2i(100, 100), miniGUI::Vector2i(200, 50), new miniGUI::TextElement("Disable Layer", std::string(SOURCE_DIR) + std::string("assets/roboto-black.ttf"), 64, 0x000000FF), 0xFFFFFFFF);
    secondLayer.addWidget(&disableLayerButton);

    while(!window.shouldClose()){
        window.update();
        window.draw();

        // Monitor Enable/Display Layer Buttons
        if(enableLayerButton.isClicked())   window.getCanvas() -> addLayer(&secondLayer);
        if(disableLayerButton.isClicked())  window.getCanvas() -> removeLayer(&secondLayer);

        // Change HoverButton Text When Hovering
        if(hoverButton.isHovering()){
            hoverButton.getTextElement() -> setText("Hovering");
        }else{
            hoverButton.getTextElement() -> setText("Not Hovering");
        }
    }

    return 0;
}   