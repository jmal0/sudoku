#include <iostream>
#include <fstream>
#include "../include/sudoku_definitions.h"
#include "../include/Sudoku.h"
#include "../include/SudokuIO.h"

using namespace std;

int main(int argc, char* argv[]){
    fstream file("../puzzles/test_puzzle.txt", fstream::in);
    if(file.is_open()){
        Sudoku* puzz = SudokuIO::readSudokuFile(&file);
        puzz->print();
        delete puzz;
    }
    file.close();
    return 0;
}
