#include "../include/SudokuPackage.h"

Solver::Solver(Sudoku& p){
    puzz = p;
    empty = 0;
    for (int i = 0; i < SUDOKU_SIZE*SUDOKU_SIZE; ++i){
        if (p.get(i) == EMPTY){
            ++empty;
        }
        else{
            std::cout << puzz.eliminate(i/SUDOKU_SIZE, i%SUDOKU_SIZE, p.get(i)) << std::endl;
        }
    }
}

bool Solver::canSolve() const{
    return puzz.validate();
}

bool Solver::solve(){
    // TODO
    int empty_before;
    do{
        empty_before = empty;
        std::cout << "Empty: " << empty << std::endl;
        for (int i = 0; i < SUDOKU_SIZE*SUDOKU_SIZE; ++i){
            num_t val = puzz.simplify(i);
            if (val != EMPTY){
                puzz.set(i, val);
                std::cout << "Simpified " << i/9 << ", " << i%9 << std::endl;
                empty--;
                puzz.eliminate(i / SUDOKU_SIZE, i % SUDOKU_SIZE, val);
            }
        }
    } while (!doneSolving() && empty_before - empty > 0);
    std::cout << doneSolving() << std::endl;
    return doneSolving();
}

inline int Solver::numEmpty() const{
    return empty;
}

inline bool Solver::doneSolving() const{
    return empty == 0;
}
