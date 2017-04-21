/*
CS 120 Final Project
Pong: Agent Implementation
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include "GameObjects.h"

// ***************************
//  Agent

Agent::Agent() {
    xPos = 0;
    yPos = 0;
    objColor.r = 255;
    objColor.g = 255;
    objColor.b = 255;
}

Agent::~Agent() { }

/** Setters and Getters

*/
void Agent::setcolor(color c) {
    objColor.r = c.r;
    objColor.g = c.g;
    objColor.b = c.b;
}

void Agent::setX(double x) {
    xPos = x;
}

void Agent::setY(double y) {
    yPos = y;
}

color Agent::getcolor() const {
    return objColor;
}

double Agent::getX() const {
    return xPos;
}

double Agent::getY() const {
    return yPos;
}

// ***************************
//  Ball

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
    xPos = sin(angle * PI / 180) * speed;
    yPos = cos(angle * PI / 180) * speed;
}

// ***************************
//  Paddle
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
        yPos += 1 * speed;
    }
    else {
        yPos -= 1 * speed;
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

// ***************************
//  Field
Field::Field() {
    width = DEFAULT_FIELD_WIDTH;
    height = DEFAULT_FIELD_HEIGHT;
    fieldColor = BLACK;
}

Field::Field(int w, int h) {
    if (w > 0 && h > 0) {
        width = w;
        height = h;
    }
    else {
        width = DEFAULT_FIELD_WIDTH;
        height = DEFAULT_FIELD_HEIGHT;
    }
    fieldColor = BLACK;

}

Field::Field(color c) {
    width = DEFAULT_FIELD_WIDTH;
    height = DEFAULT_FIELD_HEIGHT;
}

Field::Field(int w, int h, color c) {

}

Field::~Field() {

}

void Field::setLeftPaddle(Paddle p) {
    leftPaddle = p;
}

void Field::setRightPaddle(Paddle p) {
    rightPaddle = p;
}

int Field::getHeight() const {
    return height;
}

int Field::getWidth() const {
    return width;
}

color Field::getColor() const {
    return fieldColor;
}
