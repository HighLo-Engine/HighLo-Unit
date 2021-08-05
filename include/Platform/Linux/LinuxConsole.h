#pragma once

#include "../../Core/Console.h"

namespace highloUnit
{
	class LinuxConsole : public Console
	{
	public:

		HL_UNIT_API virtual void SetColor(int32 color = 0x07) override;
		HL_UNIT_API virtual void EnableVirtualTerminalProcessing() override;
		HL_UNIT_API virtual void ResetTerminalFormat() override;
		HL_UNIT_API virtual void SetVirtualTerminalFormat(ConsoleForeground foreground, ConsoleBackground background, std::set<ConsoleTextStyle> styles) override;

		HL_UNIT_API virtual void Clear() override;

		HL_UNIT_API virtual void Write(const char *str, ConsoleForeground foreground = ConsoleForeground::NONE, ConsoleBackground background = ConsoleBackground::NONE, std::set<ConsoleTextStyle> styles = {}) override;
		HL_UNIT_API virtual void WriteLine(const char *str, ConsoleForeground foreground = ConsoleForeground::NONE, ConsoleBackground background = ConsoleBackground::NONE, std::set<ConsoleTextStyle> styles = {}) override;
		HL_UNIT_API virtual void WriteLine() override;
	};
}

