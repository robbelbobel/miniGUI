#include "text.hpp"

miniGUI::Text::Text(std::string text, std::string fontPath, int size, uint32_t color){
    // Assign Class Variables
    miniGUI::Text::text     = text;
    miniGUI::Text::font     = TTF_OpenFont(fontPath.c_str(), size);
    miniGUI::Text::size     = size;

    miniGUI::Text::color.r = (color  & 0xFF000000)  >> 24;
    miniGUI::Text::color.g = (color & 0xFF0000)     >> 16;
    miniGUI::Text::color.b = (color & 0xFF00)       >> 8;
    miniGUI::Text::color.a =  color & 0xFF;

    // Load Font And Create Text Surface
    miniGUI::Text::setFont(fontPath);
}

miniGUI::Text::~Text(){
    SDL_FreeSurface(miniGUI::Text::surface);
}

void miniGUI::Text::setText(std::string text){
    miniGUI::Text::text = text;
    miniGUI::Text::createSurface();
}

void miniGUI::Text::setFont(std::string fontPath){
    free(miniGUI::Text::font);
    miniGUI::Text::font = TTF_OpenFont(fontPath.c_str(), miniGUI::Text::size);
    miniGUI::Text::createSurface();
}

void miniGUI::Text::setSize(int size){
    miniGUI::Text::size = size;
    miniGUI::Text::createSurface();
}

void miniGUI::Text::setColor(uint32_t color){
    miniGUI::Text::color.r = (color  & 0xFF000000)  >> 24;
    miniGUI::Text::color.g = (color & 0xFF0000)     >> 16;
    miniGUI::Text::color.b = (color & 0xFF00)       >> 8;
    miniGUI::Text::color.a =  color & 0xFF;

    miniGUI::Text::createSurface();
}

SDL_Surface* miniGUI::Text::__getSurface(){
    return miniGUI::Text::surface;
}

void miniGUI::Text::createSurface(){
    // Check If Font Was Loaded Correctly
    if(font == NULL) std::cerr << "Font failed to load. " << std::endl << "TTF Error: " << TTF_GetError() << std::endl;

    // Free Old Surface
    SDL_FreeSurface(miniGUI::Text::surface);
    
    // Create Surface
    miniGUI::Text::surface = TTF_RenderText_Blended(font, miniGUI::Text::text.c_str(), miniGUI::Text::color);

    if(miniGUI::Text::surface == nullptr) std::cerr << "Failed to render text" << std::endl;
}