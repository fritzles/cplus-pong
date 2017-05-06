/*
CS 120 Final Project
Pong
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include <vector>
#include <iostream>

#include "Graphics.hpp"
#include "Gameplay.hpp"
#include "UiObjects.hpp"

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
const bool GAME_STATE_DEBUG = false;
const bool UI_DEBUG = false;

enum GameState{ Start, Menu, FieldSetup, Play, Pause, GameOver, Settings };

enum KeyboardInputMode{ notTyping, typing };

// global variables
GameState currentState;
GLdouble screen_width, screen_height;
int wd, mouseX, mouseY;

color menuTextColor{ 255, 255, 255 };
color menuTextColorHover{ 173, 219, 162 };
color menuButtonColor{ 61, 61, 61 };
color green{ 127,255,0 };

Gameplay game;
Player player1, player2;
bool player1Loaded, player2Loaded;
Field gameField;
Ball gameBall;
Paddle paddle1, paddle2;

Button newGame_b("New Game", 150, 50, 325, 200);
Button quitGame_b("Quit", 150, 50, 325, 350);
Button playGame_b("Play Game", 150, 50, 325, 200);
Button resumeGame_b("Resume Game", 170, 50, 320, 300);
Button mainMenu_b("Main Menu", 170, 50, 320, 550);

Button nameP1_b("Enter Player Name", 190, 50, 55, 250);
Button statsP1_b("", 190, 50, 55, 300);
Button scoreP1_b("", 190, 50, 55, 300);

Button nameP2_b("Enter Player Name", 190, 50, 515, 250);
Button statsP2_b("", 190, 50, 515, 300);
Button scoreP2_b("", 190, 50, 515, 300);

Button winner("", 190, 50, 320, 150);

Button playerStats_b("temp", 170, 50, 320, 550);

KeyboardInputMode keyboardMode;
string keyboardInput;
int selectedTextBox;

void init() {
    screen_width = 800;
    screen_height = 600;

    keyboardMode = notTyping;
    keyboardInput = "";
    selectedTextBox = 0;

    currentState = Start;
    mouseX = mouseY = -1;

    gameField.initalizePaddles();
    gameField.initalizeBall();
    gameField.ball.setSpeed(1);
    gameField.ball.diameter = 10;
    gameField.ball.setAngle(180);
    gameField.rightPaddle.setLength(20);
    gameField.rightPaddle.setWidth(5);
    gameField.leftPaddle.setLength(20);
    gameField.leftPaddle.setWidth(5);
    gameField.leftPaddle.setY(gameField.getHeight()/2);
    newGame_b.setTextColor(menuTextColor);
    quitGame_b.setTextColor(menuTextColor);

    playGame_b.setTextColor(menuTextColor);
    resumeGame_b.setTextColor(menuTextColor);
    mainMenu_b.setTextColor(menuTextColor);
    
    nameP1_b.setTextColor(menuTextColor);
    statsP1_b.setTextColor(menuTextColor);
    scoreP1_b.setTextColor(menuTextColor);

    nameP2_b.setTextColor(menuTextColor);
    statsP2_b.setTextColor(menuTextColor);
    scoreP2_b.setTextColor(menuTextColor);

    player1Loaded = false;
    player2Loaded = false;
    playerStats_b.setTextColor(menuTextColor);

}

// initialize OpenGL graphics
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3ub(0, 0, 1);
}

// **************************
// display helper functions
void displayMouseLocation() {
    string pos = to_string(mouseX) + "," + to_string(mouseY);
    glRasterPos2i(screen_width/2 - pos.length()*4, 30);
    for (unsigned int i = 0; i < pos.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pos[i]);
    }
}

void displayCurrentState(string s) {
    glRasterPos2i(10, 10);
    for (unsigned int i = 0; i < s.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
}

void displayStart() {
    glColor3ub(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        displayCurrentState("Start");
    }

    if (UI_DEBUG) {
        displayMouseLocation();
    }

    string title = "Welcome to Pong";

    glRasterPos2i(screen_width / 2 - title.length()*5, screen_height / 2);
    for (unsigned int i = 0; i < title.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
    }

    /*
    string message = "Click anywhere to begin";
    glRasterPos2i(screen_width / 2 - title.length() / 2, screen_height / 2 - 10);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    */
}

void displayMenu() {
    glColor3ub(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        displayCurrentState("Menu");
    }

    if (UI_DEBUG) {
        displayMouseLocation();
    }

    newGame_b.draw();
    quitGame_b.draw();

}

void displayFieldSetup() {
    glColor3ub(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        displayCurrentState("Field Setup");
    }

    if (UI_DEBUG) {
        displayMouseLocation();
    }
    playGame_b.draw();

    nameP1_b.draw();
    if (player1Loaded) {
        statsP1_b.draw();
    }

    nameP2_b.draw();
    if (player2Loaded) {
        statsP2_b.draw();
    }

    mainMenu_b.draw();

}

void displayPlay() {
    glColor3ub(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        displayCurrentState("Play");
    }

//    displayCurrentState("P1: " + to_string(gameField.leftPaddle.getPoints()) + "   P2: " + to_string(gameField.rightPaddle.getPoints()));

    playerStats_b.setText("P1: " + to_string(gameField.leftPaddle.getPoints()) + "   P2: " + to_string(gameField.rightPaddle.getPoints()));
    playerStats_b.draw();

    if (UI_DEBUG) {
        displayMouseLocation();
    }

    glTranslatef(screen_width / 2 - gameField.getWidth() / 2, screen_height / 2 - gameField.getHeight() + 50, 0.0f);
    gameField.leftPaddle.draw();
    gameField.rightPaddle.draw();
    gameField.ball.draw();
    gameField.ball.move();
    gameField.checkCollision();

    if(gameField.rightPaddle.getPoints() == 5 || gameField.leftPaddle.getPoints() == 5) {
        currentState = GameOver;
    }

}

void displayPause() {
    glColor3ub(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        displayCurrentState("Pause");
    }
    if (UI_DEBUG) {
        displayMouseLocation();
    }
    glTranslatef(screen_width / 2 - gameField.getWidth() / 2, screen_height / 2 - gameField.getHeight() + 50, 0.0f);
    gameField.leftPaddle.draw();
    gameField.rightPaddle.draw();
    gameField.ball.draw();

    glTranslatef(-(screen_width / 2 - gameField.getWidth() / 2), -(screen_height / 2 - gameField.getHeight() + 50), 0.0f);
    resumeGame_b.draw();
}

void displayGameOver() {
    glColor3ub(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    if (GAME_STATE_DEBUG) {
        displayCurrentState("Game Over");
    }

    if (UI_DEBUG) {
        displayMouseLocation();
    }

    string win;
    if (gameField.rightPaddle.getPoints() == 5) {
        win = player2.getName();
    }
    else {
        win = player1.getName();
    }
    win += " wins!";
    winner.setText(win);

    scoreP1_b.setText(to_string(gameField.leftPaddle.getPoints()) + " points");
    scoreP2_b.setText(to_string(gameField.rightPaddle.getPoints()) + " points");

    game.gameOver();


    scoreP1_b.draw();
    scoreP2_b.draw();
    winner.draw();

    mainMenu_b.draw();

    /*
    glColor3ub(menuTextColor.r, menuTextColor.g, menuTextColor.b);
    string message = "Game Over";
    glRasterPos2i(220, screen_height / 2);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    */

}

void displaySettings() {
    glColor3ub(menuTextColor.r, menuTextColor.g, menuTextColor.b);

    if (GAME_STATE_DEBUG) {
        string state = "Settings";
        glRasterPos2i(0, 0);
        for (unsigned int i = 0; i < state.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, state[i]);
        }
    }

    if (UI_DEBUG) {
        displayMouseLocation();
    }


}

// **************************
// main recalled display function
void display() {
    // for updating
    glViewport(0, 0, screen_width, screen_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, screen_width, screen_height, 0.0, -1.f, 1.f);
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

void reshape(int w, int h) {
    if (glutGet(GLUT_SCREEN_WIDTH) != screen_width || glutGet(GLUT_SCREEN_HEIGHT) != screen_height) {
        exit(0);
    }
}

// **************************
// cursor and keboard button handlers
void kbd(unsigned char key, int x, int y) {

    switch (keyboardMode)
    {
    case notTyping:
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
            }
            else if (key == 115) {
                gameField.leftPaddle.setDirection(Down);
                gameField.leftPaddle.move();
            }

            // player 2 keyboard inputs

            if (key == 111) {
                gameField.rightPaddle.setDirection(Up);
                gameField.rightPaddle.move();
            }
            else if (key == 108) {
                gameField.rightPaddle.setDirection(Down);
                gameField.rightPaddle.move();
            }

            if (key == 'r') {
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
        break;
    case typing:
        keyboardInput += key;
        if (selectedTextBox == 1) {
            if (key == 13) {
                player1.loadData(nameP1_b.getText());
                string stats = to_string(player1.getGamesWon()) + "-" + to_string(player1.getGamesLost()) +  " total:" + to_string(player1.getGamesPlayed());
                statsP1_b.setText(stats);
                player1Loaded = true;
            }
            nameP1_b.setText(keyboardInput);
        }
        else if (selectedTextBox == 2) {
            if (key == 13) {
                player2.loadData(nameP2_b.getText());
                string stats = to_string(player2.getGamesWon()) + "-" + to_string(player2.getGamesLost()) + " total:" + to_string(player2.getGamesPlayed());
                statsP2_b.setText(stats);
                player2Loaded = true;
            }
            nameP2_b.setText(keyboardInput);
        }

        if (key == 13 || key == 27) {
            keyboardMode = notTyping;
            break;
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
    mouseX = x;
    mouseY = y;

    switch (currentState)
    {
    case Menu:
        if (newGame_b.hasOverlap(mouseX, mouseY)) {
            newGame_b.setTextColor(menuTextColorHover);
        }
        else {
            newGame_b.setTextColor(menuTextColor);
        }

        if (quitGame_b.hasOverlap(mouseX, mouseY)) {
            quitGame_b.setTextColor(menuTextColorHover);
        }
        else {
            quitGame_b.setTextColor(menuTextColor);
        }

        break;
    case FieldSetup:
        if (playGame_b.hasOverlap(mouseX, mouseY)) {
            playGame_b.setTextColor(menuTextColorHover);
        }
        else {
            playGame_b.setTextColor(menuTextColor);
        }

        if (nameP1_b.hasOverlap(mouseX, mouseY)) {
            nameP1_b.setTextColor(menuTextColorHover);
        }
        else {
            nameP1_b.setTextColor(menuTextColor);
        }

        if (nameP2_b.hasOverlap(mouseX, mouseY)) {
            nameP2_b.setTextColor(menuTextColorHover);
        }
        else {
            nameP2_b.setTextColor(menuTextColor);
        }

        if (mainMenu_b.hasOverlap(mouseX, mouseY)) {
            mainMenu_b.setTextColor(menuTextColorHover);
        }
        else {
            mainMenu_b.setTextColor(menuTextColor);
        }
        break;
    case Play:
        break;
    case Pause:
        if (resumeGame_b.hasOverlap(mouseX, mouseY)) {
            resumeGame_b.setTextColor(menuTextColorHover);
        }
        else {
            resumeGame_b.setTextColor(menuTextColor);
        }
        break;
    case GameOver:
        if (mainMenu_b.hasOverlap(mouseX, mouseY)) {
            mainMenu_b.setTextColor(menuTextColorHover);
        }
        else {
            mainMenu_b.setTextColor(menuTextColor);
        }
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
        // start new game
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && newGame_b.hasOverlap(x,y)) {
            currentState = FieldSetup;
        }

        // exit
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && quitGame_b.hasOverlap(x, y)) {
            exit(0);
        }

        break;
    case FieldSetup:
        // start game
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && playGame_b.hasOverlap(x, y)) {
            currentState = Play;
        }

        // player 1 data
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && nameP1_b.hasOverlap(x, y)) {
            if (keyboardMode == notTyping) {
                keyboardMode = typing;
                selectedTextBox = 1;
                keyboardInput = "";
                nameP1_b.setText("");
            }
            else {
                selectedTextBox = 1;
                keyboardInput = "";
                nameP1_b.setText("");
            }
            player1Loaded = false;
        }

        // load player 2 data
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && nameP2_b.hasOverlap(x, y)) {
            if (keyboardMode == notTyping) {
                keyboardMode = typing;
                selectedTextBox = 2;
                keyboardInput = "";
                nameP2_b.setText("");
            }
            else {
                selectedTextBox = 2;
                keyboardInput = "";
                nameP2_b.setText("");
            }
            player2Loaded = false;
        }

        // main menu
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainMenu_b.hasOverlap(x, y)) {
            currentState = Menu;
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && quitGame_b.hasOverlap(x, y)) {
            currentState = Menu;
        }

        if (state == GLUT_DOWN && (!nameP1_b.hasOverlap(x, y) && !nameP2_b.hasOverlap(x, y) )) {
            keyboardMode = notTyping;
        }

        break;
    case Play:
        break;
    case Pause:
        // resume game
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && resumeGame_b.hasOverlap(x, y-50)) {
            currentState = Play;
        }
        break;
    case GameOver:
        // main menu
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainMenu_b.hasOverlap(x, y)) {
            currentState = Menu;
        }

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

        glutInitWindowSize((int)screen_width, (int)screen_height);
        glutInitWindowPosition(250, 250);

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
        glutDestroyWindow(wd);

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