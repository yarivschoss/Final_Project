#include "SurgeryVisit.h"
#include <iostream>
#include <typeinfo>

using namespace std;


SurgeryVisit::SurgeryVisit(Patient* patient, const char* purpose, Department* department, Employee* staff, time_t visitDate, int room, bool fasting)
    : Visit(patient, purpose, department, staff, visitDate), surgeryRoomNumber(room), isFasting(fasting)
{
    
    if (typeid(*staff) != typeid(Surgeon)) {
        cout << "Error: Staff member in a surgery visit must be a Surgeon!" << endl;
        exit(1);
    }
}

void SurgeryVisit::show() const
{
    cout << "Surgery Visit for patient: " << patient->getName() << " (ID: " << patient->getId() << ")\n";
    cout << "Date: " << ctime(&visitDate);
    cout << "Purpose: " << purpose << "\n";
    cout << "Department: " << department->getName() << "\n";
    cout << "Surgeon: " << staff->getName() << "\n";
    cout << "Surgery Room: " << surgeryRoomNumber << "\n";
    cout << "Fasting: " << (isFasting ? "Yes" : "No") << "\n";
}


const char* SurgeryVisit::getVisitType() const
{
    return "Surgery";
}

// Getters
int SurgeryVisit::getSurgeryRoomNumber() const
{
    return surgeryRoomNumber;
}

bool SurgeryVisit::getIsFasting() const
{
    return isFasting;
}
