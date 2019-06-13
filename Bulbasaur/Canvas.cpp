#include "Canvas.h"

void Canvas::DrawPixel(Color& c, int x, int y)
{
	if (0 <= x && x < width && 0 <= y && y < height)
	{
		PixelData[x + y * width] = c.toUint32();
	}
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
		// increment direction
		int inc = (y0 < y1) ? 1 : -1;
		for (int y = y0; y != y1; y += inc)
		{
			DrawPixel(c, x0, y);
		}
		DrawPixel(c, x1, y1);
	}
	// Horizontal line
	else if (y0 == y1)
	{
		// increment direction
		int inc = (x0 < x1) ? 1 : -1;
		for (int x = x0; x != x1; x += inc)
		{
			DrawPixel(c, x, y0);
		}
		DrawPixel(c, x1, y1);
	}
	else
	{
		int dx = abs(x1 - x0);
		int dy = abs(y1 - y0);

		// -1 <= Slope <= 1
		if (dx >= dy)
		{
			// Accumulation
			int acc = 0;
			// increment direction
			int incX = (x0 > x1) ? -1 : 1;
			int incY = (y0 > y1) ? -1 : 1;
			for (int x = x0, y = y0; x != x1 && y != y1; x += incX)
			{
				DrawPixel(c, x, y);
				// Accumulate short side
				acc += dy;
				if (acc >= dx)
				{
					// What the fuck
					acc -= dx;
					y += incY;
				}
			}
			DrawPixel(c, x1, y1);
		}
		// Slope > 1 || Slope < -1
		else
		{
			// Accumulation
			int acc = 0;
			// increment direction
			int incX = (x0 > x1) ? -1 : 1;
			int incY = (y0 > y1) ? -1 : 1;
			for (int x = x0, y = y0; x != x1 && y != y1; y += incY)
			{
				DrawPixel(c, x, y);
				// Accumulate short side
				acc += dx;
				if (acc >= dy)
				{
					// What the fuck
					acc -= dy;
					x += incX;
				}
			}
			DrawPixel(c, x1, y1);
		}
	}
}

void Canvas::DrawPrimitive(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float u, v, w;
}
