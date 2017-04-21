/*
CS 120 Final Project
Pong: Ball Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef BALL_H
#define BALL_H

#include "Agent.h"

class Ball : public Agent
{
public:
    Ball();
    Ball(int, int);
    Ball(color);
    Ball(int, int, color);
    ~Ball();

    virtual void move() override;

private:
    int angle, speed;

};

#endif // !BALL_H
