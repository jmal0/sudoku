#ifndef SQUARE_H
#define SQUARE_H

#include "SudokuPackage.h"

class Square{
    public:
        Square();
        Square(num_t);
        bool eliminate(num_t);
        num_t simplify() const;
        inline bool isPossibility(num_t i) const{
            return this->possibilities[i-1];
        }
        /**
         * @return  The value this square should take or 0 if not known
         */
        inline num_t getValue() const{
            return this->value;
        }
        void setValue(num_t);
    private:
        bool possibilities[SUDOKU_SIZE];
        num_t value;
};

#endif
