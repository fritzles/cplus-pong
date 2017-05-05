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

// text based testing constants
const bool MOVEMENT_TESTING = false;
const bool FIELD_TESTING = false;
const bool COLISION_TESTING = false;
const bool SCORING_TESTING = false;
const bool SETUP_TESTING = false;
const bool GAME_OVER_TESTING = false;

// graphical game debug constants
const bool GAME_STATE_DEBUG = true;

enum GameState{ Start, Menu, FieldSetup, Play, Pause, GameOver, Settings };

// global variables
GameState currentState;
GLdouble width, height;
int wd, mouseX, mouseY;

color menuTextColor{ 255, 255, 255 };
color green{ 127,255,0 };

Gameplay game;
Player player1, player2;
Field gameField;
Ball gameBall;
Paddle paddle1, paddle2;


void init() {
    width = 700;
    height = 500;

    currentState = Start;
    mouseX = mouseY = -1;

    gameField.initalizePaddles();
    gameField.initalizeBall();
//    gameField.leftPaddle.setcolor(green);
    gameField.ball.setSpeed(.5);
    gameField.ball.diameter = 5;
//    gameField.ball.setAngle(180);
    gameField.rightPaddle.setLength(20);
    gameField.rightPaddle.setWidth(5);
    gameField.leftPaddle.setLength(20);
    gameField.leftPaddle.setWidth(5);
//    gameField.ball.setX(gameField.leftPaddle.getX() + 3);

}

// initialize OpenGL graphics
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0, 0, 1);
}

// **************************
// display helper functions
void displayStart() {
    glColor3f(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        string state = "Start";
        glRasterPos2i(10, height - 10);
        for (int i = 0; i < state.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, state[i]);
        }
    }

    string title = "Welcome to Pong";

    glRasterPos2i(width / 2 + title.length(), height / 2);
    for (int i = 0; i < title.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
    }

    /*
    string message = "Click anywhere to begin";
    glRasterPos2i(width / 2 - title.length() / 2, height / 2 - 10);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    */
}

void displayMenu() {
    glColor3f(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        string state = "Menu";
        glRasterPos2i(10, height - 10);
        for (int i = 0; i < state.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, state[i]);
        }
    }
}

void displayFieldSetup() {
    glColor3f(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        string state = "Field Setup";
        glRasterPos2i(10, height - 10);
        for (int i = 0; i < state.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, state[i]);
        }
    }
}

void displayPlay() {
    glColor3f(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        string state = "Play";
        glRasterPos2i(10, height - 10);
        for (int i = 0; i < state.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, state[i]);
        }
    }
    gameField.leftPaddle.draw();
    gameField.rightPaddle.draw();
    gameField.ball.draw();
    gameField.ball.move();
    gameField.checkCollision();

}

void displayPause() {
    glColor3f(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        string state = "Pause";
        glRasterPos2i(10, height - 10);
        for (int i = 0; i < state.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, state[i]);
        }
    }
    gameField.leftPaddle.draw();
    gameField.rightPaddle.draw();
    gameField.ball.draw();
}

void displayGameOver() {
    glColor3f(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        string state = "Game Over";
        glRasterPos2i(10, height - 10);
        for (int i = 0; i < state.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, state[i]);
        }
    }

    /*
    glColor3f(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    string message = "Game Over";
    glRasterPos2i(220, height / 2);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    */

}

void displaySettings() {
    glColor3f(menuTextColor.r, menuTextColor.g, menuTextColor.b);

    if (GAME_STATE_DEBUG) {
        string state = "Settings";
        glRasterPos2i(10, height - 10);
        for (int i = 0; i < state.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, state[i]);
        }
    }
}

// **************************
// main recalled display function
void display() {
    // for updating
    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // state handling
    switch (currentState)
    {
    case Start:
        displayStart();
        break;
    case Menu:
        displayMenu();
        break;
    case FieldSetup:
        displayFieldSetup();
        break;
    case Play:
        displayPlay();
        break;
    case Pause:
        displayPause();
        break;
    case GameOver:
        displayGameOver();
        break;
    case Settings:
        displaySettings();
        break;
    default:
        break;
    }

    glFlush();
}

// **************************
// cursor and keboard button handlers
void kbd(unsigned char key, int x, int y)
{
    // keboard input controls vary depending
    //  on the current state of the program
    switch (currentState)
    {
    case Start:
        // esc
        if (key == 27) {
            glutDestroyWindow(wd);
            exit(0);
        }
        if (key != 27) {
            currentState = Menu;
        }
        break;
    case Menu:
        // esc
        if (key == 27) {
            glutDestroyWindow(wd);
            exit(0);
        }
        if (key == 32) {
            currentState = Play;
        }
        break;
    case FieldSetup:
        // esc
        if (key == 27) {
            currentState = Menu;
        }
        break;
    case Play:
        // esc and enter for pausing the game
        if (key == 27) {
            currentState = Pause;
        }
        if (key == 32) {
            currentState = Pause;
        }

        // player 1 keyboard inputs
        if (key == 119) {
            gameField.leftPaddle.setDirection(Up);
            gameField.leftPaddle.move();
        }else if (key == 115) {
            gameField.leftPaddle.setDirection(Down);
            gameField.leftPaddle.move();
        }

        // player 2 keyboard inputs

        if(key == 111){
            gameField.rightPaddle.setDirection(Up);
            gameField.rightPaddle.move();
        } else if(key == 108) {
            gameField.rightPaddle.setDirection(Down);
            gameField.rightPaddle.move();
        }

        if(key == 'r') {
            gameField.initalizePaddles();
            gameField.initalizeBall();
        }

        break;
    case Pause:
        // esc and enter for returning the game
        if (key == 27 || key == (unsigned)' ') {
            currentState = Play;
        }
        break;
    case GameOver:
        // any key
        if (key) {
            currentState = Menu;
        }
        break;
    case Settings:
        // esc
        if (key == 27) {
            currentState = Menu;
        }
        break;
    default:
        break;
    }


    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_DOWN:
        gameField.rightPaddle.setDirection(Down);
        gameField.rightPaddle.move();
        break;
    case GLUT_KEY_LEFT:

        break;
    case GLUT_KEY_RIGHT:

        break;
    case GLUT_KEY_UP:
        gameField.rightPaddle.setDirection(Up);
        gameField.rightPaddle.move();
        break;
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {
    switch (currentState)
    {
    case Menu:
        break;
    case FieldSetup:
        break;
    case Play:
        break;
    case GameOver:
        break;
    case Settings:
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    switch (currentState)
    {
    case Start:
        if (state == GLUT_DOWN) { // cursor click
            currentState = Menu;
        }
        break;
    case Menu:
        break;
    case FieldSetup:
        break;
    case Play:
        break;
    case GameOver:
        break;
    case Settings:
        break;
    default:
        break;
    }
    

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { // right click

    }
    glutPostRedisplay();
}

void timer(int extra) {
    
    glutPostRedisplay();
    glutTimerFunc(2, timer, 0);
}

int main(int argc, char** argv) {

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
    } else {
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