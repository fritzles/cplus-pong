/*
CS 120 Pong Project
Graphics Handlers
Jordan Guzak, Michael Fritz, Chris Bracky
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
//#include <GL\glut.h> // not sure why visual studio hates the capital letter folder
#endif

void init(void);

// *************************************
// Callback functions for GLUT 

// Draw the window - this is where all the GL actions are
void display(void);

// Called when window is resized,
// also when window is first created,
// before the first call to display().
void reshape(int w, int h);

// Refresh the display, called when system is idle
void refresh(void);

// Trap and process keyboard events
void kbd(unsigned char key, int x, int y);

// Handle cursor move events 
void cursor(int x, int y);

// Handle cursor move with button press events
void drag(int x, int y);

// Handle cursor button press and releas events
void mouse(int button, int state, int x, int y);

int graphicsPlay(int argc, char *argv[]);

#endif /* graphics_h */
