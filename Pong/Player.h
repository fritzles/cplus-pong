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
    Player();
    ~Player();

    void saveData();

    void loadData(string);

    string getName() const;
    int getGamesPlayed() const;
    int getGamesWon() const;
    int getGamesLost() const;

    void setName(string);
    void setGamesPlayed(int);
    void setGamesWon(int);

    int gamesPlayed;
    int gamesWon;
private:

    string name;

};

#endif // !PLAYER_H
