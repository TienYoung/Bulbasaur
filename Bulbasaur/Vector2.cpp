#include "Vector2.h"

Vector2& Vector2::operator=(const Vector2& a)
{
	x = a.x; y = a.y;
	return *this;
}

Vector2& Vector2::operator/=(float a)
{
	float oneOverA = 1.0f / a;
	x *= oneOverA; y *= oneOverA;
	return *this;
}

Vector2 Vector2::operator/(float a) const
{
	float oneOverA = 1.0f / a;
	return Vector2(x * oneOverA, y * oneOverA);
}

Vector2& Vector2::operator+=(const Vector2& a)
{
	x += a.x; y += a.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& a) const
{
	return Vector2(x + a.x, y + a.y);
}

bool Vector2::operator!=(const Vector2& a) const
{
	return x != a.x || y != a.y;
}

bool Vector2::operator==(const Vector2& a) const
{
	return x == a.x && y == a.y;
}

void Vector2::zero()
{
	x = y = 0.0f;
}

Vector2& Vector2::operator-=(const Vector2& a)
{
	x -= a.x; y -= a.y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& a) const
{
	return Vector2(x - a.x, y - a.y);
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

Vector2& Vector2::operator*=(float a)
{
	x *= a; y *= a;
	return *this;
}

Vector2 Vector2::operator*(float a) const
{
	return Vector2(x * a, y * a);
}

void Vector2::normalize()
{
	float length = this->Length();
	if (length != 0.0f) {
		float inv = 1.0f / length;
		x *= inv;
		y *= inv;
	}
}

float Vector2::operator|(const Vector2& a) const
{
	return x * a.x + y * a.y;
}



//
// Non-Member Functions
//
Vector2 operator*(float k, const Vector2& v)
{
	return Vector2(k * v.x, k * v.y);
}



