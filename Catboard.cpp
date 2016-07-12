#include "Catboard.h"

Catboard::Catboard()
{
    //ctor
}

Catboard::~Catboard()
{
    //dtor
}

void Catboard::setSymbol(int row, int column, char symbol)
{
    board[row][column] = symbol;
}

char Catboard::getSymbol(int row, int column)
{
    return board[row][column];
}
