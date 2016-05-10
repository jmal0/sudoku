#ifndef SOLVER_H
#define SOLVER_H

#include "sudoku_definitions.h"
#include "Sudoku.h"

class Solver{
    public:
        Solver();
        Solver(Sudoku* puzz);
        ~Solver();
        bool canSolve() const;
        bool solve();
        int numEmpty() const;
    private:
        Sudoku* puzz;
        int empty;
        bool doneSolving() const;
        int countEmpty() const;
};
#endif
