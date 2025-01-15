#pragma warning(disable: 4996)
using namespace std;

#include <iostream>
#include <cstring>
#include "Hospital.h"


enum eChoice { AddDepartment = 1, AddDoctorHospital , AddNurseHospital, AddDoctorDepartment, AddNurseDepartment, 
    ShowDepartments, ShowDoctors, ShowNurses, ShowHospital, ClearConsole, Exit };


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
        cout << "6. Show Departments in Hospital" << endl;
        cout << "7. Show Doctors in Hospital" << endl;
        cout << "8. Show Nurses in Hospital" << endl;
        cout << "9. Show all Hospital data" << endl;
        cout << "10. Clear console" << endl;
        cout << "11. Exit" << endl;
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

        case ShowDepartments:
        {
            hospital("departments");
            break;
        }

        case ShowDoctors:
        {
            hospital("doctors");
            break;
        }

        case ShowNurses:
        {
            hospital("nurses");
            break;
        }

        case ShowHospital: 
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






