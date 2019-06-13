#include "Vector4.h"

Vector4& Vector4::operator=(const Vector4& a)
{
	x = a.x; y = a.y; z = a.z; w = a.w;
	return *this;
}

Vector4& Vector4::operator/=(float a)
{
	float oneOverA = 1.0f / a;
	x *= oneOverA; y *= oneOverA; z *= oneOverA;
	return *this;
}

Vector4 Vector4::operator/(float a) const
{
	float oneOverA = 1.0f / a;
	return Vector4(x * oneOverA, y * oneOverA, z * oneOverA);
}

Vector4& Vector4::operator+=(const Vector4& a)
{
	x += a.x; y += a.y; z += a.z;
	return *this;
}

Vector4 Vector4::operator+(const Vector4& a) const
{
	return Vector4(x + a.x, y + a.y, z + a.z);
}

bool Vector4::operator!=(const Vector4& a) const
{
	return x != a.x || y != a.y || z != a.z || w != a.w;
}

bool Vector4::operator==(const Vector4& a) const
{
	return x == a.x && y == a.y && z == a.z && w == a.w;
}

void Vector4::zero()
{
	x = y = z = 0.0f;
}

Vector4& Vector4::operator-=(const Vector4& a)
{
	x -= a.x; y -= a.y; z -= a.z;
	return *this;
}

Vector4 Vector4::operator-(const Vector4& a) const
{
	return Vector4(x - a.x, y - a.y, z - a.z);
}

Vector4 Vector4::operator-() const
{
	return Vector4(-x, -y, -z);
}

Vector4& Vector4::operator*=(float a)
{
	x *= a; y *= a; z *= a;
	return *this;
}

Vector4 Vector4::operator*(float a) const
{
	return Vector4(x * a, y * a, z * a);
}

void Vector4::normalize()
{
	float length = this->Length();
	if (length != 0.0f) {
		float inv = 1.0f / length;
		x *= inv;
		y *= inv;
		z *= inv;
	}
}

float Vector4::operator|(const Vector4& a) const
{
	return x * a.x + y * a.y + z * a.z;
}



//
// Non-Member Functions
//
Vector4 operator*(float k, const Vector4& v)
{
	return Vector4(k * v.x, k * v.y, k * v.z);
}

