/*
CS 120 Pong Project
UI Objects
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include "UiObjects.hpp"

Button::Button(string n, int w, int h , int x, int y) {
    title = n;
    width = w;
    height = h;
    xPos = x;
    yPos = y;
    buttonColor = color{ 0, 0, 0 };
    textColor = color{ 255, 255, 255 };
}

Button::~Button() { }

void Button::draw() const {

    // draw box
    glBegin(GL_QUADS);
    glColor3ub(buttonColor.r, buttonColor.g, buttonColor.b);
    glVertex2i(xPos, yPos);
    glVertex2i(xPos, yPos + height);
    glVertex2i(xPos + width, yPos + height);
    glVertex2i(xPos + width, yPos);
    glEnd();

    // draw text
    glColor3ub(textColor.r, textColor.g, textColor.b);
    glRasterPos2i(xPos + 10, yPos + 20);
    for (unsigned int i = 0; i < title.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
    }

}

void Button::setTextColor(color c) {
    textColor.r = c.r;
    textColor.g = c.g;
    textColor.b = c.b;
}

bool Button::hasOverlap(int x, int y) {
    if (x >= xPos && x <= xPos + width && y >= yPos && y <= yPos + height ) {
        return true;
    }
    return false;
}

void Button::setText(string s) {
    title = s;
}

string Button::getText() const {
    return title;
}
