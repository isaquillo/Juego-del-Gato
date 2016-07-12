#ifndef ADMINCATGAME_H
#define ADMINCATGAME_H
#include "CatGame.h"
#include "Catboard.h"
#include "AdminCatboard.h"

#define MAX_SHIFTS 9

class AdminCatGame
{
    public:
        AdminCatGame();
        virtual ~AdminCatGame();
        void initializeStatusGame(CatGame* cG);
        void playShift(AdminCatboard* aCB, Catboard* cB, CatGame* cG);
        void verifyCatboardStatus(Catboard* cB, AdminCatboard* aCB, CatGame* cG);
        void showResults(CatGame* cG);
        bool wishContinueGame();

    private:
        bool continueGame;
        CatGame* catG;
        Catboard* catB;
        AdminCatboard* adCatB;
};

#endif // ADMINCATGAME_H
