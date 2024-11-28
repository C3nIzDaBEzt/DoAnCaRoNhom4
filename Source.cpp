#pragma once
#include "header.h"
#include"Draw.h"
#include"Sound.h"
#include "Save.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include"Timer.h"
#include <iomanip>
#include <thread>//de chay timer


using namespace std;

#define BOARD_SIZE 12
#define LEFT 3
#define TOP 1

//menu
 _POINT pastcoord; // Định nghĩa biến
 _POINT _A[BOARD_SIZE + 1][BOARD_SIZE + 1];

 int _B[BOARD_SIZE + 1][BOARD_SIZE + 1];
 bool _TURN;
 int _COMMAND;
 int _X, _Y;
 int scoreP1 = 0;

 int scoreP2 = 0;
 bool InputActive = true;



int mainmenu()
{
	
	int choice = 0;
	char key;
	DrawBg_xp();
	
	
	drawcaro();
	GotoXY(0, 0);
	while (true) {
		
		
		displayMenu(choice);
		key = _getch(); // Nhận đầu vào từ bàn phím mà không cần nhấn Enter

		if (key == 'w' || key == 'W') {
			click();
			choice = (choice - 1 + 6) % 6; // Di chuyển lên
		}
		else if (key == 's' || key == 'S') {
			click();
			choice = (choice + 1) % 6; // Di chuyển xuống
		}
		else if (key == 13) {
			click();
			switch (choice) {
				//thuc hien hanh dong
			case 0:
				
				startGame();
				drawcaro();
				
				break;
			case 1:
				showInstructions();
				drawcaro();
				
				break;
			case 2:
				about();
				drawcaro();
				
				break;
			case 3:
				LoadGameWithFileName();
				drawcaro();
				
				break;
			case 4:
				Setting();
				drawcaro();
				
				break;
			case 5:
				system("cls");
				cout << "Cam on da choi! Tam biet!\n";
				ExitProcess(1);
				
				break;
			}
		}
	}
	return 0;
}

void DrawBoard(int pSize) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 1);
	SetConsoleOutputCP(CP_UTF8);
	for (int i = 0;i <= pSize - 1;i++) {
		for (int j = 0;j <= pSize - 1;j++) {
			GotoXY(LEFT, TOP + 2 * j);
			cout << u8"╠";

			//
			GotoXY(LEFT + 5 * i, TOP + 2 * j);
			cout << u8"╬════";
			GotoXY(LEFT + 5 * i, TOP);
			cout << u8"╦════";
			GotoXY(LEFT + 5 * i + 5, TOP + 2 * j);
			cout << u8"╣";
			GotoXY(LEFT + 5 * (i)+5, TOP + 2 * j + 1);
			cout << u8"║ ";
			GotoXY(LEFT + 5 * (i), TOP + 2 * j + 1);
			cout << u8"║ ";
			//dong cuoi
			GotoXY(LEFT + 5 * i, TOP + 2 * j + 2);
			cout << u8"╬════";
			GotoXY(LEFT + 5 * i + 5, TOP + 2 * j + 2);
			cout << u8"╣";
			GotoXY(LEFT + 5 * pSize, TOP);
			cout << u8"╗";
			GotoXY(LEFT + 5 * i, TOP + 2 * pSize);
			cout << u8"╩════";
			//goc tren
			GotoXY(LEFT, TOP);
			cout << u8"╔";
			//goc duoi
			GotoXY(LEFT + 5 * pSize, TOP + 2 * pSize);
			cout << u8"╝";
			GotoXY(LEFT, TOP + 2 * pSize);
			cout << u8"╚";

		}
	}
}

void clearScreen() {
	system("cls");
}
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 1);
}

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ResetKetqua(int a[BOARD_SIZE + 1][BOARD_SIZE + 1]) {
	for (int i = 0;i < BOARD_SIZE;i++) {
		for (int j = 0;j < BOARD_SIZE;j++) {
			a[1 + i ][2 + j] = 0;
		}
	}
}
void ResetData() {
	for (int i = 0;i < BOARD_SIZE;i++) {
		for (int j = 0;j < BOARD_SIZE;j++) {
			_A[i][j].x = 5 * j + LEFT + 2;
			_A[i][j].y = 2 * i + TOP + 1;
			_A[i][j].c = 0;
		}
	}
	_TURN = true;_COMMAND = -1;
	_X = _A[0][0].x;_Y = _A[0][0].y;
}


void StartGame() {
	ResetKetqua(_B);
	system("cls");
	
	system("cls");
	ResetData();
	DrawBoard(BOARD_SIZE);
	Score2Player();
	countdownActive = true;
}

void GabageCollect() {

}

void ExitGame() {
	system("cls");
	GabageCollect();
}

int ProcessFinish(int pWhoWin) {
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
	switch (pWhoWin) {
	case -1: {
		countdownActive = false;
		victory();
		scoreP1 += 1;
		int demnguoc = 7;
		while (demnguoc > 0) {
			DrawX(71, 9);
			DrawWIN();
			Sleep(150);
			DrawBlank();
			Sleep(150);
			DrawX(71, 9);
			DrawWIN();

			demnguoc--;

		}
		break;
	}
	case 1: {
		countdownActive = false;
		victory();
		scoreP2 += 1;
		int demnguoc = 7;
		while (demnguoc > 0) {
			DrawO(71, 9);
			DrawWIN();
			Sleep(150);
			DrawBlank();
			Sleep(150);
			DrawO(71, 9);
			DrawWIN();

			demnguoc--;

		}
		break;
	}
	case 0: {
		countdownActive = false;
		victory();
		int demnguoc = 7;
		while (demnguoc > 0) {

			DrawTIE();
			Sleep(150);
			DrawBlank();
			Sleep(150);

			DrawTIE();

			demnguoc--;

		}

		break;
	}
	case 2:
		_TURN = !_TURN;

	}
	GotoXY(_X, _Y);
	return pWhoWin;
}
int AskContinue() {
	Sleep(1000);
	GotoXY(15, _A[BOARD_SIZE][BOARD_SIZE - 1].y);
	Box4();
	return toupper(_getch());
}
int checkHoa(int a[BOARD_SIZE+1][BOARD_SIZE+1]) {
	int countSL = 0;
	for (int i = 0; i <= BOARD_SIZE; i++) {
		for (int j = 0; j <= BOARD_SIZE; j++) {
			if (a[1 + i ][ 1 +  j] == 1 || a[1 + i ][1+ j] == -1) {
				countSL += 1;
				GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 5);//test vitri
				if (countSL == BOARD_SIZE * BOARD_SIZE ) return 0;
			}
			else break;
		}
	}
	return 2;
}

int TestBoard() {
	int countX = 0;
	int countY = 0;
	int countOCC = 0;
	int countXCC = 0;
	int countCP = 0;
	int startXn = -1;//X bat dau khi xet ngang
	int startOn = -1;
	int startOt = -1;
	int startXt = -1;//X bat dau khi xet doc
	int startOcc = -1;
	int startXcc = -1;//X bat dau khi xet cheo chinh
	int startOcp = -1;
	int startXcp = -1;//X bat dau khi xet cheo phu
	if (checkHoa(_B) == 0) return 0;

	//cheo phu
	for (int i = 0;i <= 9;i++) {
		if (_B[_X / 5 + 4 - i][_Y / 2 - 4 + i] == -1) {
			if (countCP == 0) startXcp = i;
			countCP += 1;
			if (countCP == 5) {
				for (int j = 0;j < 5;j++) {
					GotoXY(_X + 20 - (startXcp + j) * 5, _Y - 8 + (startXcp + j) * 2);
					SetColor(4, 14);
					cout << " X ";

				}
				return -1;
			}
		}
		else { countCP = 0;startXcp = -1; }
	}
	for (int i = 0;i <= 9;i++) {
		if (_B[_X/5 + 4 - i][_Y/2 - 4 + i] == 1) {
			if (countCP == 0) startOcp = i;
			countCP += 1;
			if (countCP == 5) {
				for (int j = 0;j < 5;j++) {
					GotoXY(_X + 20 - (startOcp + j) * 5, _Y - 8 + (startOcp + j) * 2);
					SetColor(0, 14);
					cout << " 0 ";

				}
				return 1;
			}
		}
		else { countCP = 0;startOcp = -1; }
	}
	//cheo chinh
	for (int i = 0;i <= 9;i++) {
		if (_B[_X / 5 - 4 + i][_Y / 2 - 4 + i] == -1) {
			if (countXCC == 0) startXcc = i;
			countXCC += 1;
			if (countXCC == 5) {
				for (int j = 0;j < 5;j++) {
					GotoXY(_X - 20 + (startXcc + j) * 5, _Y - 8 + (startXcc + j) * 2);
					SetColor(4, 14);
					cout << " X ";

				}
				return -1;
			}
		}
		else {
			countXCC = 0;
			startXcc = -1;
		}
	}

	for (int i = 0;i <= 9;i++) {
		if (_B[_X / 5 - 4 + i][_Y / 2 - 4 + i] == 1) {
			if (countOCC == 0) startOcc = i;
			countOCC += 1;

			if (countOCC == 5) {
				for (int j = 0;j < 5;j++) {
					GotoXY(_X - 20 + (startOcc + j) * 5, _Y - 8 + (startOcc + j) * 2);
					SetColor(0, 14);
					cout << " O ";
				}
				return 1;
			}
		}
		else {
			countOCC = 0;startOcc = -1;
		}

	}
	//thang
	for (int i = 0;i <= 9;i++) {
		if (_B[_X/5][_Y/2-4+ i ] == -1) {
			if (countY == 0) {
				startXt = i;
			}
			countY += 1;
			
			if (countY == 5) {
				for (int j = 0;j < 5;j++) {
					GotoXY(_X, _Y - 8 + (startXt + j) * 2);
					SetColor(4, 14);
					cout << " X ";
				}
				return -1;
			}
		}
		else {
			startXt = -1;
			countY = 0;
		}

	}
	for (int i = 0;i <= 9;i++) {
		if (_B[_X / 5][_Y / 2 - 4 + i] == 1) {
			if (countX == 0) startOt = i;
			countX += 1;
			if (countX == 5) {
				for (int j = 0; j < 5; j++) {
					GotoXY(_X, _Y - 8 + (startOt + j) * 2);
					SetColor(0, 14);
					cout << " O ";
				}
				return 1;
			}
		}
		else {
			countX = 0;startOt = -1;
		}
	}


	//ngang
	for (int i = 0;i <= 9;i++) {
		if (_B[_X / 5 - 4 + i][_Y / 2] == -1) {
			if (countX == 0) startXn = i;
			countX += 1;
			if (countX == 5) {
				for (int j = 0; j < 5; j++) {
					GotoXY(_X - 20 + (startXn + j) * 5, _Y);
					SetColor(4, 14);
					cout << "X";
				}
				return -1;
			}
		}
		else {
			countX = 0;
			startXn = -1;
		}
	}

	for (int i = 0;i <= 9;i++) {
		if (_B[_X / 5 - 4 + i][_Y / 2] == 1) {
			if (countX == 0) startOn = i;
			countX += 1;
			if (countX == 5) {
				for (int j = 0; j < 5; j++) {
					GotoXY(_X - 20 + (startOn + j) * 5, _Y);
					SetColor(0, 14);
					cout << "O";
				}
				return 1;
			}
		}
		else {
			countX = 0;startOn = -1;
		}
	}
	return 2;

}

int CheckBoard(int pX, int pY) {
	for (int i = 0;i <= BOARD_SIZE;i++) {
		for (int j = 0;j <= BOARD_SIZE;j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) _A[i][j].c = -1;
				else _A[i][j].c = 1;
				return _A[i][j].c;
			}
		}
	}
	return 0;
}


void MoveRight() {
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
		_X += 5;
		GotoXY(_X, _Y);
	}
}

void MoveLeft() {
	if (_X > _A[0][0].x) {
		_X -= 5;
		GotoXY(_X, _Y);
	}
}

void MoveDown() {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
		_Y += 2;
		GotoXY(_X, _Y);
	}
}

void MoveUp() {
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}

int GetConsoleWidth() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int width = 80; // Đặt mặc định
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	}
	return width;
}




void startGame() {

	SetConsoleOutputCP(1251);


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | (15 << 4));

	FixConsoleWindow();
	if (InputActive = true) { InputPlayerNames(); }
	
	bool ValidEnter = true;
	seconds = 15;
	StartGame();

	Box1();
	Box2();
	Box3();
	DrawX(89 + 2, 17);
	Score2Player();
	GotoXY(LEFT + 2, TOP + 1);//dua con tro ve o dau tien
	pastcoord.x = 0;
	pastcoord.y = 0;
	
	
	while (1) {

		_COMMAND = toupper(_getch());
		if (_COMMAND == 27 || _COMMAND == 'Q') {
			countdownActive = false;
			int choice = 0;
			char key;
			bool running = true;
			while (running) {
				GotoXY(0, 17);
				displayMenu2(choice);
				key = _getch(); // Nhận đầu vào từ bàn phím mà không cần nhấn Enter

				if (key == 'w' || key == 'W') {
					choice = (choice - 1 + 3) % 3; // Di chuyển lên
				}
				else if (key == 's' || key == 'S') {
					choice = (choice + 1) % 3; // Di chuyển xuống
				}
				else if (key == 13) {


					if (choice == 2) {
						click();
						Sleep(500);
						scoreP1 = 0;
						scoreP2 = 0;

						ExitGame();
						mainmenu();

						ExitProcess(0);
						break;
					}
					else if (choice == 1) {

						toggleSFX();


						GotoXY(72, 4);

					}
					else break;


				}

			}RecoveryBoard();

		}

		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'L') {
				countdownActive = false;
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo(hStdOut, &csbi);
				int bottomRow = csbi.srWindow.Bottom;  // Get the bottom row of the current console window

				GotoXY(0, bottomRow);

				SaveGameWithFileName();  // Gọi hàm để lưu game với tên file người chơi nhập

			}
			else if (_COMMAND == 13) {
				resetFlag = true;
				switch (CheckBoard(_X, _Y)) {
				case -1:
					step();
					_B[_X / 5][_Y / 2] = -1;
					SetConsoleTextAttribute(hStdOut, 12 | (7 << 4));
					cout << "X";
					if (pastcoord.x != 0 && pastcoord.y != 0) {
						if ((_B[_X / 5][_Y / 2]) == 1) {
							GotoXY(pastcoord.x, pastcoord.y);
							SetColor(12, 15);
							cout << "X";
						}
						if ((_B[_X / 5][_Y / 2]) == -1) {
							GotoXY(pastcoord.x, pastcoord.y);
							SetColor(0, 15);
							cout << "O";

						}

					}
					pastcoord.x = _X;
					pastcoord.y = _Y;


					DrawO(89 + 2, 17);SetConsoleTextAttribute(hStdOut, 0 | (15 << 4));

					break;
				case 1:
					stepO();
					_B[_X / 5][_Y / 2] = 1;
					SetConsoleTextAttribute(hStdOut, 0 | (7 << 4));
					cout << "O";
					if (pastcoord.x != 0 && pastcoord.y != 0) {
						if ((_B[_X / 5][_Y / 2]) == 1) {
							GotoXY(pastcoord.x, pastcoord.y);
							SetColor(12, 15);
							cout << "X";
						}
						if ((_B[_X / 5][_Y / 2]) == -1) {
							GotoXY(pastcoord.x, pastcoord.y);
							SetColor(0, 15);
							cout << "O";

						}

					}
					pastcoord.x = _X;
					pastcoord.y = _Y;

					DrawX(89 + 2, 17);SetConsoleTextAttribute(hStdOut, 1 | (15 << 4));
					break;
				case 0:
					ValidEnter = false;
				}
				if (ValidEnter == true) {
					if (seconds > 0) {
						switch (ProcessFinish(TestBoard())) {
						case-1:
							countdownActive = false;
						case 1:
						case 0:
							if (toupper(AskContinue()) != 'Y' && toupper(AskContinue()) != 13 || AskContinue() == 27) {
								//system("pause");
								//Sleep(500);
								ResetKetqua(_B);
								system("cls");
								scoreP1 = 0;
								scoreP2 = 0;
								mainmenu();
								return;
							}
							else {
								countdownActive = true;
								ResetKetqua(_B);
								startGame();
							}
						}
					}




				}
				ValidEnter = true;
			}
		}if (seconds == 0) {
			HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
			DWORD prevMode;

			// Lấy chế độ hiện tại
			GetConsoleMode(hInput, &prevMode);

			// Tắt chế độ ENABLE_PROCESSED_INPUT để ngăn nhận phím Enter
			SetConsoleMode(hInput, prevMode & ~ENABLE_PROCESSED_INPUT);
		}
		
		if (seconds == 0) {
			if (pastcoord.x == 1) kq = -1;
			if (pastcoord.x == -1) kq = 1;
			if (pastcoord.x == 0) kq = 0;
			cout << "abc";
			switch (ProcessFinish(kq)) {
			case-1:
				cout << "1";
			case 1:
			case 0:
				if (toupper(AskContinue()) != 'Y' && toupper(AskContinue()) != 13 || AskContinue() == 27) {
					//system("pause");
					Sleep(500);
					ResetKetqua(_B);
					system("cls");
					scoreP1 = 0;
					scoreP2 = 0;
					mainmenu();
					return;
				}
				else {
					countdownActive = true;
					ResetKetqua(_B);
					startGame();
				}
			}
		}


	}
	
}


void RecoveryBoard() {
	system("cls");
	DrawBoard(BOARD_SIZE);
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].c == 1) {
				GotoXY((j + 1) * 5, (i + 1) * 2);
				SetColor(0, 15);
				cout << "O";
			}
			else if (_A[i][j].c == -1) {
				GotoXY((j + 1) * 5, (i + 1) * 2);
				SetColor(12, 15);
				cout << "X";
			}
		}
	}
	Box1();
	Box2();
	Box3();
	Score2Player();
	GotoXY(_X, _Y);
	countdownActive = true;

}

void displayMenu2(int selected) {
	const string options[] = { "Continue","SFX","Thoat"};
	const int numOptions = sizeof(options) / sizeof(options[0]);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (15 << 4) | 0);
	SetConsoleOutputCP(CP_UTF8);
	GotoXY(46, 10);
	cout << u8"┌────────────────────────┐" << endl;
	for (int i = 0; i < numOptions; i++) {

		if (i == selected) {
			// Mục đang chọn với màu chữ đỏ
			SetConsoleTextAttribute(hConsole, (15 << 4) | 5);
			SetConsoleOutputCP(CP_UTF8);

			if (options[i] == "Continue") {
				GotoXY(46, 11);
				cout << u8"│  >>  " << options[i];
				cout << u8"          │" << "\n";
			}
			if (options[i] == "SFX") {
				GotoXY(46, 12);
				cout << u8"│  >>  " << options[i];
				cout << setw(10) << (isSFXEnabled ? " (On)" : " (Off)") << u8"     │" << endl;
			}
			else if (options[i] == "Thoat") {
				GotoXY(46, 13);
				cout << u8"│  >>  " << options[i];
				cout << u8"             │" << "\n";
			}
		}
		else {
			// Mục không chọn với màu mặc định (trắng)
			SetConsoleTextAttribute(hConsole, (15 << 4) | 0);
			// Màu mặc định
			if (options[i] == "Continue") {
				GotoXY(46, 11);
				cout << u8"│      " << options[i];
				cout << u8"          │" << "\n";
			}
			else if(options[i] == "SFX") {
				GotoXY(46, 12);
				cout << u8"│      " << options[i];
				cout << setw(10) << (isSFXEnabled ? " (On)" : " (Off)") << u8"     │" << endl;
			}

			else if (options[i] == "Thoat") {
				GotoXY(46, 13);
				cout << u8"│      " << options[i];
				cout << u8"             │" << "\n";
			}
		}
	}
	GotoXY(46, 14);
	std::cout << u8"└────────────────────────┘" << endl;


	std::cout << endl;



}


