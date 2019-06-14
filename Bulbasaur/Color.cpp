#include "Color.h"

Color Color::operator*(const Color& c) const
{
	return Color(r * c.r, g * c.g, b * c.b);
}

Color Color::operator*(float a)const
{
	return Color(r * a, g * a, b * a);
}

Color Color::operator+(const Color& c) const
{
	return Color(r + c.r, g + c.g, b + c.b);
}

Uint32 Color::toUint32() const
{
	return uintR << 24 | uintG << 16 | uintB << 8 | uintA;
}

//
// Non_Member Functions
//
