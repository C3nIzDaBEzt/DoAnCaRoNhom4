#include "header.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Draw.h"

void showInstructions() {
	clearScreen();
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15 << 4));
	clearScreen();
	DrawBg_Cam();
	drawRule(39, 1);
	
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(34, 9); std::cout << u8"██████████████████████████████████████████████████" << "\n";
	GotoXY(32, 10); std::cout << u8"██████████████████████████████████████████████████████" << "\n";
	GotoXY(30, 11); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(50, 11); std::cout << u8"'A'    : MOVE LEFT";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 12); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(50, 12); std::cout << u8"'D'    : MOVE RIGHT";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 13); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(50, 13); std::cout << u8"'W'    : MOVE UP";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 14); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(50, 14); std::cout << u8"'S'    : MOVE DOWN";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 15); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(50, 15); std::cout << u8"'ENTER': MARK";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 16); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(45, 16); std::cout << u8"Press Q to return Menu";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(32, 17); std::cout << u8"██████████████████████████████████████████████████████" << "\n";
	GotoXY(34, 18); std::cout << u8"██████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
	GotoXY(84, 9); std::cout << u8"█" << "\n";
	GotoXY(86, 10); std::cout << u8"█" << "\n";
	GotoXY(88, 11); std::cout << u8"█" << "\n";
	GotoXY(88, 12); std::cout << u8"█" << "\n";
	GotoXY(88, 13); std::cout << u8"█" << "\n";
	GotoXY(88, 14); std::cout << u8"█" << "\n";
	GotoXY(88, 15); std::cout << u8"█" << "\n";
	GotoXY(88, 16); std::cout << u8"█" << "\n";
	GotoXY(86, 17); std::cout << u8"█" << "\n";
	GotoXY(84, 18); std::cout << u8"█" << "\n";

	// Chờ người dùng nhấn 'Q' để quay lại menu
	while (true) {
		char key =_getch(); // Nhận đầu vào từ bàn phím
		if (key == 'q' || key == 'Q') {
			break; // Quay về menu
		}
	}
}

