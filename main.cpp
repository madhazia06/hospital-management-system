#include <iostream>
#include <string>
#include <cstdlib>
#include "common.h"
#include "medicine.h"
#include "doctor.h"
#include "admin.h"

using namespace std;

// This function checks login details for different portals
// portalName is used to display the login heading
// correctUser is the correct username
// correctPass is the correct password
bool login(string portalName, string correctUser, string correctPass)
{
    string username, password;
    clearScreen(); // Clears the console screen before showing login page
    header(portalName + " LOGIN"); // Displays login heading, for example: DOCTOR LOGIN


    // Allows the user to try login multiple times
    // NOTE: i <= 3 gives 4 attempts: i = 0, 1, 2, 3
    for (int i=0; i<=3; i++)
    {
        username = readStringLine("Enter Username: ");
        password = readStringLine("Enter Password: ");

        // Checks whether entered username and password are correct
        if(username==correctUser && password==correctPass)
        {
            cout<<"\nLogin Successful!"<<endl;
            pauseScreen(); // Pauses screen so user can read the success message
            return true;
        }
        else
        {
            // Message shown if username or password is wrong
            cout<<"\nWrong username or password!"<<endl;
            cout<<"Attempts left: "<<3-i<<endl;
        }
    }
    cout<<"\nToo many wrong attempts!"<<endl;
    pauseScreen();
    return false;
}

int main()
{
    int choice;
    // Main menu loop
    // This menu keeps showing until the user selects Exit
    do
    {
        clearScreen();
        system("color 0A"); // Changes console text/background color
        header("HOSPITAL MANAGEMENT SYSTEM");

        // Main menu options
        cout << "1. Doctor Portal Login" << endl;
        cout << "2. Admin Portal Login" << endl;
        cout << "3. Medicine Portal Login" << endl;
        cout << "4. Exit" << endl;

        choice=readInt("Enter choice: ");

      
        if(choice==1)
        {
            if(login("DOCTOR", "doctor", "doctor123"))
            {
                system("color 0B"); // Changes console color for doctor portal
                doctorMenu(); // Opens doctor menu after successful login
            }
        }
        else if(choice==2)
        {
            if(login("ADMIN", "admin", "admin123"))
            {
                    P_loadFromFile();
                    D_loadFromFile();
                    system("color 0E");
                    adminMenu();
            }
        }
        else if(choice==3)
        {
            if(login("MEDICINE", "medicine", "med123"))
            {
                system("color 0D"); // Changes console color for medicine portal
                medicineMenu(); // Opens medicine menu after successful login
            }
        }
        else if(choice==4) // If user selects Exit
        {
            cout << "Thank you for using Hospital Management System!" << endl;
            pauseScreen();
        }
        else // If user enters any invalid menu option
        {
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }


    } while (choice!=4); // Repeat menu until user chooses Exit
    
    return 0;
}
