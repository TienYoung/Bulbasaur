#include "Color.h"

Color Color::operator*(const Color& c) const
{
	return Color(uintR * c.uintR, uintG * c.uintG, uintB * c.uintB);
}

Color Color::operator+(const Color& c) const
{
	return Color(uintR + c.uintR, uintG + c.uintG, uintB + c.uintB);
}

//
// Non_Member Functions
//
