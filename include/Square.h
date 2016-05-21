#ifndef SQUARE_H
#define SQUARE_H

#include "SudokuPackage.h"

class Square{
    public:
        Square();
        Square(num_t);
        bool eliminate(num_t);
        num_t simplify() const;
        /**
         * @return  The value this square should take or 0 if not known
         */
        inline num_t getValue() const{
            return this->value;
        }
        inline void setValue(num_t val){
            this->value = val;
        }
    private:
        bool possibilities[SUDOKU_SIZE];
        num_t value;
};

#endif
