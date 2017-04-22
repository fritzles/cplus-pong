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

    /**
    R: 
    M: 
    E: 
    */
    void checkContact();

    /**
    R: ball and field to check for top/bottom collision
    M: none
    E: true for top/bottom collision, false otherwise
    */
    bool ballFieldYTouch(Ball, Field) const;

    /**
    R: ball and field to check for left collision
    M: none
    E: true for left collision, false otherwise
    */
    bool ballFieldTouchLeft(Ball, Field) const;

    /**
    R: ball and field to check for right collision
    M: none
    E: true for right collision, false otherwise
    */
    bool ballFieldTouchRight(Ball, Field) const;

    /**
    R: paddle and field to check for top collision
    M: none
    E: true for top collision, false otherwise
    */
    bool paddleFieldTouchTop(Paddle, Field) const;

    /**
    R: paddle and field to check for bottom collision
    M: none
    E: true for bottom collision, false otherwise
    */
    bool paddleFieldTouchBottom(Paddle, Field) const;

    /**
    R: paddle and ball to check for left collision
    M: none
    E: true for left collision, false otherwise
    */
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
