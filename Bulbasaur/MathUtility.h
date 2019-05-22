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
	static std::default_random_engine e;
	static std::uniform_int_distribution<Uint32> i(0, 0xFFFFFFFF);
	static std::uniform_real_distribution<float> r(0.0f, 1.0f);

	static Uint32 GetUint32()
	{
		return i(e);
	}

	static float GetNormalizedFloat()
	{
		return r(e);
	}
};


#endif // !MATHUTILITY_H
