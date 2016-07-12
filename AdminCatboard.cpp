#include <cstdlib>
#include <iostream>

#include "AdminCatboard.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
#define ROWS 3
#define COLUMNS 3

using namespace std;

AdminCatboard::AdminCatboard() {
    //ctor
}

AdminCatboard::~AdminCatboard() {
    //dtor
}

void AdminCatboard::initializeCatboard(Catboard* cB) {
    int i, j;
    catB = cB;
    char symbol = ' ';
    for(i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            catB->setSymbol(i, j, symbol);
        }
    }
}

void AdminCatboard::showCatboard(Catboard* cB) {
    int i, j;
    catB = cB;
    system(CLEAR);
    cout << "Cat Game v1.0" << endl << endl;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            cout << " " << catB->getSymbol(i, j);
            (j < COLUMNS - 1) ? cout << " |" : cout << endl;
        }
        cout << "-----------" << endl;
    }
}
