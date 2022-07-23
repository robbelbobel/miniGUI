#include "text.hpp"

miniGUI::Text::Text(std::string text, std::string fontPath, int fontSize, uint32_t color){
    // Assign Class Variables
    miniGUI::Text::text     = text;
    miniGUI::Text::font     = TTF_OpenFont(fontPath.c_str(), fontSize);
    miniGUI::Text::size     = fontSize;
    miniGUI::Text::surface  = nullptr;
    miniGUI::Text::texture  = nullptr;

    miniGUI::Text::color.r  = (color  & 0xFF000000)  >> 24;
    miniGUI::Text::color.g  = (color & 0xFF0000)     >> 16;
    miniGUI::Text::color.b  = (color & 0xFF00)       >> 8;
    miniGUI::Text::color.a  =  color & 0xFF;

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

int miniGUI::Text::getWidth(){
    return miniGUI::Text::surface -> w;
}

int miniGUI::Text::getHeight(){
    return miniGUI::Text::surface -> h;
}

void miniGUI::Text::__draw(SDL_Renderer* renderer, SDL_Rect rect){
    // Generate Texture If Not Present
    if(miniGUI::Text::texture == nullptr){
        miniGUI::Text::texture = SDL_CreateTextureFromSurface(renderer, miniGUI::Text::surface);

        // Free Surface
        SDL_FreeSurface(miniGUI::Text::surface);
        miniGUI::Text::surface = nullptr;
    }

    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void miniGUI::Text::createSurface(){
    // Check If Font Was Loaded Correctly
    if(miniGUI::Text::font == nullptr) std::cerr << "Font failed to load. " << std::endl << "SDL_TTF Error: " << TTF_GetError() << std::endl;

    // Free Old Surface
    SDL_FreeSurface(miniGUI::Text::surface);
    
    // Create Surface
    miniGUI::Text::surface = TTF_RenderText_Blended(font, miniGUI::Text::text.c_str(), miniGUI::Text::color);
    if(miniGUI::Text::surface == nullptr) std::cerr << "Failed to render text" << std::endl;

    // Destroy Old Texture
    SDL_DestroyTexture(miniGUI::Text::texture);
    miniGUI::Text::texture = nullptr;
}