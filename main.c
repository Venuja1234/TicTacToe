#include "tictactoe.h"

int main() {
    int n, game_mode;
    printf("=== Tic-Tac-Toe Game ===\n");

    printf("Enter board size (3-10): ");
    scanf("%d", &n);
    if (n < 3 || n > 10) {
        printf("Invalid board size! Using 3x3 board.\n");
        n = 3;
    }

    printf("Select game mode:\n");
    printf("1. Two Players\n");
    printf("2. Player vs Computer\n");
    printf("3. Three Players\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &game_mode);

    char** board = initializingBoard(n);
    int move_count = 0;
    char players[] = {'X', 'O', 'Z'};
    int num_players = (game_mode == 3) ? 3 : 2;
    int current_player = 0;

    FILE* log = fopen("game_log.txt", "w");
    if (log) {
        fprintf(log, "New Game Started - %dx%d Board\n", n, n);
        fclose(log);
    }

    displayingBoard(board, n);

    while (1) {
        int row, col;
        char player = players[current_player];

        if (game_mode == 2 && current_player == 1) {
            generatingComputerMove(board, n, &row, &col);
        } else {
            do {
                if (!gettingUserInput(&row, &col, n, player)) continue;
            } while (!validatingMove(board, row, col, n));
        }

        makeMove(board, row, col, player);
        move_count++;
        displayingBoard(board, n);
        logGameStatus(board, n, "game_log.txt", move_count);

        if (checkWinCon(board, n, player)) {
            printf("Player %c wins!\n", player);
            break;
        }

        if (checkDrawCon(board, n)) {
            printf("It's a draw!\n");
            break;
        }

        current_player = (current_player + 1) % num_players;
    }

    freeBoard(board, n);
    printf("Thanks for playing!\n");
    return 0;
}

