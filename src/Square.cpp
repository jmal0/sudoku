#include "../include/SudokuPackage.h"

Square::Square(){
    value = 0;
    for (int i = 0; i < SUDOKU_SIZE; ++i){
        possibilities[i] = true;
    }
}

Square::Square(num_t val){
    value = val;
    for (int i = 0; i < SUDOKU_SIZE; ++i){
        possibilities[i] = i+1 == val;
    }
}

/**
 * Eliminates the number [val] as a possibility for this square
 * @param val  A number 1-9 to eliminate as a possibility
 * @return     Boolean indicating if the possibility needed to be eliminated
 */
bool Square::eliminate(num_t val){
    if (possibilities[val-1]){
        possibilities[val-1] = false;
        return true;
    }
    return false;
}

/**
 * Checks if one possibility remains and returns that possibility if so
 * @return  The only possible value of this square or 0 if > 1 possibility
 */
num_t Square::simplify() const{
    if(value != EMPTY){
        return value;
    }

    num_t val = 0;
    for (int i = 0; i < SUDOKU_SIZE; ++i){
        if(!val && possibilities[i]){
            val = i+1;
        }
        else if(val && possibilities[i]){
            return EMPTY;
        }
    }
    return val;
}

/**
 * @return  The value this square should take or 0 if not known
 */
num_t Square::getValue() const{
    return value;
}
