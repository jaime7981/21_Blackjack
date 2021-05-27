#include "player.h"

player::player(string Username, int Money, int RoundsPlayed, int RoundsWinned){
    username = Username;
    money = Money;
    roundsplayed = RoundsPlayed;
    roundswinned = RoundsWinned;
    win = false;
    extracardcounter = 0;
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

void player::ChangeName(string Username){
    username = Username;
}

string player::ShowName(){
    return username;
}

void player::AddRound(){
    roundsplayed ++;
    if (win){
        roundswinned ++;
    }
    win = false;
}

int player::ShowRoundsPlayed(){
    return roundsplayed;
}
int player::ShowRoundsWinned(){
    return roundswinned;
}

void player::GetHand(card firstcard, card secondcard){
    startingcards[0] = firstcard;
    startingcards[1] = secondcard;
}

void player::AddCards(card newcard){
    extracard[extracardcounter] = newcard;
    extracardcounter ++;
}

void player::RemoveHand(){
    startingcards[0].EraseCard();
    startingcards[1].EraseCard();
    for (int a = 0; a < extracardcounter; a++){
        extracard[extracardcounter].EraseCard();
    }
    extracardcounter = 0;
}

int player::CalculateHand(){
    return 0;
}

bool player::GetWin(){
    return win;
}

void player::ChangeWin(bool state){
    win = state;
}