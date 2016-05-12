#ifndef SUDOKUIO_H
#define SUDOKUIO_H

#include <fstream>
#include "SudokuPackage.h"

namespace SudokuIO {
    Sudoku* readSudokuFile(std::fstream*);
}

#endif
