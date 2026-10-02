# CodeAlpha C++ Programming Projects

This repository contains three completed C++ tasks for the CodeAlpha internship.

## Tasks Included

1. CGPA Calculator
2. Login and Registration System
3. Sudoku Solver

## Requirements Covered

### Task 1: CGPA Calculator
- Takes the number of courses/semesters as input.
- Takes grade and credit hours for each course.
- Calculates grade points using grade × credit hours.
- Calculates semester GPA.
- Calculates overall CGPA.
- Displays individual course grades and final CGPA.

### Task 2: Login and Registration System
- Registration function for username and password.
- Checks for duplicate usernames.
- Stores user credentials in a file.
- Password is hashed before being stored.
- Login verifies the stored credentials.
- Displays success/error messages.

### Task 3: Sudoku Solver
- Uses a 2D array for the Sudoku grid.
- Uses a recursive backtracking algorithm.
- Checks row, column, and 3x3 subgrid rules.
- Tries possible numbers until the puzzle is solved.
- Displays the original and solved Sudoku.

## How to Run in VS Code

Open any task folder in VS Code.

Compile:
g++ main.cpp -o main

Run on Windows:
.\main.exe

For Task 2, the program creates `users.txt` automatically in the same folder when a user registers.

## Suggested GitHub Repository Name

CodeAlpha_Cpp_Programming
