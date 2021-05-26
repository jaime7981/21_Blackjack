#include "card.h"

#ifndef _DECK
#define _DECK

class deck{
private:
    int cards[4][13] = {{1,2,3,4,5,6,7,8,9,10,11,12,13}, 
                        {1,2,3,4,5,6,7,8,9,10,11,12,13}, 
                        {1,2,3,4,5,6,7,8,9,10,11,12,13}, 
                        {1,2,3,4,5,6,7,8,9,10,11,12,13}};
    card deckofcards[4][13];
    int seed;
public:
    deck() {};
    deck(int);

    void ShuffleDeck();
    card GiveCard();
};

#endif