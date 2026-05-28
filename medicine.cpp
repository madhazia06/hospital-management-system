#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int menuChoice();
void addNewMed();
void viewAllMed();
void searchMed();
void updateMedQty();
void deleteMed();
void checkStock();
void expiryAlert();
void invoice();
//void mainMenu();


int main()
{
    int choice=menuChoice();
    if(choice==1)       {addNewMed();}
    else if(choice==2)  {viewAllMed();}
    else if(choice==3)  {searchMed();}
    else if(choice==4)  {updateMedQty();}
    else if(choice==5)  {deleteMed();}
    else if(choice==6)  {checkStock();}
    else if(choice==7)  {expiryAlert();}
    else if(choice==8)  {invoice();}
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
        cout<<"4. Update Medicine Quantity\n";
        cout<<"5. Delete Medicine\n";
        cout<<"6. Check Low Stock Medicines\n";
        cout<<"7. Expiry Alert\n";
        cout<<"8. Generate Invoice\n";
        cout<<"9. Back to Main Menu\n\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        i++;
    } while (choice <1 || choice>9);
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
        cin.ignore();
        cout << left << setw(25) << "Enter Medicine Name" << ": ";
        getline(cin, name);
        cout << left << setw(25) << "Enter Comapany Name" << ": ";
        getline(cin, company);
        cout << left << setw(25) << "Enter Quantity" << ": ";
        cin>>quantity;
        cout << left << setw(25) << "Enter Price (in PKR)" << ": ";
        cin>>price;
        cout << left << setw(25) << "Enter Expiry Date (yyyy)" << ": ";
        cin>>expirydate;
        
        fout << id << endl;
        fout << name << endl;
        fout << company << endl;
        fout << quantity << endl;
        fout << price << endl;
        fout << expirydate << endl;

        cout<<"\n\nMedicine Added Successfully!";
        cout<<"\n\nAdd Another Medicne (yes/no): ";
        cin>>choice;
    } while(choice=="Yes"||choice=="yes"||choice=="YES");

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

    cout<<"------------------------------------------\n";
    cout<<"\t\tSEARCH MEDICINE\n";
    cout<<"------------------------------------------\n\n";
    cout<<"Enter Medicine ID: ";
    cin>>searchId;

    while (fin>>id)
    {
        fin.ignore();

        getline(fin, name);
        getline(fin, company);

        fin >> quantity;
        fin >> price;
        fin >> expirydate;

        fin.ignore();

        if(id==searchId)
        {
            found=true;

            cout<<"\nMedicine Found!\n\n";

            cout << "Medicine ID      : " << id << endl;
            cout << "Medicine Name    : " << name << endl;
            cout << "Company Name     : " << company << endl;
            cout << "Quantity         : " << quantity << endl;
            cout << "Price (PKR)      : " << fixed << setprecision(2) << price << endl;
            cout << "Expiry Date      : " << expirydate << endl;

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
    ifstream fin;
    ofstream fout;
    
    cout<<"------------------------------------------\n";
    cout<<"\tUPDATE MEDICINE QUANTITY\n";
    cout<<"------------------------------------------\n\n";
    cout<<"Enter Medicine ID to update: ";
    cin>>updateId;

    fout.open("temp.txt");
    fin.open("medicine.txt");
    while (fin>>id)
    {
        fin.ignore();

        getline(fin, name);
        getline(fin, company);

        fin >> quantity;
        fin >> price;
        fin >> expirydate;

        fin.ignore();

        if(id==updateId)
        {
            found=true;
            cout<<"\n\nCurrent Quantity: "<<quantity<<endl;
            cout<<"Enter New Quantity: ";
            cin>>newQuantity;
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

    if(!found)
    {
        cout<<"\nWrong ID entered!\n";
    }

    fin.close();
    fout.close();


    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");
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
    
    cout<<"------------------------------------------\n";
    cout<<"\tDELETE MEDICINE\n";
    cout<<"------------------------------------------\n\n";
    cout<<"Enter Medicine ID to Delete: ";
    cin>>deleteId;

    fout.open("temp.txt");
    fin.open("medicine.txt");
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
    const int LOW=20;
    int id, quantity, expirydate;
    double price;
    string name, company;
    bool found=false;
    ifstream fin;
    fin.open("medicine.txt");

    cout<<"------------------------------------------\n";
    cout<<"\tLOW STOCK MEDICINES\n";
    cout<<"------------------------------------------\n\n";

    cout<<left<<setw(8)<<"ID"<<setw(30)<<"Name"<<setw(30)<<"Company"<<setw(10)<<"Quantity"<<endl;

    while (fin>>id)
    {
        fin.ignore();

        getline(fin, name);
        getline(fin, company);

        fin >> quantity;
        fin >> price;
        fin >> expirydate;

        fin.ignore();

        if(quantity<=LOW)
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
    const int YEAR=2026;
    int id, quantity, expirydate;
    double price;
    string name, company;
    bool found=false;
    ifstream fin;
    fin.open("medicine.txt");

    cout<<"------------------------------------------\n";
    cout<<"\tEXPIRY ALERT\n";
    cout<<"------------------------------------------\n\n";
    cout<<"Medicines getting expired in "<<YEAR<<".\n\n";

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

        if(expirydate==YEAR)
        {
            found=true;
            cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(30)<<company<<setw(10)<<quantity<<setw(12)<<expirydate<<endl;
        }
    }

    if (!found)
    {
        cout<<"\nNo medicine is getting expired in "<<YEAR<<"!\n";
    }

    fin.close();
}

void invoice()
{
    int id, quantity, expirydate, medcount;
    double price, amount, total=0;
    string name, company, patient;
    int medid[100];
    int medqty[100];

    ifstream fin;
    ofstream fout;
    fout.open("temp.txt");
    fin.open("medicine.txt");

    cout<<"------------------------------------------\n";
    cout<<"\tGENERATE INVOICE\n";
    cout<<"------------------------------------------\n\n";
    cin.ignore();
    cout<<"\nEnter patient's name: ";
    getline(cin, patient);
    cout<<"How many medications is the patient buying: ";
    cin>>medcount;

    for (int i=0; i<medcount; i++)
    {
        cout<<"Enter medicine ("<<i+1<<") ID: ";
        cin>>medid[i];
        cout<<"Enter medicine quantity: ";
        cin>>medqty[i];

    }
    cout<<"======BILL======\n";
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
        bool purchased = false;

        for (int i = 0; i < medcount; i++)
        {
            if(id==medid[i])
            {
                amount = price*medqty[i]*1.0;
                cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(10)<<medqty[i]<<setw(15)<<fixed<<setprecision(2)<<price<<setw(15)<<amount<<endl;
                total+=amount;
                quantity-=medqty[i];
                purchased=true;
            }
        }
        fout << id << endl;
        fout << name << endl;
        fout << company << endl;
        fout << quantity << endl;
        fout << price << endl;
        fout << expirydate << endl;
    }
 


    cout<<"\n-----------------------------------------------------------------------------------------\n";
    cout<<"Total Bill: "<<total;

    fin.close();
    fout.close();
    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");

}