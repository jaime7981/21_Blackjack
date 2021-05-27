#include "player.h"

player::player(string Username, int Money, int RoundsPlayed, int RoundsWinned){
    username = Username;
    money = Money;
    roundsplayed = RoundsPlayed;
    roundswinned = RoundsWinned;
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

void player::ChangeName(string Username){
    username = Username;
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
    extracard = newcard;
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