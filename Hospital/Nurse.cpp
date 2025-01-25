#include <iostream>
using namespace std;

#include "Nurse.h"
#include "Department.h"
#pragma warning(disable: 4996)

int const MAX_STRING_SIZE = 100;

const Nurse& Nurse::operator=(const Nurse& other)
{
	if (this != &other)
	{
		experience = other.experience;
		setDepartment(other.department); // sending the department of the R-Value
		return *this;
	}
}

// Nurse's info when printing an array of employees
void Nurse::toOs(ostream& os) const
{
	os << "experience: " << this->getExperience() << ", "
		<< "department: " << this->department->getName();
}

ostream& operator<<(ostream& os, const Nurse& n)
{
	os << (const Employee&)n << ", "; // using the employee's operator<< by casting 'e' to 'const Person&';
	os << "experience: " << n.getExperience() << ", " << "department: " << n.department->getName();

	return os;
}

istream& operator>>(istream& in, Nurse& n)
{
	char name[MAX_STRING_SIZE];

	cout << "Enter nurse's name: ";
	in.getline(name, MAX_STRING_SIZE);
	n.setName(name);

	cout << "Enter nurse's birth year: ";
	in >> n.birthYear;

	cout << "Enter nurse's gender(m/f): ";
	in >> n.gender;

	cout << "Enter years of experience: ";
	in >> n.experience;

	return in;
}

bool Nurse::setDepartment(Department* newDepartment)
{
	if (!newDepartment)
		return false;

	this->department = newDepartment;  
	return true;
	
}



