#ifndef __NURSE_H
#define __NURSE_H

#include <iostream>
#include "Employee.h"
using namespace std;

class Department; // forward declaration that nurse will be able to point to department

class Nurse : public Employee
{

public:

	friend class Hospital;
	//friend class Department;

private:

	int experience;
	Department* department;

	Nurse(const Nurse& other) : Employee(other), department(nullptr) { *this = other; } // only allowing department and hospital to use the copy c'tor for adding 

public:

	Nurse(const Employee& n, const int& experience) : Employee((const Person&)n), department(nullptr), 
		experience(experience) { ; }

	~Nurse() { cout << "fire Nurse" << endl; }

	const Nurse& operator=(const Nurse& other);
	friend ostream& operator<<(ostream& os, const Nurse& n);

	
	inline bool setExperience(const int& experience);
	bool setDepartment(Department * department);

	int getExperience() const { return experience; }
};

inline bool Nurse::setExperience(const int& experience)
{
	if (experience < 0)
		return false;

	else
	{
		this->experience = experience;
		return true;
}

}


#endif //__NURSE_H