#include "player.hpp"
    //prints the amount of cards left. should be 21 but can be less if a draw was played
    int Player :: stacksize()
    {
        return this->stackSize;
    }
    //prints the amount of cards this player has won. 
    int Player :: cardesTaken()
    {
        return this->cardsTaken;
    }
    string Player :: getName()
    {
        return this->playerName;
    }