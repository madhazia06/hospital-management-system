#include <iostream>
#include <string>
#include <cstdlib>
#include "common.h"
#include "medicine.h"
#include "doctor.h"

using namespace std;

bool login(string portalName, string correctUser, string correctPass)
{
    string username, password;
    clearScreen();
    header(portalName + " LOGIN");

    for (int i=0; i<=3; i++)
    {
        username = readStringLine("Enter Username: ");
        password = readStringLine("Enter Password: ");

        if(username==correctUser && password==correctPass)
        {
            cout<<"\nLogin Successful!"<<endl;
            pauseScreen();
            return true;
        }
        else
        {
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
    system("color 0A");
    //loadFromFile();
    int choice;
    do
    {
        clearScreen();
        header("HOSPITAL MANAGEMENT SYSTEM");

        //cout << "1. Admin Login" << endl;
        cout << "1. Doctor Portal Login" << endl;
        cout << "2. Admin Portal Login" << endl;
        cout << "3. Medicine Portal Login" << endl;
        cout << "4. Exit" << endl;

        choice=readInt("Enter choice: ");

      
        if(choice==1)
        {
            if(login("DOCTOR", "doctor", "doctor123"))
            {
                system("color 0B");
                doctorMenu();
            }
        }
 /*       else if(choice==2)
        {
            if(login("ADMIN", "admin", "admin123"))
            {
                PatientMenu();
            }
        }*/
        else if(choice==3)
        {
            if(login("MEDICINE", "medicine", "med123"))
            {
                system("color 0D");
                medicineMenu();
            }
        }
        else if(choice==4)
        {
            cout << "Thank you for using Hospital Management System!" << endl;
            pauseScreen();
        }
        else
        {
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }


    } while (choice!=4);
    
    return 0;
}
