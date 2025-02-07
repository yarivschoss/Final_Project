#include "CheckupVisit.h"
#include <iostream>
#include <typeinfo>

using namespace std;


CheckupVisit::CheckupVisit(Patient* patient, const string& purpose,
    Department* department, Employee* staff, time_t visitDate)
    : Visit(patient, purpose, department, staff, visitDate)
{
    /*
    if (!(typeid(*staff) == typeid(Doctor) || typeid(*staff) == typeid(Nurse))) {
        cout << "Error: Staff member in a checkup visit must be a Doctor or a Nurse!" << endl;
        exit(1);
    }
    */
}


void CheckupVisit::show() const 
{
    Visit::show();
    /*
    cout << "Checkup Visit for patient: " << patient->getName() << " (ID: " << patient->getId() << ")\n";
    cout << "Date: " << ctime(&visitDate);
    cout << "Purpose: " << purpose << "\n";
    cout << "Department: " << department->getName() << "\n";
    */
    
    cout << "Staff: " << staff->getName() << " (" << (typeid(*staff) == typeid(Nurse) ? "Nurse" : "Doctor") << ")\n";
}


const string& CheckupVisit::getVisitType() const
{
    return "Checkup";
}
