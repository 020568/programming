#include <stdio.h>
#include <stdlib.h>

/**
 * Check if it is safe to place a queen at mat[row][col].
 * Since queens are placed row by row, we only check the columns
 * and diagonals above the current row.
 */
int isSafe(int** mat, int n, int row, int col) {
    int i, j;

    // Check this column on the upper side
    for (i = 0; i < row; i++)
        if (mat[i][col])
            return 0;

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j])
            return 0;

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (mat[i][j])
            return 0;

    return 1;
}

/**
 * Recursive backtracking function to find and store all valid solutions.
 * @param row: The current row being processed.
 * @param n: Board size (n x n).
 * @param mat: The 2D chess board.
 * @param result: Pointer to a 2D array storing all successful placements.
 * @param resultCount: Pointer to the number of solutions found.
 */
void placeQueens(int row, int n, int** mat, int*** result, int* resultCount) {
    // Base case: All queens are placed
    if (row == n) 
	{
        (*resultCount)++;
        // Reallocate memory to store the new solution
        *result = (int**)realloc(*result, sizeof(int*) * (*resultCount));
        (*result)[*resultCount - 1] = (int*)malloc(sizeof(int) * n);

        // Store the column indices (1-based index) for each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    (*result)[*resultCount - 1][i] = j + 1;
                }
            }
        }
        return;
    }

    // Try placing a queen in each column of the current row
    for (int i = 0; i < n; i++) {
        if (isSafe(mat, n, row, i)) {
            // Place the queen
            mat[row][i] = 1;

            // Move to the next row
            placeQueens(row + 1, n, mat, result, resultCount);//!!!recursion
            //core step: row+1

            // Backtrack: Remove the queen to try other possibilities
            mat[row][i] = 0;
        }
    }
}

int main() {
    int n = 4;
    int resultCount = 0;
    int** result = NULL;

    // Dynamically allocate the n x n board
    int** mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)calloc(n, sizeof(int)); // Initialize with 0s
    }

    // Start the backtracking process
    placeQueens(0, n, mat, &result, &resultCount);

    // Print all discovered solutions
    for (int i = 0; i < resultCount; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        // Free individual solution memory
        free(result[i]);
    }

    // Manual memory cleanup
    free(result);
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}