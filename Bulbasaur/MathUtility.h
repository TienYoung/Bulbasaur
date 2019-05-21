#ifndef	MATHUTILITY_H
#define MATHUTILITY_H

#include <SDL.h>
#include <math.h>
#include <random>

// 计算插值：t 为 [0, 1] 之间的数值
float inline LinearInterpolate(float x1, float x2, float t)
{
	return x1 + (x2 - x1) * t;
}

template <class T>
T inline Clamp(T value, T min, T max)
{
	if (value < min)
	{
		return min;
	}
	else if (value > max)
	{
		return max;
	}
	else
	{
		return value;
	}
}


namespace Random
{
	static std::uniform_int_distribution<Uint32> u(0, 0xFFFFFFFF);
	static std::default_random_engine e;
	static Uint32 GetUint32()
	{
		return u(e);
	}
};


#endif // !MATHUTILITY_H
