/*
CS 120 Final Project
Pong: Paddle Implementation
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include "Paddle.h"

Paddle::Paddle() {
    points = 0;
    length = 10;

}

Paddle::Paddle(int l) {
    points = 0;
    length = l;
}

Paddle::~Paddle() {

}

void Paddle::move() {
    if (direction == 1) {
        yPos += 1*speed;
    }
    else {
        yPos -= 1*speed;
    }
}

void Paddle::setPaddleLocation(int x, int y) {
    xPos = x;
    yPos = y;
}

int Paddle::getPoints() const {
    return points;
}

int Paddle::getLength() const {
    return length;
}
