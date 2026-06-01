#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<windows.h>
using namespace std;

// Main Function
int main()
{
    system("color 0B");

    menu();

    return 0;
}

// Function to display formatted section headers
void header(string title)
{
    cout << "\n========================================\n";
    cout << "         " << title << endl;
    cout << "========================================\n";
}

// Function to pause screen until user presses Enter
void pauseScreen()
{
    cin.ignore(1000, '\n');

    cout << "\nPress Enter to continue...";
    cin.get();
}

// Function to change text color
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Displays Main Menu for doctors pannel
void menu()
{
    int choice;

    do
    {
       system("cls");
       header("DOCTOR PANEL");
        cout << "1. View Appointments\n";
        cout << "2. Cancel Appointment\n";
        cout << "3. Write Prescription\n";
        cout << "4. View Patient History\n";
        cout << "5. Search Patient\n";
        cout << "6. Daily Schedule\n";
        cout << "7. Add Notes\n";
        cout << "8. View Reports\n";
        cout << "9. Doctor Profile\n";
        cout << "10. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

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
               doctorProfile();
               pauseScreen();
               break;

            case 10:
              cout << "\nLogging out";
              for(int i = 0; i < 3; i++)
              {
                cout << ".";
              }
                cout << "\nThank you for using DOCTOR PANNEL !\n";
                break;

            default:
                cout << "Feature not added yet!\n";
        }

    } while(choice != 10);
}

// View Appointments Function
void viewAppointments()
{
    header("VIEW APPOINTMENTS");
    ifstream file("appointments.txt");
    if(!file)
   {
    cout << "File not found!\n";
    return;
   }
    int id, priority;
    string name, date, status;
    int total = 0;

    cout << left
         << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(18) << "Date"
         << setw(15) << "Status"
         << endl;

    cout << "------------------------------------------------------\n";

    // SHOW LEGEND ONLY ONCE
    setColor(14);
    cout << "[Yellow = Emergency Patient]\n";

    setColor(12);
    cout << "[Red = Cancelled Appointment]\n\n";


    while(file >> id >> name >> date >> status >> priority)
    {
       cout << left
     << setw(10) << id
     << setw(15) << name
     << setw(18) << date;

     if(status == "Cancelled")
      {
        setColor(12); // Red
      }
     else
      {
        setColor(11); // Aqua
      }

     cout << setw(15) << status;
     setColor(11);

     if(priority == 1 && status != "Cancelled")
      {
       setColor(14);
       cout << " [EMERGENCY]";
       setColor(11);
      }
      total++;
      cout << endl;
    }
    cout << "\nTotal Appointments: " << total << endl;
    file.close();
}

// Function to cancel appointment
void cancelAppointment()
{
    header("CANCEL APPOINTMENT");

    ifstream file("appointments.txt");
    ofstream temp("temp.txt");

    int id, priority, searchID;
    string name, date, status;

    bool found = false;

    cout << "Enter Patient ID to cancel: ";
    cin >> searchID;

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
        cout << "\n[ERROR] Patient not found!\n";
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

    cout << "Enter Patient ID: ";
    cin >> id;

    cout << "Enter Disease: ";
    cin >> disease;

    cout << "Enter Medicine: ";
    cin >> medicine;

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

    cout << "Enter Patient ID: ";
    cin >> searchID;

    cout << "\n===== PATIENT HISTORY =====\n";

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

    cout << "Enter Patient ID: ";
    cin >> searchID;

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

    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> today;

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

    cout << "Enter Patient ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Note: ";
    getline(cin, note);

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

    cout << "\n===== REPORTS =====\n";

    cout << "Total Appointments: " << total << endl;
    cout << "Booked Appointments: " << booked << endl;
    cout << "Cancelled Appointments: " << cancelled << endl;
    cout << "Emergency Patients: " << emergency << endl;

    file.close();
}

// Function to display doctor profile
void doctorProfile()
{
    header("DOCTOR PROFILE");

    cout << "Doctor ID      : D101\n";
    cout << "Doctor Name    : Dr. Ahmad\n";
    cout << "Specialization : Cardiologist\n";
    cout << "Room Number    : 12\n";
    cout << "Experience     : 5 Years\n";
    cout << "Available Days : Mon - Fri\n";
    cout << "Timing         : 10 AM - 5 PM\n";
}
