#ifndef SUDOKUIO_H
#define SUDOKUIO_H

#include <fstream>
#include "sudoku_definitions.h"
#include "Sudoku.h"

namespace SudokuIO {
    Sudoku* readSudokuFile(std::fstream*);
}

#endif
