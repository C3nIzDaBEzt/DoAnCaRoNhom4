
#include "Save.h"
#include <Windows.h>
#include<iostream>
#include<string>
#include <vector> 
#include<fstream>
#include "Header.h"
#include"Sound.h"
#include <conio.h>
#include "Draw.h"

#include <sys/stat.h>
#ifdef _WIN32
#include <direct.h>  // Thư viện cho Windows
#define CreateDir _mkdir  // Đổi tên cho hàm Windows

using namespace std;

#else
#endif

string getInputWithEscCheck_Save() {
	string input = "";
	char ch;

	while (true) {
		// Kiểm tra nếu có phím nhấn
		if (_kbhit()) {
			ch = _getch(); // Lấy ký tự nhập vào

			if (ch == 27) { // Kiểm tra nếu là phím Esc
				RecoveryBoard();
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
bool isFileNameDuplicate(const string& fileName, const vector<string>& existingFiles) {
	for (const auto& file : existingFiles) {
		if (fileName == file) {
			return true;
		}
	}
	return false;
}
void SaveGameWithFileName() {
	// Đếm số lượng file .txt trong thư mục Saves
	system("dir /b Saves\\*.txt > file_count.txt");  // Lưu danh sách file vào file_count.txt
	ifstream countFile("file_count.txt");
	vector<string> existingFiles;
	string temp;
	while (getline(countFile, temp)) {
		existingFiles.push_back(temp);
	}
	countFile.close();
	remove("file_count.txt");  // Xóa file tạm sau khi sử dụng

	// Kiểm tra nếu số lượng file đạt giới hạn 8
	if (existingFiles.size() >= 9) {
		error();
		int countError = 3;
		do {
			Box_Error_MaxSave(); // Hiển thị lỗi quá số lượng file
			Sleep(500);
			GotoXY(42, 9);
			std::cout << "                                                          ";
			Sleep(500);

			countError--;
		} while (countError > 0);
		Box_Error_MaxSave();
		char key = _getch();

		if (key == 'k') {
			xoagame();
		}
		RecoveryBoard();
		int countX, countO;
		countXO(countX, countO);
		_TURN = (countX <= countO); // Nếu số lượng X <= O, thì lượt chơi là của X
		if (_TURN == 1) DrawX(89 + 2, 17);
		else DrawO(89 + 2, 17);
		GotoXY(_X, _Y);
		return;
	}

	string fileName;

	GotoXY(LEFT + 20, TOP + 2 * BOARD_SIZE + 2);
	Box6();

	bool validInput = true;
	while (validInput) { // Chặn nhập vượt quá giới hạn và trùng tên
		fileName = getInputWithEscCheck_Save();
		if (fileName.length() > 8) {
			error();
			// Thông báo lỗi
			GotoXY(LEFT, TOP + 2 * BOARD_SIZE + 3);
			int countError = 3;
			do {
				Box_Error_Name(); // Hiển thị lỗi quá dài
				Sleep(500);
				GotoXY(41, 13);
				cout << "                                        ";
				Sleep(200);
				countError--;
			} while (countError > 0);
			Box_Error_Name();
			system("cls");
			RecoveryBoard();
			Box6();
			GotoXY(58, 9);
			cout << "                                  "; // Che tên cũ
			GotoXY(58, 9);
		}
		else if (isFileNameDuplicate(fileName + ".txt", existingFiles)) {
			error();
			int countError = 3;
			do {
				Box_Error_Duplicate_file();
				Sleep(500);
				GotoXY(41, 13);
				cout << "                                        ";
				Sleep(200);
				countError--;
			} while (countError > 0);
			RecoveryBoard();
			Box6();
			GotoXY(58, 9); // Xóa tên cũ
			cout << "                                  ";
			GotoXY(58, 9);
		}
		else {
			validInput = false;
		}
	}

	if (!fileName.empty()) {
		fileName += ".txt"; // Thêm phần mở rộng cho file

		// Thêm đường dẫn vào thư mục "Saves"
		string filePath = "Saves/" + fileName;

		// Mở file để lưu vào đường dẫn
		ofstream saveFile(filePath.c_str());

		if (!saveFile) {
			error();
			cout << "ERROR, khong the tao file luu game" << endl;
			return;
		}

		// Lưu trạng thái bàn cờ
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				saveFile << _A[i][j].c << " "; // Lưu giá trị của từng ô cờ
			}
			saveFile << endl;
		}

		// Lưu lượt chơi hiện tại
		saveFile << (_TURN ? 1 : 0) << endl;

		// Lưu vị trí con trỏ hiện tại
		saveFile << _X << " " << _Y << endl;
		saveFile << scoreP1 << " " << scoreP2 << endl; // Lưu điểm số của người chơi 1 và 2
		saveFile.close();

		Box_Save_Complete();
		Sleep(1000);
		RecoveryBoard();
	}
}
void showSavedFiles(vector<string>& savedFiles) {
	// Chạy lệnh dir và ghi đầu ra vào file temp.txt
	system("dir Saves > temp.txt");

	ifstream file("temp.txt");
	string line;

	// Đọc từng dòng trong file temp.txt
	while (getline(file, line)) {
		// Kiểm tra xem dòng có chứa .txt hay không và lưu vào vector
		if (line.find(".txt") != string::npos) {
			// Cắt tên file từ dòng
			size_t pos = line.find_last_of(" ");
			savedFiles.push_back(line.substr(pos + 1)); // Lưu tên file vào vector
		}
	}

	file.close();
	remove("temp.txt");  // Xóa file tạm sau khi sử dụng
}

void CreateSaveDirectory() {
	int result = CreateDir("Saves");

	if (result == 0) {
		cout << "Created directory 'Saves'." << endl;
	}
	else if (errno == EEXIST) {
		cout << "'Saves' directory already exists." << endl;

	}
	else {
		cout << "Error creating 'Saves' directory." << endl;
	}
}

void SaveToFile(const string& filename, const string& content) {

	string filepath = "Saves/" + filename;  // Lưu vào thư mục Saves
	ofstream file(filepath);

	if (file.is_open()) {
		file << content;
		file.close();
		cout << "File saved to: " << filepath << endl;
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
}

int checkWinCondition() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j <= BOARD_SIZE - 5; j++) {
			// Kiểm tra chuỗi 5 ký tự liên tiếp của X
			if (_A[i][j].c == -1 && _A[i][j + 1].c == -1 && _A[i][j + 2].c == -1 &&
				_A[i][j + 3].c == -1 && _A[i][j + 4].c == -1) {

				// Đặt màu cho chuỗi chiến thắng của X
				for (int k = 0; k < 5; k++) {
					GotoXY(5 + (j + k) * 5, 2 + i * 2); // Tọa độ X thay đổi theo cột, Y giữ nguyên theo hàng
					SetColor(4, 14);
					cout << " X ";
				}
				return -1; // X thắng
			}
			// Kiểm tra chuỗi 5 ký tự liên tiếp của O
			if (_A[i][j].c == 1 && _A[i][j + 1].c == 1 && _A[i][j + 2].c == 1 &&
				_A[i][j + 3].c == 1 && _A[i][j + 4].c == 1) {

				// Đặt màu cho chuỗi chiến thắng của O
				for (int k = 0; k < 5; k++) {
					GotoXY(5 + (j + k) * 5, 2 + i * 2);
					SetColor(0, 14);
					cout << " O ";
				}
				return 1; // O thắng
			}
		}
	}

	// Kiểm tra cột
	for (int j = 0; j < BOARD_SIZE; j++) {
		for (int i = 0; i <= BOARD_SIZE - 5; i++) {
			// Kiểm tra chuỗi 5 ký tự liên tiếp của X
			if (_A[i][j].c == -1 && _A[i + 1][j].c == -1 && _A[i + 2][j].c == -1 &&
				_A[i + 3][j].c == -1 && _A[i + 4][j].c == -1) {

				// Đặt màu cho chuỗi chiến thắng của X
				for (int k = 0; k < 5; k++) {
					GotoXY(5 + j * 5, 2 + (i + k) * 2); // Tọa độ X giữ nguyên theo cột, Y thay đổi theo hàng
					SetColor(4, 14);
					cout << " X ";
				}
				return -1; // X thắng
			}
			// Kiểm tra chuỗi 5 ký tự liên tiếp của O
			if (_A[i][j].c == 1 && _A[i + 1][j].c == 1 && _A[i + 2][j].c == 1 &&
				_A[i + 3][j].c == 1 && _A[i + 4][j].c == 1) {

				// Đặt màu cho chuỗi chiến thắng của O
				for (int k = 0; k < 5; k++) {
					GotoXY(5 + j * 5, 2 + (i + k) * 2);
					SetColor(0, 14);
					cout << " O ";
				}
				return 1; // O thắng
			}
		}
	}

	// Kiểm tra đường chéo chính
	for (int i = 0; i <= BOARD_SIZE - 5; i++) {
		for (int j = 0; j <= BOARD_SIZE - 5; j++) {
			// Kiểm tra chuỗi 5 ký tự liên tiếp của X
			if (_A[i][j].c == -1 && _A[i + 1][j + 1].c == -1 && _A[i + 2][j + 2].c == -1 &&
				_A[i + 3][j + 3].c == -1 && _A[i + 4][j + 4].c == -1) {

				// Đặt màu cho chuỗi chiến thắng của X
				for (int k = 0; k < 5; k++) {
					GotoXY(5 + (j + k) * 5, 2 + (i + k) * 2); // X và Y đều tăng
					SetColor(4, 14);
					cout << " X ";
				}
				return -1; // X thắng
			}
			// Kiểm tra chuỗi 5 ký tự liên tiếp của O
			if (_A[i][j].c == 1 && _A[i + 1][j + 1].c == 1 && _A[i + 2][j + 2].c == 1 &&
				_A[i + 3][j + 3].c == 1 && _A[i + 4][j + 4].c == 1) {

				// Đặt màu cho chuỗi chiến thắng của O
				for (int k = 0; k < 5; k++) {
					GotoXY(5 + (j + k) * 5, 2 + (i + k) * 2);
					SetColor(0, 14);
					cout << " O ";
				}
				return 1; // O thắng
			}
		}
	}

	// Kiểm tra đường chéo phụ
	for (int i = 0; i <= BOARD_SIZE - 5; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			// Kiểm tra chuỗi 5 ký tự liên tiếp của X
			if (_A[i][j].c == -1 && _A[i + 1][j - 1].c == -1 && _A[i + 2][j - 2].c == -1 &&
				_A[i + 3][j - 3].c == -1 && _A[i + 4][j - 4].c == -1) {

				// Đặt màu cho chuỗi chiến thắng của X
				for (int k = 0; k < 5; k++) {
					GotoXY(5 + (j - k) * 5, 2 + (i + k) * 2); // X giảm, Y tăng
					SetColor(4, 14);
					cout << " X ";
				}
				return -1; // X thắng
			}
			// Kiểm tra chuỗi 5 ký tự liên tiếp của O
			if (_A[i][j].c == 1 && _A[i + 1][j - 1].c == 1 && _A[i + 2][j - 2].c == 1 &&
				_A[i + 3][j - 3].c == 1 && _A[i + 4][j - 4].c == 1) {

				// Đặt màu cho chuỗi chiến thắng của O
				for (int k = 0; k < 5; k++) {
					GotoXY(5 + (j - k) * 5, 2 + (i + k) * 2);
					SetColor(0, 14);
					cout << " O ";
				}
				return 1; // O thắng
			}
		}
	}
	// Kiểm tra hòa
	int countX = 0, countO = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].c == 1) countO++;
			else if (_A[i][j].c == -1) countX++;
		}
	}

	// Nếu bàn cờ đầy mà không có ai thắng, trả về 2 (hòa)
	if (countX + countO == BOARD_SIZE * BOARD_SIZE) {
		return 2;
	}
	return 0; // Không có ai thắng
}

void countXO(int& countX, int& countO) {
	countX = 0;
	countO = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].c == 1) {
				countO++; // Đếm O
			}
			else if (_A[i][j].c == -1) {
				countX++; // Đếm X
			}
		}
	}
}



void restartGame() {
	_POINT pc;
	SetConsoleOutputCP(1251);
	cout << "Bat dau tro choi...\n";

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | (15 << 4));

	FixConsoleWindow();

	int a, b;
	bool ValidEnter = true;

	reStartGame();
	Box1();
	Box2();
	Box3();
	Score2Player();
	pc.x = 0;
	pc.y = 0;
	GotoXY(LEFT + 2, TOP + 1); // Đưa con trỏ về ô đầu tiên
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
	resetData();

	// Đếm X và O để xác định lượt chơi tiếp theo
	int countX, countO;
	countXO(countX, countO);
	_TURN = (countX <= countO); // Nếu số lượng X <= O, thì lượt chơi là của X
	if (_TURN == 1) DrawX(89 + 2, 17);
	else DrawO(89 + 2, 17);
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27 || _COMMAND == 'q' || _COMMAND == 'Q') { // Nếu người chơi bấm Esc
			Sleep(500);
			//system("pause");
			Sleep(500);scoreP1 = 0;
			scoreP2 = 0;
			system("cls");
			click();
			mainmenu();

			return;
		}
		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 'L') {
				click();
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo(hStdOut, &csbi);
				int bottomRow = csbi.srWindow.Bottom;  // Lấy hàng cuối cùng của cửa sổ console
				GotoXY(0, bottomRow);
				SaveGameWithFileName();  // Gọi hàm để lưu game với tên file người chơi nhập
			}
			else if (_COMMAND == 13) {
				// Nếu người chơi bấm Enter
				switch (CheckBoard(_X, _Y)) {
				case -1:
					step();
					_B[_X][_Y] = -1;
					SetConsoleTextAttribute(hStdOut, 12 | (7 << 4));
					cout << "X";
					if (pc.x != 0 && pc.y != 0) {
						if ((_B[_X][_Y]) == 1) {
							GotoXY(pc.x, pc.y);
							SetColor(12, 15);
							cout << "X";
						}
						if ((_B[_X][_Y]) == -1) {
							GotoXY(pc.x, pc.y);
							SetColor(0, 15);
							cout << "O";

						}

					}
					pc.x = _X;
					pc.y = _Y;
					DrawO(89 + 2, 17);SetConsoleTextAttribute(hStdOut, 0 | (15 << 4));


					break;
				case 1:
					stepO();
					_B[_X][_Y] = 1;
					SetConsoleTextAttribute(hStdOut, 0 | (7 << 4));
					cout << "O";

					if (pc.x != 0 && pc.y != 0) {
						if ((_B[_X][_Y]) == 1) {
							GotoXY(pc.x, pc.y);
							SetColor(12, 15);
							cout << "X";
						}
						if ((_B[_X][_Y]) == -1) {
							GotoXY(pc.x, pc.y);
							SetColor(0, 15);
							cout << "O";

						}
					}
					pc.x = _X;
					pc.y = _Y;
					DrawX(89 + 2, 17);SetConsoleTextAttribute(hStdOut, 1 | (15 << 4));
					break;
				case 0: // Nếu ô trống
					ValidEnter = false; // Không làm gì, ô đã có X hoặc O
				}
				if (ValidEnter == true) {
					int winStatus = checkWinCondition(); // Hàm kiểm tra thắng
					if (winStatus != 0)
					{
						victory();
						if (winStatus == -1) {
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

						}
						else if (winStatus == 1)
						{
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

						}
						else if (winStatus == 2)
						{
							int demnguoc = 7;
							while (demnguoc > 0) {

								DrawTIE();
								Sleep(150);
								DrawBlank();
								Sleep(150);

								DrawTIE();

								demnguoc--;

							}
						}
						if (AskContinue() == 'N' || AskContinue() == 27) {
							//system("pause");
							Sleep(500);
							ResetKetqua(_B);
							system("cls");
							mainmenu();
							return;
						}
						else {
							ResetKetqua(_B);
							startGame(); // Khởi động lại trò chơi
						}
					}

					switch (ProcessFinish(TestBoard())) {
					case -1:
					case 1:
					case 0:
						SetConsoleOutputCP(CP_UTF8);



						if (AskContinue() == 'N' || AskContinue() == 27) {
							//system("pause");
							Sleep(500);
							ResetKetqua(_B);
							system("cls");
							mainmenu();
							return;
						}
						else {
							ResetKetqua(_B);
							startGame(); // Khởi động lại trò chơi
						}
					}
				}
				ValidEnter = true; // Reset biến ValidEnter cho lượt tiếp theo
			}
		}
	}
}

void reStartGame() {
	system("cls");
	DrawBoard(BOARD_SIZE);

}


void resetData() {
	for (int i = 0;i < BOARD_SIZE;i++) {
		for (int j = 0;j < BOARD_SIZE;j++) {
			_A[i][j].x = 5 * j + LEFT + 2;
			_A[i][j].y = 2 * i + TOP + 1;

		}
	}
	_TURN = true;_COMMAND = -1;
	_X = _A[0][0].x;_Y = _A[0][0].y;
}

//final
void showloadgame()
{
	clearScreen();
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true) {
		// Xóa màn hình và đặt màu sắc cho phần nền
		clearScreen();
		DrawBG_Tim();
		drawLoadGame(20, 1);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

		GotoXY(40, 12); cout << u8"┌────────────────────────────────────────────┐" << "\n";
		GotoXY(40, 13); cout << u8"│            DANH SACH FILE SAVE             │" << "\n";
		GotoXY(40, 14); cout << u8"│                                            │" << "\n";

		vector<string> savedFiles;
		showSavedFiles(savedFiles);

		int selectedFileIndex = 0;
		int selectingFile = 0;

		// Số lượng tối đa của file trong bảng
		const int maxFiles = 8;
		// Chỉ số dòng bắt đầu cho các file
		int fileStartRow = 15;

		while (true) {
			// Xóa màn hình nếu người dùng di chuyển
			if (selectingFile) {
				clearScreen();
				// Vẽ lại nền mỗi lần sau khi người dùng di chuyển lựa chọn
				DrawBG_Tim();
				drawLoadGame(20, 1);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

			}
			GotoXY(40, 12); cout << u8"┌────────────────────────────────────────────┐" << "\n";
			GotoXY(40, 13); cout << u8"│            DANH SACH FILE SAVE             │" << "\n";
			GotoXY(40, 14); cout << u8"│                                            │" << "\n";
			// Vẽ bảng file và danh sách các file
			for (int i = 0; i < maxFiles; i++) {
				// Đảm bảo không vẽ quá số lượng file có sẵn
				string formattedFileName = (i < savedFiles.size()) ? savedFiles[i] : "";
				if (formattedFileName.length() > 40) {
					formattedFileName = formattedFileName.substr(0, 37) + "...";
				}

				// Đánh dấu file đang chọn
				if (i == selectedFileIndex) {
					GotoXY(40, fileStartRow + i);
					cout << u8"│ > " << formattedFileName
						<< std::string(38 - formattedFileName.length(), ' ') << u8"   │" << "\n";
				}
				else {
					GotoXY(40, fileStartRow + i);
					cout << u8"│   " << formattedFileName
						<< std::string(40 - formattedFileName.length(), ' ') << u8" │" << "\n";
				}
			}

			// Hiển thị bảng đóng lại
			GotoXY(40, fileStartRow + maxFiles);
			cout << u8"└────────────────────────────────────────────┘" << "\n";
			GotoXY(36, fileStartRow + maxFiles + 1);
			cout << "Ban co muon Load File khong? (Y/N) hoac xoa file? (D) ";
			char choice = _getch();

			// Xử lý lựa chọn của người dùng
			if (choice == 'n' || choice == 'N') {
				click();
				return;
			}
			else if (choice == 'q' || choice == 'Q') {
				click();
				return;
			}
			else if (choice == 'd' || choice == 'D') {
				click();
				if (savedFiles.empty()) {
					int countError = 3;
					error();
					do {
						Box_Error_Empty_File();
						Sleep(500);
						GotoXY(50, 17); cout << "                      ";
						Sleep(200);
						countError--;
					} while (countError > 0);
					selectingFile = 0;
				}
				else {
					selectingFile = -1;
				}
			}
			else if (selectingFile == -1) {
				if (choice == 'w' || choice == 'W') {
					click();
					if (selectedFileIndex > 0) selectedFileIndex--; // Di chuyển lên
				}
				else if (choice == 's' || choice == 'S') {
					click();
					if (selectedFileIndex < savedFiles.size() - 1) selectedFileIndex++; // Di chuyển xuống
				}
				else if (choice == '\r') {
					// Xóa file khi nhấn Enter
					string fileName = savedFiles[selectedFileIndex];
					deleteSavedFile(fileName);
					savedFiles.clear();
					showSavedFiles(savedFiles);
					selectedFileIndex = 0;
					selectingFile = 0;
				}
			}
			else if (choice == 'y' || choice == 'Y')
			{
				click();
				if (savedFiles.empty())
				{
					int countError = 3;
					error();
					do {
						Box_Error_Empty_File();
						Sleep(500);
						GotoXY(50, 17); cout << "                      ";
						Sleep(200);
						countError--;
					} while (countError > 0);
					selectingFile = 0;
				}
				else {
					selectingFile = 1;
				}
			}

			else if (selectingFile == 1) {
				if (choice == 'w' || choice == 'W') {
					click();
					if (selectedFileIndex > 0) selectedFileIndex--; // Di chuyển lên
				}
				else if (choice == 's' || choice == 'S') {
					click();
					if (selectedFileIndex < savedFiles.size() - 1) selectedFileIndex++; // Di chuyển xuống
				}
				else if (choice == '\r') { // Enter để load tệp
					click();
					string fileName = savedFiles[selectedFileIndex];
					string fullFileName = "Saves/" + fileName + ".txt";

					if (fileName.size() >= 4 && fileName.substr(fileName.size() - 4) == ".txt") {
						fullFileName = "Saves/" + fileName; // Nếu đã có ".txt" thì giữ nguyên
					}
					else {
						fullFileName = "Saves/" + fileName + ".txt"; // Nếu chưa có thì thêm ".txt"
					}

					ifstream loadFile(fullFileName.c_str());
					cout << "duong dan file load: " << fullFileName << endl;

					if (!loadFile.is_open()) {
						error();
						cout << "Loi: Khong the mo file save! Kiem tra lai ten file va thu muc 'Saves/'." << endl;
						return;
					}

					if (loadFile.peek() == ifstream::traits_type::eof()) {
						error();
						cout << "Loi: File save rong hoac khong dung dinh dang!" << endl;
						return;
					}

					for (int i = 0; i < BOARD_SIZE; i++) {
						for (int j = 0; j < BOARD_SIZE; j++) {
							loadFile >> _A[i][j].c;
						}
					}

					int turn;
					loadFile >> turn;
					_TURN = (turn == 1);

					loadFile >> _X >> _Y;
					loadFile >> scoreP1 >> scoreP2;
					loadFile.close();

					clearScreen();
					restartGame();
					GotoXY(_X, _Y);
					cout << "Game da duoc load thanh cong tu file: " << fullFileName << endl;
					break;
				}
			}
		}
	}
}

void LoadGameWithFileName() {
	clearScreen();  // Xóa màn hình trước khi tải game
	showloadgame();  // Hiện danh sách các file save

}

void deleteSavedFile(const string& fileName) {
	string filePath = "Saves/" + fileName; // Tạo đường dẫn đầy đủ đến tệp

	if (remove(filePath.c_str()) != 0) {
		perror("Loi khi xoa tep"); // Thông báo lỗi nếu không xóa được
	}
}
void xoagame()
{
	clearScreen();
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true)
	{
		clearScreen();
		DrawBG_Tim();
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		GotoXY(40, 12); cout << u8"┌────────────────────────────────────────────┐" << "\n";
		GotoXY(40, 13); cout << u8"│            DANH SACH FILE SAVE             │" << "\n";
		GotoXY(40, 14); cout << u8"│                                            │" << "\n";

		vector<string> savedFiles;
		showSavedFiles(savedFiles);

		int selectedFileIndex = 0;
		int selectingFile = 0;

		// Số lượng tối đa của file trong bảng
		const int maxFiles = 8;
		// Chỉ số dòng bắt đầu cho các file
		int fileStartRow = 15;

		while (true) {
			// Xóa màn hình nếu người dùng di chuyển
			if (selectingFile) {
				clearScreen();
				// Vẽ lại nền mỗi lần sau khi người dùng di chuyển lựa chọn
				DrawBG_Tim();
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

			}
			GotoXY(40, 12); cout << u8"┌────────────────────────────────────────────┐" << "\n";
			GotoXY(40, 13); cout << u8"│            DANH SACH FILE SAVE             │" << "\n";
			GotoXY(40, 14); cout << u8"│                                            │" << "\n";
			// Vẽ bảng file và danh sách các file
			for (int i = 0; i < maxFiles; i++) {
				// Đảm bảo không vẽ quá số lượng file có sẵn
				string formattedFileName = (i < savedFiles.size()) ? savedFiles[i] : "";
				if (formattedFileName.length() > 40) {
					formattedFileName = formattedFileName.substr(0, 37) + "...";
				}

				// Đánh dấu file đang chọn
				if (i == selectedFileIndex) {
					GotoXY(40, fileStartRow + i);
					cout << u8"│ > " << formattedFileName
						<< std::string(38 - formattedFileName.length(), ' ') << u8"   │" << "\n";
				}
				else {
					GotoXY(40, fileStartRow + i);
					cout << u8"│   " << formattedFileName
						<< std::string(40 - formattedFileName.length(), ' ') << u8" │" << "\n";
				}
			}

			// Hiển thị bảng đóng lại
			GotoXY(40, fileStartRow + maxFiles);
			cout << u8"└────────────────────────────────────────────┘" << "\n";
			GotoXY(46, fileStartRow + maxFiles + 1);
			cout << "Ban co muon xoa File khong? (D) ";
			char choice = _getch();

			if (choice == 'n' || choice == 'N') {
				click();
				return;
			}
			else if (choice == 'q' || choice == 'Q') {
				click();
				return;
			}
			else if (choice == 'd' || choice == 'D') {
				click();
				if (savedFiles.empty()) {
					int countError = 3;
					error();
					do {
						Box_Error_Empty_File();
						Sleep(500);
						GotoXY(50, 17); cout << "                      ";
						Sleep(200);
						countError--;
					} while (countError > 0);
					selectingFile = 0;
				}
				else {
					selectingFile = -1;
				}
			}

			else if (selectingFile == -1)
			{
				if (choice == 'w' || choice == 'W') {
					click();
					if (selectedFileIndex > 0) selectedFileIndex--; // Di chuyển lên
				}
				else if (choice == 's' || choice == 'S') {
					click();
					if (selectedFileIndex < savedFiles.size() - 1) selectedFileIndex++; // Di chuyển xuống
				}
				else if (choice == '\r') {

					string fileName = savedFiles[selectedFileIndex];
					deleteSavedFile(fileName);
					savedFiles.clear();
					showSavedFiles(savedFiles);
					selectedFileIndex = 0;
					selectingFile = 0;
				}
			}
		}
	}
}

