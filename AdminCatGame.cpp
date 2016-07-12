#include <iostream>
#include "AdminCatGame.h"

#define ROWS 3
#define COLUMNS 3
#define MAX_SHIFTS 9

using namespace std;

AdminCatGame::AdminCatGame() {
    //ctor
}

AdminCatGame::~AdminCatGame() {
    //dtor
}

void AdminCatGame::initializeStatusGame(CatGame* cG) {
    catG = cG;
    catG->setPlayedShifts();
    catG->setAreShiftsOver(false);
    catG->setIsThereAWinner(false);
}

void AdminCatGame::playShift(AdminCatboard* aCB, Catboard* cB, CatGame* cG) {
    int row, column;
    bool isValidPosition;
    bool areValidData;
    char symbol;
    adCatB = aCB;
    catB = cB;
    catG = cG;

    do {
        do {
            adCatB->showCatboard(catB);
            cout << "It is turn of the player " << catG->getCurrentSymbol() << endl;
            cout << "Give me the row (1 to 3): ";
            cin >> row;
            cout << "Give me the column (1 to 3): ";
            cin >> column;
            cin.get();
            if((row >= 1 && row <= ROWS) && (column >= 1 && column <= COLUMNS)) {
                areValidData = true;
            } else {
                areValidData = false;
                cout << endl << "Invalid position. Choose again..." << endl;
                cout << endl << "Press enter to continue...";
                cin.ignore();
            }
        } while (!areValidData);
        if (catB->getSymbol(row - 1, column - 1) == ' ') {
            isValidPosition = true;
            catB->setSymbol(row - 1, column - 1, catG->getCurrentSymbol());
            catG->increasePlayedShifts();
            symbol = catG->getCurrentSymbol();
            if(symbol == 'X') {
                catG->setCurrentSymbol('O');
            } else {
                catG->setCurrentSymbol('X');
            }
        } else {
            isValidPosition = false;
            cout << endl << "That position is not available. Choose again...";
            cout << endl << "Press enter to continue...";
            cin.ignore();
        }

    } while (!isValidPosition);

}
void AdminCatGame::verifyCatboardStatus(Catboard* cB, AdminCatboard* aCB, CatGame* cG) {
    int i;
    catB = cB;
    adCatB = aCB;
    catG = cG;

    adCatB->showCatboard(catB);

    // Verify played shifts
    if (catG->getPlayedShifts() == MAX_SHIFTS) {
        catG->setAreShiftsOver(true);
    }
    // Verify rows and columns
    for (i = 0; i < ROWS; i++) {
        if (catB->getSymbol(i, 0) == catB->getSymbol(i, 1) &&
                catB->getSymbol(i, 1) == catB->getSymbol(i, 2) &&
                catB->getSymbol(i, 0) != ' ') {
            catG->setIsThereAWinner(true);
            catG->setWinnerSymbol(catB->getSymbol(i, 0));
        } else if (catB->getSymbol(0, i) == catB->getSymbol(1, i) &&
                   catB->getSymbol(1, i) == catB->getSymbol(2, i) &&
                   catB->getSymbol(0, i) != ' ') {
            catG->setIsThereAWinner(true);
            catG->setWinnerSymbol(catB->getSymbol(0, i));
        }
    }
    // Verifica las diagonales
    if (catB->getSymbol(0, 0) == catB->getSymbol(1, 1) &&
            catB->getSymbol(1, 1) == catB->getSymbol(2, 2) && catB->getSymbol(0, 0) != ' ') {
        catG->setIsThereAWinner(true);
        catG->setWinnerSymbol(catB->getSymbol(0, 0));
    } else if (catB->getSymbol(2, 0) == catB->getSymbol(1, 1) &&
               catB->getSymbol(1, 1) == catB->getSymbol(0, 2) && catB->getSymbol(2, 0) != ' ') {
        catG->setIsThereAWinner(true);
        catG->setWinnerSymbol(catB->getSymbol(0, 0));
    }
}
void AdminCatGame::showResults(CatGame* cG) {
    catG = cG;
    if(catG->getAreShiftsOver() && !(catG->getIsThereAWinner())) {
        cout << "It is a tie..." << endl;
    } else {
        cout << endl << "The winner is player  " << catG->getWinnerSymbol() << endl;
    }
}
bool AdminCatGame::wishContinueGame() {
    char answer;
    bool validAnswer;
    bool continueGame;
    do {
        validAnswer = true;
        cout << endl << "Another game? (Y/N): ";
        answer = toupper(cin.get());
        /*cin >> respuesta;
        respuesta = toupper(respuesta);*/
        switch (answer) {
        case 'Y':
            continueGame = true;
            break;
        case 'N':
            continueGame = false;
            break;
        default:
            validAnswer = false;
            cout << endl << "Invalid option. Choose again...";
            cout << endl << "Press enter to continue...";
            cin.ignore();
            break;
        }
    } while (!validAnswer);
    return continueGame;
}
