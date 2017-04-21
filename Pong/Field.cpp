/*
CS 120 Final Project
Pong: Field Implementation
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#include "Field.h"

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
        
    }
}

Field::Field(color c) {
    width = DEFAULT_FIELD_WIDTH;
    height = DEFAULT_FIELD_HEIGHT;
}

Field::Field(int w, int h, color c) {

}

Field::~Field() {

}

int Field::getHeight() const
{
    return 0;
}

int Field::getWidth() const
{
    return 0;
}

color Field::getColor() const
{
    return color();
}
