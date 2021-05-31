#include "player.h"
#include "card.h"
#include <string>

player::player(string Username, int Money, int RoundsPlayed, int RoundsWinned){
    username = Username;
    money = Money;
    roundsplayed = RoundsPlayed;
    roundswinned = RoundsWinned;
    win = false;
    stand = false;
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
    int newmoney;
    roundsplayed ++;
    if (win){
        roundswinned ++;
        newmoney = bet*multiplier;
        AddMoney(newmoney);
    }
    win = false;
    stand = false;
    multiplier = 0;
    bet = 0;
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
    cout << " Card: " + to_string(newcard.GetType()) + " " + to_string(newcard.GetNumber()) << endl;
    extracardcounter ++;
}

void player::RemoveHand(){
    startingcards[0].EraseCard();
    startingcards[1].EraseCard();
    for (int a = 0; a < 5; a++){
        extracard[a].EraseCard();
    }
    extracardcounter = 0;
}

card player::GetCards(int num){
    return startingcards[num];
}

void player::EmptyExtraCards(){
    for (int a = 0; a < 5; a++){
        extracard[a].EraseCard();
    }
}

int player::CardSum(){
    int sum = 0;
    int aux = 0;
    int as = 0;
    int num;
    for (int a = 0; a < 2; a++){
        num = startingcards[a].GetNumber();
        //cout << to_string(num) << endl;
        if (num == 1){
            as ++;
        }
        else if (num == 11 || num == 12 || num == 13) {
            sum += 10;
        }
        else{
            sum += num;
        }
    }
    for (int a = 0; a < 5; a++){
        if (extracard[a].GetNumber() != 0){
            num = extracard[a].GetNumber();
            //cout << to_string(num) << endl;
            if (num == 1){
                as ++;
            }
            else if (num == 11 || num == 12 || num == 13) {
                sum += 10;
            }
            else{
                sum += num;
            }
        }
    }
    for (int a = 0; a < as; a++){
        aux = sum + 11;
        sum += 1;
        if (aux <= 21){
            sum = aux;
        }
        else if (sum > 21) {
            return sum; //pierde
        }
    }
    return sum;
}

int player::CalculateHand(){
    return 0;
}

bool player::GetWin(){
    return win;
}

void player::SetWin(bool state){
    win = state;
}

int player::GetBet(){
    return bet;
}

void player::SetBet(int Bet){
    bet = Bet;
}

int player::GetMultiplier(){
    return multiplier;
}

void player::SetMultiplier(int Mult){
    multiplier = Mult;
}

bool player::GetStand(){
    return stand;
}

void player::SetStand(bool Stand){
    stand = Stand;
}