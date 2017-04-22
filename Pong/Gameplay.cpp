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

bool Gameplay::ballFieldYCollision(Ball b, Field f) {
    if (b.getY() <= 0) {
        return true;
    }

    if (b.getY() >= f.getHeight()) {
        return true;
    }

    return false;
}

bool Gameplay::ballFieldCollisionLeft(Ball b, Field f) {
    if (b.getX() <= 0) {
        return true;
    }

    if (b.getX() >= f.getWidth()) {
        return true;
    }

    return false;
}

bool Gameplay::ballFieldCollisionRight(Ball b, Field f) {
    if (b.getX() <= 0) {
        return true;
    }

    if (b.getX() >= f.getWidth()) {
        return true;
    }

    return false;
}

bool Gameplay::paddleFieldCollision(Paddle, Field) {
    return false;
}

bool Gameplay::paddleBallCollision(Paddle, Ball) {
    return false;
}
