/*
CS 120 Final Project
Pong: Player Implementation
Jordan Guzak, Michael Fritz, Chris Bracky
*/


#include "Player.h"

#include <iostream>
#include <fstream>


Player::Player() : name(""), gamesPlayed(0), gamesWon(0) {
}

Player::~Player() {
}

void Player::saveData() {
    if(name != "") {
        fstream player;
        player.open(name + ".txt", fstream::out | fstream::trunc);
        player << gamesWon << " " << gamesPlayed;
    }else{
        cout << "You must first select a player." << endl;
    }
}

void Player::loadData(string playerName) {
    name = playerName;

    fstream player;
    string filename = playerName + ".txt";
    player.open(filename);

    // If file does not exist, Create new file
    if ( !player )
    {
        player.open(filename,  fstream::in | fstream::out | fstream::trunc);
        player << gamesWon << " " << gamesPlayed;
        player.close();

    } else {    // use existing file
        int test, test2;
        player >> gamesWon;
        player >> gamesPlayed;
        player.close();
    }
}

string Player::getName() const{
    return name;
}

int Player::getGamesPlayed() const{
    return gamesPlayed;
}

int Player::getGamesWon() const{
    return gamesWon;
}

int Player::getGamesLost() const{
    return gamesPlayed - gamesWon;
}

void Player::setName(string name){
    loadData(name);
}

void Player::setGamesPlayed(int games){
    gamesPlayed = games;
}

void Player::setGamesWon(int games){
    gamesWon = games;
}
