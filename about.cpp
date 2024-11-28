#include "header.h"
#include <windows.h>
#include<iostream>;
#include <conio.h>
#include "sound.h"
#include "Draw.h"

void about() {
	clearScreen();
	DrawBg_Xanh();
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15<<4));

	drawAbout(39, 1);
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	SetConsoleOutputCP(CP_UTF8);
	GotoXY(34, 9); std::cout << u8"██████████████████████████████████████████████████" << "\n";
	GotoXY(32, 10); std::cout << u8"██████████████████████████████████████████████████████" << "\n";
	GotoXY(30, 11); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(45, 11); std::cout << u8"Teacher_Instructors:Trương Toàn Thịnh";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 12); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(35, 12); std::cout << u8"GROUP 04:";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 13); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(45, 13); std::cout << u8"+Đỗ Ngọc Gia Bảo - Leader(24120263)";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 14); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(45, 14); std::cout << u8"+Huỳnh Thanh Tú          (24120235)";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 15); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(45, 15); std::cout << u8"+Trần Lê Quốc Bảo        (24120268)";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 16); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(45, 16); std::cout << u8"+Nguyễn Văn Toàn         (24120232)";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 17); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(45, 17); std::cout << u8"+Trần Thiên An           (24120255)";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(30, 18); std::cout << u8"██████████████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
	GotoXY(45, 18); std::cout << u8"Press Q to return Menu  ";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
	GotoXY(32, 19); std::cout << u8"██████████████████████████████████████████████████████" << "\n";
	GotoXY(34, 20); std::cout << u8"██████████████████████████████████████████████████" << "\n";
	SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
	GotoXY(84, 9); std::cout << u8"█" << "\n";
	GotoXY(86, 10); std::cout << u8"█" << "\n";
	GotoXY(88, 11); std::cout << u8"█" << "\n";
	GotoXY(88, 12); std::cout << u8"█" << "\n";
	GotoXY(88, 13); std::cout << u8"█" << "\n";
	GotoXY(88, 14); std::cout << u8"█" << "\n";
	GotoXY(88, 15); std::cout << u8"█" << "\n";
	GotoXY(88, 16); std::cout << u8"█" << "\n";
	GotoXY(88, 17); std::cout << u8"█" << "\n";
	GotoXY(88, 18); std::cout << u8"█" << "\n";
	GotoXY(86, 19); std::cout << u8"█" << "\n";
	GotoXY(84, 20); std::cout << u8"█" << "\n";
	
	while (true) {
		char key = _getch(); // Nhận đầu vào từ bàn phím
		if (key == 'q' || key == 'Q') {
			click();
			return;
			// Quay về menu
		}
	}
}

