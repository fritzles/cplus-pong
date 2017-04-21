/*
CS 120 Final Project
Pong: Ball Implementation
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include "Ball.h"

Ball::Ball() {
    xPos = 0;
    yPos = 0;
    speed = 1;
    angle = 0;
    objColor = WHITE;
}

Ball::Ball(double x, double y) {
    xPos = x;
    yPos = y;
    speed = 1;
    angle = 0;
    objColor = WHITE;
}

Ball::Ball(color c) {
    xPos = 0;
    yPos = 0;
    speed = 1;
    angle = 0;
    objColor.r = c.r;
    objColor.g = c.g;
    objColor.b = c.b;
}

Ball::Ball(double x, double y, color c) {
    xPos = x;
    yPos = y;
    speed = 1;
    angle = 0;
    objColor.r = c.r;
    objColor.g = c.g;
    objColor.b = c.b;
}

Ball::~Ball() {

}

/* setters and getters

*/
void Ball::setAngle(int a) {
    if (0 <= a && a < 360) {
        angle = a;
    }
}

void Ball::setSpeed(double s) {
    if (s > 0) {
        speed = s;
    }
}

int Ball::getAngle() const {
    return angle;
}

double Ball::getSpeed() const {
    return speed;
}

void Ball::move() {
    xPos = sin(angle * PI/180) * speed;
    yPos = cos(angle * PI/180) * speed;
}
