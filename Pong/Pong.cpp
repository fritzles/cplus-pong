/*
CS 120 Final Project
Pong
Jordan Guzak, Michael Fritz, Chris Bracky
*/


#include <vector>

#include "GameObjects.h"

using namespace std;

int main() {

    const bool MOVEMENT_TESTING = false;
    const bool FIELD_TESTING = false;
    const bool COLISION_TESTING = true;
    const bool GAME_MECHANICS_TESTING = false;
    const bool PLAYER_DATA_TESTING = false;

    string endPrgm;
    
    // movement testing
    if (MOVEMENT_TESTING) {
        
        // **************************
        // ball movement
        Ball testBall = Ball();
        cout << "Ball starts at X,Y: " << testBall.getX() << "," << testBall.getY() << endl;

        // check all four clean directional moves
        cout << "\n" << "4 direction Tests:" << endl;
        vector<int> directAngles = { 0, 180, 90, 270 };
        for (int i = 0; i < 4; i++) {
            testBall.setAngle(directAngles[i]);
            testBall.move();
            cout << "Moved at " << testBall.getAngle() << " angle" << endl;
            cout << "  Speed: " << testBall.getSpeed() << endl;
            cout << "  X,Y: " << testBall.getX() << "," << testBall.getY() << endl;
        }

        // check 4 diagonal degree moves
        cout << "\n" << "45 degree diagonal Tests:" << endl;
        vector<int> diagonalAngles = { 45,225, 135, 315 };
        for (int i = 0; i < 4; i++) {
            testBall.setAngle(diagonalAngles[i]);
            testBall.move();
            cout << "Moved at " << testBall.getAngle() << " angle" << endl;
            cout << "  Speed: " << testBall.getSpeed() << endl;
            cout << "  X,Y: " << testBall.getX() << "," << testBall.getY() << endl;
        }

        // speed change tests
        cout << "\n" << "Speed change Tests:" << endl;
        vector<int> speedChange = { 2, 1, 1 };
        vector<int> directionChange = { 0, 180, 180 };
        for (int i = 0; i < 3; i++) {
            testBall.setSpeed(speedChange[i]);
            testBall.setAngle(directionChange[i]);
            testBall.move();
            cout << "Moved at " << testBall.getAngle() << " angle" << endl;
            cout << "  Speed: " << testBall.getSpeed() << endl;
            cout << "  X,Y: " << testBall.getX() << "," << testBall.getY() << endl;
        }


        // **************************
        // paddle movement
        Paddle testPaddle = Paddle();

        cout << "\n" << "Paddle starts at " << testPaddle.getX() << "," << testPaddle.getY() << endl;
        cout << "Move paddle up 1" << endl;
        testPaddle.setDirection(Up);
        testPaddle.move();
        cout << "  Speed: " << testPaddle.getSpeed() << endl;
        cout << "  X,Y: " << testPaddle.getX() << "," << testPaddle.getY() << endl;

        cout << "Move paddle down 1 " << endl;
        testPaddle.setDirection(Down);
        testPaddle.move();
        cout << "  Speed: " << testPaddle.getSpeed() << endl;
        cout << "  X,Y: " << testPaddle.getX() << "," << testPaddle.getY() << endl;

        cout << "Move paddle up 1 with speed 2" << endl;
        testPaddle.setDirection(Up);
        testPaddle.setSpeed(2);
        testPaddle.move();
        cout << "  Speed: " << testPaddle.getSpeed() << endl;
        cout << "  X,Y: " << testPaddle.getX() << "," << testPaddle.getY() << endl;

        cout << "Move paddle down 1 with speed 2" << endl;
        testPaddle.setDirection(Down);
        testPaddle.setSpeed(2);
        testPaddle.move();
        cout << "  Speed: " << testPaddle.getSpeed() << endl;
        cout << "  X,Y: " << testPaddle.getX() << "," << testPaddle.getY() << endl;

        // mover function
        cout << "Move paddle location Test" << endl;
        testPaddle.setPaddleLocation(-100, 0);
        cout << "  X,Y: " << testPaddle.getX() << "," << testPaddle.getY() << endl;

    }

    // field object construction test
    if (FIELD_TESTING) {

        Field testField = Field();
        testField.initalizeBall();
        testField.initalizePaddles();
        
        cout << "Default field size: " << testField.getWidth() << "x" << testField.getHeight() << endl;
        cout << "Ball location: " << testField.ball.getX() << "," << testField.ball.getY() << endl;
        cout << "Left Paddle location: " << testField.leftPaddle.getX() << "," << testField.leftPaddle.getY() << endl;
        cout << "Right Paddle location: " << testField.rightPaddle.getX() << "," << testField.rightPaddle.getY() << endl;

        testField = Field(900, 600);
        testField.initalizeBall();
        testField.initalizePaddles();
        cout << "Custom field size: " << testField.getWidth() << "x" << testField.getHeight() << endl;
        cout << "Ball location: " << testField.ball.getX() << "," << testField.ball.getY() << endl;
        cout << "Left Paddle location: " << testField.leftPaddle.getX() << "," << testField.leftPaddle.getY() << endl;
        cout << "Right Paddle location: " << testField.rightPaddle.getX() << "," << testField.rightPaddle.getY() << endl;


    }

    if (COLISION_TESTING) {
        Field collisionField = Field();
        collisionField.initalizeBall();
        collisionField.ball.setPos(5,2);



    }

    if (GAME_MECHANICS_TESTING) {

    }

    if (PLAYER_DATA_TESTING) {
    
    }

    //cin >> endPrgm;
    cout << "bye" << endl;

    return 0;
}