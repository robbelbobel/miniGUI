#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <stdint.h>
#include <SDL_ttf.h>

#include "../inputState/inputState.hpp"
#include "../canvas/canvas.hpp"

namespace miniGUI{
	class Window{
	public:	
		/** PUBLIC CLASS FUNCTIONS **/
		Window(Vector2i size, std::string title);
		~Window();

		void update();
		void draw();

		void setCanvas(Canvas* canvas);
		miniGUI::Vector2i getSize();

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