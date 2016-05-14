#include <iostream>
#include <fstream>
#include <string.h>
#include "../include/SudokuPackage.h"

int main(int argc, const char* argv[]){
    if (argc < 2){
        std::cout << "Usage: sudoku.exe [puzzle filename]" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i){
        std::fstream file(("../" + static_cast<std::string>(argv[i])).c_str(), std::fstream::in);
        std::cout << argv[i] << std::endl;
        if(file.is_open()){
            Sudoku* puzz = SudokuIO::readSudokuFile(&file);
            Solver sol(puzz);
            //sol->solve();
            puzz->print();
        }
        file.close();
    }
    
    return 0;
}
