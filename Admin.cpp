#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include "admin.h"
#include "common.h"
using namespace std;

int patientID[100];
string patientName[100];
int patientAge[100];
string patientDisease[100];
string patientHitory[100];
int totalPatient = 0;
int doctorID[25];
string doctorName[25];
int totalDoctors=0;
int doctorSalary[25];
string doctorField[25];
//============================================================DATA SAVE TO PATIENT FILE===========================================================
void P_saveToFile()
{
    ofstream outFile("patients_data.txt"); 
    
    if(!outFile) {
        cout << "Error: File couldn't open" << endl;
        return;
    }
    outFile << totalPatient << endl;
    
    for(int i = 0; i<totalPatient && i<100; i++)
    {
        outFile << patientID[i] << endl;
        outFile << patientName[i] << endl;
        outFile << patientAge[i] << endl;
        outFile << patientDisease[i] << endl;
        outFile << patientHitory[i] << endl;
        outFile <<"==============================================  "<<i+1<<"  =========================================="<<endl;

    }
    outFile.close(); 
}
//============================================================DATA SAVE TO DOCTOR FILE
void D_saveToFile()
{
    ofstream outFile("doctors_data.txt"); // 
    
    if(!outFile) {
        cout << "Error: File couldn't open" << endl;
        return;
    }
    outFile << totalDoctors << endl;
    for(int i = 0; i < totalDoctors && i<25; i++)
    {
        outFile << doctorID[i] << endl;
        outFile << doctorName[i] << endl;
        outFile << doctorSalary[i] << endl;
        outFile << doctorField[i] << endl;
        outFile <<"==============================================  "<<i+1<<"  =========================================="<<endl;
    }
    outFile.close(); 
}

//====================================================LOAD DATA FROM PATIENT FILE=============================================================
void P_loadFromFile()
{
    ifstream inFile("patients_data.txt");
    
    if(!inFile) {
        return; 
    }
    inFile >> totalPatient; 
    if(totalPatient > 100)
    {
        totalPatient = 100;
    }
    string dummyLine;
    for(int i = 0; i < totalPatient; i++)
    {
        inFile >> patientID[i];
        inFile.ignore();

        getline(inFile, patientName[i]);
        
        inFile >> patientAge[i];
        inFile.ignore();
        
        getline(inFile, patientDisease[i]);
        getline(inFile, patientHitory[i]);
        getline(inFile, dummyLine);
    }
    inFile.close();
}
//====================================================LOAD DATA FROM DOCTOR FILE
void D_loadFromFile()
{
    ifstream inFile("doctors_data.txt");    
    if(!inFile) 
    {
        return; 
    }
    inFile >> totalDoctors; 

    if(totalDoctors > 25)
    {
        totalDoctors = 25;
    }

    string dummyLine;
    for(int i = 0; i < totalDoctors; i++)
    {
        inFile >> doctorID[i];
        inFile.ignore(); 

        getline(inFile, doctorName[i]);
        
        inFile >> doctorSalary[i];
        inFile.ignore();
        
        getline(inFile, doctorField[i]);
        getline(inFile, dummyLine);

    }
    inFile.close();
}

//===========================================================ADD PATIENT RECORD======================================================
void addPatient()
{
    header("Add Patient Record");
    if(totalPatient>=100)
    {
        cout << "Hospital's capacity is full"<<endl;
        return;
    }
    
    patientID[totalPatient]=totalPatient+1;
    patientName[totalPatient] = readStringLine("Enter patient name: ");
    patientAge[totalPatient] = readInt("Enter age of patient: ");
    
    while(patientAge[totalPatient]<=0 || patientAge[totalPatient]>200)
    { 
        cout <<"Kindly enter valid patient age."<<endl;
        patientAge[totalPatient] = readInt("Enter age of patient: ");
    }
    
    patientDisease[totalPatient] = readStringLine("Enter disease of patient: ");
    patientHitory[totalPatient] = readStringLine("Enter history of patient: ");
    
    totalPatient++;
    P_saveToFile();
    cout << "Patient's record add successfully to file!" << endl;
}
//===========================================================ADD DOCTOR RECORD=======================================================
void addDoctor()
{
    header("Add Doctor Record");
    if(totalDoctors>=25)
    {
        cout << "Hospital's capacity is full."<<endl;
        return ;
    }
    
    doctorID[totalDoctors] = totalDoctors + 1;

    doctorName[totalDoctors] = readStringLine("Enter doctor name: ");

    doctorSalary[totalDoctors] = readInt("Enter salary of the doctor (PKR): ");

    while(doctorSalary[totalDoctors] <= 0)
    {
        cout << "Kindly enter valid doctor salary." << endl;
        doctorSalary[totalDoctors] = readInt("Enter salary of the doctor: ");
    }

    doctorField[totalDoctors] = readStringLine("enter field of the doctor : ");

    totalDoctors++;
    D_saveToFile();
    cout << "Doctor's record added successfully to file." << endl;
}

//=================================================DISPLAY ALL PATIENTS=====================================================================
void displayAllPatients()
{
    header("Display All Patients");
    if(totalPatient==0)
    {
        cout << "There is no patient in the hospital."<<endl;
        return;
    }
    cout <<"\n ======================================================"<<endl;
    cout << "Records of all patients in the hospital."<<endl;
    for(int i=0; i<totalPatient; i++)
    {
        cout << "\nPatient No.: "  <<i+1 <<endl;
        cout <<"ID: " <<patientID[i] <<endl;
        cout << "Name: " <<patientName[i] << endl;
        cout << "Age: " << patientAge[i] <<endl;
        cout << "Disease: " <<patientDisease[i] <<endl;
        cout << "History: " <<patientHitory[i] <<endl;
        cout << "----------------------------------------" <<endl;

    }
}
//=================================================DISPLAY ALL DOCTORS======================================================================
void displayAllDoctors()
{
    header("Display All Doctors");
    if(totalDoctors==0)
    {
        cout << "There is no doctor working in the hospital."<<endl;
        return;
    }
    cout <<"\n ======================================================"<<endl;
    cout << "Records of all doctors in the hospital"<<endl;
    for(int i=0; i<totalDoctors; i++)
    {
        cout << "\nDoctor No.: "  <<i+1 <<endl;
        cout <<"ID: " <<doctorID[i] <<endl;
        cout << "Name: " <<doctorName[i] << endl;
        cout << "Salary: " << doctorSalary[i] << endl;
        cout << "Field: " <<doctorField[i] <<endl;
        cout << "----------------------------------------" <<endl;

    }
}

//=========================================================VIEW PATIENT HISTORY==============================================================
void viewPatientHistory()
{
    header("View Patient History");
    if(totalPatient==0)
    {
        cout << "There is no patient record in the hospital to search."<<endl;
        return ;
    }
    int searchID = readInt("Enter ID of the patient to view history: ");
    bool found = false;
    
    for(int i=0; i<totalPatient; i++)
    {
        if(patientID[i]==searchID)
        {
            cout <<"=======================" <<endl;
            cout << "Patient ID Found!" <<endl;
            cout <<"ID: " <<patientID[i] <<endl;
            cout << "Name: " <<patientName[i] << endl;
            cout << "Age: " << patientAge[i] <<endl;
            cout << "Disease: " <<patientDisease[i] <<endl;
            cout << "History: " <<patientHitory[i] <<endl;
            found = true;
            break;
        }
    }
    if(found==false)
    {
        cout << "History/Record of ID " <<searchID << " not found!"<<endl;
    }
}
//=========================================================vIEW DOCTOR HISTORY===============================================================
void viewDoctorHistory()
{
    header("View Doctor History");
    if(totalDoctors==0)
    {
        cout << "There is no doctor record in the hospital to search."<<endl;
        return;
    }
    int searchID = readInt("Enter ID of the doctor to view doctor's history: ");
    bool found = false;

    for(int i=0; i<totalDoctors; i++)
    {
        if(doctorID[i]==searchID)
        {
            cout <<"=======================" <<endl;
            cout << "Doctor ID Found!" <<endl;
            cout <<"ID: " << doctorID[i] <<endl;
            cout << "Name: " << doctorName[i] << endl;
            cout << "Salary: " << doctorSalary[i] <<endl;
            cout << "Field: " << doctorField[i] << endl;
            
            found = true;
            break;
        }
    }
    if(found==false)
    {
        cout << "History/Record of ID " <<searchID << " not found!"<<endl;
    }
}

//======================================================SEARCH PAATIENT BY ID==========================================================================
void searchPatientById()
{
    header("Search Patient by ID");
    if(totalPatient==0)
    {
        cout << "There is no patient record in the hospital to search."<<endl;
        return ;
    }
    int searchID = readInt("Enter ID of the patient to search: ");
    bool found = false;
    
    for(int i=0; i<totalPatient; i++)
    {
        if(patientID[i]==searchID)
        {
            cout <<"=======================" <<endl;
            cout << "patient ID Found!" <<endl;
            cout <<"ID: " <<patientID[i] <<endl;
            cout << "Name: " <<patientName[i] << endl;
            cout << "Age: " << patientAge[i] <<endl;
            cout << "Disease: " <<patientDisease[i] <<endl;
            cout << "History: " <<patientHitory[i] <<endl;
            found = true;
            break;
        }
    }
    if(found==false)
    {
        cout << "Record of ID " <<searchID << " not found!"<<endl;
    }
}
//=========================================================SEARCH DOCTOR BY ID===============================================================
void searchDoctorById()
{
    header("Search Doctor by ID");
    if(totalDoctors==0)
    {
        cout << "There is no doctor record in the hospital to search."<<endl;
        return;
    }
    int searchID = readInt("Enter ID of the doctor to search: ");
    bool found = false;
    
    for(int i=0; i<totalDoctors; i++)
    {
        if(doctorID[i]==searchID)
        {
            cout <<"=======================" <<endl;
            cout << "Doctor ID Found!" <<endl;
            cout <<"ID: " << doctorID[i] <<endl;
            cout << "Name: " << doctorName[i] << endl;
            cout << "Salary: " << doctorSalary[i] <<endl;
            cout << "Field: " << doctorField[i] << endl;
            found = true;
            break;
        }
    }
    if(found==false)
    {
        cout << "Record of ID " <<searchID << " not found!"<<endl;
    }
}
//=======================================================SEARCH PATIENT BY NAME========================================================================

void searchPatientByName()
{
    header("Search Patient by Name");
    if(totalPatient == 0)
    {
        cout << "There is no patient record in the hospital." << endl;
        return;
    }
    string searchName = readStringLine("Enter patient name to search: ");
    bool found = false;
    
    cout << "\n================ Search Results ================" << endl;
    for(int i = 0; i < totalPatient; i++)
    {
        if(patientName[i] == searchName)
        {
            cout << "Patient Found at Index " << i + 1 << endl;
            cout << "ID      : " << patientID[i] << endl;
            cout << "Name    : " << patientName[i] << endl;
            cout << "Age     : " << patientAge[i] << endl;
            cout << "Disease : " << patientDisease[i] << endl;
            cout << "History : " << patientHitory[i] << endl;
            cout << "----------------------------------------" << endl;
            found = true;
        }
    }
    
    if(!found)
    {
        cout << "There is no patient named " <<searchName <<"." << endl;
    }
}
//=======================================================SEARCH DOCTOR BY NAME=========================================================================
void searchDoctorByName()
{
    header("Search Doctor by Name");
    if(totalDoctors == 0)
    {
        cout << "There is no doctor record in the hospital." << endl;
        return;
    }
    string searchName = readStringLine("Enter Doctor Name to search: ");
    bool found = false;
    
    cout << "\n================ Search Results ================" << endl;
    
    for(int i = 0; i < totalDoctors; i++)
    {
        if(doctorName[i] == searchName)
        {
            cout << "Patient Found at Index " << i + 1 << endl;
            cout << "ID      : " << doctorID[i] << endl;
            cout << "Name    : " << doctorName[i] << endl;
            cout << "Salary  : " <<doctorSalary[i] <<endl;
            cout << "Field   : " <<doctorField[i] <<endl;
            cout << "----------------------------------------" << endl;
            found = true;
        }
    }
    
    if(!found)
    {
        cout << "There is no doctor named " <<searchName <<"." << endl;
    }
}

//=============================================REMOVE PATIENT RECORD===================================================================
void removePatient()
{
    header("Remove Patient Record");
    if(totalPatient==0)
    {
        cout <<"There is no patient record in the hospital to delete." <<endl;
        return;
    }
    
    int deleteID = readInt("Enter patient ID to remove: ");
    int foundIndex=-1;
    
    for(int i=0; i<totalPatient; i++)
    {
        if(patientID[i]==deleteID)
        {
            foundIndex=i;
            break;
        }
    }
    if(foundIndex==-1)
    {
        cout << "There is no Patient having ID " <<deleteID <<endl;
        return ;
    }
    for(int i=foundIndex; i<totalPatient-1; i++)
    {
        patientID[i] = patientID[i + 1];
        patientName[i] = patientName[i + 1];
        patientAge[i] = patientAge[i + 1];
        patientDisease[i] = patientDisease[i + 1];
        patientHitory[i] = patientHitory[i + 1];
    }
    totalPatient--;
    P_saveToFile();
    cout<<"Patient's record deleted successfully."<<endl;
}
//=============================================REMOOVE DOCTOR RECORD===================================================================
void removeDoctor()
{
    header("Remove Doctor Record!");
    if(totalDoctors==0)
    {
        cout <<"There is no doctor record in the hospital to delete." <<endl;
        return;
    }
    int deleteID = readInt("Enter Doctor ID to remove: ");
    int foundIndex=-1;

    for(int i=0; i<totalDoctors; i++)
    {
        if(doctorID[i]==deleteID)
        {
            foundIndex=i;
            break;
        }
    }
    if(foundIndex==-1)
    {
        cout << "There is no doctor having ID " <<deleteID <<endl;
        return ;
    }

    for(int i=foundIndex; i<totalDoctors-1; i++)
    {
        doctorID[i] = doctorID[i + 1];
        doctorName[i] = doctorName[i + 1];
        doctorSalary[i] = doctorSalary[i + 1];
        doctorField[i] = doctorField[i + 1];
    }
    totalDoctors--;
    D_saveToFile();
    cout<<"Doctor's record deleted successfully!"<<endl;
}
//=============================================UPDATE PATIENT RECORD=====================================================================

void updatePatientRecord() 
{
    header("UPDATE PATIENT RECORD");
    
    if(totalPatient == 0)
    {
        cout << "There is no patient record in the hospital to update!" << endl;
        return;
    }
    int id = readInt("Enter Patient ID to update: ");

    bool found = false;
    for (int i = 0; i < totalPatient; i++) {
        if (patientID[i] == id) {
            found = true;
            
            cout << "\nCurrent Details:" << endl;
            cout << "Name: " << patientName[i] << " | Disease: " << patientDisease[i] << endl;
            cout << "\nEnter New Details:" << endl;
            patientName[i] = readStringLine("Enter New Name: ");
            patientAge[i] = readInt("Enter New Age: ");
            while(patientAge[i] <= 0 || patientAge[i] > 200)
            {
                cout << "Kindly enter valid patient age." << endl;
                patientAge[i] = readInt("Enter New Age: ");
            }
            patientDisease[i] = readStringLine("Enter New Disease: ");
            patientHitory[i] = readStringLine("Enter New History: ");
            
            P_saveToFile();

            cout << "\nPatient record updated successfully and saved to file!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "\nError: Patient with ID " << id << " not found.\n";
    }
}
//================================================UPDATE DOCTOOR RECORD====================================================================
void updateDoctorRecord() 
{
    header("UPDATE DOCTOR RECORD");
    
    if(totalDoctors == 0)
    {
        cout << "There is no doctor record in the hospital to update!" << endl;
        return;
    }

    int id = readInt("Enter Doctor ID to update: ");

    bool found = false;

    for (int i = 0; i < totalDoctors; i++) {
        if (doctorID[i] == id) 
        {
            found = true;

            cout << "\nCurrent Details:" << endl;
            cout << "Name: " << doctorName[i] << " | Field: " << doctorField[i] << " | Salary: " << doctorSalary[i] << endl;

            cout << "\nEnter New Details:" << endl;

            doctorName[i] = readStringLine("Enter New Name: ");
            doctorField[i] = readStringLine("Enter New Field/Specialization: ");

            doctorSalary[i] = readInt("Enter New Salary: ");

            while(doctorSalary[i] <= 0)
            {
                cout << "Kindly enter valid doctor salary." << endl;
                doctorSalary[i] = readInt("Enter New Salary: ");
            }

            D_saveToFile();

            cout << "\nDoctor record updated successfully and saved to file!" << endl;
            break;
        }
    }
    if (!found) 
    {
        cout << "\nError: Doctor with ID " << id << " not found.\n";
    }
}
//=================================================DEARCH PATIENT BY DISEASE=====================================================================

void searchPatientsByDisease() 
{
    header("SEARCH PATIENTS BY DISEASE");
    if(totalPatient == 0)
    {
        cout << "There is no patient record in the hospital!" << endl;
        return;
    }

    string disease = readStringLine("Enter Disease Name to search: ");

    bool found = false;
    cout << "\nMatching Patients:\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < totalPatient; i++) 
    {
        if (patientDisease[i] == disease) 
        {
            cout << "ID: " << patientID[i] 
                 << " | Name: " << patientName[i] 
                 << " | Age: " << patientAge[i] << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No patients found suffering from " << disease << ".\n";
    }
}
//=================================================SEARCH DOCTOR BY FIELD=====================================================================
void searchDoctorByField() 
{
    header("SEARCH DOCTORS BY FIELD");
    
    if(totalDoctors == 0)
    {
        cout << "There is no doctor record in the hospital!" << endl;
        return;
    }

    string field = readStringLine("Enter Specialization/Field to search: ");
    bool found = false;
    cout << "\nMatching Doctors:\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < totalDoctors; i++) 
    {
        if (doctorField[i] == field) 
        {
            cout << "ID : " << doctorID[i] 
                 << " | Name : " << doctorName[i] 
                 << " | Salary : Rs. " << doctorSalary[i] << "\n";
            found = true;
        }
    }
}
//==================================================VIEW HOSPITAL STATISTICS=====================================================================

void viewHospitalStatistics() 
{
    header("HOSPITAL STATISTICS");
    cout << "Total Registered Patients: " << totalPatient << " / 100\n";
    cout << "Total Active Doctors:      " << totalDoctors << " / 25\n";
    cout << "------------------------------------\n";
    int totalSalarySpent = 0;
    for(int i = 0; i < totalDoctors; i++) {
        totalSalarySpent += doctorSalary[i];
    }
    cout << "Total Monthly Budget for Doctors Salary: Rs. " << totalSalarySpent << "\n";
    cout << "====================================\n";
}
//==========================================================UPDATE DOCTOR SALARY=======================================================================

void updateDoctorSalary() 
{
    header(" UPDATE DOCTOR SALARY");
    if(totalDoctors == 0)
    {
        cout << "There is no doctor record in the hospital to update salary!" << endl;
        return;
    }

    int id = readInt("Enter Doctor ID to update salary: ");
    bool found = false;
    for (int i = 0; i < totalDoctors; i++) {
        if (doctorID[i] == id) 
        {
            found = true;
            cout << "\nCurrent Salary of Dr. " << doctorName[i] << " is: Rs. " << doctorSalary[i] << "\n";
            doctorSalary[i] = readInt("Enter new salary: ");
            
            while(doctorSalary[i] <= 0)
            {
                cout << "Kindly enter valid doctor salary." << endl;
                doctorSalary[i] = readInt("Enter new salary: ");
            }

            D_saveToFile();
            cout << "\nSalary updated successfully and saved to file.\n";
            break;
        }
    }
    if (!found) {
        cout << "\nError: Doctor with ID " << id << " not found.\n";
    }
}
//===========================================================HOPITAL PAYROLL===========================================================================

void hospitalPayrollReport() 
{
    header("HOSPITAL PAYROLL REPORT");
    if (totalDoctors == 0) {
        cout << "No doctors registered to generate payroll.\n";
        return;
    }

    cout << left << setw(10) << "Doc ID" << setw(25) << "Doctor Name" << "Salary (Rs.)\n";
    cout << "--------------------------------------------------\n";
    
    int netPayroll = 0;
    for (int i = 0; i < totalDoctors; i++) {
        cout << left << setw(10) << doctorID[i] 
             << setw(25) << doctorName[i] 
             << doctorSalary[i] << "\n";
        netPayroll += doctorSalary[i];
    }
    
    cout << "--------------------------------------------------\n";
    cout << "Total Payroll Expenditure: Rs. " << netPayroll << "\n";
    cout << "==================================================\n";
}

//================================================PATIENT MENU======================================================
void adminMenu()
{
    int choice;
    do
    {
        clearScreen();
        header("ADMIN MANAGEMENT SYSTEM");

        cout << "1. Add New Patient Record" <<endl;
        cout << "2. Display All Patients" <<endl;
        cout << "3. Display Patient History" <<endl;
        cout << "4. Search Patient by Name" << endl;
        cout << "5. Search Patient by ID" <<endl;
        cout << "6. Remove Patient Record " <<endl;
        cout << "7. Update Patient Record" <<endl;
        cout << "8. Search Patient by Disease" <<endl; 
        cout << "9. Add Doctor" <<endl;
        cout << "10. View All Doctors" <<endl;
        cout << "11. View Doctor History" <<endl;
        cout << "12. Search Doctor by ID" <<endl;
        cout << "13. Search Doctor by Name" <<endl;
        cout << "14. Remove Doctor" <<endl;
        cout << "15. Update Doctor Record" <<endl;
        cout << "16. Search Doctors by Field" <<endl;
        cout << "17. View Hospital Statistics" << endl;
        cout << "18. Update Doctor Salary" <<endl;
        cout << "19. Hospital Payroll Report" <<endl;
        cout << "20. Exit" <<endl;
        cout << "==========================================" <<endl;
        choice = readInt("Enter your choice (1-20) : ");
        switch(choice)
        {
            case 1:
                addPatient();
                pauseScreen();
                break;
            case 2:
                displayAllPatients();
                pauseScreen();
                break;
            case 3:
                viewPatientHistory();
                pauseScreen();
                break;
            case 4:
                searchPatientByName();
                pauseScreen();
                break;
            case 5:
                searchPatientById();
                pauseScreen();
                break;
            case 6:
                removePatient();
                pauseScreen();
                break;        
            case 7:
                updatePatientRecord();
                pauseScreen();
                break;
            case 8:
                searchPatientsByDisease();
                pauseScreen();
                break;
            case 9:
                addDoctor();
                pauseScreen();
                break;
            case 10:
                displayAllDoctors();
                pauseScreen();
                break;
            case 11:
                viewDoctorHistory();
                pauseScreen();
                break;
            case 12:
                searchDoctorById();
                pauseScreen();
                break;
            case 13:
                searchDoctorByName();
                pauseScreen();
                break;
            case 14:
                removeDoctor();
                pauseScreen();
                break;
            case 15:
                updateDoctorRecord();
                pauseScreen();
                break;
            case 16:
                searchDoctorByField();
                pauseScreen();
                break;
            case 17:
                viewHospitalStatistics();
                pauseScreen();
                break;
            case 18:
                updateDoctorSalary();
                pauseScreen();
                break;
            case 19:
                hospitalPayrollReport();
                pauseScreen();
                break;
            case 20:
                cout <<"Exiting Admin Portal...";
                break;
            default:
                cout << "Invalid choice! Kindly enter your choice between 1 and 20 only.";
                pauseScreen();
        }
    }while(choice!=20);
}