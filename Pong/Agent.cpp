/*
CS 120 Final Project
Pong: Agent Implementation
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include "Agent.h"

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

void Agent::setX(int x) {
    xPos = x;
}

void Agent::setY(int y) {
    yPos = y;
}

color Agent::getcolor() const {
    return objColor;
}

int Agent::getX() const {
    return xPos;
}

int Agent::getY() const {
    return yPos;
}
