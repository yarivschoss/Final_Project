#include <iostream>
using namespace std;

#include "Nurse.h"
#include "Department.h"
#pragma warning(disable: 4996)


const Nurse& Nurse::operator=(const Nurse& other)
{
	if (this != &other)
	{
		Employee::operator=(other); // using the operator= of employee 
		experience = other.experience;
		setDepartment(other.department); // sending the department of the R-Value
		return *this;
	}
}

ostream& operator<<(ostream& os, const Nurse& n)
{
	os << "{" << (const Employee&)n << ", "; // using the employee's operator<< by casting 'e' to 'const Person&';
	os << "experience: " << n.getExperience() << ", " << "department: " << n.department->getName() << "}";

	return os;
}

bool Nurse::setDepartment(Department* newDepartment)
{
	if (!newDepartment)
		return false;

	this->department = newDepartment;  
	return true;
	
}



