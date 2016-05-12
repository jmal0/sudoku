#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include "SudokuPackage.h"

bool validateGrid(num_t*);

class Sudoku{
    public:
        Sudoku(num_t*);
        ~Sudoku();
        bool isSolved() const;
        inline num_t get(int ind) const{
            return squares[ind].getValue();
        }
        inline num_t simplify(int ind){
            return squares[ind].simplify();
        }
        int eliminate(int r, int c, num_t val);
        bool validate();
        void print() const;
    private:
        num_t grid[SUDOKU_SIZE*SUDOKU_SIZE];
        Square squares[SUDOKU_SIZE*SUDOKU_SIZE];

        int rowEliminate(int r, int c, num_t val);
        int colEliminate(int r, int c, num_t val);
        int boxEliminate(int r, int c, num_t val);
};

#endif
