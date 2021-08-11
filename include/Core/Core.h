#pragma once

#include <memory>

#ifdef HIGHLO_UNIT_USE_DLL

#ifdef HIGHLO_UNIT_LIBRARY_EXPORT
#define HL_UNIT_API __declspec(dllexport)
#else
#define HL_UNIT_API __declspec(dllimport)
#endif

#else

#define HL_UNIT_API /* NOTHING */

#endif

#define HL_UNIT_ASSERT(x, testName) { if(!(x)) { std::cout << "Error: Test " << testName << " has failed." << std::endl; return true; } }

namespace highloUnit
{
	typedef unsigned int uint32;
	typedef signed int int32;
	typedef unsigned long long uint64;
	typedef signed long long int64;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename... Args>
	constexpr Ref<T> CreateRef(Args&&... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

