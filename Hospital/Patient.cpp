#include "Patient.h"

ostream& operator<<(ostream& os, const Patient& p)
{
    os << (const Person&)p << ", "; // using the person's operator<< by casting 'e' to 'const Person&'
    os << "id: " << p.getId();
    return os;
}


//const Patient& operator=(const Patient& other)
//{
//
//	if (this != &other)
//	{
//		occupation = other.occupation;
//		setDepartment(other.department); // sending the department of the R-Value
//		return *this;
//	}
//}
