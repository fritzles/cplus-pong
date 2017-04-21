/*
CS 120 Final Project
Pong: Agent Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef AGENT_H
#define AGENT_H

struct color
{
    int r;
    int g;
    int b;
};

class Agent
{
public:
    Agent();
    ~Agent();

    void setcolor(color);
    void setX(int);
    void setY(int);

    color getcolor() const;
    int getX() const;
    int getY() const;

    virtual void move() = 0;

protected:
    int xPos, yPos;
    color objColor;

};

#endif // !AGENT_H
