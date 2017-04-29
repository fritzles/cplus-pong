/*
CS 120 Final Project
Pong
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include <vector>

#include "Graphics.hpp"
#include "Gameplay.hpp"


using namespace std;

// global constants
const bool GRAPHICS_MODE = true;

const bool MOVEMENT_TESTING = false;
const bool FIELD_TESTING = false;
const bool COLISION_TESTING = false;
const bool SCORING_TESTING = false;
const bool SETUP_TESTING = false;
const bool GAME_OVER_TESTING = true;

enum GameState{ Menu, Play  };


// global variables
GLdouble width, height;
int wd;



void init() {
    width = 700;
    height = 500;

}

// initialize OpenGL graphics
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0, 0, 1);
}

// called over and over
void display() {

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);




    glFlush();
}

void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    if (key == 'g') {
        glColor3f(0, 1, 0);
    }

    if (key == 'r') {
        glColor3f(1, 0, 0);
    }


    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_DOWN:

        break;
    case GLUT_KEY_LEFT:

        break;
    case GLUT_KEY_RIGHT:

        break;
    case GLUT_KEY_UP:

        break;
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        
    }
    glutPostRedisplay();
}

void timer(int extra) {
    
    glutPostRedisplay();
    glutTimerFunc(2, timer, 0);
}

int main(int argc, char** argv) {

    string endPrgm;

    // full graphics game
    if (GRAPHICS_MODE) {
        
        init();
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA);

        glutInitWindowSize((int)width, (int)height);
        glutInitWindowPosition(500, 500);

        wd = glutCreateWindow("PONG");

        glutDisplayFunc(display);

        initGL();

        // setup handler functions
        glutKeyboardFunc(kbd);
        glutSpecialFunc(kbdS);
        glutPassiveMotionFunc(cursor);
        glutMouseFunc(mouse);
        glutTimerFunc(0, timer, 0);

        glutMainLoop();
    }
    else {
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
            Gameplay game = Gameplay();
            game.setField(collisionField);
            collisionField.initalizeBall();

            // bottom collision test
            cout << "\nBottom collision Test:" << endl;
            collisionField.ball.setPos(5, 1);
            collisionField.ball.setAngle(270);
            cout << "Collision: " << game.ballFieldYTouch(collisionField.ball, collisionField) << endl;
            collisionField.ball.move();
            cout << "Collision: " << game.ballFieldYTouch(collisionField.ball, collisionField) << endl;

            // top collision test
            cout << "\nTop collision Test:" << endl;
            collisionField.ball.setPos(5, collisionField.getHeight() - 1);
            collisionField.ball.setAngle(90);
            cout << "Collision: " << game.ballFieldYTouch(collisionField.ball, collisionField) << endl;
            collisionField.ball.move();
            cout << "Collision: " << game.ballFieldYTouch(collisionField.ball, collisionField) << endl;

            // left collision test
            cout << "\nLeft collision Test:" << endl;
            collisionField.ball.setPos(1, 5);
            collisionField.ball.setAngle(180);
            cout << "Collision: " << game.ballFieldTouchLeft(collisionField.ball, collisionField) << endl;
            collisionField.ball.move();
            cout << "Collision: " << game.ballFieldTouchLeft(collisionField.ball, collisionField) << endl;

            // right collision test
            cout << "\nRight collision Test:" << endl;
            collisionField.ball.setPos(collisionField.getWidth() - 1, 5);
            collisionField.ball.setAngle(0);
            cout << "Collision: " << game.ballFieldTouchRight(collisionField.ball, collisionField) << endl;
            collisionField.ball.move();
            cout << "Collision: " << game.ballFieldTouchRight(collisionField.ball, collisionField) << endl;

            collisionField.initalizePaddles();
        }

        if (SCORING_TESTING) {
            Gameplay g = Gameplay();
            g.score(0);
            cout << g.getScore() << endl;
            g.score(1);
            cout << g.getScore() << endl;
        }

        if (SETUP_TESTING) {
            Gameplay g2 = Gameplay();
            g2.gameStart();
            cout << g2.field.ball.getX() << "-" << g2.field.ball.getY() << endl;
            cout << g2.field.leftPaddle.getX() << "-" << g2.field.leftPaddle.getY() << endl;
            g2.field.leftPaddle.setX(25);
            cout << g2.field.leftPaddle.getX() << "-" << g2.field.leftPaddle.getY() << endl;
            g2.gameStart();
            cout << g2.field.leftPaddle.getX() << "-" << g2.field.leftPaddle.getY() << endl;
        }

        if (GAME_OVER_TESTING) {
            Gameplay g3 = Gameplay();
            g3.gameStart();
            g3.score(0);
            g3.player1.loadData("jordy");
            cout << g3.player1.getGamesWon() << endl;
            g3.player1.setGamesWon(10);
            cout << g3.player1.getGamesWon() << endl;
            g3.player1.setGamesPlayed(11);
            cout << g3.player1.getGamesPlayed() << endl;
            g3.player2.loadData("micoo");
            g3.gameOver();
            cout << g3.player1.getGamesWon() << endl;
        }
    }

    cout << "bye" << endl;

    return 0;
}