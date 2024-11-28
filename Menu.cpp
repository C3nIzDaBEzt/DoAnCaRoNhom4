#include "header.h"
#include<iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "Draw.h"


using namespace std;

void drawcaro() {
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (15 << 4) | 0);
	clearScreen();
	DrawBg_xp();
	SetConsoleTextAttribute(hConsole, (15 << 4) | 12);
	DrawCaro(38,1);
}


void displayMenu(int selected) {
	const string options[] = { "NEW GAME", "HELP","ABOUT","LOAD GAME","SETTING","EXIT" };
	const int numOptions = sizeof(options) / sizeof(options[0]);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	
	for (int i = 0; i < numOptions; i++) {

		if (i == selected) {
			// Mục đang chọn với màu chữ đỏ
			SetConsoleOutputCP(CP_UTF8);

			if (options[i] == "NEW GAME") {
				SetConsoleTextAttribute(hConsole, (1 << 4) | 10);
				GotoXY(51, 9); cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 9); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10); 
				GotoXY(50, 10); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 0); 
				GotoXY(55, 10); cout << options[i];
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10); 
				GotoXY(63, 10); cout << u8"      █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(70, 10); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);
				GotoXY(46, 11); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 11); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);


			}
			else if (options[i] == "HELP") {
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);
				GotoXY(46, 12); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 12); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
				GotoXY(50, 13); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
				GotoXY(55, 13); cout << options[i];
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
				GotoXY(59, 13); cout << u8"          █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(70, 13); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);
				GotoXY(46, 14); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 14); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
			}
			else if (options[i] == "ABOUT") {
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);
				GotoXY(46, 15); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 15); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);

				GotoXY(50, 16); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
				GotoXY(55, 16); cout << options[i];
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
				GotoXY(60, 16); cout << u8"         █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(70, 16); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);
				GotoXY(46, 17); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 17); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);

			}
			else if (options[i] == "LOAD GAME") {
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);
				GotoXY(46, 18); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 18); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);

				GotoXY(50, 19); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
				GotoXY(55, 19); cout << options[i];
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
				GotoXY(64, 19); cout << u8"     █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(70, 19); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);
				GotoXY(46, 20); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 20); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);


			}
			else if (options[i] == "SETTING") {
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);
				GotoXY(46, 21); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 21); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
				GotoXY(50, 22); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
				GotoXY(55, 22); cout << options[i];
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
				GotoXY(62, 22); cout << u8"       █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(70, 22); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);

				GotoXY(46, 23); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 23); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);

			}
			else if (options[i] == "EXIT") {
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);
				GotoXY(46, 24); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 24); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
				GotoXY(50, 25); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (10 << 4) | 0);
				GotoXY(55, 25); cout << options[i];
				SetConsoleTextAttribute(hConsole, (10 << 4) | 10);
				GotoXY(59, 25); cout << u8"          █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(70, 25); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 2);
				GotoXY(69, 26); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 10);

			}
		}
		else {
			// Mục không chọn với màu mặc định (trắng)
			// Màu mặc định
			if (options[i] == "NEW GAME") {
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
				GotoXY(46, 9); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 9); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);

				GotoXY(50, 10); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
				GotoXY(55, 10); cout << options[i];
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(63, 10); cout<< u8"      █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(70, 10); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
				GotoXY(46, 11); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 11); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
			}
			else if (options[i] == "HELP") {
				GotoXY(46, 12); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 12); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(50, 13); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
				GotoXY(55, 13); cout << options[i];
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(59, 13); cout<< u8"          █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(70, 13); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
				GotoXY(46, 14); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 14); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
			}
			else if (options[i] == "ABOUT") {
				GotoXY(46, 15); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 15); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(50, 16); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
				GotoXY(55, 16); cout << options[i];
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(60, 16); cout<< u8"         █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(70, 16); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
				GotoXY(46, 17); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 17); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
			}
			else if (options[i] == "LOAD GAME") {
				GotoXY(46, 18); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 18); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);

				GotoXY(50, 19); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
				GotoXY(55, 19); cout << options[i];
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(64, 19); cout<< u8"     █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(70, 19); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
				GotoXY(46, 20); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 20); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
			}
			else if (options[i] == "SETTING") {
				GotoXY(46, 21); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 21); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(50, 22); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
				GotoXY(55, 22); cout << options[i];
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(62, 22); cout<< u8"       █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(70, 22); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);

				GotoXY(46, 23); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 23); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
			}
			else if (options[i] == "EXIT") {
				GotoXY(46, 24); cout << u8"     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 24); cout << u8"▄";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(50, 25); cout << u8"█    ";
				SetConsoleTextAttribute(hConsole, (11 << 4) | 0);
				GotoXY(55, 25); cout << options[i];
				SetConsoleTextAttribute(hConsole, (11 << 4) | 11);
				GotoXY(59, 25); cout<< u8"          █" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(70, 25); cout << u8"█" << endl;
				SetConsoleTextAttribute(hConsole, (15 << 4) | 9);
				GotoXY(69, 26); 	cout << u8"▀";
				SetConsoleTextAttribute(hConsole, (15 << 4) | 11);
			}
		}
	}
	                                
	GotoXY(46, 26); 	cout << u8"     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";



	std::cout << endl;

	

}
