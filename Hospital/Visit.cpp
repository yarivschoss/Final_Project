#include "Visit.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
Visit::Visit(Patient* patient, const char* purpose, Department* department, Employee* staff, time_t visitDate)
    : patient(patient), department(department), staff(staff), visitDate(visitDate) {
    this->purpose = new char[strlen(purpose) + 1];
    strcpy(this->purpose, purpose);
}

// Destructor
Visit::~Visit()
{
    delete[] purpose;
}

// Setters
void Visit::setVisitDate(time_t date)
{
    visitDate = date;
}

void Visit::setPurpose(const char* purpose)
{
    delete[] this->purpose;
    this->purpose = new char[strlen(purpose) + 1];
    strcpy(this->purpose, purpose);
}

void Visit::setDepartment(Department* department)
{
    this->department = department;
}

void Visit::setStaff(Employee* staff)
{
    this->staff = staff;
}

// Getters
time_t Visit::getVisitDate() const
{
    return visitDate;
}

const char* Visit::getPurpose() const
{
    return purpose;
}
Department* Visit::getDepartmentForPatient(const Patient* patient) const 
{
    if (this->patient == patient) 
    {
        return department; // Return the department if the patient matches
    }
    return nullptr; // Return nullptr if no match
}

Employee* Visit::getStaff() const
{
    return staff;
}

Patient* Visit::getPatient() const
{
    return patient; // Return the patient pointer
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
    if (v.visitDate != -1) {
        os << ctime(&v.visitDate); // פלט קריא
    }
    else {
        os << "Invalid date"; // במקרה שהתאריך לא חוקי
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



