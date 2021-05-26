#ifndef _PLAY
#define _PLAY
#include <string>
using namespace std;

class player{
private:
    string username;
    int money;
    int roundsplayed;
    int roundswinned;
public:
    player(){};
    player(string, int, int, int);
    void AddMoney(int);
    void RemoveMoney(int);
    int ShowMoney();
    void AddRound(bool);
    int ShowRoundsPlayed();
    int ShowRoundsWinned();
};

#endif