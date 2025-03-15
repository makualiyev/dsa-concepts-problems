/*
 * 
* N Queens problem
*/

#include <stdio.h>
#include <stdbool.h>

#define N 5

// Function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col) {
    // Check this row on left side
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}


// Recursive utility function to solve N Queen problem
bool solveQUtil(int board[N][N], int col)
{
    // Base case: If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be place on board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of queens
            if (solveQUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove queen from board[i][col] (backtrack)
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column col then return false
    return false;
}

// This function solves the N Queen problem using Backtracking
bool solveNQ() {
    int board[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0} 
    };
    printSolution(board);
    printf("------------\n");
    if (solveQUtil(board, 0) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(board);
    return true;
}


int main(int argc, char *argv[])
{
    solveNQ();
    return 0;
}