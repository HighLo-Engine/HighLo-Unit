#include "UnitTest.h"

namespace highloUnit
{
	void UnitTest::AppendTest(const HighLoUnitFunc &func, const char *name, bool enabled)
	{
		UnitFuncs.push_back({ func, name, enabled });
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
		std::cout << "OK: All Tests have passed successfully! The test duration took " << timer.GetRawTimeMeasure() << " microseconds." << std::endl;
		return 0;
	}
}