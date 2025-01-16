#ifndef __DOCTOR_H
#define __DOCTOR_H

#pragma warning(disable: 4996)
#include <iostream>
#include "Employee.h"

using namespace std;

class Department; // forward declaration that doctor will be able to point to department

class Doctor : public Employee
{

public:

	enum class eOccupation { Pathology, Dentist, Psychiatrist, Neurologist };
	
	friend class Hospital;
	//friend class Department;

private: 

	eOccupation occupation;
	Department* department;

	Doctor(const Doctor& other) : Employee(other), department(nullptr) { *this = other; } // only allowing department and hospital to use the copy c'tor for adding
	const Doctor& operator=(const Doctor& other);

public:

	Doctor(const Employee& d, const eOccupation occupation) : Employee((const Person&)d), department(nullptr), 
		occupation(occupation) { ; }

	~Doctor() { cout << "fire Doctor" << endl; }
	
	bool setDepartment(Department* department);

	eOccupation getOccupation() const { return occupation; }


	friend ostream& operator<<(ostream& os, const Doctor& d);
	
	operator eOccupation() const { return getOccupation(); } // returns occupation
	
};
















#endif // __DOCTOR_H

