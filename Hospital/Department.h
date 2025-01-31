#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include "Surgeon.h"
#include "Doctor.h"
#include "Nurse.h"
#include "ResearcherDoctor.h"

//class Nurse;
//class Doctor;

class Department
{

public:

	int const MAX_DEPARTMENT_SIZE = 20; // Max size of department
	
private:

	char* name;
	int numOfEmployees;
	int maxNumOfEmployees;
	

	Employee** employees = nullptr;

	void operator=(const Department& other) = delete; // coping a department is not allowed
	Department(const Department& other) = delete; // coping a department is not allowed 

public:

	Department(const char* name);
	virtual ~Department();

	operator int const() const { return maxNumOfEmployees; } // returns size of department staff
	operator const char* () const { return getName(); } // returns name of department
	
	bool setName(const char* name);
	const char* getName() const 
	{
		if (!this) return "";

		return name; 
	}

	bool addEmployee(Employee& e);

	void showSurgeons() const;
	void showDoctors() const;
	void showNurses() const;

	friend ostream& operator<<(ostream& os, const Department& d); // prints department's data


	const Department& operator+=(Employee& other)
	{
		this->addEmployee(other);
		return *this;
	}


	bool operator()(const char* name); // prints data according to name
};

#endif //__DEPARTMENT_H