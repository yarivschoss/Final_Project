#ifndef __NURSE_H
#define __NURSE_H

#include <iostream>
#include "Employee.h"
using namespace std;


class Nurse : virtual public Employee
{

public:

	friend class Hospital;

private:

	int experience;
	Department* department;

	Nurse(const Nurse& other) : Employee(other), department(nullptr) { *this = other; } // only allowing department and hospital to use the copy c'tor for adding 
	const Nurse& operator=(const Nurse& other);

public:

	Nurse(const Employee& n, const int& experience) : Employee((const Person&)n), department(nullptr), 
		experience(experience) { ; }

	virtual ~Nurse() { cout << "fire Nurse" << endl; }

	inline bool setExperience(const int& experience);
	virtual bool setDepartment(Department* department) override;

	int getExperience() const { return experience; }

	virtual Employee* clone() const override { return new Nurse(*this); }

	virtual void toOs(ostream& os) const override;

	friend ostream& operator<<(ostream& os, const Nurse& n);
	friend istream& operator>>(istream& in, Nurse& n);

	
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