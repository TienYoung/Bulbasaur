#include "Canvas.h"



void Canvas::DrawPixel(Color& c, int x, int y)
{
	PixelData[x + y * width] = c.toUint32();
}

void Canvas::DrawLine(Color& c, int x0, int y0, int x1, int y1)
{

	// Line is a pixel
	if (x0 == x1 && y0 == y1)
	{
		DrawPixel(c, x0, y0);
	}
	// Vertical line
	else if (x0 == x1)
	{
		int inc = (y0 < y1) ? 1 : -1;
		for (int i = y0; i != y1; i += inc)
		{
			DrawPixel(c, x0, i);
		}
		DrawPixel(c, x1, y1);
	}
	// Horizontal line
	else if (y0 == y1)
	{
		int inc = (x0 < x1) ? 1 : -1;
		for (int i = x0; i != x1; i += inc)
		{
			DrawPixel(c, i, y0);
		}
		DrawPixel(c, x1, y1);
	}
	else
	{
		int dx = x1 - x0;
		int dy = y1 - y0;
		
		// increment direction
		int ux = (dx < 0) ? -1 : 1;
		int uy = (dy < 0) ? -1 : 1;


		// Slope < 1
		if (abs(dx) > abs(dy))
		{
			ux
		}
		// Slope >1
		else
		{

		}
	}
}
