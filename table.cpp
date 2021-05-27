#include "table.h"
#include <string>

void table::AddPlayers(string username, int money, int roundsplayed, int roundswinned){
    if (numberofplayers < 8){
        players[numberofplayers] = *new player(username, money, roundsplayed, roundswinned);
        numberofplayers ++;
    }
}

int table::RemovePlayers(int num){
    if (num < 8){
        for (int a = 0; a < 7; a++){
            if (a+1 == num){
                players[a].ChangeName("");
                numberofplayers --;
                return 0;
            }
        }
    }
    return 1;
}

void table::ShowPlayers(){
    for (int a = 0; a < 7; a++){
        if (players[a].ShowName() != ""){
            cout << to_string(a + 1) + ") Name: " + players[a].ShowName() + " Money: " + to_string(players[a].ShowMoney()) << endl;
        }
    }
}

player* table::GetPlayers(int num){
    return &players[num];
}

void table::ShuffleDecks(){
    for (int a = 0; a < 4; a++){
        maindeck[a].ShowAllCard();
    }
}

void table::StartRound(){
    card firstcard;
    card secondcard;
    int decknumber;

    for (int a = 0; a < 7; a++){
        if (players[a].ShowName() != ""){
            decknumber = 0; //randomizar
            firstcard = maindeck[decknumber].GiveCard();
            decknumber = 0; //randomizar
            secondcard = maindeck[decknumber].GiveCard();

            players[a].GetHand(firstcard, secondcard);
        }
    }
}

void table::EndRound(){
    for (int a = 0; a < 7; a++){
        if (players[a].ShowName() != ""){
            players[a].RemoveHand();
            players[a].AddRound();
        }
    }
}