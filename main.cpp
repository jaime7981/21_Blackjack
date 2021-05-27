#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include "table.h"
#include "player.h"

using namespace std;
ofstream outputfile;
ifstream inputfile;

string writefile = "players.txt";

table maintable = *new table();

typedef struct Players {
    string playername;
    int playermoney;
    int numberofrounds;
    int roundswin;
} Players;

void print(string writeline){
    cout << writeline << endl;
}

bool CheckNumber(string str){
    for (long unsigned int a = 0; a < str.length(); a++){
        if (isdigit(str[a]) == false){
            return false;
        }
    }
    return true;
}

int GetFileLength(string file){
    inputfile.open((file));
    int filelength = 0;
    string readline;
    while(getline(inputfile, readline)){
        filelength ++;
    }
    inputfile.close();
    return filelength;
}

int ReadFile(Players players[], string file){
    inputfile.open(file);
    int filelength = 0;
    int counter = 0;
    string parameter = "";
    string readline;

    while(getline(inputfile, readline)){
        for (long unsigned int a = 0; a < readline.length(); a++){
            if (readline[a] == *","){
                switch (counter) {
                    case 0:
                        players[filelength].playername = parameter;
                        break;
                    case 1:
                        if (CheckNumber(parameter)){
                            players[filelength].playermoney = stoi(parameter);
                        }
                        else{
                            print("Error: Please check players.txt (money parse error)");
                            return 1;
                        }
                        break;
                    case 2:
                        if (CheckNumber(parameter)){
                            players[filelength].numberofrounds = stoi(parameter);
                        }
                        else{
                            print("Error: Please check players.txt (rounds parse error)");
                            return 1;
                        }
                        break;
                    default:
                        print("Error: Please check players.txt");
                        return 1;
                }
                parameter = "";
                counter ++;
            }
            else{
                parameter += readline[a];
            }
        }

        if (CheckNumber(parameter)){
            players[filelength].roundswin = stoi(parameter);
        }
        else{
            print("Error: Please check players.txt (wins parse error)");
            return 1;
        }

        parameter = "";
        counter = 0;
        filelength ++;
    }

    inputfile.close();
    return 0;
}

int WriteFile(Players players[], string file, int length){
    outputfile.open(file);
    player *aux = new player();
    bool check = true;

    for (int a = 0; a < 7; a++){
        aux = maintable.GetPlayers(a);
        if (aux->ShowName() != ""){
            outputfile << aux->ShowName() + "," + \
                          to_string(aux->ShowMoney()) + "," + \
                          to_string(aux->ShowRoundsPlayed()) + "," + \
                          to_string(aux->ShowRoundsWinned()) + "\n";
        }
    }

    for (int a = 0; a < length; a++){
        for (int b = 0; b < 7; b++){
            aux = maintable.GetPlayers(b);
            if (aux->ShowName() == players[a].playername){
                check = false;
            }
        }
        if (check == true){
            outputfile << players[a].playername + "," + \
                            to_string(players[a].playermoney) + "," + \
                            to_string(players[a].numberofrounds) + "," + \
                            to_string(players[a].roundswin) + "\n";
        }
        check = true;
    }
    
    outputfile.close();
    return 0;
}

bool PlayersBet(){
    string userinput;
    string bet;
    player *roundplayer;
    for (int a = 0; a < 7; a++){
        roundplayer = maintable.GetPlayers(a);
        cout << to_string(a + 1) + ") Name: " + roundplayer->ShowName() + \
                                    " Money: " + to_string(roundplayer->ShowMoney()) << endl;
        print("Options:\n 1) Bet\n 2) Out Of The Round\n 3) Exit Program");
        cin >> userinput;
        if (CheckNumber(userinput)){
            switch (stoi(userinput)) {
                case 1:
                    cin >> bet;
                    if (CheckNumber(bet)){
                        if (roundplayer->ShowMoney() > stoi(bet)){
                            roundplayer->SetBet(stoi(bet));
                            roundplayer->RemoveMoney(stoi(bet));
                        }
                        else {
                            print("Error: Not enought money to bet: Out Of The Round");
                            roundplayer->SetStand(true);
                        }
                    }
                    else {
                        print("Error: Wrong input, not int");
                    }
                    break;
                case 2:
                    roundplayer->SetStand(true);
                    break;
                case 3:
                    return false;
                    break;
                default:
                    break;
            }
        }
        else {
            print("Error: Wrong input, not int");
        }
    }
    return true;
}

void CardRounds(){
    string userinput;
    player *roundplayer;
    bool split = true;
    bool round = true;
    cout << "Name: " + maintable.GetPlayers(8)->ShowName() + " Bet: " + to_string(maintable.GetPlayers(8)->GetBet()) << endl;
    cout << " Card1: " + to_string(maintable.GetPlayers(8)->GetCards(0).GetType()) + " " + to_string(maintable.GetPlayers(8)->GetCards(0).GetNumber()) << endl;
    cout << " Card2: " + to_string(maintable.GetPlayers(8)->GetCards(1).GetType()) + " " + to_string(maintable.GetPlayers(8)->GetCards(1).GetNumber()) << endl;
    cout << "Sum: " + to_string(maintable.GetPlayers(8)->CardSum()) + "\n" << endl;

    for (int a = 0; a < 7; a++){
        roundplayer = maintable.GetPlayers(a);

        cout << to_string(a + 1) + ") Name: " + roundplayer->ShowName() + " Bet: " + to_string(maintable.GetPlayers(a)->GetBet()) << endl;
        cout << "   Card1: " + to_string(roundplayer->GetCards(0).GetType()) + " " + to_string(maintable.GetPlayers(a)->GetCards(0).GetNumber()) << endl;
        cout << "   Card2: " + to_string(roundplayer->GetCards(1).GetType()) + " " + to_string(maintable.GetPlayers(a)->GetCards(1).GetNumber()) << endl;
        cout << "Sum: " + to_string(roundplayer->CardSum()) << endl;
        if (roundplayer->ShowName() != ""){
            while(round){
                if (roundplayer->GetStand() != true){
                    print("Options:\n 1) Ask Card\n 2) Stand");
                    if (split){
                        print("\n3) Split");
                    }
                    cin >> userinput;
                    switch (stoi(userinput)) {
                        case 1:
                            roundplayer->AddCards(maintable.AskForCards());
                            cout << "Sum: " + to_string(maintable.GetPlayers(a)->CardSum()) << endl;
                            break;
                        case 2:
                            roundplayer->SetStand(true);
                            round = false;
                            break;
                        case 3:
                            round = false;
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
}

void Game(){
    bool flag = true;
    maintable.EndRound();

    while (flag) {
        maintable.StartRound();

        flag = PlayersBet();

        CardRounds();
    }
}

int main() {

    int filelength = GetFileLength(writefile);
    Players players[filelength];
    ReadFile(players, writefile);

    bool flag = true;
    string userinput;
    while (flag) {
        print("Options:\n 1) Add Existing Player\n 2) Remove Player\n 3) Create Player\n 4) Show Players\n 5) Start Game\n 6) Exit");
        cin >> userinput;

        if (CheckNumber(userinput)){
            string username;
            string money;

            switch(stoi(userinput)){
                case 1:
                    for (int a = 0; a < filelength; a++){
                        print(to_string(a + 1) + ") Username: " + players[a].playername + 
                        " -> Money: " + to_string(players[a].playermoney) +
                        " -> Winrate: " + to_string(100 * players[a].roundswin / players[a].numberofrounds) + "%");
                    }
                    print("Select a user to sit on the table");
                    cin >> username;
                    if (CheckNumber(username)){
                        for (int a = 0; a < filelength; a++){
                            if (a+1 == stoi(username)){
                                maintable.AddPlayers(players[a].playername, players[a].playermoney, players[a].numberofrounds, players[a].roundswin);
                            }
                        }
                    }
                    break;
                case 2:
                    maintable.ShowPlayers();
                    print("Write the username you want to delete: ");
                    cin >> username;
                    if (CheckNumber(username)){
                        if (maintable.RemovePlayers(stoi(username)) != 0){
                            print("Error: Number out of range");
                        }
                    }
                    break;
                case 3:
                    print("Enter your username: ");
                    cin >> username;
                    print("Enter your money");
                    cin >> money;
                    if(CheckNumber(money)){
                        maintable.AddPlayers(username, stoi(money), 1, 1);
                    }
                    else{
                        print("Error: wrong money input");
                    }
                    break;
                case 4:
                    maintable.ShowPlayers();
                    break;
                case 5:
                    Game();
                    break;
                case 6:
                    WriteFile(players, writefile, filelength);
                    flag = false;
                    break;
                default:
                    print("Error: Input out of range");
                    break;
            }
        }
        else{
            print("Error: Wrong input");
        }
    }
    return 0;
}