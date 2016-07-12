#ifndef CATGAME_H
#define CATGAME_H


class CatGame
{
    public:
        CatGame();
        virtual ~CatGame();
        void setPlayedShifts();
        void setCurrentSymbol(char symbol);
        void setWinnerSymbol(char symbol);
        void increasePlayedShifts();
        void setAreShiftsOver(bool state);
        void setIsThereAWinner(bool state);
        char getCurrentSymbol();
        char getWinnerSymbol();
        int getPlayedShifts();
        bool getAreShiftsOver();
        bool getIsThereAWinner();

    private:
        char currentSymbol;
        char winnerSymbol;
        int playedShifts;
        bool areShiftsOver;
        bool isThereAWinner;
};

#endif // CATGAME_H
