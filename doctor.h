#ifndef DOCTOR_H
#define DOCTOR_H

// Displays the Doctor Portal menu and handles user selections
void doctorMenu();
// Displays all scheduled appointments for patients
void viewAppointments();
// Cancels an existing appointment based on patient ID
void cancelAppointment();
// Allows the doctor to write and save prescriptions for patients
void writePrescription();
// Displays the medical history of patients
void viewHistory();
// Searches for a patient using their ID or name
void searchPatient();
// Shows the doctor's appointments and schedule for the day
void dailySchedule();
// Allows the doctor to add notes related to patient treatment
void addNotes();
// Displays reports such as appointment summaries and patient statistics
void viewReports();

#endif
