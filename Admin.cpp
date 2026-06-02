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
    ofstream outFile("patients_data.txt"); // 
    
    if(!outFile) {
        cout << "Error: File couldn't open!" << endl;
        return;
    }
    outFile << totalPatient << endl;
    
    for(int i = 0; i < totalPatient; i++)
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
        cout << "Error: File couldn't open!" << endl;
        return;
    }
    outFile << totalDoctors << endl;
    for(int i = 0; i < totalDoctors; i++)
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
    if(totalPatient>=100)
    {
        cout << "hospitals' capacity is full!"<<endl;
        return ;
    }
    cout <<"-----enter new patient records-----"<<endl;
    /*bool alreadyexists;
    do
    {
        alreadyexists=false;
        cout << "enter patient id, ID must be one plus to last ID in records in data file ";
        cin >> patientID[totalPatient];
        int tempID=patientID[totalPatient];
        for(int i=0; i<totalPatient; i++)
        {
            if(patientID[i]==patientID[totalPatient])
            {
                cout << "this ID already belong to a patient. Now enter new ID for this patient : " <<endl;
                alreadyexists=true;
            }
        }
    }while(alreadyexists);*/
    patientID[totalPatient]=totalPatient+1;
    cin.ignore();
    cout << "enter patient name : ";
    getline(cin,patientName[totalPatient]);
    cout << "enter age of patient : ";
    cin >>patientAge[totalPatient];
     while(patientAge[totalPatient]<=0||patientAge[totalPatient]>200)
    { 
        cout <<"kindly enter valid patient age : ";
        cin >> patientAge[totalPatient];
    }
    cin.ignore();
    cout << "enter disease of patient : ";
    getline(cin,patientDisease[totalPatient]);
    cout << "enter history of patient : ";
    //cin.ignore();
    getline (cin, patientHitory[totalPatient]);
    totalPatient++;
    P_saveToFile();
    cout << "Patient's record add successfully  to file!" << endl;
}
//===========================================================ADD DOCTOR RECORD=======================================================
void addDoctor()
{
    if(totalDoctors>=25)
    {
        cout << "hospitals' capacity is full!"<<endl;
        return ;
    }
    cout <<"-----enter new doctor record-----"<<endl;
    doctorID[totalDoctors]=totalDoctors+1;
    cout << "enter Doctor name : ";
    cin.ignore();
    getline(cin,doctorName[totalDoctors]);
    cout << "enter salary of the doctor : " ;
    cin >> doctorSalary[totalDoctors];
    cout << "enter field of the doctor : " ;
    cin.ignore();
    getline(cin,doctorField[totalDoctors]);
    totalDoctors++;
    D_saveToFile();
    cout << "Doctor's record add successfully to file!" << endl;

}

//=================================================DISPLAY ALL PATIENTS=====================================================================
void displayAllPatients()
{
    if(totalPatient==0)
    {
        cout << "there is no patient in the hospital!"<<endl;
    }
    cout <<"\n ======================================================"<<endl;
    cout << "records of all patients in the hospital !"<<endl;
    for(int i=0; i<totalPatient; i++)
    {
        cout << "patient no. "  <<i+1 <<endl;
        cout <<"ID : " <<patientID[i] <<endl;
        cout << "Name : " <<patientName[i] << endl;
        cout << "Age : " << patientAge[i] <<endl;
        cout << "Disease : " <<patientDisease[i] <<endl;
        cout << "History : " <<patientHitory[i] <<endl;
        cout << "----------------------------------------" <<endl;

    }
}
//=================================================DISPLAY ALL DOCTORS======================================================================
void displayAllDoctors()
{
    if(totalDoctors==0)
    {
        cout << "there is no doctor in the hospital!"<<endl;
    }
    cout <<"\n ======================================================"<<endl;
    cout << "records of all doctors in the hospital !"<<endl;
    for(int i=0; i<totalDoctors; i++)
    {
        cout << "Doctor no. "  <<i+1 <<endl;
        cout <<"ID : " <<doctorID[i] <<endl;
        cout << "Name : " <<doctorName[i] << endl;
        cout << "Salary : " << doctorSalary[i] << endl;
        cout << "Field : " <<doctorField[i] <<endl;
        cout << "----------------------------------------" <<endl;

    }
}

//=========================================================VIEW PATIENT HISTORY==============================================================
void viewPatientHistory()
{
    if(totalPatient==0)
    {
        cout << "there is not any patient's record in the hospital whom record can be searched!"<<endl;
        return ;
    }
    int searchID;
    bool found = false;
    cout <<"enter ID of the patient to view history:";
    cin >> searchID;
    for(int i=0; i<totalPatient; i++)
    {
        if(patientID[i]==searchID)
        {
            cout <<"=======================" <<endl;
            cout << "patient ID Found!" <<endl;
            cout <<"ID : " <<patientID[i] <<endl;
            cout << "Name : " <<patientName[i] << endl;
            cout << "Age : " << patientAge[i] <<endl;
            cout << "Disease : " <<patientDisease[i] <<endl;
            cout << "History : " <<patientHitory[i] <<endl;
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
    if(totalDoctors==0)
    {
        cout << "there is not any patient's record in the hospital whom record can be searched!"<<endl;
        return ;
    }
    int searchID;
    bool found = false;
    cout <<"enter ID of the doctor to view doctor's history:";
    cin >> searchID;
    for(int i=0; i<totalDoctors; i++)
    {
        if(doctorID[i]==searchID)
        {
            cout <<"=======================" <<endl;
            cout << "doctor ID Found!" <<endl;
            cout <<"ID : " << doctorID[i] <<endl;
            cout << "Name : " << doctorName[i] << endl;
            cout << "Salary : " << doctorSalary[i] <<endl;
            cout << "Filed : " << doctorField[i] << endl;
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
    if(totalPatient==0)
    {
        cout << "there is not any patient's record in the hospital whom record can be searched!"<<endl;
        return ;
    }
    int searchID;
    bool found = false;
    cout <<"enter ID of the patient to search!";
    cin >> searchID;
    for(int i=0; i<totalPatient; i++)
    {
        if(patientID[i]==searchID)
        {
            cout <<"=======================" <<endl;
            cout << "patient ID Found!" <<endl;
            cout <<"ID : " <<patientID[i] <<endl;
            cout << "Name : " <<patientName[i] << endl;
            cout << "Age : " << patientAge[i] <<endl;
            cout << "Disease : " <<patientDisease[i] <<endl;
            cout << "History : " <<patientHitory[i] <<endl;
            found = true;
            break;
        }
    }
    if(found==false)
    {
        cout << "History/Record of ID " <<searchID << " not found!"<<endl;
    }
}
//=========================================================SEARCH DOCTOR BY ID===============================================================
void searchDoctorById()
{
    if(totalDoctors==0)
    {
        cout << "there is not any patient's record in the hospital whom record can be searched!"<<endl;
        return ;
    }
    int searchID;
    bool found = false;
    cout <<"enter ID of the doctor to search!";
    cin >> searchID;
    for(int i=0; i<totalDoctors; i++)
    {
        if(doctorID[i]==searchID)
        {
            cout <<"=======================" <<endl;
            cout << "doctor ID Found!" <<endl;
            cout <<"ID : " << doctorID[i] <<endl;
            cout << "Name : " << doctorName[i] << endl;
            cout << "Salary : " << doctorSalary[i] <<endl;
            cout << "Filed : " << doctorField[i] << endl;
            found = true;
            break;
        }
    }
    if(found==false)
    {
        cout << "History/Record of ID " <<searchID << " not found!"<<endl;
    }
}
//=======================================================SEARCH PATIENT BY NAME========================================================================

void searchPatientByName()
{
    if(totalPatient == 0)
    {
        cout << "Hospital mein koi record nahi hai!" << endl;
        return;
    }
    string searchName;
    bool found = false;
    cout << "Enter Patient Name to search: ";
    cin.ignore(); 
    getline(cin, searchName);
    
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
        cout << "there is not any patient names " <<searchName <<" ! " << endl;
    }
}
//=======================================================SEARCH DOCTOR BY NAME=========================================================================
void searchDoctorByName()
{
    if(totalDoctors == 0)
    {
        cout << "There is not any Doctor in the hospital!" << endl;
        return;
    }
    string searchName;
    bool found = false;
    cout << "Enter Doctor Name to search : ";
    cin.ignore(); 
    getline(cin, searchName);
    
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
        cout << "there is not any doctors named " <<searchName <<" ! " << endl;
    }
}

//=============================================REMOVE PATIENT RECORD===================================================================
void removePatient()
{
    if(totalPatient==0)
    {
        cout <<"there is not any record in the hospital which could be delete!" <<endl;
        return;
    }
    int deleteID;
    cout <<"\n============================================" <<endl;
    cout << "======= Remove Patient Record! ========" <<endl;
    cout << "enter patient ID to remove: ";
    cin >> deleteID;
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
        cout << "There is not any Patient having ID " <<deleteID <<endl;
        return ;
    }
    for(int i=foundIndex; i<totalPatient-1; i++)
    {
        patientName[i]=patientName[i+1];
        patientAge[i]=patientAge[i+1];
        patientDisease[i]=patientDisease[i+1];
        patientHitory[i]=patientHitory[i+1];
    }
    totalPatient--;
    P_saveToFile();
    cout<<"Patient's record deleted successfully!"<<endl;
}
//=============================================REMOOVE DOCTOR RECORD===================================================================
void removeDoctor()
{
    if(totalDoctors==0)
    {
        cout <<"there is not any doctor's record in the hospital which could be delete!" <<endl;
        return;
    }
    int deleteID;
    cout <<"\n============================================" <<endl;
    cout << "======= Remove Doctor Record! ========" <<endl;
    cout << "enter Doctor ID to remove: ";
    cin >> deleteID;
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
        cout << "There is not any Doctor having ID " <<deleteID <<endl;
        return ;
    }
    for(int i=foundIndex; i<totalDoctors-1; i++)
    {
        doctorID[i]=doctorID[i];
        doctorName[i]=doctorName[i+1];
        doctorSalary[i]=doctorSalary[i+1];
        doctorField[i]=doctorField[i+1];
    }
    totalDoctors--;
    D_saveToFile();
    cout<<"Doctor's record deleted successfully!"<<endl;
}
//=============================================UPDATE PATIENT RECORD=====================================================================

void updatePatientRecord() 
{
    int id;
    cout << "\n====================================\n";
    cout << "      UPDATE PATIENT RECORD\n";
    cout << "====================================\n";
    cout << "Enter Patient ID to update: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < totalPatient; i++) {
        if (patientID[i] == id) {
            found = true;
            cout << "\nCurrent Details:\n";
            cout << "Name: " << patientName[i] << " | Disease: " << patientDisease[i] << "\n";
            
            cout << "\nEnter New Details:\n";
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, patientName[i]);
            cout << "Enter New Age: ";
            cin >> patientAge[i];
            cout << "Enter New Disease: ";
            cin.ignore();
            getline(cin, patientDisease[i]);
            cout << "Enter New History: ";
            getline(cin, patientHitory[i]);
            P_saveToFile();
            cout << "\nPatient record updated successfully and saved to file!\n";
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
    int id;
    cout << "\n====================================\n";
    cout << "       UPDATE DOCTOR RECORD\n";
    cout << "====================================\n";
    cout << "Enter Doctor ID to update: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < totalDoctors; i++) {
        if (doctorID[i] == id) {
            found = true;
            cout << "\nCurrent Details:\n";
            cout << "Name: " << doctorName[i] << " | Field: " << doctorField[i] << " | Salary: " << doctorSalary[i] << "\n";            
            cout << "\nEnter New Details:\n";
            cout << "Enter New Name: ";
            cin.ignore(); 
            getline(cin, doctorName[i]);
            
            cout << "Enter New Field/Specialization: ";
            getline(cin, doctorField[i]);
            
            cout << "Enter New Salary: ";
            cin >> doctorSalary[i];
            D_saveToFile();
            cout << "\nDoctor record updated successfully and saved to file!\n";
            break;
        }
    }
    if (!found) {
        cout << "\nError: Doctor with ID " << id << " not found.\n";
    }
}
//=================================================DEARCH PATIENT BY DISEASE=====================================================================

void searchPatientsByDisease() 
{
    string disease;
    cout << "\n====================================\n";
    cout << "     SEARCH PATIENTS BY DISEASE\n";
    cout << "====================================\n";
    cout << "Enter Disease Name to search: ";
    cin.ignore();
    getline(cin, disease);

    bool found = false;
    cout << "\nMatching Patients:\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < totalPatient; i++) 
    {
        if (patientDisease[i] == disease) {
            cout << "ID: " << patientID[i] 
                 << " | Name: " << patientName[i] 
                 << " | Age: " << patientAge[i] << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No patients found suffering from \"" << disease << "\".\n";
    }
}
//=================================================SEARCH DOCTOR BY FIELD=====================================================================
void searchDoctorByField() 
{
    string field;
    cout << "\n====================================\n";
    cout << "      SEARCH DOCTORS BY FIELD\n";
    cout << "====================================\n";
    cout << "Enter Specialization/Field to search: ";
    cin.ignore();
    getline(cin, field);

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
    cout << "\n====================================\n";
    cout << "      HOSPITAL STATISTICS\n";
    cout << "====================================\n";
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
    int id;
    cout << "\n====================================\n";
    cout << "        UPDATE DOCTOR SALARY\n";
    cout << "====================================\n";
    cout << "Enter Doctor ID to update salary: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < totalDoctors; i++) {
        if (doctorID[i] == id) 
        {
            found = true;
            cout << "\nCurrent Salary of Dr. " << doctorName[i] << " is: Rs. " << doctorSalary[i] << "\n";
            cout << "Enter New Salary: ";
            cin >> doctorSalary[i];
            D_saveToFile();
            cout << "\nSalary updated successfully and saved to file!\n";
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
        system("cls");
        cout <<"\n ====================================" <<endl;
        cout <<"Patient Management System! " <<endl;
        cout << "=================================" <<endl;
        cout << "1. Add New Patient Record!" <<endl;
        cout << "2. Display All Patients!" <<endl;
        cout << "3. Display Patient History!" <<endl;
        cout << "4. Search Patient by name!" << endl;
        cout << "5. Search patient by ID!" <<endl;
        cout << "6. Remove Patient Record! " <<endl;
        cout << "7. Update Patient Record!" <<endl;
        cout << "8. Search Patient by Disease!" <<endl; 
        cout << "9. Add Doctor!" <<endl;
        cout << "10. View all Doctors!" <<endl;
        cout << "11. View Doctor History!" <<endl;
        cout << "12. Search Doctor by ID!" <<endl;
        cout << "13. Search Doctor by Name! " <<endl;
        cout << "14. Remove Doctor!" <<endl;
        cout << "15. Update Doctor Record! " <<endl;
        cout << "16. Search Doctors by field!" <<endl;
        cout << "17. View Hospital's Statistics!" << endl;
        cout << "18. Update Doctor Salary!" <<endl;
        cout << "19. Hospital Payroll Report!" <<endl;
        cout << "20. Exit....." <<endl;
        cout << "==========================================" <<endl;
        cout << "enter your choice (1-20) : ";
        cin >> choice;
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
                cout <<"Exiting Admin Portal......";
                break;
            default:
                cout << "invalid choice! kindy enter your choice between 1 and 20 only!";
        }
    }while(choice!=20);
}
/*int main()
{
    P_loadFromFile();
    D_loadFromFile();
    system("color 0E");
    //addPatient();
    //displayAllPatients();
    //viewPatientHistory();
    //removePatient();
    adminMenu();
    return 0;
}
*/