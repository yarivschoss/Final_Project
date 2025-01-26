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
		 occupation = other.occupation;
		 setDepartment(other.department); // sending the department of the R-Value
		 return *this;
	}
}

// Doctor's info when printing an array of employees
void Doctor::toOs(ostream& os) const
{
	os << "occupation: " << Occupation[(int)this->occupation] << ", " <<
		"department: " << this->department->getName();
} 

bool Doctor::setDepartment(Department* newDepartment)
{
	if (!newDepartment)
		return false;

	this->department = newDepartment;  
	return true;

}


