#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"

using namespace std;
ofstream outputfile;
ifstream inputfile;

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

int GetFileLength(){
    inputfile.open(("players.txt"));
    int filelength = 0;
    string readline;
    while(getline(inputfile, readline)){
        filelength ++;
    }
    inputfile.close();
    return filelength;
}

int ReadFile(Players players[]){
    inputfile.open("players.txt");
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

int WriteFile(){
    return 0;
}

int main() {

    int filelength = GetFileLength();
    Players players[filelength];
    ReadFile(players);

    bool flag = true;
    string userinput;
    while (flag) {
        print("Options:\n 1) Add Existing Player\n 2) Remove Player\n 3) Create Player\n 4) Start Game\n 5) Exit");
        cin >> userinput;

        if (CheckNumber(userinput)){
            switch(stoi(userinput)){
                case 1:
                    //struct info
                    for (int a = 0; a < filelength; a++){
                        print(to_string(a + 1) + ") Username: " + players[a].playername + 
                        " -> Money: " + to_string(players[a].playermoney) +
                        " -> Winrate: " + to_string(100 * players[a].roundswin / players[a].numberofrounds) + "%");
                    }
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
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