#include <iostream>
#include "player.h"
#include "deck.h"

#ifndef _TBL
#define _TBL

class table {
private:
    int numberofplayers;
    string tablename;
    player players[7];
    deck maindeck[4];

public:
    table() {
        numberofplayers = 0;
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