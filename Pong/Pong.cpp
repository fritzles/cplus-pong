/*
CS 120 Final Project
Pong
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include <iostream>

#include "Field.h"

const bool MOVEMENT_TESTING = true;

int main() {
    
    // movement testing
    if (MOVEMENT_TESTING) {
        Ball testBall = Ball();

        std::cout << "Ball state:" << std::endl;
        std::cout << "  Angle:" << testBall.getAngle() << std::endl;
        std::cout << "  Speed:" << testBall.getSpeed() << std::endl;
        std::cout << "  X, Y:" << testBall.getX() << ", " << testBall.getY() << std::endl;
    }



    return 0;
}