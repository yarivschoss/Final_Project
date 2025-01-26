#include <iostream>
using namespace std;

#include "Nurse.h"
#include "Department.h"
#pragma warning(disable: 4996)

const Nurse& Nurse::operator=(const Nurse& other)
{
	if (this != &other)
	{
		experience = other.experience;
		setDepartment(other.department); // sending the department of the R-Value
		return *this;
	}
}

void Nurse::toOs(ostream& os) const
{
	os << "experience: " << this->getExperience() << ", "
		<< "department: " << this->department->getName();
}

bool Nurse::setDepartment(Department* newDepartment)
{
	if (!newDepartment)
		return false;

	this->department = newDepartment;  
	return true;
	
}



