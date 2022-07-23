#include "image.hpp"

miniGUI::Image::Image(std::string path){
    miniGUI::Image::surface = nullptr;
    miniGUI::Image::texture = nullptr;
    miniGUI::Image::setImage(path);
}

miniGUI::Image::~Image(){
    SDL_FreeSurface(miniGUI::Image::surface);
}

void miniGUI::Image::setImage(std::string path){
    // Create Surface
    SDL_FreeSurface(miniGUI::Image::surface);
    miniGUI::Image::surface = IMG_Load(path.c_str());
    
    if(miniGUI::Image::surface == nullptr) std::cerr << "Image failed to load. " << std::endl << "SDL_IMG Error: " << IMG_GetError() << std::endl;

    // Destroy Old Texture
    SDL_DestroyTexture(miniGUI::Image::texture);
    miniGUI::Image::texture = nullptr;
}

int miniGUI::Image::getWidth(){
    return miniGUI::Image::surface -> w;
}

int miniGUI::Image::getHeight(){
    return miniGUI::Image::surface -> h;
}

void miniGUI::Image::__draw(SDL_Renderer* renderer, SDL_Rect rect){
    // Generate Texture If Not Present
    if(miniGUI::Image::texture == nullptr){
        miniGUI::Image::texture = SDL_CreateTextureFromSurface(renderer, miniGUI::Image::surface);

        // Free Surface
        SDL_FreeSurface(miniGUI::Image::surface);
        miniGUI::Image::surface = nullptr;
    }

    SDL_RenderCopy(renderer, miniGUI::Image::texture, NULL, &rect);
}