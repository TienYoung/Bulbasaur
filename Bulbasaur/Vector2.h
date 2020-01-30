#ifndef VECTOR2_H
#define VECTOR2_H

#include "MathUtility.h"

class Vector2
{
public:
	float x, y;
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(const Vector2& a) : x(a.x), y(a.y) {}
	Vector2(float _x, float _y) :x(_x), y(_y) {}

	// 重载赋值运算符并返回引用
	Vector2& operator=(const Vector2& a);

	bool operator==(const Vector2& a) const;

	bool operator!=(const Vector2& a) const;

	// 向量点乘,重载"|"运算符
	float operator|(const Vector2& a) const;

	Vector2 operator-() const;

	Vector2 operator+(const Vector2& a) const;

	Vector2 operator-(const Vector2& a) const;

	// 向量与标量相乘，重载"*"运算符
	Vector2 operator*(float a)const;

	Vector2 operator/(float a)const;

	Vector2& operator+=(const Vector2& a);

	Vector2& operator-=(const Vector2& a);

	Vector2& operator*=(float a);

	Vector2& operator/=(float a);

	// 置为零向量
	void zero();

	// 向量标准化
	void normalize();

	// 向量模长
	inline float Length()
	{
		return sqrtf(*this | *this);
	}

	// 向量距离
	static inline float Distance(const Vector2& a, const Vector2& b)
	{
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		return sqrtf(dx * dx + dy * dy);
	}

	// 向量插值，t取值 [0, 1]
	static inline Vector2 Leap(const Vector2& a, const Vector2& b, float t)
	{
		return LinearInterpolate(a, b, t);
	}
};


// 标量左乘，重载"*"运算符
Vector2 operator*(float k, const Vector2& v);




#endif // !VECTOR2_H
