#include "table.h"
#include <string>
#include <ctime>

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
    if (num == 8){
        return &dealer;
    }
    else if (num < 8 && num >= 0){
        return &players[num];
    }
    return NULL;
}

void table::ShowDeck(){
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
            decknumber = rand() % 4;
            firstcard = maindeck[decknumber].GiveCard();
            decknumber = rand() % 4;
            secondcard = maindeck[decknumber].GiveCard();

            players[a].GetHand(firstcard, secondcard);
            for (int a = 0; a < 5; a++){
                
            }
        }
        
        players[a].EmptyExtraCards();
    }
    decknumber = rand() % 4;
    firstcard = maindeck[decknumber].GiveCard();
    decknumber = rand() % 4;
    secondcard = maindeck[decknumber].GiveCard();

    dealer.GetHand(firstcard, secondcard);
}

card table::AskForCards(){
    int decknumber = rand() % 4;
    return maindeck[decknumber].GiveCard();
}

void table::EndRound(){
    for (int a = 0; a < 7; a++){
        if (players[a].ShowName() != ""){
            players[a].RemoveHand();
            players[a].AddRound();
        }
    }
    dealer.RemoveHand();
}