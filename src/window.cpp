#include "../include/window.hpp"
        
miniGUI::Window::Window(Vector2i size, std::string title){
	miniGUI::Window::size 	= size;
	miniGUI::Window::closed = false;
	miniGUI::Window::canvas = nullptr;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	
	miniGUI::Window::sdlWindow 	= SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_SHOWN);
	miniGUI::Window::renderer 	= SDL_CreateRenderer(miniGUI::Window::sdlWindow, -1, SDL_RENDERER_ACCELERATED);
}

miniGUI::Window::~Window(){
	SDL_DestroyRenderer(miniGUI::Window::renderer);
	SDL_DestroyWindow(miniGUI::Window::sdlWindow);
	
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void miniGUI::Window::update(){
	miniGUI::__InputState_t* inputState = miniGUI::Window::handleInput();
	if(miniGUI::Window::canvas != nullptr) miniGUI::Window::canvas -> __update(inputState);
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
	if(miniGUI::Window::canvas != nullptr) miniGUI::Window::canvas -> __draw(miniGUI::Window::renderer);

	// Present Rendering
	SDL_RenderPresent(miniGUI::Window::renderer);
}

void miniGUI::Window::setCanvas(miniGUI::Canvas* canvas){
	miniGUI::Window::canvas = canvas;
}

miniGUI::Canvas* miniGUI::Window::getCanvas(){
	return miniGUI::Window::canvas;
}

int miniGUI::Window::getWidth(){
	return miniGUI::Window::size.x;
}

int miniGUI::Window::getHeight(){
	return miniGUI::Window::size.y;
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
