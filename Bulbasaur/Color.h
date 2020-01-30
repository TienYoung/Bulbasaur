#ifndef COLOR_H
#define COLOR_H

#include <SDL.h>

class Color
{
public:
	float r, g, b, a;
	Uint8 uintR, uintG, uintB, uintA;
	Color() :r(0.0f), g(0.0f), b(0.0f), a(1.0f)
	{
		uintR = (Uint8)(r * 255);
		uintG = (Uint8)(g * 255);
		uintB = (Uint8)(b * 255);
		uintA = (Uint8)(a * 255);
	}

	Color(float _r, float _g, float _b, float _a = 1.0f) :r(_r), g(_g), b(_b), a(_a)
	{
		uintR = (Uint8)(r * 255);
		uintG = (Uint8)(g * 255);
		uintB = (Uint8)(b * 255);
		uintA = (Uint8)(a * 255);
	}

	Color(const Color& c) : r(c.r), g(c.g), b(c.b), a(c.a), uintR(c.uintR), uintG(c.uintG), uintB(c.uintB), uintA(c.uintA)
	{

	}

	Color(Uint32 c)
	{
		uintR = c >> 24 & 0xFF;
		uintG = c >> 16 & 0xFF;
		uintB = c >> 8 & 0xFF;
		uintA = c & 0xFF;

		float oneOver255 = (float)(1.0f / 255.0f);
		r = uintR * oneOver255;
		g = uintG * oneOver255;
		b = uintB * oneOver255;
		a = uintA * oneOver255;
	}

// 	Color(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a = 0xFF) : uintR(_r), uintG(_g), uintB(_b), uintA(_a)
// 	{
// 		float oneOver255 = (float)(1.0f / 255.0f);
// 		r = _r * oneOver255;
// 		g = _g * oneOver255;
// 		b = _b * oneOver255;
// 		a = _a * oneOver255;
// 	}

	Color operator*(const Color& c)const;
	Color operator*(float a)const;
	Color operator+(const Color& c)const;

	Uint32 toUint32() const;

};

#endif // !COLOR_H
