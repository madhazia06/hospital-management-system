#ifndef MEDICINE_H
#define MEDICINE_H

//This header file contains declarations of all medicine-related functions.
//These functions are defined in medicine.cpp.

//Opens the medicine management menu
void medicineMenu();
//Adds a new medicine record to medicine.txt
void addNewMed();
//Displays all medicine records
void viewAllMed();
//Searches medicine by ID
void searchMed();
//Updates the quantity of an existing medicine
void updateMedQty();
//Deletes a medicine record by ID
void deleteMed();
//Checks medicines with low stock
void checkStock();
//Shows medicines expiring in a specific year
void expiryAlert();
//Generates invoice and updates medicine quantity
void invoice();

#endif