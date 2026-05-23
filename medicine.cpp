#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int menuChoice();
void addNewMed();
void viewAllMed();
void searchMed();
//void updateMed();
//void deleteMed();
//void checkStock();
//void expiryAlert();
//void mainMenu();


int main()
{
    int choice=menuChoice();
    if(choice==1)       {addNewMed();}
    else if(choice==2)  {viewAllMed();}
    else if(choice==3)  {searchMed();}
//    else if(choice==4)  {updateMed();}
//    else if(choice==5)  {deleteMed();}
//    else if(choice==6)  {checkStock();}
//    else if(choice==7)  {expiryAlert();}
//    else                {mainMenu();}
    return 0;
}

int menuChoice()
{
    int i=0;
    int choice;
    do
    {
        if (i>0)
        {
            cout<<"\nWRONG CHOICE ENTERED!!!\n";
        }

        cout<<"==========================================\n";
        cout<<"\tMEDICINE MANAGEMENT PORTAL\n";
        cout<<"==========================================\n\n";
        cout<<"1. Add Medicine\n";
        cout<<"2. View All Medicines\n";
        cout<<"3. Search Medicine\n";
        cout<<"4. Update Medicine\n";
        cout<<"5. Delete Medicine\n";
        cout<<"6. Check Stock\n";
        cout<<"7. Expiry Alert\n";
        cout<<"8. Back to Main Menu\n\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        i++;
    } while (choice <1 || choice>8);
    return choice;
}

void addNewMed()
{
    int id, quantity, expirydate;
    double price;
    string name, company, choice;
    ofstream fout;
    fout.open("medicine.txt", ios::app);

    do 
    {
        cout<<"------------------------------------------\n";
        cout<<"\t\tADD NEW MEDICINE\n";
        cout<<"------------------------------------------\n\n";

        cout << left << setw(25) << "Enter Medicine ID" << ": ";
        cin>>id;
        fout<<id<<"|";
        cin.ignore();
        cout << left << setw(25) << "Enter Medicine Name" << ": ";
        getline(cin, name);
        fout<<name<<"|";
        cout << left << setw(25) << "Enter Comapny Name" << ": ";
        getline(cin, company);
        fout<<company<<"|";
        cout << left << setw(25) << "Enter Quantity" << ": ";
        cin>>quantity;
        fout<<quantity<<"|";
        cout << left << setw(25) << "Enter Price (in PKR)" << ": ";
        cin>>price;
        fout<<price<<"|";
        cout << left << setw(25) << "Enter Expiry Date (yyyy)" << ": ";
        cin>>expirydate;
        fout<<expirydate<<endl;

        cout<<"\n\nMedicine added successfully!";
        cout<<"\nWould you like to add a new medicne (yes/no)? ";
        cin>>choice;    
    } while(choice=="Yes"||choice=="yes");

    fout.close();   
}
void viewAllMed()
{
    int id, quantity, expirydate;
    double price;
    string name, company;
    ifstream fin;
    fin.open("medicine.txt");
    cout<<"------------------------------------------\n";
    cout<<"\t\tVIEW ALL MEDICINES\n";
    cout<<"------------------------------------------\n\n";
    cout<<left<<setw(8)<<"ID"<<setw(30)<<"Name"<<setw(20)<<"Company"<<setw(10)<<"Quantity"<<setw(12)<<"Price (PKR)"<<setw(12)<<"Expiry"<<endl;
    cout<<"-----------------------------------------------------------------------------------------\n";

    while (fin>>id)
    {
        fin.ignore();
        getline(fin,name);
        getline(fin,company);
        fin>>quantity>>price;
        fin.ignore();
        fin>>expirydate;
        cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(20)<<company<<setw(10)<<quantity<<setw(12)<<fixed<<setprecision(2)<<price<<setw(12)<<expirydate<< endl;
    }
    fin.close();
}

void searchMed()
{
    int search;
    cout<<"------------------------------------------\n";
    cout<<"\t\tSEARCH MEDICINE\n";
    cout<<"------------------------------------------\n\n";
    cout<<"Enter Medicine ID: ";

       

}