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
        num_t get(int) const;
        num_t simplify(int);
        int eliminate(int r, int c, num_t val);
        void print() const;
    private:
        num_t grid[SUDOKU_SIZE*SUDOKU_SIZE];
        Square squares[SUDOKU_SIZE*SUDOKU_SIZE];

        int rowEliminate(int r, int c, num_t val);
        int colEliminate(int r, int c, num_t val);
        int boxEliminate(int r, int c, num_t val);
};

#endif
