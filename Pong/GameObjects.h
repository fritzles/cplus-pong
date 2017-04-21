/*
CS 120 Final Project
Pong: Game Object Classes
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

#include "Colors.h"


//color BLACK = color{ 0, 0, 0 };
//color WHITE(255, 255, 255 );

const static double PI = 3.14159265;

enum PaddleDirection { Up, Down };
enum ContactSide { Left, Right, Top, Bottom };

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
    Ball(double, double, double);
    Ball(double, double, double, color);
    ~Ball();

    void setAngle(int);
    void setSpeed(double);

    int getAngle() const;
    double getSpeed() const;

    virtual void move() override;

private:
    int angle;
    double speed, diameter;

};

// ***************************
//  Paddle
class Paddle : public Agent
{
public:
    Paddle();
    Paddle(int, double, double);
    Paddle(int, double, double, color);
    ~Paddle();

    virtual void move() override;

    void setPaddleLocation(int, int);
    void setDirection(PaddleDirection);
    void setSpeed(double);

    int getPoints() const;
    int getLength() const;
    double getSpeed() const;

private:
    int points, length;
    PaddleDirection direction;
    double speed;

};

// ***************************
//  Field
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

    int DEFAULT_FIELD_HEIGHT = 400;
    int DEFAULT_FIELD_WIDTH = 600;

};

#endif // !GAME_OBJECTS_H
