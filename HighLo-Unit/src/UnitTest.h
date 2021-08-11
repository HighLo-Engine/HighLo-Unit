#pragma once

#include <functional>
#include <iostream>
#include <vector>

#include "Core/Core.h"
#include "Core/Timer.h"

using HighLoUnitFunc = std::function<bool()>;

namespace highloUnit
{
	struct UnitTestEntry
	{
		bool Enabled = true;
		HighLoUnitFunc Function;
		const char *FunctionName;

		HL_UNIT_API UnitTestEntry(const HighLoUnitFunc &func, bool enabled = true)
		{
			Function = func;
			FunctionName = "";
			Enabled = enabled;
		}

		HL_UNIT_API UnitTestEntry(const HighLoUnitFunc &func, const char *funcName, bool enabled = true)
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

		HL_UNIT_API void AppendTest(const HighLoUnitFunc &func, const char *name, bool enabled);
		HL_UNIT_API void AppendAllTests(const std::vector<UnitTestEntry> &funcs);

		HL_UNIT_API int32 ExecuteTests();
	};
}