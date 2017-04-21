/*
CS 120 Final Project
Pong: Agent Class
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <math.h>

#include "Colors.h"

const static double PI = 3.14159265;

enum Side { Left, Right, Top, Bottom };

// ***************************
//  Agent
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

// ***************************
//  Ball
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

// ***************************
//  Paddle
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
    int points, length, direction;
    double speed;

};

// ***************************
//  Field
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

    void setLeftPaddle(Paddle);
    void setRightPaddle(Paddle);

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

#endif // !GAME_OBJECTS_H
