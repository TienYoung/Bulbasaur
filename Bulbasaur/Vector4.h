#ifndef VECTOR4_H
#define VECTOR4_H

#include "MathUtility.h"

class Vector4
{
public:
	float x, y, z, w;
	Vector4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
	Vector4(const Vector4& a) : x(a.x), y(a.y), z(a.z), w(a.w) {}
	Vector4(float _x, float _y, float _z) :x(_x), y(_y), z(_z), w(1.0f) {}

	// 重载赋值运算符并返回引用
	//Vector4& operator=(const Vector4 &a);

	bool operator==(const Vector4& a) const;

	bool operator!=(const Vector4& a) const;

	// 向量点乘,重载"*"运算符
	float operator*(const Vector4 & a) const;

	Vector4 operator-() const;

	Vector4 operator+(const Vector4 & a) const;

	Vector4 operator-(const Vector4 & a) const;

	// 向量与标量相乘，重载"*"运算符
	Vector4 operator*(float a)const;

	Vector4 operator/(float a)const;

	Vector4& operator+=(const Vector4 & a);

	Vector4& operator-=(const Vector4 & a);

	Vector4& operator*=(float a);

	Vector4& operator/=(float a);

	// 置为零向量
	void zero();

	// 向量标准化
	void normalize();

	// 向量模长
	static inline float Magnitude(const Vector4& a)
	{
		float sq = a.x * a.x + a.y * a.y + a.z * a.z;
		return sqrtf(sq);
	}

	// 向量叉乘
	static inline Vector4 Cross(const Vector4& a, const Vector4& b)
	{
		return Vector4(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		);
	}

	// 向量距离
	static inline float Distance(const Vector4& a, const Vector4& b)
	{
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		float dz = a.z - a.z;
		return sqrtf(dx * dx + dy * dy + dz * dz);
	}

	// 向量插值，t取值 [0, 1]
	static inline Vector4 Leap(const Vector4 & a, const Vector4 & b, float t)
	{
		return Vector4(a + (b - a) * t);
	}
};


// 标量左乘，重载"*"运算符
Vector4 operator*(float k, const Vector4 & v);




#endif // !VECTOR4_H
