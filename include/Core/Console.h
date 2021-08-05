#pragma once

#include <set>
#include "Core.h"

namespace highloUnit
{
	enum class ConsoleTextStyle
	{
		NONE = 0,
		BOLD = 1,
		FAINT = 2,
		ITALIC = 3,
		UNDERLINE = 4,
		SLOW_BLINK = 5,
		RAPID_BLINK = 6,
		REVERSE = 7,
	};

	enum class ConsoleForeground
	{
		NONE = 0,
		BLACK,
		DARK_RED,
		DARK_GREEN,
		DARK_YELLOW,
		DARK_BLUE,
		DARK_MAGENTA,
		DARK_CYAN,
		GRAY,
		DARK_GRAY,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE
	};

	enum class ConsoleBackground
	{
		NONE = 0,
		BLACK,
		DARK_RED,
		DARK_GREEN,
		DARK_YELLOW,
		DARK_BLUE,
		DARK_MAGENTA,
		DARK_CYAN,
		GRAY,
		DARK_GRAY,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE
	};

	class Console
	{
	public:

		HL_UNIT_API virtual void SetColor(int32 color = 0x07) = 0;
		HL_UNIT_API virtual void EnableVirtualTerminalProcessing() = 0;
		HL_UNIT_API virtual void ResetTerminalFormat() = 0;
		HL_UNIT_API virtual void SetVirtualTerminalFormat(ConsoleForeground foreground, ConsoleBackground background, std::set<ConsoleTextStyle> styles) = 0;
		
		HL_UNIT_API virtual void Clear() = 0;
		
		HL_UNIT_API virtual void Write(const char *str, ConsoleForeground foreground = ConsoleForeground::NONE, ConsoleBackground background = ConsoleBackground::NONE, std::set<ConsoleTextStyle> styles = {}) = 0;
		HL_UNIT_API virtual void WriteLine(const char *str, ConsoleForeground foreground = ConsoleForeground::NONE, ConsoleBackground background = ConsoleBackground::NONE, std::set<ConsoleTextStyle> styles = {}) = 0;
		HL_UNIT_API virtual void WriteLine() = 0;

		HL_UNIT_API static Ref<Console> Create();
	};
}

