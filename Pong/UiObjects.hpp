/*
CS 120 Pong Project
UI Objects
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef UI_OBJECTS_H
#define UI_OBJECTS_H

#include <string>
#include "Colors.hpp"
#include "Graphics.hpp"

using namespace std;

class Button
{
public:
    Button() = default;
    Button(string, int, int, int, int);
    ~Button();

    void draw() const;
    void setTextColor(color);
    void setText(string);

    bool hasOverlap(int, int);

private:
    string title;
    int width, height, xPos, yPos;
    color buttonColor, textColor;

};

#endif // !UI_OBJECTS_H
