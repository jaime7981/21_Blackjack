#include "deck.h"

using namespace std;

void deck::AsignCards(){
    for (int a = 0; a < 4; a++){
        for (int b = 0; b < 13; b++){
            deckofcards[a][b].SetType(a + 1);
            deckofcards[a][b].SetNumber(b + 1);
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
        a = rand() % 4;
        b = rand() % 13;
        if (cards[a][b] != 0){
            type = a;
            number = b;
            cards[a][b] = 0;
            flag = false;
        }
    }
    cardcounter ++;
    return deckofcards[type][number];
}

int deck::GetCardCount(){
    return cardcounter;
}

void deck::SetCardCount(int num){
    cardcounter = num;
}

void deck::ShowAllCard(){
    for (int a = 0; a < 4; a++){
        for (int b = 0; b < 13; b++){
            cout << to_string(deckofcards[a][b].GetType()) + " " + to_string(deckofcards[a][b].GetNumber()) << endl;
        }
    }
}
