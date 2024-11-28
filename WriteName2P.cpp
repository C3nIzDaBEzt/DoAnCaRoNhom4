#include "Header.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include "Draw.h"
#include <conio.h>
#include"Sound.h"


using namespace std;

string getInputWithEscCheck() {
	string input = "";
	char ch;

	while (true) {
		// Kiểm tra nếu có phím nhấn
		if (_kbhit()) {
			ch = _getch(); // Lấy ký tự nhập vào

			if (ch == 27) { // Kiểm tra nếu là phím Esc
				click();
				ExitGame();
				mainmenu();
				return ""; // Quay lại menu
			}
			else if (ch == '\r') { // Kiểm tra nếu là phím Enter
				cout << endl;
				break;
			}
			else if (ch == '\b') { // Xóa ký tự nếu nhấn phím Backspace
				if (!input.empty()) {
					cout << "\b \b"; // Xóa ký tự khỏi màn hình
					input.pop_back();
				}
			}
			else if (input.length() < 32) {
				cout << ch; // Hiển thị ký tự vừa nhập
				input += ch;
			}
		}
	}
	return input;
}

string player1, player2;
void InputPlayerNames() {
	
	int consoleWidth = GetConsoleWidth();
	int boxWidth = 41; // Chiều rộng của khung
	int centerX = (consoleWidth - boxWidth) / 2;
	SetName_View();
	bool validInput = false;
	while (!validInput) {
		GotoXY(3, 6);
		player1 = getInputWithEscCheck();
		if (player1.empty())  player1 = "Player 1";
		if (player1.length() > 10) {
			Sleep(200);
			int count = 3;
			while (count > 0) {
				Box_Error_SetName(2,8);
				Sleep(400);
				GotoXY(3, 10);
				cout << "                                       ";
				Sleep(400);
				count--;
			}
			SetName_View();
			GotoXY(3,7);
			validInput = false;
		}
		else validInput = true;
	}
	validInput = false;
	while (!validInput) {
		//DrawBG();
		GotoXY(76,6);
		player2 = getInputWithEscCheck(); // Sử dụng hàm để nhập tên Player 2
		
		if (player2.empty()) { // Nếu người dùng nhấn Esc
			player2 = "Player2"; // Đặt tên mặc định
			return; // Quay lại menu
		}

		if (player2.length() > 10) {
			Sleep(200);
			Box_Error_SetName(75,8);
			Sleep(800);
			SetName_View();
			GotoXY(4, 6);
			cout << player1;
			int count = 3;
			while (count > 0) {
				Box_Error_SetName(75,8);
				Sleep(400);
				GotoXY(76, 10);
				cout << "                                       ";
				Sleep(400);
				count--;
			}
			GotoXY(centerX + 5, 12); // Đưa con trỏ về vị trí nhập tên
			validInput = false;
		}
		else if (player1 == player2) {
			Sleep(200);
			Box_Error_Duplicate_SetName();
			Sleep(800);
			SetName_View();
			GotoXY(4, 6);
			cout << player1;
			int count = 3; 
			while (count > 0) {
				Box_Error_Duplicate_SetName();
				Sleep(400);
				GotoXY(43, 16);
				cout << "                                       ";
				Sleep(400);
				count--;
			}
			GotoXY(76,8); // Đưa con trỏ về vị trí nhập tên
			validInput = false;
		}
		else {
			validInput = true; // Thoát khỏi vòng lặp nếu nhập tên hợp lệ
		}
	}
}

void SetName_View() {
	system("cls");
	DrawBG();
	SetConsoleOutputCP(CP_UTF8);

	// Lấy chiều rộng của console
	int consoleWidth = GetConsoleWidth();
	int boxWidth = 41; // Chiều rộng của khung
	int centerX = (consoleWidth - boxWidth) / 2;

	// Hiển thị khung tiêu đề
	SetColor(12, 15);
	GotoXY(centerX, 1);
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(centerX, 2);
	cout << u8R"(║            ENTER NICKNAME               ║)";
	GotoXY(centerX, 3);
	cout << u8R"(╚═════════════════════════════════════════╝)";

	// Hiển thị và căn giữa phần nhập tên Player 1
	SetColor(0, 15);
	GotoXY(2, 4);
	cout << ">>Nhap ten player1";
	GotoXY(2, 5);
	cout << u8R"(┌─────────────────────────────────────────┐)";
	GotoXY(2, 6);
	cout << u8R"(│                                         │)";
	GotoXY(2, 7);
	cout << u8R"(└─────────────────────────────────────────┘)";


	// Hiển thị và căn giữa phần nhập tên Player 2
	GotoXY(75,4);
	cout << ">>Nhap ten player2";
	GotoXY(75, 5);
	cout << u8R"(┌─────────────────────────────────────────┐)";
	GotoXY(75, 6);
	cout << u8R"(│                                         │)";
	GotoXY(75, 7);
	cout << u8R"(└─────────────────────────────────────────┘)";
}