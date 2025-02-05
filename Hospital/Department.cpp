#include <iostream>
using namespace std;

#include "Department.h"
#pragma warning(disable: 4996)

Department::Department(const char* name) : name(nullptr)
{
	setName(name);
}

Department::~Department()
{
	delete[] name;
	cout << "Destroy Department" << endl;
}

ostream& operator<<(ostream& os, const Department& d)
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
		if (typeid(*itr) == typeid(Doctor) || typeid(*itr) == typeid(ResearcherDoctor) || typeid(*itr) == typeid(Surgeon))
		{
			os << *itr;

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
		if (typeid(*itr) == typeid(Nurse))
		{
			os << *itr;

			if (i < size) // Avoid trailing comma
			{
				os << ", ";
			}
		}
	}
	os << endl;

	return os;
}

bool Department::operator()(const char* name)
{
	if (!name)
		return false;

	if (strcmp(name, "name") == 0)
	{
		cout << name;
		return true;
	}

	if (strcmp(name, "doctors") == 0)
	{
		showDoctors();
		return true;
	}

	if (strcmp(name, "nurses") == 0)
	{
		showNurses();
		return true;
	}

	return false;
}

bool Department::setName(const char* name)
{
	if (!name) return false;

	else
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		return true;
	}

}

bool Department::addEmployee(Employee& e)
{
	if (!this) return false;

	employees.push_back(&e); // allocates the employee to the department's employee array
	(*(--employees.end()))->setDepartment(this); // setting 'this' department to the given employee (last in vector)
	return true;
}

void Department::showSurgeons() const
{
	vector<Employee*>::const_iterator itr = employees.begin();
	vector<Employee*>::const_iterator itrEnd = employees.end();
	int size = employees.size();

	cout << "surgeons: " << "\n" << endl; //showing surgeons in hospital
	cout << "{";
	for (int i = 1; itr != itrEnd; ++itr, i++)
	{
		if (typeid(*itr) == typeid(Surgeon))
		{
			cout << (*itr)->getName();

			if (i < size)
				cout << ", ";
		}
	}
	cout << "}" << endl;
}

void Department::showDoctors() const
{
	vector<Employee*>::const_iterator itr = employees.begin();
	vector<Employee*>::const_iterator itrEnd = employees.end();
	int size = employees.size();

	cout << "doctors: " << "\n" << endl; //showing doctors in department
	cout << "{";
	for (int i = 1; itr != itrEnd; ++itr, i++)
	{
		if (typeid(*itr) == typeid(Doctor) || typeid(*itr) == typeid(ResearcherDoctor) || typeid(*itr) == typeid(Surgeon))
		{
			cout << (*itr)->getName();

			if (i < size)
				cout << ", ";
		}
	}
	cout << "}" << endl;
}

void Department::showNurses() const
{
	vector<Employee*>::const_iterator itr = employees.begin();
	vector<Employee*>::const_iterator itrEnd = employees.end();
	int size = employees.size();

	cout << "nurses: " << "\n" << endl; //showing nurses in hospital
	cout << "{";
	for (int i = 1; itr != itrEnd; ++itr, i++)
	{
		if (typeid(*itr) == typeid(Nurse))
		{
			cout << (*itr)->getName();

			if (i < size)
				cout << ", ";
		}
	}
	cout << "}" << endl;
}

