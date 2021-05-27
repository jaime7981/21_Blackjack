#ifndef _CARD
#define _CARD

class card{
private:
    int number;
    int type;

public:
    card() {};
    card(int, int);
    int GetNumber();
    int GetType();

    void SetNumber(int);
    void SetType(int);

    void EraseCard();
};

#endif