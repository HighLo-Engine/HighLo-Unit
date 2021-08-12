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
		RawTimeMeasure = "";
		StartPoint = std::chrono::high_resolution_clock::now();
	}
	
	void Timer::Stop()
	{
		auto endPoint = std::chrono::high_resolution_clock::now();

		int64 start = std::chrono::time_point_cast<std::chrono::microseconds>(StartPoint).time_since_epoch().count();
		int64 end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

		std::stringstream formattedStream;
		formattedStream << " The Test took " << (end - start) << " microseconds.";
		std::string s = formattedStream.str();
		OutputString = s.c_str();

		std::stringstream rawStream;
		rawStream << "" << end - start;
		std::string sa = rawStream.str();
		RawTimeMeasure = sa.c_str();

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

	const char *Timer::GetRawTimeMeasure() const
	{
		return RawTimeMeasure;
	}
	
	void Timer::PrintOutputString()
	{
		std::cout << OutputString << std::endl;
	}
}

