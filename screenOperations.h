#ifndef SCREENOPERATIONS_H
#define SCREENOPERATIONS_H
#include <windows.h>
#include <iostream>
class screenOperations
{
	public:
		void setScreen(int x, int y) {
				HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
 
   MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);
		}
		
		void setFontBold() {
			HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);//you don't have to call this function every time

    CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
    GetCurrentConsoleFontEx(outcon, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
    font.dwFontSize.X = 7;
    font.dwFontSize.Y = 12;
    font.FontWeight = 100;
    SetCurrentConsoleFontEx(outcon, false, &font);
    SetConsoleTextAttribute(outcon, BOLD_FONTTYPE);
    
		}
		
		void setFontColor(int c) {
			 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			 SetConsoleTextAttribute(hConsole, c);
		}
	protected:
};

#endif
