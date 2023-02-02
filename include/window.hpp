#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <stdint.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "inputState.hpp"
#include "canvas.hpp"

namespace miniGUI{
	class Window{
	public:	
		/** PUBLIC CLASS FUNCTIONS **/
		Window(Vector2i size, std::string title);
		~Window();

		void update();
		void draw();

		void setCanvas(miniGUI::Canvas* canvas);
		miniGUI::Canvas* getCanvas();
		
		int getWidth();
		int getHeight();

		bool shouldClose();

	private:
		/** PRIVATE CLASS FUNCTIONS **/
		__InputState_t* handleInput();

		/** PRIVATE CLASS VARIABLES **/
		SDL_Window* sdlWindow;
		SDL_Renderer* renderer;

		miniGUI::Vector2i size;
		miniGUI::Canvas* canvas;

		bool closed;
	};
}

#endif