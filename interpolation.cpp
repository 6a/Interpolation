#include "interpolation.h"

extern "C"
{
	float EaseOutQuad(float value, float start, float end)
	{
		end -= start;

		return end - (value * (2 - value)) + start;
	}

	float EaseInBounce(float value, float start, float end)
	{
		end -= start;
		float d = 1.f;
		return end - EaseOutBounce(d - value, 0.f, end) + start;
	}

	float EaseOutBounce(float value, float start, float end)
	{
		value /= 1.f;
		end -= start;
		if (value < (1 / 2.75f))
		{
			return end * (7.5625f * value * value) + start;
		}
		else if (value < (2 / 2.75f))
		{
			value -= (1.5f / 2.75f);
			return end * (7.5625f * (value)*value + .75f) + start;
		}
		else if (value < (2.5 / 2.75))
		{
			value -= (2.25f / 2.75f);
			return end * (7.5625f * (value)*value + .9375f) + start;
		}
		else
		{
			value -= (2.625f / 2.75f);
			return end * (7.5625f * (value)*value + .984375f) + start;
		}
	}
}

