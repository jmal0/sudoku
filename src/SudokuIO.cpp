#include "../include/SudokuPackage.h"

Sudoku* SudokuIO::readSudokuFile(std::fstream* file){
    num_t grid[SUDOKU_SIZE*SUDOKU_SIZE];
    int i = 0;
    char ch;
    while (i < SUDOKU_SIZE*SUDOKU_SIZE && file->get(ch)) {
        while(ch == ' ' || ch == '\n'){
            file->get(ch);
        }
        if(ch < MIN_CHAR || ch > MAX_CHAR){
            return NULL;
        }
        grid[i] = ch - MIN_CHAR;
        i++;
    }
    if(i == SUDOKU_SIZE*SUDOKU_SIZE){
        return new Sudoku(grid);
    }
    return NULL;
}
