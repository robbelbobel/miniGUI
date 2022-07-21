#include "image.hpp"

miniGUI::Image::Image(std::string path){
    miniGUI::Image::surface = nullptr;
    miniGUI::Image::setImage(path);
}

miniGUI::Image::~Image(){
    SDL_FreeSurface(miniGUI::Image::surface);
}

void miniGUI::Image::setImage(std::string path){
    SDL_FreeSurface(miniGUI::Image::surface);
    miniGUI::Image::surface = IMG_Load(path.c_str());
    
    if(miniGUI::Image::surface == nullptr) std::cerr << "Image failed to load. " << std::endl << "SDL_IMG Error: " << IMG_GetError() << std::endl;
}

int miniGUI::Image::getWidth(){
    return miniGUI::Image::surface -> w;
}

int miniGUI::Image::getHeight(){
    return miniGUI::Image::surface -> h;
}

SDL_Surface* miniGUI::Image::__getSurface(){
    return miniGUI::Image::surface;
}