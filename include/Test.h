#pragma once

#include <string>
#include <iostream>

#include "Core/Core.h"
#include "Core/Timer.h"

namespace highloUnit
{
	class Test
	{
	public:

		HL_UNIT_API bool AssertEqual(Timer &timer, const char *str1, wchar_t *str2);
		HL_UNIT_API bool AssertNotEqual(Timer &timer, const char *str1, wchar_t *str2);

		HL_UNIT_API bool AssertEqual(Timer &timer, const char *str1, const char *str2);
		HL_UNIT_API bool AssertNotEqual(Timer &timer, const char *str1, const char *str2);

		template<typename T>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const T &str1, const T &str2)
		{
			HL_UNIT_ASSERT(str1 == str2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const double &d1, const double &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const float &d1, const float &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const bool &d1, const bool &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const std::string &d1, const std::string &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, char *const &d1, char *const &d2)
		{
			HL_UNIT_ASSERT(strcmp(d1, d2) == 0, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const int32 &d1, const int32 &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const uint32 &d1, const uint32 &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<typename T>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const T &str1, const T &str2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(str1 != str2, timer.GetName());

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const double &d1, const double &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const float &d1, const float &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const bool &d1, const bool &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const std::string &d1, const std::string &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, char *const &d1, char *const &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(strcmp(d1, d2) != 0, timer.GetName());

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const int32 &d1, const int32 &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const uint32 &d1, const uint32 &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}
	};
}

