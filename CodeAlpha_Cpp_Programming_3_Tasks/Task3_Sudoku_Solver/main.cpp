#include <iostream>
using namespace std;

const int SIZE = 9;

// Display the Sudoku grid.
void printGrid(int grid[SIZE][SIZE]) {
    cout << "\n+-------+-------+-------+\n";

    for (int row = 0; row < SIZE; row++) {
        cout << "| ";

        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0)
                cout << ". ";
            else
                cout << grid[row][col] << ' ';

            if ((col + 1) % 3 == 0)
                cout << "| ";
        }

        cout << '\n';

        if ((row + 1) % 3 == 0)
            cout << "+-------+-------+-------+\n";
    }
}

// Check whether a number can be placed in a cell.
bool isSafe(int grid[SIZE][SIZE], int row, int col, int number) {
    // Check the row.
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == number)
            return false;
    }

    // Check the column.
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == number)
            return false;
    }

    // Check the 3x3 subgrid.
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grid[startRow + r][startCol + c] == number)
                return false;
        }
    }

    return true;
}

// Find an empty cell and solve the puzzle using backtracking.
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row = -1;
    int col = -1;
    bool emptyCellFound = false;

    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (grid[r][c] == 0) {
                row = r;
                col = c;
                emptyCellFound = true;
                break;
            }
        }

        if (emptyCellFound)
            break;
    }

    // No empty cells means the puzzle is solved.
    if (!emptyCellFound)
        return true;

    // Try numbers 1 through 9.
    for (int number = 1; number <= 9; number++) {
        if (isSafe(grid, row, col, number)) {
            grid[row][col] = number;

            // Recursively solve the remaining cells.
            if (solveSudoku(grid))
                return true;

            // Backtrack if the choice does not lead to a solution.
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "===== CodeAlpha Sudoku Solver =====\n";
    cout << "\nOriginal Sudoku:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "\nThis Sudoku puzzle has no solution.\n";
    }

    return 0;
}
