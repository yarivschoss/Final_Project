#include "Visit.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
Visit::Visit(Patient* patient, const char* purpose,const Department* department, Employee* staff, time_t visitDate)
    : patient(patient), department(department), staff(staff), visitDate(visitDate), purpose(nullptr)
{
    setPurpose(purpose);
}

// Destructor
Visit::~Visit()
{
    delete[] purpose;
}

// Setters
 bool Visit::setVisitDate(time_t date)
{
     if (!date) return false;

    visitDate = date;
    return true;
}

bool Visit::setPurpose(const char* purpose)
{
    if (!purpose) return false;  // Check if the provided name is valid

    delete[] this->purpose;  // Free previously allocated memory
    this->purpose = new char[strlen(purpose) + 1];  // Allocate new memory for the name
    strcpy(this->purpose, purpose);  // Copy the name
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



