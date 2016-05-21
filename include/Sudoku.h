#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include "SudokuPackage.h"

bool validateGrid(const num_t*);

class Sudoku{
    public:
        Sudoku();
        Sudoku(num_t*);
        bool isSolved() const;
        inline num_t get(int ind) const{
            return squares[ind].getValue();
        }
        inline void set(int ind, num_t val){
            grid[ind] = val;
            squares[ind].setValue(val);
        }
        num_t simplify(int);
        int eliminate(int r, int c, num_t val);
        bool validate() const;
        void print() const;
    private:
        num_t grid[SUDOKU_SIZE*SUDOKU_SIZE];
        Square squares[SUDOKU_SIZE*SUDOKU_SIZE];

        int rowEliminate(int r, int c, num_t val);
        int colEliminate(int r, int c, num_t val);
        int boxEliminate(int r, int c, num_t val);
};

#endif
