#ifndef SOLVER_H
#define SOLVER_H

#include "SudokuPackage.h"

class Solver{
    public:
        Solver();
        Solver(Sudoku&);
        bool canSolve() const;
        bool solve();
        inline void set(int ind, int num){
            this->puzz.set(ind, num);
            this->puzz.eliminate(ind / SUDOKU_SIZE, ind % SUDOKU_SIZE, num);
            this->empty--;
        }
        inline void print() const{
            this->puzz.print();
        }
    private:
        Sudoku puzz;
        int empty;
        int simplify();
        int reduce();
        int rowReduce(int);
        int colReduce(int);
        int boxReduce(int);
        inline bool doneSolving() const{
            return this->empty == 0;
        }
};
#endif
