#include<iostream>
#include<string>
using namespace std;
int patientID[100];
string patientName[100];
int patientAge[100];
string patientDisease[100];
string patientHitory[100];
int totalPatient = 0;
void addPatient()
{
    if(totalPatient>=100)
    {
        cout << "hospitals' capacity is full!"<<endl;
        return ;
    }
    cout <<"-----enter new patient records-----"<<endl;
    cout << "enter patient id : ";
    cin >> patientID[totalPatient];
    int tempID=patientID[totalPatient];
    for(int i=0; i<totalPatient; i++)
    {
        if(patientID[i]==tempID)
        {
            cout << "this ID already belong to a patient. Now enter new ID for this patient : " <<endl;
            cin >> patientID[totalPatient];
        }
    }
    cout << "enter patient name : ";
    cin.ignore();
    getline(cin,patientName[totalPatient]);
    cout << "enter age of patient : ";
    cin >>patientAge[totalPatient];
    while(patientAge[totalPatient]<=0||patientAge[totalPatient]>200)
    {
        cout <<"kindly enter valid patient age : ";
        cin >> patientAge[totalPatient];
    }
    cout << "enter disease of patient : ";
    cin.ignore();
    getline(cin,patientDisease[totalPatient]);
    cout << "enter history of patient : ";
    cin.ignore();
    getline (cin, patientHitory[totalPatient]);
    totalPatient++;

}
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
        cout << "patient no. 1 :"<<endl;
        cout <<"ID : " <<patientID[i] <<endl;
        cout << "Name : " <<patientName[i] << endl;
        cout << "Age : " << patientAge[i] <<endl;
        cout << "Disease : " <<patientDisease[i] <<endl;
        cout << "Histroy : " <<patientHitory[i] <<endl;
        cout << "----------------------------------------" <<endl;

    }
}
void viewPatientHistory()
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
            cout << "Histroy : " <<patientHitory[i] <<endl;
            found = true;
            break;
        }
    }
    if(found==false)
    {
        cout << "History/Record of ID " <<searchID << " not found!"<<endl;
    }
}
void removePatient()
{
    if(totalPatient==0)
    {
        cout <<"there is not any record in the hospital which could be delete!" <<endl;
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
        patientID[i]=patientID[i+1];
        patientName[i]=patientName[i+1];
        patientAge[i]=patientAge[i+1];
        patientDisease[i]=patientDisease[i+1];
        patientHitory[i]=patientHitory[i+1];
    }
    totalPatient--;

}
void PatientMenu()
{
    int choice;
    do
    {
        cout <<"\n ====================================" <<endl;
        cout <<"Patient Management System! " <<endl;
        cout << "=================================" <<endl;
        cout << "1. Add New Patient Record" <<endl;
        cout << "2. Display All Patients" <<endl;
        cout << "3. Display Patient History!" <<endl;
        cout << "4. Remove Patient Record! " <<endl;
        cout << "5. Exit / Go Back to Master Menu!" <<endl;
        cout << "==========================================" <<endl;
        cout << "enter your choice (1-5) : ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                addPatient();
                break;
            case 2:
                displayAllPatients();
                break;
            case 3:
                viewPatientHistory();
                break;
            case 4:
                removePatient();
                break;
            case 5:
                cout << "going out of the patient menu!";
                break;
            default:
                cout << "invalid choice! kindy enter your choice between 1 and 5!";

        }

    }while(choice!=5);
}
int main()
{
    //addPatient();
    //displayAllPatients();
    //viewPatientHistory();
    //removePatient();
    PatientMenu();
    return 0;
}
