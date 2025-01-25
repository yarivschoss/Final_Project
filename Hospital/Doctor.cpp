#include <iostream>
using namespace std;

#include <string.h>
#include "Doctor.h"
#include "Department.h"
#pragma warning(disable: 4996)

const char* Occupation[] = { "Pathology", "Dentist", "Psychiatrist", "Neurologist" };
int const MAX_STRING_SIZE = 100;

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

ostream& operator<<(ostream& os, const Doctor& d)
{
	os << (const Employee&)d << ", "; // using the employee's operator<< by casting 'e' to 'const Person&';
	os << "occupation: " << Occupation[(int)d.occupation] << ", " <<
		"department: " << d.department->getName();

	return os;
}

istream& operator>>(istream& in, Doctor& d)
{
	int occupation;
	char name[MAX_STRING_SIZE];

	cout << "Enter doctor's name: ";
	in.getline(name, MAX_STRING_SIZE);
	d.setName(name);

	cout << "Enter doctor's birth year: ";
	in >> d.birthYear;

	cout << "Enter doctor's gender(m/f): ";
	cin >> d.gender;

	cout << "Select occupation (0 - Pathology, 1 - Dentist, 2 - Psychiatrist, 3 - Neurologist): ";
	in >> occupation;
	d.occupation = (Doctor::eOccupation)occupation;

	return in;
}

bool Doctor::setDepartment(Department* newDepartment)
{
	if (!newDepartment)
		return false;

	this->department = newDepartment;  
	return true;

}


