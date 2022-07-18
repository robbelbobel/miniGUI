#include "window.hpp"
        
miniGUI::Window::Window(Vector2i size, std::string title){
	miniGUI::Window::size = size;
	miniGUI::Window::closed = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	miniGUI::Window::sdlWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_SHOWN);
}

miniGUI::Window::~Window(){
	SDL_DestroyWindow(miniGUI::Window::sdlWindow);
	SDL_Quit();
}

void miniGUI::Window::update(){
	miniGUI::__InputState_t* inputState = miniGUI::Window::handleInput();
	miniGUI::Window::canvas -> __update(inputState);
	delete(inputState);
}

void miniGUI::Window::draw(){
	miniGUI::Window::canvas -> __draw();
}

void miniGUI::Window::setCanvas(Canvas* canvas){
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
