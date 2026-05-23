#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

// Function Prototypes
void menu();
void viewAppointments();
void cancelAppointment();
void writePrescription();
void viewHistory();
void searchPatient();
void dailySchedule();
void addNotes();
void viewReports();

int main()
{
    menu();

    return 0;
}

// MENU FUNCTION
void menu()
{
    int choice;

    do
    {
        cout << "\n===== DOCTOR PANEL =====\n";
        cout << "1. View Appointments\n";
        cout << "2. Cancel Appointment\n";
        cout << "3. Write Prescription\n";
        cout << "4. View Patient History\n";
        cout << "5. Search Patient\n";
        cout << "6. Daily Schedule\n";
        cout << "7. Add Notes\n";
        cout << "8. View Reports\n";
        cout << "9. Logout\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                viewAppointments();
                break;

            case 2:
                cancelAppointment();
                break;

            case 3:
               writePrescription();
               break;

            case 4:
               viewHistory();
               break;

            case 5:
               searchPatient();
               break;

            case 6:
               dailySchedule();
               break;

            case 7:
               addNotes();
               break;

            case 8:
               viewReports();
               break;

            case 9:
                cout << "Logging out...\n";
                break;

            default:
                cout << "Feature not added yet!\n";
        }

    } while(choice != 9);
}

// VIEW APPOINTMENTS
void viewAppointments()
{
    ifstream file("appointments.txt");

    int id, priority;
    string name, date, status;

    cout << "\n--- Appointments ---\n";

    while(file >> id >> name >> date >> status >> priority)
    {
        cout << id << " "
             << name << " "
             << date << " "
             << status << endl;
    }

    file.close();
}

// CANCEL APPOINTMENT
void cancelAppointment()
{
    ifstream file("appointments.txt");
    ofstream temp("temp.txt");

    int id, searchID, priority;
    string name, date, status;

    cout << "Enter ID to cancel: ";
    cin >> searchID;

    while(file >> id >> name >> date >> status >> priority)
    {
        if(id == searchID)
        {
            status = "Cancelled";
            cout << "Appointment Cancelled!\n";
        }

        temp << id << " "
             << name << " "
             << date << " "
             << status << " "
             << priority << endl;
    }

    file.close();
    temp.close();

    remove("appointments.txt");
    rename("temp.txt", "appointments.txt");
}

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

void searchPatient()
{
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

void dailySchedule()
{
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

void addNotes()
{
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

void viewReports()
{
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
