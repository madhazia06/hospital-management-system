#ifndef ADMIN_H
#define ADMIN_H

#include <string>
using namespace std;

// Patient file functions
void P_saveToFile();
void P_loadFromFile();

// Doctor file functions
void D_saveToFile();
void D_loadFromFile();

// Patient management functions
void addPatient();
void displayAllPatients();
void viewPatientHistory();
void searchPatientById();
void searchPatientByName();
void removePatient();
void updatePatientRecord();
void searchPatientsByDisease();

// Doctor management functions
void addDoctor();
void displayAllDoctors();
void viewDoctorHistory();
void searchDoctorById();
void searchDoctorByName();
void removeDoctor();
void updateDoctorRecord();
void searchDoctorByField();
void updateDoctorSalary();

// Reports / statistics
void viewHospitalStatistics();
void hospitalPayrollReport();

// Utility functions
void pauseScreen();

// Main admin menu
void adminMenu();

#endif