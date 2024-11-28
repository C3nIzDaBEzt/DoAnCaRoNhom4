


#include <iostream>
#include <conio.h>
#include "Draw.h"
#include <Windows.h>

using namespace std;

void GotoXY1(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showInstructions() {
	system("cls");
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15 << 4));
	system("cls");
	DrawBg_Cam();
	drawRule(39, 1);

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY1(34, 9); std::cout << u8"██████████████████████████████████████████████████" << "\n";
	GotoXY1(32, 10); std::cout << u8"██████████████████████████████████████████████████████" << "\n";
	GotoXY1(30, 11); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY1(50, 11); std::cout << u8"'A'    : MOVE LEFT";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY1(30, 12); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY1(50, 12); std::cout << u8"'D'    : MOVE RIGHT";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY1(30, 13); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY1(50, 13); std::cout << u8"'W'    : MOVE UP";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY1(30, 14); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY1(50, 14); std::cout << u8"'S'    : MOVE DOWN";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY1(30, 15); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY1(50, 15); std::cout << u8"'ENTER': MARK";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY1(30, 16); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (126 << 4) | 0);
	GotoXY1(45, 16); std::cout << u8"Press Q to return Menu";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 126);
	GotoXY1(32, 17); std::cout << u8"██████████████████████████████████████████████████████" << "\n";
	GotoXY1(34, 18); std::cout << u8"██████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 6);
	GotoXY1(84, 9); std::cout << u8"█" << "\n";
	GotoXY1(86, 10); std::cout << u8"█" << "\n";
	GotoXY1(88, 11); std::cout << u8"█" << "\n";
	GotoXY1(88, 12); std::cout << u8"█" << "\n";
	GotoXY1(88, 13); std::cout << u8"█" << "\n";
	GotoXY1(88, 14); std::cout << u8"█" << "\n";
	GotoXY1(88, 15); std::cout << u8"█" << "\n";
	GotoXY1(88, 16); std::cout << u8"█" << "\n";
	GotoXY1(86, 17); std::cout << u8"█" << "\n";
	GotoXY1(84, 18); std::cout << u8"█" << "\n";

	// Chờ người dùng nhấn 'Q' để quay lại menu
	while (true) {
		char key = _getch(); // Nhận đầu vào từ bàn phím
		if (key == 'q' || key == 'Q') {
			break; // Quay về menu
		}
	}
}