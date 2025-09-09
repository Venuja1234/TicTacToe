#include <stdio.h>
#include <stdlib.h>


char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void drawboard() {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("---|---|---\n");
        }
    }
}

int checkwin() {
   
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        return 1;
    }

   
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'x' && board[i][j] != 'o') {
                count++;
            }
        }
    }
    if (count == 0) return 2;

    return 0;
}

int main() {
    int row, column, move, gamestatus;
    int player = 1;

    while (1) {
        system("clear");
        drawboard();

        player = (player % 2) ? 1 : 2;
        printf("Player %d move (1-9): ", player);
        scanf("%d", &move);

       
        if (move < 1 || move > 9) {
            printf("Invalid input! Please enter 1-9.\n");
            player--;
            continue;
        }

        row = (move - 1) / 3;
        column = (move - 1) % 3;

        if (board[row][column] != 'x' && board[row][column] != 'o') {
            board[row][column] = (player == 1) ? 'x' : 'o';
        } else {
            printf("Warning! Cell already taken.\n");
            player--;
        }
 
        gamestatus = checkwin();
        if (gamestatus == 1) {
            system("clear");
            drawboard();
            printf("Player %d Wins!\n", player);
            break;
        } else if (gamestatus == 2) {
            system("clear");
            drawboard();
            printf("Match Draw! Try again.\n");
            break;
        }
        player++;
    }
    return 0;
}
