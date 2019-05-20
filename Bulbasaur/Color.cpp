#include "Color.h"

Color Color::operator*(const Color& c) const
{
	return Color(uintR * c.uintR, uintG * c.uintG, uintB * c.uintB);
}

Color Color::operator+(const Color& c) const
{
	return Color(uintR + c.uintR, uintG + c.uintG, uintB + c.uintB);
}

Uint32 Color::toUint32()
{
	return uintR << 24 | uintG << 16 | uintB << 8 | uintA;
}

//
// Non_Member Functions
//
