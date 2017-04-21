/*
CS 120 Final Project
Pong: Field Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef FIELD_H
#define FIELD_H

#include "Colors.h"
#include "Paddle.h"
#include "Ball.h"
#include "Player.h"


int DEFAULT_FIELD_HEIGHT = 400;
int DEFAULT_FIELD_WIDTH = 600;

class Field
{
public:
    Field();
    Field(int, int);
    Field(color);
    Field(int, int, color);

    ~Field();

    void setLeftPlayer(Player);
    void setRightPlayer(Player);

    int getHeight() const;
    int getWidth() const;
    color getColor() const;


private:
    int height, width;
    color fieldColor;

    Paddle leftPaddle;
    Paddle rightPaddle;

    Ball ball;

};


#endif // !FIELD_H
