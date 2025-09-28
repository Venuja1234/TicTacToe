#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <stdio.h>
#include <stdlib.h>
void displayingBoard(char** board, int n);
char** initializingBoard(int n);
void freeBoard(char** board, int n);
#endif

int checkWinCon(char** board, int n, char player) {
    // Check rows and columns
    for (int i = 0; i < n; i++) {
        int row_count = 0, col_count = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == player) row_count++;
            if (board[j][i] == player) col_count++;
        }
        if (row_count == n || col_count == n) return 1;
    }
    
    // Check diagonals
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        if (board[i][i] == player) diag1++;
        if (board[i][n-1-i] == player) diag2++;
    }
    return (diag1 == n || diag2 == n) ? 1 : 0;
}
