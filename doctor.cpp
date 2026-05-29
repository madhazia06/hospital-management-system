#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<windows.h>
#include "doctor.h"
#include "common.h"

using namespace std;

// Displays Main Menu for doctors pannel
void doctorMenu()
{
    int choice;

    do
    {
        clearScreen();
        header("DOCTOR PANEL");
        cout << "1. View Appointments\n";
        cout << "2. Cancel Appointment\n";
        cout << "3. Write Prescription\n";
        cout << "4. View Patient History\n";
        cout << "5. Search Patient\n";
        cout << "6. Daily Schedule\n";
        cout << "7. Add Notes\n";
        cout << "8. View Reports\n";
        cout << "9. Logout\n";

        choice = readInt("Enter choice: ");

        switch(choice)
        {
            case 1:
                viewAppointments();
                pauseScreen();
                break;

            case 2:
                cancelAppointment();
                pauseScreen();
                break;

            case 3:
               writePrescription();
               pauseScreen();
               break;

            case 4:
               viewHistory();
               pauseScreen();
               break;

            case 5:
               searchPatient();
               pauseScreen();
               break;

            case 6:
               dailySchedule();
               pauseScreen();
               break;

            case 7:
               addNotes();
               pauseScreen();
               break;

            case 8:
               viewReports();
               pauseScreen();
               break;

            case 9:
              cout << "\nLogging out";
              for(int i = 0; i < 3; i++)
              {
                cout << ".";
              }
                cout << "\nThank you for using DOCTOR PANNEL of Hospital Management System!\n";
                break;

            default:
                cout << "Feature not added yet!\n";
                pauseScreen();
        }

    } while(choice != 9);
}

// View Appointments Function
void viewAppointments()
{
    header("VIEW APPOINTMENTS");

    ifstream file("appointments.txt");

    int id, priority;
    string name, date, status;

    cout << left
         << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(18) << "Date"
         << setw(15) << "Status"
         << endl;

    cout << "------------------------------------------------------\n";

    while(file >> id >> name >> date >> status >> priority)
    {
        cout << left
             << setw(10) << id
             << setw(15) << name
             << setw(18) << date
             << setw(15) << status
             << endl;
    }

    file.close();
}

// Cancel Appointment Function
void cancelAppointment()
{
    header("CANCEL APPOINTMENT");

    ifstream file("appointments.txt");
    ofstream temp("temp.txt");

    int id, priority, searchID;
    string name, date, status;

    bool found = false;

    searchID=readInt("Enter Patient ID to cancel: ");

    while(file >> id >> name >> date >> status >> priority)
    {
        if(id == searchID)
        {
            status = "Cancelled";
            found = true;

            cout << "\n[SUCCESS] Appointment Cancelled!\n";
        }

        temp << id << " "
             << name << " "
             << date << " "
             << status << " "
             << priority << endl;
    }

    if(found == false)
    {
        cout << "\n[ERROR] Patient ID not found!\n";
    }

    file.close();
    temp.close();

    remove("appointments.txt");
    rename("temp.txt", "appointments.txt");
}

// Write Prescription Function
void writePrescription()
{
    ofstream pres("prescriptions.txt", ios::app);
    ofstream hist("history.txt", ios::app);

    int id;
    string disease, medicine;

    id=readInt("Enter Patient ID: ");

    cout<<"Enter Disease: ";
    cin>>disease;
    cout<<"Enter Medicine: ";
    cin>>medicine;

    pres << id << " " << medicine << endl;

    hist << id << " "
         << disease << " "
         << medicine << endl;

    cout << "\nPrescription Saved!\n";

    pres.close();
    hist.close();
}

// View History Function
void viewHistory()
{
    ifstream file("history.txt");

    int id, searchID;
    string disease, medicine;

    searchID = readInt("Enter Patient ID: ");

    header("PATIENT MEDICAL HISTORY");

    while(file >> id >> disease >> medicine)
    {
        if(id == searchID)
        {
            cout << "Disease: " << disease
                 << " | Medicine: " << medicine << endl;
        }
    }

    file.close();
}

// Search Patient Function
void searchPatient()
{
    header("SEARCH PATIENT");
    ifstream file("patients.txt");

    int id, age, searchID;
    string name;

    bool found = false;

    searchID=readInt("Enter Patient ID: ");

    while(file >> id >> name >> age)
    {
        if(id == searchID)
        {
            cout << "\n--- Patient Found ---\n";

            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;

            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "Patient not found!\n";
    }

    file.close();
}

// Daily Schedule Function
void dailySchedule()
{
    header("DAILY SCHEDULE");
    ifstream file("appointments.txt");

    int id, priority;
    string name, date, status;
    string today;

    today=readStringLine("Enter Date (YYYY-MM-DD): ");

    cout << "\n--- Daily Schedule ---\n";

    while(file >> id >> name >> date >> status >> priority)
    {
        if(date == today && status == "Booked")
        {
            cout << id << " "
                 << name << " "
                 << date << endl;
        }
    }

    file.close();
}

// Add Notes Function
void addNotes()
{
    header("ADD NOTES");
    ofstream file("notes.txt", ios::app);

    int id;
    string note;

    id=readInt("Enter Patient ID: ");

    cin.ignore();

    note=readStringLine("Enter Note: ");

    file << id << " " << note << endl;

    cout << "Note Added Successfully!\n";

    file.close();
}

// View Reports Function
void viewReports()
{
    header("REPORTS");
    ifstream file("appointments.txt");

    int id, priority;

    int total = 0;
    int booked = 0;
    int cancelled = 0;
    int emergency = 0;

    string name, date, status;

    while(file >> id >> name >> date >> status >> priority)
    {
        total++;

        if(status == "Booked")
        {
            booked++;
        }

        if(status == "Cancelled")
        {
            cancelled++;
        }

        if(priority == 1)
        {
            emergency++;
        }
    }

    cout << "Total Appointments: " << total << endl;
    cout << "Booked Appointments: " << booked << endl;
    cout << "Cancelled Appointments: " << cancelled << endl;
    cout << "Emergency Patients: " << emergency << endl;

    file.close();
}