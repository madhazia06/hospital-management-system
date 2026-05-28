#include<iostream> //Allows input and output
#include<string> //Allows use of the string data type
#include<cstdlib> //Provides system functions
#include "common.h" //defined header file for multiple file handling
using namespace std;

void header(string title) //Displays a formatted heading/title.
{
    cout << "\n========================================\n";
    cout << "         " << title << endl;
    cout << "========================================\n";
}

void clearScreen() //Clears console
{
    system("cls");
}

void clearInput() //********************************!!!!!!!!!!!!Fixes invalid input problems.
{
    cin.clear();
    cin.ignore(1000, '\n');
}

void pauseScreen() //Stops screen before continuing.
{
    cout << "\nPress Enter to continue...";
    cin.get();
}

int readInt(string message) //********************!!!!!!!!!!!!!!!!!!!Safely takes integer input from user. 
{
    int value;

    while(true)
    {
        cout << message;
        cin >> value;

        if(!cin.fail())
        {
            clearInput();
            return value;
        }

        cout << "Invalid input! Enter number only.\n";
        clearInput();
    }
}

double readDouble(string message) //********************!!!!!!!!!!!!!!!!!!!Safely takes decimal input from user.
{
    double value;

    while(true)
    {
        cout << message;
        cin >> value;

        if(!cin.fail())
        {
            clearInput();
            return value;
        }

        cout << "Invalid input! Enter valid amount.\n";
        clearInput();
    }
}

string readStringLine(string message) //****************!!!!!!!!!!!!!!!!!Takes full-line string input.
{
    string value;
    cout << message;
    getline(cin, value);
    return value;
}