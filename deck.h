#include "card.h"
#include <iostream>

#ifndef _DECK
#define _DECK

class deck{
private:
    int cards[4][13] = {{1,2,3,4,5,6,7,8,9,10,11,12,13}, 
                        {1,2,3,4,5,6,7,8,9,10,11,12,13}, 
                        {1,2,3,4,5,6,7,8,9,10,11,12,13}, 
                        {1,2,3,4,5,6,7,8,9,10,11,12,13}};
    card deckofcards[4][13];
    int cardcounter;
public:
    deck() {
        AsignCards();
        cardcounter = 0;
    };
    void AsignCards();
    card GiveCard();
    void ShowAllCard();

    int GetCardCount();
    void SetCardCount(int);
};

#endif