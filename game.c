#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// Function to print the game board
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
bool checkWinner(char board[3][3], char player) {
    // ... (Same checkWinner function as before)
}

// Function to check if the board is full
bool isBoardFull(char board[3][3]) {
    // ... (Same isBoardFull function as before)
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';

    while (1) {
        printBoard(board);

        int row, col;
        printf("Player %c, enter your move (row [0-2] and column [0-2]): ", currentPlayer);

        // Record the start time
        time_t startTime = time(NULL);

        // Read the move from the player
        scanf("%d %d", &row, &col);

        // Record the end time
        time_t endTime = time(NULL);
        double elapsedTime = difftime(endTime, startTime);

        if (elapsedTime > 10) {
            printf("Time's up! Player %c took more than 10 seconds for the move.\n", currentPlayer);
            break;
        }

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWinner(board, currentPlayer)) {
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            } else if (isBoardFull(board)) {
                printBoard(board);
                printf("It's a draw!\n");
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
