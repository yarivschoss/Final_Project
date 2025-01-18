// Yariv Shossberger 316523406
// Gal Fridman 207495524

#pragma warning(disable: 4996)
using namespace std;

#include <iostream>
#include <cstring>
#include "Hospital.h"

int const MAX_STRING_SIZE = 100, DEFAULT_BIRTH_YEAR = 2000, DEFAULT_GENDER = 109, DEFAULT_EXPERIENCE = 5;
const char DEFAULT_NAME[] = "Default Name";
const time_t DEFAULT_TIME = 0;
Doctor::eOccupation DEFAULT_OCCUPATION = Doctor::eOccupation::Pathology;


enum eChoice { AddDepartment = 1, AddDoctorHospital , AddNurseHospital,
    AddResearcher, AddDoctorDepartment, AddNurseDepartment, AddPaper, AddPatient,AddVisit,
    ShowPatientsByDepartment,FindPatientById, ShowResearchers, ShowDepartments, ShowDoctorsByNameOnly,
    ShowNursesByNameOnly, ShowHospitalcrewdata , CompareResearchers, ClearConsole, Exit };


int main() 
{
    char name[MAX_STRING_SIZE], Hname[MAX_STRING_SIZE], Rname[MAX_STRING_SIZE], gender;
    int choice, birthYear;

    Hospital hospital(DEFAULT_NAME, DEFAULT_NAME);

    cin >> hospital;

    bool running = true;

    while (running) 
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add Department to Hospital" << endl;
        cout << "2. Add Doctor to Hospital" << endl;
        cout << "3. Add Nurse to Hospital" << endl;
        cout << "4. Add Researcher to Research Center" << endl; 
        cout << "5. Add Doctor to Department" << endl;
        cout << "6. Add Nurse to Department" << endl;
        cout << "7. Add Paper to Researcher" << endl; 
        cout << "8. Add Patient" << endl;
        cout << "9. Add Visit" << endl;
        cout << "10. Show Patients by Department" << endl; 
        cout << "11. Find Patient by ID" << endl;
        cout << "12. Show Researchers in Research Center" << endl; 
        cout << "13. Show Departments in Hospital" << endl;
        cout << "14. Show Doctors in Hospital" << endl;
        cout << "15. Show Nurses in Hospital" << endl;
        cout << "16. Show Hospital crew data" << endl;
        cout << "17. Compare Researchers by number of papers" << endl;
        cout << "18. Clear console" << endl;
        cout << "19. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
       
        cout << endl;

        switch (choice) 
        {

        case(AddResearcher):
        {
            Researcher newResearcher(Employee(Person(DEFAULT_NAME, DEFAULT_BIRTH_YEAR, DEFAULT_GENDER)));

            cin >> newResearcher;

            hospital.getResearchCenter() += newResearcher;
             
            break;
        }

        case(AddPaper):
        {
            hospital.getResearchCenter().showResearchers();
            cout << endl;
            cout << "Choose researcher: ";
            cin.getline(name, MAX_STRING_SIZE);

            Researcher* r = hospital.getResearchCenter().getResearcher(name);

            if (!r)
            {
                cout << "no existing researcher found" << endl;
                choice = AddPaper;
                break;
            }

            Paper newPaper(DEFAULT_NAME, DEFAULT_NAME, DEFAULT_TIME);

            cin >> newPaper;

            r->addPaper(newPaper);

            break;
        }

        case(ShowResearchers):
        {
            hospital.getResearchCenter()("researchers");
            cout << endl;
            break;
        }

        case(CompareResearchers):
        {
            hospital.getResearchCenter().showResearchers();
            cout << endl;

            cout << "Choose Researchers" << endl;
            cout << "Researcher 1: ";
            cin.getline(name, MAX_STRING_SIZE);

            Researcher* r1 = hospital.getResearchCenter().getResearcher(name);

            if (!r1)
            {
                cout << "no existing researcher found" << endl;
                choice = CompareResearchers;
                break;
            }

            cout << "Researcher 2: ";
            cin.getline(name, MAX_STRING_SIZE);

            Researcher* r2 = hospital.getResearchCenter().getResearcher(name);

            if (!r2)
            {
                cout << "no existing researcher found" << endl;
                choice = CompareResearchers;
                break;
            }

            if(*r1 > *r2) 
            {
                cout << r1->getName() << " has more papers" << endl;
                break;
            }

            if (*r1 < *r2)
            {
                cout << r2->getName() << " has more papers" << endl;
                break;
            }

            cout << r1->getName() << " and " << r2->getName() << " has the same amount of papers" << endl;
            break;
        }
            
        case AddDoctorHospital:
        {
            Doctor newDoctor(Employee(Person(DEFAULT_NAME, DEFAULT_BIRTH_YEAR, DEFAULT_GENDER)), DEFAULT_OCCUPATION);

            cin >> newDoctor;

            hospital += newDoctor;
           
            break;
        }

        case AddNurseHospital:
        {
            Nurse newNurse(Employee(Person(DEFAULT_NAME, DEFAULT_BIRTH_YEAR, DEFAULT_GENDER)), DEFAULT_EXPERIENCE);

            cin >> newNurse;

            hospital += newNurse;

            break;
        }

        case AddDepartment: 
        {
            cout << "Enter department name: ";
            cin.getline(name, MAX_STRING_SIZE);

            hospital.addDepartmant(name);
            break;
        }

        case AddDoctorDepartment:
        {
            hospital.showDoctors();
            cout << "choose doctor: ";
            cin.getline(name, MAX_STRING_SIZE);

            Doctor* D = hospital.getDoctor(name); //by pointer so we will not create another doctor with the same parameters

            if (!D)
            {
                cout << "no existing doctor found" << endl;
                choice = AddDoctorDepartment;
                break;
            }

            hospital.showDepartments();
            cout << "\nchoose department: ";
            cin.getline(name, MAX_STRING_SIZE);
            
            if (!hospital.getDepartment(name)->addDoctor(*D))
            {
                cout << "no existing department found" << endl;
                choice = AddDoctorDepartment;
                break;
            }
           
            break;
        }

        case AddNurseDepartment:
        {
            hospital.showNurses();
            cout << "choose nurse: ";
            cin.getline(name, MAX_STRING_SIZE);

            Nurse* N = hospital.getNurse(name); //by pointer so we will not create another nurse with the same parameters

            if (!N)
            {
                cout << "no existing nurse found" << endl;
                choice = AddNurseDepartment;
                break;
            }

            hospital.showDepartments();
            cout << "\nchoose department: ";
            cin.getline(name, MAX_STRING_SIZE);

            if (!hospital.getDepartment(name)->addNurse(*N))
            {
                cout << "no existing department found" << endl;
                choice = AddNurseDepartment;
                break;
            }

            break;
        }

        case AddPatient:
        {
            // Get patient details from the user
            cout << "Enter patient's name: ";
            cin.getline(name, MAX_STRING_SIZE);

            cout << "Enter patient's birth year: ";
            cin >> birthYear;

            cout << "Enter patient's gender (m/f): ";
            cin >> gender;

            // Create a Person object
            Person p(name, birthYear, gender);

            // Add the patient to the hospital and get the new ID
            int patientID = hospital.addPatient(p);
            if (patientID != -1) 
            {
                cout << "Patient added successfully! ID: " << patientID << endl;
            }
            else 
            {
                cout << "Failed to add patient. Hospital might be full." << endl;
            }
            break;
        }

        case AddVisit:
        {
            int patientID;
            char purpose[MAX_STRING_SIZE], departmentName[MAX_STRING_SIZE], staffName[MAX_STRING_SIZE];

            // Check if the patient exists
            cout << "Is the patient already in the system? (y/n): ";
            char isExisting;
            cin >> isExisting;

            if (isExisting == 'n' || isExisting == 'N') {
                // Add a new patient

                cout << "Enter patient's name: ";
                cin.ignore();
                cin.getline(name, MAX_STRING_SIZE);

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
            cin.getline(purpose, MAX_STRING_SIZE);

            // Show available departments
            cout << "\nAvailable departments:" << endl;
            hospital.showDepartments();

            // Get department name
            cout << "Enter department name: ";
            cin.getline(departmentName, MAX_STRING_SIZE);

            // Show available staff
            cout << "\nAvailable staff (doctors and nurses):" << endl;
            hospital.showDoctors();
            hospital.showNurses();

            // Get staff name
            cout << "Enter staff name: ";
            cin.getline(staffName, MAX_STRING_SIZE);

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

            cout << "Enter department name from the list: ";
            cin.getline(name, MAX_STRING_SIZE);

            hospital.showPatientsInDepartment(name);
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






