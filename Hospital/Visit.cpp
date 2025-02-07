#include "Visit.h"
#include <iostream>
#include <cstring>
using namespace std;





// Setters
 bool Visit::setVisitDate(time_t date)
{
     if (!date) return false;

    visitDate = date;
    return true;
}

bool Visit::setPurpose(const string& purpose)
{
    this->purpose = purpose;
    return true;
}

bool Visit::setDepartment(Department* department)
{
    if (!department) return false;

    this->department = department;
    return true;
}

bool Visit::setStaff(Employee* staff)
{
    if (!staff) return false;

    this->staff = staff;
    return true;
}




const Department* Visit::getDepartmentForPatient(const Patient* patient) const
{
    cout << "Debug: Visit patient: " << this->patient->getName()
        << ", Input patient: " << patient->getName() << endl;

    if (this->patient == patient)
    {
        return department;
    }

    return nullptr;
}




// Display function
void Visit::show() const
{
    cout << "Visit Details:" << endl;
    cout << "Patient: ";
    if (patient) {
        cout << patient->getName();
    }
    else {
        cout << "Unknown";
    }
    cout << endl;

    cout << "Date: " << ctime(&visitDate);

    cout << "Purpose: " << purpose << endl;

    cout << "Department: ";
    if (department) {
        cout << department->getName();
    }
    else {
        cout << "Unknown";
    }
    cout << endl;

    cout << "Staff: ";
    if (staff) {
        cout << staff->getName();
    }
    else {
        cout << "Unknown";
    }
    cout << endl;
}

// Overloaded operator for output
ostream& operator<<(ostream& os, const Visit& v)
{
    os << "Visit for patient ";

    if (v.patient) 
        os << v.patient->getName() << " (ID: " << v.patient->getId() << ")";

    else
    {
        os << "Unknown";
        return os;
    }
     
    os << ", Purpose: " << v.purpose;


    os << ", Date: ";
    if (v.visitDate != -1)
    {
        os << ctime(&v.visitDate); 
    }
    else {
        os << "Invalid date"; 
    }


    os << ", Department: ";
    if (v.department) {
        os << v.department->getName();
    }
    else {
        os << "Unknown";
    }

    os << ", Staff: ";
    if (v.staff) {
        os << v.staff->getName();
    }
    else {
        os << "Unknown";
    }

    return os;
}







