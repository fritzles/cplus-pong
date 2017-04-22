/*
CS 120 Final Project
Pong: Gameplay Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GameObjects.h"

class Gameplay
{
public:
    Gameplay();
    ~Gameplay();

    // setters
    void setField();
    void setField(Field);

    void checkContact();

    bool ballFieldCollision(Ball, Field);
    bool paddleFieldCollision(Paddle, Field);
    bool paddleBallCollision(Paddle, Ball);

private:
    Field field;

};


#endif // !GAMEPLAY_H
