#include "../include/SudokuPackage.h"

bool validateGrid(num_t grid[SUDOKU_SIZE*SUDOKU_SIZE]){
    for (num_t num = 1; num <= SUDOKU_SIZE; ++num){
        bool found;
        // Check rows
        for (int row = 0; row < SUDOKU_SIZE; ++row){
            found = false;
            for (int col = 0; col < SUDOKU_SIZE; ++col){
                if(grid[PUZZ_IND(row, col)] == num){
                    if(found){
                        // num found twice in same row -> invalid
                        return false;
                    }
                    found = true;
                }
            }
        }

        // Check columns
        for (int col = 0; col < SUDOKU_SIZE; ++col){
            found = false;
            for (int row = 0; row < SUDOKU_SIZE; ++row){
                if(grid[PUZZ_IND(row, col)] == num){
                    if(found){
                        // num found twice in same row -> invalid
                        return false;
                    }
                    found = true;
                }
            }
        }

        // Check boxes
        for (int box = 0; box < SUDOKU_SIZE; ++box){
            found = false;
            for (int col = box % 3; col < box%3 + 3; ++col){
                for (int row = box / 3; row < box/3 + 3; ++row){
                    if(grid[PUZZ_IND(row, col)] == num){
                        if(found){
                            // num found twice in same row -> invalid
                            return false;
                        }
                        found = true;
                    }
                }
            }
        }
    }
    return true;
}

Sudoku::Sudoku(num_t ref[SUDOKU_SIZE*SUDOKU_SIZE]){
    for (int i = 0; i < SUDOKU_SIZE*SUDOKU_SIZE; ++i){
        grid[i] = ref[i];
        squares[i] = Square(ref[i]);
    }
}

bool Sudoku::isSolved() const{
    bool found[SUDOKU_SIZE];
    for (int i = 0; i < SUDOKU_SIZE; ++i){
        found[i] = 0;
    }

    // Check rows
    for (int row = 0; row < SUDOKU_SIZE; ++row){
        for (int col = 0; col < SUDOKU_SIZE; ++col){
            if(grid[PUZZ_IND(row, col)] == EMPTY){
                return false;
            }
            found[grid[PUZZ_IND(row, col)]] = true;
        }
        for(int i = 0; i < SUDOKU_SIZE; ++i){
            if(!found[i]){
                return false;
            }
        }
    }

    // Check columns
    for (int col = 0; col < SUDOKU_SIZE; ++col){
        for (int row = 0; row < SUDOKU_SIZE; ++row){
            if(grid[PUZZ_IND(row, col)] == EMPTY){
                return false;
            }
            found[grid[PUZZ_IND(row, col)]] = true;
        }
        for(int i = 0; i < SUDOKU_SIZE; ++i){
            if(!found[i]){
                return false;
            }
        }
    }

    // Check boxes
    for (int box = 0; box < SUDOKU_SIZE; ++box){
        for (int col = box % 3; col < box%3 + 3; ++col){
            for (int row = box / 3; row < box/3 + 3; ++row){
                if(grid[PUZZ_IND(row, col)] == EMPTY){
                    return false;
                }
                found[grid[PUZZ_IND(row, col)]] = true;
            }
        }
        for(int i = 0; i < SUDOKU_SIZE; ++i){
            if(!found[i]){
                return false;
            }
        }
    }
    return true;
}

int Sudoku::eliminate(int r, int c, num_t val){
    int count = 0;
    count += rowEliminate(r, c, val);
    count += colEliminate(r, c, val);
    count += boxEliminate(r, c, val);
}

int Sudoku::rowEliminate(int r, int c, num_t val){
    int count = 0;
    for (int i = 0; i < SUDOKU_SIZE; ++i){
        if (i != c){
            count += squares[PUZZ_IND(r, i)].eliminate(val);
        }
    }
    return count;
}

int Sudoku::colEliminate(int r, int c, num_t val){
    int count = 0;
    for (int i = 0; i < SUDOKU_SIZE; ++i){
        if (i != r){
            count += squares[PUZZ_IND(i, c)].eliminate(val);
        }
    }
    return count;
}

int Sudoku::boxEliminate(int r, int c, num_t val){
    int count = 0;
    for (int rb = BOX_SIZE*(r/BOX_SIZE); rb < BOX_SIZE*(r/BOX_SIZE) + BOX_SIZE; ++rb){
        for (int cb = BOX_SIZE*(c/BOX_SIZE); cb < BOX_SIZE*(c/BOX_SIZE) + BOX_SIZE; ++cb){
            if (rb != r && cb != c){
                count += squares[PUZZ_IND(rb, cb)].eliminate(val);
            }
        }
    }
    return count;
}

bool Sudoku::validate(){
    return validateGrid(grid);
}

void Sudoku::print() const{
    for (int r = 0; r < SUDOKU_SIZE; ++r){
        for (int c = 0; c < SUDOKU_SIZE; ++c){
           printf("%c ", grid[PUZZ_IND(r,c)] + '0');
        }
        std::cout << std::endl;
    }
}
