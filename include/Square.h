#ifndef SQUARE_H
#define SQUARE_H

#include "SudokuPackage.h"

class Square{
    public:
        Square();
        Square(num_t);
        bool eliminate(num_t);
        num_t simplify() const;
        num_t getValue() const;
    private:
        bool possibilities[SUDOKU_SIZE];
        num_t value;
};

#endif
