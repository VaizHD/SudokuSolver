#include <iostream>
#include <string>

using namespace std;

bool trySolveSudoku(int sudoku[9][9]);
bool isValid(int sudoku[9][9], int column, int row, int value);
void printSudoku(int sudoku[9][9]);
int main() {
    std::cout << "SudokuSolver by VaizHD" << std::endl;
    std::clock_t start;
    double duration;

    start = std::clock();

    int sudoku[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    for (int i = 0; i < 9; i++) {
        std::cout << "Veuillez saisir les valeurs de la ligne " << i + 1 << " (9 chiffres sans espaces) :\n";
        std::string line;
        std::getline(std::cin, line);
        if (line.length() != 9) {
            std::cout << "Erreur : vous devez saisir exactement 9 chiffres.\n";
            i--;
            continue;
        }
        for (int j = 0; j < 9; j++) {
            int inputValue = line[j] - '0'; 
            sudoku[i][j] = inputValue;
        }
    }
    start = std::clock();
    std::cout << "Calcul en cours ..." << std::endl;
    trySolveSudoku(sudoku);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "Temps du calcul : " << duration << " seconde(s)" << std::endl;
    
}

bool trySolveSudoku(int sudoku[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int column = 0; column < 9; column++) {
            if (sudoku[row][column] == 0) {
                for (int testValue = 1; testValue <= 9; testValue++) {
                    if (isValid(sudoku, row, column, testValue)) {
                        sudoku[row][column] = testValue;
                        if (trySolveSudoku(sudoku)) {
                            return true;
                        }
                        sudoku[row][column] = 0;
                    }
                }
                return false;
            }
        }
    }
    printSudoku(sudoku);
    return true;
}

bool isValid(int sudoku[9][9], int row, int column, int value) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == value) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][column] == value) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startColumn = column - column % 3;
    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startColumn; c < startColumn + 3; c++) {
            if (sudoku[r][c] == value) {
                return false;
            }
        }
    }

    return true;
}

void printSudoku(int sudoku[9][9]) {
    std::cout << "Solution du Sudoku : " << std::endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << sudoku[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
