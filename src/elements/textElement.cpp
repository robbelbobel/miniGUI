#include "../../include/elements/textElement.hpp"

miniGUI::TextElement::TextElement(std::string text, std::string fontPath, int fontSize, uint32_t color){
    // Assign Class Variables
    miniGUI::TextElement::text     = text;
    miniGUI::TextElement::font     = TTF_OpenFont(fontPath.c_str(), fontSize);
    miniGUI::TextElement::size     = fontSize;
    miniGUI::TextElement::surface  = nullptr;
    miniGUI::TextElement::texture  = nullptr;

    miniGUI::TextElement::color.r  = (color  & 0xFF000000)  >> 24;
    miniGUI::TextElement::color.g  = (color & 0xFF0000)     >> 16;
    miniGUI::TextElement::color.b  = (color & 0xFF00)       >> 8;
    miniGUI::TextElement::color.a  =  color & 0xFF;

    // Load Font And Create Text Surface
    miniGUI::TextElement::setFont(fontPath);
}

miniGUI::TextElement::~TextElement(){
    SDL_FreeSurface(miniGUI::TextElement::surface);
}

void miniGUI::TextElement::setText(std::string text){
    miniGUI::TextElement::text = text;
    miniGUI::TextElement::createSurface();
}

void miniGUI::TextElement::setFont(std::string fontPath){
    free(miniGUI::TextElement::font);
    miniGUI::TextElement::font = TTF_OpenFont(fontPath.c_str(), miniGUI::TextElement::size);
    miniGUI::TextElement::createSurface();
}

void miniGUI::TextElement::setSize(int size){
    miniGUI::TextElement::size = size;
    miniGUI::TextElement::createSurface();
}

void miniGUI::TextElement::setColor(uint32_t color){
    miniGUI::TextElement::color.r = (color  & 0xFF000000)  >> 24;
    miniGUI::TextElement::color.g = (color & 0xFF0000)     >> 16;
    miniGUI::TextElement::color.b = (color & 0xFF00)       >> 8;
    miniGUI::TextElement::color.a =  color & 0xFF;

    miniGUI::TextElement::createSurface();
}

int miniGUI::TextElement::getWidth(){
    if(miniGUI::TextElement::surface == nullptr) return 0;
    return miniGUI::TextElement::surface -> w;
}

int miniGUI::TextElement::getHeight(){
    if(miniGUI::TextElement::surface == nullptr) return 0;
    return miniGUI::TextElement::surface -> h;
}

void miniGUI::TextElement::__draw(SDL_Renderer* renderer, SDL_Rect rect){
    // Generate Texture If Not Present
    if(miniGUI::TextElement::texture == nullptr){
        miniGUI::TextElement::texture = SDL_CreateTextureFromSurface(renderer, miniGUI::TextElement::surface);

        // Free Surface
        SDL_FreeSurface(miniGUI::TextElement::surface);
        miniGUI::TextElement::surface = nullptr;
    }

    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void miniGUI::TextElement::createSurface(){
    // Check If Font Was Loaded Correctly
    if(miniGUI::TextElement::font == nullptr) std::cerr << "Font failed to load. " << std::endl << "SDL_TTF Error: " << TTF_GetError() << std::endl;

    // Free Old Surface
    SDL_FreeSurface(miniGUI::TextElement::surface);
    
    // Create Surface
    miniGUI::TextElement::surface = TTF_RenderText_Blended(font, miniGUI::TextElement::text.c_str(), miniGUI::TextElement::color);
    if(miniGUI::TextElement::surface == nullptr) std::cerr << "Failed to render text" << std::endl;

    // Destroy Old Texture
    SDL_DestroyTexture(miniGUI::TextElement::texture);
    miniGUI::TextElement::texture = nullptr;
}