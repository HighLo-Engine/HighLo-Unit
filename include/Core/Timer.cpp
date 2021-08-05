#include "Timer.h"

#include <iostream>
#include <sstream>

namespace highloUnit
{
	Timer::Timer(const char *name)
		: Name(name), Stopped(false)
	{
		StartPoint = std::chrono::high_resolution_clock::now();
	}

	Timer::~Timer()
	{
		if (!Stopped)
			Stop();
	}
	
	void Timer::Start(const char *name)
	{
		if (0 == strlen(Name))
			Name = name;

		Stopped = false;
		OutputString = "";
		StartPoint = std::chrono::high_resolution_clock::now();
	}
	
	void Timer::Stop()
	{
		auto endPoint = std::chrono::high_resolution_clock::now();

		int64 start = std::chrono::time_point_cast<std::chrono::microseconds>(StartPoint).time_since_epoch().count();
		int64 end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

		std::stringstream ss;
		ss << " The Test took " << (end - start) << " microseconds.";
		OutputString = ss.str().c_str();
		Stopped = true;
	}

	bool Timer::IsStopped() const
		{
		return Stopped;
		}
	
	const char *Timer::GetName() const
	{
		return Name;
	}
	
	const char *Timer::GetOutputString() const
	{
		return OutputString;
	}
	
	void Timer::PrintOutputString()
	{
		std::cout << OutputString << std::endl;
	}
}

