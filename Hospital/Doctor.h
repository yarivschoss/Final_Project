#ifndef __DOCTOR_H
#define __DOCTOR_H

#pragma warning(disable: 4996)
#include <iostream>
#include "Employee.h"

using namespace std;

class Doctor : virtual public Employee
{

public:

	enum class eOccupation { Pathology, Dentist, Psychiatrist, Neurologist };
	
	friend class Hospital;

protected: 

	eOccupation occupation;
	Department* department = nullptr;

	Doctor(const Doctor& other) : Employee(other), department(nullptr) { *this = other; } // only allowing department and hospital to use the copy c'tor for adding
	const Doctor& operator=(const Doctor& other);

public:

	Doctor(const Employee& d, const eOccupation occupation) : Employee(d), department(nullptr), 
		occupation(occupation) { ; }

	virtual ~Doctor() { ; }
	
	virtual bool setDepartment(Department* department) override;

	eOccupation getOccupation() const { return occupation; }

	virtual Employee* clone() const override { return new Doctor(*this); }

	// Doctor's info when printing an array of employees
	virtual void toOs(ostream& os) const override;

	friend ostream& operator<<(ostream& os, const Doctor& d)
	{
		os << (const Employee&)d; // using the employee's operator<< by casting 'e' to 'const Person&';
		return os;
	}
	friend istream& operator>>(istream& in, Doctor& d)
	{
		int occupation;

		in >> (Employee&)d;
		cout << "Select occupation (0 - Pathology, 1 - Dentist, 2 - Psychiatrist, 3 - Neurologist): ";
		in >> occupation;
		d.occupation = (Doctor::eOccupation)occupation;
		return in;
	}
	
	operator eOccupation() const { return getOccupation(); } // returns occupation
	
};
















#endif // __DOCTOR_H

