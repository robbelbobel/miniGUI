#include "text.hpp"

miniGUI::Text::Text(std::string text, std::string fontPath, int size, uint32_t color){
    // Assign Class Variables
    miniGUI::Text::text     = text;
    miniGUI::Text::fontPath = fontPath;
    miniGUI::Text::size     = size;
    miniGUI::Text::color    = color;

    // Create Text Surface
    miniGUI::Text::createSurface();
}

miniGUI::Text::~Text(){
    SDL_FreeSurface(miniGUI::Text::surface);
}

void miniGUI::Text::setText(std::string &text){
    miniGUI::Text::text = text;
    miniGUI::Text::createSurface();
}

void miniGUI::Text::setFont(std::string &fontPath){
    miniGUI::Text::fontPath = fontPath;
    miniGUI::Text::createSurface();
}

void miniGUI::Text::setSize(int size){
    miniGUI::Text::size = size;
    miniGUI::Text::createSurface();
}

void miniGUI::Text::setColor(uint32_t color){
    miniGUI::Text::color = color;
    miniGUI::Text::createSurface();
}

SDL_Surface* miniGUI::Text::__getSurface(){
    return miniGUI::Text::surface;
}

void miniGUI::Text::createSurface(){
    // Load Font
    TTF_Font* font = TTF_OpenFont(miniGUI::Text::fontPath.c_str(), miniGUI::Text::size);

    if(font == NULL) std::cerr << "Failed to load Font. " << std::endl << "TTF Error: " << TTF_GetError() << std::endl;

    // Convert Color to SDL Color
    SDL_Color sdlColor;
    sdlColor.r = color & 0xFF;
    sdlColor.g = color & 0x00FF     << 8;
    sdlColor.b = color & 0x0000FF   << 16;
    sdlColor.a = color & 0x000000FF << 24;
    
    // Create Surface
    miniGUI::Text::surface = TTF_RenderText_Blended(font, miniGUI::Text::text.c_str(), sdlColor);

    if(miniGUI::Text::surface == nullptr) std::cerr << "Failed to render text" << std::endl;

    // Free Font
    free(font);
}