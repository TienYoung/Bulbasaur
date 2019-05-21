#include "Canvas.h"



void Canvas::DrawPixel(Color& c, int x, int y)
{
	PixelData[x + y * width] = c.toUint32();
}
