#include "Patient.h"


Patient::Patient(const Person& p) : Person(p.getName(), p.getBirthYear(), p.getGender())
{
    id = 100000000 + counter++;
}

//Patient::~Patient() 
//{
//}

ostream& operator<<(ostream& os, const Patient& p)
{
    os << (const Person&)p << ", "; // using the person's operator<< by casting 'e' to 'const Person&'
    os << "id: " << p.getId();
    return os;
}
