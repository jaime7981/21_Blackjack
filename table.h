#include <iostream>
#include "player.h"
#include "deck.h"

#ifndef _TBL
#define _TBL

class table {
private:
    int numberofplayers;
    player players[7];
    player dealer;
    deck maindeck[4];

public:
    table() {
        numberofplayers = 0;
        dealer = *new player("dealer", 100000, 1, 1);
        for (long unsigned int a = 0; a < sizeof(maindeck); a++){
            maindeck[a] = *new deck();
        }
    };
    table(string);

    void AddPlayers(string, int, int , int);
    int RemovePlayers(int);
    void ShowPlayers();
    player* GetPlayers(int num);

    void AskForCards();

    void ShuffleDecks();

    void StartRound();
    void EndRound();
};

#endif