#pragma warning(disable: 4996)
using namespace std;

#include <iostream>
#include <cstring>
#include "Hospital.h"


enum eChoice { AddDepartment = 1, AddDoctorHospital , AddNurseHospital, AddDoctorDepartment, AddNurseDepartment, AddPatient,AddVisit,
    ShowPatientsByDepartment,FindPatientById,ShowDepartments, ShowDoctorsByNameOnly, ShowNursesByNameOnly, ShowHospitalcrewdata , ClearConsole, Exit };


int main() 
{
    
    char name[100];
    cout << "Enter Hospital name: ";
    cin.ignore();
    cin.getline(name, 100);

    Hospital hospital(name);

    int choice;
    bool running = true;

    while (running) {
       
        cout << "\nMenu:" << endl;
        cout << "1. Add Department to Hospital" << endl;
        cout << "2. Add Doctor to Hospital" << endl;
        cout << "3. Add Nurse to Hospital" << endl;
        cout << "4. Add Doctor to Department" << endl;
        cout << "5. Add Nurse to Department" << endl;
        cout << "6. AddPatient" << endl;
        cout << "7. Add Visit" << endl;
        cout << "8. Show Patients by Department" << endl;
        cout << "9. Find Patient by ID" << endl;
        cout << "10. Show Departments in Hospital" << endl;
        cout << "11. Show Doctors in Hospital by name only" << endl;
        cout << "12. Show Nurses in Hospital by name only" << endl;
        cout << "13. Show Hospital crew data" << endl;
        cout << "14. Clear console" << endl;
        cout << "15. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;

        switch (choice) 
        {

        case AddDoctorHospital:
        {
            char name[100], gender;
            int birthYear, occupation;

            cout << "Enter doctor's name: ";
            cin.ignore();
            cin.getline(name, 100);
            cout << "Enter doctor's birth year: ";
            cin >> birthYear;
            cout << "Enter doctor's gender(m/f): ";
            cin >> gender;
            cout << "Select occupation (0 - Pathology, 1 - Dentist, 2 - Psychiatrist, 3 - Neurologist): ";
            cin >> occupation;
            Doctor::eOccupation doctorOccupation = (Doctor::eOccupation)occupation;

            Person p(name, birthYear, gender);
            Employee e(p);

            Doctor newDoctor(e, doctorOccupation); // goes to employee c'tor 2 times (need to check how to fix) 
            hospital.addDoctor(newDoctor);
           
            break;
        }

        case AddNurseHospital:
        {
            char name[100], gender;
            int birthYear, experience;

            cout << "Enter nurse's name: ";
            cin.ignore();
            cin.getline(name, 100);
            cout << "Enter nurse's birth year: ";
            cin >> birthYear;
            cout << "Enter nurse's gender(m/f): ";
            cin >> gender;
            cout << "Enter years of experience: ";
            cin >> experience;

            Person p(name, birthYear, gender);
            Employee e(p); 

            Nurse newNurse(e, experience); // goes to employee c'tor 2 times (need to check how to fix) 
            hospital.addNurse(newNurse);
            break;
        }

        case AddDepartment: 
        {
            char departmentName[100];
            cout << "Enter department name: ";
            cin.ignore();
            cin.getline(departmentName, 100);

            hospital.addDepartmant(departmentName);
            break;
        }

        case AddDoctorDepartment:
        {
            char name[100];

            hospital.showDoctors();
            cout << "choose doctor: ";
            cin.ignore();
            cin.getline(name, 100);
            Doctor* D = hospital.getDoctor(name); //by pointer so we will not create another doctor with the same parameters

            hospital.showDepartments();
            cout << "\nchoose department: ";
            cin.getline(name, 100);
            
           hospital.getDepartment(name)->addDoctor(*D); // using the operator overloading '[]'

            break;
        }

        case AddNurseDepartment:
        {
            char name[100];

            hospital.showNurses();
            cout << "choose nurse: ";
            cin.ignore();
            cin.getline(name, 100);
            Nurse* N = hospital.getNurse(name); //by pointer so we will not create another nurse with the same parameters

            hospital.showDepartments();
            cout << "\nchoose department: ";
            cin.getline(name, 100);

            hospital.getDepartment(name)->addNurse(*N); 

            break;
        }


        case AddPatient:
        {
            char name[100], gender;
            int birthYear;

            // Get patient details from the user
            cout << "Enter patient's name: ";
            cin.ignore();
            cin.getline(name, 100);

            cout << "Enter patient's birth year: ";
            cin >> birthYear;

            cout << "Enter patient's gender (m/f): ";
            cin >> gender;

            // Create a Person object
            Person p(name, birthYear, gender);

            // Add the patient to the hospital and get the new ID
            int patientID = hospital.addPatient(p);
            if (patientID != -1) {
                cout << "Patient added successfully! ID: " << patientID << endl;
            }
            else {
                cout << "Failed to add patient. Hospital might be full." << endl;
            }
            break;
        }





       
        case AddVisit:
        {
            int patientID;
            char purpose[100], departmentName[100], staffName[100];

            // Check if the patient exists
            cout << "Is the patient already in the system? (y/n): ";
            char isExisting;
            cin >> isExisting;

            if (isExisting == 'n' || isExisting == 'N') {
                // Add a new patient
                char name[100], gender;
                int birthYear;

                cout << "Enter patient's name: ";
                cin.ignore();
                cin.getline(name, 100);

                cout << "Enter patient's birth year: ";
                cin >> birthYear;

                cout << "Enter patient's gender (m/f): ";
                cin >> gender;

                // Create a new patient and add them to the hospital
                Person p(name, birthYear, gender);
                patientID = hospital.addPatient(p);
                if (patientID == -1) {
                    cout << "Failed to add patient. Hospital might be full." << endl;
                    break;
                }

                cout << "Patient added successfully! ID: " << patientID << endl;
            }
            else if (isExisting == 'y' || isExisting == 'Y') {
                // Display all patient IDs
                cout << "Existing patient IDs:" << endl;
                for (int i = 0; i < hospital.getNumOfPatients(); ++i) {
                    cout << "- " << hospital.getPatient(i)->getId() << endl;
                }

                // Select a patient by ID
                cout << "Enter patient ID from the list above: ";
                cin >> patientID;
            }
            else {
                cout << "Invalid input. Returning to the main menu." << endl;
                break;
            }

            // Get visit purpose
            cout << "Enter visit purpose: ";
            cin.ignore();
            cin.getline(purpose, 100);

            // Show available departments
            cout << "\nAvailable departments:" << endl;
            hospital.showDepartments();

            // Get department name
            cout << "Enter department name: ";
            cin.getline(departmentName, 100);

            // Show available staff
            cout << "\nAvailable staff (doctors and nurses):" << endl;
            hospital.showDoctors();
            hospital.showNurses();

            // Get staff name
            cout << "Enter staff name: ";
            cin.getline(staffName, 100);

            // Get visit date
            cout << "Enter visit date (YYYY-MM-DD): ";
            int year, month, day;
            char separator;
            cin >> year >> separator >> month >> separator >> day;

            struct tm timeStruct = { 0 };
            timeStruct.tm_year = year - 1900;
            timeStruct.tm_mon = month - 1;
            timeStruct.tm_mday = day;
            time_t visitDate = mktime(&timeStruct);

            // Add the visit
            if (hospital.addVisit(patientID, purpose, departmentName, staffName, visitDate)) {
                cout << "Visit added successfully!" << endl;
            }
            else {
                cout << "Failed to add visit!" << endl;
            }
            break;
        }








        case ShowPatientsByDepartment:
        {
            // Show patients by department
            hospital.showDepartments();

            char departmentName[100];
            cout << "Enter department name from the list: ";
            cin.ignore();
            cin.getline(departmentName, 100);

            hospital.showPatientsInDepartment(departmentName);
            break;
        }

        case FindPatientById:
        {

            // Display all patient IDs
            cout << "Existing patient IDs:" << endl;
            for (int i = 0; i < hospital.getNumOfPatients(); ++i)
            {
                cout << "- " << hospital.getPatient(i)->getId() << endl;
            }


            int patientID;
            cout << "Enter patient ID from the list: ";
            cin >> patientID;

            // Find the patient by ID
            Patient* patient = hospital.findPatientById(patientID);
            if (patient) {
                cout << "Patient Name: " << patient->getName() << endl;

                // Find the visit associated with the patient
                Visit* visit = hospital.getVisitByPatientId(patientID);
                if (visit) {
                    // Pass the patient to the function as a parameter
                    Department* department = visit->getDepartmentForPatient(patient);
                    if (department) {
                        cout << "Assigned Department: " << department->getName() << endl;
                    }
                    else {
                        cout << "No department assigned yet." << endl;
                    }
                }
                else {
                    cout << "No visit found for the patient." << endl;
                }
            }
            else {
                cout << "Patient not found!" << endl;
            }
            break;
        }



        case ShowDepartments:
        {
            hospital("departments");
            break;
        }

        case  ShowDoctorsByNameOnly:
        {
            hospital("doctors");
            break;
        }

        case ShowNursesByNameOnly:
        {
            hospital("nurses");
            break;
        }

        case ShowHospitalcrewdata:
        {
            cout << endl << hospital;
            break;
        }

        case ClearConsole:
        {
            std::cout << "\033[2J\033[H"; // ANSI escape code to clear screen and move cursor to home position
            break;
        }

        case Exit: 
        {
            running = false;
            break;
        } // need to check memory freeing

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}






