#ifndef CANVAS_H
#define CANVAS_H

#include <SDL.h>
#include "Color.h"
//#include "MathUtility.h"

class Canvas
{
public:
	Uint32* PixelData;
	int width, height;
	SDL_Rect rect;

	Canvas(int _w, int _h) : width(_w), height(_h)
	{
		PixelData = new Uint32[width * height];
		rect.x = 0;
		rect.y = 0;
		rect.w = width;
		rect.h = height;
	}

	void DrawPixel(Color& c, int x, int y);

	// Bresenham's line algorithm
	void DrawLine(Color& c, int x1, int y1, int x2, int y2);
};


#endif	// £¡CANVAS_H
