#ifndef CATBOARD_H
#define CATBOARD_H

#define ROWS 3
#define COLUMNS 3

class Catboard
{
    public:
        Catboard();
        virtual ~Catboard();
        void setSymbol(int row, int column, char symbol);
        char getSymbol(int row, int column);

    private:
        char board[ROWS][COLUMNS];
};

#endif // CATBOARD_H
