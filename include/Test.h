#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Core/Core.h"
#include "Core/Timer.h"

namespace highloUnit
{
	namespace utils
	{
		static char *ConvertFromWide(wchar_t *str)
		{
			size_t size = wcslen(str) + 1;
			size_t convertedChars = 0;
			char *nstring = new char[size * 2];

			// Put a copy of the converted string into nstring
			wcstombs_s(&convertedChars, nstring, size * 2, str, _TRUNCATE);

			return nstring;
		}
	}

	class Test
	{
	public:

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
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, wchar_t *const &d1, wchar_t *const &d2)
		{
			HL_UNIT_ASSERT(wcscmp(d1, d2) == 0, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const char &d1, const char &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const std::vector<char*> &d1, const std::vector<char*> &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

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
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, wchar_t *const &d1, wchar_t *const &d2)
		{
			HL_UNIT_ASSERT(wcscmp(d1, d2) != 0, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const char &d1, const char &d2)
		{
			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const std::vector<char*> &d1, const std::vector<char*> &d2)
		{
			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

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

