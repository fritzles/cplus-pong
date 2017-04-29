/*
CS 120 Final Project
Pong: Player Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/


#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
public:
    //constructor/destructor
    Player();
    ~Player();

    //saves data, requires a player to load data first, puts save data into file
    void saveData();

    //loads data, if the file exists, import the data. else, create one
    void loadData(string);

    //Get the thing in the function name
    string getName() const;
    int getGamesPlayed() const;
    int getGamesWon() const;
    //calculated by taking gamesplayed-gameswon
    int getGamesLost() const;

    //set the thing in the function name
    void setName(string);
    void setGamesPlayed(int);
    void setGamesWon(int);

private:
    //these are variables
    string name;
    int gamesPlayed;
    int gamesWon;
};

#endif // !PLAYER_H
