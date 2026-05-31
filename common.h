#ifndef COMMON_H
#define COMMON_H

// This header file contains common helper function declarations.
// These functions are used in different files of the project.

#include <string>
using namespace std;

// Displays a formatted heading
void header(string title);
// Pauses the screen until user presses Enter
void pauseScreen();
// Clears the console screen
void clearScreen();
// Clears invalid input from cin
void clearInput();
// Safely reads integer input
int readInt(string message);
// Safely reads decimal/double input
double readDouble(string message);
// Reads full line string input
string readStringLine(string message);

#endif