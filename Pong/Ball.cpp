/*
CS 120 Final Project
Pong: Ball Implementation
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include "Ball.h"

Ball::Ball() {
    xPos = 0;
    yPos = 0;
    objColor = WHITE;
}

Ball::Ball(int x, int y) {
    xPos = x;
    yPos = y;
    objColor = WHITE;
}

Ball::Ball(color c) {
    xPos = 0;
    yPos = 0;
    objColor.r = c.r;
    objColor.g = c.g;
    objColor.b = c.b;
}

Ball::Ball(int x, int y, color c) {
    xPos = x;
    yPos = y;
    objColor.r = c.r;
    objColor.g = c.g;
    objColor.b = c.b;
}

Ball::~Ball() {

}

void Ball::move() {

}
