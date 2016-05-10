#ifndef SQUARE_H
#define SQUARE_H

class Square{
    public:
        Square();
        Square(num_t);
        ~Square();
        bool eliminate(num_t);
        num_t simplify() const;
        num_t getValue() const;
    private:
        bool possibilities[SUDOKU_SIZE];
        num_t value;
};

#endif
