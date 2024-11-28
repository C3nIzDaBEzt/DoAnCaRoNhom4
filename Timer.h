#pragma once

#ifndef TIME_H
#define TIME_H


extern bool resetFlag ;
extern bool countdownActive;
extern int kq;
extern int seconds;

void TimerCountDown( );
void CheckCountDown();
#endif // !TIME_H
