#include <iostream>
#include <Windows.h>
#include "Header.h"
#include "Draw.h"


using namespace std;




void Box1() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 6);
	SetConsoleOutputCP(CP_UTF8);
	//box p1
	GotoXY(LEFT + 70, TOP + 2);
	for (int i = 0;i < 20;i++) cout << u8"─";
	//cot doc trai
	GotoXY(LEFT + 69, TOP + 3);
	cout << u8"│ ";// cot giua
	GotoXY(LEFT + 69, TOP + 2);
	cout << u8"┌";
	GotoXY(LEFT + 69, TOP + 4);
	cout << u8"└";
	//cot doc phai
	GotoXY(LEFT + 90, TOP + 3);
	cout << u8"│ ";
	GotoXY(LEFT + 90, TOP + 2);
	cout << u8"┐";
	GotoXY(LEFT + 90, TOP + 4);
	cout << u8"┘";
	//duoi cung
	GotoXY(LEFT + 70, TOP + 4);
	for (int i = 0;i < 20;i++) cout << u8"─";
	//box p2
	GotoXY(LEFT + 70, TOP + 5);
	for (int i = 0;i < 20;i++) cout << u8"─";
	//cot doc trai
	GotoXY(LEFT + 69, TOP + 6);
	cout << u8"│";//cot giua
	GotoXY(LEFT + 69, TOP + 5);
	cout << u8"┌";
	GotoXY(LEFT + 69, TOP + 7);
	cout << u8"└";
	//cot doc phai
	GotoXY(LEFT + 90, TOP + 6);
	cout << u8"│";
	GotoXY(LEFT + 90, TOP + 5);
	cout << u8"┐";
	GotoXY(LEFT + 90, TOP + 7);
	cout << u8"┘";
	//duoi cung
	GotoXY(LEFT + 70, TOP + 7);
	for (int i = 0;i < 20;i++) cout << u8"─";
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 0);
	GotoXY(LEFT + 70, TOP + 6);
	cout << player2 << "(O)";
	GotoXY(LEFT + 70, TOP + 3);
	cout << player1 << "(X)";
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 1);
}


void Score2Player() {
	GotoXY(LEFT + 88, TOP + 3);
	cout << scoreP1;
	GotoXY(LEFT + 88, TOP + 6);
	cout << scoreP2;
}

void Box2() {
	SetConsoleOutputCP(CP_UTF8);
	SetColor(0, 15);
	//box p1
	GotoXY(LEFT + 70, TOP + 2 + 6);
	for (int i = 0;i < 45;i++) cout << u8"═";
	//cot doc trai
	for (int i = 0;i <= 6;i++) {
		GotoXY(LEFT + 69, TOP + 8);
		cout << u8"╔";
		GotoXY(LEFT + 115, TOP + 2 + 6);
		cout << u8"╗";
		GotoXY(LEFT + 69, TOP + 3 + i + 6);
		cout << u8"║ ";// cot giua
		GotoXY(LEFT + 115, TOP + 3 + i + 6);
		cout << u8"║ ";// cot giua
	}

	GotoXY(LEFT + 69, TOP + 14 + 1);
	cout << u8"╚";
	GotoXY(LEFT + 115, TOP + 14 + 1);
	cout << u8"╝";
	/*//cot doc phai
	GotoXY(LEFT + 115, TOP + 2 +6 );
	cout << u8"┐";
	*/
	//duoi cung
	GotoXY(LEFT + 70, TOP + 14 + 1);
	for (int i = 0;i < 45;i++) cout << u8"═";

}


void Box3() {
	SetConsoleOutputCP(CP_UTF8);
	//box p1
	SetColor(1, 15);
	GotoXY(LEFT + 70, TOP + 2 + 6 + 8);
	for (int i = 0;i < 35;i++) cout << u8"─";
	//cot doc trai
	for (int i = 0;i <= 5;i++) {
		GotoXY(LEFT + 69, TOP + 8 + 8);
		cout << u8"┌";
		GotoXY(LEFT + 105, TOP + 2 + 6 + 8);
		cout << u8"┐";
		GotoXY(LEFT + 69, TOP + 3 + i + 6 + 8);
		cout << u8"│ ";// cot giua
		GotoXY(LEFT + 105, TOP + 3 + i + 6 + 8);
		cout << u8"│ ";// cot giua
	}
	GotoXY(LEFT + 69, TOP + 14 + 8 + 1);
	cout << u8"└";
	//cot doc phai

	GotoXY(LEFT + 105, TOP + 14 + 8 + 1);
	cout << u8"┘";
	//duoi cung
	GotoXY(LEFT + 70, TOP + 14 + 8 + 1);
	for (int i = 0;i < 35;i++) cout << u8"─";
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 4);

	GotoXY(LEFT + 70, TOP + 17);//nhap noi dung
	cout << " --HOW TO PLAY-- ";
	GotoXY(LEFT + 70, TOP + 18);
	cout << "RIGHT: D | LEFT: A ";
	GotoXY(LEFT + 70, TOP + 19);
	cout << "UP:    W | DOWN: S ";
	GotoXY(LEFT + 70, TOP + 20);
	cout << "QUIT: ESC| SAVE: L";
	GotoXY(LEFT + 70, TOP + 21);
	cout << "CHOOSE:ENTER";
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 1);
	for (int i = 0;i < 6;i++) {
		GotoXY(LEFT + 88, TOP + 16);
		cout << u8"┬";
		GotoXY(LEFT + 88, TOP + 17 + i);
		cout << u8"│";
		GotoXY(LEFT + 88, TOP + 17 + 6);
		cout << u8"┴";
	}

}

void Box4() {
	SetColor(0, 15);
	GotoXY(40, 8);
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(40, 9);
	cout << u8R"(║    NHAP Y/N DE (TIEP TUC)/(DUNG LAI)    ║)";
	GotoXY(40, 10);
	cout << u8R"(╚═════════════════════════════════════════╝)";
}

void Box_Error_MaxSave() {
	SetColor(4, 15);
	GotoXY(40, 8);
	cout << u8R"(╔═════════════════════════════════════════════════════════════╗)";
	GotoXY(40, 9);
	cout << u8R"(║ Save limit reached. You cannot create any more save files!  ║)";
	GotoXY(40, 10);
	cout << u8R"(╚═════════════════════════════════════════════════════════════╝)";
	GotoXY(55, 11);SetColor(4, 14);cout << "--Press (K) to delete file--";SetColor(0, 15);
}


void Box6() {
	SetColor(0, 15);
	GotoXY(30, 8);
	cout << u8R"(╔═════════════════════════════════════════════════════════════╗)";
	GotoXY(30, 9);
	cout << u8R"(║ Nhap ten file de luu game:                                   )";
	GotoXY(92, 9);
	cout << u8"║";
	GotoXY(30, 10);
	cout << u8R"(╚═════════════════════════════════════════════════════════════╝)";
	GotoXY(34, 11);SetColor(4, 14);cout << "--Please name the file with fewer than 8 characters.--";SetColor(0, 15);
	GotoXY(58, 9);
	
}
void Box_Error_Name() {
	SetColor(4, 15);
	GotoXY(40, 12);
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(40, 13);
	cout << u8R"(║  FILE NAME MUST BE UNDER 8 CHARACTERS.  ║)";
	GotoXY(40, 14);
	cout << u8R"(╚═════════════════════════════════════════╝)";
}
void Box_Save_Complete() {
	SetColor(2, 15);
	GotoXY(40, 12);
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(40, 13);
	cout << u8R"(║         FILE SAVED SUCCESSFULLY!!       ║)";
	GotoXY(40, 14);
	cout << u8R"(╚═════════════════════════════════════════╝)";
}

void Box_Error_SetName(int x,int y) {
	SetColor(4, 15);
	GotoXY(x, y+1);
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(x, y+2);
	cout << u8R"(║   NICKNAME MUST BE UNDER 8 CHARTACTERS  ║)";
	GotoXY(x, y+3);
	cout << u8R"(╚═════════════════════════════════════════╝)";
	SetColor(0, 15);
}
void Box_Error_Duplicate_SetName() {
	SetColor(4, 15);
	GotoXY(40, 15);
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(40, 16);
	cout << u8R"(║         THE NAME ALREADY EXISTS         ║)";
	GotoXY(40, 17);
	cout << u8R"(╚═════════════════════════════════════════╝)";
	SetColor(0, 15);
}

void Box_TimeCountdown_End() {
	SetColor(4, 15);
	GotoXY(40, 15);
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(40, 16);
	cout << u8R"(║              TIME IS UP!!!!!            ║)";
	GotoXY(40, 17);
	cout << u8R"(╚═════════════════════════════════════════╝)";
	SetColor(0, 15);
}
void Box_Error_Empty_File() {
	SetColor(4, 15);
	GotoXY(41, 16);
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(41, 17);
	cout << u8R"(║              FILE NOT FOUND             ║)";
	GotoXY(41, 18);
	cout << u8R"(╚═════════════════════════════════════════╝)";
	SetColor(0, 15);
}
void Box_Error_Duplicate_file() {
	SetColor(4, 15);
	GotoXY(40, 12);
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(40, 13);
	cout << u8R"(║         FILE NAME ALREADY EXISTS        ║)";
	GotoXY(40, 14);
	cout << u8R"(╚═════════════════════════════════════════╝)";
	SetColor(0, 15);
}



