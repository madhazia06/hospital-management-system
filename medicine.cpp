#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdio>
#include "medicine.h"
#include "common.h"

using namespace std;

bool medicineExists(int searchID)
{
    int id, quantity, expirydate;
    double price;
    string name, company;
    ifstream fin("medicine.txt");

    while(fin >> id)
    {
        fin.ignore();
        getline(fin, name);
        getline(fin, company);
        fin >> quantity >> price >> expirydate;
        fin.ignore();

        if(id == searchID)
        {
            fin.close();
            return true;
        }
    }

    fin.close();
    return false;
}

void addNewMed()
{
    int id, quantity, expirydate;
    double price;
    string name, company, choice;
    do 
    {
        header("ADD NEW MEDICINE");
        id=readInt("Enter Medicine ID: ");
        if(medicineExists(id))
        {
            cout<<"Medicine ID already exists.";
        }
        else
        {
            name=readStringLine("Enter Medicine Name: ");
            company=readStringLine("Enter Company Name: ");
            quantity=readInt("Enter Quantity: ");
            while (quantity<0)
            {
                cout<<"Re-enter quantity as it cannot be negative.\n";
                quantity=readInt("Enter Quantity: ");
            }
            price=readDouble("Enter Price (PKR): ");
            while (price<0)
            {
                cout<<"Re-enter price as it cannot be negative.\n";
                price=readInt("Enter Price (PKR): ");
            }
            expirydate=readInt("Enter Expiry Date (yyyy): ");
            ofstream fout;
            fout.open("medicine.txt", ios::app);
            fout << id << endl;
            fout << name << endl;
            fout << company << endl;
            fout << quantity << endl;
            fout << price << endl;
            fout << expirydate << endl;

            fout.close();
            cout<<"\n\nMedicine Added Successfully!";

        }
        choice="\n\nAdd Another Medicne (yes/no): ";
    } while(choice=="Yes"||choice=="yes"||choice=="YES");
}

void viewAllMed()
{
    int id, quantity, expirydate;
    double price;
    string name, company;
    ifstream fin;
    fin.open("medicine.txt");
            
    header("VIEW ALL MEDICINES");

    if(!fin)
    {
        cout<<"No records of medicines were found.!\n";
        return;
    }
    cout<<left<<setw(8)<<"ID"<<setw(30)<<"Name"<<setw(30)<<"Company"<<setw(10)<<"Quantity"<<setw(12)<<"Price (PKR)"<<setw(12)<<"Expiry"<<endl;
    cout<<"-----------------------------------------------------------------------------------------\n";

    while (fin>>id)
    {
        fin.ignore();
        getline(fin,name);
        getline(fin,company);
        fin>>quantity>>price>>expirydate;
        fin.ignore();
        cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(30)<<company<<setw(10)<<quantity<<setw(12)<<fixed<<setprecision(2)<<price<<setw(12)<<expirydate<< endl;
    }
    fin.close();
}

void searchMed()
{
    int searchId;
    int id, quantity, expirydate;
    double price;
    string name, company;
    bool found=false;
    ifstream fin;
    fin.open("medicine.txt");

    header("SEARCH MEDICINE");

    if(!fin)
    {
        cout<<"No records of medicines were found.!\n";
        return;
    }
    
    searchId=readInt("Enter Medicine ID: ") ;
    

    while (fin>>id)
    {
        fin.ignore();
        getline(fin, name);
        getline(fin, company);
        fin>>quantity>>price>>expirydate;
        fin.ignore();

        if(id==searchId)
        {
            found=true;

            cout<<"\nMedicine Found!"<<endl;
            cout<<"Medicine ID      : "<<id<<endl;
            cout<<"Medicine Name    : "<<name<<endl;
            cout<<"Company Name     : "<<company<<endl;
            cout<<"Quantity         : "<<quantity<<endl;
            cout<<"Price (PKR)      : "<<fixed<<setprecision(2)<<price<<endl;
            cout<<"Expiry Date      : "<<expirydate << endl;
            break;
        }
    }

    if (!found)
    {
        cout<<"\nMedicine NOT Found!\n";
    }

    fin.close();
}

void updateMedQty()
{
    int updateId,newQuantity;
    int id, quantity, expirydate;
    double price;
    string name, company;
    bool found=false;
    
    header("UPDATE MEDICINE QUANTITY");
    updateId=readInt("Enter Medicine ID: ");
    
    ifstream fin;
    fin.open("medicine.txt");
    ofstream fout;
    fout.open("temp.txt");

    if(!fin)
    {
        cout<<"No records of medicines were found.!\n";
        return;
    }
    
    while (fin>>id)
    {
        fin.ignore();
        getline(fin, name);
        getline(fin, company);
        fin >> quantity >> price >> expirydate;
        fin.ignore();

        if(id==updateId)
        {
            found=true;
            cout<<"\nCurrent Quantity: "<<quantity<<endl;
            newQuantity=readInt("Enter New Quantity: ");
            while (newQuantity<0)
            {
                cout<<"Quantity cannot be negative!"<<endl;
                newQuantity=readInt("Enter New Quantity: ");
            }
            quantity=newQuantity;
            cout<<"\nMedicine Updated Successfully!\n";
        }
        fout << id << endl;
        fout << name << endl;
        fout << company << endl;
        fout << quantity << endl;
        fout << price << endl;
        fout << expirydate << endl;
    }
    
    fin.close();
    fout.close();
    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");

    if(!found)
    {
        cout<<"\nWrong ID entered!\n";
    }

}

void deleteMed()
{
    int deleteId;
    int id, quantity, expirydate;
    double price;
    string name, company;
    bool found=false;
    ifstream fin;
    ofstream fout;
    
    header("DELETE MEDICINE");
    deleteId=readInt("Enter medicine ID to delete: ");

    fout.open("temp.txt");
    fin.open("medicine.txt");
    
    if(!fin)
    {
        cout<<"No records of medicines were found.!\n";
        return;
    }

    while (fin>>id)
    {
        fin.ignore();
        getline(fin, name);
        getline(fin, company);
        fin >> quantity;
        fin >> price;
        fin >> expirydate;
        fin.ignore();

        if(id!=deleteId)
        {
            fout << id << endl;
            fout << name << endl;
            fout << company << endl;
            fout << quantity << endl;
            fout << price << endl;
            fout << expirydate << endl;
        }
        else
        {
            found=true;
            cout<<"\nMedicine Successfully Deleted!";
        }
    }
    if(!found)
    {
        cout<<"\nNo medicine exists with the entered ID.\n";
    }
    fin.close();
    fout.close();
    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");
}

void checkStock()
{
    int low=0;
    int id, quantity, expirydate;
    double price;
    string name, company;
    bool found=false;
    ifstream fin;
    fin.open("medicine.txt");

    header("LOW STOCK MEDICINES");
    if(!fin)
    {
        cout << "No medicine record found!" << endl;
        return;
    }

    low=readInt("Enter minimum quantity threshold for low-stock medicines: ");
    cout<<left<<setw(8)<<"ID"<<setw(30)<<"Name"<<setw(30)<<"Company"<<setw(10)<<"Quantity"<<endl;

    while (fin>>id)
    {
        fin.ignore();
        getline(fin, name);
        getline(fin, company);
        fin>>quantity>>price>>expirydate;
        fin.ignore();

        if(quantity<=low)
        {
            found=true;
            cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(30)<<company<<setw(10)<<quantity<<endl;
        }
    }

    if (!found)
    {
        cout<<"\nNo medicine is below minimum stock level!\n";
    }

    fin.close();
}

void expiryAlert()
{
    int year=2026;
    int id, quantity, expirydate;
    double price;
    string name, company;
    bool found=false;
    ifstream fin;
    fin.open("medicine.txt");

    header("EXPIRY ALERT");
    if(!fin)
    {
        cout<<"No records of medicines were found.!\n";
        return;
    }
    year=readInt("Enter expiry year (yyyy) to display expired medicines: ");
    cout<<"Medicines getting expired in "<<year<<".\n\n";

    cout<<left<<setw(8)<<"ID"<<setw(30)<<"Name"<<setw(30)<<"Company"<<setw(10)<<"Quantity"<<setw(12)<<"Expiry"<<endl;

    while (fin>>id)
    {
        fin.ignore();
        getline(fin, name);
        getline(fin, company);
        fin >> quantity;
        fin >> price;
        fin >> expirydate;
        fin.ignore();

        if(expirydate==year)
        {
            found=true;
            cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(30)<<company<<setw(10)<<quantity<<setw(12)<<expirydate<<endl;
        }
    }

    if (!found)
    {
        cout<<"\nNo medicine is getting expired in year "<<year<<"!\n";
    }

    fin.close();
}

void invoice()
{
    ifstream fin;
    ofstream fout;
    ofstream bill;
    int id, quantity, expirydate, medcount;
    double price, amount, total=0;
    string name, company, patient;
    int medid[100];
    int medqty[100];
    bool foundID[100];

    for(int i = 0; i < 100; i++)
    {
        foundID[i] = false;
    }


    header("GENERATE INVOICE");
    patient = readStringLine("Enter Patient Name: ");
    medcount = readInt("How many medications is the patient buying: ");
    if(medcount <= 0 || medcount > 100)
    {
        cout << "Invalid medicine count!" << endl;
        return;
    }

    for (int i=0; i<medcount; i++)
    {
        cout<<"Medicine "<<i+1<<endl;
        medid[i] = readInt("Enter Medicine ID: ");
        medqty[i] = readInt("Enter Medicine Quantity: ");
        while(medqty[i] <= 0)
        {
            cout << "Quantity must be greater than zero!" << endl;
            medqty[i] = readInt("Enter Medicine Quantity: ");
        }
    }

    
    fout.open("temp.txt");
    fin.open("medicine.txt");
    bill.open("invoices.txt", ios::app);
    
    cout << "\n====== BILL ======\n";
    cout << "Patient Name: " << patient << endl;
    cout<<left<<setw(8)<<"ID"<<setw(30)<<"Name"<<setw(10)<<"Quantity"<<setw(15)<<"Rate (PKR)"<<setw(15)<<"Amount (PKR)"<<endl;

    while (fin>>id)
    {
        fin.ignore();
        getline(fin, name);
        getline(fin, company);
        fin >> quantity;
        fin >> price;
        fin >> expirydate;
        fin.ignore();

        for (int i = 0; i < medcount; i++)
        {
            if(id==medid[i])
            {
                foundID[i]=true;
                if(medqty[i] > quantity)
                {
                    cout << "\nNot enough stock for Medicine ID " << id << endl;
                    cout << "Available Quantity: " << quantity << endl;
                }
                else
                {
                    amount = price*medqty[i]*1.0;
                    cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(10)<<medqty[i]<<setw(15)<<fixed<<setprecision(2)<<price<<setw(15)<<amount<<endl;
                    total+=amount;
                    quantity-=medqty[i];
                }
            }
        }
        fout << id << endl;
        fout << name << endl;
        fout << company << endl;
        fout << quantity << endl;
        fout << price << endl;
        fout << expirydate << endl;
    }

    for(int i = 0; i < medcount; i++)
    {
        if(foundID[i] == false)
        {
            cout << "\nMedicine ID " << medid[i] << " not found!" << endl;
        }
    }
    cout<<"\n-----------------------------------------------------------------------------------------\n";
    cout << "Total Bill: " << fixed << setprecision(2) << total << endl;


    bill << "Patient Name: " << patient << endl;
    bill << "Total Bill: " << total << endl;
    bill << "----------------------------------------" << endl;

    fin.close();
    fout.close();
    bill.close();

    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");
}

void medicineMenu()
{
    int choice;
    do
    {
        clearScreen();
        header("MEDICINE MANAGEMENT PORTAL");

        cout<<"1. Add Medicine\n";
        cout<<"2. View All Medicines\n";
        cout<<"3. Search Medicine\n";
        cout<<"4. Update Medicine Quantity\n";
        cout<<"5. Delete Medicine\n";
        cout<<"6. Check Low Stock Medicines\n";
        cout<<"7. Expiry Alert\n";
        cout<<"8. Generate Invoice\n";
        cout<<"9. Back to Main Menu\n\n";
        choice=readInt("Enter Choice: ");
            
        if(choice==1)       {addNewMed(); pauseScreen();}
        else if(choice==2)  {viewAllMed(); pauseScreen();}
        else if(choice==3)  {searchMed(); pauseScreen();}
        else if(choice==4)  {updateMedQty(); pauseScreen();}
        else if(choice==5)  {deleteMed(); pauseScreen();}
        else if(choice==6)  {checkStock(); pauseScreen();}
        else if(choice==7)  {expiryAlert(); pauseScreen();}
        else if(choice==8)  {invoice(); pauseScreen();}
        else if(choice==9)  {cout << "Going back to main menu!" << endl;}
        else 
        {
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }
    } while(choice != 9);
}