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

#include "Colors.hpp"

const static double PI = 3.14159265;

enum PaddleDirection { Up, Down };
enum ContactSide { Left, Right, Top, Bottom };

class Paddle;

// ***************************
//  Agent
class Agent
{
public:
    Agent();
    ~Agent();

    // setters
    void setcolor(color);
    void setX(double);
    void setY(double);

    // getters
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
    double  diameter;
    Ball();

    /**
    R: diameter
    M:
    E:
    */
    Ball(double);

    /**
    R: diameter and color
    M:
    E:
    */
    Ball(double, color);
    ~Ball();

    // setters
    void setAngle(int);
    void setSpeed(double);
    void setPos(int, int);

    // getters
    int getAngle() const;
    double getSpeed() const;

    virtual void move() override;

    void draw() const;

    void isOverlapping(const Paddle &);


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

    /**
    R: length, x, y
    M:
    E:
    */
    Paddle(int, double, double);

    /**
    R: length, x, y, color
    M:
    E:
    */
    Paddle(int, double, double, color);
    ~Paddle();

    // setters
    void setPaddleLocation(int, int);
    void setDirection(PaddleDirection);
    void setSpeed(double);

    // getters
    int getPoints() const;
    int getLength() const;
    int getWidth() const;
    double getSpeed() const;

    virtual void move() override;

    void draw() const;

private:
    int points, length, width;
    PaddleDirection direction;
    double speed;

};

// ***************************
//  Field
class Field
{
public:
    Paddle leftPaddle;
    Paddle rightPaddle;
    Ball ball;

    Field();

    /**
    R: width, height
    M: none
    E: none
    */
    Field(int, int);
    
    /**
    R: width, height, color
    M: none
    E: none
    */
    Field(int, int, color);

    ~Field();

    // setters
    // make and place ball on field
    void initalizePaddles();
    void initalizePaddles(Paddle, Paddle);

    // make and place ball on field
    void initalizeBall();
    void initalizeBall(Ball);

    // getters
    int getHeight() const;
    int getWidth() const;
    color getColor() const;

    void checkCollision();


private:
    int height, width;
    color fieldColor;

    int DEFAULT_FIELD_HEIGHT = 400;
    int DEFAULT_FIELD_WIDTH = 600;

};

#endif // !GAME_OBJECTS_H
