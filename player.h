#include <string>
#include "card.h"
#include "deck.h"

#ifndef _PLAY
#define _PLAY
using namespace std;

class player{
private:
    string username;
    int money;
    int roundsplayed;
    int roundswinned;
    card startingcards[2];
    card extracard[5];
    int extracardcounter;
    bool win;
    int bet;
    int multiplier;
    bool stand;
public:
    player(){};
    player(string, int, int , int);
    
    void AddMoney(int);
    void RemoveMoney(int);
    int ShowMoney();
    
    void ChangeName(string);
    string ShowName();

    void AddRound();
    int ShowRoundsPlayed();
    int ShowRoundsWinned();

    void GetHand(card, card);
    void AddCards(card);
    void RemoveHand();
    void EmptyExtraCards();
    card GetCards(int);
    int CardSum();

    int CalculateHand();

    bool GetWin();
    void SetWin(bool);

    int GetBet();
    void SetBet(int);

    int GetMultiplier();
    void SetMultiplier(int);

    bool GetStand();
    void SetStand(bool);
};

#endif