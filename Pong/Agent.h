/*
CS 120 Final Project
Pong: Agent Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef AGENT_H
#define AGENT_H

#include "Colors.h"

const static double PI = 3.14159265;

enum Side { Left, Right, Top, Bottom };

class Agent
{
public:
    Agent();
    ~Agent();

    void setcolor(color);
    void setX(double);
    void setY(double);

    color getcolor() const;
    double getX() const;
    double getY() const;

    virtual void move() = 0;

protected:
    double xPos, yPos;
    color objColor;

};

#endif // !AGENT_H
