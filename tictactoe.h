#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char** initializingBoard(int n);
void freeBoard(char** board, int n);
void displayingBoard(char** board, int n);
int gettingUserInput(int* row, int* col, int n, char player);
int validatingMove(char** board, int row, int col, int n);
int makeMove(char** board, int row, int col, char player);
int checkWinCon(char** board, int n, char player);
int checkDrawCon(char** board, int n);
void logGameStatus(char** board, int n, const char* filename, int move_count);
void generatingComputerMove(char** board, int n, int* row, int* col);

#endif

