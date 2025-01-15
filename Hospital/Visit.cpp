#include "Visit.h"
#include <ctime>
#include <cstring>

Visit::Visit(Patient* patient, const char* purpose, Department* department, Doctor* doctor)
    : patient(patient), department(department), doctor(doctor)
{
    visitDate = time(0); // current date and time
    this->purpose = new char[strlen(purpose) + 1];
    strcpy(this->purpose, purpose);
}

void Visit::setVisitDate(time_t date)
{
    visitDate = date;
}

void Visit::show() const
{
    cout << "Visit for patient " << patient->getName() << " (ID: " << patient->getId() << "), ";
    cout << "Purpose: " << purpose << ", ";
    cout << "Date: " << ctime(&visitDate) << ", ";
    cout << "Department: " << (department ? department->getName() : "Not assigned") << ", ";
    cout << "Doctor: " << (doctor ? doctor->getName() : "Not assigned") << endl;
}

ostream& operator<<(ostream& os, const Visit& v)
{
    os << "Visit for patient " << v.patient->getName() << " (ID: " << v.patient->getId() << "), ";
    os << "Purpose: " << v.purpose << ", Date: " << ctime(&v.visitDate);
    return os;
}
