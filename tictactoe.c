#include "tictactoe.h"


// tictactoe.c - Implementation file

// Initialize the game board with empty spaces
char** initializingBoard(int n) {
    char** board = (char**)malloc(n * sizeof(char*));
    if (board == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc(n * sizeof(char));
        if (board[i] == NULL) {
            printf("Memory allocation failed!\n");
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(board[j]);
            }
            free(board);
            exit(1);
        }
        // Initialize with empty spaces
        for (int j = 0; j < n; j++) {
            board[i][j] = ' ';
        }
    }
    return board;
}

// Free dynamically allocated memory
void freeBoard(char** board, int n) {
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
}

// Display the current board state
void displayingBoard(char** board, int n) {
    printf("\n   ");
    // Column headers
    for (int i = 0; i < n; i++) {
        printf(" %d  ", i + 1);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d  ", i + 1); // Row number
        for (int j = 0; j < n; j++) {
            printf(" %c ", board[i][j]);
            if (j < n - 1) printf("|");
        }
        printf("\n");
        
        // Horizontal separator
        if (i < n - 1) {
            printf("   ");
            for (int j = 0; j < n; j++) {
                printf("---");
                if (j < n - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Get user input for move
int gettingUserInput(int* row, int* col, int n, char player) {
    printf("Player %c's turn. Enter row and column (1-%d): ", player, n);
    
    if (scanf("%d %d", row, col) != 2) {
        printf("Invalid input! Please enter two numbers.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return 0;
    }
    
    // Convert to 0-based indexing
    (*row)--;
    (*col)--;
    
    return 1;
}

// Validate if the move is legal
int validatingMove(char** board, int row, int col, int n) {
    // Check bounds
    if (row < 0 || row >= n || col < 0 || col >= n) {
        printf("Invalid position! Please choose between 1-%d.\n", n);
        return 0;
    }
    
    // Check if cell is empty
    if (board[row][col] != ' ') {
        printf("Cell already occupied! Choose another position.\n");
        return 0;
    }
    
    return 1;
}

// Make a move on the board
int makeMove(char** board, int row, int col, char player) {
    board[row][col] = player;
    return 1;
}

// Check for win condition
int checkWinCon(char** board, int n, char player) {
    // Check rows
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == player) count++;
        }
        if (count == n) return 1;
    }
    
    // Check columns
    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][j] == player) count++;
        }
        if (count == n) return 1;
    }
    
    // Check main diagonal
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (board[i][i] == player) count++;
    }
    if (count == n) return 1;
    
    // Check anti-diagonal
    count = 0;
    for (int i = 0; i < n; i++) {
        if (board[i][n - 1 - i] == player) count++;
    }
    if (count == n) return 1;
    
    return 0;
}

// Check for draw condition
int checkDrawCon(char** board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == ' ') {
                return 0; // Still empty cells
            }
        }
    }
    return 1; // Board is full
}

// Log game state to file
void logGameStatus(char** board, int n, const char* filename, int move_count) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    
    fprintf(file, "Move %d:\n", move_count);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(file, "%c ", board[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "---\n");
    
    fclose(file);
}

// Generate computer move (random valid move)
void generatingComputerMove(char** board, int n, int* row, int* col) {
    srand(time(NULL));
    
    do {
        *row = rand() % n;
        *col = rand() % n;
    } while (board[*row][*col] != ' ');
    
    printf("Computer chooses position (%d, %d)\n", *row + 1, *col + 1);
}

