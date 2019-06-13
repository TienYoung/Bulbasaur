#ifndef VECTOR3_H
#define VECTOR3_H

#include "MathUtility.h"

class Vector3
{
public:
	float x, y, z;
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
	Vector3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {}

	// 重载赋值运算符并返回引用
	Vector3& operator=(const Vector3 &a);

	bool operator==(const Vector3& a) const;

	bool operator!=(const Vector3& a) const;

	// 向量点乘,重载"|"运算符
	float operator|(const Vector3& a) const;

	Vector3 operator-() const;

	Vector3 operator+(const Vector3& a) const;

	Vector3 operator-(const Vector3& a) const;

	// 向量与标量相乘，重载"*"运算符
	Vector3 operator*(float a)const;

	Vector3 operator/(float a)const;

	Vector3& operator+=(const Vector3& a);

	Vector3& operator-=(const Vector3& a);

	Vector3& operator*=(float a);

	Vector3& operator/=(float a);

	// 置为零向量
	void zero();

	// 向量标准化
	void normalize();

	// 向量模长
	inline float Length()
	{
		return sqrtf(*this | *this);
	}

	// 向量叉乘
	static inline Vector3 Cross(const Vector3& a, const Vector3& b)
	{
		return Vector3(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		);
	}

	// 向量距离
	static inline float Distance(const Vector3& a, const Vector3& b)
	{
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		float dz = a.z - a.z;
		return sqrtf(dx * dx + dy * dy + dz * dz);
	}

	// 向量插值，t取值 [0, 1]
	static inline Vector3 Leap(const Vector3& a, const Vector3& b, float t)
	{
		return LinearInterpolate(a, b, t); 
	}
};


// 标量左乘，重载"*"运算符
Vector3 operator*(float k, const Vector3& v);




#endif // !VECTOR3_H
