#include <iostream>
#include <fstream>
#include "../include/sudoku_definitions.h"
#include "../include/Sudoku.h"
#include "../include/SudokuIO.h"
#include "../include/Solver.h"

int main(int argc, char* argv[]){
    if (argc < 2){
        std::cout << "Usage: sudoku.exe [puzzle filename]" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i){
        std::fstream file(argv[i], std::fstream::in);
        if(file.is_open()){
            Sudoku* puzz = SudokuIO::readSudokuFile(&file);
            Solver sol(puzz);
            //sol->solve();
            std::cout << argv[i] << std::endl;
            puzz->print();
            delete puzz;
        }
        file.close();
    }
    
    return 0;
}
