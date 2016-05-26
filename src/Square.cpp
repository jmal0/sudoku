#include "../include/SudokuPackage.h"

Square::Square(){
    this->value = 0;
    for (int i = 0; i < SUDOKU_SIZE; ++i){
        this->possibilities[i] = true;
    }
}

Square::Square(num_t val){
    this->value = val;
    if(val == EMPTY){
        for (int i = 0; i < SUDOKU_SIZE; ++i){
            this->possibilities[i] = true;
        }
    }
    else{
        for (int i = 0; i < SUDOKU_SIZE; ++i){
            this->possibilities[i] = i == val;
        }   
    }
}

/**
 * Eliminates the number [val] as a possibility for this square
 * @param val  A number 1-9 to eliminate as a possibility
 * @return     Boolean indicating if the possibility needed to be eliminated
 */
bool Square::eliminate(num_t val){
    if (this->possibilities[val-1]){
        this->possibilities[val-1] = false;
        return true;
    }
    return false;
}

/**
 * Checks if one possibility remains and returns that possibility if so
 * @return  The only possible value of this square or 0 if > 1 possibility
 */
num_t Square::simplify() const{
    if (this->value != EMPTY){
        return this->value;
    }

    num_t val = 0;
    for (int i = 0; i < SUDOKU_SIZE; ++i){
        if (!val && this->possibilities[i]){
            val = i+1;
        }
        else if (val && this->possibilities[i]){
            return EMPTY;
        }
    }
    return val;
}

void Square::setValue(num_t val){
    for (int i = 0; i < SUDOKU_SIZE; ++i){
        this->possibilities[i] = false;
    }
    this->value = val;
}
