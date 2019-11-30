#pragma once

#ifdef DLL_EXPORT
#define DLL_EXPORT_API __declspec(dllexport)
#else
#define DLL_EXPORT_API __declspec(dllimport)
#endif

extern "C"
{
	DLL_EXPORT_API float EaseInQuad(float value, float start, float end);
	DLL_EXPORT_API float EaseOutQuad(float value, float start, float end);
	DLL_EXPORT_API float EaseInOutQuad(float value, float start, float end);
	DLL_EXPORT_API float EaseInBounce(float value, float start, float end);
	DLL_EXPORT_API float EaseOutBounce(float value, float start, float end);
}