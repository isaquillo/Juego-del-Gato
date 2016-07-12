/*
    Nickname: UnoUno
    Invested time: 11:25
*/

#include <iostream>
#include "Catboard.h"
#include "AdminCatboard.h"
#include "CatGame.h"
#include "AdminCatGame.h"

using namespace std;

int main()
{
    Catboard catboard;
    AdminCatboard adminCatboard;
    CatGame catGame;
    AdminCatGame adminCatGame;
   do
    {
        adminCatboard.initializeCatboard(&catboard);
        adminCatGame.initializeStatusGame(&catGame);
        do
        {
            adminCatGame.playShift(&adminCatboard, &catboard, &catGame);
            adminCatGame.verifyCatboardStatus(&catboard, &adminCatboard, &catGame);
        }
        while (!(catGame.getIsThereAWinner()) && !(catGame.getAreShiftsOver()));
        adminCatGame.showResults(&catGame);
    }
    while (adminCatGame.wishContinueGame());
    cin.ignore();
    cout << endl << "Press enter to finish...";
    cin.ignore();

    return 0;
}
