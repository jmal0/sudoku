#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <cstdio>
#include "sudoku_definitions.h"
#include "Square.h"

bool validateGrid(num_t*);

class Sudoku{
    public:
        Sudoku(num_t*);
        ~Sudoku();
        bool isSolved() const;
        void print() const;
    private:
        num_t grid[SUDOKU_SIZE*SUDOKU_SIZE];
        Square squares[SUDOKU_SIZE*SUDOKU_SIZE];
};

#endif
