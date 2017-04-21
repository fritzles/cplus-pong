/*
CS 120 Final Project
Pong: Ball Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef BALL_H
#define BALL_H

#include <math.h>

#include "Agent.h"


class Ball : public Agent
{
public:
    Ball();
    Ball(double, double);
    Ball(color);
    Ball(double, double, color);
    ~Ball();

    void setAngle(int);
    void setSpeed(double);

    int getAngle() const;
    double getSpeed() const;

    virtual void move() override;

private:
    int angle;
    double speed;

};

#endif // !BALL_H
