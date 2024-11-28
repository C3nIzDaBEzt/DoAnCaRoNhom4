#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include "header.h"
#include <mutex>

bool resetFlag;
bool countdownActive=true;
int kq;
int seconds=15;
using namespace std;



void TimerCountDown() {
    while (seconds >= 0 && countdownActive) {
        cout << "\033[H\n\n";
        cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "  ";
        cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << seconds;

        GotoXY(_X, _Y);
        this_thread::sleep_for(chrono::seconds(1));
        if (resetFlag) {
            seconds = 15; // Reset lại thời gian
            resetFlag = false; // Đặt lại cờ reset
        }
        if (seconds == 0) {
            if (_B[pastcoord.x / 5][pastcoord.y / 2] == 1) {
                kq = -1;
            }
            else if (_B[pastcoord.x / 5][pastcoord.y / 2] == -1) { kq = 1; }
            else kq = 0;
            int count = 3;
            while (count > 0) {
                Box_TimeCountdown_End();
                Sleep(500);
                GotoXY(45, 16);
                cout << "                         ";
                Sleep(500);
                count--;
            }
            RecoveryBoard();
            

           
        }
        seconds--;
    }
}

void CheckCountDown() {
    
}


