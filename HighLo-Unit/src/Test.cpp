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
		int32 exitCode = 0, i = 0;
		Timer timer("GlobalTimer");
		Ref<Console> console = Console::Create();
		ConsoleForeground foreground = ConsoleForeground::GREEN;
		ConsoleBackground background = ConsoleBackground::BLACK;

		for (i = 0; i < UnitFuncs.size(); ++i)
		{
			if (!UnitFuncs[i].Enabled)
			{
				foreground = ConsoleForeground::YELLOW;
				std::stringstream ss;
				ss << "Skipped test " << UnitFuncs[i].FunctionName;

				console->WriteLine(ss.str().c_str(), foreground, background);
				continue;
			}

			exitCode = UnitFuncs[i].Function();
			if (exitCode == 1)
				{
				foreground = ConsoleForeground::RED;
				console->WriteLine("Error: Some tests have failed!", foreground, background);
				return 1;
				}
		}

		timer.Stop();
		std::stringstream ss;
		ss << "OK: All Tests have passed successfully!" << timer.GetOutputString();

		foreground = ConsoleForeground::GREEN;
		console->WriteLine(ss.str().c_str(), foreground, background);
		return exitCode;
	}

	bool UnitTest::AssertEqual(Timer &timer, const char *str1, wchar_t *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		char *result = utils::ConvertFromWide(str2);
		HL_UNIT_ASSERT(strcmp(str1, result) == 0, timer.GetName());

		Ref<Console> console = Console::Create();
		ConsoleForeground foreground = ConsoleForeground::GREEN;
		ConsoleBackground background = ConsoleBackground::BLACK;
		
		std::stringstream ss;
		ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

		console->WriteLine(ss.str().c_str(), foreground, background);
		return false;
	}

	bool UnitTest::AssertNotEqual(Timer &timer, const char *str1, wchar_t *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		char *result = utils::ConvertFromWide(str2);
		HL_UNIT_ASSERT(strcmp(str1, result) != 0, timer.GetName());

		Ref<Console> console = Console::Create();
		ConsoleForeground foreground = ConsoleForeground::GREEN;
		ConsoleBackground background = ConsoleBackground::BLACK;

		std::stringstream ss;
		ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

		console->WriteLine(ss.str().c_str(), foreground, background);
		return false;
	}

	bool UnitTest::AssertEqual(Timer &timer, const char *str1, const char *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		HL_UNIT_ASSERT(strcmp(str1, str2) == 0, timer.GetName());

		Ref<Console> console = Console::Create();
		ConsoleForeground foreground = ConsoleForeground::GREEN;
		ConsoleBackground background = ConsoleBackground::BLACK;

		std::stringstream ss;
		ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

		console->WriteLine(ss.str().c_str(), foreground, background);
		return false;
	}

	bool UnitTest::AssertNotEqual(Timer &timer, const char *str1, const char *str2)
	{
		if (!timer.IsStopped())
			timer.Stop();

		HL_UNIT_ASSERT(strcmp(str1, str2) != 0, timer.GetName());

		Ref<Console> console = Console::Create();
		ConsoleForeground foreground = ConsoleForeground::GREEN;
		ConsoleBackground background = ConsoleBackground::BLACK;

		std::stringstream ss;
		ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

		console->WriteLine(ss.str().c_str(), foreground, background);
		return false;
	}
}

