#include "player.h"

player::player(string Username, int Money, int RoundsPlayed, int RoundsWinned){
    username = Username;
    money = Money;
    roundsplayed = RoundsPlayed;
    roundswinned = RoundsWinned;
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

void player::AddRound(bool check){
    roundsplayed ++;
    if (check){
        roundswinned ++;
    }
}