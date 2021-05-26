#include "card.h"

card::card(int Number, int Type){
    number = Number;
    Type = Type;
}

void card::EraseCard(){
    number = 0;
    type = 0;
}

int card::GetNumber(){
    return number;
}

int card::GetType(){
    return type;
}