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
    if (ballFieldYTouch(field.ball, field)) {

    }

    if (paddleBallTouch(field.leftPaddle, field.ball)) {

    }

    if (paddleBallTouch(field.rightPaddle, field.ball)) {

    }

    if (ballFieldTouchLeft(field.ball, field)) {

    }

    if (ballFieldTouchRight(field.ball, field)) {

    }
}

bool Gameplay::ballFieldYTouch(Ball b, Field f) const {
    if (b.getY() <= 0) {
        return true;
    }

    if (b.getY() >= f.getHeight()) {
        return true;
    }

    return false;
}

bool Gameplay::ballFieldTouchLeft(Ball b, Field f) const {
    if (b.getX() - b.diameter <= 0) {
        return true;
    }

    return false;
}

bool Gameplay::ballFieldTouchRight(Ball b, Field f) const {
    if (b.getX() + b.diameter > f.getWidth()) {
        return true;
    }

    return false;
}

bool Gameplay::paddleFieldTouchTop(Paddle p, Field f) const {
    if (p.getY() + p.getLength() / 2 >= f.getHeight()) {
        return true;
    }
    return false;
}

bool Gameplay::paddleFieldTouchBottom(Paddle p, Field f) const {
    if (p.getY() - p.getLength() / 2 <= 0) {
        return true;
    }
    return false;
}

bool Gameplay::paddleBallTouch(Paddle p, Ball b) const {
    // x check
    if (p.getX() + p.getWidth() >= b.getX() - b.diameter) {
        // y check
        if (p.getY() + p.getLength() / 2 >= b.getY() - b.diameter && p.getY() - p.getLength() / 2 <= b.getY() + b.diameter ) {
            return true;
        }
    } else if (p.getX() - p.getWidth() >= b.getX() - b.diameter) {
        // y check
        if (p.getY() + p.getLength() / 2 >= b.getY() - b.diameter && p.getY() - p.getLength() / 2 <= b.getY() + b.diameter) {
            return true;
        }
    }
    return false;
}
