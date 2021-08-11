#include "Test.h"

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

	bool Test::AssertEqual(Timer &timer, const char *str1, wchar_t *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		char *result = utils::ConvertFromWide(str2);
		HL_UNIT_ASSERT(strcmp(str1, result) == 0, timer.GetName());

		std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
		return false;
	}

	bool Test::AssertNotEqual(Timer &timer, const char *str1, wchar_t *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		char *result = utils::ConvertFromWide(str2);
		HL_UNIT_ASSERT(strcmp(str1, result) != 0, timer.GetName());

		std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
		return false;
	}

	bool Test::AssertEqual(Timer &timer, const char *str1, const char *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		HL_UNIT_ASSERT(strcmp(str1, str2) == 0, timer.GetName());

		std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
		return false;
	}

	bool Test::AssertNotEqual(Timer &timer, const char *str1, const char *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		HL_UNIT_ASSERT(strcmp(str1, str2) != 0, timer.GetName());

		std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
		return false;
	}
}

