#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace miniGUI{
	struct Vector2i_s{
		int x, y;
		Vector2i_s(){} 								// Default Constructor
		Vector2i_s(int x, int y) : x(x), y(y) {}
	} typedef Vector2i;
}

#endif