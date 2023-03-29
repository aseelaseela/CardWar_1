#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("1- checking the players names")
{
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.getName()=="Alice");
    CHECK(p2.getName()=="Alice");
}
TEST_CASE("2- there is no name for player 1")
{
    Player p1("");
    Player p2("Bob");
    CHECK_THROWS(Game{p1,p2});
}
TEST_CASE("3- there is no name for the two players")
{
    Player p1("");
    Player p2("");
    CHECK_THROWS(Game{p1,p2});
}
TEST_CASE("4- there is no name for player 2")
{
    Player p1("Alice");
    Player p2("");
    CHECK_THROWS(Game{p1,p2});
}
TEST_CASE("5- checking before starting the game")
{
    Player p1("Alice");
    Player p2("Bob");
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0);
}
TEST_CASE("6- checking initial stack")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==26);
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0);
}
TEST_CASE("7- playing five turns")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i=0;i<5;i++) {
    game.playTurn();
    }
    game.printLastTurn();
    CHECK(p1.stacksize()<=21);
    CHECK(p2.stacksize()<=21);
    bool sumNum=(p1.cardesTaken()+p1.stacksize()+p2.cardesTaken()+p2.stacksize()==52);
    CHECK(sumNum);
}
TEST_CASE("8-cheacking after the play the game untill the end")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playAll();
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
}    
TEST_CASE("9-cheacking if someone won the game")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    game.playAll();
    CHECK(p1.stacksize()==0);
    bool won=(p1.stacksize()==0 && p2.stacksize()==0 && p1.cardesTaken()!=p2.cardesTaken());
    if(won)
    {
        CHECK_THROWS(game.playTurn());
    }
    else CHECK_THROWS(game.printWiner());
    CHECK(won);
}      