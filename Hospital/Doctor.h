#ifndef __DOCTOR_H
#define __DOCTOR_H

#pragma warning(disable: 4996)
#include <iostream>
#include "Employee.h"

using namespace std;

class Department; // forward declaration that doctor will be able to point to department

class Doctor : virtual public Employee
{

public:

	enum class eOccupation { Pathology, Dentist, Psychiatrist, Neurologist };
	
	friend class Hospital;
	//friend class Department;

protected: 

	eOccupation occupation;
	Department* department = nullptr;

	Doctor(const Doctor& other) : Employee(other), department(nullptr) { *this = other; } // only allowing department and hospital to use the copy c'tor for adding
	const Doctor& operator=(const Doctor& other);

public:

	Doctor(const Employee& d, const eOccupation occupation) : Employee((const Person&)d), department(nullptr), 
		occupation(occupation) { ; }

	virtual ~Doctor() { cout << "fire Doctor" << endl; }
	
	bool setDepartment(Department* department);

	eOccupation getOccupation() const { return occupation; }

	virtual Employee* clone() const override { return new Doctor(*this); }

	friend ostream& operator<<(ostream& os, const Doctor& d);
	friend istream& operator>>(istream& in, Doctor& d);
	
	operator eOccupation() const { return getOccupation(); } // returns occupation
	
};
















#endif // __DOCTOR_H

