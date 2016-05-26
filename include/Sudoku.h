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
        num_t simplify(int);
        int eliminate(int r, int c, num_t val);
        inline num_t get(int ind) const{
            return this->squares[ind].getValue();
        }
        inline Square getSquare(int ind) const{
            return this->squares[ind];
        }
        inline void set(int ind, num_t val){
            this->grid[ind] = val;
            this->squares[ind].setValue(val);
        }
        bool validate() const;
        void print() const;
    private:
        num_t grid[SUDOKU_SIZE*SUDOKU_SIZE];
        Square squares[SUDOKU_SIZE*SUDOKU_SIZE];

        int rowEliminate(int, int, num_t);
        int colEliminate(int, int, num_t);
        int boxEliminate(int, int, num_t);
};

#endif
