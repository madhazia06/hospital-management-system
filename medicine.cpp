#include <iostream> // Allows input and output using cin and cout
#include <iomanip> // Allows formatting output using setw, fixed, setprecision
#include <fstream> // Allows file handling using ifstream and ofstream
#include <string> // Allows use of string data type
#include <cstdio> // Allows remove() and rename() functions for files

#include "medicine.h" // Includes medicine function declarations
#include "common.h" // Includes common helper functions

using namespace std;


// This function displays the medicine management menu
void medicineMenu()
{
    int choice;
    do
    {
        clearScreen();
        header("MEDICINE MANAGEMENT PORTAL");

        // Display menu options
        cout<<"1. Add Medicine\n";
        cout<<"2. View All Medicines\n";
        cout<<"3. Search Medicine\n";
        cout<<"4. Update Medicine Quantity\n";
        cout<<"5. Delete Medicine\n";
        cout<<"6. Check Low Stock Medicines\n";
        cout<<"7. Expiry Alert\n";
        cout<<"8. Generate Invoice\n";
        cout<<"9. Back to Main Menu\n\n";

        // Take user choice
        choice=readInt("Enter Choice: ");
        
        // Call function according to user's choice
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

// This function checks whether a medicine ID already exists in medicine.txt
bool medicineExists(int searchID)
{
    int id, quantity, expirydate;
    double price;
    string name, company;

    ifstream fin("medicine.txt"); // Open medicine.txt file for reading
    
    while(fin >> id) // Read medicine records one by one
    {
        fin.ignore(); // Clears leftover newline after reading id
        getline(fin, name); // Reads medicine name
        getline(fin, company); // Reads company name
        fin >> quantity >> price >> expirydate; // Reads quantity, price, and expiry year
        fin.ignore();

        if(id == searchID) // If entered ID matches existing ID, medicine exists
        {
            fin.close();
            return true;
        }
    }

    fin.close();
    return false; // If no matching ID found
}

// This function adds a new medicine record
void addNewMed()
{
    int id, quantity, expirydate;
    double price;
    string name, company, choice;
    do 
    {
        header("ADD NEW MEDICINE");
        id=readInt("Enter Medicine ID: "); // Take medicine ID from user
        if(medicineExists(id)) // Check duplicate medicine ID
        {
            cout<<"Medicine ID already exists.";
        }
        else
        {
            name=readStringLine("Enter Medicine Name: ");
            company=readStringLine("Enter Company Name: ");
            quantity=readInt("Enter Quantity: ");

            while (quantity<0) // Quantity cannot be negative
            {
                cout<<"Re-enter quantity as it cannot be negative.\n";
                quantity=readInt("Enter Quantity: ");
            }
            price=readDouble("Enter Price (PKR): ");
            
            while (price<0) // Price cannot be negative
            {
                cout<<"Re-enter price as it cannot be negative.\n";
                price=readInt("Enter Price (PKR): ");
            }
            expirydate=readInt("Enter Expiry Date (yyyy): ");
            ofstream fout;

            // Open medicine.txt file in append mode
            // ios::app means new data will be added at the end of file
            fout.open("medicine.txt", ios::app);

            // Save medicine data line by line
            fout << id << endl;
            fout << name << endl;
            fout << company << endl;
            fout << quantity << endl;
            fout << price << endl;
            fout << expirydate << endl;

            fout.close();
            cout<<"\n\nMedicine Added Successfully!";

        }
        cout<<endl;
        choice=readStringLine("Add Another Medicne (yes/no): ");
    } while(choice=="Yes"||choice=="yes"||choice=="YES");
}

// This function displays all medicine records
void viewAllMed()
{
    int id, quantity, expirydate;
    double price;
    string name, company;
    ifstream fin;
    fin.open("medicine.txt");
            
    header("VIEW ALL MEDICINES");

    // Check if file does not exist or cannot be opened
    if(!fin)
    {
        cout<<"No records of medicines were found.!\n";
        return;
    }

    // Displays table heading
    cout<<left<<setw(8)<<"ID"<<setw(30)<<"Name"<<setw(30)<<"Company"<<setw(10)<<"Quantity"<<setw(12)<<"Price (PKR)"<<setw(12)<<"Expiry"<<endl;
    cout<<"-----------------------------------------------------------------------------------------\n";

    // Read all medicine records from file
    while (fin>>id)
    {
        fin.ignore();
        getline(fin,name);
        getline(fin,company);
        fin>>quantity>>price>>expirydate;
        fin.ignore();

        // Display medicine record one by one in table format
        cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(30)<<company<<setw(10)<<quantity<<setw(12)<<fixed<<setprecision(2)<<price<<setw(12)<<expirydate<< endl;
    }
    fin.close();
}

// This function searches medicine by ID
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

    if(!fin) // Check if medicine file exists
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

        if(id==searchId) // If ID matches, display medicine details
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

    if (!found) // If no medicine found with entered ID
    {
        cout<<"\nMedicine NOT Found!\n";
    }

    fin.close();
}

// This function updates medicine quantity
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

    // Check if medicine file exists
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

        // If entered ID matches, update quantity
        if(id==updateId)
        {
            found=true;
            cout<<"\nCurrent Quantity: "<<quantity<<endl;
            newQuantity=readInt("Enter New Quantity: ");
            
            // New quantity cannot be negative
            while (newQuantity<0)
            {
                cout<<"Quantity cannot be negative!"<<endl;
                newQuantity=readInt("Enter New Quantity: ");
            }
            quantity=newQuantity;
            cout<<"\nMedicine Updated Successfully!\n";
        }

        // Write updated or unchanged record to temp.txt
        fout << id << endl;
        fout << name << endl;
        fout << company << endl;
        fout << quantity << endl;
        fout << price << endl;
        fout << expirydate << endl;
    }
    
    fin.close();
    fout.close();

    // Delete old medicine file
    remove("medicine.txt");
    // Rename temp.txt to medicine.txt
    rename("temp.txt", "medicine.txt");

    // If entered ID was not found
    if(!found)
    {
        cout<<"\nWrong ID entered!\n";
    }

}

// This function deletes medicine by ID
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

    fout.open("temp.txt"); // temp.txt will store all records except deleted medicine
    fin.open("medicine.txt"); // Open original medicine file

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

        if(id!=deleteId) // If ID does not match deleteId, keep the record in temp.txt
        {
            fout << id << endl;
            fout << name << endl;
            fout << company << endl;
            fout << quantity << endl;
            fout << price << endl;
            fout << expirydate << endl;
        }
        else // If ID matches, skip writing it to temp file
        {
            found=true;
            cout<<"\nMedicine Successfully Deleted!";
        }
    }
    if(!found) // If no matching medicine was found
    {
        cout<<"\nNo medicine exists with the entered ID.\n";
    }
    fin.close();
    fout.close();

    // Replace old file with temp file
    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");
}

// This function checks low stock medicines
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

    // Check if medicine file exists
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

        if(quantity<=low) // If quantity is less than or equal to threshold, display it
        {
            found=true;
            cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(30)<<company<<setw(10)<<quantity<<endl;
        }
    }

    // If no low stock medicine found
    if (!found)
    {
        cout<<"\nNo medicine is below minimum stock level!\n";
    }

    fin.close();
}

// This function shows medicines expiring in a specific year
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

    // Take expiry year from user
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

        // If expiry year matches user input, display medicine
        if(expirydate==year)
        {
            found=true;
            cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(30)<<company<<setw(10)<<quantity<<setw(12)<<expirydate<<endl;
        }
    }

    if (!found) // If no medicine expires in entered year
    {
        cout<<"\nNo medicine is getting expired in year "<<year<<"!\n";
    }

    fin.close();
}

// This function generates invoice and updates stock
void invoice()
{
    ifstream fin; // Reads medicine.txt
    ofstream fout; // Writes updated medicine records to temp.txt
    ofstream bill; // Saves invoice summary to invoices.txt

    int id, quantity, expirydate, medcount;
    double price, amount, total=0;
    string name, company, patient;

    // Arrays to store medicine IDs and quantities entered by user
    int medid[100];
    int medqty[100];

    // This array tracks whether each entered medicine ID was found or not
    bool foundID[100];

    for(int i = 0; i < 100; i++) // Set all foundID values to false initially
    {
        foundID[i] = false;
    }

    header("GENERATE INVOICE");
    patient = readStringLine("Enter Patient Name: ");
    medcount = readInt("How many medications is the patient buying: ");
    
    if(medcount <= 0 || medcount > 100) // Validate medicine count
    {
        cout << "Invalid medicine count!" << endl;
        return;
    }

    // Take medicine ID and quantity for each medicine
    for (int i=0; i<medcount; i++)
    {
        cout<<"Medicine "<<i+1<<endl;
        medid[i] = readInt("Enter Medicine ID: ");
        medqty[i] = readInt("Enter Medicine Quantity: ");

        // Quantity must be greater than zero
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

    while (fin>>id) // Read all medicines from medicine.txt
    {
        fin.ignore();
        getline(fin, name);
        getline(fin, company);
        fin >> quantity;
        fin >> price;
        fin >> expirydate;
        fin.ignore();

        for (int i = 0; i < medcount; i++) // Compare current medicine ID with all requested medicine IDs
        {
            if(id==medid[i])
            {
                foundID[i]=true;
                if(medqty[i] > quantity) // Check if requested quantity is more than available stock
                {
                    cout << "\nNot enough stock for Medicine ID " << id << endl;
                    cout << "Available Quantity: " << quantity << endl;
                }
                else
                {
                    amount = price*medqty[i]*1.0; // Calculate amount for this medicine
                    // Print medicine in bill
                    cout<<left<<setw(8)<<id<<setw(30)<<name<<setw(10)<<medqty[i]<<setw(15)<<fixed<<setprecision(2)<<price<<setw(15)<<amount<<endl;
                    total+=amount; // Add amount to total bill
                    quantity-=medqty[i]; // Reduce stock quantity
                }
            }
        }
        // Write updated medicine record to temp.txt
        fout << id << endl;
        fout << name << endl;
        fout << company << endl;
        fout << quantity << endl;
        fout << price << endl;
        fout << expirydate << endl;
    }

    for(int i = 0; i < medcount; i++) // Check if any entered medicine ID was not found
    {
        if(foundID[i] == false)
        {
            cout << "\nMedicine ID " << medid[i] << " not found!" << endl;
        }
    }
    cout<<"\n-----------------------------------------------------------------------------------------\n";
    cout << "Total Bill: " << fixed << setprecision(2) << total << endl;

    // Save invoice summary to invoices.txt
    bill << "Patient Name: " << patient << endl;
    bill << "Total Bill: " << total << endl;
    bill << "----------------------------------------" << endl;

    fin.close();
    fout.close();
    bill.close();

    // Replace old medicine file with updated temp file
    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");
}
