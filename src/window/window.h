#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

#include "../vector/vector.h"
#include "../canvas/canvas.h"

namespace miniGUI{
	class Window{
		// Public Variables
		Vector2i size;
		uint8_t parameters;
		
		// Private Variables
		Canvas* canvas;

		// Public Functions
		Window(Vector2i size, uint8_t parameters);

		void setCanvas(Canvas* canvas);
	};
}

#endif