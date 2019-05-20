#ifndef	MATHUTILITY_H
#define MATHUTILITY_H

#include <math.h>

// 计算插值：t 为 [0, 1] 之间的数值
float inline LinearInterpolate(float x1, float x2, float t)
{
	return x1 + (x2 - x1) * t;
}

float inline clamp(float value, float min, float max)
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



#endif // !MATHUTILITY_H
