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

	void UnitTest::AppendTest(const HighLoUnitFunc &func, bool enabled)
	{
		UnitFuncs.push_back({ func, enabled });
	}

	void UnitTest::AppendAllTests(const std::vector<UnitTestEntry> &funcs)
	{
		for (UnitTestEntry entry : funcs)
		{
			UnitFuncs.push_back(entry);
		}
	}

	int32 UnitTest::ExecuteTests()
	{
		int32 exitCode = 0;
		int32 i = 0;
		Timer timer("GlobalTimer");

		for (i = 0; i < UnitFuncs.size(); ++i)
		{
			if (!UnitFuncs[i].Enabled)
			{
				std::cout << "Skipped test " << UnitFuncs[i].FunctionName << std::endl;
				continue;
			}

			exitCode = UnitFuncs[i].Function();
			if (exitCode == 1)
				{
				std::cout << "Error: Some tests have failed!" << std::endl;
				return 1;
				}
		}

		timer.Stop();
		std::cout << "OK: All Tests have passed successfully!" << std::endl;
		return 0;
	}

	bool UnitTest::AssertEqual(Timer &timer, const char *str1, wchar_t *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		char *result = utils::ConvertFromWide(str2);
		HL_UNIT_ASSERT(strcmp(str1, result) == 0, timer.GetName());

		std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
		return false;
	}

	bool UnitTest::AssertNotEqual(Timer &timer, const char *str1, wchar_t *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		char *result = utils::ConvertFromWide(str2);
		HL_UNIT_ASSERT(strcmp(str1, result) != 0, timer.GetName());

		std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
		return false;
	}

	bool UnitTest::AssertEqual(Timer &timer, const char *str1, const char *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		HL_UNIT_ASSERT(strcmp(str1, str2) == 0, timer.GetName());

		std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
		return false;
	}

	bool UnitTest::AssertNotEqual(Timer &timer, const char *str1, const char *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		HL_UNIT_ASSERT(strcmp(str1, str2) != 0, timer.GetName());

		std::cout << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString() << std::endl;
		return false;
	}
}

