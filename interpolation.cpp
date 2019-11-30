#include "interpolation.h"

extern "C"
{
	float EaseInQuad(float value, float start, float end)
	{
		return 1 - EaseOutQuad(value, start, end);
	}

	float EaseOutQuad(float value, float start, float end)
	{
		end -= start;

		return end - (value * (2 - value)) + start;
	}

	float EaseInOutQuad(float value, float start, float end)
	{
		float output = 0;

		end -= start;

		if (value <= 0.5f)
		{
			output = 2.0f * (value * value);
		}
		else
		{
			value -= 0.5f;
			output = 2.0f *  value * (1.0f - value) + 0.5f;
		}

		return end - output + start;
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

