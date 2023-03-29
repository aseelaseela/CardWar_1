#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
using namespace std;

class Player{
    public:
        string playerName;
        int cardsTaken;
        int stackSize;
        //to create player with his name
        Player (string pName)
        {
            this->cardsTaken=0;
            this->playerName=pName;
            this->stackSize=0;
        }
        //prints the amount of cards left. should be 21 but can be less if a draw was played
        int stacksize();
        //prints the amount of cards this player has won. 
        int cardesTaken();
        string getName();
};
#endif