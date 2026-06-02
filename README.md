# 🏥 Hospital Management System

A console-based **Hospital Management System** developed in **C++** using **Multifiling, File Handling, Functions, and Modular Programming** concepts. The system helps manage hospital operations through separate Doctor, Admin, and Medicine modules while storing records in text files.

---

# 📖 Project Overview

The Hospital Management System is designed to streamline hospital management tasks such as handling patient records, doctor records, appointments, prescriptions, medicine inventory, invoices, and reports.

The project follows a **multifile architecture**, where each module is implemented in separate source (`.cpp`) and header (`.h`) files for better organization, maintainability, and team collaboration.

---

# ✨ Features

## 👨‍⚕️ Doctor Portal

The Doctor Portal provides functionalities for managing patient care and appointments.

* View Appointments
* Cancel Appointments
* Write Prescriptions
* View Patient History
* Search Patients
* View Daily Schedule
* Add Medical Notes
* View Reports
* View Doctor Profile

---

## 🔐 Admin Portal

The Admin Portal manages hospital records, doctors, patients, and reports.

### Patient Management

* Add Patient Records
* Display All Patients
* View Patient History
* Search Patient by ID
* Search Patient by Name
* Update Patient Records
* Remove Patient Records
* Search Patients by Disease

### Doctor Management

* Add Doctor Records
* Display All Doctors
* View Doctor History
* Search Doctor by ID
* Search Doctor by Name
* Update Doctor Records
* Remove Doctor Records
* Search Doctors by Specialization
* Update Doctor Salary

### Reports & Statistics

* Hospital Statistics Report
* Payroll Report

---

## 💊 Medicine Portal

The Medicine Portal manages medicine inventory and billing operations.

* Add New Medicines
* View All Medicines
* Search Medicine by ID
* Update Medicine Quantity
* Delete Medicine Records
* Check Low Stock Medicines
* Medicine Expiry Alerts
* Generate Invoices

---

# 🛠 Technologies Used

* C++
* File Handling (`fstream`)
* Multifiling
* Structures
* Functions
* Arrays
* Loops
* Conditional Statements
* Menu-Driven Programming

---

# 📂 Project Structure

```text
Hospital-Management-System
│
├── main.cpp
├── common.cpp
├── common.h
│
├── doctor.cpp
├── doctor.h
│
├── admin.cpp
├── admin.h
│
├── medicine.cpp
├── medicine.h
│
├── appointments.txt
├── doctors_data.txt
├── patients.txt
├── patients_data.txt
├── prescriptions.txt
├── history.txt
├── notes.txt
├── medicine.txt
├── invoices.txt
│
├── hospital.exe
├── .gitignore
└── README.md
```

---

# 💾 Data Files

| File Name         | Description                  |
| ----------------- | ---------------------------- |
| appointments.txt  | Appointment records          |
| doctors_data.txt  | Doctor information           |
| patients.txt      | Patient records              |
| patients_data.txt | Detailed patient information |
| prescriptions.txt | Doctor prescriptions         |
| history.txt       | Patient medical history      |
| notes.txt         | Doctor notes                 |
| medicine.txt      | Medicine inventory           |
| invoices.txt      | Billing and invoice records  |

---

# 🔄 Multifiling Implementation

This project is developed using **multifiling**, where different modules are separated into independent files:

* **doctor.cpp / doctor.h** → Doctor Portal
* **Admin.cpp / admin.h** → Admin Portal
* **medicine.cpp / medicine.h** → Medicine Portal
* **common.cpp / common.h** → Shared utility functions
* **main.cpp** → Main menu and program execution

### Benefits of Multifiling

* Better code organization
* Easier debugging and maintenance
* Improved code reusability
* Efficient teamwork and collaboration

---

# 🚀 How to Run

### Compile

```bash
g++ main.cpp doctor.cpp Admin.cpp medicine.cpp common.cpp -o hospital
```

### Run

#### Windows

```bash
hospital.exe
```

#### Linux / Mac

```bash
./hospital
```

---

# 👥 Team Members

This project was developed by a team of three students as part of the **Programming Fundamentals (PF)** course.

* Member 1 – Doctor Portal
* Member 2 – Admin Portal
* Member 3 – Medicine Portal

---

# 📚 Academic Project

Developed for the **Programming Fundamentals (PF)** course in the **BS Artificial Intelligence** program.

---

⭐ If you find this project useful, consider giving it a star on GitHub.
