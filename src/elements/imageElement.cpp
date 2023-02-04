#include "../../include/elements/imageElement.hpp"

miniGUI::ImageElement::ImageElement(std::string path){
    miniGUI::ImageElement::surface = nullptr;
    miniGUI::ImageElement::texture = nullptr;
    miniGUI::ImageElement::setImage(path);
}

miniGUI::ImageElement::~ImageElement(){
    SDL_FreeSurface(miniGUI::ImageElement::surface);
}

void miniGUI::ImageElement::setImage(std::string path){
    // Create Surface
    SDL_FreeSurface(miniGUI::ImageElement::surface);
    miniGUI::ImageElement::surface = IMG_Load(path.c_str());
    
    if(miniGUI::ImageElement::surface == nullptr) std::cerr << "Image failed to load. " << std::endl << "SDL_IMG Error: " << IMG_GetError() << std::endl;

    // Destroy Old Texture
    SDL_DestroyTexture(miniGUI::ImageElement::texture);
    miniGUI::ImageElement::texture = nullptr;
}

int miniGUI::ImageElement::getWidth(){
    if(miniGUI::ImageElement::surface == nullptr) return 0;
    return miniGUI::ImageElement::surface -> w;
}

int miniGUI::ImageElement::getHeight(){
    if(miniGUI::ImageElement::surface == nullptr) return 0;
    return miniGUI::ImageElement::surface -> h;
}

void miniGUI::ImageElement::__draw(SDL_Renderer* renderer, SDL_Rect rect){
    // Generate Texture If Not Present
    if(miniGUI::ImageElement::texture == nullptr){
        miniGUI::ImageElement::texture = SDL_CreateTextureFromSurface(renderer, miniGUI::ImageElement::surface);

        // Free Surface
        SDL_FreeSurface(miniGUI::ImageElement::surface);
        miniGUI::ImageElement::surface = nullptr;
    }

    SDL_RenderCopy(renderer, miniGUI::ImageElement::texture, NULL, &rect);
}