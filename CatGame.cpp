#include "CatGame.h"

CatGame::CatGame() {
    currentSymbol = 'X';
    //ctor
}

CatGame::~CatGame() {
    //dtor
}

void CatGame::setPlayedShifts() {
    playedShifts = 0;
}

void CatGame::setCurrentSymbol(char symbol) {
    currentSymbol = symbol;
}

void CatGame::setWinnerSymbol(char symbol) {
    winnerSymbol = symbol;
}

void CatGame::increasePlayedShifts() {
    ++playedShifts;
}

void CatGame::setAreShiftsOver(bool state) {
    areShiftsOver = state;
}

void CatGame::setIsThereAWinner(bool state) {
    isThereAWinner = state;
}

char CatGame::getCurrentSymbol() {
    return currentSymbol;
}

char CatGame::getWinnerSymbol() {
    return winnerSymbol;
}

int CatGame::getPlayedShifts() {
    return playedShifts;
}

bool CatGame::getAreShiftsOver() {
    return areShiftsOver;
}

bool CatGame::getIsThereAWinner() {
    return isThereAWinner;
}
