#include "table.h"

table::table(string file){
    numberofplayers = 0;

}

void table::AddPlayers(string username, int money){
    player *pl = new player(username, money);
    players[numberofplayers] = *pl;
    numberofplayers ++;
}

void table::RemovePlayers(string username){
    for (int a = 0; a < numberofplayers; a++){
        if (players[a].ShowName() == username){
            player *p = &players[a];
            p = NULL;
        }
    }
    numberofplayers --;
}

void table::StartRound(){
    card firstcard;
    card secondcard;
    int decknumber;

    for (int a = 0; a < 7; a++){
        decknumber = 0; //randomizar
        firstcard = maindeck[decknumber].GiveCard();
        decknumber = 0; //randomizar
        secondcard = maindeck[decknumber].GiveCard();

        players[a].GetHand(firstcard, secondcard);
    }
}

void table::EndRound(){
    
}