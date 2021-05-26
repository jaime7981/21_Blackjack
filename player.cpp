#include "player.h"

player::player(string Username, int Money){
    username = Username;
    money = Money;
    roundsplayed = 0;
    roundswinned = 0;
    win = false;
}

void player::AddMoney(int Money){
    money += Money;
}

void player::RemoveMoney (int Money){
    money -= Money;
}

int player::ShowMoney(){
    return money;
}

string player::ShowName(){
    return username;
}

void player::AddRound(bool check){
    roundsplayed ++;
    if (check){
        roundswinned ++;
    }
}

void player::GetHand(card firstcard, card secondcard){
    startingcards[0] = firstcard;
    startingcards[1] = secondcard;
}

void player::AddCards(card newcard){

}

void player::RemoveHand(){
    startingcards[0].EraseCard();
    startingcards[1].EraseCard();
    extracard.EraseCard();
}

bool player::GetWin(){
    return win;
}

void player::ChangeWin(bool state){
    win = state;
}