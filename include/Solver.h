#ifndef SOLVER_H
#define SOLVER_H

#include "SudokuPackage.h"

class Solver{
    public:
        Solver();
        Solver(Sudoku&);
        bool canSolve() const;
        bool solve();
        int numEmpty() const;
    private:
        Sudoku puzz;
        int empty;
        bool doneSolving() const;
        int countEmpty() const;
};
#endif
