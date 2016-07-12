#ifndef ADMINCATBOARD_H
#define ADMINCATBOARD_H
#include "Catboard.h"

class AdminCatboard
{
    public:
        AdminCatboard();
        virtual ~AdminCatboard();
        void initializeCatboard(Catboard* cB);
        void showCatboard(Catboard* cB);

    private:
        Catboard* catB;
};


#endif // ADMINCATBOARD_H
