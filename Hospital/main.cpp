// Yariv Shossberger 316523406
// Gal Fridman 207495524

#pragma warning(disable: 4996)
using namespace std;

#include <iostream>
#include <string>
#include <cstring>
#include "Hospital.h"

int const MAX_STRING_SIZE = 100, DEFAULT_BIRTH_YEAR = 2000, DEFAULT_GENDER = 109, DEFAULT_EXPERIENCE = 5;
const string DEFAULT_NAME = "Default Name";
const time_t DEFAULT_TIME = 0;
Doctor::eOccupation DEFAULT_OCCUPATION = Doctor::eOccupation::Pathology;


enum eChoice { AddDepartment = 1, AddEmployeeHospital, AddToResearchCenter, AddEmployeeDepartment, AddPaper, AddPatient,AddVisit,
    ShowPatientsByDepartment,FindPatientById, ShowInfo , CompareResearchers, ClearConsole, Exit };


int main() 
{
    string name, Hname, Rname;
    char gender;
    int choice, birthYear;

    Hospital hospital(DEFAULT_NAME, DEFAULT_NAME);

    cin >> hospital;

    bool running = true;

    while (running) 
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add Department to Hospital" << endl;
        cout << "2. Add Employee to Hospital" << endl;
        cout << "3. Add Researcher to Research Center" << endl; 
        cout << "4. Add Employee to Department" << endl;
        cout << "5. Add Paper to Researcher" << endl; 
        cout << "6. Add Patient" << endl;
        cout << "7. Add Visit" << endl;
        cout << "8. Show Patients visits by Department" << endl; 
        cout << "9. Find Patient by ID" << endl;
        cout << "10. Show system's info" << endl;
        cout << "11. Compare Researchers by number of papers" << endl;
        cout << "12. Clear console" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
       
        cout << endl;

        switch (choice) 
        {

        case(AddToResearchCenter):
        {

            enum eChoiceAddResearcher { AddResearcher = 1, AddResearcherDoctor, ClearConsole, eReturn };
            bool Return = false;

            while (!Return)

            {
                cout << endl;
                cout << "1. Add Researcher" << endl;
                cout << "2. Add Researcher Doctor" << endl;
                cout << "3. Clear console" << endl;
                cout << "4. Return" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();

                switch (choice)
                {

                case(AddResearcher):
                {

                    Researcher newResearcher(Employee(Person(DEFAULT_NAME, DEFAULT_BIRTH_YEAR, DEFAULT_GENDER)));

                    cin >> newResearcher;

                    hospital.getResearchCenter() += newResearcher;

                    break;

                }

                case (AddResearcherDoctor):
                {
                    ResearcherDoctor newResearcherDoctor(Doctor(Employee(Person(DEFAULT_NAME, DEFAULT_BIRTH_YEAR, DEFAULT_GENDER)), DEFAULT_OCCUPATION), Researcher(Employee(Person(DEFAULT_NAME, DEFAULT_BIRTH_YEAR, DEFAULT_GENDER))));

                    cin >> newResearcherDoctor;

                    hospital.getResearchCenter() += newResearcherDoctor;

                    hospital += newResearcherDoctor;

                    break;
                }

                case (ClearConsole):
                {
                    std::cout << "\033[2J\033[H"; // ANSI escape code to clear screen and move cursor to home position
                    break;
                }

                case(eReturn):
                {
                    Return = true;
                    break;
                }

                default:
                    cout << "Invalid choice" << endl;
                }
            }

            break;

        }

        case(AddPaper):
        {
            hospital.getResearchCenter().showResearchers();
            cout << endl;
            cout << "Choose researcher: ";
            getline(cin,name);

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

        case(CompareResearchers):
        {
            hospital.getResearchCenter().showResearchers();
            cout << endl;

            cout << "Choose Researchers" << endl;
            cout << "Researcher 1: ";
            getline(cin,name);

            Researcher* r1 = hospital.getResearchCenter().getResearcher(name);

            if (!r1)
            {
                cout << "no existing researcher found" << endl;
                choice = CompareResearchers;
                break;
            }

            cout << "Researcher 2: ";
            getline(cin,name);

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
            
        case(AddEmployeeHospital):
        {
            enum eChoiceAddEmployeeHospital {AddDoctorHospital = 1, AddNurseHospital, AddSurgeonHospital, ClearConsole, eReturn };
            bool Return = false;

            while(!Return)

            {
                cout << endl;
                cout << "1. Add Doctor to Hospital" << endl;
                cout << "2. Add Nurse to Hospital" << endl;
                cout << "3. Add Surgeon to Hospital" << endl;
                cout << "4. Clear console" << endl;
                cout << "5. Return" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();

                switch (choice)
                {

                case(AddDoctorHospital):
                {

                    Doctor newDoctor(Employee(Person(DEFAULT_NAME, DEFAULT_BIRTH_YEAR, DEFAULT_GENDER)), DEFAULT_OCCUPATION);

                    cin >> newDoctor;

                    hospital += newDoctor;

                    break;
                }

                case (AddNurseHospital):
                {
                    Nurse newNurse(Employee(Person(DEFAULT_NAME, DEFAULT_BIRTH_YEAR, DEFAULT_GENDER)), DEFAULT_EXPERIENCE);

                    cin >> newNurse;

                    hospital += newNurse;

                    break;
                }

                case(AddSurgeonHospital):
                {

                    Surgeon newSurgeon(Doctor(Employee(Person(DEFAULT_NAME, DEFAULT_BIRTH_YEAR, DEFAULT_GENDER)), DEFAULT_OCCUPATION), 0);

                    cin >> newSurgeon;

                    hospital += newSurgeon;

                    break;
                }

                case (ClearConsole):
                {
                    std::cout << "\033[2J\033[H"; // ANSI escape code to clear screen and move cursor to home position
                    break;
                }

                case(eReturn):
                {
                    Return = true;
                    break;
                }

                default:
                    cout << "Invalid choice" << endl;
                }
            }

            break;
        }

        case(AddDepartment):
        {
            cout << "Enter department name: ";
            getline(cin,name);

            hospital.addDepartmant(name);
            break;
        }

        case(AddEmployeeDepartment):
        {
            enum eChoiceAddEmployeeDepartment { AddDoctorDepartment = 1, AddNurseDepartment, AddSurgeonDepartment, ClearConsole, eReturn };
            bool Return = false;

            while (!Return)

            {
                cout << endl;
                cout << "1. Add Doctor to Department" << endl;
                cout << "2. Add Nurse to Department" << endl;
                cout << "3. Add Surgeon to Department" << endl;
                cout << "4. Clear console" << endl;
                cout << "5. Return" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();

                switch (choice)
                {

                case(AddDoctorDepartment):
                {

                    hospital("doctors");
                    cout << "choose doctor: ";
                    getline(cin,name);

                    Doctor* D = dynamic_cast<Doctor*>(hospital.getEmployee(name)); //by pointer so we will not create another doctor with the same parameters

                    if (!D)
                    {
                        cout << "no existing doctor found" << endl;
                        break;
                    }

                    hospital("departments");
                    cout << "\nchoose department: ";
                    getline(cin,name);

                    if (!hospital.getDepartment(name)->addEmployee(*D))
                    {
                        cout << "no existing department found" << endl;
                        break;
                    }

                    break;
                }

                case (AddNurseDepartment):
                {
                    hospital.showNurses();
                    cout << "choose nurse: ";
                    getline(cin,name);

                    Nurse* N = dynamic_cast<Nurse*>(hospital.getEmployee(name)); //by pointer so we will not create another nurse with the same parameters

                    if (!N)
                    {
                        cout << "no existing nurse found" << endl;
                        choice = AddNurseDepartment;
                        break;
                    }

                    hospital.showDepartments();
                    cout << "\nchoose department: ";
                    getline(cin,name);

                    if (!hospital.getDepartment(name)->addEmployee(*N))
                    {
                        cout << "no existing department found" << endl;
                        choice = AddNurseDepartment;
                        break;
                    }

                    break;
                }

                case(AddSurgeonDepartment):
                {
                    hospital("surgeons");
                    cout << "choose surgeon: ";
                    getline(cin,name);

                    Surgeon* S = dynamic_cast<Surgeon*>(hospital.getEmployee(name)); //by pointer so we will not create another doctor with the same parameters

                    if (!S)
                    {
                        cout << "no existing surgeon found" << endl;
                        break;
                    }

                    hospital("departments");
                    cout << "\nchoose department: ";
                    getline(cin,name);

                    if (!hospital.getDepartment(name)->addEmployee(*S))
                    {
                        cout << "no existing department found" << endl;
                        break;
                    }

                    break;
                }

                case (ClearConsole):
                {
                    std::cout << "\033[2J\033[H"; // ANSI escape code to clear screen and move cursor to home position
                    break;
                }

                case(eReturn):
                {
                    Return = true;
                    break;
                }

                default:
                    cout << "Invalid choice" << endl;
                }
            }

            break;
        }

        case (AddPatient): {
            // Get patient details from the user

            cout << "Enter patient's name: ";
            getline(cin, name);

            cout << "Enter patient's birth year: ";
            cin >> birthYear;

            cout << "Enter patient's gender (m/f): ";
            cin >> gender;

            // Create a Person object
            Person p(name, birthYear, gender);

           
            const Patient* newPatient = hospital.addPatient(p);

            // Add the patient to the hospital
            if (!newPatient) 
            {
                cout << "Failed to add patient. Hospital might be full." << endl;
            }
            else {
                // Retrieve the newly added patient and display their ID
                if (newPatient) {
                    int patientID = newPatient->getId();
                    cout << "Patient added successfully! ID: " << patientID << endl;
                }
                else {
                    cout << "Failed to retrieve the newly added patient. Please check the system." << endl;
                }
            }

            break;
        }

        case (AddVisit):
        {
            int patientID;
            bool isSurgery = false;
            int room = 0;
            bool fasting = false;
            string purpose, departmentName, staffName;

            cout << "Is the patient already in the system? (y/n): ";
            char isExisting;
            cin >> isExisting;

            if (isExisting == 'n' || isExisting == 'N')
            {
                // Add a new patient
                cout << "Enter patient's name: ";
                cin.ignore();
                getline(cin,name);

                cout << "Enter patient's birth year: ";
                cin >> birthYear;

                cout << "Enter patient's gender (m/f): ";
                cin >> gender;
                cin.ignore();

                Patient p(Person(name, birthYear, gender));

                const Patient* newPatient = hospital.addPatient(p);

                if (!newPatient)
                {
                    cout << "Failed to add patient. Hospital might be full." << endl;
                    break;
                }

                if (newPatient)
                {
                    patientID = newPatient->getId();
                    cout << "Patient added successfully! ID: " << patientID << endl;
                }
            }
            else if (isExisting == 'y' || isExisting == 'Y')
            {
                // Display existing patient IDs
                cout << "Existing patient IDs:" << endl;
                for (int i = 0; i < hospital.getNumOfPatients(); ++i)
                {
                    cout << "- " << hospital.getPatient(i)->getId() << endl;
                }

                cout << "Enter patient ID from the list above: ";
                cin >> patientID;
            }
            else
            {
                cout << "Invalid input. Returning to the main menu." << endl;
                break;
            }

            

            // Ask if the visit is for a surgery or checkup
            cout << "Is this a surgery visit? (y/n): ";
            char surgeryChoice;
            cin >> surgeryChoice;

            if (surgeryChoice == 'y' || surgeryChoice == 'Y') {
                // It's a surgery visit
                isSurgery = true;

                // Ask for surgery specific data
                cout << "Enter surgery room number: ";
                cin >> room;

                cout << "Is the patient fasting? (y/n): ";
                char fastingChoice;
                cin >> fastingChoice;
                fasting = (fastingChoice == 'y' || fastingChoice == 'Y');
            }

            // Show available departments
            cout << "\nAvailable departments:" << endl;
            hospital.showDepartments();

            cout << "Enter department name: ";
            cin.ignore();
            getline(cin, departmentName);

            const Department* department = hospital.getDepartment(departmentName);
            if (!department)
            {
                cout << "Invalid department name. Visit creation failed." << endl;
                break;
            }

            // Show available staff (doctors and nurses) based on visit type
            if (isSurgery) {
                // If surgery, only show surgeons
                cout << "\nAvailable surgeons:" << endl;
                hospital.showSurgeons();
            }
            else {
                // If checkup, show doctors and nurses
                cout << "\nAvailable doctors and nurses:" << endl;
                hospital.showDoctors();
                hospital.showNurses();
            }

            cout << "Enter staff name: ";
            getline(cin, staffName);

            const Employee* staff = hospital.getEmployee(staffName);
            if (!staff)
            {
                cout << "Invalid staff name. Visit creation failed." << endl;
                break;
            }

            // Ask for visit date
                int month, day;
                char separator;

                cout << "Enter visit date (MM-DD): ";
                cin >> month >> separator >> day;

                struct tm timeStruct = {};
                timeStruct.tm_year = 2025 - 1900;  
                timeStruct.tm_mon = month - 1;     
                timeStruct.tm_mday = day;          
                
                time_t visitDate = mktime(&timeStruct);

            // Ask for the purpose of the visit
            cout << "Enter visit purpose: ";
            cin.ignore();
            getline(cin,purpose);

            // Add the visit to the hospital
            if (hospital.addVisit(patientID, purpose, departmentName, staffName, visitDate, isSurgery, room, fasting))
            {
                cout << "Visit added successfully!" << endl;
            }
            else
            {
                cout << "Failed to add visit!" << endl;
            }

            break;
        }

        case (ShowPatientsByDepartment):
        {
            // Show patients by department

            hospital.showDepartments();

            cout << "Enter department name from the list: ";
            getline(cin,name);

            hospital.showPatientsInDepartment(name.c_str());
            break;
        }

        case (FindPatientById):
        {
            // Display existing patient IDs
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
            if (patient)
            {
                // Print patient name
                cout << "Patient Name: " << patient->getName() << endl;

                // Find the visit associated with the patient
                Visit* visit = hospital.getVisitByPatientId(patientID);
                if (visit)
                {
                    // Check and display visit type (Checkup or Surgery)
                    if (typeid(*visit) == typeid(SurgeryVisit))
                        cout << "Visit Type: Surgery" << endl;
                    else if (typeid(*visit) == typeid(CheckupVisit))
                        cout << "Visit Type: Checkup" << endl;
                    else
                        cout << "Visit Type: Unknown" << endl;
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





        case (ShowInfo):
        {
            enum eChoiceShow { ShowDepartments = 1, ShowAllDoctors, ShowAllSurgeons, ShowAllNurses, ShowHospitalStaff, ShowResearchers, ClearConsole, eReturn };
            bool Return = false;

            while (!Return)

            {
                cout << endl;
                cout << "1. Show Departments in Hospital" << endl;
                cout << "2. Show Doctors in Hospital" << endl;
                cout << "3. Show Surgeons in Hospital" << endl;
                cout << "4. Show Nurses in Hospital" << endl;
                cout << "5. Show Hospital's staff" << endl;
                cout << "6. Show Researchers in Research Center" << endl;
                cout << "7. Clear console" << endl;
                cout << "8. Return" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();

                switch (choice)
                {

                case(ShowDepartments): 
                {
                    hospital("departments");
                    break;
                }

                case (ShowAllDoctors): 
                {
                    hospital("doctors");
                    break;
                }

                case (ShowAllSurgeons):
                {
                    hospital("surgeons");
                    break;
                }

                case(ShowAllNurses): 
                {
                    hospital("nurses");
                    break;
                }

                case(ShowHospitalStaff): 
                {
                    cout << endl << hospital;
                    break;
                }

                case(ShowResearchers): 
                {
                    hospital.getResearchCenter()("researchers");
                    cout << endl;
                    break;
                }

                case (ClearConsole):
                {
                    std::cout << "\033[2J\033[H"; // ANSI escape code to clear screen and move cursor to home position
                    break;
                }

                case(eReturn):
                {
                    Return = true;
                    break;
                }

                default:
                    cout << "Invalid choice" << endl;
                }
            }

        }

        case (ClearConsole):
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






