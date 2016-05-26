#include <iostream>
#include <fstream>
#include <string.h>
#include <chrono>
#include "../include/SudokuPackage.h"

int main(int argc, const char* argv[]){
    if (argc < 2){
        std::cout << "Usage: sudoku.exe [puzzle filename]" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i){
        std::fstream file((static_cast<std::string>(argv[i])).c_str(), std::fstream::in);
        std::cout << argv[i] << std::endl;
        if(file.is_open()){
            std::cout << "opened" << std::endl;
            Sudoku puzz = SudokuIO::readSudokuFile(&file);
            if (&puzz != NULL){
                Solver sol(puzz);

                auto start = std::chrono::high_resolution_clock::now();
                sol.solve();
                auto elapsed = std::chrono::high_resolution_clock::now() - start;
                long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
                std::cout << "Solution obtained after " << microseconds << " microsceonds:" << std::endl;

                sol.print();
            }
        }
        file.close();
    }
    
    return 0;
}
