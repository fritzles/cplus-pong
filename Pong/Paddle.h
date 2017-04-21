/*
CS 120 Final Project
Pong: Paddle Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef PADDLE_H
#define PADDLE_H

#include "Agent.h"

class Paddle : public Agent
{
public:
    Paddle();
    Paddle(int);
    ~Paddle();

    virtual void move() override;

    void setPaddleLocation(int, int);

    int getPoints() const;
    int getLength() const;

private:
    int points, length;

};

#endif // !PADDLE_H
