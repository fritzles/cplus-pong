/*
CS 120 Final Project
Pong: Gameplay Implementation
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include "Gameplay.h"

Gameplay::Gameplay() {

}

Gameplay::~Gameplay() { }

void Gameplay::setField()
{
}

void Gameplay::setField(Field) {

}

void Gameplay::checkContact() {

}

/**
R: ball and field to check for top/bottom collision
M: none
E: true for top/bottom collision, false otherwise
*/
bool Gameplay::ballFieldYTouch(Ball b, Field f) const {
    if (b.getY() <= 0) {
        return true;
    }

    if (b.getY() >= f.getHeight()) {
        return true;
    }

    return false;
}

/**
R: ball and field to check for left collision
M: none
E: true for left collision, false otherwise
*/
bool Gameplay::ballFieldTouchLeft(Ball b, Field f) const {
    if (b.getX() - b.diameter <= 0) {
        return true;
    }

    return false;
}

/**
R: ball and field to check for right collision
M: none
E: true for right collision, false otherwise
*/
bool Gameplay::ballFieldTouchRight(Ball b, Field f) const {
    if (b.getX() + b.diameter > f.getWidth()) {
        return true;
    }

    return false;
}

/**
R: paddle and field to check for top collision
M: none
E: true for top collision, false otherwise
*/
bool Gameplay::paddleFieldTouchTop(Paddle p, Field f) const {
    if (p.getY() + p.getLength()/2 >= f.getHeight()) {
        return true;
    }
    return false;
}

/**
R: paddle and field to check for bottom collision
M: none
E: true for bottom collision, false otherwise
*/
bool Gameplay::paddleFieldTouchBottom(Paddle p, Field f) const {
    if (p.getY() - p.getLength()/2 <= 0) {
        return true;
    }
    return false;
}

/**
R: paddle and ball to check for left collision
M: none
E: true for left collision, false otherwise
*/
bool Gameplay::paddleBallTouch(Paddle p, Ball b) const {

    return false;
}
