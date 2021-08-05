#include "WindowsConsole.h"

#include <Windows.h>
#include <string>
#include <iostream>

namespace highloUnit
{
	namespace utils
	{
		static int32 ConvertForeground(ConsoleForeground foreground)
		{
			switch (foreground)
			{
				case ConsoleForeground::NONE: return 39;
				case ConsoleForeground::BLACK: return 30;
				case ConsoleForeground::DARK_RED: return 31;
				case ConsoleForeground::DARK_GREEN: return 32;
				case ConsoleForeground::DARK_YELLOW: return 33;
				case ConsoleForeground::DARK_BLUE: return 34;
				case ConsoleForeground::DARK_MAGENTA: return 35;
				case ConsoleForeground::DARK_CYAN: return 36;
				case ConsoleForeground::GRAY: return 37;
				case ConsoleForeground::DARK_GRAY: return 90;
				case ConsoleForeground::RED: return 91;
				case ConsoleForeground::GREEN:return  92;
				case ConsoleForeground::YELLOW: return 93;
				case ConsoleForeground::BLUE: return 94;
				case ConsoleForeground::MAGENTA: return 95;
				case ConsoleForeground::CYAN: return 96;
				case ConsoleForeground::WHITE: return 97;
			}

			return -1;
		}

		static int32 ConvertBackground(ConsoleBackground background)
		{
			switch (background)
			{
				case ConsoleBackground::NONE: return 49;
				case ConsoleBackground::BLACK: return 40;
				case ConsoleBackground::DARK_RED: return 41;
				case ConsoleBackground::DARK_GREEN: return 42;
				case ConsoleBackground::DARK_YELLOW: return 43;
				case ConsoleBackground::DARK_BLUE: return 44;
				case ConsoleBackground::DARK_MAGENTA: return 45;
				case ConsoleBackground::DARK_CYAN: return 46;
				case ConsoleBackground::GRAY: return 47;
				case ConsoleBackground::DARK_GRAY: return 100;
				case ConsoleBackground::RED: return 101;
				case ConsoleBackground::GREEN: return 102;
				case ConsoleBackground::YELLOW: return 103;
				case ConsoleBackground::BLUE: return 104;
				case ConsoleBackground::MAGENTA: return 105;
				case ConsoleBackground::CYAN: return 106;
				case ConsoleBackground::WHITE: return 107;
			}

			return -1;
		}
	}

	void WindowsConsole::SetColor(int32 color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
	
	void WindowsConsole::EnableVirtualTerminalProcessing()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		if (!(dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING))
		{
			dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
			SetConsoleMode(hOut, dwMode);
		}
	}
	
	void WindowsConsole::ResetTerminalFormat()
	{
		std::cout << u8"\033[0m";
	}
	
	void WindowsConsole::SetVirtualTerminalFormat(ConsoleForeground foreground, ConsoleBackground background, std::set<ConsoleTextStyle> styles)
	{
		std::string format = u8"\033[";
		format.append(std::to_string(utils::ConvertForeground(foreground)));
		format.append(u8";");
		format.append(std::to_string(utils::ConvertBackground(background)));

		if (styles.size() > 0)
		{
			for (auto it = styles.begin(); it != styles.end(); ++it)
			{
				format.append(u8";");
				format.append(std::to_string(static_cast<int>(*it)));
			}
		}

		format.append(u8"m");
		std::cout << format;
	}
	
	void WindowsConsole::Clear()
	{
		std::system(u8"cls");
	}
	
	void WindowsConsole::Write(const char *str, ConsoleForeground foreground, ConsoleBackground background, std::set<ConsoleTextStyle> styles)
	{
		std::string s(str);
		std::wstring ws(s.begin(), s.end());

		EnableVirtualTerminalProcessing();
		SetVirtualTerminalFormat(foreground, background, styles);
		WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), ws.c_str(), static_cast<DWORD>(ws.size()), nullptr, nullptr);
		ResetTerminalFormat();
	}
	
	void WindowsConsole::WriteLine(const char *str, ConsoleForeground foreground, ConsoleBackground background, std::set<ConsoleTextStyle> styles)
	{
		Write(str, foreground, background, styles);
		std::cout << std::endl;
	}
	
	void WindowsConsole::WriteLine()
	{
		std::cout << std::endl;
	}
}

