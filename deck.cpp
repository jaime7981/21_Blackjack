#include "deck.h"

deck::deck(int Seed) {
    seed = Seed;
}

void deck::ShuffleDeck(){
    for (int a = 0; a < 4; a++){
        for (int b = 0; b < 13; b++){

        }
    }
}

card deck::GiveCard(){
    bool flag = true;
    int a;
    int b;
    int number;
    int type;
    while (flag){
        a = 0; //randomizar
        b = 0; //randomizar
        if (cards[a][b] != 0){
            type = a;
            number = b;
            cards[a][b] = 0;
            flag = false;
        }
    }

    card *newcard = new card(number, type);

    return *newcard;
}

