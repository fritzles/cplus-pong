/*
CS 120 Final Project
Pong
Jordan Guzak, Michael Fritz, Chris Bracky
*/


#include <vector>

#include "GameObjects.h"

using namespace std;

int main() {

    const bool MOVEMENT_TESTING = true;
    const bool COLISION_TESTING = false;
    const bool GAME_MECHANICS_TESTING = false;
    const bool PLAYER_DATA_TESTING = false;

    string endPrgm;
    
    // movement testing
    if (MOVEMENT_TESTING) {
        
        /*
        // ball movement
        Ball testBall = Ball();
        cout << "Ball Starts at (X, Y):" << testBall.getX() << ", " << testBall.getY() << endl;

        // check all four clean directional moves
        cout << " " << endl;
        vector<int> directAngles = { 0, 180, 90, 270 };
        for (int i = 0; i < 4; i++) {
            testBall.setAngle(directAngles[i]);
            testBall.move();
            cout << "Moved at " << testBall.getAngle() << " angle" << endl;
            cout << "  Speed: " << testBall.getSpeed() << endl;
            cout << "  X, Y: " << testBall.getX() << ", " << testBall.getY() << endl;
        }

        // check 4 diagonal degree moves
        cout << " " << endl;
        vector<int> diagonalAngles = { 45,225, 135, 315 };
        for (int i = 0; i < 4; i++) {
            testBall.setAngle(diagonalAngles[i]);
            testBall.move();
            cout << "Moved at " << testBall.getAngle() << " angle" << endl;
            cout << "  Speed: " << testBall.getSpeed() << endl;
            cout << "  X, Y: " << testBall.getX() << ", " << testBall.getY() << endl;
        }


        */

    }

    if (COLISION_TESTING) {

    }

    if (GAME_MECHANICS_TESTING) {

    }

    if (PLAYER_DATA_TESTING) {

    }

    //cin >> endPrgm;
    cout << "bye" << endl;

    return 0;
}