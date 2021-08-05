#include "Console.h"

#include "../Platform/Windows/WindowsConsole.h"
#include "../Platform/Linux/LinuxConsole.h"

namespace highloUnit
{
	Ref<Console> Console::Create()
	{
	#ifdef HL_PLATFORM_WINDOWS
		return CreateRef<WindowsConsole>();
	#elif PLATFORM_LINUX
		return CreateRef<LinuxConsole>();
	#elif PLATFORM_MAC
		return CreateRef<LinuxConsole>();
	#else
		return nullptr;
	#endif
	}
}

