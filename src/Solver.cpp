#include "../include/SudokuPackage.h"

Solver::Solver(Sudoku& p){
    this->puzz = p;
    this->empty = 0;
    for (int i = 0; i < SUDOKU_SIZE*SUDOKU_SIZE; ++i){
        if (p.get(i) == EMPTY){
            ++this->empty;
        }
        else{
            this->puzz.eliminate(i/SUDOKU_SIZE, i%SUDOKU_SIZE, p.get(i));
        }
    }
}

bool Solver::canSolve() const{
    return this->puzz.validate();
}

bool Solver::solve(){
    // TODO
    int empty_before;
    do{
        empty_before = this->empty;
        std::cout << "Empty: " << this->empty << std::endl;
        simplify();
        reduce();
    } while (!doneSolving() && empty_before - this->empty > 0);
    return doneSolving();
}

int Solver::simplify(){
    int count = 0;
    for (int i = 0; i < SUDOKU_SIZE*SUDOKU_SIZE; ++i){
        num_t val = this->puzz.simplify(i);
        if (val != EMPTY){
            set(i, val);
            count++;
        }
    }
    return count;
}

int Solver::reduce(){
    int count = 0;
    for (int i = 0; i < SUDOKU_SIZE; i++){    
        count += rowReduce(i);
        count += colReduce(i);
        count += boxReduce(i);
    }
    return count;
}

int Solver::rowReduce(int r){
    int count = 0;
    for (int num = 1; num <= SUDOKU_SIZE; num++){
        int found = -1;
        for (int c = 0; c < SUDOKU_SIZE; c++){
            if (this->puzz.getSquare(PUZZ_IND(r, c)).isPossibility(num)){
                if (found != -1){
                    found = -1;
                    break;
                }
                found = c;
            }
        }
        // Only one possible occurence of this number in this row
        if (found != -1){
            int ind = PUZZ_IND(r, found);
            set(ind, num);
            count++;
        }
    }
    return count;
}

int Solver::colReduce(int c){
    int count = 0;
    for (int num = 1; num <= SUDOKU_SIZE; num++){
        int found = -1;
        for (int r = 0; r < SUDOKU_SIZE; r++){
            if (this->puzz.getSquare(PUZZ_IND(r, c)).isPossibility(num)){
                if (found != -1){
                    found = -1;
                    break;
                }
                found = r;
            }
        }
        // Only one possible occurence of this number in this column
        if (found != -1){
            int ind = PUZZ_IND(found, c);
            set(ind, num);
            count++;
        }
    }
    return count;
}

int Solver::boxReduce(int b){
    int count = 0;
    for (int num = 1; num <= SUDOKU_SIZE; num++){
        int found = -1;
        for (int i = 0; i < SUDOKU_SIZE; i++){
            if (this->puzz.getSquare(PUZZ_IND(BOX_R(b, i), BOX_C(b, i))).isPossibility(num)){
                if (found != -1){
                    found = -1;
                    break;
                }
                found = i;
            }
        }
        // Only one possible occurence of this number in this box
        if (found != -1){
            int ind = PUZZ_IND(BOX_R(b,found), BOX_C(b,found));
            set(ind, num);
            count++;
        }
    }
    return count;
}
