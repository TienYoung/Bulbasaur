#include "Vector3.h"

Vector3& Vector3::operator=(const Vector3& a)
{
	x = a.x; y = a.y; z = a.z;
	return *this;
}

Vector3& Vector3::operator/=(float a)
{
	float oneOverA = 1.0f / a;
	x *= oneOverA; y *= oneOverA; z *= oneOverA;
	return *this;
}

Vector3 Vector3::operator/(float a) const
{
	float oneOverA = 1.0f / a;
	return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
}

Vector3& Vector3::operator+=(const Vector3& a)
{
	x += a.x; y += a.y; z += a.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3& a) const
{
	return Vector3(x + a.x, y + a.y, z + a.z);
}

bool Vector3::operator!=(const Vector3& a) const
{
	return x != a.x || y != a.y || z != a.z;
}

bool Vector3::operator==(const Vector3& a) const
{
	return x == a.x && y == a.y && z == a.z;
}

void Vector3::zero()
{
	x = y = z = 0.0f;
}

Vector3& Vector3::operator-=(const Vector3& a)
{
	x -= a.x; y -= a.y; z -= a.z;
	return *this;
}

Vector3 Vector3::operator-(const Vector3& a) const
{
	return Vector3(x - a.x, y - a.y, z - a.z);
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

Vector3& Vector3::operator*=(float a)
{
	x *= a; y *= a; z *= a;
	return *this;
}

Vector3 Vector3::operator*(float a) const
{
	return Vector3(x * a, y * a, z * a);
}

void Vector3::normalize()
{
	float length = this->Length();
	if (length != 0.0f) {
		float inv = 1.0f / length;
		x *= inv;
		y *= inv;
		z *= inv;
	}
}

float Vector3::operator|(const Vector3& a) const
{
	return x * a.x + y * a.y + z * a.z;
}



//
// Non-Member Functions
//
Vector3 operator*(float k, const Vector3& v)
{
	return Vector3(k * v.x, k * v.y, k * v.z);
}



