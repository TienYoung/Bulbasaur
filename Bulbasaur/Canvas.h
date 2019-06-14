#ifndef CANVAS_H
#define CANVAS_H

#include <SDL.h>
#include "Color.h"
#include "Vector.h"

struct vertex
{
	Vector2 p;
	Color c;
// 	vertex()
// 	{
// 		p = Vector2();
// 		c = Color();
// 	}
};

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

	void DrawPixel(const Color& c, int x, int y);

	// Bresenham's line algorithm
	void DrawLine(const Color& c, int x1, int y1, int x2, int y2);

	// Tiangle rasterization
	void DrawPrimitive(const vertex& V1, const vertex& V2, const vertex& V3);

	// Get Barycentric Coordinate
	static Vector3 GetBarycentricCoord(const Vector2& P1, const Vector2& P2, const Vector2& P3, const Vector2& P);
};



#endif	// £¡CANVAS_H
