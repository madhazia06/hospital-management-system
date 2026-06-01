#include<iostream> // Allows input and output using cin and cout
#include<string> // Allows use of the string data type
#include<cstdlib> // Provides system functions (Used here: system("cls"))
#include "common.h" //defined header file for multiple file handling. Includes common function declarations

using namespace std;

// This function displays a formatted heading/title
void header(string title) 
{
    cout << "\n========================================\n";
    cout << "         " << title << endl;
    cout << "========================================\n";
}

// This function clears the console screen
void clearScreen()
{
    system("cls");
}

// This function clears invalid input from cin
// Useful when user enters wrong input, like text instead of number
void clearInput() 
{
    cin.clear(); // Clears the error state of cin
    cin.ignore(1000, '\n'); // Removes leftover input from input buffer
}

// This function pauses the screen until user presses Enter
void pauseScreen() 
{
    cout << "\nPress Enter to continue...";
    cin.get();
}

// This function safely takes integer input from user
int readInt(string message)  
{
    int value;

    while(true)
    {
        cout << message;
        cin >> value;

        // If input is valid integer
        if(!cin.fail())
        {
            clearInput(); //To remove leftover Enter/newline before returning
            return value;
        }

        // If input is invalid
        cout << "Invalid input! Enter number only.\n";
        clearInput();
    }
}

// This function safely takes decimal input from user
double readDouble(string message)
{
    double value;

    while(true)
    {
        cout << message;
        cin >> value;

        // If input is valid decimal number
        if(!cin.fail())
        {
            clearInput();
            return value;
        }

        // If input is invalid
        cout << "Invalid input! Enter valid amount.\n";
        clearInput();
    }
}

// This function takes full-line string input from user
// It can read names with spaces, like "Panadol Extra"
string readStringLine(string message)
{
    string value;
    cout << message;
    getline(cin, value);
    return value;
}