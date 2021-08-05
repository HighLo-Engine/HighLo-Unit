#pragma once

#include <string>
#include <functional>

#include "Core/Core.h"
#include "Core/Console.h"
#include "Core/Timer.h"

using HighLoUnitFunc = std::function<bool()>;

namespace highloUnit
{
#define HL_UNIT_ASSERT(x, testName) { if(!(x)) { Ref<Console> console = Console::Create(); ConsoleForeground foreground = ConsoleForeground::RED; ConsoleBackground background = ConsoleBackground::BLACK; std::stringstream ss; ss << "Error: Test " << testName << " has failed."; console->WriteLine(ss.str().c_str(), foreground, background); return true; } }

	struct UnitTestEntry
	{
		bool Enabled = true;
		HighLoUnitFunc Function;
		const char *FunctionName;

		HL_UNIT_API UnitTestEntry(const HighLoUnitFunc &func, bool enabled = true, const char *funcName = "")
		{
			Enabled = enabled;
			Function = func;
			FunctionName = funcName;
		}
	};

	class UnitTest
	{
	private:

		std::vector<UnitTestEntry> UnitFuncs;

	public:

		HL_UNIT_API void AppendTest(const HighLoUnitFunc &func, bool enabled);
		HL_UNIT_API void AppendAllTests(const std::vector<UnitTestEntry> &funcs);

		HL_UNIT_API int32 ExecuteTests();

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

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const double &d1, const double &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const float &d1, const float &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const bool &d1, const bool &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const std::string &d1, const std::string &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, char *const &d1, char *const &d2)
		{
			HL_UNIT_ASSERT(strcmp(d1, d2) == 0, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const int32 &d1, const int32 &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertEqual(Timer &timer, const uint32 &d1, const uint32 &d2)
		{
			HL_UNIT_ASSERT(d1 == d2, timer.GetName());

			if (!timer.IsStopped())
				timer.Stop();

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<typename T>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const T &str1, const T &str2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(str1 != str2, timer.GetName());

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const double &d1, const double &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const float &d1, const float &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const bool &d1, const bool &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const std::string &d1, const std::string &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, char *const &d1, char *const &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(strcmp(d1, d2) != 0, timer.GetName());

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const int32 &d1, const int32 &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}

		template<>
		HL_UNIT_API inline static bool AssertNotEqual(Timer &timer, const uint32 &d1, const uint32 &d2)
		{
			if (!timer.IsStopped())
				timer.Stop();

			HL_UNIT_ASSERT(d1 != d2, timer.GetName());

			Ref<Console> console = Console::Create();
			ConsoleForeground foreground = ConsoleForeground::GREEN;
			ConsoleBackground background = ConsoleBackground::BLACK;

			std::stringstream ss;
			ss << "OK: Test " << timer.GetName() << " has passed." << timer.GetOutputString();

			console->WriteLine(ss.str().c_str(), foreground, background);

			return false;
		}


	};
}
