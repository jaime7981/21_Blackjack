#include "player.h"
#include "deck.h"

#ifndef _TBL
#define _TBL

class table {
private:
    int numberofplayers;
    string loadfile;
    player players[7];
    deck maindeck[4];

public:
    table() {};
    table(string);

    void AddPlayers(string, int);
    void RemovePlayers(string);

    void AskForCards();

    void ShuffleDecks();

    void StartRound();
    void EndRound();
};

#endif