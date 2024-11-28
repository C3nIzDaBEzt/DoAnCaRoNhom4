#include"Header.h"
#include <conio.h>
#include <iostream>
#include "Sound.h"
#include <string>
#include <Windows.h>
#include <iomanip>
#include"Draw.h"

using namespace std;

void displaysetting(int selected) {
	const string options[] = { "SFX", "LANGUAGE" };
	const int numOptions = sizeof(options) / sizeof(options[0]);
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
	clearScreen();
	DrawBg_Hong();
	drawSetting(32,1);
	
	//DrawC(0,15);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | (15 << 4));
	SetConsoleOutputCP(CP_UTF8);
	GotoXY(46, 12);
	cout << u8"┌────────────────────────┐" << endl;
	for (int i = 0; i < numOptions; i++) {
		if (i == selected) {
			// Mục đang chọn với màu chữ xanh lam
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
			SetConsoleOutputCP(CP_UTF8);
			GotoXY(46, 13+i%2);//di chuyen toi cho option
			cout << u8"│   >> " << options[i];
			if (i == 0) { // Chỉ hiển thị trạng thái cho SFX
				cout << setw(10) << (isSFXEnabled ? " (On)" : " (Off)") << u8"     │" << endl;
			}
			else {
				GotoXY(70, 14);
				cout << u8" │" << endl; // Không hiển thị trạng thái cho LANGUAGE
			}
		}
		else {
			// Mục không chọn với màu mặc định (trắng)
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | (15 << 4));
			GotoXY(43, 13 + i % 2);//di chuyen toi cho option
			cout << u8"   │      " << options[i];
			if (i == 0) { // Chỉ hiển thị trạng thái cho SFX
				cout << setw(10) << (isSFXEnabled ? " (On)" : " (Off)") << u8"     │" << endl;
			}
			else {
				cout << u8"          │" << endl; // Không hiển thị trạng thái cho LANGUAGE
			}
		}
	}
	GotoXY(46, 15);
	cout << u8"└────────────────────────┘" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
}


void Setting() {
	int choice = 0;
	char key;
	while (true) {

		displaysetting(choice);
		key = _getch(); // Nhận đầu vào từ bàn phím mà không cần nhấn Enter

		if (key == 'w' || key == 'W') {
			choice = (choice - 1 + 2) % 2; // Di chuyển lên
		}
		else if (key == 's' || key == 'S') {
			choice = (choice + 1) % 2; // Di chuyển xuống
		}
		else if (key == 'Q' || key == 'q')
		{
			click();
			return;

		}
		else if (key == 13) {
			click();
			switch (choice) {
				//thuc hien hanh dong
			case 0:

				toggleSFX();
				GotoXY(72, 4);
				
				break;
			case 1:
				showInstructions();
				break;
			}
		}
	}
}
