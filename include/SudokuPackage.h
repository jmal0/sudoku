#ifndef SUDOKUPACKAGE_H
#define SUDOKUPACKAGE_H

typedef char num_t;
const num_t EMPTY = 0;
const num_t SUDOKU_SIZE = 9;
const num_t BOX_SIZE = 3;
const char MIN_CHAR = '0';
const char MAX_CHAR = '9';

inline int PUZZ_IND(int r, int c){
    return r*SUDOKU_SIZE + c;
}

inline int BOX_R(int b, int i){
    return (b / BOX_SIZE)*BOX_SIZE + i / BOX_SIZE;
}

inline int BOX_C(int b, int i){
    return (b % BOX_SIZE)*BOX_SIZE + i % BOX_SIZE;
}

#include "Square.h"
#include "Sudoku.h"
#include "Solver.h"
#include "SudokuIO.h"

#endif
