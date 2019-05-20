#ifndef CANVAS_H
#define CANVAS_H

#include <SDL.h>
#include "Color.h"

class Canvas
{
public:
	Uint32* PixelData;
	int width, height;
	Canvas();

	void DrawPixel(Color& c, int x, int y);
};


#endif	// £¡CANVAS_H
