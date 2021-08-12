#pragma once

#include <chrono>
#include "Core.h"

namespace highloUnit
{
	class Timer
	{
	private:
		bool Stopped;
		const char *Name;
		const char *OutputString;
		const char *RawTimeMeasure;
		std::chrono::time_point<std::chrono::high_resolution_clock> StartPoint;

	public:

		HL_UNIT_API Timer(const char *name = "default");
		HL_UNIT_API ~Timer();

		HL_UNIT_API void Start(const char *name = "");
		HL_UNIT_API void Stop();
		HL_UNIT_API bool IsStopped() const;

		HL_UNIT_API const char *GetName() const;
		HL_UNIT_API const char *GetOutputString() const;
		HL_UNIT_API const char *GetRawTimeMeasure() const;
		HL_UNIT_API void PrintOutputString();
	};
}

