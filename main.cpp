#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"

using namespace std;
ofstream outputfile;
ifstream inputfile("players.txt");

typedef struct Players {
    string playername;
    int playermoney;
    int numberofrounds;
    int roundswin;
} Players;

int ReadFile(){
    return 0;
}

int WriteFile(){
    return 0;
}

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

int main() {

    int filelength = 0;
    string readline;
    string parameter = "";
    while(getline(inputfile, readline)){
        for (long unsigned int a = 0; a < readline.length(); a++){
            if (readline[a] == *","){
                print(parameter);
                parameter = "";
            }
            else{
                parameter += readline[a];
            }
        }
        parameter = "";
        filelength ++;
    }
    print(to_string(filelength));
    /*
    Players *loadedplayers[filelength];

    while(getline(inputfile, readline)){
        cout << readline;
    }
    for (int a = 0; a < filelength; a++){
        loadedplayers[a]->playername;
    }
    */

    bool flag = true;
    string userinput;

    while (flag) {
        print("Options:\n 1) Add Player\n 2) Remove Player\n 3) Start Game\n 4) Exit");
        cin >> userinput;

        if (CheckNumber(userinput)){
            switch(stoi(userinput)){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
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