#include "../include/Solver.h"

Solver::Solver(Sudoku* p){
    puzz = p;
    empty = 0;
    for (int i = 0; i < SUDOKU_SIZE*SUDOKU_SIZE; ++i){
        if (p->get(i) == EMPTY){
            ++empty;
        }
    }
}

Solver::~Solver(){}

bool Solver::canSolve() const{
    return puzz->validate();
}

bool Solver::solve(){
    // TODO
    int empty_before;
    do{
        empty_before = empty;
        for (int i = 0; i < SUDOKU_SIZE*SUDOKU_SIZE; ++i){
            num_t val = puzz->simplify(i);
            if (val != EMPTY){
                empty -= puzz->eliminate(i / SUDOKU_SIZE, i % SUDOKU_SIZE, val);
            }
        }
    } while (!doneSolving() && empty_before - empty > 0);
    return doneSolving();
}

inline int Solver::numEmpty() const{
    return empty;
}

inline bool Solver::doneSolving() const{
    return empty == 0;
}
