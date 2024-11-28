#pragma once
#include <string>
#include <vector>


#ifndef SAVE_H
#define SAVE_H

using namespace std;


void SaveToFile(const string& filename, const string& content);
void CreateSaveDirectory();
void SaveGameWithFileName();
void LoadGameWithFileName();
void showSavedFiles(vector<string>& savedFiles);
void restartGame();
void reStartGame();
void resetData();
void countXO(int& countX, int& countO);
void reStartGame();
int checkWinCondition();
void deleteSavedFile(const std::string& fileName);
void xoagame();
bool isFileNameDuplicate(const string& fileName, const vector<string>& existingFiles);


#endif