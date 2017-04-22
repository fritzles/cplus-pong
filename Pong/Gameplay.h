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

    bool ballFieldYTouch(Ball, Field) const;
    bool ballFieldTouchLeft(Ball, Field) const;
    bool ballFieldTouchRight(Ball, Field) const;
    bool paddleFieldTouchTop(Paddle, Field) const;
    bool paddleFieldTouchBottom(Paddle, Field) const;

    bool paddleBallTouch(Paddle, Ball) const;

    void gameOver();
    void gameStart();
    void score();

private:
    Field field;

    Player player1, player2;
    int player1Score, player2Score;

};


#endif // !GAMEPLAY_H
