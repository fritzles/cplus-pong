/*
CS 120 Final Project
Pong: Gameplay Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GameObjects.h"
#include "Player.h"

class Gameplay
{
public:
    Gameplay();
    ~Gameplay();

    // setters
    void setField();
    void setField(Field);

    void checkContact();

    bool ballFieldYCollision(Ball, Field);
    bool ballFieldCollisionLeft(Ball, Field);
    bool ballFieldCollisionRight(Ball, Field);
    bool paddleFieldCollision(Paddle, Field);
    bool paddleBallCollision(Paddle, Ball);

    void gameOver();
    void gameStart();
    void score();

private:
    Field field;

    Player player1, player2;

};


#endif // !GAMEPLAY_H
