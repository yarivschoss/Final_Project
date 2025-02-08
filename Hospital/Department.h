#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include <vector>
#include <string>

#include "Surgeon.h"
#include "Doctor.h"
#include "Nurse.h"
#include "ResearcherDoctor.h"

//class Nurse;
//class Doctor;

class Department
{

public:

	friend class Hospital;
//	int const MAX_DEPARTMENT_SIZE = 20; // Max size of department
	
private:

	string name;
	

	vector<Employee*> employees;
	// unable to use default c'tor as private member due to C2248 error (visual studio/C++ bug)
	//Department(const Department& other)  = default; // coping a department is not allowed 

public:

    Department(const string& name)
	{
		setName(name);
	}
	virtual ~Department()
	{
		cout << "Destroy Department" << endl;
	}

	operator int const() const { return employees.capacity(); } // returns size of department staff
	operator const string () const { return getName(); } // returns name of department
	
	bool setName(const string& name)
	{
		this->name = name;
		return true;
	}
	const string& getName() const 
	{
		if (!this) return "";

		return name; 
	}

	bool addEmployee(Employee& e)
	{
		if (!this) return false;

		employees.push_back(&e); // allocates the employee to the department's employee array
		(*(--employees.end()))->setDepartment(this); // setting 'this' department to the given employee (last in vector)
		return true;
	}

	void showSurgeons() const
	{
		vector<Employee*>::const_iterator itr = employees.begin();
		vector<Employee*>::const_iterator itrEnd = employees.end();
		int size = employees.size();

		cout << "surgeons: " << "\n" << endl; //showing surgeons in hospital
		cout << "{";
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			if (typeid(**itr) == typeid(Surgeon))
			{
				cout << (*itr)->getName();

				if (i < size)
					cout << ", ";
			}
		}
		cout << "}" << endl;
	}
	void showDoctors() const
	{
		vector<Employee*>::const_iterator itr = employees.begin();
		vector<Employee*>::const_iterator itrEnd = employees.end();
		int size = employees.size();

		cout << "doctors: " << "\n" << endl; //showing doctors in department
		cout << "{";
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			if (typeid(**itr) == typeid(Doctor) || typeid(**itr) == typeid(ResearcherDoctor) || typeid(**itr) == typeid(Surgeon))
			{
				cout << (*itr)->getName();

				if (i < size)
					cout << ", ";
			}
		}
		cout << "}" << endl;
	}
	void showNurses() const
	{
		vector<Employee*>::const_iterator itr = employees.begin();
		vector<Employee*>::const_iterator itrEnd = employees.end();
		int size = employees.size();

		cout << "nurses: " << "\n" << endl; //showing nurses in hospital
		cout << "{";
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			if (typeid(**itr) == typeid(Nurse))
			{
				cout << (*itr)->getName();

				if (i < size)
					cout << ", ";
			}
		}
		cout << "}" << endl;
	}

	friend ostream& operator<<(ostream& os, const Department& d) // prints department's data
	{
		vector<Employee*>::const_iterator itr = d.employees.begin();
		vector<Employee*>::const_iterator itrEnd = d.employees.end();
		int size = d.employees.size();

		os << "{name: " << d.getName() << ", ";
		os << "number of employees: " << d.employees.size() << ", ";
		os << "employees capacity: " << d.employees.capacity() << "}" << endl;

		os << "\ndoctors: " << endl; //showing doctors in department
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			if (typeid(**itr) == typeid(Doctor) || typeid(**itr) == typeid(ResearcherDoctor) || typeid(**itr) == typeid(Surgeon))
			{
				os << **itr;

				if (i < size) // Avoid trailing comma
				{
					os << ", ";
				}
			}
		}
		os << endl;

		itr = d.employees.begin(); // reseting the iterator

		cout << "nurses: " << endl; //showing nurses in department
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			if (typeid(**itr) == typeid(Nurse))
			{
				os << **itr;

				if (i < size) // Avoid trailing comma
				{
					os << ", ";
				}
			}
		}
		os << endl;

		return os;
	}

	const Department& operator+=(Employee& other)
	{
		this->addEmployee(other);
		return *this;
	}

	bool operator()(const char* name); // prints data according to name
};

#endif //__DEPARTMENT_H