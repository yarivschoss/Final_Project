#include <iostream>
using namespace std;

#include <string.h>
#include "Doctor.h"
#include "Department.h"
#pragma warning(disable: 4996)

const char* Occupation[] = { "Pathology", "Dentist", "Psychiatrist", "Neurologist" };

const Doctor& Doctor::operator=(const Doctor& other)
{
	if (this != &other)
	{
		Employee::operator=(other); // using the operator= of employee 
		 occupation = other.occupation;
		 setDepartment(other.department); // sending the department of the R-Value
		 return *this;
	}
}

ostream& operator<<(ostream& os, const Doctor& d)
{
	os << "{" <<(const Employee&)d << ", "; // using the employee's operator<< by casting 'e' to 'const Person&';
	os << "occupation: " << Occupation[(int)d.occupation] << ", " << 
		"department: " << d.department->getName() << "}";

	return os;
}

bool Doctor::setDepartment(Department* newDepartment)
{
	if (!newDepartment)
		return false;

	this->department = newDepartment;  
	return true;

}


