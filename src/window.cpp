#include "../include/window.hpp"
        
miniGUI::Window::Window(Vector2i size, std::string title){
	miniGUI::Window::size = size;
	miniGUI::Window::closed = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	
	miniGUI::Window::sdlWindow 	= SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_SHOWN);
	miniGUI::Window::renderer 	= SDL_CreateRenderer(miniGUI::Window::sdlWindow, -1, SDL_RENDERER_ACCELERATED);
}

miniGUI::Window::~Window(){
	SDL_DestroyRenderer(miniGUI::Window::renderer);
	SDL_DestroyWindow(miniGUI::Window::sdlWindow);
	SDL_Quit();
}

void miniGUI::Window::update(){
	miniGUI::__InputState_t* inputState = miniGUI::Window::handleInput();
	miniGUI::Window::canvas -> __update(inputState);
	delete(inputState);
}

void miniGUI::Window::draw(){
	// Draw Background
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = miniGUI::Window::size.x;
	rect.h = miniGUI::Window::size.y;
	
	SDL_SetRenderDrawColor(miniGUI::Window::renderer, 0, 0, 0, 0xFF);
	SDL_RenderFillRect(miniGUI::Window::renderer, &rect);

	// Draw Canvas
	miniGUI::Window::canvas -> __draw(miniGUI::Window::renderer);

	// Present Rendering
	SDL_RenderPresent(miniGUI::Window::renderer);
}

void miniGUI::Window::setCanvas(miniGUI::Canvas* canvas){
	miniGUI::Window::canvas = canvas;
}

miniGUI::Vector2i miniGUI::Window::getSize(){
	return miniGUI::Window::size;
}

bool miniGUI::Window::shouldClose(){
	return miniGUI::Window::closed;
}

miniGUI::__InputState_t* miniGUI::Window::handleInput(){
	/** INPUTSTATE INITIALIZATION **/
	miniGUI::__InputState_t* inputState = new miniGUI::__InputState_t;
	// Reset Mouseclick
	inputState -> clicked = false;
	
	/** EVENT HANDLING **/
	SDL_Event e;
	while(SDL_PollEvent(&e) != 0){
		switch(e.type){
			case SDL_QUIT:
				// Window Quit 
				miniGUI::Window::closed = true;
				break;
			
			case SDL_MOUSEBUTTONDOWN:
				// Mouse Click
				inputState -> clicked = true;
				break;
		}
	}

	/** MOUSE POSITION HANDLING **/
	SDL_GetMouseState(&inputState -> mousePosition.x, & inputState -> mousePosition.y);

	return inputState;
}
