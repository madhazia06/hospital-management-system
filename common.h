#ifndef COMMON_H
#define COMMON_H

#include <string>
using namespace std;

void header(string title);
void pauseScreen();
void clearScreen();
void clearInput();

int readInt(string message);
double readDouble(string message);
string readStringLine(string message);

#endif